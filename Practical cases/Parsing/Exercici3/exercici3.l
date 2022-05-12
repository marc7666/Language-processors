        /*************************************************/
        /*               ESPECIFICACIO LEX               */
        /*                   Exercici 3                  */
        /*************************************************/

%{
	#include "exercici3.tab.h"
	
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

[0-9]+                          {
									yylval.valor=atoi(yytext);
                               	 	return(INT);
                                }
                                
\n                              {
									nlin++;
                                    return(yytext[0]);
                                }
("div"|"/")						{
									return(DIV);
								}
"mod"							{
									return(MOD);
								}								

.                     		 {	return(yytext[0]);	}	/*  Els errors es processaran a nivell sintàctic */


