%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iterator>
#include <fstream>
#include "symbol-table.h"
#include "ast.h"
#include "user-options.hh"
using namespace std;
void yyerror(char* );
extern "C" int yylex(void);
extern char* yytext;
extern int yylineno;
vector<data_type> arg_data_types;
symbol_table* global_symtab = new symbol_table(global);
symbol_table* local_symtab = new symbol_table(local);
symbol_table* universal_symtab = new symbol_table(local);
FILE* astout = stdout;
FILE* tacout = stdout;
bool declared = false;
%}

%union{
	int int_num;
	float float_num;
	std::string* id;
	std::string* string_constant;
	ast_node * ast;
	std::vector<ast_node *> * ast_node_list;
	symbol_table * sym_tab;
	symbol_table_entry* sym_tab_entry;
	std::vector<symbol_table_entry*> * symbol_table_entry_list;
	program_node * program;
	data_type d_type;
	procedure_node* procedure;
}
%token<int_num> NUM
%token<float_num> FNUM
%token<id> NAME
%token<string_constant> STR_CONSTANT
%token INT BOOL FLOAT STRING WRITE READ VOID ASSIGN_OP UMINUS AND OR GTE LTE NE EQUAL
%token DO WHILE IF ELSE 

%type<ast_node_list> statement_list 
%type<symbol_table_entry_list> varlist  variable_declaration optional_variable_declaration_list  arg_list optional_arg_list
%type<d_type> type
%type<program> program
%type<sym_tab_entry> arg
%type<ast> assignment print read exp statement while_stmt do_while_stmt if_else_stmt optional_else_stmt
%type<procedure> procedure_definition procedure_declaration


%right '?' ':'
%left OR
%left AND 
%right '!'
%nonassoc '<' '>' LTE GTE EQUAL NE
%left '+' '-'
%left '*' '/'
%right UMINUS
%start program
%%

program : procedure_definition{
			if(command_options.construct_ast()){
				$$ = new program_node();
				$$->add_procedure($1);
				if(command_options.is_show_ast_selected()){ 
					string file_name = command_options.get_file_name();
					if(!command_options.is_demo_mode_selected()){
						astout = fopen((file_name+".ast").c_str(), "w");
					};
					fprintf(astout, "Program:\n");
					$1->print_node(astout);
				};
			};
		}
		| variable_declaration program{
			if(command_options.construct_ast()){
					for(vector<symbol_table_entry*>::iterator it = (*$1).begin();it!=(*$1).end();it++){
						(*it)->set_symbol_scope(global);
						if(! global_symtab->check_entry((*it)->get_var_name()))  
							global_symtab->push_entry(*it);
						else{
							cerr << "Variable has been declared more than once in Global scope\n";
							exit(1);
						}
					}
					$$ =  $2;
				}
		}
		| procedure_declaration program
			{
				$$ = $2;
			}
		; 

procedure_declaration	: type NAME '(' optional_arg_list ')' ';' 
							{
								if(command_options.construct_ast()){
									if(!declared){
										if($1 == void_type and *$2 == "main"){
											for(vector<symbol_table_entry*>::iterator it = (*$4).begin();it!= (*$4).end();it++){
												if((*it)->get_var_name()=="main"){
													cerr<<"arguments name shouldn't be name\n";
													exit(1);
												};
												arg_data_types.push_back((*it)->get_data_type());
											}
											$$ = new procedure_node(void_type,$2,local_symtab,yylineno);
										}
										else{
											cerr<< "procedure_declaration type must be void and name of func should be main\n";
											exit(1);
										};
										declared = true;
									} else {
										cerr << "Procedure redeclaration\n";
										exit(1);
									}
								}
							}
						;

type	:	INT
				{
					if(command_options.construct_ast()){
						$$ = int_type;
					}
				}
			| BOOL
				{
					if(command_options.construct_ast()){
						$$ = bool_type;
					}
				}
			| FLOAT
				{
					if(command_options.construct_ast()){
						$$ = float_type;
					}

				}
			| VOID
				{
					if(command_options.construct_ast()){
						$$ = void_type;
					}
				}
			| STRING
				{
					if(command_options.construct_ast()){
						$$ = string_type;
					}
				}
			; 

arg 	: type NAME 
			{
				$$ = new symbol_table_entry(*$2,$1,yylineno);
			}
		;

arg_list	: arg
				{
					if(command_options.construct_ast()){
						$$ = new vector<symbol_table_entry *>();
						$$->push_back($1);
					}
				}
			| arg_list ',' arg
				{
					if(command_options.construct_ast()){
						$1->push_back($3);
						$$ = $1;
					}
				}
			;

