%option nounput
%option noinput

%x inside_comment inside_string

%{
	int reserved_words_c = 0;
	int identifiers_c = 0;
	int constants_c = 0;
	int operators_c = 0;
	int delimiters_c = 0;
	int separators_c = 0;
	int comments_c = 0;
%}

operators ("+"|"*"|"-"|"/"|"::"|"->"|"="|"<"|">"|".."|"$"|".")
delimiters ("("|")"|"["|"]"|"{"|"}"|"|")
separators [ \t\n]+
reserved ("case"|"class"|"data"|"deriving"|"do"|"else"|"if"|"import"|"in"|"infix"|"infixl"|"infixr"|"instance"|"let"|"of"|"module"|"newtype"|"then"|"type"|"where")
identifiers [a-z'_]+[a-zA-Z'_0-9]*
numbers [0-9]*


%%

"--"				{	
						BEGIN(inside_comment);
						printf("<COM>");
						ECHO;
					}
\"					{
						BEGIN(inside_string);
						printf("<CON>");
						ECHO;
					}
<inside_comment>\n {
						comments_c += 1;
						ECHO;
						printf("</COM>");
						BEGIN(0);
						REJECT;
					}
<inside_string>\"	{
						constants_c += 1;
						printf("</CON>");
						BEGIN(0);
						ECHO;
					}
<inside_string>\n	{
						printf("SUS!! Wrong string");
						BEGIN(0);
						ECHO;
					}
{operators}		{
					operators_c += 1;
					printf("<OP>");
					ECHO;
					printf("</OP>");
				}
{delimiters}	{
					delimiters_c += 1;
					printf("<DEL>");
					ECHO;
					printf("</DEL>");
				}
{separators}	{
					printf("<SEP>");
					separators_c += 1;
					ECHO;
					printf("</SEP>");
				}
{reserved}		{
					printf("<RES>");
					reserved_words_c += 1;
					ECHO;
					printf("</RES>");
				}
{identifiers}	{
					printf("<IDF>");
					identifiers_c += 1;
					ECHO;
					printf("</IDF>");
				}
{numbers}		{
					printf("<NUM>");
					constants_c += 1;
					ECHO;
					printf("</NUM>");
				}
				
%%

int yywrap(){
	printf("END OF FILE REACHED\n");
	printf("reserved_words_c = %i\nidentifiers_c = %i\nconstants_c = %i\noperators_c = %i\ndelimiters_c = %i\nseparators_c = %i\ncomments_c = %i\n",reserved_words_c,identifiers_c,constants_c,operators_c,delimiters_c,separators_c,comments_c);
		return 1;
}
