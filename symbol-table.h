#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <vector>
#include <string>
// #include "ast.h"

using namespace std;

typedef enum{
	int_type,
	float_type,
	bool_type,
	string_type,
	void_type,
	null_type
} data_type;

typedef enum{
	global,
	local
} table_scope;

typedef enum{
	less_than,
	greater_than,
	less_than_equal_to,
	greater_than_equal_to,
	equal_to,
	not_equal_to,
} relational_op;



class symbol_table_entry{
	string variable_name;
	data_type variable_data_type;
	int lineno;
	table_scope scope;
public:
	// symbol_table_entry();
	symbol_table_entry(string name,data_type new_data_type,int line);
	~symbol_table_entry();
	string get_var_name();
	data_type get_data_type();
	table_scope get_symbol_scope();
	void set_symbol_scope(table_scope s);
	void set_data_type(data_type new_data_type);

};

class symbol_table{
	vector <symbol_table_entry *> table_list;
	table_scope scope;

public:
	symbol_table(table_scope s);
	~symbol_table();
	table_scope get_table_scope();
	void push_entry(symbol_table_entry * entry);
	void pop_entry();
	symbol_table_entry* get_entry(string variable_name);
	void print();
	bool check_entry(string variable);

};



#endif