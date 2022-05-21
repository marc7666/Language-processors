        /***************************************************************/
        /*               ESPECIFICACIO LEX                             */
        /*        Gestio de tipus basics a les declaracions	           */
        /*   Gestio d'àmbits: begin/end                                */
        /*  Generació de codi 3 adreces sobre variables temoporals    */
        /**************************************************************/

%{
    
    #define MAXNOM 30
    
    typedef struct _doble_cond{
        char label_V[MAXNOM+1];
        char label_F[MAXNOM+1];
    } doble_cond;
    
    typedef struct t_info_expr{
        char *nom;       // lexema amb memòria dinàmica
        int tipus;           // 3 tipus bàsics
    } info_expr;
    
    typedef struct t_info_aux{
        int tipus;           // 3 tipus bàsics
        long int despla;
    } info_aux;
    
    typedef struct t_info_despla_temp{
        long int despla;           // Offset de l'àmbit
        long int temp;             // Numeració variables temporals de l'àmbit
    } info_despla_temp;



    #include "array_if_while_adreces.tab.h"

    int nlin=1;
%}

%array

%option nounput
%option noinput
%option noyywrap

lletra      [a-zA-Z]
digit       [0-9]
id          {lletra}({lletra}|{digit}|_)*

enter       [0-9]+
real        {enter}\.{enter}(e|E[+-]?{enter})?


%%

"the golden mile"     return INICI;

"the world's end"     return FINAL;

[ \t]+           ;       // saltar delimitadors

"//".*\n        { nlin++; }         // comptar línies i saltar comentaris

"int"                 return INT; // paraules reservades

"bool"                return BOOL;

"float"|"double"      return REAL;

"char"                return CHAR;

">="                  {return MAI;}  // Operadors de relació amb múltiples símbols lèxics

"<="                  {return MEI;}

"=="                  {return IG;}

"!="                  {return DIF;}

"You take the blue pill"                  {return IF;} // Paraules reservades: if then else endif

":"          {return THEN;}

"or you take the red pill"          {return ELSE;}

";"         {return ENDIF;}

"I can do this all day"         {return WHILE;} //  Paraules reservades: while do endwhile

"do"            {return DO;}

"are you not entertained?"      {return ENDWHILE;}

"&&"|"and"            {return AND;} // Operadors lògics: && || !

"||"|"or"            {return OR;}

"!"         {return NOT;}

    /* Valor de les constants enteres, reals, char i bool  */

{enter}     { yylval.name = malloc( yyleng+1 );
            // Els valors constants enters es gestionen com string
            strcpy( yylval.name, yytext );
            return VINT; }

{real}      { yylval.name = malloc( yyleng+1 );
            //Els valors constants reals es gestionen com string
            strcpy( yylval.name, yytext );
            return VREAL; }

\'.\'       { yylval.name = malloc( yyleng+1 );
            // Els caràcters es gestionen com string
            // Conté cometes per dif de nom de variables
            strcpy( yylval.name, yytext );
            return VCHAR; }

"true"|"false"  { yylval.name = malloc( yyleng+1 );
                // Els valors constants enters es gestionen com string
                strcpy( yylval.name, yytext );
                return VBOOL; }

        /* Identificadors sempre darrera de totes les paraules reservades */

{id}    { yylval.name = malloc( yyleng+1 );
        strcpy( yylval.name, yytext );
        return ID; }

\n      { nlin++; }              // comptar línies

        /*  resta operadors  1 símbol lèxic */

.       { return(yytext[0]); }    //  Els errors es processaran a nivell sintàctic

