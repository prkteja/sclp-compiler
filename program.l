%{
# include "user-options.hh"
# include <string.h>
# include <string>
# include <vector>
# include "ast.h"
# include "y.tab.h"
using namespace std;
void yyerror(char *);
extern "C" int yylex();
%}

digit [0-9]
letter [a-zA-Z_]

%%
{digit}+ 			{
							if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: NUM		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						yylval.int_num  = atoi(yytext);
						return NUM; 
					}
int					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: INTEGER		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return INT; 
					}
float 				{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: FLOAT		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return FLOAT; 
					}
bool				{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: BOOL			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return BOOL; 
					}

string				{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: STRING		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return STRING; 
					}
print 				{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: WRITE		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return WRITE; 
					}
read				{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: READ			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return READ; 
					}
void				{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: VOID			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return VOID; 
					}
do					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: DO			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return DO; 
					}
while				{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: WHILE		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return WHILE; 
					}
if					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: IF			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return IF; 
					}					
else 				{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: ELSE 		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return ELSE; 
					}

&&					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: AND			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return AND; 
					}
\|\|					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: OR			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return OR; 
					}
!					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: NOT 			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}

\{|\}|\(|\) 		{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: DELIMITERS	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
\"[^"\n]*["\n"] 	{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: STR_CONST 	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						yylval.string_constant  = new string(yytext);
						return STR_CONSTANT;
					}
=					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: ASSIGN_OP	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
\+					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: PLUS			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
-					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: MINUS		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
\*					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: MULT			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
\/					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: DIV			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
;|,					{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: PUNCTUATION	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}
[0-9]*\.[0-9]*		{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: FNUM			Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						yylval.float_num  = atof(yytext);
						return FNUM; 
					}

{letter}({letter}|{digit})*    	{ 
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: NAME 		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						yylval.id  = new string(yytext);
						return NAME; 
					}

\<					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: LESS_THAN 	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}

\>					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: GREATER_THAN Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}

\<=					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: LESS_THAN_EQUAL	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return LTE; 
					}

\>=					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: GREATER_THAN_EQUAL 	Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return GTE; 
					}

!=					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: NOT_EQUAL		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return NE; 
					}

==					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: EQUAL 		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return EQUAL; 
					}

\?					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: OP_FOR_TERNARY_EXPR 		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}

\:					{
						if(command_options.is_show_tokens_selected()) fprintf (yyout, "Token Name: OP_FOR_TERNARY_EXPR 		Lexeme: %s 		Lineno:%d \n", yytext, yylineno); 
						return yytext[0]; 
					}

\/[\/]+.*|"/*"([^*]|\*+[^*/])*\*+"/" {}
[ ]|\t		    	{ 
					}
\n					{ 
						yylineno++;
					}
					
.					{ 
					yyerror((char*)"invalid character");
					}

%%

int yywrap(){
	if(!command_options.construct_parse()) exit(0);
	else return 1;
}