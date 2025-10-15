/* A Bison parser, made by GNU Bison 3.5.1.  */

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
    ID = 259,
    STR = 260,
    PLUS = 261,
    MUL = 262,
    DIV = 263,
    MINUS = 264,
    MOD = 265,
    READ = 266,
    WRITE = 267,
    IF = 268,
    THEN = 269,
    ELSE = 270,
    ENDIF = 271,
    WHILE = 272,
    DO = 273,
    ENDWHILE = 274,
    LT = 275,
    LE = 276,
    GT = 277,
    GE = 278,
    NE = 279,
    EQ = 280,
    OR = 281,
    AND = 282,
    BREAK = 283,
    CONTINUE = 284,
    REPEAT = 285,
    UNTIL = 286,
    DECL = 287,
    ENDDECL = 288,
    INT_TYPE = 289,
    STR_TYPE = 290,
    TUPLE_TYPE = 291,
    MAIN = 292,
    RETURN = 293,
    BRKP = 294,
    BEGINSTMT = 295,
    ENDSTMT = 296
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define STR 260
#define PLUS 261
#define MUL 262
#define DIV 263
#define MINUS 264
#define MOD 265
#define READ 266
#define WRITE 267
#define IF 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define WHILE 272
#define DO 273
#define ENDWHILE 274
#define LT 275
#define LE 276
#define GT 277
#define GE 278
#define NE 279
#define EQ 280
#define OR 281
#define AND 282
#define BREAK 283
#define CONTINUE 284
#define REPEAT 285
#define UNTIL 286
#define DECL 287
#define ENDDECL 288
#define INT_TYPE 289
#define STR_TYPE 290
#define TUPLE_TYPE 291
#define MAIN 292
#define RETURN 293
#define BRKP 294
#define BEGINSTMT 295
#define ENDSTMT 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "main.y"

    struct tnode* node;
    struct SymbolTable* symbolTable;
    struct TypeTable* typetable;
    struct dimNode* dim;
    struct paramList* params;
    struct argList* args;

#line 148 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
