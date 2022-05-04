        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*                 Exercici 2                   */
        /************************************************/

	
		
%{
	
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
	#include<stdlib.h>

	extern int nlin;
    extern int yylex(void);
    void yyerror (char const *);
%}
	

%start sufixer

%union{	int valor;
		int opc;
		char *oper;
		}

%token <opc> OPER
%token <valor> INT

%left '+' '-'
%left '*' DIV MOD
%left UMENYS        /* precedencia de l'operador unari menys */

%type <oper> expr  sentencia sufixer

%%

sufixer	:           {;}
       			 |       sufixer sentencia
       			 ;
sentencia  :    '\n' 			{;}
                |	 expr ';' '\n'             {fprintf(stdout,"%s \n", $1);}
                |    error '\n'           {fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;	}

         		  ;
expr  :			'(' expr ')'            {
											$$ = (char 	*) malloc(sizeof(char) * (strlen($2)));
											strcpy($$,$2);
										}
      |			expr '+' expr           {
      										$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 4));
      										sprintf($$,"%s %s +", $1, $3);
      									}
      |			expr '-' expr           {
      										$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 4));
      										sprintf($$,"%s %s -", $1, $3);
      									}
      |			expr '*' expr           {
      										$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 4));
      										sprintf($$,"%s %s *", $1, $3);
      									}
      |			expr MOD expr         	{
      										$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 6));
      										sprintf($$,"%s %s mod", $1, $3);
      									}
      |			expr DIV expr			{
      										$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 6));
      										sprintf($$,"%s %s div", $1, $3);
      									}
      |			'-' expr %prec UMENYS   {
      										$$ = (char *) malloc(sizeof(char) * (strlen($2) + 1));
      										sprintf($$,"-%s", $2);
      									}
      |			INT                		{
      										int digits = 1;
      										int thenum = $1;
      										while (thenum > 9){
      											digits += 1;
      											thenum = thenum / 10;
      										}
      										$$ = (char *) malloc(sizeof(char) * digits);
      										sprintf($$,"%d", $1);
      									}
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
