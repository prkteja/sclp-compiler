#include "user-options.hh"
#include <string>

using namespace std;

User_Options::User_Options(){
	source_file = "";
	show_tokens_selected = 0;
	show_ast_selected = 0;
	show_symtab_selected = 0;
	show_rtl_selected = 0;
	demo_mode_selected = 0;
	show_tac_selected = 0;

	stop_after_scan = 0;
	stop_after_parse = 0;
	stop_after_ast = 0;
	stop_after_tac = 0;
	stop_after_rtl = 0;
}

User_Options::~User_Options(){}

void User_Options::process_user_command_options(int argc, char* argv[]){
	bool file_found = 0;
	for(int i=1; i<argc; i++){
		string s = argv[i];
		if(s[0] == '-'){
			if(s == "-sa-scan") stop_after_scan = 1;
			else if(s == "-sa-parse") stop_after_parse = 1;
			else if(s == "-sa-ast") stop_after_ast = 1;
			else if(s == "-sa-tac") stop_after_tac = 1;
			else if(s == "-sa-rtl") stop_after_rtl = 1;
			else if(s == "-tokens") show_tokens_selected = 1;
			else if(s == "-ast") show_ast_selected = 1;
			else if(s == "-tac") show_tac_selected = 1;
			else if(s == "-rtl") {show_rtl_selected = 1;printf("sclp error: File:  The -rtl option not supported. The current implementation supports only SCAN and PARSE.\n");exit(1);}
			else if(s == "-symtab") {show_symtab_selected = 1;printf("sclp error: File:  The -symtab option not supported. The current implementation supports only SCAN and PARSE.\n");exit(1);}
			else if(s == "-d") demo_mode_selected = 1;
			else if(s == "-help") {printf("\n     Usage: sclp [options] [file]\n			Options:\n			-help     Show this help\n			-sa-scan  Stop after scanning\n			-sa-parse Stop after parsing\n			-sa-ast   Stop after constructing Abstract Syntac Tree (AST)\n			-sa-tac   Stop after constructing Three Address Code (TAC)\n			-sa-rtl   Stop after constructing Register Transfer Language (RTL) code\n			-tokens   Show the tokens in file.toks (or out.toks)\n			-ast      Show abstract syntax trees in file.ast (or out.ast)\n			-tac      Show the Three Address Code in file.tac (or out.tac)\n			-rtl	  Show the Register Transfer Language code in file.rtl (or out.rtl)\n			-symtab   Show the symbol table of delcarations in file.sy, (or out.sym)\n			-d        Demo version. Use stdout for the outputs instead of files\n"); exit(1);}
			else {printf("sclp error: File:  Unknown Option `%s'\n     Usage: sclp [options] [file]\n			Options:\n			-help     Show this help\n			-sa-scan  Stop after scanning\n			-sa-parse Stop after parsing\n			-sa-ast   Stop after constructing Abstract Syntac Tree (AST)\n			-sa-tac   Stop after constructing Three Address Code (TAC)\n			-sa-rtl   Stop after constructing Register Transfer Language (RTL) code\n			-tokens   Show the tokens in file.toks (or out.toks)\n			-ast      Show abstract syntax trees in file.ast (or out.ast)\n			-tac      Show the Three Address Code in file.tac (or out.tac)\n			-rtl	  Show the Register Transfer Language code in file.rtl (or out.rtl)\n			-symtab   Show the symbol table of delcarations in file.sy, (or out.sym)\n			-d        Demo version. Use stdout for the outputs instead of files\n", argv[i]);exit(1);}
		}else{
			if(file_found){
				printf("sclp error: File:  Only one input file name can be provided\n     Usage: sclp [options] [file]\n			Options:\n			-help     Show this help\n			-sa-scan  Stop after scanning\n			-sa-parse Stop after parsing\n			-sa-ast   Stop after constructing Abstract Syntac Tree (AST)\n			-sa-tac   Stop after constructing Three Address Code (TAC)\n			-sa-rtl   Stop after constructing Register Transfer Language (RTL) code\n			-tokens   Show the tokens in file.toks (or out.toks)\n			-ast      Show abstract syntax trees in file.ast (or out.ast)\n			-tac      Show the Three Address Code in file.tac (or out.tac)\n			-rtl	  Show the Register Transfer Language code in file.rtl (or out.rtl)\n			-symtab   Show the symbol table of delcarations in file.sy, (or out.sym)\n			-d        Demo version. Use stdout for the outputs instead of files\n");
				exit(1);
			}else{
				file_found = 1;
				source_file = s;
			}
		}
	}
}

string User_Options::get_file_name(){
	return source_file;
}

bool User_Options::construct_parse(){
	return (not stop_after_scan);
}
bool User_Options::construct_ast(){
	return (not stop_after_scan) and (not stop_after_parse);
	// return false;
};
bool User_Options::construct_tac(){
	return (not stop_after_scan) and (not stop_after_parse) and (not stop_after_ast);
	// return false;
};
bool User_Options::construct_rtl(){
	// return (not stop_after_scan) and (not stop_after_parse) and (not stop_after_ast) and (not stop_after_tac);
	return false;
};
bool User_Options::construct_asm(){
	// return (not stop_after_scan) and (not stop_after_parse) and (not stop_after_ast) and (not stop_after_tac) and (not stop_after_rtl);
	return false;
};

bool User_Options::is_show_tokens_selected(){
	return show_tokens_selected;
};
bool User_Options::is_show_ast_selected(){
	return show_ast_selected;
};
bool User_Options::is_demo_mode_selected(){
	return demo_mode_selected;
};
bool User_Options::is_show_symtab_selected(){
	return show_symtab_selected;
};
bool User_Options::is_show_rtl_selected(){
	return show_rtl_selected;
};
bool User_Options::is_show_tac_selected(){
	return show_tac_selected;
};