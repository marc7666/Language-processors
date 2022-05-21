        /********************************************************************/
        /*              ESPECIFICACIO YACC                                  */
        /*               Gestió atributs                                    */
        /*  Gestio de tipus basics + ARRAY UNIDIMENSIONALS                  */
        /*   Gestio d'àmbits: begin/end                                     */
        /*     If/Else  gestió de labels: codi 3 adreces                    */
        /*   Generació de codi intermedi a partir de les adreces a memòria  */
        /********************************************************************/



%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include"symtab.h"    // Conté la definicio de les Entrades a la TS

#define MAXNOM 30

#define TBOOL 0         // Tipus del IDENTIFICADORS: de més específic a més general
#define TCHAR 1
#define TINT 2
#define TREAL 3

#define MBOOL 1         // Mida en bytes per a cada tipus
#define MCHAR 1
#define MINT 2
#define MREAL 4


#define MAX(x,y) (x)>=(y)?x:y
#define NUL (void *)0

extern int nlin;
extern int yylex();

void yyerror (char const *);

extern FILE * yyin;
extern FILE * yyout;

info_TS tid;        // variable extreure atributs de la TS

long int offset=0;    // Desplaçament respecte el punter a la pila per a les variables locals

long int t_actual=0;  // Numeracio variables temporals

char *aux_l;  // Gestio dels noms de les etiquetes amb mem. dinàmica

int mida(int);   // Obtenir offset de cada tipus

char *new_temp();  // Gestió variables temporals
char *new_label(); // Gestió etiquetes de salt
void convertir(int , char *);
void afegir_temp_TS(char *, int);

typedef struct t_info_expr{
    char *nom;       // lexema amb memòria dinàmica
    int tipus;       // 4 tipus bàsics
} info_expr;

typedef struct t_info_aux{
    int tipus;           // 3 tipus bàsics
    long int despla;
} info_aux;

typedef struct _doble_cond{
    char label_V[MAXNOM+1];
    char label_F[MAXNOM+1];
} doble_cond;

typedef struct t_info_despla_temp{
    long int despla;           // Offset de l'àmbit
    long int temp;             // Numeració variables temporals de l'àmbit
} info_despla_temp;

int out=1;

%}

%union	{
    char *name;       // lexema amb memòria dinàmica
    int tipus_b;           // 4 tipus bàsics
    info_expr vbles;    // gestio variables temporals expressions (TOTS els tipus)!!
    info_aux info;      // informacio gestio errors accés array
    info_despla_temp despla_temp;    // Desplaçament per a cada àmbit
    doble_cond bloc_cond;   // Adreces de salt if/else i while
    void *sense_atribut;    // constructors sense atribut
    }

%start programa

%token<name> ID

%token<name> VINT VREAL VCHAR  VBOOL  // Utilitzem directament el string llegit


%token INT REAL CHAR BOOL

%token INICI FINAL

%token IF THEN ELSE ENDIF WHILE DO ENDWHILE

    // De menor a major precedència: logics, relacionals, aritmètics

%right NOT              /* precedència operadors de lògics */
%left AND
%left OR

%left MAI MEI  '>' '<'    /* precedència operadors de relació */
%left IG DIF

%left '+' '-'           /* precedència operadors aritmètics */
%left '*' '/'
%right UMENYS




%type<tipus_b> tipus llistaid  aux_iden1 aux_iden2

%type<despla_temp> aux_ambit

%type<info> aux_error

%type<vbles> expr
    // Al incorporar els BOOL les condicions s'avaluen com expressions de tipus BOOL

%type <bloc_cond> aux_if aux_while

%type<sense_atribut> programa llistainst inst decla asig ambit iden_decla


%type <sense_atribut>  inst_if else_opcional inst_while


%%

programa    :   { $$=NUL; }       // epsilon (programa buit)
            |   INICI llistainst FINAL
                            {fprintf(yyout,"%d\tHalt\n",out);
                            $$=NUL; }       // FINAL de programa. Àmbit global o principal
            ;

