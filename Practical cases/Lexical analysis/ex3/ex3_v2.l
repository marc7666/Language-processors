%option nounput
%option noinput

%x panic inside_comment
%{
  #include<string.h>
  char error[24];
  int character_err = 0;
  int lines = 0;
  int cn = 0;
%}

operators ("|"|"."|"*"|"+"|"?"|"("|")"|"["|"]"|"-")
vars [a-z]+
reserved ("buida"|"BUIDA")
separators [ \t]+

%%

"--"				{
						BEGIN(inside_comment);
						ECHO;
					}
<inside_comment>\n {
						ECHO;
            			character_err += 1;
						lines += 1;
						cn = 0;
						BEGIN(0);
					}
<panic>\n			{
						printf("\n ERROR at line %i:%i\n", lines, character_err);
						printf(" Caused by %s\n", error);
						strcpy(error, "");
						lines += 1;
						cn = 0;
						BEGIN(0);
					}
{operators}		|
{separators}	|
{reserved}		|
{vars}			{
					character_err += strlen(yytext);
					ECHO;
				}
\n				{
					ECHO;
					lines += 1;
					character_err = 0;
					cn = 0;
				}
.				{
					BEGIN(panic);
					strcpy(error, yytext);
					ECHO;
				}
