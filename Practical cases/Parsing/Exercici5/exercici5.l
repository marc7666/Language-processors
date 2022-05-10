%option nounput
%option noinput

%x panic inside_comment

%{
	#include <string.h>
	#include <stdlib.h>
	
	int lines = 0;
	int cn = 0;
%}

operators ("or"|"and"|"||"|"&&"|"->"|"<->")
separators [ \t]+
vars [A-Z]+

%%

"#"					{	
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
								yylval.optipus = yytext[0];
                                return(OPERATOR);
                        }
{separators}	{;}
{vars}			{
                	return(REG);
				}
\n				{
					lines += 1;
					cn = 0;
				}
.				{
					return(yytext[0]);
				}
