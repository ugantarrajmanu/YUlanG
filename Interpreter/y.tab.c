
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser1.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    int yylex(void);
    int yyerror(const char *s);

    #define MAX_VARS 100
    typedef struct
    {
        char *type;
        char *name;
        int value;
        char *str;
    } symbol;

    symbol symbolTable[MAX_VARS];

    int symbol_count = 0;

    // Symbol table function;
    int lookup(char *name);                                    // for loocking for a variable
    void insert(char *name, char *type, int value, char *str); // for inserting a variable
    int getIntValue(char *name);                               // for getting the value of a variable
    char* getStringValue(char *name);                          // for getting the value of a variable
    void setValue(char *name, int value, char *str);           // for setting the value of a variable

    // AST
    #include "AST.h"

    // Evaluation function
    int eval_expr(ASTNode * node);
    void eval(ASTNode * node);



/* Line 189 of yacc.c  */
#line 112 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN = 258,
     YUG_OR = 259,
     YUG_AND = 260,
     YUG_NOT_EQUAL = 261,
     YUG_EQUAL = 262,
     YUG_GREATER_EQUAL = 263,
     YUG_GREATER = 264,
     YUG_LESS_EQUAL = 265,
     YUG_LESS = 266,
     YUG_IF = 267,
     YUG_ELSE = 268,
     MINUS = 269,
     PLUS = 270,
     DIVIDE = 271,
     MULTIPLY = 272,
     YUG_NOT = 273,
     RPARAN = 274,
     LPARAN = 275,
     LBRACE = 276,
     RBRACE = 277,
     YUG_DECLARATION = 278,
     YUG_INT = 279,
     YUG_EOS = 280,
     YUG_STR = 281,
     YUG_IF_THEN = 282,
     YUG_KO = 283,
     YUG_SE = 284,
     YUG_TAK = 285,
     YUG_INIT = 286,
     YUG_PRINT_END = 287,
     NUMBER = 288,
     IDENTIFIER = 289,
     STRING = 290
   };
#endif
/* Tokens.  */
#define ASSIGN 258
#define YUG_OR 259
#define YUG_AND 260
#define YUG_NOT_EQUAL 261
#define YUG_EQUAL 262
#define YUG_GREATER_EQUAL 263
#define YUG_GREATER 264
#define YUG_LESS_EQUAL 265
#define YUG_LESS 266
#define YUG_IF 267
#define YUG_ELSE 268
#define MINUS 269
#define PLUS 270
#define DIVIDE 271
#define MULTIPLY 272
#define YUG_NOT 273
#define RPARAN 274
#define LPARAN 275
#define LBRACE 276
#define RBRACE 277
#define YUG_DECLARATION 278
#define YUG_INT 279
#define YUG_EOS 280
#define YUG_STR 281
#define YUG_IF_THEN 282
#define YUG_KO 283
#define YUG_SE 284
#define YUG_TAK 285
#define YUG_INIT 286
#define YUG_PRINT_END 287
#define NUMBER 288
#define IDENTIFIER 289
#define STRING 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 39 "parser1.y"

    int value;
    char *id;
    char *str;
    struct ASTNode *node;



