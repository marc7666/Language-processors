        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*         Calculadora amb registres            */
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
	

%start calculadora

%union{
	char optipus;
	char reg;
	char *expression;
}

%token <optipus> OPERADOR
%token <reg> REG


%left OPERADOR
%left UMENYS        /* precedencia de l'operador unari menys */

%type <expression> expr  sentencia calculadora

%%

calculadora	:           {;}
       			 |       calculadora sentencia
       			 ;
sentencia  :    '\n' 			{;}
                |	expr ';' '\n'             {fprintf(stdout,"%s \n", $1);}
                |    error '\n'           {fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;	}

         		  ;
expr  :  '(' expr ')'			{	
									$$ = (char *) malloc(sizeof(char) * (strlen($2) + 2));
									sprintf($$,"(%s)",$2);
								}     
	  |  expr OPERADOR expr		{
											if($2 == '-'){
												$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 5));
      											sprintf($$,"!%s or %s",$1, $3);
											}else if ($2 == '<'){
												$$ = (char *) malloc(sizeof(char) * (strlen($1) * 2 + strlen($3) * 2 + 19));
      											sprintf($$,"(!%s or %s) and (!%s or %s)",$1, $3, $3, $1);
											}else{
												// Que printi el OPERADOR que toque
												if ($2 == 'o' || $2 == '|'){
													$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 4));
	      											sprintf($$,"%s or %s",$1, $3);
												}else if($2 == 'a' || $2 == '&'){
													$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 5));
	      											sprintf($$,"%s and %s",$1, $3);
												}
												
											}
										}
      |       '!' expr %prec UMENYS   	{	
      										$$ = (char *) malloc(sizeof(char) * (strlen($2) + 1));
      										sprintf($$,"!%s",$2);
      									}
      |       REG                  		{
      										$$ = (char *) malloc(sizeof(char));
      										sprintf($$,"%c",$1);
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
