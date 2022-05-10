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

%X comment

%%
[ \t]+                          ;

#								{
									BEGIN(comment);
								}
<comment>.						;
								
<comment>\n						{
									nlin++;
									BEGIN(0);
								}
 
[a-z]+                          {
									yylval.reg = (char *) malloc(sizeof(char) * strlen(yytext));
									strcpy(yylval.reg, yytext);
									return(REG);	
                                }
"["[a-z]-[a-z]"]"				{	// Passarli al yacc amb totes les lletres (bucle) per despres crear un OR multiple (de sol 2 estats) quan el yacc rebi RANG
									yylval.rangg.inicial = yytext[1];
									yylval.rangg.final = yytext[3];
									return(RANG);
								}
("buida"|"BUIDA")				{
									return(BUIDA);
								}
\n                             	{	
									nlin++;
									BEGIN(0);
                                    return(yytext[0]);
                                }

.                     		 {	return(yytext[0]);	}	/*  Els errors es processaran a nvell sintàctic */