llistainst  :                       { $$=NUL; }        // bloc buit
            | llistainst inst       { $$=NUL; }
            | llistainst  ambit     { $$=NUL; }
            ;

ambit   :   INICI  aux_ambit llistainst  FINAL
                { if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                        fprintf(stderr,"ERROR compilador!!\n");
                        YYERROR;    // ERROR del sistema!!
                    }
                    offset = $2.despla;
                    t_actual = $2.temp;
                    // Restaurar el desplaçament de l'àmbit anterior
                    fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);
                    $$=NUL;
                }
        ;

aux_ambit   :       { if (sym_push_scope()==SYMTAB_STACK_OVERFLOW){
                    //Empilar àmbit i verificar espai pila àmbits disponible
                            fprintf(stderr,"ERROR NO es pot crear nou àmbit de definició. Línea %d \n", nlin);
                            YYERROR;
                        }
                     $$.despla = offset;
                     $$.temp = t_actual;
                // Salvar el desplaçament de l'àmbit anterior (actual abans empilar)
                // Salvar la numeració generada de les variables temporals a l'àmbit actual
                fprintf(yyout,"\n// Empila àmbit. Salva offset actual %ld. Salva temporal actual %ld\n\n", offset, t_actual);
                     }
            ;


inst:      ';'              { $$=NUL; }
        | decla ';'         { $$=NUL; }
        | asig              {$$=NUL;}       // instrucció assignació
        | inst_if           {$$=NUL;}       // instrucció if_else
        | inst_while        {$$=NUL;}       // instrucció while-do
        | error ';'
            {$$=NUL;
            fprintf(stderr,"ERROR INSTRUCCIÓ INCORRECTA: línea %d\n", nlin);
            yyerrok; }      // sortir de l'error amb ;
        ;

decla:	    tipus llistaid       {$$=NUL;}
        ;


tipus   :   BOOL {$$ = TBOOL;}
        |   INT  {$$ = TINT;}
        |   REAL {$$ = TREAL;}
        |   CHAR {$$ = TCHAR;}
        ;

llistaid: 	aux_iden1 iden_decla                 {$$=$1;}
        |  llistaid ','  aux_iden2 iden_decla    {$$=$1;}
            ;

aux_iden1 :            { $$ = $<tipus_b>0;}    // Atribut heretat per a iden_decla
          ;

aux_iden2 :            { $$ = $<tipus_b>-1;}     // Atribut heretat per a iden_decla
          ;

iden_decla :     ID
            {  if (sym_lookup($1, &tid)==SYMTAB_OK){
                //verificar duplicat
                fprintf(stderr,"ERROR ID %s ja definit. Línea %d \n", $1, nlin);
                YYERROR;
                }else{
                    tid.tipus=$<tipus_b>0;
                    tid.despla=offset;
                    offset=offset+(mida(tid.tipus)*1); // Un valor
                    tid.mida=0; // tipus basic
                    sym_add($1,&tid);
                    fprintf(yyout,"\n// Declara Identificador: %s\t Tipus: %d\t ADREÇA: %ld\n\n", $1, tid.tipus,tid.despla);
                    $$ = NUL;}
            }
    |   ID '[' VINT ']'
        {  if (sym_lookup($1, &tid)==SYMTAB_OK){
            //verificar duplicat
            fprintf(stderr,"ERROR ID %s ja definit. Línea %d \n", $1, nlin);
            YYERROR;
            }else { int v = atoi($3);
                    if (v <= 0){
                        fprintf(stderr,"ERROR MIDA %d ARRAY %s. Línea %d \n",v , $1, nlin);
                        YYERROR;
                    }else{
                        tid.tipus=$<tipus_b>0;
                        tid.despla=offset;
                        offset=offset+(mida(tid.tipus)*v);  // VINT valors
                        tid.mida=v; // tipus array
                        sym_add($1,&tid);
                        fprintf(yyout,"\n// Declara ARRAY: %s\t Tipus: %d\t ADREÇA: %ld\t MIDA: %d\n\n", $1, tid.tipus,tid.despla,v);
                        $$ = NUL;
                    }
                }
        }
    ;

