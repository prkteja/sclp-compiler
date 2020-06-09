/* A Bison parser, made by GNU Bison 3.5.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iterator>
#include <fstream>
#include "symbol-table.h"
#include "ast.h"
#include "user-options.hh"
using namespace std;
void yyerror(char* );
extern "C" int yylex(void);
extern char* yytext;
extern int yylineno;
vector<data_type> arg_data_types;
symbol_table* global_symtab = new symbol_table(global);
symbol_table* local_symtab = new symbol_table(local);
symbol_table* universal_symtab = new symbol_table(local);
FILE* astout = stdout;
FILE* tacout = stdout;
bool declared = false;

#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 213 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

#define YYUNDEFTOK  2
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,     2,     2,     2,
      35,    36,    33,    31,    38,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,    37,
      29,    41,    30,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    82,    96,   102,   129,   135,   141,   148,
     154,   162,   168,   175,   185,   190,   198,   268,   273,   289,
     318,   327,   341,   346,   355,   355,   355,   355,   355,   355,
     358,   368,   379,   389,   400,   411,   424,   429,   438,   451,
     469,   479,   489,   501,   520,   543,   552,   561,   569,   583,
     591,   599,   607,   615,   622,   628,   636,   644,   652,   660,
     668,   676,   684,   692,   699
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "FNUM", "NAME", "STR_CONSTANT",
  "INT", "BOOL", "FLOAT", "STRING", "WRITE", "READ", "VOID", "ASSIGN_OP",
  "UMINUS", "AND", "OR", "GTE", "LTE", "NE", "EQUAL", "DO", "WHILE", "IF",
  "ELSE", "'?'", "':'", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "';'", "','", "'{'", "'}'", "'='", "$accept", "program",
  "procedure_declaration", "type", "arg", "arg_list", "optional_arg_list",
  "procedure_definition", "optional_variable_declaration_list",
  "variable_declaration", "varlist", "statement_list", "statement",
  "while_stmt", "do_while_stmt", "if_else_stmt", "optional_else_stmt",
  "print", "read", "assignment", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    63,    58,    33,    60,
      62,    43,    45,    42,    47,    40,    41,    59,    44,   123,
     125,    61
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,   -56,   -56,   -56,   -56,   -56,    20,    39,    35,   -56,
      39,   -56,   -56,     6,   -26,   -56,    39,   -56,    45,    46,
     -56,    15,    29,   -56,   -56,    39,   -20,   -56,   -56,   -56,
      39,    63,   -56,    32,   -56,    28,     1,    68,    89,    41,
      51,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    10,
      37,    43,    50,    52,    56,   -56,    65,    10,    10,   -56,
     -56,   -56,   -56,    10,    10,    10,   143,   -56,   -56,   -56,
     -56,   -56,    55,    70,   165,   186,   314,   -56,   207,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,   -56,    75,    10,   110,   118,   -56,   314,   308,
     331,   331,   331,   331,   270,   331,   331,   -11,   -11,   -56,
     -56,    71,   228,   -56,   -56,   -56,    91,    10,    10,    77,
      59,    80,   132,   -56,   289,   249,   -56,   -56,    91,   -56,
     -56,    81,   -56,    85,   -56,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     6,     7,     8,    10,     9,     0,     0,     0,     2,
       0,     1,     4,    20,     0,     3,    14,    19,     0,     0,
      12,    15,     0,    21,    11,     0,     0,    13,     5,    17,
      22,     0,    18,     0,    20,     0,     0,     0,     0,     0,
       0,    16,    23,    27,    28,    29,    25,    26,    24,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,    45,
      46,    48,    47,     0,     0,     0,     0,    41,    42,    39,
      40,    43,     0,     0,     0,     0,    63,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,    54,    62,    61,
      60,    59,    56,    55,     0,    57,    58,    49,    50,    51,
      52,     0,     0,    22,    30,    22,    36,     0,     0,     0,
       0,     0,     0,    34,    64,     0,    32,    31,    36,    22,
      37,     0,    35,     0,    33,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,    11,   -56,    94,    92,   -56,   -56,   -56,   -56,    96,
     -56,   -54,   -38,   -56,   -56,   -56,    -1,   -56,   -56,   -56,
     -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    20,    21,    22,     9,    30,    10,
      14,    33,    42,    43,    44,    45,   123,    46,    47,    48,
      66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    72,    74,    75,    50,    51,    52,    53,    76,    77,
      78,    17,    18,    59,    60,    61,    62,    28,    12,    29,
      11,    15,    90,    91,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    35,    63,   112,
      13,    16,    64,    36,    37,    65,     1,     2,     3,     4,
      23,    24,     5,    25,    38,    39,    40,   114,   116,   120,
      35,   121,   124,   125,    35,    26,    36,    37,    34,    49,
      36,    37,    41,    54,    67,   133,    57,    38,    39,    40,
      68,    38,    39,    40,   130,    35,    58,    69,    73,    70,
      35,    36,    37,    71,    35,    93,    36,    37,   111,   127,
      36,    37,    38,    39,    40,    94,   118,    38,    39,    40,
      19,    38,    39,    40,   126,    35,   122,    27,   134,    19,
     128,    36,    37,    35,    31,   135,    32,   132,    55,    36,
      37,     0,    38,    39,    40,     0,     0,    35,     0,     0,
      38,    39,    40,    36,    37,     0,     0,     0,     0,   113,
       0,     0,     0,     0,    38,    39,    40,   115,     0,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,    85,
       0,   129,    86,    87,    88,    89,    90,    91,     0,     0,
      92,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,    85,     0,     0,    86,    87,    88,    89,    90,    91,
       0,    95,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,     0,     0,    86,    87,    88,    89,    90,
      91,     0,    96,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,    85,     0,     0,    86,    87,    88,    89,
      90,    91,     0,    97,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,    85,     0,     0,    86,    87,    88,
      89,    90,    91,     0,   119,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,    85,     0,     0,    86,    87,
      88,    89,    90,    91,     0,   131,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,    85,   117,     0,    86,
      87,    88,    89,    90,    91,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,    85,     0,     0,    86,    87,
      88,    89,    90,    91,    79,     0,    81,    82,    83,    84,
       0,     0,    81,    82,    83,    84,     0,    86,    87,    88,
      89,    90,    91,    86,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,     0,     0,     0,     0,     0,     0,     0,
      -1,    -1,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      38,    55,    57,    58,     3,     4,     5,     6,    63,    64,
      65,    37,    38,     3,     4,     5,     6,    37,     7,    39,
       0,    10,    33,    34,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     5,    28,    94,
       5,    35,    32,    11,    12,    35,     7,     8,     9,    10,
       5,     5,    13,    38,    22,    23,    24,    95,    96,   113,
       5,   115,   117,   118,     5,    36,    11,    12,     5,    41,
      11,    12,    40,     5,    37,   129,    35,    22,    23,    24,
      37,    22,    23,    24,   122,     5,    35,    37,    23,    37,
       5,    11,    12,    37,     5,    40,    11,    12,    23,    40,
      11,    12,    22,    23,    24,    35,    35,    22,    23,    24,
      16,    22,    23,    24,    37,     5,    25,    25,    37,    25,
      40,    11,    12,     5,    30,    40,    30,   128,    39,    11,
      12,    -1,    22,    23,    24,    -1,    -1,     5,    -1,    -1,
      22,    23,    24,    11,    12,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    22,    23,    24,    39,    -1,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      -1,    39,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    16,    -1,    18,    19,    20,    21,
      -1,    -1,    18,    19,    20,    21,    -1,    29,    30,    31,
      32,    33,    34,    29,    30,    31,    32,    33,    34,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    43,    44,    45,    49,
      51,     0,    43,     5,    52,    43,    35,    37,    38,    45,
      46,    47,    48,     5,     5,    38,    36,    46,    37,    39,
      50,    45,    51,    53,     5,     5,    11,    12,    22,    23,
      24,    40,    54,    55,    56,    57,    59,    60,    61,    41,
       3,     4,     5,     6,     5,    39,    54,    35,    35,     3,
       4,     5,     6,    28,    32,    35,    62,    37,    37,    37,
      37,    37,    53,    23,    62,    62,    62,    62,    62,    16,
      17,    18,    19,    20,    21,    26,    29,    30,    31,    32,
      33,    34,    37,    40,    35,    36,    36,    36,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    23,    62,    39,    54,    39,    54,    27,    35,    36,
      53,    53,    25,    58,    62,    62,    37,    40,    40,    39,
      54,    36,    58,    53,    37,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    45,    45,    45,    45,
      45,    46,    47,    47,    48,    48,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    60,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     6,     1,     1,     1,     1,
       1,     2,     1,     3,     0,     1,     9,     0,     2,     3,
       1,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       5,     7,     7,     9,     6,     8,     0,     2,     4,     3,
       3,     3,     3,     3,     4,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 68 "parse.y"
                              {
			if(command_options.construct_ast()){
				(yyval.program) = new program_node();
				(yyval.program)->add_procedure((yyvsp[0].procedure));
				if(command_options.is_show_ast_selected()){ 
					string file_name = command_options.get_file_name();
					if(!command_options.is_demo_mode_selected()){
						astout = fopen((file_name+".ast").c_str(), "w");
					};
					fprintf(astout, "Program:\n");
					(yyvsp[0].procedure)->print_node(astout);
				};
			};
		}
#line 1536 "y.tab.c"
    break;

  case 3:
#line 82 "parse.y"
                                              {
			if(command_options.construct_ast()){
					for(vector<symbol_table_entry*>::iterator it = (*(yyvsp[-1].symbol_table_entry_list)).begin();it!=(*(yyvsp[-1].symbol_table_entry_list)).end();it++){
						(*it)->set_symbol_scope(global);
						if(! global_symtab->check_entry((*it)->get_var_name()))  
							global_symtab->push_entry(*it);
						else{
							cerr << "Variable has been declared more than once in Global scope\n";
							exit(1);
						}
					}
					(yyval.program) =  (yyvsp[0].program);
				}
		}
#line 1555 "y.tab.c"
    break;

  case 4:
#line 97 "parse.y"
                        {
				(yyval.program) = (yyvsp[0].program);
			}
#line 1563 "y.tab.c"
    break;

  case 5:
#line 103 "parse.y"
                                                        {
								if(command_options.construct_ast()){
									if(!declared){
										if((yyvsp[-5].d_type) == void_type and *(yyvsp[-4].id) == "main"){
											for(vector<symbol_table_entry*>::iterator it = (*(yyvsp[-2].symbol_table_entry_list)).begin();it!= (*(yyvsp[-2].symbol_table_entry_list)).end();it++){
												if((*it)->get_var_name()=="main"){
													cerr<<"arguments name shouldn't be name\n";
													exit(1);
												};
												arg_data_types.push_back((*it)->get_data_type());
											}
											(yyval.procedure) = new procedure_node(void_type,(yyvsp[-4].id),local_symtab,yylineno);
										}
										else{
											cerr<< "procedure_declaration type must be void and name of func should be main\n";
											exit(1);
										};
										declared = true;
									} else {
										cerr << "Procedure redeclaration\n";
										exit(1);
									}
								}
							}
#line 1592 "y.tab.c"
    break;

  case 6:
#line 130 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyval.d_type) = int_type;
					}
				}
#line 1602 "y.tab.c"
    break;

  case 7:
#line 136 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyval.d_type) = bool_type;
					}
				}
#line 1612 "y.tab.c"
    break;

  case 8:
#line 142 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyval.d_type) = float_type;
					}

				}
#line 1623 "y.tab.c"
    break;

  case 9:
#line 149 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyval.d_type) = void_type;
					}
				}
#line 1633 "y.tab.c"
    break;

  case 10:
#line 155 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyval.d_type) = string_type;
					}
				}
#line 1643 "y.tab.c"
    break;

  case 11:
#line 163 "parse.y"
                        {
				(yyval.sym_tab_entry) = new symbol_table_entry(*(yyvsp[0].id),(yyvsp[-1].d_type),yylineno);
			}
#line 1651 "y.tab.c"
    break;

  case 12:
#line 169 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyval.symbol_table_entry_list) = new vector<symbol_table_entry *>();
						(yyval.symbol_table_entry_list)->push_back((yyvsp[0].sym_tab_entry));
					}
				}
#line 1662 "y.tab.c"
    break;

  case 13:
#line 176 "parse.y"
                                {
					if(command_options.construct_ast()){
						(yyvsp[-2].symbol_table_entry_list)->push_back((yyvsp[0].sym_tab_entry));
						(yyval.symbol_table_entry_list) = (yyvsp[-2].symbol_table_entry_list);
					}
				}
#line 1673 "y.tab.c"
    break;

  case 14:
#line 185 "parse.y"
                                                {
							if(command_options.construct_ast()){
								(yyval.symbol_table_entry_list) = new vector<symbol_table_entry*>();
							}
						}
#line 1683 "y.tab.c"
    break;

  case 15:
#line 191 "parse.y"
                                                {
							if(command_options.construct_ast()){
								(yyval.symbol_table_entry_list) = (yyvsp[0].symbol_table_entry_list);
							}
						}
#line 1693 "y.tab.c"
    break;

  case 16:
#line 199 "parse.y"
                                                        {
								if(command_options.construct_ast()){
									if((yyvsp[-8].d_type) == void_type and *(yyvsp[-7].id) == "main"){
										if(arg_data_types.size() > 0 and (*(yyvsp[-5].symbol_table_entry_list)).size() != arg_data_types.size()) {
											cout<<arg_data_types.size()<<endl;
											cerr<<"number of arguments must match in procedure\n";
											exit(1);
										}
										int i =0;
										for(vector<symbol_table_entry*>::iterator it = (*(yyvsp[-5].symbol_table_entry_list)).begin();it!= (*(yyvsp[-5].symbol_table_entry_list)).end(),i<arg_data_types.size();it++,i++){
											if((*it)->get_data_type() != arg_data_types[i]){
												cerr<<"type of arguments must be same in procedure and its declaration\n";
												exit(1);
											};
										}
										for(vector<symbol_table_entry*>::iterator it = (*(yyvsp[-5].symbol_table_entry_list)).begin();it!= (*(yyvsp[-5].symbol_table_entry_list)).end();it++){
											if(! local_symtab->check_entry((*it)->get_var_name())){
												if((*it)->get_var_name()=="main"){
													cerr<<"arguments name shouldn't be main\n";
													exit(1);
												};
												local_symtab->push_entry(*it);
											}
											else{
												cerr << "Argument has been declared more than once\n";
												exit(1);
											}
										}

										for(vector<symbol_table_entry*>::iterator it = (*(yyvsp[-2].symbol_table_entry_list)).begin();it!= (*(yyvsp[-2].symbol_table_entry_list)).end();it++){
											if(! local_symtab->check_entry((*it)->get_var_name())){
												if((*it)->get_var_name()=="main"){
													cerr<<"arguments name shouldn't be main\n";
													exit(1);
												};
												local_symtab->push_entry(*it);
											}
											else{
												cerr << "Argument and local Variable has same name\n";
												exit(1);
											}
										}


										(yyval.procedure) = new procedure_node(void_type,(yyvsp[-7].id),local_symtab,yylineno);
										(yyval.procedure)->add_stmt_list(*(yyvsp[-1].ast_node_list));
										(yyval.procedure)->add_arg(*(yyvsp[-5].symbol_table_entry_list));
										if(command_options.construct_tac()){
											vector<tac_stmt> taclist = build_tac((yyval.procedure));
											if(command_options.is_show_tac_selected()){ 
												string file_name = command_options.get_file_name();
												if(!command_options.is_demo_mode_selected()){
													tacout = fopen((file_name+".tac").c_str(), "w");
												};
												fprintf(tacout, "**PROCEDURE: main\n");
												print_tac(taclist, tacout);
											}
										}
									}
									else{
										cerr<<"procedure return type must be void and name of func should be main";
										exit(1);
									}
								}
							}
#line 1763 "y.tab.c"
    break;

  case 17:
#line 268 "parse.y"
                                                                {
									if(command_options.construct_ast()){
										(yyval.symbol_table_entry_list) = new vector<symbol_table_entry*>();
									}
								}
#line 1773 "y.tab.c"
    break;

  case 18:
#line 274 "parse.y"
                                                                {
									if(command_options.construct_ast()){
										for(vector<symbol_table_entry*>:: iterator it = (*(yyvsp[0].symbol_table_entry_list)).begin();it != (*(yyvsp[0].symbol_table_entry_list)).end();it++){
											for(vector<symbol_table_entry*>::iterator it1 = (*(yyvsp[-1].symbol_table_entry_list)).begin();it1 != (*(yyvsp[-1].symbol_table_entry_list)).end();it1++){
												if((*it)->get_data_type() == (*it1)->get_data_type() && (*it)->get_var_name() == (*it1)->get_var_name()){
													cerr<<"Variable has been declared more than once\n";
													exit(1);
												}
											}
											(*((yyvsp[-1].symbol_table_entry_list))).push_back(*it);
										};
										(yyval.symbol_table_entry_list) = (yyvsp[-1].symbol_table_entry_list);
									}
								}
#line 1792 "y.tab.c"
    break;

  case 19:
#line 290 "parse.y"
                                                {
							if(command_options.construct_ast()){
								for(vector<symbol_table_entry*>:: iterator it = (*(yyvsp[-1].symbol_table_entry_list)).begin();it != (*(yyvsp[-1].symbol_table_entry_list)).end();it++){
									if((yyvsp[-2].d_type) != void_type){
										(*it)->set_data_type((yyvsp[-2].d_type));
										// if(! global_symtab->check_entry((*it)->get_var_name())){
										universal_symtab->push_entry(*it);
										if((*it)->get_var_name()=="main"){
												cerr<<"variable name shouldn't be name\n";
												exit(1);
											};
										// }
										// else{
										// 	cerr << "Variable has been declared more than once\n";
										// 	exit(1);
										// }
									}
									else{
										cerr<<"shouldn't be void\n";
										exit(1);
									}
								}
								(yyval.symbol_table_entry_list) = (yyvsp[-1].symbol_table_entry_list);
							}					
						}
#line 1822 "y.tab.c"
    break;

  case 20:
#line 319 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.symbol_table_entry_list) = new vector<symbol_table_entry *> ();
					//$1 = $1 + "_";
					symbol_table_entry* a = new symbol_table_entry(*(yyvsp[0].id),int_type,yylineno);
					(*(yyval.symbol_table_entry_list)).push_back(a);
				}
			}
#line 1835 "y.tab.c"
    break;

  case 21:
#line 328 "parse.y"
                        {	
				if(command_options.construct_ast()){
					//$3 = $3 + "_";
					symbol_table_entry* b = new symbol_table_entry(*(yyvsp[0].id),int_type,yylineno);
					(*(yyvsp[-2].symbol_table_entry_list)).push_back(b);
					(yyval.symbol_table_entry_list) = (yyvsp[-2].symbol_table_entry_list);
				}

			}
#line 1849 "y.tab.c"
    break;

  case 22:
#line 341 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast_node_list) = new vector<ast_node *> ();
						}
					}
#line 1859 "y.tab.c"
    break;

  case 23:
#line 347 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast_node_list) = (yyvsp[-1].ast_node_list);
							(yyval.ast_node_list)->push_back((yyvsp[0].ast));	
						}
					}
#line 1870 "y.tab.c"
    break;

  case 30:
#line 359 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast) = new ast_node(while_type, yylineno);
							if(!((yyval.ast)->add_child((yyvsp[-2].ast)))) exit(1);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							stmt_list_node->add_child((yyvsp[0].ast));
							(yyval.ast)->add_child(stmt_list_node);
						}
					}
#line 1884 "y.tab.c"
    break;

  case 31:
#line 369 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast) = new ast_node(while_type, yylineno);
							(yyval.ast)->add_child((yyvsp[-4].ast));
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							for(int i=0; i<(yyvsp[-1].ast_node_list)->size(); i++) stmt_list_node->add_child((*(yyvsp[-1].ast_node_list))[i]);
							(yyval.ast)->add_child(stmt_list_node);
						}
					}
#line 1898 "y.tab.c"
    break;

  case 32:
#line 380 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast) = new ast_node(do_while_type, yylineno);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							stmt_list_node->add_child((yyvsp[-5].ast));
							(yyval.ast)->add_child(stmt_list_node);
							(yyval.ast)->add_child((yyvsp[-2].ast));
						}
					}
#line 1912 "y.tab.c"
    break;

  case 33:
#line 390 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast) = new ast_node(do_while_type, yylineno);
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							for(int i=0; i<(yyvsp[-6].ast_node_list)->size(); i++) stmt_list_node->add_child((*(yyvsp[-6].ast_node_list))[i]);
							(yyval.ast)->add_child(stmt_list_node);
							(yyval.ast)->add_child((yyvsp[-2].ast));
						}
					}
#line 1926 "y.tab.c"
    break;

  case 34:
#line 401 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast) = new ast_node(if_else_type, yylineno);
							(yyval.ast)->add_child((yyvsp[-3].ast));
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							stmt_list_node->add_child((yyvsp[-1].ast));
							(yyval.ast)->add_child(stmt_list_node);
							if((yyvsp[0].ast)->num_child > 0) (yyval.ast)->add_child((yyvsp[0].ast));
						}
					}
#line 1941 "y.tab.c"
    break;

  case 35:
#line 412 "parse.y"
                                        {
						if(command_options.construct_ast()){
							(yyval.ast) = new ast_node(if_else_type, yylineno);
							(yyval.ast)->add_child((yyvsp[-5].ast));
							ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
							for(int i=0; i<(yyvsp[-2].ast_node_list)->size(); i++) stmt_list_node->add_child((*(yyvsp[-2].ast_node_list))[i]);
							(yyval.ast)->add_child(stmt_list_node);
							if((yyvsp[0].ast)->num_child > 0) (yyval.ast)->add_child((yyvsp[0].ast));
						}
					}
#line 1956 "y.tab.c"
    break;

  case 36:
#line 424 "parse.y"
                                                {
							if(command_options.construct_ast()){
								(yyval.ast) = new ast_node(stmt_list_type, yylineno);
							}
						}
#line 1966 "y.tab.c"
    break;

  case 37:
#line 430 "parse.y"
                                                {
							if(command_options.construct_ast()){
								(yyval.ast) = new ast_node(stmt_list_type, yylineno);
								ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
								stmt_list_node->add_child((yyvsp[0].ast));
								(yyval.ast)->add_child(stmt_list_node);
							}
						}
#line 1979 "y.tab.c"
    break;

  case 38:
#line 439 "parse.y"
                                                {
							if(command_options.construct_ast()){
								(yyval.ast) = new ast_node(stmt_list_type, yylineno);
								ast_node* stmt_list_node = new ast_node(stmt_list_type, yylineno);
								for(int i=0; i<(yyvsp[-1].ast_node_list)->size(); i++) stmt_list_node->add_child((*(yyvsp[-1].ast_node_list))[i]);
								(yyval.ast)->add_child(stmt_list_node);
							}
						}
#line 1992 "y.tab.c"
    break;

  case 39:
#line 452 "parse.y"
                        {
					if(command_options.construct_ast()){
						if(universal_symtab->check_entry(*(yyvsp[-1].id))){
							(yyval.ast) = new ast_node(write_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, (yyvsp[-1].id),universal_symtab->get_entry(*(yyvsp[-1].id))->get_data_type(),yylineno);
							if(!((yyval.ast)->add_child(id))) exit(1);
						}
						else if(local_symtab->check_entry(*(yyvsp[-1].id))){
							(yyval.ast) = new ast_node(write_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, (yyvsp[-1].id),local_symtab->get_entry(*(yyvsp[-1].id))->get_data_type(),yylineno);
							if(!((yyval.ast)->add_child(id))) exit(1);
						}
						else {
							yyerror((char*)"Variable has not been declared");
						}
					}
			}
#line 2014 "y.tab.c"
    break;

  case 40:
#line 470 "parse.y"
                        {	
				if(command_options.construct_ast()){
					node_val s;
					s.const_string_val = (yyvsp[-1].string_constant);
					ast_node * str = new ast_node(const_type, s,string_type,yylineno);
					(yyval.ast) = new ast_node(write_stmt_type, yylineno);
					if(!((yyval.ast)->add_child(str))) exit(1);
				}
			}
#line 2028 "y.tab.c"
    break;

  case 41:
#line 480 "parse.y"
                        {
				if(command_options.construct_ast()){
					node_val s;
					s.const_int_val = (yyvsp[-1].int_num);
					ast_node * str = new ast_node(const_type, s,int_type,yylineno);
					(yyval.ast) = new ast_node(write_stmt_type, yylineno);
					if(!((yyval.ast)->add_child(str))) exit(1);
				}
			}
#line 2042 "y.tab.c"
    break;

  case 42:
#line 490 "parse.y"
                        {
				if(command_options.construct_ast()){
					node_val s;
					s.const_float_val = (yyvsp[-1].float_num);
					ast_node * str = new ast_node(const_type, s,float_type,yylineno);
					(yyval.ast) = new ast_node(write_stmt_type, yylineno);
					if(!((yyval.ast)->add_child(str))) exit(1);
				}
			}
#line 2056 "y.tab.c"
    break;

  case 43:
#line 502 "parse.y"
                        {
				if(command_options.construct_ast()){
					if(universal_symtab->check_entry(*(yyvsp[-1].id))){
						(yyval.ast) = new ast_node(read_stmt_type, yylineno);
						ast_node * id = new ast_node(id_type, (yyvsp[-1].id),universal_symtab->get_entry(*(yyvsp[-1].id))->get_data_type(),yylineno);
						if(!((yyval.ast)->add_child(id))) exit(1);
					}
					else if(local_symtab->check_entry(*(yyvsp[-1].id))){
						(yyval.ast) = new ast_node(read_stmt_type, yylineno);
						ast_node * id = new ast_node(id_type, (yyvsp[-1].id),local_symtab->get_entry(*(yyvsp[-1].id))->get_data_type(),yylineno);
						if(!((yyval.ast)->add_child(id))) exit(1);
					}
					else 
						{cerr << "Variable has not been declared\n";exit(1);}
				}
			}
#line 2077 "y.tab.c"
    break;

  case 44:
#line 521 "parse.y"
                                {
					if(command_options.construct_ast()){
						if(universal_symtab->check_entry(*(yyvsp[-3].id))){
							(yyval.ast) = new ast_node(assgn_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, (yyvsp[-3].id),universal_symtab->get_entry(*(yyvsp[-3].id))->get_data_type(),yylineno);
							(yyval.ast)->add_child(id);
							(yyval.ast)->add_child((yyvsp[-1].ast));
						}
						else if(local_symtab->check_entry(*(yyvsp[-3].id))){
							(yyval.ast) = new ast_node(assgn_stmt_type, yylineno);
							ast_node * id = new ast_node(id_type, (yyvsp[-3].id),local_symtab->get_entry(*(yyvsp[-3].id))->get_data_type(),yylineno);
							(yyval.ast)->add_child(id);
							(yyval.ast)->add_child((yyvsp[-1].ast));
						}
						else 
							{cerr << "Variable has not been declared\n";exit(1);}
					}
				}
#line 2100 "y.tab.c"
    break;

  case 45:
#line 544 "parse.y"
                        {	
				if(command_options.construct_ast()){
					node_val i;
					i.const_int_val = (yyvsp[0].int_num);
					(yyval.ast) = new ast_node(const_type, i,int_type,yylineno);
				}

			}
#line 2113 "y.tab.c"
    break;

  case 46:
#line 553 "parse.y"
                        {	
				if(command_options.construct_ast()){
					node_val f;
					f.const_float_val = (yyvsp[0].float_num);
					(yyval.ast) = new ast_node(const_type, f,float_type,yylineno);
				}
			}
#line 2125 "y.tab.c"
    break;

  case 47:
#line 562 "parse.y"
                        {	
				if(command_options.construct_ast()){
					node_val s;
					s.const_string_val = (yyvsp[0].string_constant);
					(yyval.ast) = new ast_node(const_type, s,string_type,yylineno);
				}	
			}
#line 2137 "y.tab.c"
    break;

  case 48:
#line 570 "parse.y"
                        {	
				if(command_options.construct_ast()){
					if(universal_symtab->check_entry(*(yyvsp[0].id))){
						(yyval.ast) = new ast_node(id_type, (yyvsp[0].id),universal_symtab->get_entry(*(yyvsp[0].id))->get_data_type(),yylineno);
					}

					else if(local_symtab->check_entry(*(yyvsp[0].id))){
						(yyval.ast) = new ast_node(id_type, (yyvsp[0].id),local_symtab->get_entry(*(yyvsp[0].id))->get_data_type(),yylineno);
					}
					else 
						{cerr << "Variable has not been declared\n";exit(1);}
				}
			}
#line 2155 "y.tab.c"
    break;

  case 49:
#line 584 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, plus_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2167 "y.tab.c"
    break;

  case 50:
#line 592 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, minus_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2179 "y.tab.c"
    break;

  case 51:
#line 600 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, mult_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2191 "y.tab.c"
    break;

  case 52:
#line 608 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, div_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2203 "y.tab.c"
    break;

  case 53:
#line 616 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(un_op_type, uminus_val,yylineno);
					if(!((yyval.ast)->add_child((yyvsp[0].ast)))) {cerr << "Uminus error\n";exit(1);}
				}
			}
#line 2214 "y.tab.c"
    break;

  case 54:
#line 623 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = (yyvsp[-1].ast);
				}
			}
#line 2224 "y.tab.c"
    break;

  case 55:
#line 629 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, eq_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2236 "y.tab.c"
    break;

  case 56:
#line 637 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, ne_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2248 "y.tab.c"
    break;

  case 57:
#line 645 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, lt_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2260 "y.tab.c"
    break;

  case 58:
#line 653 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, gt_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2272 "y.tab.c"
    break;

  case 59:
#line 661 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, lte_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2284 "y.tab.c"
    break;

  case 60:
#line 669 "parse.y"
                        {	
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, gte_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2296 "y.tab.c"
    break;

  case 61:
#line 677 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, or_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2308 "y.tab.c"
    break;

  case 62:
#line 685 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(bin_op_type, and_val,yylineno);
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2320 "y.tab.c"
    break;

  case 63:
#line 693 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(un_op_type, neg_val,yylineno);
					if(!((yyval.ast)->add_child((yyvsp[0].ast))))  exit(1);
				}
			}
#line 2331 "y.tab.c"
    break;

  case 64:
#line 700 "parse.y"
                        {
				if(command_options.construct_ast()){
					(yyval.ast) = new ast_node(ter_op_type, yylineno);
					(yyval.ast)->add_child((yyvsp[-4].ast));
					(yyval.ast)->add_child((yyvsp[-2].ast));
					(yyval.ast)->add_child((yyvsp[0].ast));
				}
			}
#line 2344 "y.tab.c"
    break;


#line 2348 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 710 "parse.y"


void yyerror(char* s){
	if(strcmp(s,"invalid character") == 0) cerr<<"sclp error: File: error1.c, Line: "<<yylineno<<", Next Token: INTEGER, Lexeme: \""<<yytext<<"\"\n            Description: Illegal character '"<<yytext<<"'\n";
	else cerr << "sclp error: Cannot parse input\n";
	exit(1);
}
