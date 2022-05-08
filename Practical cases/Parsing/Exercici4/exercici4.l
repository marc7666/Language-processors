        /*************************************************/
        /*               ESPECIFICACIO LEX               */
        /*                   Exercici 4                  */
        /*************************************************/

%{
	#include "exercici4.tab.h"
	#include <stdlib.h>
	#include <string.h>

	int nlin=0;
%}

%option nounput
%option noinput
%option noyywrap


%%
[ \t]+                          ;
 
[a-d]+                          {
									yylval.reg = (char *) malloc(sizeof(char) * strlen(yytext));
									strcpy(yylval.reg, yytext);
									return(REG);	
                                }
("buida"|"BUIDA")				{
									return(BUIDA);
								}
\n                             	{	
									nlin++;
                                    return(yytext[0]);
                                }

.                     		 {	return(yytext[0]);	}	/*  Els errors es processaran a nvell sintàctic */


