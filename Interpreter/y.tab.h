
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 39 "parser1.y"

    int value;
    char *id;
    char *str;
    struct ASTNode *node;



/* Line 1676 of yacc.c  */
#line 131 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