asig  :  ID  '='  expr
            { if (sym_lookup($1, &tid) != SYMTAB_OK){
                    //verificar ID definit a l'àmbit actual
                    fprintf(stderr,"ERROR ID %s NO definit. Línea %d \n", $1, nlin);
                    YYERROR;
                }else if (tid.mida!=0){
                        // verificar variable simple
                        fprintf(stderr,"Línea %d: Error accés a array sense índex %s: \n", nlin, $1);
                        YYERROR; }
                        else if (($3.tipus==TBOOL && tid.tipus!=TBOOL) || ($3.tipus > tid.tipus)){
                            // verificar casament de tipus entre ID i exp
                            // expressions logiques només assignables a ID de tipus bool
                                fprintf(stderr,"Línea %d: Error tipus ID %s:  tipus %d = tipus %d\n", nlin, $1, tid.tipus, $3.tipus);
                                YYERROR; }
                            else{ // assignacio OK
                                fprintf(yyout,"%d\t%s  = %s \n", out, $1,  $3.nom); out++;
                                $$=NUL;
                                }
            }
        |  ID '[' expr ']' aux_error '=' expr
            { if (($7.tipus==TBOOL && $5.tipus!=TBOOL) || ($7.tipus > $5.tipus)){
    // verificar casament de tipus entre ID i exp
    // expressions logiques només només assignables a ID de tipus bool
                fprintf(stderr,"Línea %d: Error tipus ID %s:  tipus %d = tipus %d\n", nlin, $1, $5.tipus, $7.tipus);
                YYERROR; }
            else{
                fprintf(yyout, "%d\t%s @ %ld + %s * %d = %s \n",out, $1,$5.despla, $3.nom,mida($5.tipus),$7.nom); out++;
                $$=NUL; }
            }
       ;

aux_error:      {  if (sym_lookup($<name>-3, &tid) != SYMTAB_OK){
                    //verificar existeix ID
                       fprintf(stderr,"ERROR ID %s NO definit. Línea %d \n", $<name>-3, nlin);
                       YYERROR;
                    }else if (tid.mida==0){
                        //verificar si està declarat a tipus ARRAY
                             fprintf(stderr,"ERROR ID %s NO definit com ARRAY. Línea %d \n", $<name>-3, nlin);
                             YYERROR;
                          }else if ($<vbles>-1.tipus > TINT){
                              // index ARRAY TIPUS enter o char (codi 8 bits)
                               fprintf(stderr,"Index tipus %d incorrecte ARRAY %s. Línea %d \n", $<vbles>-1.tipus, $<name>-3, nlin);
                               YYERROR;
                               }
                          $$.tipus=tid.tipus;
                          $$.despla=tid.despla;
                    }
          ;

