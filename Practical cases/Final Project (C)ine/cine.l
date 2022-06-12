%option nounput
%option noinput
%option noyywrap

%x inside_comment inside_string

%{
  #include<string.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include "cine.tab.h"

  int lines = 1;
  char error[24];
%}

%%

"--"                {
                      BEGIN(inside_comment);
                      printf("COMENTARI: ");
                    }
<inside_comment>.\n  {
                      ECHO;
      							  lines += 1;
                      BEGIN(0);
                    }
\"                  {
                      BEGIN(inside_string);
                    }
<inside_string>\"   {
                      BEGIN(0);
                    }
<inside_string>[^\"]+   {
                          printf("STRING (%s)",yytext);
                          return(CADENA);
                        }
"You can take the blue pill"  {
                                printf("IF");
                                return(IF);
                              }
"or you can take the red pill"  {
                                  printf("ELSE");
                                  return(ELSE);
                                }
"I can do this all day"         {
                                  printf("WHILE");
                                  return(WHILE);
                                }
"Fight!"                        {
                                  printf("DO");
                                  return(DO);
                                }
"Are you not entertained?"      {
                                  printf("WHILE");
                                  return(WHILE);
                                }
"Good morning"                  {
                                  printf("FOR1");
                                  return(FOR1);
                                }
"and in case I don't see you, good evening" {
                                              printf("FOR2");
                                              return(FOR2);
                                            }
"and good night"                {
                                  printf("FOR3");
                                  return(FOR3);
                                }
[ \t]+              {
                      ECHO;
                    }
"=="                {
                      printf("EQ");
                      return(EQ);
                    }
"!="                {
                      printf("NE");
                      return(NE);
                    }
"!"|"not"           {
                      printf("NOT");
                      return(NOT);
                    }
"<"                 {
                      printf("LT");
                      return(LT);
                    }
"<="                {
                      printf("LTE");
                      return(LTE);
                    }
">"                 {
                      printf("GT");
                      return(GT);
                    }
">="                {
                      printf("GTE");
                      return(GTE);
                    }
"+="                {
                      printf("ADDTO");
                      return(ADDTO);
                    }
"-="                {
                      printf("SUBFROM");
                      return(SUBFROM);
                    }
"*="                {
                      printf("MULTBY");
                      return(MULTBY);
                    }
"/="                {
                      printf("DIVBY");
                      return(DIVBY);
                    }
"**"                {
                      printf("POWER");
                      return(POWER);
                    }
"//"                {
                      printf("INTDIV");
                      return(INTDIV);
                    }
"/"|"div"           {
                      printf("DIV");
                      return(DIV);
                    }
"%"|"mod"           {
                      printf("MOD");
                      return(MOD);
                    }
("and"|"&&"|"AND")  {
                      printf("AND");
                      return(AND);
                    }
("or"|"||"|"OR")    {
                      printf("OR");
                      return(OR);
                    }
"->"                {
                      printf("IMPLICA");
                      return(IMPLICA);
                    }
"<->"               {
                      printf("DOBLE IMPLICA");
                      return(IMPLICADOB);
                    }
"True"|"False"      {
                      printf("BOOLEAN (%c)", yytext[0]);
                      yylval.caracter = yytext[0];
                      return(BOOLEAN);
                    }
\'.\'               {
                      printf("CHARACTER (%c)", yytext[1]);
                      yylval.caracter = yytext[1];
                      return(CARACTER);
                    }
"int"               {
                      printf("INT");
                      return(INT);
                    }
"bool"              {
                      printf("BOOL");
                      return(BOOL);
                    }
"char"            {
                      printf("CHAR");
                      return(CHAR);
                    }
"float"           {
                      printf("FLOAT");
                      return(FLOAT);
                    }
"string "           {
                      printf("STRING");
                      return(STRING);
                    }
[0-9]+"."[0-9]+     {
                      printf("REAL (%.2f)", atof(yytext));
                      yylval.valor_real = atof(yytext);
                      return(REAL);
                    }
[0-9]+              {
                      printf("ENTER (%d)", atoi(yytext));
                      yylval.valor_enter = atoi(yytext);
                      return(ENTER);
                    }
[a-zA-Z_][a-zA-Z0-9_]*       {
                                yylval.lexema = (char *) malloc(sizeof(char) * strlen(yytext));
                                sprintf(yylval.lexema, "%s", yytext);
                                printf("IDEN (%s)", yytext);
                                return(IDEN);
                    }
\n                  {
                      ECHO;
                      lines += 1;
                    }
.                   {
                      ECHO;
                      return(yytext[0]);
                    }