/* Line 214 of yacc.c  */
#line 227 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 239 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNRULES -- Number of states.  */
#define YYNSTATES  96

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    23,
      30,    35,    40,    47,    58,    70,    80,    82,    85,    88,
      91,    94,    96,    98,   100,   102,   107,   112,   116,   120,
     124,   128,   132,   136,   140,   144,   148,   152,   156,   160,
     164,   168,   170
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    37,    38,    -1,    39,    -1,
      40,    -1,    41,    -1,    44,    -1,    23,    34,     3,    45,
      24,    25,    -1,    23,    34,     3,    35,    26,    25,    -1,
      34,     3,    45,    25,    -1,    34,     3,    35,    25,    -1,
      12,    45,    27,    21,    42,    22,    -1,    12,    45,    27,
      21,    42,    22,    13,    21,    42,    22,    -1,    31,    34,
      28,    45,    29,    45,    30,    25,    21,    42,    22,    -1,
      31,    34,    28,    45,    30,    25,    21,    42,    22,    -1,
      43,    -1,    43,    39,    -1,    43,    40,    -1,    43,    41,
      -1,    43,    44,    -1,    39,    -1,    40,    -1,    44,    -1,
      41,    -1,    31,    35,    32,    25,    -1,    31,    45,    32,
      25,    -1,    45,    15,    45,    -1,    45,    14,    45,    -1,
      45,    17,    45,    -1,    45,    16,    45,    -1,    45,     7,
      45,    -1,    45,     6,    45,    -1,    45,    11,    45,    -1,
      45,    10,    45,    -1,    45,     9,    45,    -1,    45,     8,
      45,    -1,    45,     4,    45,    -1,    45,     5,    45,    -1,
      45,    18,    45,    -1,    20,    45,    19,    -1,    33,    -1,
      34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    82,    83,    84,    85,    87,    89,
      93,   102,   111,   112,   116,   119,   131,   133,   134,   135,
     136,   137,   138,   139,   140,   144,   145,   147,   148,   149,
     150,   152,   153,   155,   156,   157,   158,   160,   161,   162,
     164,   166,   167
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "YUG_OR", "YUG_AND",
  "YUG_NOT_EQUAL", "YUG_EQUAL", "YUG_GREATER_EQUAL", "YUG_GREATER",
  "YUG_LESS_EQUAL", "YUG_LESS", "YUG_IF", "YUG_ELSE", "MINUS", "PLUS",
  "DIVIDE", "MULTIPLY", "YUG_NOT", "RPARAN", "LPARAN", "LBRACE", "RBRACE",
  "YUG_DECLARATION", "YUG_INT", "YUG_EOS", "YUG_STR", "YUG_IF_THEN",
  "YUG_KO", "YUG_SE", "YUG_TAK", "YUG_INIT", "YUG_PRINT_END", "NUMBER",
  "IDENTIFIER", "STRING", "$accept", "program", "statement", "assign",
  "ifstatement", "forstatement", "blockstatement", "body",
  "printstatement", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    39,    39,
      39,    39,    40,    40,    41,    41,    42,    43,    43,    43,
      43,    43,    43,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       4,     4,     6,    10,    11,     9,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     0,    41,    42,     0,     0,    42,     0,     0,     0,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    37,    38,    32,    31,    36,    35,
      34,    33,    28,    27,    30,    29,    39,     0,     0,     0,
       0,    25,    26,    11,    10,    21,    22,    24,     0,    16,
      23,     0,     0,     0,     0,    12,    17,    18,    19,    20,
       9,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    13,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,    65,    66,    67,    68,    69,    70,    14
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -75
static const yytype_int16 yypact[] =
{
      34,   -19,   -31,   157,    15,    33,   -75,   -75,   -75,   -75,
     -75,   -19,   -75,   -75,   107,    16,    19,    12,    44,   166,
     -75,   -75,   165,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,    42,   169,   -19,    41,
      47,    60,   122,   -75,   200,   213,   224,   224,    22,    22,
      22,    22,    25,    25,    51,    51,    51,    34,    66,   144,
      73,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    64,    34,
     -75,    68,    84,   -19,    85,   106,   -75,   -75,   -75,   -75,
     -75,   -75,    90,   114,   120,   117,    34,    34,   123,   121,
     124,    34,   -75,   -75,   134,   -75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   140,     2,     4,     5,   -74,   -75,     6,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    11,     7,    15,     8,     9,    10,     7,    22,     8,
       9,    10,    89,    90,    12,    13,    42,    94,    19,    37,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    20,    59,    60,    31,    32,    33,    34,
      35,    33,    34,    35,    39,     1,     1,    38,    23,    24,
      25,    26,    27,    28,    29,    30,     2,     2,    31,    32,
      33,    34,    35,    57,     3,     3,    61,     4,     4,    35,
      82,    76,    62,    77,    78,    79,    40,    23,    24,    25,
      26,    27,    28,    29,    30,    63,    75,    31,    32,    33,
      34,    35,    71,    80,    23,    24,    25,    26,    27,    28,
      29,    30,    73,    74,    31,    32,    33,    34,    35,    81,
      83,    23,    24,    25,    26,    27,    28,    29,    30,    84,
      85,    31,    32,    33,    34,    35,    23,    24,    25,    26,
      27,    28,    29,    30,    36,    86,    31,    32,    33,    34,
      35,    87,    88,    92,    91,    21,    93,    64,    23,    24,
      25,    26,    27,    28,    29,    30,    95,     0,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,    72,    23,
      24,    25,    26,    27,    28,    29,    30,    11,     0,    31,
      32,    33,    34,    35,    43,     0,    11,     0,     0,    11,
      12,    16,    17,     0,     0,     0,     0,     0,     0,    12,
      13,    41,    12,    13,    58,    24,    25,    26,    27,    28,
      29,    30,     0,     0,    31,    32,    33,    34,    35,    25,
      26,    27,    28,    29,    30,     0,     0,    31,    32,    33,
      34,    35,    27,    28,    29,    30,     0,     0,    31,    32,
      33,    34,    35
};