expr  :   expr '+' expr
            { if ($1.tipus==TBOOL || $3.tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
            }else{
                $$.nom=new_temp();      // Nova variable temporal
               // Afegir temporal a la TS + gestió offset
                afegir_temp_TS($$.nom,MAX($1.tipus,$3.tipus) );
                // tipus expressió més general
                fprintf(yyout, "%d\t%s =  %s ADD %s\n", out, $$.nom,$1.nom,$3.nom); out++;
                $$.tipus = MAX($1.tipus,$3.tipus);
                }
            }
    |   expr '-' expr
            { if ($1.tipus==TBOOL || $3.tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
                }else{  $$.nom=new_temp();      // Nova variable temporal
                    afegir_temp_TS($$.nom,MAX($1.tipus,$3.tipus) );
                    // tipus expressió més general
                    fprintf(yyout, "%d\t%s =  %s DIF %s\n", out, $$.nom,$1.nom,$3.nom); out++;
                    $$.tipus = MAX($1.tipus,$3.tipus);
                }
            }
    |   expr '*' expr
            { if ($1.tipus==TBOOL || $3.tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
            }else{
                $$.nom=new_temp();      // Nova variable temporal
                afegir_temp_TS($$.nom,MAX($1.tipus,$3.tipus) );
                // tipus expressió més general
                fprintf(yyout, "%d\t%s =  %s MULT %s\n",out, $$.nom,$1.nom,$3.nom); out++;
                $$.tipus = MAX($1.tipus,$3.tipus);
            }
        }
    |   expr '/' expr
            { if ($1.tipus==TBOOL || $3.tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();      // Nova variable temporal
                    afegir_temp_TS($$.nom,MAX($1.tipus,$3.tipus) );
                    // tipus expressió més general
                    fprintf(yyout, "%s =  %s ADD %s\n",$$.nom,$1.nom,$3.nom); out++;
                    $$.tipus = MAX($1.tipus,$3.tipus);
                }
            }
    |   '-' expr %prec UMENYS
            { if ($2.tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
                }else{  $$.nom=new_temp();      // Nova variable temporal
                    afegir_temp_TS($$.nom, $2.tipus );
                    // tipus expressió
                    fprintf(yyout, "%d\t%s = MINUS %s\n",out, $$.nom,$2.nom); out++;
                    $$.tipus = $2.tipus;
                    }
            }
    |   ID
            { if (sym_lookup($1,&tid) != SYMTAB_OK){
                //verificar existeix entrada TS
                fprintf(stderr,"Línea %d: ERROR ID %s NO definit\n", nlin, $1);
                YYERROR;
            }else if (tid.mida!=0){
                // verificar variable simple
                fprintf(stderr,"Línea %d: Error accés a array sense índex %s: \n", nlin, $1);
                YYERROR; }
                    else { // entrada correcta
                        $$.nom=$1;   // Actualitzar el * lexema de l'id
                        $$.tipus = tid.tipus;

                    }
            }
    |   ID '[' expr ']'
        {  if (sym_lookup($1, &tid) != SYMTAB_OK){
            //verificar existeix
            fprintf(stderr,"ERROR ID %s NO definit. Línea %d \n", $1, nlin);
            YYERROR;
            }else if (tid.mida==0){
                //verificar definit tipus ARRAY
                fprintf(stderr,"ERROR ID %s NO definit com ARRAY. Línea %d \n", $1, nlin);
                YYERROR;
            }else if ($3.tipus != TINT){
                // index enter
                fprintf(stderr,"Index tipus %d incorrecte ARRAY %s. Línea %d \n", $3.tipus, $1, nlin);
                YYERROR;
                }else{ // NOVA temporal per garantir màxim 3 adreces
                    $$.nom=new_temp();    // Nova variable temporal
                    afegir_temp_TS($$.nom,tid.tipus);
                    // tipus expressió més general
                    fprintf(yyout, "%d\t%s =  *(%s @ %ld + %s * %d)\n",out, $$.nom,$1,tid.despla,$3.nom, mida(tid.tipus)); out++;
                    $$.tipus = tid.tipus;
                }
        }
    | '(' expr ')'  { $$.nom=$2.nom;
                    // Actualitzar el * nom variable expressio
                    $$.tipus = $2.tipus; }
    |   VINT    { $$.nom=$1;  // lexema del valor enter
                $$.tipus=TINT; }
    |   VREAL   { $$.nom=$1;    // lexema del valor real
                $$.tipus = TREAL;}
    |   VCHAR   {  $$.nom=$1;  // lexema del caràcter
                $$.tipus = TCHAR; }
    |   VBOOL   {  $$.nom=$1;  // lexema: true  / false
                $$.tipus = TBOOL; }
    |   NOT expr
            { if ($2.tipus != TBOOL){
                        fprintf(stderr,"Error tipus %s. Línea %d \n", $2.nom, nlin);
                        YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = NOT %s\n",out,$$.nom,$2.nom); out++;
                    }
            }
    |   expr AND
        { if ($1.tipus != TBOOL){
            fprintf(stderr,"Error tipus %s. Línea %d \n", $1.nom, nlin);
            YYERROR;}
        }
        expr
        { if ($4.tipus != TBOOL){
            fprintf(stderr,"Error tipus %s. Línea %d \n", $4.nom, nlin);
            YYERROR;
            }else{
                $$.nom=new_temp();
                $$.tipus = TBOOL;
                afegir_temp_TS($$.nom,$$.tipus);
                fprintf(yyout, "%d\t%s = %s AND %s\n",out,$$.nom,$1.nom,$4.nom);
                out++; }
        }
    |   expr OR
            { if ($1.tipus != TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", $1.nom, nlin);
                YYERROR;}
            }
        expr
            { if ($4.tipus != TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", $4.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s OR %s\n",out,$$.nom,$1.nom,$4.nom);
                    out++; }
            }
    |   expr '>'
            { if ($1.tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", $1.nom, nlin);
                YYERROR;}
            }
        expr
            { if ($4.tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", $4.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s GT %s\n",out,$$.nom,$1.nom,$4.nom);
                    out++; }
            }
    |   expr '<'
            { if ($1.tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", $1.nom, nlin);
                YYERROR;}
            }
        expr
            { if ($4.tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", $4.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s LT %s\n",out,$$.nom,$1.nom,$4.nom);
                    out++; }
            }
    |   expr MAI
            { if ($1.tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", $1.nom, nlin);
                YYERROR;}
            }
        expr
            { if ($4.tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", $4.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s GEQ %s\n",out,$$.nom,$1.nom,$4.nom);
                    out++; }
            }
    |   expr MEI
            { if ($1.tipus == TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", $1.nom, nlin);
                YYERROR;}
                }
        expr
            { if ($4.tipus == TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", $4.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s LEQ %s\n",out,$$.nom,$1.nom,$4.nom);
                    out++; }
            }

    |   expr IG expr
            { if ($1.tipus != $3.tipus){
                // comparacions d'igualtat amb tipatge estricte
                fprintf(stderr,"Error tipus %s comparació amb %s. Línea %d \n", $1.nom,$3.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s EQ %s\n",out,$$.nom,$1.nom,$3.nom);
                    out++; }
            }
    |   expr DIF expr
            { if ($1.tipus != $3.tipus){
                // comparacions amb tipatge estricte
                fprintf(stderr,"Error tipus %s comparació amb %s. Línea %d \n", $1.nom,$3.nom, nlin);
                YYERROR;
                }else{
                    $$.nom=new_temp();
                    $$.tipus = TBOOL;
                    afegir_temp_TS($$.nom,$$.tipus);
                    fprintf(yyout, "%d\t%s = %s DIFF %s\n",out,$$.nom,$1.nom,$3.nom);
                    out++; }
                }
    ;

inst_if :   IF expr
                { if ($2.tipus != TBOOL){
                    fprintf(stderr,"Error tipus condició IF %s. Línea %d \n", $2.nom, nlin);
                    YYERROR;}
                }
            aux_if
            aux_ambit
                { fprintf(yyout,"%d\tif false %s goto %s\n",out,$2.nom,$4.label_F);
                out++; }
            THEN llistainst
                { fprintf(yyout, "%d\tgoto %s\n",out,$4.label_V); out++;
                fprintf(yyout, "%d Label %s:\n",out,$4.label_F); out++;
                offset = $5.despla;
                t_actual = $5.temp;
                // Restaurar el desplaçament de l'àmbit actual (abans d'empilar)
                // Desempilar ambit IF
                if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                    fprintf(stderr,"ERROR compilador!!\n");
                    YYERROR;    // ERROR del sistema!!
                }
                else{fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);}
                }
            else_opcional
            ENDIF
                { fprintf(yyout, "%d Label %s:\n",out,$4.label_V); out++;
                $$=NUL; }
        | error ENDIF
                    {  $$=NUL;
                    fprintf(stderr,"ERROR IF/ELSE INCORRECTE: línea %d\n", nlin);
                    yyerrok; }           // sortir de l'error amb endif
        ;

