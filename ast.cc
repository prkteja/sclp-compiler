#include "ast.h"
#include "symbol-table.h"

using namespace std;

bool ast_node::add_child(ast_node* child){//cout << this->type << assgn_stmt_type << un_op_type <<"switch";
	switch (this->type){
		case assgn_stmt_type: {
			if(this->num_child > 1){
				cerr << "Node of assignment statement at line " << this->lineno << " already has 2 children\n";
				exit(1);
			};
			if(this->num_child == 0){
				if(child->type != id_type){
					cerr << "Assignment statement at line " << this->lineno << " has invalid lhs\n";
				exit(1);
				}else{
					this->return_type = child->return_type;
				}
			};
			if(this->num_child == 1){
				if(this->return_type != child->return_type){
					cerr << "Assignment statement at line " << this->lineno << " has Incompatible rhs\n";
				exit(1);
				}
			}
			break;
		};
		case read_stmt_type: {
			if(this->num_child>1){
				cerr << "Node of read statement at line " << this->lineno << " already has 1 children\n";
				exit(1);
			}else{
				if(child->type == id_type){
					if(child->return_type == bool_type || child->return_type == void_type || child->return_type == string_type) {
						cerr << "invalid argument for read \n";
						exit(1);
					}
				}else{
					cerr << "invalid argument for read \n";
					exit(1);
				}
			};break;
		};
		case write_stmt_type: {
			if(this->num_child>1){
				cerr << "Node of write statement at line " << this->lineno << " already has 1 children\n";
				exit(1);
			}else{
				if(child->type == id_type || child->type == const_type){
					if(child->return_type == bool_type || child->return_type == void_type) {
						cerr << "invalid argument for print \n";
						exit(1);
					}
				}
			};
			break;
		};
		case bin_op_type:{
			if(this->num_child > 1){
				cerr << "Node of binary operator at line " << this->lineno << " already has 2 children\n";
				exit(1);
			};
			if(this->lval.bin_op_val == plus_val || this->lval.bin_op_val == minus_val || this->lval.bin_op_val == mult_val || this->lval.bin_op_val == div_val){
				if(this->num_child == 0){
					if(child->return_type == int_type || child->return_type == float_type){
						this->return_type = child->return_type;
					}else{
						cerr << "Invalid arguments for arithmetic operator at line "<< this->lineno <<"\n";
						exit(1);
					}
				}else{
					if(child->return_type != this->return_type){
						cerr << "Incompatible argument types for arithmetic operator at line " << this->lineno << "\n";
						exit(1); 
					}
				}
			} else if(this->lval.bin_op_val == and_val || this->lval.bin_op_val == or_val){
				if(child->return_type != bool_type){
					cerr << "Incompatible argument types for boolean operator at line "<< this->lineno << "\n";
					exit(1);
				}else{
					this->return_type = bool_type;
				}
			} else{
				this->return_type = bool_type;
				if(this->num_child == 0){
					if(child->return_type == int_type || child->return_type == float_type){
					}else{
						cerr << "Invalid arguments for arithmetic operator at line "<< this->lineno <<"\n";
						exit(1);
					}
				}else{
					if(child->return_type != this->children[0]->return_type){
						cerr << "Incompatible argument types for arithmetic operator at line " << this->lineno << "\n";
						exit(1); 
					}
				}
			};break;
		};
		case un_op_type: { //cout <<this->type << this->lval.un_op_val << "asssssssssssssss\n";
			if(this->num_child > 0){
				cerr << "Node of unary operator at line " << this->lineno << " already has 1 children\n";
				exit(1);
			};
			if(this->lval.un_op_val == uminus_val){
				if(child->return_type != int_type && child->return_type != float_type){
					cerr << "Incompatible argument type for uminus at line " << this->lineno << "\n";
					exit(1);
				}else{
					this->return_type = child->return_type;
				}
			} else {
				if(child->return_type != bool_type){
					cerr << "Incompatible argument type for negation at line " << this->lineno << "\n";
					exit(1);
				} else{
					this->return_type = child->return_type;
				}
			};break;
		};
		case ter_op_type: {
			if(this->num_child > 3) {
				cerr << "Node of ternary operator at line " << this->lineno << " already has 3 children\n";
				exit(1);
			};
			if(this->num_child == 0) {
				if(child->return_type != bool_type) {
					cerr << "First argument of ternary condition must be a boolean at line " << this->lineno << "\n";
					exit(1);
				}
			};
			if(this->num_child == 1) {
				if(child->return_type == void_type) {
					cerr << "Argument return type cannot be void at line " << this->lineno << "\n";
					exit(1);
				} else {
					this->return_type = child->return_type;
				}
			};
			if(this->num_child == 2) {
				if(this->children[1]->return_type != child->return_type) {
					cerr << "Incompatible return types for arguments to ternary operator at line " << this->lineno << "\n";
					exit(1);
				}
			};break;
		};
		case id_type: {
			cerr << "Node of type ID cannot have children at line " << this->lineno << "\n";
			exit(1);
		};
		case const_type: {
			cerr << "Node of type constant cannot have children at line " << this->lineno << "\n";
			exit(1);
		};
		case while_type: {
			if(this->num_child == 0){
				if(child->return_type != bool_type){
					cerr << "Expression in while condition must be of type 'bool' at line " << this->lineno << "\n";
					exit(1);
				}
			}else if(this->num_child == 1){
				if(child->type != stmt_list_type){
					cerr << "Body of while must be a statement list at line " << this->lineno << "\n";
					exit(1);
				}
			}else{
				cerr << "Too many arguments for node 'while' at line "<< this->lineno << "\n";
				exit(1);
			};
			break;
		};
		case do_while_type: {
			if(this->num_child == 1){
				if(child->return_type != bool_type){
					cerr << "Expression in while condition must be of type 'bool' at line " << this->lineno << "\n";
					exit(1);
				}
			}else if(this->num_child == 0){
				if(child->type != stmt_list_type){
					cerr << "Body of do must be a statement list at line " << this->lineno << "\n";
					exit(1);
				}
			}else{
				cerr << "Too many arguments for node 'do_while' at line "<< this->lineno << "\n";
				exit(1);
			};
			break;
		};
		case if_else_type:{
			if(this->num_child == 0){
				if(child->return_type != bool_type){
					cerr << "Expression in if condition must be of type 'bool' at line " << this->lineno << "\n";
					exit(1);
				}
			}else if(this->num_child == 1 || this->num_child == 2){
				if(child->type != stmt_list_type){
					cerr << "Body of while must be a statement list at line " << this->lineno << "\n";
					exit(1);
				}
			}else{
				cerr << "Too many arguments for node 'if_else' at line "<< this->lineno << "\n";
				exit(1);
			};
			break;
		}
	};
	this->children.push_back(child);
	this->num_child++;
	return true;
};


