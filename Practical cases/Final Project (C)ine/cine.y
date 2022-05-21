%{
  #include <stdio.h>
  #include <stdlib.h>

  extern int yylex();
  void yyerror (char const *);

  extern FILE * yyin;
  extern FILE * yyout;
%}

%union {
  void *sense_atribut;
  int valor_enter;
  float valor_real;
  char caracter;
  char *lexema;
}

%start programa

%token INT BOOL CHAR FLOAT ENTER REAL IDEN CARACTER BOOLEAN STRING
%token IF ELSE DO WHILE FOR1 FOR2 FOR3 ADDTO SUBFROM MULTBY DIVBY

%right NOT
%left AND OR
%left IMPLICA IMPLICADOB

%left LT GT GTE LTE EQ NE

%left '+' '-'
%left '*' DIV MOD INTDIV POWER
%right UMENYS

%type<sense_atribut> programa tipus instruccio llista_inst
%type<sense_atribut> declaracio declaracio_variable declaracio_amb_IDEN
%type<sense_atribut> assignacio
%type<sense_atribut> condicio comparacio
%type<sense_atribut> operacio operador_assignador
%type<sense_atribut> crida_a_funcio parametres
%type<sense_atribut> instruccio_while

%type<valor_enter> ENTER
%type<valor_real> REAL
%type<caracter> CARACTER BOOLEAN
%type<lexema> IDEN

%%

programa:   {;}
        |   llista_inst {;}

llista_inst: instruccio  {;}
            | llista_inst instruccio  {;}

instruccio: declaracio ';' {printf("(DECLARACIÓ EXITOSA)");}
          | assignacio ';' {printf("(ASSIGNACIÓ EXITOSA)");}
          | operacio ';'  {printf("(OPERACIÓ EXITOSA)");}
          | instruccio_if {printf("(IF EXITÓS)");}
          | instruccio_while {printf("(WHILE EXITÓS)");}
          | instruccio_do {printf("(DO WHILE EXITÓS)");}
          | instruccio_for {printf("(FOR EXITÓS)");}
          | crida_a_funcio ';' {printf("(CRIDA A FUNCIÓ EXITOSA)");}
          | error ';' {
                        yyerrok;
                      }

instruccio_for: FOR1 '(' llista_inst ')' FOR2 '(' llista_inst ')' FOR3 '(' condicio ')' '{' llista_inst '}' {;}

instruccio_do: DO '{' llista_inst '}' WHILE '(' condicio ')' ';' {;}

instruccio_while: WHILE '(' condicio ')' '{' llista_inst '}' {;}

crida_a_funcio: IDEN '(' parametres ')' {;}
              | IDEN '(' ')' {;}

parametres: expr {;}
          | expr ',' parametres {;}

operacio: IDEN operador_assignador expr {;}

operador_assignador:  ADDTO {;}
                    | SUBFROM {;}
                    | MULTBY {;}
                    | DIVBY {;}

instruccio_if:  IF '(' condicio ')' '{' llista_inst final_if  {;}

final_if: '}' {;}
        | '}' ELSE '(' condicio ')' '{' llista_inst final_if  {;}
        | '}' ELSE '{' llista_inst '}' {;}

assignacio: IDEN '=' expr {;}

declaracio: tipus declaracio_variable {;}

declaracio_variable:  declaracio_amb_IDEN {;}
                    | declaracio_variable ',' declaracio_amb_IDEN {;}

declaracio_amb_IDEN:  assignacio {;}
                    | IDEN {;}

expr: IDEN {;}
    | '(' expr ')' {;}
    | expr '+' expr {;}
    | expr '-' expr {;}
    | expr DIV expr {;}
    | expr '*' expr {;}
    | expr MOD expr {;}
    | expr INTDIV expr {;}
    | expr POWER expr {;}
    | '-' expr %prec UMENYS {;}
    | crida_a_funcio {;}
    | STRING {;}
    | ENTER {;}
    | REAL {;}
    | CARACTER {;}
    | BOOLEAN {;}

condicio: '(' condicio ')' {;}
        | NOT condicio {;}
        | condicio AND condicio {;}
        | condicio OR condicio  {;}
        | condicio IMPLICA condicio  {;}
        | condicio IMPLICADOB condicio  {;}
        | expr comparacio expr  {;}
        | BOOLEAN {;}

comparacio: EQ  {;}
          | NE  {;}
          | LT  {;}
          | LTE {;}
          | GT  {;}
          | GTE {;}

tipus:  INT {;}
      | BOOL {;}
      | CHAR {;}
      | FLOAT {;}

%%
void yyerror (char const *s){
    printf("YYERROR diu: ");
    fprintf (stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
    return(yyparse());
}