aux_if      :      {    // constructor auxiliar per les etiquetes IF
                    aux_l = new_label();
                    strcpy($$.label_V, aux_l);
                    free(aux_l);
                    aux_l = new_label();
                    strcpy($$.label_F, aux_l);
                    free(aux_l);
                    }
            ;

else_opcional   :      { $$=NUL; } // epsilon (buida) (ELSE BUIT)
                |   ELSE  aux_ambit  llistainst
                        { offset = $2.despla;
                        t_actual = $2.temp;
                        // Restaurar el desplaçament de l'àmbit actual (abans d'empilar l'àmbit del ELSE)
                        $$=NUL;
                        // Desempilar ambit ELSE
                        if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                            fprintf(stderr,"ERROR compilador!!\n");
                            YYERROR;    // ERROR del sistema!!
                            }else{fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);}
                        }
                ;

inst_while :    WHILE aux_while
                    { fprintf(yyout, "%d Label %s:\n",out,$2.label_V); out++; }
                expr
                    { if ($4.tipus != TBOOL){
                        fprintf(stderr,"Error tipus condició WHILE %s. Línea %d \n", $4.nom, nlin);
                        YYERROR;
                        }else{
                            fprintf(yyout,"%d\tif false %s goto %s\n",out,$4.nom,$2.label_F);
                            out++; }
                    }
                aux_ambit
                DO llistainst ENDWHILE
                    { fprintf(yyout, "%d\tgoto %s\n",out,$2.label_V); out++;
                    fprintf(yyout, "%d Label %s:\n",out,$2.label_F); out++;
                    offset = $6.despla;
                    t_actual = $6.temp;
                    // Restaurar el desplaçament de l'àmbit actual (abans d'empilar l'àmbit del WHILE)
                    $$=NUL;
                    // Desempilar ambit IF
                    if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                        fprintf(stderr,"ERROR compilador!!\n");
                        YYERROR;    // ERROR del sistema!!
                        }else{fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);}
                    }
            | error ENDWHILE
                    { $$=NUL;
                    fprintf(stderr,"ERROR WHILE/DO INCORRECTE: línea %d\n", nlin);
                    yyerrok; }           // sortir de l'error amb endwhile
            ;

