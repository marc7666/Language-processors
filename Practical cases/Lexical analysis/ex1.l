%option nounput
%option noinput

%x inside_comment

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
reserved ("if"|"do"|"otherwise")
identifiers [a-zA-Z'_]+[a-zA-Z'_0-9]*
numbers [0-9]*

%%

"--"				{	
					BEGIN(inside_comment);
					ECHO;
				}
<inside_comment>\n {
						comments_c += 1;
						printf("<COM");
						BEGIN(0);
						ECHO;
						printf(">");
						REJECT;
					}
{operators}		{
					operators_c += 1;
					printf("<OP");
					ECHO;
					printf(">");
				}
{delimiters}	{
					delimiters_c += 1;
					printf("<DEL");
					ECHO;
					printf(">");
				}
{separators}	{
					printf("<SEP");
					separators_c += 1;
					ECHO;
					printf(">");
				}
{reserved}		{
					printf("<RES");
					reserved_words_c += 1;
					ECHO;
					printf(">");
				}
{identifiers}	{
					printf("<IDF");
					identifiers_c += 1;
					ECHO;
					printf(">");
				}
{numbers}		{
					printf("<NUM");
					constants_c += 1;
					ECHO;
					printf(">");
				}
				
%%

int yywrap(){
	printf("END OF FILE REACHED\n");
	printf("reserved_words_c = %i\nidentifiers_c = %i\nconstants_c = %i\noperators_c = %i\ndelimiters_c = %i\nseparators_c = %i\ncomments_c = %i\n",reserved_words_c,identifiers_c,constants_c,operators_c,delimiters_c,separators_c,comments_c);
		return 1;
}
