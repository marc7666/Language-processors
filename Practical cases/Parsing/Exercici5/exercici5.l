        /*************************************************/
        /*               ESPECIFICACIO LEX               */
        /*          Calculadora amb registres            */
        /*************************************************/

%{
	#include "exercici5.tab.h"

	int nlin=0;
%}

operators ("or"|"and"|"||"|"&&"|"->"|"<->"|"!")
delimiters ("("|")")
separators [ \t]+
vars [A-Z]+

%option nounput
%option noinput
%option noyywrap


%%
separators                      ;
 
vars                           	{	
									yylval.reg=yytext[0]-'A'; 		// definim registres amb noms a-z
                                	return(REG);
                                }

[0-9]+                          {	yylval.valor=atoi(yytext);
                               	 	 return(INT);
                                }

\n                             {	nlin++;
                                    return(yytext[0]);
                                }

.                     		 {	return(yytext[0]);	}	/*  Els errors es processaran a nvell sintàctic */


