#ifndef TAC_H
#define TAC_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
// #include "ast.h"

using namespace std;

typedef enum {compute_tac, copy_tac, goto_tac, if_goto_tac, io_tac, label_tac, return_tac} tac_type;
typedef enum {int_const_opd, float_const_opd, label_opd, str_const_opd, temp_opd, var_opd} tac_opd_type;
typedef enum {neg_tac_val, uminus_tac_val, plus_tac_val, minus_tac_val, mult_tac_val, div_tac_val, gt_tac_val, lt_tac_val, eq_tac_val, ne_tac_val, and_tac_val, or_tac_val, lte_tac_val, gte_tac_val, read_tac_val, print_tac_val} op_val_type;


typedef union {
	string* id_val;
	int const_int_val;
	float const_float_val;
	string* const_string_val;
	string* temp_val;
	string* label_val;
} opd_val;

class tac_opd{
public:
	tac_opd_type type;
	opd_val lval;
	tac_opd();
	void print(FILE* out);
	string str_val();
};

class tac_stmt{
public:
	tac_type type;
	int num_opd;
	op_val_type op_type;
	tac_opd ret_var;
	vector<tac_opd> opd_list;
	tac_stmt();
	void print(FILE* out);
};


string temp();
string label();

// vector<tac_stmt> build_tac(procedure_node node);
// vector<tac_stmt> build_tac_node(ast_node* node);
void print_tac(vector<tac_stmt> tac, FILE* out);
string type_to_str(op_val_type type);

#endif