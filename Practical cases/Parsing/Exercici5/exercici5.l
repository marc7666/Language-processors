%option nounput
%option noinput

%x panic inside_comment

%{
	#include "exercici5.tab.h"
	#include <string.h>
	#include <stdlib.h>
	
	int nlin = 0;
	
%}

%option nounput
%option noinput
%option noyywrap

operators ("or"|"and"|"||"|"&&"|"->"|"<->")
separators [ \t]+
vars [A-Z]+

%%

"#"					{	
						BEGIN(inside_comment);
					}
<inside_comment>\n {
						nlin++;
						BEGIN(0);
					}
("or"|"||")		{
					return(OR);
				}
("and"|"&&")	{
					return(AND);
				}
"->"			{
					return(IMPLICA);
				}
"<->"			{
					return(IMPLICAD);
				}
{separators}	{;}
{vars}			{
					yylval.reg = yytext[0];
                	return(REG);
				}
\n				{
					nlin++;
					BEGIN(0);
					return(yytext[0]);
				}
.				{
					return(yytext[0]);
				}
