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


// typedef struct{
// 	node_type type;
// 	data_type return_type;
// 	union {
// 		assgn_stmt_node* assgn_stmt;
// 		read_stmt_node* read_stmt;
// 		write_stmt_node* write_stmt;
// 		bin_op_node* bin_op;
// 		ter_op_node* ter_op;
// 		un_op_node* un_op;
// 		id_node* id;
// 		const_node* constant;
// 	}
// } child_node;

// class ast_node;
// class assgn_stmt_node;
// class read_stmt_node;
// class write_stmt_node;
// class un_op_node;
// class bin_op_node;
// class ter_op_node;
// class id_node;
// class const_node;
// class while_node;
// class do_while_node;
// class if_else_node;
// class stmt_list_node;

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
	// ast_node(assgn_stmt_node* node);
	// ast_node(write_stmt_node* node);
	// ast_node(read_stmt_node* node);
	// ast_node(un_op_node* node);
	// ast_node(bin_op_node* node);
	// ast_node(ter_op_node* node);
	// ast_node(id_node* node);
	// ast_node(const_node* node);
	// ast_node(while_node* node);
	// ast_node(do_while_node* node);
	// ast_node(if_else_node* node);
	// ast_node(stmt_list_node* node);
	ast_node(node_type type, int lineno);
	ast_node(node_type type, node_val lval, data_type return_type, int lineno);
	ast_node(node_type type, un_op_val_type val_type, int lineno);
	ast_node(node_type type, bin_op_val_type val_type, int lineno);
	ast_node(node_type type, string* lval, data_type return_type, int lineno);
	bool add_child(ast_node *child);
	void print_node(FILE* out);
	string str_val();
};

/*


class assgn_stmt_node: public ast_node{public:
	node_type type = assgn_stmt_type;
public:s
	assgn_stmt_node(int lineno);
};

class read_stmt_node: public ast_node{public:
	node_type type = read_stmt_type;
	public:
	read_stmt_node(int lineno);
};

class write_stmt_node: public ast_node{public:
	node_type type = write_stmt_type;
	public:
	write_stmt_node(int lineno);
};

class const_node: public ast_node{public:
	node_type type = const_type	;
	public:
	const_node(node_val lval, data_type return_type, int lineno);
};

class un_op_node: public ast_node{public:
	node_type type = un_op_type;
	public:
	un_op_node(un_op_val_type type, int lineno);
};

class bin_op_node: public ast_node{public:
	node_type type = bin_op_type;
	public:
	bin_op_node(bin_op_val_type type, int lineno);
};

class ter_op_node: public ast_node{public:
	node_type type = ter_op_type;
	public:
	ter_op_node(int lineno);
};

class id_node: public ast_node{public:
	node_type type = id_type;
	public:
	id_node(string* lval, data_type return_type, int lineno);
};

class while_node: public ast_node{
public:
	node_type type = while_type;
	while_node(int lineno);
};

class do_while_node: public ast_node{
public:
	node_type type = do_while_type;
	do_while_node(int lineno);
};

class if_else_node: public ast_node{
public:
	node_type type = if_else_type;
	if_else_node(int lineno);
};

class stmt_list_node: public ast_node{
public:
	node_type type = stmt_list_type;
	stmt_list_node(int lineno);
}

*/

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