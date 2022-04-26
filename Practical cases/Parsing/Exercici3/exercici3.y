        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*                 Exercici 3                   */
        /************************************************/

	
		
%{
	
	#include<stdio.h>
	#include<ctype.h>

	extern int nlin;
    extern int yylex(void);
    void yyerror (char const *);

	

%}
	

%start parenter

%union{	int valor;
		int opc;
		}

%token <opc> OPER
%token <valor> INT

%left '+' '-'
%left '*' "div" "mod"
%left UMENYS        /* precedencia de l'operador unari menys */

%type <valor> expr  sentencia parenter

%%

parenter	:           {;}
       			 |       parenter sentencia
       			 ;
sentencia  :    '\n' 			{;}
				|    '(' expr ')' ';' '\n' 	{fprintf(stdout,"Sobre parentesis exterior");}
                |	 expr ';' '\n'             {//fprintf(stdout,"%d \n", $1);
                }
                |    error '\n'           {fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;	}

         		  ;
expr  :			'(' expr '*' expr  ')'          {//$$ = $1 * $3;
												fprintf(stdout, "Sobre parentesis al *\n");}
      |			'(' expr "mod" expr ')'         {//$$ = $1 % $3;
      											fprintf(stdout, "Sobre parentesis al mod\n");}
      |			'(' expr "div" expr ')'			{//$$ = $1 / $3;
      											fprintf(stdout, "Sobre parentesis al div\n");}			
	  |			'(' expr ')'            {//$$ = $2;
	  }
      |			expr '+' expr           {//$$ = $1 + $3;
      }
      |			expr '-' expr           {//$$ = $1 - $3;
      } 
      |			expr '*' expr           {//$$ = $1 * $3;
      }
      |			expr "mod" expr         {//$$ = $1 % $3;
      }
      |			expr "div" expr			{//$$ = $1 / $3;
      }
      |			'-' expr %prec UMENYS   {//$$ = - $2;
      }
      |			INT                		{//$$ = $1;
      									fprintf(stdout, "%d ", $1);}
      ;

%%

/* Called by yyparse on error. */

void yyerror (char const *s){
    fprintf (stderr, "%s\n", s);
}

int main(){
        
    if (yyparse()==0){
        return(0);
    }
    else
    return(1);
    
}
