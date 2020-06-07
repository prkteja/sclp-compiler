/* A Bison parser, made by GNU Bison 3.5.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    FNUM = 259,
    NAME = 260,
    STR_CONSTANT = 261,
    INT = 262,
    BOOL = 263,
    FLOAT = 264,
    STRING = 265,
    WRITE = 266,
    READ = 267,
    VOID = 268,
    ASSIGN_OP = 269,
    UMINUS = 270,
    AND = 271,
    OR = 272,
    GTE = 273,
    LTE = 274,
    NE = 275,
    EQUAL = 276,
    DO = 277,
    WHILE = 278,
    IF = 279,
    ELSE = 280
  };
#endif
/* Tokens.  */
#define NUM 258
#define FNUM 259
#define NAME 260
#define STR_CONSTANT 261
#define INT 262
#define BOOL 263
#define FLOAT 264
#define STRING 265
#define WRITE 266
#define READ 267
#define VOID 268
#define ASSIGN_OP 269
#define UMINUS 270
#define AND 271
#define OR 272
#define GTE 273
#define LTE 274
#define NE 275
#define EQUAL 276
#define DO 277
#define WHILE 278
#define IF 279
#define ELSE 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parse.y"

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

#line 122 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
