#include "symbol-table.h"
#include "ast.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;



symbol_table_entry::symbol_table_entry(string name,data_type new_data_type,int line){
	variable_data_type = new_data_type;
	variable_name = name;
	lineno = line;
}

symbol_table_entry::~symbol_table_entry(){

}

string symbol_table_entry:: get_var_name(){
	return variable_name;
}

data_type symbol_table_entry::get_data_type(){
	return variable_data_type;
}

void symbol_table_entry::set_data_type(data_type new_data_type){
	variable_data_type = new_data_type;
}

void symbol_table_entry:: set_symbol_scope(table_scope s){
	scope = s;
}

table_scope symbol_table_entry::get_symbol_scope(){
	return scope;
}

symbol_table::symbol_table(table_scope s){
	scope = s;

}

symbol_table::~symbol_table(){

}

table_scope symbol_table:: get_table_scope(){
	return scope;
}


void symbol_table::push_entry(symbol_table_entry * entry){
	// string d_type;
	// 	switch(entry->get_data_type()){
	// 		case int_type: {d_type = "INT";break;};
	// 		case float_type: {d_type = "FLOAT";break;};
	// 		case void_type: {d_type = "VOID";break;};
	// 		case string_type: {d_type = "STRING";break;};
	// 		case null_type: {d_type = "NULL";break;};
	// 		case bool_type: {d_type = "BOOL";break;};
	// 	};
	// cout<<entry->get_var_name()<<"_  Type:"<<d_type<<endl;
	table_list.push_back(entry);
}

void symbol_table::pop_entry(){
	table_list.pop_back();
}

symbol_table_entry* symbol_table::get_entry(string variable_name){
	for(int i =table_list.size()-1;i>=0;i--){
		if(table_list[i]->get_var_name() == variable_name) return table_list[i];
	}
	return NULL;

}

void symbol_table::print(){
	for(int i =0;i<table_list.size();i++){
		cout<<"name: "<<table_list[i]->get_var_name()<<" data_type: "<<table_list[i]->get_var_name()<<endl;
	}
}

bool symbol_table::check_entry(string variable){
	for(int i =0;i<table_list.size();i++){
		// cout<<table_list[i]->get_var_name()<<endl;
		if(table_list[i]->get_var_name() == variable) return true;
	}
	return false;
}