/*

assgn_stmt_node::assgn_stmt_node(int lineno){
	this->type = assgn_stmt_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
	// this->lval.bin_op_val = assgn_val;
};

read_stmt_node::read_stmt_node(int lineno){
	this->type = read_stmt_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
	// this->lval.un_op_val = read_val;
};

write_stmt_node::write_stmt_node(int lineno){
	this->type = write_stmt_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
	// this->lval.un_op_val = write_val;
};

const_node::const_node(node_val lval, data_type return_type, int lineno){
	if(return_type == void_type || return_type == null_type) {
		cerr << "Constant cannot be void at line "<< lineno <<"\n";
		exit(1);
	}
	this->type = const_type;
	this->num_child = 0;
	this->return_type = return_type;
	this->lineno = lineno;
	this->lval = lval;
};

un_op_node::un_op_node(un_op_val_type type, int lineno){
	this->type = un_op_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
	this->lval.un_op_val = type;
};

bin_op_node::bin_op_node(bin_op_val_type type, int lineno){
	this->type = bin_op_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
	this->lval.bin_op_val = type;
};

ter_op_node::ter_op_node(int lineno){
	this->type = ter_op_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
	this->lval.ter_op_val = ter_cond_val;
};

id_node::id_node(string* lval, data_type return_type, int lineno){
	if(return_type == void_type || return_type == null_type) {
		cerr << "ID cannot be void at line "<< lineno <<"\n";
		exit(1);
	}
	this->type = id_type;
	this->num_child = 0;
	this->return_type = return_type;
	this->lineno = lineno;
	this->lval.id_val = lval;
};

while_node::while_node(int lineno){
	this->type = while_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
};

do_while_node::do_while_node(int lineno){
	this->type = do_while_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
};

if_else_node::if_else_node(int lineno){
	this->type = if_else_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
};

stmt_list_node::stmt_list_node(int lineno){
	this->type = while_type;
	this->num_child = 0;
	this->return_type = null_type;
	this->lineno = lineno;
};

*/


