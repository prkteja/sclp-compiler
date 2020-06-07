#ifndef AST_H
#define AST_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "symbol-table.h"
#include "tac.h"
using namespace std;

typedef enum {assgn_stmt_type, read_stmt_type, write_stmt_type, bin_op_type, ter_op_type, un_op_type, id_type, const_type, while_type, do_while_type, if_else_type, stmt_list_type} node_type;
// typedef enum {void_type, int_type, bool_type, float_type, string_type, null_type} data_type;
typedef enum {neg_val, uminus_val} un_op_val_type;
typedef enum {plus_val, minus_val, mult_val, div_val, gt_val, lt_val, eq_val, ne_val, and_val, or_val, lte_val, gte_val} bin_op_val_type;
typedef enum {ter_cond_val} ter_op_val_type;

typedef union {
	un_op_val_type un_op_val;
	bin_op_val_type bin_op_val;
	ter_op_val_type ter_op_val;
	string* id_val;
	int const_int_val;
	float const_float_val;
	string* const_string_val;
} node_val;


class ast_node{
// protected:
public:
	node_type type;
	int num_child = 0;
	data_type return_type = null_type;
	node_val lval;
	int lineno;
	vector <ast_node*> children;
	tac_opd tac_return;
	bool tac_built;
public:
	ast_node();
	ast_node(ast_node* ast);
	ast_node(node_type type, int lineno);
	ast_node(node_type type, node_val lval, data_type return_type, int lineno);
	ast_node(node_type type, un_op_val_type val_type, int lineno);
	ast_node(node_type type, bin_op_val_type val_type, int lineno);
	ast_node(node_type type, string* lval, data_type return_type, int lineno);
	bool add_child(ast_node *child);
	void print_node(FILE* out);
	string str_val();
};


class procedure_node{
public:
	data_type return_type;
	symbol_table *local_symtab;
	node_val lval;
	vector<symbol_table_entry*> arg_list;
	vector<ast_node*> stmt_list;
	int lineno;
public:
	procedure_node(data_type return_type, string* lval, symbol_table *local_symtab, int lineno);
	void add_arg(vector<symbol_table_entry*> arg_list);
	void add_stmt_list(vector<ast_node*> stmt_list);
	void print_node(FILE* out);
};



class program_node{
protected:
	// symbol_table global_symtab;
	vector <procedure_node*> procedure_list;
public:
	program_node();
	void add_procedure(procedure_node *procedure);
};

string ftos(float a);

vector<tac_stmt> build_tac(procedure_node* node);
vector<tac_stmt> build_tac_node(ast_node* node);

#endif