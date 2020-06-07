/* BEGIN_BANNER */
/*******************************************************************************************************

                                sclp : A C Language Processor
                                --------------------------------

       About:

       Originally implemented by Tanu Kanvar and Uday Khedker (http://www.cse.iitb.ac.in/~uday)
       for the courses cs302+cs316 Language Processors (theory and lab) at IIT Bombay.

       Initial release date Jan 15, 2013.

       Updated by N. Venkatesh in Jan 2019. The main updates included
       - Changing the input language from a basic-block-based GCC GIMPLE dump to a subset of C.
       - Replacing the flexc++ and bisonc++ scripts by flex and bison.
       - Supporting print operation for variables.
       
       Updated by Uday Khedker with the help of Nisha Biju and Saari Rajan in Jan 2020. The main
       updates include
       - Introduction of three address code (TAC) phase between abstract syntax tree (AST)
         and Register Transfer Language (RTL) which was originally called icode.
       - Introduction of string data type with constant strings.
       - Support for read operation for integer and floating point variables, and print
         operation for all variables (including string variables) and string constants. 
       - Significant changes in command line switches for printing each representation (tokens,
         AST, TAC, RTL, and assembly) as well as stopping after each phase (scanning, parsing,
	 AST construction (i.e. semantic analysis), TAC generation and RTL generation).
       - Substantial clean up of the code including removal of AST to icode translation,
         and interpretation (which was buggy and had not been tested thorougly after the front
	 end and the input langauge changed in 2019). 

       Copyrights reserved  by Uday Khedker. This  implemenation has been made available purely  
       for academic purposes without any warranty of any kind.

*******************************************************************************************************/
/* END_BANNER */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include "y.tab.c"
#include "lex.yy.c"


using namespace std;

#include "user-options.hh"

User_Options command_options;

int main(int argc, char * argv[]) 
{
	command_options.process_user_command_options(argc, argv);

	string file_name = command_options.get_file_name();
	remove((file_name+".toks").c_str());


	if(!(yyin = fopen(file_name.c_str(), "r"))){
		cerr << "sclp error: File: " << file_name << " Cannot open the input file\n";
	};
	if(!command_options.is_demo_mode_selected() && command_options.is_show_tokens_selected()){
		yyout = fopen((file_name+".toks").c_str(), "w");
	};
	
	if (command_options.construct_parse()){
		yyparse();
		// if (command_options.construct_ast())
		// 	cout << "Constructing AST" << endl;
	} else {
		while(1) yylex();
	};
		

	// if (command_options.construct_ast())
	// {
	// 	if (command_options.is_show_ast_selected())
 //         		if(command_options.is_demo_mode_selected()) 
	// 			cout << "Printing AST on stdout" << endl;
	//  		else
	// 			cout << "Printing AST in file " << file_name  << ".ast " << endl;
		    
 //        }

	// if (command_options.construct_tac())
	// 	cout << "Constructing TAC" << endl;
		
	// if (command_options.is_show_tac_selected())
 //         	if(command_options.is_demo_mode_selected()) 
	// 		cout << "Printing TAC on stdout" << endl;
	//  	else
	// 		cout << "Printing TAC in file " << file_name  << ".tac " << endl;
	
	// if (command_options.construct_rtl())
	// 	cout << "Constructing RTL" << endl;
		
	// if (command_options.is_show_symtab_selected() && command_options.construct_rtl())
 //         	if(command_options.is_demo_mode_selected()) 
	// 		cout << "Printing Symtab on stdout" << endl;
	//  	else
	// 		cout << "Printing Symtab in file " << file_name  << ".sym " << endl;

	// if (command_options.is_show_rtl_selected())
 //         	if(command_options.is_demo_mode_selected()) 
	// 		cout << "Printing RTL on stdout" << endl;
	//  	else
	// 		cout << "Printing RTL in file " << file_name  << ".rtl " << endl;


	// if (command_options.construct_asm())
 //         	if(command_options.is_demo_mode_selected()) 
	// 		cout << "Printing ASM on stdout" << endl;
	//  	else
	// 		cout << "Printing ASM in file " << file_name  << ".spim " << endl;

	return 0;
}