void ast_node::print_node(FILE* out){
	if(this->type == assgn_stmt_type){
		fprintf(out, "Asgn:\n");
		fprintf(out, "LHS (");
		this->children[0]->print_node(out);
		fprintf(out,")\nRHS (");
		this->children[1]->print_node(out);
		fprintf(out, ")\n");
		return;
	}else if(this->type == write_stmt_type){
		fprintf(out, "Write: ");
		this->children[0]->print_node(out);
		fprintf(out, "\n");
		return;
	}else if(this->type == read_stmt_type){
		fprintf(out, "Read: ");
		this->children[0]->print_node(out);
		fprintf(out, "\n");
		return;
	}else if(this->type == un_op_type){
		if(this->lval.un_op_val == neg_val){
			fprintf(out, "\nCondition: NOT<bool>\nL_Opd (");
			this->children[0]->print_node(out);
			fprintf(out, ")");
			return;
		}else{
			string d_type = this->return_type == int_type ? "int":"float";
			fprintf(out, "\nArith: Uminus<%s>\nL_Opd (", d_type.c_str());
			this->children[0]->print_node(out);
			fprintf(out, ")");
			return;
		}
		
	}else if(this->type == bin_op_type){
		if(this->lval.bin_op_val == plus_val || this->lval.bin_op_val == minus_val || this->lval.bin_op_val == mult_val || this->lval.bin_op_val == div_val){
			string d_type = this->return_type == int_type ? "int":"float";
			string arith_type;
			switch(this->lval.bin_op_val){
				case plus_val: {arith_type = "Plus";break;};
				case minus_val: {arith_type = "Minus";break;};
				case mult_val: {arith_type = "Mult";break;};
				case div_val: {arith_type = "Div";break;};
			};
			fprintf(out, "\nArith: %s<%s>\nL_Opd (", arith_type.c_str(), d_type.c_str());
			this->children[0]->print_node(out);
			fprintf(out, ")\nR_Opd (");
			this->children[1]->print_node(out);
			fprintf(out, ")");
			return;
		}else {
			string c_type;
			switch(this->lval.bin_op_val){
				case and_val: {c_type = "AND";break;};
				case or_val: {c_type = "OR";break;};
				case eq_val: {c_type = "EQ";break;};
				case ne_val: {c_type = "NE";break;};
				case lt_val: {c_type = "LT";break;};
				case gt_val: {c_type = "GT";break;};
				case lte_val: {c_type = "LE";break;};
				case gte_val: {c_type = "GE";break;};
			};
			fprintf(out, "\nCondition: %s<bool>\nL_Opd (", c_type.c_str());
			this->children[0]->print_node(out);
			fprintf(out, ")\nR_Opd (");
			this->children[1]->print_node(out);
			fprintf(out, ")");
			return;
		}
	}else if(this->type == ter_op_type){
		this->children[0]->print_node(out);
		fprintf(out, "\nTrue_Part (");
		this->children[1]->print_node(out);
		fprintf(out, ")\nFalse_Part (");
		this->children[2]->print_node(out);
		fprintf(out, ")");
		return;
	}else if(this->type == id_type || this->type == const_type){
		string d_type;
		switch(this->return_type){
			case int_type: {d_type = "int";break;};
			case float_type: {d_type = "float";break;};
			case void_type: {d_type = "void";break;};
			case string_type: {d_type = "string";break;};
			case bool_type: {d_type = "bool";break;};
			case null_type: {d_type = "null";break;};
		};
		string id;// = this->type == id_type?"Name":((this->return_type == string) ? "String":"Num");
		if(this->type == id_type) id = "Name";
		else if(this->return_type == string_type) id = "String";
		else id = "Num";
		string val;
		if(this->type == id_type) val = *(this->lval.id_val) + "_";
		else if(this->return_type == int_type) val = to_string(this->lval.const_int_val);
		else if(this->return_type == float_type) val = ftos(this->lval.const_float_val);
		else val = *(this->lval.const_string_val);
		// cout << id << " : " << val << "<" << d_type << ">";
		fprintf(out, "%s : %s <%s>", id.c_str(), val.c_str(), d_type.c_str());
		return;
	}else if(this->type == while_type){
		fprintf(out, "While:\nCondition (\n");
		this->children[0]->print_node(out);
		fprintf(out, ")\nBody (\n");
		this->children[1]->print_node(out);
		fprintf(out, ")\n");
		return;
	}else if(this->type == do_while_type){
		fprintf(out, "Do:\nBody (\n");
		this->children[0]->print_node(out);
		fprintf(out, ")\nWhile Condition (\n");
		this->children[1]->print_node(out);
		fprintf(out, ")\n");
		return;
	}else if(this->type == if_else_type){
		fprintf(out, "If:\nCondition (\n");
		this->children[0]->print_node(out);
		fprintf(out, ")\nThen (\n");
		this->children[1]->print_node(out);
		if(this->num_child == 2){
			fprintf(out, ")\n");
			return;
		}else{
			fprintf(out, ")\nElse (\n");
			this->children[2]->print_node(out);
			fprintf(out, ")\n");
			return;
		}
	}else{// stmt_list_type
		for(int i=0; i<this->num_child; i++) this->children[i]->print_node(out);
		return;
	}
};

procedure_node::procedure_node(data_type return_type, string* lval, symbol_table *local_symtab, int lineno){
	this->return_type = return_type;
	this->local_symtab = local_symtab;
	this->lval.id_val = lval;
	this->lineno = lineno;
};

void procedure_node::add_arg(vector<symbol_table_entry*> arg){
	this->arg_list = arg;
};

