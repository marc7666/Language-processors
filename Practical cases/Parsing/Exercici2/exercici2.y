        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*                 Exercici 2                   */
        /************************************************/

	
		
%{
	
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
	#define MAXLEN 100

	extern int nlin;
    extern int yylex(void);
    void yyerror (char const *);

	

%}
	

%start sufixer

%union{	int valor;
		int opc;
		char oper[100];
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
expr  :			'(' expr ')'            {strcpy($$,$2);}
      |			expr '+' expr           {sprintf($$,"%s %s + ", $1, $3);}
      |			expr '-' expr           {sprintf($$,"%s %s - ", $1, $3);} 
      |			expr '*' expr           {sprintf($$,"%s %s * ", $1, $3);}
      |			expr MOD expr         {sprintf($$,"%s %s mod ", $1, $3);}
      |			expr DIV expr			{sprintf($$,"%s %s div ", $1, $3);}
      |			'-' expr %prec UMENYS   {sprintf($$,"-%s", $2);}
      |			INT                		{sprintf($$,"%d", $1);}
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
