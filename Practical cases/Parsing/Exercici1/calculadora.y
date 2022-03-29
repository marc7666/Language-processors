        /************************************************/
        /*              ESPECIFICACIO YACC              */
        /*         Calculadora amb registres            */
        /************************************************/

	
		
%{
	
	#include<stdio.h>
	#include<ctype.h>
    
    int regs[26]={0};
    double reals[26]={0};
	
	extern int nlin;
    extern int yylex(void);
    void yyerror (char const *);

	

%}
	

%start calculadora

%union{	int valor;
		int reg;
		float valr;
		}

%token <reg> REGI
%token <reg> REGL
%token <valor> INT
%token <valr> REAL

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMENYS        /* precedencia de l'operador unari menys */

%type <valr> expr sentencia calculadora
%type <valor> expri

%%

calculadora	:           {;}
       			 |       calculadora sentencia
       			 ;
sentencia  :    '\n' 			{;}
				| 	 expri '\n'			   {fprintf(stdout,"ENTER: %d \n", $1);}
                |	 expr '\n'             {fprintf(stdout,"REAL: %.2f \n", $1);}
                |    REGI '=' expri '\n'    {regs[$1] = $3;}
                |    REGL '=' expr '\n'    {reals[$1] = $3;}
                |    error '\n'           {fprintf(stderr,"ERROR EXPRESSIO INCORRECTA Línea %d \n", nlin);
                                            yyerrok;	}

         		  ;
         		  
expri :		  expri '%' expri           {$$ = $1 % $3;}
      |       expri '&' expri           {$$ = $1 & $3;}
      |       expri '|' expri           {$$ = $1 | $3;}
	  |		  '(' expri ')'             {$$ = $2;}
      |       expri '+' expri            {$$ = $1 + $3;}
      |       expri '-' expri            {$$ = $1 - $3;} 
      |       expri '*' expri            {$$ = $1 * $3;}
      |       expri '/' expri            {if ($3)
                                          $$ = $1 / $3;
                                         else
                                          {fprintf(stderr,"Divisio per zero \n");
                                           YYERROR;}
                                          }
      |       '-' expri %prec UMENYS   {$$ = - $2;}
      |       REGI                  {$$ = regs[$1];}
      |       INT                {$$ = $1;}
      ;
      
expr  :        '(' expr ')'             {$$ = $2;}
      |        expr '+' expr            {$$ = $1 + $3;}
      |        expr '-' expr            {$$ = $1 - $3;} 
      |        expr '*' expr            {$$ = $1 * $3;}
      |        expr '/' expr            {if ($3)
                                          $$ = $1 / $3;
                                         else
                                          {fprintf(stderr,"Divisio per zero \n");
                                           YYERROR;}
                                          }
      |       '-' expr %prec UMENYS   {$$ = - $2;}
      |		  expri					{$$ = (float) $1;}
      |		  REGL				{$$ = reals[$1];}
      | 	  REAL				{$$ = $1;}
      ;

%%

/* Called by yyparse on error. */

void yyerror (char const *s){
    fprintf (stderr, "%s\n", s);
}

int main(){
        
    if (yyparse()==0){
        for (int i=0; i<26; i++)
        if (regs[i]!=0)
        printf("%c = %d \n", 'a'+i, regs[i]);
        for (int i=0; i<26; i++)
        if (reals[i]!=0)
        printf("%c = %.2f \n", 'A'+i, reals[i]);
        return(0);
    }
    else
    return(1);
    
}
