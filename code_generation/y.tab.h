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
    READ = 265,
    WRITE = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    ENDIF = 270,
    WHILE = 271,
    DO = 272,
    ENDWHILE = 273,
    LT = 274,
    LE = 275,
    GT = 276,
    GE = 277,
    NE = 278,
    EQ = 279,
    BREAK = 280,
    CONTINUE = 281,
    REPEAT = 282,
    UNTIL = 283,
    DECL = 284,
    ENDDECL = 285,
    INT_TYPE = 286,
    STR_TYPE = 287
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
#define READ 265
#define WRITE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define WHILE 271
#define DO 272
#define ENDWHILE 273
#define LT 274
#define LE 275
#define GT 276
#define GE 277
#define NE 278
#define EQ 279
#define BREAK 280
#define CONTINUE 281
#define REPEAT 282
#define UNTIL 283
#define DECL 284
#define ENDDECL 285
#define INT_TYPE 286
#define STR_TYPE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "main.y"

    struct tnode* node;
    struct Gsymbol* gsymbol;
    int var_type;

#line 127 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
