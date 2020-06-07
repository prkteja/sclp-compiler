#include "tac.h"
#include "ast.h"
using namespace std;

int temp_num = 0;
int label_num = 0;

vector<tac_stmt> build_tac(procedure_node* node){
	vector<tac_stmt> tac;
	for(int i=0; i<node->stmt_list.size(); i++){
		vector<tac_stmt> tac1 = build_tac_node(node->stmt_list[i]);
		tac.insert(tac.end(), tac1.begin(), tac1.end());
	};
	return tac;
};

void print_tac(vector<tac_stmt> tac, FILE* out){
	fprintf(out, "**BEGIN: Three Address Code Statements\n");
	for(int i=0; i<tac.size(); i++)tac[i].print(out);
	fprintf(out, "**END: Three Address Code Statements\n");
};

tac_stmt::tac_stmt(){
	num_opd = 0;
};

tac_opd::tac_opd(){
	this->type = temp_opd;
};

void tac_opd::print(FILE* out){//int_const_opd, float_const_opd, label_opd, str_const_opd, temp_opd, var_opd
	string opdtype;
	string val;
	if(this->type == int_const_opd) {opdtype = "int_const"; val = to_string(this->lval.const_int_val);}
	else if(this->type == float_const_opd) {opdtype = "float_const"; val = to_string(this->lval.const_float_val);}
	else if(this->type == label_opd) {opdtype = "label"; val = *(this->lval.label_val);}
	else if(this->type == str_const_opd) {opdtype = "string_const"; val = *(this->lval.const_string_val);}
	else if(this->type == temp_opd) {opdtype = "temporary_var"; val = *(this->lval.temp_val);}
	else if(this->type == var_opd) {opdtype = "variable"; val = *(this->lval.id_val);}
	else opdtype = "!!!this shouldn't happen!!!";
	fprintf(out, "tac_opd: %s %s\n", opdtype.c_str(), val.c_str());
};

string tac_opd::str_val(){
	string opdtype;
	string val;
	if(this->type == int_const_opd) {opdtype = "int_const"; val = to_string(this->lval.const_int_val);}
	else if(this->type == float_const_opd) {opdtype = "float_const"; val = ftos(this->lval.const_float_val);}
	else if(this->type == label_opd) {opdtype = "label"; val = *(this->lval.label_val);}
	else if(this->type == str_const_opd) {opdtype = "string_const"; val = *(this->lval.const_string_val);}
	else if(this->type == temp_opd) {opdtype = "temporary_var"; val = *(this->lval.temp_val);}
	else if(this->type == var_opd) {opdtype = "variable"; val = *(this->lval.id_val); val += "_";}
	else opdtype = "!!!this shouldn't happen!!!";
	return val;
};

string type_to_str(op_val_type type){
	string val;
	if(type == neg_tac_val) val = "!";
	else if(type == uminus_tac_val) val = "-";
	else if(type == plus_tac_val) val = "+";
	else if(type == minus_tac_val) val = "-";
	else if(type == mult_tac_val) val = "*";
	else if(type == div_tac_val) val = "/";
	else if(type == gt_tac_val) val = ">";
	else if(type == lt_tac_val) val = "<";
	else if(type == eq_tac_val) val = "==";
	else if(type == ne_tac_val) val = "!=";
	else if(type == and_tac_val) val = "&&";
	else if(type == or_tac_val) val = "||";
	else if(type == lte_tac_val) val = "<=";
	else if(type == gte_tac_val) val = ">=";
	else if(type == read_tac_val) val = "read";
	else if(type == print_tac_val) val = "write";
	else val = "!!error!!";
	return val;
};

op_val_type binop_to_opval(bin_op_val_type type){//plus_val, minus_val, mult_val, div_val, gt_val, lt_val, eq_val, ne_val, and_val, or_val, lte_val, gte_val
	if(type == plus_val) return plus_tac_val;
	else if(type == minus_val) return minus_tac_val;
	else if(type == mult_val) return mult_tac_val;
	else if(type == div_val) return div_tac_val;
	else if(type == gt_val) return gt_tac_val;
	else if(type == lt_val) return lt_tac_val;
	else if(type == eq_val) return eq_tac_val;
	else if(type == ne_val) return ne_tac_val;
	else if(type == and_val) return and_tac_val;
	else if(type == or_val) return or_tac_val;
	else if(type == lte_val) return lte_tac_val;
	else return gte_tac_val;
}