static const yytype_int8 yycheck[] =
{
       3,    20,     0,    34,     0,     0,     0,     5,    11,     5,
       5,     5,    86,    87,    33,    34,    19,    91,     3,     3,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,    37,    38,    14,    15,    16,    17,
      18,    16,    17,    18,    32,    12,    12,    28,     4,     5,
       6,     7,     8,     9,    10,    11,    23,    23,    14,    15,
      16,    17,    18,    21,    31,    31,    25,    34,    34,    18,
      73,    69,    25,    69,    69,    69,    32,     4,     5,     6,
       7,     8,     9,    10,    11,    25,    22,    14,    15,    16,
      17,    18,    26,    25,     4,     5,     6,     7,     8,     9,
      10,    11,    29,    30,    14,    15,    16,    17,    18,    25,
      25,     4,     5,     6,     7,     8,     9,    10,    11,    13,
      30,    14,    15,    16,    17,    18,     4,     5,     6,     7,
       8,     9,    10,    11,    27,    21,    14,    15,    16,    17,
      18,    21,    25,    22,    21,     5,    22,    25,     4,     5,
       6,     7,     8,     9,    10,    11,    22,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,     4,
       5,     6,     7,     8,     9,    10,    11,    20,    -1,    14,
      15,    16,    17,    18,    19,    -1,    20,    -1,    -1,    20,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    33,    34,    35,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    23,    31,    34,    37,    38,    39,    40,    41,
      44,    20,    33,    34,    45,    34,    34,    35,    45,     3,
       0,    38,    45,     4,     5,     6,     7,     8,     9,    10,
      11,    14,    15,    16,    17,    18,    27,     3,    28,    32,
      32,    35,    45,    19,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    21,    35,    45,
      45,    25,    25,    25,    25,    39,    40,    41,    42,    43,
      44,    26,    24,    29,    30,    22,    39,    40,    41,    44,
      25,    25,    45,    25,    13,    30,    21,    21,    25,    42,
      42,    21,    22,    22,    42,    22
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 82 "parser1.y"
    { eval((yyvsp[(1) - (1)].node)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 83 "parser1.y"
    { eval((yyvsp[(1) - (1)].node)); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 84 "parser1.y"
    { eval((yyvsp[(1) - (1)].node)); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 85 "parser1.y"
    { eval((yyvsp[(1) - (1)].node)); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 87 "parser1.y"
    { (yyval.node) = makeVarDeclNode("int", makeIDNode(strdup((yyvsp[(2) - (6)].id))), (yyvsp[(4) - (6)].node)); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 89 "parser1.y"
    { 
                (yyval.node) = makeVarDeclNode("string", makeIDNode(strdup((yyvsp[(2) - (6)].id))), makeStringLiteralNode(strdup((yyvsp[(4) - (6)].str))));
            }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 93 "parser1.y"
    {
                if (lookup((yyvsp[(1) - (4)].id)) != -1) {
                    (yyval.node) = makeAssignNode("int", makeIDNode(strdup((yyvsp[(1) - (4)].id))), (yyvsp[(3) - (4)].node));
                } else {
                    printf("Error: Variable \'%s\' is not declared.....\n", (yyvsp[(1) - (4)].id));
                    exit(1);
                }
            }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 102 "parser1.y"
    {
                if (lookup((yyvsp[(1) - (4)].id)) != -1) {
                    (yyval.node) = makeAssignNode("string", makeIDNode(strdup((yyvsp[(1) - (4)].id))), makeStringLiteralNode(strdup((yyvsp[(3) - (4)].str))));
                } else {
                    printf("Error: Variable \'%s\' is not declared.....\n", (yyvsp[(1) - (4)].id));
                    exit(1);
                }
            }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 111 "parser1.y"
    { (yyval.node) = makeIfNode((yyvsp[(2) - (6)].node), (yyvsp[(5) - (6)].node), NULL); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 112 "parser1.y"
    {
                (yyval.node) = makeIfNode((yyvsp[(2) - (10)].node), (yyvsp[(5) - (10)].node), (yyvsp[(9) - (10)].node));
            }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 116 "parser1.y"
    { 
                (yyval.node) = makeForNode(makeIDNode(strdup((yyvsp[(2) - (11)].id))), (yyvsp[(4) - (11)].node), (yyvsp[(6) - (11)].node), (yyvsp[(10) - (11)].node)); 
            }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 119 "parser1.y"
    {
                int idx = lookup((yyvsp[(2) - (9)].id));
                if (idx != -1) {
                    (yyval.node) = makeForNode(makeIDNode(strdup((yyvsp[(2) - (9)].id))), makeLiteralNode(symbolTable[idx].value), (yyvsp[(4) - (9)].node), (yyvsp[(8) - (9)].node));                    
                } else {
                    printf("Error: Variable \'%s\' is not declared.....\n", (yyvsp[(2) - (9)].id));
                    exit(1);
                }
            }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 131 "parser1.y"
    { (yyval.node) = makeBlockNode((yyvsp[(1) - (1)].node)); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 133 "parser1.y"
    { (yyval.node) = makeBodyNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 134 "parser1.y"
    { (yyval.node) = makeBodyNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 135 "parser1.y"
    { (yyval.node) = makeBodyNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 136 "parser1.y"
    { (yyval.node) = makeBodyNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 137 "parser1.y"
    { (yyval.node) = makeBodyNode(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 138 "parser1.y"
    { (yyval.node) = makeBodyNode(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 139 "parser1.y"
    { (yyval.node) = makeBodyNode(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 140 "parser1.y"
    { (yyval.node) = makeBodyNode(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 144 "parser1.y"
    { (yyval.node) = makePrintNode(makeStringLiteralNode(strdup((yyvsp[(2) - (4)].str)))); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 145 "parser1.y"
    { (yyval.node) = makePrintNode((yyvsp[(2) - (4)].node)); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 147 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), PLUS, (yyvsp[(3) - (3)].node)); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 148 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), MINUS, (yyvsp[(3) - (3)].node)); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 149 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), MULTIPLY, (yyvsp[(3) - (3)].node)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 150 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), DIVIDE, (yyvsp[(3) - (3)].node)); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 152 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_EQUAL, (yyvsp[(3) - (3)].node)); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 153 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_NOT_EQUAL, (yyvsp[(3) - (3)].node)); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 155 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_LESS, (yyvsp[(3) - (3)].node)); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 156 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_LESS_EQUAL, (yyvsp[(3) - (3)].node)); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 157 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_GREATER, (yyvsp[(3) - (3)].node)); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 158 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_GREATER_EQUAL, (yyvsp[(3) - (3)].node)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 160 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_OR, (yyvsp[(3) - (3)].node)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 161 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_AND, (yyvsp[(3) - (3)].node)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 162 "parser1.y"
    { (yyval.node) = makeBinExprNode((yyvsp[(1) - (3)].node), YUG_NOT, (yyvsp[(3) - (3)].node)); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 164 "parser1.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 166 "parser1.y"
    { (yyval.node) = makeLiteralNode((yyvsp[(1) - (1)].value)); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 167 "parser1.y"
    { (yyval.node) = makeIDNode((yyvsp[(1) - (1)].id)); }
    break;



/* Line 1455 of yacc.c  */
#line 1839 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 168 "parser1.y"


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;        
    }
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }
    extern FILE *yyin;
    yyin = file;
    
    int parsed = yyparse();
    fclose(file);

    return parsed;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

// Symbol Table function
int lookup(char *name) {
    for (int i = 0; i < symbol_count; i++)  {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(char *name, char *type, int value, char *str) {
    int idx = lookup(name);
    if (idx == -1 && symbol_count < MAX_VARS) {
        symbolTable[symbol_count].name = name;
        symbolTable[symbol_count].type = type;
        symbolTable[symbol_count].value = value;
        symbolTable[symbol_count].str = str;
        symbol_count++;
    }
    else if (idx != -1) {
        // throw error
        printf("ErrorInserting: Variable \'%s\' already declared.....\n", name);
        exit(1);
    }
}

int getIntValue(char *name) {
    int index = lookup(name);
    if (index != -1) {
        return symbolTable[index].value;
    }
    else {
        // throw error
        printf("ErrorGetting: Variable \'%s\' is not declared.....\n", name);
        exit(1);
    }
}

char *getStringValue(char *name) {
    int index = lookup(name);
    if (index != -1) {
        return symbolTable[index].str;
    } else {
        // throw error
        printf("ErrorGetting: Variable \'%s\' is not declared.....\n", name);
        exit(1);
    }
}

void setValue(char *name, int value, char *str) {
    int index = lookup(name);
    if (index != -1) {
        if (str == NULL && symbolTable[index].type == "int") { 
            symbolTable[index].value = value;
        } else if (str && symbolTable[index].type == "string") {
            symbolTable[index].str = str;
        } else {
            printf("ErrorSetting: Variable \'%s\' is not declared.....\n", name);
            exit(1);
        }
    } else {
        printf("ErrorSetting: Variable \'%s\' is not declared.....\n", name);
    }
}

// AST Functions
ASTNode *makeLiteralNode(int value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Literal;
    newNode->Literal.value = value;
    return newNode;
}

ASTNode *makeStringLiteralNode(char *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = StringLiteral;
    newNode->StringLiteral.value = value;
    return newNode;
}

ASTNode *makeIDNode(char *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Identifier;
    newNode->Identifier.value = value;
    return newNode;
}

ASTNode *makeBinExprNode(ASTNode *left, int op, ASTNode *right) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = BinaryExpression;
    newNode->BinaryExpression.left = left;
    newNode->BinaryExpression.op = op;
    newNode->BinaryExpression.right = right;
    return newNode;
}

ASTNode *makeVarDeclNode(char *type, ASTNode *id, ASTNode *init) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = VariableDeclaration;
    newNode->VariableDeclaration.type = type;
    newNode->VariableDeclaration.id = id;
    newNode->VariableDeclaration.init = init;
    return newNode;
}

ASTNode *makeAssignNode(char *type, ASTNode *id, ASTNode *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Assignment;
    newNode->Assignment.type = type;
    newNode->Assignment.id = id;
    newNode->Assignment.value = value;
    return newNode;
}

ASTNode *makeIfNode(ASTNode *test, ASTNode *consequent, ASTNode *alternate) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = IfStatement;
    newNode->IfStatement.test = test;
    newNode->IfStatement.consequent = consequent;
    newNode->IfStatement.alternate = alternate;
    return newNode;
}

ASTNode *makeBlockNode(ASTNode *body) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = BlockStatement;
    newNode->BlockStatement.body = body;
    return newNode;
}

ASTNode *makeBodyNode(ASTNode *insideBody, ASTNode *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Body;
    newNode->Body.InsideBody = insideBody;
    newNode->Body.value = value;
    return newNode;
}

ASTNode *makePrintNode(ASTNode *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = PrintStatement;
    newNode->PrintStatement.value = value;
    return newNode;
}

ASTNode *makeForNode(ASTNode *id, ASTNode *start, ASTNode *end, ASTNode *body) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = ForStatement;
    newNode->ForStatement.id = id;
    newNode->ForStatement.start = start;
    newNode->ForStatement.end = end;
    newNode->ForStatement.body = body;
}

void eval(ASTNode *node) {
    if (node == NULL)
        return;
    int expr_value;
    char *id_value;
    switch (node->type) {
        case VariableDeclaration:
            id_value = node->VariableDeclaration.id->Identifier.value;
            if (node->VariableDeclaration.type == "int") {
                expr_value = eval_expr(node->VariableDeclaration.init);
                insert(id_value, node->VariableDeclaration.type, expr_value, NULL);
            } else if (node->VariableDeclaration.type == "string") {
                char* str_value = node->VariableDeclaration.init->StringLiteral.value;
                insert(id_value, node->VariableDeclaration.type, -999, str_value);
            }
            // printf("%s %s %d\n", node->VariableDeclaration.type, id_value, expr_value);)
            break;

        case Assignment:
            id_value = node->Assignment.id->Identifier.value;
            int idx = lookup(id_value);
            if (node->Assignment.type == symbolTable[idx].type) {
                if (symbolTable[idx].type == "int") {
                    expr_value = eval_expr(node->Assignment.value);
                    setValue(id_value, expr_value, NULL);
                } else if (symbolTable[idx].type == "string"){
                    setValue(id_value, -999, getStringValue(id_value));
                }
            } else {
                exit(1);
            }
            // printf("%s %d\n",id_value, expr_value);
            break;

        case PrintStatement:
            if (node->PrintStatement.value->type == Identifier) {
                char* id = node->PrintStatement.value->Identifier.value;
                int idx = lookup(id);
                if ( idx == -1 ) {
                    printf("Error: Variable \'%s\' is not declared.....\n", id);
                    exit(1);
                }
                if ( symbolTable[idx].type == "int" ) {
                    printf("%d\n", getIntValue(id));
                } else if ( symbolTable[idx].type == "string" ) {
                    printf("%s\n", getStringValue(id));
                }
            }else if (node->PrintStatement.value->type == StringLiteral) {
                    printf("%s\n", node->PrintStatement.value->StringLiteral.value);
            } else {
                int eval_val = eval_expr(node->PrintStatement.value);
                printf("%d\n", eval_val);
            }
            break;

        case IfStatement:
            if (eval_expr(node->IfStatement.test)) {
                eval(node->IfStatement.consequent);
            } else {
                eval(node->IfStatement.alternate);
            }
            break;

        case ForStatement:
            char* id = node->ForStatement.id->Identifier.value;
            int i = node->ForStatement.start->Literal.value;
            bool inST = false;
            if(lookup(id) != -1) {
                inST = true;                
            }
            // if (lookup(id) == -1) {
            //     // printf("hello\n");
            //     i = node->ForStatement.start->Literal.value;
            //     insert(id, "int", i, NULL);
            // } else {
            //     // printf("world");
            //     inST = true;
            //     i = getIntValue(id);
            // }

            insert(id, "int", i, NULL);
            int end = node->ForStatement.end->Literal.value;
            // printf("No way.....%d\t%d\n", i, end);


            for (; i < end; i++) {
                setValue(node->ForStatement.id->Identifier.value, i, NULL);
                eval(node->ForStatement.body);
            }

            if (inST) {
                setValue(id, i, NULL);
            } else {
                symbol_count--;
            }
            // printf("\n%d\n", lookup(node->ForStatement.id->Identifier.value));
            break;

        case BlockStatement:
            eval(node->BlockStatement.body);
            break;

        case Body:
            eval(node->Body.InsideBody);
            eval(node->Body.value);
            break;

        default:
            exit(1);
    };   
};

char* strExpr(ASTNode *node) {
    switch (node->type)
    {
    case Identifier:
        return getStringValue(node->Identifier.value);
        break;
    
    default:
        break;
    }
}

int eval_expr(ASTNode *node) {
    switch (node->type) {
        case Literal:
            return node->Literal.value;
        case Identifier:
            return getIntValue(node->Identifier.value);
        case BinaryExpression:
            int l = eval_expr(node->BinaryExpression.left);
            int r = eval_expr(node->BinaryExpression.right);
            switch (node->BinaryExpression.op) {
                case PLUS:
                    return l + r;
                case MINUS:
                    return l - r;
                case MULTIPLY:
                    return l * r;
                case DIVIDE:
                    return l / r;

                case YUG_EQUAL:
                    return l == r;
                case YUG_NOT_EQUAL:
                    return l != r;
                case YUG_GREATER:
                    return l > r;
                case YUG_GREATER_EQUAL:
                    return l >= r;
                case YUG_LESS:
                    return l < r;
                case YUG_LESS_EQUAL:
                    return l <= r;

                case YUG_AND:
                    return l && r;
                case YUG_OR:
                    return l || r;
                default:
                    exit(1);
            }

        default:
            exit(1);
    };
};

