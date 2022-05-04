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

%union{
	struct exp_struct {
		char *expression;
		int is_parentized;
		int precedence;
	} exp;
	int valor;
}

%token <valor> INT

%left '+' '-'
%left '*' DIV MOD
%left UMENYS        /* precedencia de l'operador unari menys */

%type <exp> expr  sentencia sufixer

%%

sufixer	:           {;}
       			 |       sufixer sentencia
       			 ;
sentencia  :    '\n' 			{;}
                |	 expr ';' '\n'             {fprintf(stdout,"%s \n", $1.expression);}
                |    error '\n'           {fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;	}

         		  ;
expr  :			'(' expr ')'            {
											$$.expression = (char *) malloc(sizeof(char)*strlen($2.expression));
											strcpy($$.expression,$2.expression);
											$$.is_parentized = 1;
											$$.precedence = $2.precedence;
										}
      |			expr '+' expr           {
      										$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 3));
      										sprintf($$.expression,"%s + %s", $1.expression, $3.expression);
      										$$.is_parentized = 0;
      										$$.precedence = 0;
      									}
      |			expr '-' expr           {
      										$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 3));
      										sprintf($$.expression,"%s - %s", $1.expression, $3.expression);
      										$$.is_parentized = 0;
      										$$.precedence = 0;
      									}
      |			expr '*' expr           {
											int parentize_1 = 0,parentize_2 = 0;
      										if ($1.is_parentized && ($1.precedence == 0 || $1.precedence == 2)){
												parentize_1 = 1;
      										}
      										if ($3.is_parentized && ($3.precedence == 0 || $3.precedence == 2)){
												parentize_2 = 1;
      										}
      										if (parentize_1 == 1){
      											if (parentize_2 == 1){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 7));
      										sprintf($$.expression,"(%s) * (%s)", $1.expression, $3.expression);
      											}else{
		  											$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 5));
		  											sprintf($$.expression,"(%s) * %s", $1.expression, $3.expression);
      											}
      										}else{
      											if (parentize_2 == 1){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 5));
      										sprintf($$.expression,"%s * (%s)", $1.expression, $3.expression);
      											}else{
		  											$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 3));
		  											sprintf($$.expression,"%s * %s", $1.expression, $3.expression);
      											}
      										}
      										$$.is_parentized = 0;
      										$$.precedence = 1;
      									}
      |			expr MOD expr         	{
      										int parentize_1 = 0,parentize_2 = 0;
      										if ($1.is_parentized && ($1.precedence == 0 || $1.precedence == 2)){
												parentize_1 = 1;
      										}
      										if ($3.is_parentized && ($3.precedence == 0 || $3.precedence == 2)){
												parentize_2 = 1;
      										}
      										if (parentize_1 == 1){
      											if (parentize_2 == 1){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 9));
      										sprintf($$.expression,"(%s) mod (%s)", $1.expression, $3.expression);
      											}else{
		  											$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 7));
		  											sprintf($$.expression,"(%s) mod %s", $1.expression, $3.expression);
      											}
      										}else{
      											if (parentize_2 == 1){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 7));
      										sprintf($$.expression,"%s mod (%s)", $1.expression, $3.expression);
      											}else{
		  											$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 5));
		  											sprintf($$.expression,"%s mod %s", $1.expression, $3.expression);
      											}
      										}
      										$$.is_parentized = 0;
      										$$.precedence = 1;
      									}
      |			expr DIV expr			{
      										int parentize_1 = 0,parentize_2 = 0;
      										if ($1.is_parentized && ($1.precedence == 0 || $1.precedence == 2)){
												parentize_1 = 1;
      										}
      										if ($3.is_parentized && ($3.precedence == 0 || $3.precedence == 2)){
												parentize_2 = 1;
      										}
      										if (parentize_1 == 1){
      											if (parentize_2 == 1){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 9));
      										sprintf($$.expression,"(%s) div (%s)", $1.expression, $3.expression);
      											}else{
		  											$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 7));
		  											sprintf($$.expression,"(%s) div %s", $1.expression, $3.expression);
      											}
      										}else{
      											if (parentize_2 == 1){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 7));
      										sprintf($$.expression,"%s div (%s)", $1.expression, $3.expression);
      											}else{
		  											$$.expression = (char *) malloc(sizeof(char) * (strlen($1.expression) + strlen($3.expression) + 5));
		  											sprintf($$.expression,"%s div %s", $1.expression, $3.expression);
      											}
      										}
      										$$.is_parentized = 0;
      										$$.precedence = 1;
      									}
      |			'-' expr %prec UMENYS   {
      										if ($2.precedence == 0 || $2.precedence == 2){
      											if ($2.is_parentized){
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($2.expression) + 3));
		  											sprintf($$.expression,"-(%s)", $2.expression);
	  												$$.is_parentized = 0;
	  												$$.precedence = 3;
      											}else{
      												$$.expression = (char *) malloc(sizeof(char) * (strlen($2.expression) + 1));
		  											sprintf($$.expression,"-%s", $2.expression);
	  												$$.is_parentized = 0;
	  												$$.precedence = 3;
      											}
      										}else{
      											$$.expression = (char *) malloc(sizeof(char) * (strlen($2.expression) + 1));
	  											sprintf($$.expression,"-%s", $2.expression);
  												$$.is_parentized = 0;
  												$$.precedence = 3;
  											}
      									}
      |			INT                		{
      										int digits = 1;
      										int thenum = $1;
      										while (thenum > 9){
      											digits += 1;
      											thenum = thenum / 10;
      										}
      										$$.expression = (char *) malloc(sizeof(char) * digits);
      										sprintf($$.expression,"%d", $1);
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