void tac_stmt::print(FILE* out){//compute_tac, copy_tac, goto_tac, if_goto_tac, io_tac, label_tac, return_tac
	if(this->type == compute_tac){//neg_val, uminus_val, plus_val, minus_val, mult_val, div_val, gt_val, lt_val, eq_val, ne_val, and_val, or_val, lte_val, gte_val, read_val, print_val
		if(this->op_type == neg_tac_val || this->op_type == uminus_tac_val){
			fprintf(out, "\t%s = %s %s\n", this->ret_var.str_val().c_str(), type_to_str(this->op_type).c_str(), this->opd_list[0].str_val().c_str());
		}else {
			fprintf(out, "\t%s = %s %s %s\n", this->ret_var.str_val().c_str(), this->opd_list[0].str_val().c_str(), type_to_str(this->op_type).c_str(), this->opd_list[1].str_val().c_str());	
		}
	}else if(this->type == copy_tac){
		fprintf(out, "\t%s = %s\n", this->ret_var.str_val().c_str(), this->opd_list[0].str_val().c_str());
	}else if(this->type == goto_tac){
		fprintf(out, "\tgoto %s\n", this->opd_list[0].str_val().c_str());
	}else if(this->type == if_goto_tac){
		fprintf(out, "\tif(%s) goto %s\n", this->opd_list[0].str_val().c_str(), this->opd_list[1].str_val().c_str());
	}else if(this->type == io_tac){
		fprintf(out, "\t%s %s\n", type_to_str(this->op_type).c_str(), this->opd_list[0].str_val().c_str());
	}else if(this->type == label_tac){
		fprintf(out, "%s:\n", this->opd_list[0].str_val().c_str());
	}else{
		fprintf(out, "\treturn %s\n", this->opd_list[0].str_val().c_str());
	}
};

string temp(){
	string s = "temp" + to_string(temp_num);
	temp_num++;
	return s;
};

string label(){
	string s = "Label" + to_string(label_num);
	label_num++;
	return s;
};

tac_opd_type to_opd_type(data_type d){
	if(d == int_type) return int_const_opd;
	else if(d == float_type) return float_const_opd;
	else if(d == string_type) return str_const_opd;
	else {cerr << "tac.cc line no:113\n"; return int_const_opd;};
}

