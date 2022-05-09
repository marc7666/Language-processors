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
{operators}		{
                                return(OPERATOR);
                        }
{separators}	{;}
{vars}			{
					character_err += strlen(yytext);
                                        return(REG);
				}
\n				{
					lines += 1;
					cn = 0;
				}
.				{
					return(yytext[0]);
				}