aux_while   :      { // constructor auxiliar etiquetes WHILE
                    aux_l = new_label();
                    strcpy($$.label_V, aux_l);
                    free(aux_l);
                    aux_l = new_label();
                    strcpy($$.label_F, aux_l);
                    free(aux_l);
                    }
            ;

%%

    // Called by yyparse on error

void yyerror (char const *s){
    fprintf (stderr, "%s\n", s);
}


int main(int argc, char *argv[]){
    if (argc>=2){
        yyin = fopen( argv[1], "r" );
    }
    if (argc==3){
        yyout = fopen( argv[2], "w" );
    }
    if (argc > 3){
        fprintf(stderr, "Error paràmetres línia comanda");
        return 1;
    }
    return(yyparse());

}

int mida(int t){
    int m;
    switch (t){
        case TCHAR: m= MCHAR; break;
        case TINT: m= MINT; break;
        case TREAL: m= MREAL; break;
    }
    return m;
}

char *new_temp() {
    char *etiq;

    t_actual++;
    etiq = (char *)malloc(MAXNOM+1);
    strcpy(etiq,"temp");
    convertir(t_actual, etiq+4);
    return etiq;
}

char *new_label(){
    char *temp;
    static int actual=0;

    actual++;
    temp = (char *)malloc(MAXNOM+1);
    strcpy(temp,"etiq");
    convertir(actual, temp+4);
    return temp;
}

void convertir(int valor, char *etiq){
    int c,r;
    char aux[MAXNOM+1];
    int i=0;

    c=valor;

    while (c>=10){
        r= c%10;
        c= c/10;
        aux[i]= r+'0';
        i++;
    }
    aux[i]= c+'0';

    while (i>=0){
        *etiq=aux[i];
        i--;
        etiq++;
    }
    *etiq='\0';

}

void afegir_temp_TS(char *temp_nom, int temp_tipus){
    info_TS info_temp;
    // variable local crear atributs de la variable temporal a la TS

    info_temp.tipus=temp_tipus;
    info_temp.despla=offset;
    offset=offset+mida(temp_tipus); // Un valor
    info_temp.mida=0; // tipus basic
    sym_add(temp_nom,&info_temp);
}
