%option nounput
%option noinput


tipus  ("Int"|"Bool")
guards \|
reserved ("do"|"if"|"otherwise")

int tipusv = 0,guardsv = 0, reservedv = 0;
%%

{tipus}          tipusv = tipusv + 1;
{guards}         guardsv = guardsv + 1;
{reserved}       reservedv = reservedv + 1;
"otherwise"      printf("Offwhite");