optional_arg_list  : /*empty*/
						{
							if(command_options.construct_ast()){
								$$ = new vector<symbol_table_entry*>();
							}
						}
					| arg_list
						{
							if(command_options.construct_ast()){
								$$ = $1;
							}
						}
					;

procedure_definition 	: type NAME '(' optional_arg_list ')' '{' optional_variable_declaration_list statement_list '}' 
							{
								if(command_options.construct_ast()){
									if($1 == void_type and *$2 == "main"){
										if(arg_data_types.size() > 0 and (*$4).size() != arg_data_types.size()) {
											cout<<arg_data_types.size()<<endl;
											cerr<<"number of arguments must match in procedure\n";
											exit(1);
										}
										int i =0;
										for(vector<symbol_table_entry*>::iterator it = (*$4).begin();it!= (*$4).end(),i<arg_data_types.size();it++,i++){
											if((*it)->get_data_type() != arg_data_types[i]){
												cerr<<"type of arguments must be same in procedure and its declaration\n";
												exit(1);
											};
										}
										for(vector<symbol_table_entry*>::iterator it = (*$4).begin();it!= (*$4).end();it++){
											if(! local_symtab->check_entry((*it)->get_var_name())){
												if((*it)->get_var_name()=="main"){
													cerr<<"arguments name shouldn't be main\n";
													exit(1);
												};
												local_symtab->push_entry(*it);
											}
											else{
												cerr << "Argument has been declared more than once\n";
												exit(1);
											}
										}

										for(vector<symbol_table_entry*>::iterator it = (*$7).begin();it!= (*$7).end();it++){
											if(! local_symtab->check_entry((*it)->get_var_name())){
												if((*it)->get_var_name()=="main"){
													cerr<<"arguments name shouldn't be main\n";
													exit(1);
												};
												local_symtab->push_entry(*it);
											}
											else{
												cerr << "Argument and local Variable has same name\n";
												exit(1);
											}
										}


										$$ = new procedure_node(void_type,$2,local_symtab,yylineno);
										$$->add_stmt_list(*$8);
										$$->add_arg(*$4);
										if(command_options.construct_tac()){
											vector<tac_stmt> taclist = build_tac($$);
											if(command_options.is_show_tac_selected()){ 
												string file_name = command_options.get_file_name();
												if(!command_options.is_demo_mode_selected()){
													tacout = fopen((file_name+".tac").c_str(), "w");
												};
												fprintf(tacout, "**PROCEDURE: main\n");
												print_tac(taclist, tacout);
											}
										}
									}
									else{
										cerr<<"procedure return type must be void and name of func should be main";
										exit(1);
									}
								}
							}
						;


optional_variable_declaration_list 	: /*empty*/
								{
									if(command_options.construct_ast()){
										$$ = new vector<symbol_table_entry*>();
									}
								}
							| optional_variable_declaration_list variable_declaration
								{
									if(command_options.construct_ast()){
										for(vector<symbol_table_entry*>:: iterator it = (*$2).begin();it != (*$2).end();it++){
											for(vector<symbol_table_entry*>::iterator it1 = (*$1).begin();it1 != (*$1).end();it1++){
												if((*it)->get_data_type() == (*it1)->get_data_type() && (*it)->get_var_name() == (*it1)->get_var_name()){
													cerr<<"Variable has been declared more than once\n";
													exit(1);
												}
											}
											(*($1)).push_back(*it);
										};
										$$ = $1;
									}
								}

variable_declaration	: type varlist ';' 
						{
							if(command_options.construct_ast()){
								for(vector<symbol_table_entry*>:: iterator it = (*$2).begin();it != (*$2).end();it++){
									if($1 != void_type){
										(*it)->set_data_type($1);
										// if(! global_symtab->check_entry((*it)->get_var_name())){
										universal_symtab->push_entry(*it);
										if((*it)->get_var_name()=="main"){
												cerr<<"variable name shouldn't be name\n";
												exit(1);
											};
										// }
										// else{
										// 	cerr << "Variable has been declared more than once\n";
										// 	exit(1);
										// }
									}
									else{
										cerr<<"shouldn't be void\n";
										exit(1);
									}
								}
								$$ = $2;
							}					
						}				
						;


varlist	:NAME
			{
				if(command_options.construct_ast()){
					$$ = new vector<symbol_table_entry *> ();
					//$1 = $1 + "_";
					symbol_table_entry* a = new symbol_table_entry(*$1,int_type,yylineno);
					(*$$).push_back(a);
				}
			}
		| varlist ',' NAME
			{	
				if(command_options.construct_ast()){
					//$3 = $3 + "_";
					symbol_table_entry* b = new symbol_table_entry(*$3,int_type,yylineno);
					(*$1).push_back(b);
					$$ = $1;
				}

			}
		;


