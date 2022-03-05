%option nounput
%option noinput

%x panic inside_comment

%{
  #include<string.h>
  char error[24];
  int character_err = 0;
%}

operators ("|"|"."|"*"|"+"|"?"|"("|")"|"["|"]"|"-")
vars [a-z]+
vars2 ["buida"|"BUIDA"]
delimiters (\n)
separators [ \t]+

%%

^()

"--"  {
        BEGIN(inside_comment);
        ECHO;
      }
<inside_comment>\n {
                      ECHO;
                      character_err += 1;
                      BEGIN(0);
                   }
<panic>\n          {
                      printf("\n ERROR at character %i\n", character_err);
                      printf(" Caused by %s\n", error);
                      strcpy(error, "");
                      BEGIN(0);
                    }
{operators}         |
{delimiters}        |
{separators}        |
{vars}  {
          ECHO;
        }
