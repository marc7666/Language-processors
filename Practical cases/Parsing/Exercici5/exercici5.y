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

%token <optipus> IMPLICA IMPLICAD OR AND
%token <reg> REG


%left IMPLICA IMPLICAD
%left OR
%left AND
%right UMENYS        /* precedencia de l'operador unari menys */

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
	  |  expr AND expr			{
									$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 5));
	      							sprintf($$,"%s and %s",$1, $3);
								}
	  |	expr OR expr 			{
	  								$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 4));
	      							sprintf($$,"%s or %s",$1, $3);
	      						}
	  | expr IMPLICA expr 		{
	  								$$ = (char *) malloc(sizeof(char) * (strlen($1) + strlen($3) + 5));
      								sprintf($$,"!%s or %s",$1, $3);
      							}
	  | expr IMPLICAD expr 		{	
	  								$$ = (char *) malloc(sizeof(char) * (strlen($1) * 2 + strlen($3) * 2 + 19));
      								sprintf($$,"(!%s or %s) and (!%s or %s)",$1, $3, $3, $1);
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
