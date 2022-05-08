%option nounput
%option noinput

%x panic inside_comment

%{
  #include<string.h>
  #include<stdio.h>
  int char_error = 0;
  int lines = 0;
  char error[24];
  int cn = 0;
%}

operators ("or"|"and"|"||"|"&&"|"->"|"<->"|"!"|"+"|"-"|"*"|"/"|"?"|"("|")"|"["|"]"|"%"|"."|"="|"{"|"}")
varsCharUpper [A-Z]+
varsCharLower [a-z]+
varsInt [0-9]+
varsBool ("True"|"False")+
varsFloat [0-9]+\.[0-9]+
separators [ \t]+
whileStructure ([while]\(\)\{\})+
forStructure ([for]\(\)\{\})+
doWhileStructure ([repeat]\{\}[until]\(\))+
array ([array]\[[0-9]+\])+
matrix ([matrix]\[[0-9]+\]\[[0-9]+\])+

%%

"--"                    {
                            BEGIN(inside_comment);
                            ECHO;
                        }
<inside_comment>\n      {
                            ECHO;
                            char_error += 1;
                            lines += 1;
                            cn = 0;
                            BEGIN(0);
                        }
<panic>\n               {
                            printf("\n ERROR at line %i:%i\n", lines, char_error);
                            printf("Caused by %s\n", error);
                            strcpy(error, "");
                            lines += 1;
                            cn = 0;
                            BEGIN(0);
                        }
{operators}             |
{varsCharUpper}         |
{varsCharLower}         |
{varsInt}               |
{varsBool}              |
{varsFloat}             |
{whileStructure}        |
{doWhileStructure}      |
{forStructure}          |
{separators}            {
                            char_error += strlen(yytext);
                            ECHO;
                        }
\n                      {
                            ECHO;
                            lines += 1;
                            char_error = 0;
                            cn = 0;
                        }
.                       {
                            BEGIN(panic);
                            strcpy(error, yytext);
                            ECHO;
                        }
