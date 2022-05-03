        /*************************************************/
        /*               ESPECIFICACIO LEX               */
        /*          Calculadora amb registres            */
        /*************************************************/

%{
	#include "calculadora.tab.h"
	#include <stdlib.h>

	int nlin=0;
%}

%option nounput
%option noinput
%option noyywrap


%%
[ \t]+                          ;
 
[a-z]                           {	yylval.reg=yytext[0]-'a'; 		// definim registres amb noms a-z
                                	return(REGI);
                                }
[A-Z]							{
									yylval.reg=yytext[0]-'A';
									return(REGL);
								}

[0-9]+"."[0-9]+					{
									yylval.valr=atof(yytext);
									return(REAL);
								}
[0-9]+                          {	
									yylval.valor=atoi(yytext);
                               	 	return(INT);
                                }

\n                             {	nlin++;
                                    return(yytext[0]);
                                }

.                     		 {	return(yytext[0]);	}	/*  Els errors es processaran a nvell sintàctic */


