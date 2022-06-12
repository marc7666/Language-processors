%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "symtab.h"

  #define NOVAL -1

  #define TINT 0
  #define TREAL 1
  #define TCHAR 2
  #define TBOOL 3
  #define TSTRING 4

  extern int lines;
  extern int yylex();
  void yyerror (char const *);

  extern FILE * yyin;
  extern FILE * yyout;

  info_TS tid;

  typedef struct info_variable {
    int tipus;
    char *lexema;
  } info_var;
%}

%union {
  void *sense_atribut;
  int valor_enter;
  float valor_real;
  char caracter;
  char *lexema;
  struct variable_s {
    int tipus;
    char *lexema;
  } variable;
}

%start programa

%token INT BOOL CHAR FLOAT ENTER REAL IDEN CARACTER BOOLEAN STRING CADENA
%token IF ELSE DO WHILE FOR1 FOR2 FOR3 ADDTO SUBFROM MULTBY DIVBY

%right NOT
%left AND OR
%left IMPLICA IMPLICADOB

%left LT GT GTE LTE EQ NE

%left '+' '-'
%left '*' DIV MOD INTDIV POWER
%right UMENYS

%type<sense_atribut> programa instruccio llista_inst
%type<valor_enter> declaracio declaracio_variable declaracio_amb_IDEN
%type<valor_enter> assignacio assignacio_dec
%type<sense_atribut> condicio comparacio
%type<valor_enter> operacio operador_assignador
%type<sense_atribut> crida_a_funcio parametres
%type<sense_atribut> instruccio_while

%type<valor_enter> expr

%type<valor_enter> ENTER REAL CARACTER BOOLEAN CADENA
%type<valor_enter> BOOL CHAR INT FLOAT STRING tipus

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
                        printf("(TORNANT A NORMALITAT DESPRÉS D'ERROR)");
                        yyerrok;
                      }

instruccio_for: FOR1 '(' llista_inst ')' FOR2 '(' llista_inst ')' FOR3 '(' condicio ')' '{' llista_inst '}' {;}

instruccio_do: DO '{' llista_inst '}' WHILE '(' condicio ')' ';' {;}

instruccio_while: WHILE '(' condicio ')' '{' llista_inst '}' {;}

crida_a_funcio: IDEN '(' parametres ')' {;}
              | IDEN '(' ')' {;}

parametres: expr {;}
          | expr ',' parametres {;}

operacio: IDEN operador_assignador expr {
                                          int tipus = -2;
                                          if(sym_lookup($1, &tid) != SYMTAB_OK){
                                            fprintf(stderr, "ERROR: Identificador (%s) no declarat (%i)\n", $1, lines);
                                            YYERROR;
                                          }else{
                                            tipus = tid.tipus;
                                          }
                                          printf("%i %s", tipus, $1);
                                          if(tipus == TBOOL){
                                            fprintf(stderr, "ERROR: Tipus incorrecte a l'esquerra (%i)\n", lines);
                                            YYERROR;
                                          }
                                          if($3 == TBOOL){
                                            fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                            YYERROR;
                                          }else{
                                            if(tipus == TINT || tipus == TREAL){
                                              if($3 == TSTRING || $3 == TCHAR){
                                                fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                                YYERROR;
                                              }else{
                                                if (tipus == TREAL || $3 == TREAL){
                                                  $$=TREAL;
                                                }else{
                                                  $$=TINT;
                                                }
                                              }
                                            }else if (tipus == TCHAR) {
                                              if($2 == NOVAL){
                                                fprintf(stderr, "ERROR: Operador no vàlid (%i)\n", lines);
                                                YYERROR;
                                              }else{
                                                if ($2 == TINT){
                                                  if($3 == TCHAR || $3 == TSTRING){
                                                    $$=TSTRING;
                                                  }else if ($3 == TINT){
                                                    $$=TCHAR;
                                                  }else{
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                                    YYERROR;
                                                  }
                                                }else if ($2 == TCHAR){
                                                  if($3 == TINT){
                                                    $$=TCHAR;
                                                  }else{
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                                    YYERROR;
                                                  }
                                                }else{
                                                  if($3 == TINT){
                                                    $$=TSTRING;
                                                  }else{
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                                    YYERROR;
                                                  }
                                                }
                                              }
                                            }else{
                                              if($2 == NOVAL){
                                                fprintf(stderr, "ERROR: Operador no vàlid (%i)\n", lines);
                                                YYERROR;
                                              }else{
                                                if ($2 == TINT){
                                                  if($3 == TINT || $3 == TREAL){
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                                    YYERROR;
                                                  }else{
                                                    $$=TSTRING;
                                                  }
                                                }else if ($2 == TREAL){
                                                  if($3 == TINT){
                                                    $$=TSTRING;
                                                  }else{
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta (%i)\n", lines);
                                                    YYERROR;
                                                  }
                                                }else{
                                                  fprintf(stderr, "ERROR: Operador incorrecte (%i)\n", lines);
                                                  YYERROR;
                                                }
                                              }
                                            }
                                          }
                                        }