statement_list	: /*empty*/
					{
						if(command_options.construct_ast()){
							$$ = new vector<ast_node *> ();
						}
					}
				| statement_list statement
					{
						if(command_options.construct_ast()){
							$$ = $1;
							$$->push_back($2);	
						}
					}
				;

statement 	: assignment | print | read | while_stmt  | do_while_stmt | if_else_stmt;


while_stmt 	 	: 	WHILE '(' exp ')' statement 
					{
						if(command_options.construct_ast()){
							$$ = new ast_node(while_type, yylineno);
							if(!($$->add_child($3))) exit(1);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							stmt_list_node->add_child($5);
							$$->add_child(stmt_list_node);
						}
					}
				|	WHILE '(' exp ')' '{' statement_list '}'
					{
						if(command_options.construct_ast()){
							$$ = new ast_node(while_type, yylineno);
							$$->add_child($3);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							for(int i=0; i<$6->size(); i++) stmt_list_node->add_child((*$6)[i]);
							$$->add_child(stmt_list_node);
						}
					}
				;
do_while_stmt	:	DO statement WHILE '(' exp ')' ';'
					{
						if(command_options.construct_ast()){
							$$ = new ast_node(do_while_type, yylineno);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							stmt_list_node->add_child($2);
							$$->add_child(stmt_list_node);
							$$->add_child($5);
						}
					}
				|	DO '{' statement_list '}' WHILE '(' exp ')' ';'
					{
						if(command_options.construct_ast()){
							$$ = new ast_node(do_while_type, yylineno);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							for(int i=0; i<$3->size(); i++) stmt_list_node->add_child((*$3)[i]);
							$$->add_child(stmt_list_node);
							$$->add_child($7);
						}
					}
				;
if_else_stmt	: 	IF '(' exp ')' statement optional_else_stmt 
					{
						if(command_options.construct_ast()){
							$$ = new ast_node(if_else_type, yylineno);
							$$->add_child($3);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							stmt_list_node->add_child($5);
							$$->add_child(stmt_list_node);
							if($6->num_child > 0) $$->add_child($6);
						}
					}
				|	IF '(' exp ')' '{' statement_list '}' optional_else_stmt 
					{
						if(command_options.construct_ast()){
							$$ = new ast_node(if_else_type, yylineno);
							$$->add_child($3);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							for(int i=0; i<$6->size(); i++) stmt_list_node->add_child((*$6)[i]);
							$$->add_child(stmt_list_node);
							if($8->num_child > 0) $$->add_child($8);
						}
					}
				;
optional_else_stmt	:	/*empty*/
						{
							if(command_options.construct_ast()){
								$$ = new ast_node(stmt_list_type, yylineno);
							}
						}
					|	ELSE statement
						{
							if(command_options.construct_ast()){
								$$ = new ast_node(stmt_list_type, yylineno);
								ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
								stmt_list_node->add_child($2);
								$$->add_child(stmt_list_node);
							}
						}
					| 	ELSE '{' statement_list '}' 
						{
							if(command_options.construct_ast()){
								$$ = new ast_node(stmt_list_type, yylineno);
								ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
								for(int i=0; i<$3->size(); i++) stmt_list_node->add_child((*$3)[i]);
								$$->add_child(stmt_list_node);
							}
						}
					;



print 	: WRITE NAME ';'
			{
					if(command_options.construct_ast()){
						if(universal_symtab->check_entry(*$2)){
							$$ = new ast_node(write_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, $2,universal_symtab->get_entry(*$2)->get_data_type(),yylineno);
							if(!($$->add_child(id))) exit(1);
						}
						else if(local_symtab->check_entry(*$2)){
							$$ = new ast_node(write_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, $2,local_symtab->get_entry(*$2)->get_data_type(),yylineno);
							if(!($$->add_child(id))) exit(1);
						}
						else {
							yyerror((char*)"Variable has not been declared");
						}
					}
			}
		| WRITE STR_CONSTANT ';'
			{	
				if(command_options.construct_ast()){
					node_val s;
					s.const_string_val = $2;
					ast_node * str = new ast_node(const_type, s,string_type,yylineno);
					$$ = new ast_node(write_stmt_type, yylineno);
					if(!($$->add_child(str))) exit(1);
				}
			}
		| WRITE NUM ';'
			{
				if(command_options.construct_ast()){
					node_val s;
					s.const_int_val = $2;
					ast_node * str = new ast_node(const_type, s,int_type,yylineno);
					$$ = new ast_node(write_stmt_type, yylineno);
					if(!($$->add_child(str))) exit(1);
				}
			}	 
		| WRITE FNUM ';' 
			{
				if(command_options.construct_ast()){
					node_val s;
					s.const_float_val = $2;
					ast_node * str = new ast_node(const_type, s,float_type,yylineno);
					$$ = new ast_node(write_stmt_type, yylineno);
					if(!($$->add_child(str))) exit(1);
				}
			}
		;

