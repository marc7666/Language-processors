        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*                 Exercici 2                   */
        /************************************************/

	
		
%{
	
	#include<stdio.h>
	#include<ctype.h>

	extern int nlin;
    extern int yylex(void);
    void yyerror (char const *);

	

%}
	

%start sufixer

%union{	int valor;
		int opc;
		}

%token <opc> OPER
%token <valor> INT

%left '+' '-'
%left '*' "div" "mod"
%left UMENYS        /* precedencia de l'operador unari menys */

%type <valor> expr  sentencia sufixer

%%

sufixer	:           {;}
       			 |       sufixer sentencia
       			 ;
sentencia  :    '\n' 			{;}
                |	 expr ';' '\n'             {fprintf(stdout,"%d \n", $1);}
                |    '#' 					{}
                |    error '\n'           {fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;	}

         		  ;
expr  :			'(' expr ')'            {$$ = $2;}
      |			expr '+' expr           {$$ = $1 + $3;
      									fprintf(stdout, "%d %d +", $1, $3);}
      |			expr '-' expr           {$$ = $1 - $3;
      									fprintf(stdout, "%d %d -", $1, $3);} 
      |			expr '*' expr           {$$ = $1 * $3;
      									fprintf(stdout, "%d %d +", $1, $3);}
      |			expr "mod" expr         {$$ = $1 % $3;
      									fprintf(stdout, "%d %d mod", $1, $3);}
      |			expr "div" expr			{$$ = $1 / $3;
      									fprintf(stdout, "%d %d div", $1, $3);}
      |			'-' expr %prec UMENYS   {$$ = - $2;}
      |			INT                		{$$ = $1;}
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
