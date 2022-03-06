%option nounput
%option noinput

%x panic inside_comment

%{
	#include <string.h>
	int character_err = 0;
	int lines = 0;
	char error[24];
	int cn = 0;
%}

operators ("or"|"and"|"||"|"&&"|"->"|"<->"|"!")
delimiters ("("|")")
separators [ \t]+
vars [A-Z]+

%%

^(.+|\n)			{
						if (cn == 0){
							printf("Line: %i - ", lines);
							character_err = 0;
							cn = 1;
						}
						REJECT;
					}
"--"				{	
						BEGIN(inside_comment);
						ECHO;
					}
<inside_comment>\n {
						ECHO;
						lines += 1;
						cn = 0;
						BEGIN(0);
					}
<panic>\n			{
						printf("\n ERROR at line %i:%i\n", lines, character_err);
						printf(" Caused by %s\n", error);
						strcpy(error, "");
						lines += 1;
						cn = 0;
						BEGIN(0);
					}
{operators}		|
{delimiters}	|
{separators}	|
{vars}			{
					ECHO;
					character_err += strlen(yytext);
				}
\n				{
					ECHO;
					lines += 1;
					cn = 0;
				}
.				{
					BEGIN(panic);
					strcpy(error, yytext);
					ECHO;
				}
