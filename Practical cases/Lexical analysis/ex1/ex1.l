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
	int types_c = 0;
%}

operators ("+"|"*"|"-"|"/"|"::"|"->"|"="|"<"|">"|".."|"$"|".")
delimiters ("("|")"|"["|"]"|"{"|"}"|"|")
separators [ \t\n]+
reserved ("case"|"class"|"data"|"deriving"|"do"|"else"|"if"|"import"|"in"|"infix"|"infixl"|"infixr"|"instance"|"let"|"of"|"module"|"newtype"|"then"|"type"|"where")
identifiers [a-z'_]+[a-zA-Z'_0-9]*
typevals [A-Z]+[a-zA-Z'_0-9]*
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
						ECHO;
						BEGIN(0);
					}
<inside_string>\n	{
						printf("Wrong string");
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
{typevals}	{
					printf("<TYV>");
					types_c += 1;
					ECHO;
					printf("</TYV>");
				}
{numbers}		{
					printf("<NUM>");
					constants_c += 1;
					ECHO;
					printf("</NUM>");
				}
				
%%

int yywrap(){
	printf("\nEND OF FILE REACHED\n");
	printf("-----------------------\n");
	int total = 0.0;
	total = reserved_words_c + identifiers_c + constants_c + operators_c + delimiters_c + separators_c + comments_c + types_c;
	printf("Total: %i tokens\n", total);
	printf("Reserved words (RES) = %i (%.2f%%)\nIdentifiers (IDF) = %i (%.2f%%)\nTypes and Value Constructors (TYV) = %i (%.2f%%)\nConstants (CON and NUM) = %i (%.2f%%)\nOperators (OP) = %i (%.2f%%)\nDelimiters (DEL) = %i (%.2f%%)\nSeparators (SEP) = %i (%.2f%%)\nComments (COM) = %i (%.2f%%)\n",reserved_words_c,reserved_words_c / (float) total * 100,identifiers_c,identifiers_c / (float) total * 100,types_c,types_c / (float) total * 100,constants_c,constants_c / (float) total * 100,operators_c,operators_c / (float) total * 100,delimiters_c,delimiters_c / (float) total * 100,separators_c,separators_c / (float) total * 100,comments_c,comments_c / (float) total * 100);
		return 1;
}