read 	: READ NAME ';'
			{
				if(command_options.construct_ast()){
					if(universal_symtab->check_entry(*$2)){
						$$ = new ast_node(read_stmt_type, yylineno);
						ast_node * id = new ast_node(id_type, $2,universal_symtab->get_entry(*$2)->get_data_type(),yylineno);
						if(!($$->add_child(id))) exit(1);
					}
					else if(local_symtab->check_entry(*$2)){
						$$ = new ast_node(read_stmt_type, yylineno);
						ast_node * id = new ast_node(id_type, $2,local_symtab->get_entry(*$2)->get_data_type(),yylineno);
						if(!($$->add_child(id))) exit(1);
					}
					else 
						{cerr << "Variable has not been declared\n";exit(1);}
				}
			}
		;

assignment 	: NAME '=' exp ';' 
				{
					if(command_options.construct_ast()){
						if(universal_symtab->check_entry(*$1)){
							$$ = new ast_node(assgn_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, $1,universal_symtab->get_entry(*$1)->get_data_type(),yylineno);
							$$->add_child(id);
							$$->add_child($3);
						}
						else if(local_symtab->check_entry(*$1)){
							$$ = new ast_node(assgn_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, $1,local_symtab->get_entry(*$1)->get_data_type(),yylineno);
							$$->add_child(id);
							$$->add_child($3);
						}
						else 
							{cerr << "Variable has not been declared\n";exit(1);}
					}
				}
			;



exp	: 	NUM           
			{	
				if(command_options.construct_ast()){
					node_val i;
					i.const_int_val = $1;
					$$ = new ast_node(const_type, i,int_type,yylineno);
				}

			}
		| FNUM
			{	
				if(command_options.construct_ast()){
					node_val f;
					f.const_float_val = $1;
					$$ = new ast_node(const_type, f,float_type,yylineno);
				}
			}

		| STR_CONSTANT
			{	
				if(command_options.construct_ast()){
					node_val s;
					s.const_string_val = $1;
					$$ = new ast_node(const_type, s,string_type,yylineno);
				}	
			}
		| NAME
			{	
				if(command_options.construct_ast()){
					if(universal_symtab->check_entry(*$1)){
						$$ = new ast_node(id_type, $1,universal_symtab->get_entry(*$1)->get_data_type(),yylineno);
					}

					else if(local_symtab->check_entry(*$1)){
						$$ = new ast_node(id_type, $1,local_symtab->get_entry(*$1)->get_data_type(),yylineno);
					}
					else 
						{cerr << "Variable has not been declared\n";exit(1);}
				}
			}
		| exp '+' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, plus_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp '-' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, minus_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp '*' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, mult_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp '/' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, div_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| '-' exp     %prec UMINUS
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(un_op_type, uminus_val,yylineno);
					if(!($$->add_child($2))) {cerr << "Uminus error\n";exit(1);}
				}
			}
		| '(' exp ')'
			{
				if(command_options.construct_ast()){
					$$ = $2;
				}
			}
		| exp EQUAL exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, eq_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp NE exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, ne_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp '<' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, lt_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp '>' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, gt_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp LTE exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, lte_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp GTE exp
			{	
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, gte_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp OR exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, or_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| exp AND exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(bin_op_type, and_val,yylineno);
					$$->add_child($1);
					$$->add_child($3);
				}
			}
		| '!' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(un_op_type, neg_val,yylineno);
					if(!($$->add_child($2)))  exit(1);
				}
			}
		| exp '?' exp ':' exp
			{
				if(command_options.construct_ast()){
					$$ = new ast_node(ter_op_type, yylineno);
					$$->add_child($1);
					$$->add_child($3);
					$$->add_child($5);
				}
			}
		;

%%

void yyerror(char* s){
	if(strcmp(s,"invalid character") == 0) cerr<<"sclp error: File: error1.c, Line: "<<yylineno<<", Next Token: INTEGER, Lexeme: \""<<yytext<<"\"\n            Description: Illegal character '"<<yytext<<"'\n";
	else cerr << "sclp error: Cannot parse input\n";
	exit(1);
}