operador_assignador:  ADDTO {$$=TINT;}
                    | SUBFROM {$$=TCHAR;}
                    | MULTBY {$$=TREAL;}
                    | DIVBY {$$=NOVAL;}

instruccio_if:  IF '(' condicio ')' '{' llista_inst final_if  {;}

final_if: '}' {;}
        | '}' ELSE '(' condicio ')' '{' llista_inst final_if  {;}
        | '}' ELSE '{' llista_inst '}' {;}

assignacio: IDEN '=' expr {/*Mirar si l'identificador esta a la TS, si no esta mal*/
                            $$=$3;
                          }

assignacio_dec: IDEN '=' expr {/*Mirar si l'identificador esta a la TS, si esta mal*/
                                $$=$3;
                              }

declaracio: tipus declaracio_variable {
                                        if($2 != NOVAL){
                                          if($1 != $2){
                                            //ERROR DE TIPUS
                                            fprintf(stderr, "ERROR: Expressió de tipus incorrecte! (%i)\n", lines);
                                            YYERROR;
                                          }
                                        }
                                        // Si no hi ha error de tipus crear les variables que toqui al symtab
                                      }
          | tipus '[' decla_array {/*Si hi ha algun error es cridarà dins de decla_array*/}

decla_array:  expr ']' IDEN {
                              if ($1 != TINT){
                                fprintf(stderr, "ERROR: La mida ha de ser INT (%i)\n", lines);
                                YYERROR;
                              }
                              if(sym_lookup($3, &tid) == SYMTAB_OK){
                                fprintf(stderr, "ERROR: Identificador (%s) JA declarat (%i)\n", $3, lines);
                                YYERROR;
                              }
                              // Retornar nom i correcte
                            }
            | expr ']' '[' decla_array {/*Retornar nom i que es correcte*/}


declaracio_variable:  declaracio_amb_IDEN {$$=$1;}
                    | declaracio_variable ',' declaracio_amb_IDEN {
                                                                    if($1==NOVAL){
                                                                      $$=$3;
                                                                    }else if ($3==NOVAL){
                                                                      $$=$1;
                                                                    }else{
                                                                      if($1 != $3){
                                                                        // ERROR del tipus d'expressió
                                                                        fprintf(stderr, "ERROR: Expressió de tipus incorrecte! (%i)\n", lines);
                                                                        YYERROR;
                                                                      }else{
                                                                        $$=$1;
                                                                      }
                                                                    }
                                                                    // Propagar nom i tipus
                                                                  }

declaracio_amb_IDEN:  assignacio_dec {$$=$1; /*Retornar struct amb lexema i tipus on tipus es $1*/}
                    | IDEN {
                              if(sym_lookup($1, &tid) == SYMTAB_OK){
                                fprintf(stderr, "ERROR: Identificador (%s) JA declarat (%i)\n", $1, lines);
                                YYERROR;
                              }
                              // Crear struct per retornar lexema + tipus
                              $$=NOVAL;
                            }

expr: IDEN  {
              if(sym_lookup($1, &tid) != SYMTAB_OK){
                fprintf(stderr, "ERROR: Identificador (%s) no declarat (%i)\n", $1, lines);
                YYERROR;
              }else{
                $$ = tid.tipus;
              }
            }
    | '(' expr ')' {$$=$2;}
    | expr '+' expr {;}
    | expr '-' expr {;}
    | expr DIV expr {;}
    | expr '*' expr {;}
    | expr MOD expr {;}
    | expr INTDIV expr {;}
    | expr POWER expr {;}
    | '-' expr %prec UMENYS {;}
    | crida_a_funcio {;}
    | CADENA {$$=TSTRING;}
    | ENTER {$$=TINT;}
    | REAL {$$=TREAL;}
    | CARACTER {$$=TCHAR;}
    | BOOLEAN {$$=TBOOL;}

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

tipus:  INT {$$=TINT;}
      | BOOL {$$=TBOOL;}
      | CHAR {$$=TCHAR;}
      | FLOAT {$$=TREAL;}
      | STRING {$$=TSTRING;}

%%
void yyerror (char const *s){
    printf("YYERROR diu: ");
    fprintf (stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
    return(yyparse());
}
