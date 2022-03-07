
%option nounput
%option noinput


%{
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_LEN 30
#define MAX_DEFS 10
#define MAX_BUFFERS 5

char define_dict[MAX_BUFFERS][MAX_DEFS][MAX_LEN];
int define_vals[MAX_BUFFERS][MAX_DEFS][MAX_LEN];
char filename[MAX_NAME + 1];
int buffer_d = 0;
int defs_d[MAX_BUFFERS];
%}

%X DEFINE DEFINED INCLUDE

simbols [a-zA-Z_0-9\\" \t]+

%%
    
^"#include"[ \t]+		{
							BEGIN( INCLUDE );
						}

<INCLUDE>(\"|\<){simbols}+(\.{simbols}+)?(\"|\>)   {
														strcpy(filename, &yytext[1]);
                                                    	filename[yyleng - 2] = '\0';
                                                    	yyin = fopen(filename, "r");
                                                    	assert(yyin != NULL);
                                                    	yypush_buffer_state( yy_create_buffer( yyin, YY_BUF_SIZE ));
                                                    	buffer_d += 1;
                                                    	BEGIN(INITIAL);
                                                    }
                                                    
^"#define"[ \t]+		{
							BEGIN( DEFINE );
						}

<DEFINE>[A-Z_][A-Z_0-9]+	{
								BEGIN (DEFINED);
								strcpy(define_dict[buffer_d][defs_d[buffer_d]], yytext);			
                        	}
<DEFINED>{simbols}		{
							strcpy(define_vals[buffer_d][defs_d[buffer_d]], yytext);
							defs_d[buffer_d] += 1;
							BEGIN(INITIAL);
						}

<<EOF>>                                             {
														yypop_buffer_state();
														buffer_d -= 1;
                                                    	if (!YY_CURRENT_BUFFER) yyterminate();
                                                    	for (int i = 0; i < defs_d[buffer_d]; i++){
                                                    		printf("%s %s\n", define_dict[buffer_d][i],define_vals[buffer_d][defs_d[i]]);	
                                                    	}
                                                    }

.|\n		{
				int found = 0;
				for (int i = 0; i < defs_d[buffer_d]; i++){
					if(strcmp(yytext,define_dict[buffer_d][i]) == 0){
						printf("%s", define_vals[buffer_d][defs_d[i]]);
						found = 1;
					}	
				}
				if (found == 0){
					ECHO;
				}
			}

%%

int main( int argc, char *argv[] ) {
   yyin = fopen( argv[ 1 ], "r" );
   yylex();
   return 0;
}
