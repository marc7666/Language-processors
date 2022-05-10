        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*                  Exercici 4                  */
        /************************************************/

	
		
%{
	
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
    
    int regs[26]={0};
	
	extern int nlin;
    extern int yylex(void);
    void yyerror (char const *);

	

%}
	

%start expresions

%union{	struct expresio_struct {
			int node_inicial;
			int node_final;
			int sizeof_a;
			int *origen;
			int *desti;
			char *caracter;
		} expresio;
		char *reg;
		char val;
		struct rang_struct {
			char inicial;
			char final;
		} rangg;
	}
%token <reg> REG
%token <val> BUIDA
%token <rangg> RANG

%left '|'
%left '.'
%left '*' '+' '?'

%type <expresio> expr  sentencia expresions

%%

expresions	:           {;}
       			 |       expresions sentencia
       			 ;
sentencia  :    '\n' 			{;}
                |	expr ';' '\n'		{
                							for(int i = 0; i < $1.sizeof_a;i++){
                								printf("%d, %c: %d\n", $1.origen[i], $1.caracter[i], $1.desti[i]);
                							}
                							printf("ESTAT INICIAL: %d\n", $1.node_inicial);
                							printf("ESTAT FINAL: %d\n", $1.node_final);
                							printf("____________________\n");
                						}
                |    error '\n'			{
                							fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;
                                     	}

         		  ;