void procedure_node::add_stmt_list(vector<ast_node*> stmt_list){
	// if(stmt->type != assgn_stmt_type && stmt->type != write_stmt_type && stmt->type != read_stmt_type) {
	// 	cerr << "sentence at line "<< stmt->lineno << " is not a statement\n";
	// 	exit(1);
	// }else{
	// 	this->stmt_list.push_back(stmt);
	// }
	this->stmt_list = stmt_list;
};

void procedure_node::print_node(FILE* out){
	string d_type;
	switch(this->return_type){
		case int_type: {d_type = "INT";break;};
		case float_type: {d_type = "FLOAT";break;};
		case void_type: {d_type = "VOID";break;};
		case string_type: {d_type = "STRING";break;};
		case null_type: {d_type = "NULL";break;};
	};
	// cout << "**PROCEDURE: "<< *(this->lval.id_val) <<", Return Type: " << d_type <<"\n**BEGIN: Abstract Syntax Tree\n";
	fprintf(out, "**PROCEDURE: %s, Return Type: %s\n", (*(this->lval.id_val)).c_str(), d_type.c_str());
	//cout<<this->arg_list.size()<<endl;
	for(int i=0; i<this->arg_list.size(); i++){//cout<<"ajk\n";
		string arg_d_type;
		switch(this->arg_list[i]->get_data_type()){
			case int_type: {arg_d_type = "INT";break;};
			case float_type: {arg_d_type = "FLOAT";break;};
			case void_type: {arg_d_type = "VOID";break;};
			case string_type: {arg_d_type = "STRING";break;};
			case null_type: {arg_d_type = "NULL";break;};
		};
		fprintf(out, "%s  Type:%s\n", ((this->arg_list[i]->get_var_name())+"_").c_str(), arg_d_type.c_str());
	}
	fprintf(out, "**BEGIN: Abstract Syntax Tree\n");
	for(int i=0; i<this->stmt_list.size(); i++) this->stmt_list[i]->print_node(out);
	fprintf(out, "**END: Abstract Syntax Tree\n");
};

program_node::program_node(){
	// this->global_symtab = global_symtab;
};

void program_node::add_procedure(procedure_node* proc){
	if(this->procedure_list.size() > 0) {
		cerr << "Only one function supported\n";
		exit(1);
	}else{
		this->procedure_list.push_back(proc);
	}
};


/*

ast_node::ast_node(assgn_stmt_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(write_stmt_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(read_stmt_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(un_op_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(bin_op_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(ter_op_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(id_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};
ast_node::ast_node(const_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};

*/

ast_node::ast_node(ast_node* node){
	this->type = node->type;
	this->num_child = node->num_child;
	this->return_type = node->return_type;
	this->lval = node->lval;
	this->lineno = node->lineno;
	this->children = node->children;
	this->tac_built = false;
};


/**/

// ast_node::ast_node(while_node* node){
// 	//i feel like an idiot

// }

ast_node::ast_node(){
	this->tac_built = false;
};

string ftos(float a){
	stringstream stream;
	stream << fixed << setprecision(2) << a;
	return stream.str();
};

// string str_val(){
// 	if(this->type == id_type) return *(this->lval.id_val) + "_";
// 	else if(this->type == const_type){
// 		if(this->return_type == int_type) return to_string(this->lval.const_int_val);
// 		else if(this->return_type == float_type) return ftos(this->lval.const_float_val);
// 		else if(this->return_type == string_type) return "\"" + *(this->lval.const_string_val) + "\"";
// 		else return "";
// 	}else return "";
// };




ast_node::ast_node(node_type type, int lineno){
	this->type = type;
	this->lineno = lineno;
	this->return_type = null_type;
	this->tac_built = false;
	this->num_child = 0;
};

ast_node::ast_node(node_type type, node_val lval, data_type return_type, int lineno){
	this->type = type;
	this->lval = lval;
	this->return_type = return_type;
	this->lineno = lineno;
	this->tac_built = false;
	this->num_child = 0;
};

ast_node::ast_node(node_type type, un_op_val_type val_type, int lineno){
	this->type = type;
	this->lval.un_op_val = val_type;
	this->return_type = null_type;
	this->lineno = lineno;
	this->tac_built = false;
	this->num_child = 0;
};

ast_node::ast_node(node_type type, bin_op_val_type val_type, int lineno){
	this->type = type;
	this->lval.bin_op_val = val_type;
	this->return_type = null_type;
	this->lineno = lineno;
	this->tac_built = false;
	this->num_child = 0;
};

ast_node::ast_node(node_type type, string* lval, data_type return_type, int lineno){
	this->type = type;
	this->lval.id_val = lval;
	this->return_type = return_type;
	this->lineno = lineno;
	this->tac_built = false;
	this->num_child = 0;
};