vector<tac_stmt> build_tac_node(ast_node* node){//assgn_stmt_type, read_stmt_type, write_stmt_type, bin_op_type, ter_op_type, un_op_type, id_type, const_type
	if(node->type == id_type || node->type == const_type){
		node->tac_built = true;
		tac_opd opd;
		if(node->type == id_type) opd.type = var_opd;
		else opd.type = to_opd_type(node->return_type);
		if(node->type == id_type) opd.lval.id_val = node->lval.id_val;
		else{
			if(node->return_type == int_type) opd.lval.const_int_val = node->lval.const_int_val;
			else if(node->return_type == float_type) opd.lval.const_float_val = node->lval.const_float_val;
			else opd.lval.const_string_val = node->lval.const_string_val;
		};
		node->tac_return = opd;
		vector<tac_stmt> tac;
		return tac;
	}else if(node->type == assgn_stmt_type){
		vector<tac_stmt> t0 = build_tac_node(node->children[0]);
		vector<tac_stmt> t1 = build_tac_node(node->children[1]);
		node->tac_built = true;
		node->tac_return = node->children[0]->tac_return;
		tac_stmt t;
		t.ret_var = node->tac_return;
		t.type = copy_tac;
		t.num_opd = 1;
		t.opd_list.push_back(node->children[1]->tac_return);
		vector<tac_stmt> tac;
		tac.insert(tac.end(), t0.begin(), t0.end());
		tac.insert(tac.end(), t1.begin(), t1.end());
		tac.push_back(t);
		return tac;
	}else if(node->type == bin_op_type){
		vector<tac_stmt> t0 = build_tac_node(node->children[0]);
		vector<tac_stmt> t1 = build_tac_node(node->children[1]);
		node->tac_built = true;
		tac_opd opd;
		string *tmp = new string(temp());
		opd.lval.temp_val = tmp;
		node->tac_return = opd;
		tac_stmt t;
		t.type = compute_tac;
		t.num_opd = 2;
		t.ret_var = opd;
		t.op_type = binop_to_opval(node->lval.bin_op_val);
		t.opd_list.push_back(node->children[0]->tac_return);
		t.opd_list.push_back(node->children[1]->tac_return);
		vector<tac_stmt> tac;
		tac.insert(tac.end(), t0.begin(), t0.end());
		tac.insert(tac.end(), t1.begin(), t1.end());
		tac.push_back(t);
		return tac;
	}else if(node->type == un_op_type){
		vector<tac_stmt> t0 = build_tac_node(node->children[0]);
		node->tac_built = true;
		tac_opd opd;
		string *tmp = new string(temp());
		opd.lval.temp_val = tmp;
		node->tac_return = opd;
		tac_stmt t;
		t.type = compute_tac;
		t.num_opd = 1;
		t.ret_var = opd;
		t.op_type = node->lval.un_op_val == neg_val?neg_tac_val:uminus_tac_val;
		t.opd_list.push_back(node->children[0]->tac_return);
		vector<tac_stmt> tac;
		tac.insert(tac.end(), t0.begin(), t0.end());
		tac.push_back(t);
		return tac;
	}else if(node->type == read_stmt_type || node->type == write_stmt_type){
		vector<tac_stmt> t0 = build_tac_node(node->children[0]);
		node->tac_built = true;
		tac_stmt t;
		t.type = io_tac;
		t.num_opd = 1;
		t.op_type = node->type == read_stmt_type?read_tac_val:print_tac_val;
		t.opd_list.push_back(node->children[0]->tac_return);
		vector<tac_stmt> tac;
		tac.insert(tac.end(), t0.begin(), t0.end());
		tac.push_back(t);
		return tac;
	}else{
		vector<tac_stmt> t0 = build_tac_node(node->children[0]);
		vector<tac_stmt> t1 = build_tac_node(node->children[1]);
		vector<tac_stmt> t2 = build_tac_node(node->children[2]);
		vector<tac_stmt> tac;
		tac.insert(tac.end(), t0.begin(), t0.end());
		tac_stmt negtac;
		negtac.type = compute_tac;
		negtac.opd_list.push_back(node->children[0]->tac_return);
		tac_opd negopd;
		string *tmp = new string(temp());
		negopd.lval.temp_val = tmp;
		negtac.ret_var = negopd;
		negtac.op_type = neg_tac_val;
		tac.push_back(negtac);
		tac_stmt ifgototac;
		ifgototac.type = if_goto_tac;
		ifgototac.opd_list.push_back(negopd);
		tac_opd lbl;
		lbl.type = label_opd;
		string* label_str = new string(label());
		lbl.lval.label_val = label_str;
		ifgototac.opd_list.push_back(lbl);
		tac_opd ifgotoret;
		string *tmp1 = new string(temp());
		ifgotoret.lval.temp_val = tmp1;
		ifgototac.ret_var = ifgotoret;
		tac.push_back(ifgototac);
		node->tac_return = ifgotoret;
		tac.insert(tac.end(), t1.begin(), t1.end());
		tac_stmt cptac;
		cptac.type = copy_tac;
		cptac.opd_list.push_back(node->children[1]->tac_return);
		cptac.ret_var = ifgotoret;
		tac.push_back(cptac);
		tac_stmt gototac;
		gototac.type = goto_tac;
		tac_opd lbl1;
		lbl1.type = label_opd;
		string *label_str1 = new string(label());
		lbl1.lval.label_val = label_str1;
		gototac.opd_list.push_back(lbl1);
		tac.push_back(gototac);
		tac_stmt lblstmt;
		lblstmt.type = label_tac;
		lblstmt.opd_list.push_back(lbl);
		tac.push_back(lblstmt);
		tac.insert(tac.end(), t2.begin(), t2.end());
		tac_stmt cptac1;
		cptac1.type = copy_tac;
		cptac1.opd_list.push_back(node->children[2]->tac_return);
		cptac1.ret_var = ifgotoret;
		tac.push_back(cptac1);
		tac_stmt lblstmt1;
		lblstmt1.type = label_tac;
		lblstmt1.opd_list.push_back(lbl1);
		tac.push_back(lblstmt1);
		return tac;
	}
}