expr  :			'(' expr ')'            { //No s'ha de modificar res, simplement propagar les dades
											$$ = $2;
										}
      |			expr '*'            	{ //La expressió apareix 0 o més vegades
      										$$.node_inicial = 0;
      										$$.origen = (int *) malloc(($1.sizeof_a + 2) * sizeof(int));
      										$$.desti = (int *) malloc(($1.sizeof_a + 2) * sizeof(int));
      										$$.caracter = (char *) malloc(($1.sizeof_a + 2) * sizeof(char));
      										$$.sizeof_a = $1.sizeof_a + 2;
      										for (int i = 0; i < $1.sizeof_a; i++){
      											$$.origen[i] = $1.origen[i];
      											$$.caracter[i] = $1.caracter[i];
      											$$.desti[i] = $1.desti[i];
      										}
      										$$.origen[$1.sizeof_a+1] = 0;
      										$$.desti[$1.sizeof_a+1] = $1.node_final;
      										$$.caracter[$1.sizeof_a+1] = '0';
      										$$.origen[$1.sizeof_a] = $1.node_final;
      										$$.desti[$1.sizeof_a] = 0;
      										$$.caracter[$1.sizeof_a] = '0';
      										$$.node_final = $1.node_final;
      									}
      |			expr '+'            	{ //La expressió apareix 1 o més vegades
      										$$.node_inicial = 0;
      										$$.origen = (int *) malloc(($1.sizeof_a + 1) * sizeof(int));
      										$$.desti = (int *) malloc(($1.sizeof_a + 1) * sizeof(int));
      										$$.caracter = (char *) malloc(($1.sizeof_a + 1) * sizeof(char));
      										$$.sizeof_a = $1.sizeof_a + 1;
      										for (int i = 0; i < $1.sizeof_a; i++){
      											$$.origen[i] = $1.origen[i];
      											$$.caracter[i] = $1.caracter[i];
      											$$.desti[i] = $1.desti[i];
      										}
      										$$.origen[$1.sizeof_a] = $1.node_final;
      										$$.desti[$1.sizeof_a] = 0;
      										$$.caracter[$1.sizeof_a] = '0';
      										$$.node_final = $1.node_final;
      									} 
      |			expr '?'            	{ // La expressió pot aparèixer 1 vegada o no
      										$$.node_inicial = 0;
      										$$.origen = (int *) malloc(($1.sizeof_a + 1) * sizeof(int));
      										$$.desti = (int *) malloc(($1.sizeof_a + 1) * sizeof(int));
      										$$.caracter = (char *) malloc(($1.sizeof_a + 1) * sizeof(char));
      										$$.sizeof_a = $1.sizeof_a + 1;
      										for (int i = 0; i < $1.sizeof_a; i++){
      											$$.origen[i] = $1.origen[i];
      											$$.caracter[i] = $1.caracter[i];
      											$$.desti[i] = $1.desti[i];
      										}
      										$$.origen[$1.sizeof_a] = 0;
      										$$.desti[$1.sizeof_a] = $1.node_final;
      										$$.caracter[$1.sizeof_a] = '0';
      										$$.node_final = $1.node_final;
      									}
      |			expr '.' expr           { // Concatenacio, s'ajunten les 2 amb una l-transicio i es modifica la 2a expressió
      										$$.node_inicial = 0;
      										$$.origen = (int *) malloc(($1.sizeof_a + $3.sizeof_a + 1) * sizeof(int));
      										$$.desti = (int *) malloc(($1.sizeof_a + $3.sizeof_a + 1) * sizeof(int));
      										$$.caracter = (char *) malloc(($1.sizeof_a + $3.sizeof_a + 1) * sizeof(char));
      										$$.sizeof_a = $1.sizeof_a + $3.sizeof_a + 1;
      										int estats_s1 = $1.node_final + 1;
      										int i = 0;
      										for (i = 0; i < $1.sizeof_a; i++){
      											$$.origen[i] = $1.origen[i];
      											$$.caracter[i] = $1.caracter[i];
      											$$.desti[i] = $1.desti[i];
      										}
      										$$.origen[i] = $1.node_final;
      										$$.desti[i] = estats_s1;
      										$$.caracter[i] = '0';
      										i++;
      										for (int j = 0; j < $3.sizeof_a; j++){
      											$$.origen[i] = $3.origen[j] + estats_s1;
      											$$.caracter[i] = $3.caracter[j];
      											$$.desti[i] = $3.desti[j] + estats_s1;
      											i++;
      										}
      										$$.node_final = $3.node_final + estats_s1;
      									}
      |			expr '|' expr           { // Expressio expr|expr, vol dir que pot ser o una o l'altra
      										$$.node_inicial = 0;
      										$$.origen = (int *) malloc(($1.sizeof_a + $3.sizeof_a + 4) * sizeof(int));
      										$$.desti = (int *) malloc(($1.sizeof_a + $3.sizeof_a + 4) * sizeof(int));
      										$$.caracter = (char *) malloc(($1.sizeof_a + $3.sizeof_a + 4) * sizeof(char));
      										$$.sizeof_a = $1.sizeof_a + $3.sizeof_a + 4;
      										int i = 0;
      										$$.origen[i] = 0;
      										$$.desti[i] = 1;
      										$$.caracter[i] = '0';
      										int estats_s1 = $1.node_final + 1;
      										for (i = 1; i < $1.sizeof_a + 1; i++){
      											$$.origen[i] = $1.origen[i-1]+1;
      											$$.caracter[i] = $1.caracter[i-1];
      											$$.desti[i] = $1.desti[i-1]+1;
      										}
      										$$.origen[i] = 0;
      										$$.desti[i] = $3.node_inicial+estats_s1+1;
      										$$.caracter[i] = '0';
      										i++;
      										int estats_s3 = $3.node_final + 1;
      										for (int j = 0; j < $3.sizeof_a; j++){
      											$$.origen[i] = $3.origen[j] + estats_s1 + 1;
      											$$.caracter[i] = $3.caracter[j];
      											$$.desti[i] = $3.desti[j] + estats_s1 + 1;
      											i++;
      										}
      										$$.node_final = estats_s1 + estats_s3 + 1;
      										$$.origen[i] = estats_s1;
      										$$.desti[i] = $$.node_final;
      										$$.caracter[i] = '0';
      										i++;
      										$$.origen[i] = $3.node_final + estats_s1 + 1;
      										$$.desti[i] = $$.node_final;
      										$$.caracter[i] = '0';
      										i++;
      									}
      |       	REG               		{	//Expressio tipo a, bc, aab...
      										$$.node_inicial = 0;
      										$$.origen = (int *) malloc(sizeof(int) * strlen($1));
      										$$.desti = (int *) malloc(sizeof(int) * strlen($1));
      										$$.caracter = (char *) malloc(sizeof(char) * strlen($1));
      										$$.sizeof_a = strlen($1);
      										int contador_origen = $$.node_inicial;
      										for (int i = 0; i < strlen($1); i++){
      											$$.origen[i] = contador_origen;
      											$$.caracter[i] = $1[i];
      											contador_origen = contador_origen + 1;
      											$$.desti[i] = contador_origen;
      										}
      										$$.node_final = contador_origen;
      									}
      |			BUIDA					{
      										$$.node_inicial = 0;
      										$$.node_final = 0;
      										$$.origen = (int *) malloc(sizeof(int));
      										$$.desti = (int *) malloc(sizeof(int));
      										$$.caracter = (char *) malloc(sizeof(char));
      										$$.sizeof_a = 1;
      										$$.origen[0] = 0;
      										$$.desti[0] = 0;
      										$$.caracter[0] = '0';
      									}
      |			RANG					{
      										$$.node_inicial = 0;
      										$$.node_final = 1;
      										$$.sizeof_a = ($1.final - $1.inicial);
      										if ($$.sizeof_a <= 0){
      											$$.sizeof_a = 1;
      											$$.origen = (int *) malloc(sizeof(int) * $$.sizeof_a);
		  										$$.desti = (int *) malloc(sizeof(int) * $$.sizeof_a);
		  										$$.caracter = (char *) malloc(sizeof(char) * $$.sizeof_a);
		  										$$.origen[0] = 0;
		  										$$.desti[0] = 1;
		  										$$.caracter[0] = '0';
      										}else{
      											$$.origen = (int *) malloc(sizeof(int) * $$.sizeof_a);
		  										$$.desti = (int *) malloc(sizeof(int) * $$.sizeof_a);
		  										$$.caracter = (char *) malloc(sizeof(char) * $$.sizeof_a);
		  										for(int i = 0; i < $$.sizeof_a; i++){
			  										$$.origen[i] = 0;
			  										$$.desti[i] = 1;
		  											$$.caracter[i] = $1.inicial+i;
		  										}
		  									}
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
