/* A Bison parser, made by GNU Bison 3.5.1.  */

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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "main.y"

    
    #include <stdio.h>
    #include <stdlib.h>
    #include "code_generator.h"
    #include "../interpreter/interpreter.h"
    #include "../tree/tree.h"
    #include "../array/array.h"
    #include "../helper/helper.h"
    #include <string.h>

    // extern int yylex();
    // extern int yylineno;
    // extern char *yytext; 
    struct tnode* head = NULL;
    FILE* yyin;

#line 88 "y.tab.c"

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
    ENDSTMT = 296,
    BEGINTYPE = 297,
    ENDTYPE = 298,
    ALLOC = 299,
    FREE = 300,
    INITIALIZE = 301
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
#define BEGINTYPE 297
#define ENDTYPE 298
#define ALLOC 299
#define FREE 300
#define INITIALIZE 301

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
    struct Field* field;

#line 242 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   659

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


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
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      51,    52,     2,     2,    50,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    74,    77,    82,    87,    90,    95,   102,
     107,   132,   138,   146,   151,   157,   182,   187,   196,   200,
     216,   225,   230,   234,   238,   241,   244,   250,   250,   261,
     264,   269,   269,   283,   283,   299,   307,   310,   315,   318,
     324,   327,   330,   340,   350,   377,   380,   385,   393,   398,
     434,   444,   447,   457,   462,   470,   498,   529,   561,   564,
     567,   570,   573,   576,   579,   582,   585,   588,   591,   594,
     597,   600,   603,   606,   611,   617,   633,   638,   643,   654,
     673,   680,   685,   692,   702,   705,   710,   715,   719,   723,
     728,   731,   738,   745,   750,   755,   758,   761,   766,   770,
     773,   778,   784,   791,   795,   800,   803,   806,   809,   812,
     815,   818,   821,   824,   827,   830,   833,   836,   839,   842,
     850,   860,   871,   876,   882,   885,   891,   894
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "STR", "PLUS", "MUL", "DIV",
  "MINUS", "MOD", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE",
  "DO", "ENDWHILE", "LT", "LE", "GT", "GE", "NE", "EQ", "OR", "AND",
  "BREAK", "CONTINUE", "REPEAT", "UNTIL", "DECL", "ENDDECL", "INT_TYPE",
  "STR_TYPE", "TUPLE_TYPE", "MAIN", "RETURN", "BRKP", "BEGINSTMT",
  "ENDSTMT", "BEGINTYPE", "ENDTYPE", "ALLOC", "FREE", "INITIALIZE", "'{'",
  "'}'", "';'", "','", "'('", "')'", "'.'", "'='", "'['", "']'", "'&'",
  "$accept", "Program", "TypeBlock", "TypeList", "TypeDecl",
  "TypeDeclStart", "TypeItemList", "TypeItem", "GDeclBlock", "GDeclList",
  "GDecl", "GidList", "Gid", "MainBlock", "$@1", "FDefBlock", "FDef",
  "$@2", "$@3", "ParamList", "Param", "Type", "LDeclBlock", "LDecList",
  "LDecl", "VarList", "Field", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt", "ContinueStmt",
  "DoWhileStmt", "RepeatUntilStmt", "FunctionCallStmt", "ReturnStmt",
  "BreakPointStmt", "AllocStmt", "FreeStmt", "InitializeStmt", "DimDecl",
  "Dimlist", "ArgList", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   123,   125,    59,
      44,    40,    41,    46,    61,    91,    93,    38
};
# endif

#define YYPACT_NINF (-211)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,     7,    27,    93,  -211,  -211,    14,  -211,   -10,  -211,
     138,     5,    57,  -211,  -211,  -211,   232,  -211,  -211,  -211,
    -211,    49,   148,  -211,    34,    19,     5,  -211,    57,  -211,
      62,    12,  -211,    94,    55,  -211,  -211,   -43,   117,   -29,
    -211,   102,  -211,  -211,   129,   186,  -211,  -211,   153,   232,
     232,   206,  -211,   213,  -211,    34,  -211,   232,   214,  -211,
     125,  -211,    90,   126,   216,   232,  -211,   202,   139,   232,
     232,  -211,  -211,   265,  -211,   215,   176,   249,  -211,   177,
    -211,  -211,  -211,  -211,   152,   242,   237,  -211,  -211,   107,
     199,  -211,   513,   249,   238,   215,   282,   116,  -211,  -211,
     -19,   284,   236,   243,   144,   144,   513,   246,   247,   513,
     270,   269,   271,   272,   108,   403,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,   281,   249,  -211,  -211,  -211,   146,    26,   320,    51,
     144,   279,   280,   322,   144,  -211,    54,  -211,   358,   144,
     360,   310,   560,   582,   533,  -211,  -211,   433,  -211,   273,
     373,   336,   385,    69,   144,  -211,   350,   513,   352,   215,
     389,   348,   192,   604,  -211,   353,   283,   190,   144,   361,
      33,   141,   198,   112,  -211,  -211,   231,  -211,   144,   144,
     144,   144,   144,   513,   144,   144,   144,   144,   144,   144,
     144,   144,   513,   144,   144,   354,   178,   195,   357,  -211,
     366,   291,   321,   370,   403,   513,  -211,  -211,  -211,   144,
     374,   367,  -211,   347,   329,   375,   376,   372,   381,   386,
    -211,   193,  -211,   150,  -211,  -211,   150,  -211,   383,   351,
     351,   351,   351,   351,   351,   612,   634,   463,   253,   359,
    -211,   387,   390,  -211,   382,  -211,  -211,  -211,   368,   403,
     604,  -211,   394,  -211,  -211,   400,  -211,   404,  -211,  -211,
    -211,   513,   405,   406,  -211,  -211,  -211,  -211,   407,   409,
     397,  -211,   410,  -211,   483,  -211,  -211,  -211,  -211,   412,
    -211,   416,  -211,  -211
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,    11,     6,     0,     9,     0,     1,
       0,     0,     0,     4,     5,     8,     0,    43,    16,    40,
      41,     0,     0,    18,     0,     0,    40,     3,     0,    30,
       0,     0,    13,     0,     0,    15,    17,    22,     0,     0,
      21,     0,     2,    29,     0,     0,    10,    12,     0,    37,
      37,     0,    23,    24,    19,     0,    27,    37,     0,    14,
       0,    36,     0,     0,     0,    37,    20,     0,     0,    37,
       0,    42,    38,     0,    25,   100,     0,    46,    31,     0,
      35,    39,    99,    26,     0,     0,     0,    33,    45,     0,
       0,    48,     0,    46,     0,    51,     0,     0,    44,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    46,    53,    55,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   125,   127,     0,     0,
       0,   124,     0,     0,     0,    87,    88,     0,    94,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,    50,
       0,     0,     0,   104,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,    52,    54,    92,     0,
       0,     0,    78,   102,     0,     0,     0,     0,     0,     0,
     122,     0,   118,   105,   107,   108,   106,   109,     0,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
      95,     0,     0,    98,     0,    80,    93,    28,     0,     0,
     103,    91,     0,   101,    79,     0,    74,     0,    76,    77,
     123,     0,     0,     0,    89,    90,    96,    97,     0,     0,
       0,    82,     0,    75,     0,    85,    86,    81,    32,     0,
      83,     0,    34,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,   452,  -211,  -211,   435,  -211,  -211,
     446,  -211,   414,    -2,  -211,  -211,   443,  -211,  -211,     2,
     413,    -3,   -69,  -211,   395,  -211,   -92,  -103,  -114,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -210,
    -211,  -211,  -211,  -211,   -73,  -141,   290,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    31,    32,    12,    22,
      23,    39,    40,    13,    67,    28,    29,    86,    94,    60,
      61,    62,    85,    90,    91,    97,   151,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   166,
     127,   128,   129,   130,    52,   141,   172,   173
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   165,    82,   154,   258,   184,   157,    24,    50,    30,
      27,     4,    51,    33,   114,     1,    17,   114,     4,    24,
      54,    55,   133,   114,   131,    30,    42,     9,    33,   145,
     146,   147,   137,   148,   138,   139,   140,    16,    37,   227,
     165,    38,    25,   165,   152,   153,    19,    20,    21,   280,
       5,   181,    63,    34,   145,   146,   147,    14,   148,    68,
      46,    17,   114,   168,   214,   114,    44,    76,   207,    45,
      41,    79,   145,   146,   147,   114,   148,   149,   171,   176,
     177,    89,   263,   150,   182,   226,   138,    89,   140,   186,
     238,    26,    20,    21,    72,   175,   216,    73,    48,   247,
     165,   114,   149,   211,   212,   183,    49,   138,   150,   140,
     114,    95,   259,   210,    96,   145,   146,   147,   224,   148,
     149,    53,   114,   114,   165,    10,   150,    11,   233,   234,
     235,   236,   237,   165,   239,   240,   241,   242,   243,   244,
     245,   246,    17,   248,   249,   165,   114,   145,   146,   147,
     169,   148,    17,   170,    56,   114,    17,   189,   190,   260,
     192,   162,   163,   149,   230,   135,   136,   114,   284,   150,
     165,    18,    19,    20,    21,    70,    70,    71,    74,   114,
      57,    35,    19,    20,    21,    88,    19,    20,    21,    70,
      58,    78,   114,   228,   162,   149,   188,   189,   190,   191,
     192,   150,    59,    17,   188,   189,   190,   191,   192,    64,
     194,   195,   196,   197,   198,   199,   200,   201,   194,   195,
     196,   197,   198,   199,   200,   201,    70,    70,    83,    87,
     251,   138,    98,    19,    20,    21,    17,   188,   189,   190,
     191,   192,   219,   219,   220,   270,   223,   252,   162,    77,
     229,   194,   195,   196,   197,   198,   199,   200,   201,   188,
     189,   190,   191,   192,    65,    69,    19,    20,    21,    81,
      51,   202,    75,   194,   195,   196,   197,   198,   199,   200,
     201,    84,    92,   232,    93,   132,   134,   143,   142,   188,
     189,   190,   191,   192,   144,   155,   156,   188,   189,   190,
     191,   192,   274,   194,   195,   196,   197,   198,   199,   200,
     201,   194,   195,   196,   197,   198,   199,   200,   201,   158,
     159,   167,   160,   161,   174,   205,   180,   188,   189,   190,
     191,   192,   222,   178,   179,   188,   189,   190,   191,   192,
     255,   194,   195,   196,   197,   198,   199,   200,   201,   194,
     195,   196,   197,   198,   199,   200,   201,   188,   189,   190,
     191,   192,   185,   162,   187,   188,   189,   190,   191,   192,
     256,    -1,    -1,    -1,    -1,    -1,    -1,   206,   264,   194,
     195,   196,   197,   198,   199,   200,   201,   100,   208,   209,
     101,   213,   215,   217,   102,   103,   104,   218,   271,   272,
     105,   106,   140,   250,   221,   225,   253,   100,   275,   279,
     101,   107,   108,   109,   102,   103,   104,   254,   257,   262,
     105,   106,   110,   261,   267,   266,   265,   111,   112,   113,
     268,   107,   108,   109,   278,   269,   276,   100,   289,   277,
     101,   164,   110,   281,   102,   103,   104,   111,   112,   113,
     105,   106,   282,   283,   285,   286,   287,   288,    15,   290,
     292,   107,   108,   109,   204,   293,    47,   100,    36,    66,
     101,    43,   110,   231,   102,   103,   104,   111,   112,   113,
     105,   106,   273,    80,     0,    99,     0,   100,     0,     0,
     101,   107,   108,   109,   102,   103,   104,     0,     0,   291,
     105,   106,   110,     0,     0,     0,     0,   111,   112,   113,
       0,   107,   108,   109,     0,     0,     0,   100,     0,     0,
     101,     0,   110,     0,   102,   103,   104,   111,   112,   113,
     105,   106,     0,     0,     0,     0,     0,   100,     0,     0,
     101,   107,   108,   109,   102,   103,   104,     0,     0,     0,
     203,   106,   110,     0,     0,     0,     0,   111,   112,   113,
       0,   107,   108,   109,     0,     0,   188,   189,   190,   191,
     192,     0,   110,     0,   193,     0,     0,   111,   112,   113,
     194,   195,   196,   197,   198,   199,   200,   201,   188,   189,
     190,   191,   192,     0,     0,     0,     0,     0,     0,     0,
     202,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     188,   189,   190,   191,   192,     0,     0,     0,   188,   189,
     190,   191,   192,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   194,   195,   196,   197,   198,   199,     0,   201,
     188,   189,   190,   191,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   195,   196,   197,   198,   199
};

static const yytype_int16 yycheck[] =
{
      92,   115,    75,   106,   214,   146,   109,    10,    51,    12,
      12,     4,    55,    16,   106,    42,     4,   109,     4,    22,
      49,    50,    95,   115,    93,    28,    28,     0,    31,     3,
       4,     5,    51,     7,    53,    54,    55,    47,     4,   180,
     154,     7,    37,   157,   104,   105,    34,    35,    36,   259,
      43,   143,    50,     4,     3,     4,     5,    43,     7,    57,
      48,     4,   154,   132,   167,   157,     4,    65,   160,     7,
      51,    69,     3,     4,     5,   167,     7,    51,    52,   139,
     140,    84,   223,    57,   144,    52,    53,    90,    55,   149,
     193,    34,    35,    36,     4,    44,   169,     7,     4,   202,
     214,   193,    51,   163,   164,    51,    51,    53,    57,    55,
     202,     4,   215,    44,     7,     3,     4,     5,   178,     7,
      51,     4,   214,   215,   238,    32,    57,    34,   188,   189,
     190,   191,   192,   247,   194,   195,   196,   197,   198,   199,
     200,   201,     4,   203,   204,   259,   238,     3,     4,     5,
       4,     7,     4,     7,    52,   247,     4,     7,     8,   219,
      10,    53,    54,    51,    52,    49,    50,   259,   271,    57,
     284,    33,    34,    35,    36,    50,    50,    52,    52,   271,
      51,    33,    34,    35,    36,    33,    34,    35,    36,    50,
       4,    52,   284,    52,    53,    51,     6,     7,     8,     9,
      10,    57,    49,     4,     6,     7,     8,     9,    10,     3,
      20,    21,    22,    23,    24,    25,    26,    27,    20,    21,
      22,    23,    24,    25,    26,    27,    50,    50,    52,    52,
      52,    53,    33,    34,    35,    36,     4,     6,     7,     8,
       9,    10,    50,    50,    52,    52,    56,    52,    53,    47,
      52,    20,    21,    22,    23,    24,    25,    26,    27,     6,
       7,     8,     9,    10,    51,    51,    34,    35,    36,     4,
      55,    18,    56,    20,    21,    22,    23,    24,    25,    26,
      27,    32,    40,    52,    47,    47,     4,    51,     4,     6,
       7,     8,     9,    10,    51,    49,    49,     6,     7,     8,
       9,    10,    49,    20,    21,    22,    23,    24,    25,    26,
      27,    20,    21,    22,    23,    24,    25,    26,    27,    49,
      51,    40,    51,    51,     4,    52,     4,     6,     7,     8,
       9,    10,    49,    54,    54,     6,     7,     8,     9,    10,
      49,    20,    21,    22,    23,    24,    25,    26,    27,    20,
      21,    22,    23,    24,    25,    26,    27,     6,     7,     8,
       9,    10,     4,    53,     4,     6,     7,     8,     9,    10,
      49,    20,    21,    22,    23,    24,    25,     4,    49,    20,
      21,    22,    23,    24,    25,    26,    27,     4,    52,     4,
       7,    41,    40,     4,    11,    12,    13,    49,    15,    16,
      17,    18,    55,    49,    51,    44,    49,     4,    49,    41,
       7,    28,    29,    30,    11,    12,    13,    51,    48,    52,
      17,    18,    39,    49,    52,    49,    51,    44,    45,    46,
      49,    28,    29,    30,    52,    49,    49,     4,    41,    49,
       7,    38,    39,    49,    11,    12,    13,    44,    45,    46,
      17,    18,    52,    49,    49,    49,    49,    48,     6,    49,
      48,    28,    29,    30,    31,    49,    31,     4,    22,    55,
       7,    28,    39,   183,    11,    12,    13,    44,    45,    46,
      17,    18,    19,    70,    -1,    90,    -1,     4,    -1,    -1,
       7,    28,    29,    30,    11,    12,    13,    -1,    -1,    16,
      17,    18,    39,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    28,    29,    30,    -1,    -1,    -1,     4,    -1,    -1,
       7,    -1,    39,    -1,    11,    12,    13,    44,    45,    46,
      17,    18,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
       7,    28,    29,    30,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    39,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    28,    29,    30,    -1,    -1,     6,     7,     8,     9,
      10,    -1,    39,    -1,    14,    -1,    -1,    44,    45,    46,
      20,    21,    22,    23,    24,    25,    26,    27,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
       6,     7,     8,     9,    10,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    20,    21,    22,    23,    24,    25,    -1,    27,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    59,    60,     4,    43,    61,    62,    63,     0,
      32,    34,    66,    71,    43,    62,    47,     4,    33,    34,
      35,    36,    67,    68,    79,    37,    34,    71,    73,    74,
      79,    64,    65,    79,     4,    33,    68,     4,     7,    69,
      70,    51,    71,    74,     4,     7,    48,    65,     4,    51,
      51,    55,   102,     4,    49,    50,    52,    51,     4,    49,
      77,    78,    79,    77,     3,    51,    70,    72,    77,    51,
      50,    52,     4,     7,    52,    56,    77,    47,    52,    77,
      78,     4,   102,    52,    32,    80,    75,    52,    33,    79,
      81,    82,    40,    47,    76,     4,     7,    83,    33,    82,
       4,     7,    11,    12,    13,    17,    18,    28,    29,    30,
      39,    44,    45,    46,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    98,    99,   100,
     101,    80,    47,   102,     4,    49,    50,    51,    53,    54,
      55,   103,     4,    51,    51,     3,     4,     5,     7,    51,
      57,    84,   105,   105,    85,    49,    49,    85,    49,    51,
      51,    51,    53,    54,    38,    86,    97,    40,    80,     4,
       7,    52,   104,   105,     4,    44,   105,   105,    54,    54,
       4,    84,   105,    51,   103,     4,   105,     4,     6,     7,
       8,     9,    10,    14,    20,    21,    22,    23,    24,    25,
      26,    27,    18,    17,    31,    52,     4,    84,    52,     4,
      44,   105,   105,    41,    85,    40,   102,     4,    49,    50,
      52,    51,    49,    56,   105,    44,    52,   103,    52,    52,
      52,   104,    52,   105,   105,   105,   105,   105,    85,   105,
     105,   105,   105,   105,   105,   105,   105,    85,   105,   105,
      49,    52,    52,    49,    51,    49,    49,    48,    97,    85,
     105,    49,    52,   103,    49,    51,    49,    52,    49,    49,
      52,    15,    16,    19,    49,    49,    49,    49,    52,    41,
      97,    49,    52,    49,    85,    49,    49,    49,    48,    41,
      49,    16,    48,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    60,    60,    60,    61,    61,
      62,    63,    64,    64,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    70,    70,    70,    70,    72,    71,    73,
      73,    75,    74,    76,    74,    77,    77,    77,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    81,    81,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    88,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    92,    93,    94,
      95,    96,    96,    97,    98,    99,   100,   100,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     0,     2,     1,
       4,     1,     2,     1,     3,     3,     2,     2,     1,     3,
       3,     1,     1,     2,     2,     4,     5,     0,    12,     2,
       1,     0,    13,     0,    14,     3,     1,     0,     2,     3,
       1,     1,     5,     1,     3,     2,     0,     2,     1,     3,
       3,     1,     4,     2,     4,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     6,     5,     5,     4,     5,
       4,     6,     6,     7,     8,     6,     6,     2,     2,     5,
       5,     5,     4,     3,     2,     4,     5,     5,     4,     4,
       3,     4,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     4,     1,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 71 "main.y"
                                                   {
            head = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1803 "y.tab.c"
    break;

  case 3:
#line 74 "main.y"
                                        {
            head = (yyvsp[0].node);
        }
#line 1811 "y.tab.c"
    break;

  case 4:
#line 77 "main.y"
                             {
            head = (yyvsp[0].node);
        }
#line 1819 "y.tab.c"
    break;

  case 5:
#line 82 "main.y"
                                      {
            // custom_types = $2;
            printf("User Defined Types:\n");
            printCustomTypesTable();
        }
#line 1829 "y.tab.c"
    break;

  case 6:
#line 87 "main.y"
                            {
            custom_types = NULL;
        }
#line 1837 "y.tab.c"
    break;

  case 7:
#line 90 "main.y"
          {
            custom_types = NULL;
        }
#line 1845 "y.tab.c"
    break;

  case 8:
#line 95 "main.y"
                            {
            TypeTable* curr = (yyvsp[-1].typetable);
            while(curr && curr->next){
                curr = curr->next;
            }
            (yyval.typetable) = (yyvsp[-1].typetable);
        }
#line 1857 "y.tab.c"
    break;

  case 9:
#line 102 "main.y"
                   {
            (yyval.typetable) = (yyvsp[0].typetable);
        }
#line 1865 "y.tab.c"
    break;

  case 10:
#line 107 "main.y"
                                              {
        (yyval.typetable) = (yyvsp[-3].typetable);
        (yyval.typetable)->field = (yyvsp[-1].field);
        Field* f = (yyvsp[-1].field);
        int size = 0;
        while(f){
            f->offset = size;
            // printf("%s:%d\n",f->name,f->offset);
            size++;
            f = f->next;
        }
        if(size>8){
            yyerror("Maximum member fields limit (8) exceeded for type %s",(yyvsp[-3].typetable)->name);
        }
        f = (yyvsp[-1].field);
        while(f){
            if(f->typetable->name && strcmp(f->typetable->name,(yyval.typetable)->name)==0){
                f->typetable->size = size;
            }
            f = f->next;
        }
        (yyval.typetable)->size = size;
    }
#line 1893 "y.tab.c"
    break;

  case 11:
#line 132 "main.y"
                  {
        (yyval.typetable) = appendToCustomTypes(createTypeTable(TYPE_USR_DEF, TYPE_NULL, 0, NULL));
        (yyval.typetable)->name = strdup((yyvsp[0].node)->varname);
    }
#line 1902 "y.tab.c"
    break;

  case 12:
#line 138 "main.y"
                                    {
        Field* curr = (yyvsp[-1].field);
        while(curr->next){
            curr = curr->next;
        }
        curr->next = (yyvsp[0].field);
        (yyval.field) = (yyvsp[-1].field);
    }
#line 1915 "y.tab.c"
    break;

  case 13:
#line 146 "main.y"
               {
        (yyval.field) = (yyvsp[0].field);
    }
#line 1923 "y.tab.c"
    break;

  case 14:
#line 151 "main.y"
                      {
        (yyval.field) = createField((yyvsp[-2].typetable),(yyvsp[-1].node)->varname);
    }
#line 1931 "y.tab.c"
    break;

  case 15:
#line 157 "main.y"
                                   {
                pushToScopeStack((yyvsp[-1].symbolTable),&sstop);
                SymbolTable* curr = (yyvsp[-1].symbolTable);
                while(curr){
                    if(curr->typetable->field){
                        int size = 0;
                        Field* f = curr->typetable->field;
                        while(f){
                            size++;
                            f = f->next;
                        }
                        curr->size = size;
                        SymbolTable* temp = curr->next;
                        while(temp){
                            if(temp->flabel==-1){
                                temp->binding = temp->binding + (size-1);
                                initialStackTop = max(initialStackTop,temp->binding+temp->size-1);
                            }
                            temp = temp->next;
                        }
                    }
                    curr = curr->next;
                }
                showTable((yyvsp[-1].symbolTable));
            }
#line 1961 "y.tab.c"
    break;

  case 16:
#line 182 "main.y"
                          {
                pushToScopeStack(NULL,&sstop);
                showTable(sstop->symbolTable);
            }
#line 1970 "y.tab.c"
    break;

  case 17:
#line 187 "main.y"
                           {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
            // showTable($$);
        }
#line 1984 "y.tab.c"
    break;

  case 18:
#line 196 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1992 "y.tab.c"
    break;

  case 19:
#line 200 "main.y"
                       {
        SymbolTable* curr = (yyvsp[-1].symbolTable);
        
        while(curr){
            if(!curr->typetable->type || curr->typetable->type!=TYPE_PTR){
                curr->typetable = (yyvsp[-2].typetable);
            }else if(curr->typetable->type && curr->typetable->type==TYPE_PTR){
                curr->typetable->base = (yyvsp[-2].typetable)->type;
                curr->typetable->size = max(curr->typetable->size,(yyvsp[-2].typetable)->size);
                curr->typetable->field = NULL;
            }
            curr = curr->next;
        }
        (yyval.symbolTable) = (yyvsp[-1].symbolTable);
    }
#line 2012 "y.tab.c"
    break;

  case 20:
#line 216 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            // Append id to the end of the symbol table
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 2026 "y.tab.c"
    break;

  case 21:
#line 225 "main.y"
              {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 2034 "y.tab.c"
    break;

  case 22:
#line 230 "main.y"
        {
        int size = 1;
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->typetable,size,-1,GLOBAL,NULL,NULL,NULL);
    }
#line 2043 "y.tab.c"
    break;

  case 23:
#line 234 "main.y"
                 {
        int size = getArraySize((yyvsp[0].dim));
        (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->typetable,size,-1,GLOBAL,(yyvsp[0].dim),NULL,NULL);
    }
#line 2052 "y.tab.c"
    break;

  case 24:
#line 238 "main.y"
             {
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,createTypeTable(TYPE_PTR,TYPE_NULL,(yyvsp[0].node)->typetable->size,NULL),1,-1,GLOBAL,NULL,NULL,NULL);
    }
#line 2060 "y.tab.c"
    break;

  case 25:
#line 241 "main.y"
                         {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->typetable,1,currentFLabel++,GLOBAL,NULL,(yyvsp[-1].params),NULL);
    }
#line 2068 "y.tab.c"
    break;

  case 26:
#line 244 "main.y"
                             {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->typetable,1,currentFLabel++,GLOBAL,NULL,(yyvsp[-1].params),NULL);
    }
#line 2076 "y.tab.c"
    break;

  case 27:
#line 250 "main.y"
                                 {
            nextBinding = 1;
            printf("main()\n");
            pushToScopeStack(NULL,&sstop);
        }
#line 2086 "y.tab.c"
    break;

  case 28:
#line 254 "main.y"
                                                                {
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),"main",NODETYPE_MAIN,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
            (yyval.node)->Lentry = sstop->symbolTable;
            popFromScopeStack(&sstop);
        }
#line 2096 "y.tab.c"
    break;

  case 29:
#line 261 "main.y"
                          {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 2104 "y.tab.c"
    break;

  case 30:
#line 264 "main.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2112 "y.tab.c"
    break;

  case 31:
#line 269 "main.y"
                                {
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
#line 2126 "y.tab.c"
    break;

  case 32:
#line 278 "main.y"
                                                           {
        (yyval.node) = createTree(0,NULL,(yyvsp[-12].typetable),(yyvsp[-11].node)->varname,NODETYPE_FUNC,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 2136 "y.tab.c"
    break;

  case 33:
#line 283 "main.y"
                                    {
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
#line 2150 "y.tab.c"
    break;

  case 34:
#line 292 "main.y"
                                                           {
        (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_PTR,(yyvsp[-13].typetable)->type,1,NULL),(yyvsp[-11].node)->varname,NODETYPE_FUNC,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 2160 "y.tab.c"
    break;

  case 35:
#line 299 "main.y"
                               {
            paramList* curr = (yyvsp[-2].params);
            while(curr->next){
                curr = curr->next;
            }   
            curr->next = (yyvsp[0].params);
            (yyval.params) = (yyvsp[-2].params);
        }
#line 2173 "y.tab.c"
    break;

  case 36:
#line 307 "main.y"
                {
            (yyval.params) = (yyvsp[0].params);
        }
#line 2181 "y.tab.c"
    break;

  case 37:
#line 310 "main.y"
          { 
            (yyval.params) = NULL;
        }
#line 2189 "y.tab.c"
    break;

  case 38:
#line 315 "main.y"
               {
        (yyval.params) = createParamList((yyvsp[-1].typetable),(yyvsp[0].node)->varname);
    }
#line 2197 "y.tab.c"
    break;

  case 39:
#line 318 "main.y"
                  {
        (yyval.params) = createParamList(createTypeTable(TYPE_PTR,(yyvsp[-2].typetable)->type,max((yyvsp[-2].typetable)->size,(yyvsp[0].node)->typetable->size),NULL),(yyvsp[0].node)->varname);
        free((yyvsp[-2].typetable));
    }
#line 2206 "y.tab.c"
    break;

  case 40:
#line 324 "main.y"
                {
        (yyval.typetable) = createTypeTable(TYPE_INT,TYPE_NULL,1,NULL);
    }
#line 2214 "y.tab.c"
    break;

  case 41:
#line 327 "main.y"
               {
        (yyval.typetable) = createTypeTable(TYPE_STR,TYPE_NULL,1,NULL);
    }
#line 2222 "y.tab.c"
    break;

  case 42:
#line 330 "main.y"
                                      {
        int size = 0;
        Field* f = convertToField((yyvsp[-1].params));
        Field* curr = f;
        while(curr){
            size++;
            curr = curr->next;
        }
        (yyval.typetable) = createTypeTable(TYPE_TUPLE,TYPE_NULL,size,f);
    }
#line 2237 "y.tab.c"
    break;

  case 43:
#line 340 "main.y"
         {
        TypeTable* typetable = searchForUserDefinedType((yyvsp[0].node)->varname);
        if(!typetable){
            yyerror("Custom type not found");
        }
        (yyval.typetable) = createTypeTable(TYPE_USR_DEF,TYPE_NULL,typetable->size,typetable->field);
        (yyval.typetable)->name = strdup((yyvsp[0].node)->varname);
    }
#line 2250 "y.tab.c"
    break;

  case 44:
#line 350 "main.y"
                                  {
            if(!sstop->symbolTable){
                sstop->symbolTable = (yyvsp[-1].symbolTable);
            }else{
                SymbolTable* curr = sstop->symbolTable;
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = (yyvsp[-1].symbolTable);
            }
            // SymbolTable* curr = $2;
            // while(curr){
            //     if(curr->typetable->field){
            //         if(curr->size=)
            //         curr->size = 1;
            //         // SymbolTable* temp = curr->next;
            //         // while(temp){
            //         //     // if(temp->flabel==-1){
            //         //     //     temp->binding = temp->binding ;
            //         //     // }
            //         //     temp = temp->next;
            //         // }
            //     }
            //     curr = curr->next;
            // }
            showTable(sstop->symbolTable);
        }
#line 2282 "y.tab.c"
    break;

  case 45:
#line 377 "main.y"
                       {
            // showTable(sstop->symbolTable);
        }
#line 2290 "y.tab.c"
    break;

  case 46:
#line 380 "main.y"
          {
            // showTable(sstop->symbolTable);
        }
#line 2298 "y.tab.c"
    break;

  case 47:
#line 385 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
        }
#line 2311 "y.tab.c"
    break;

  case 48:
#line 393 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 2319 "y.tab.c"
    break;

  case 49:
#line 398 "main.y"
                        {
        SymbolTable* curr = (yyvsp[-1].symbolTable);
        while(curr){
            if(!curr->typetable || curr->typetable->type!=TYPE_PTR){
                curr->typetable = (yyvsp[-2].typetable);
                // if user defined variable
                if(curr->typetable->field){
                    // int size = 0;
                    // Field* f = curr->typetable->field;
                    // get size of field
                    // while(f){
                    //     size++;
                    //     f = f->next;
                    // }                    
                    if(curr->size==1){
                        curr->size = 1;
                    }

                    // SymbolTable* temp = curr->next;
                    // while(temp){
                    //     temp->binding = temp->binding + (size-1);
                    //     temp = temp->next;
                    // }
                }
                // printf("\n");
            }else if(curr->typetable && curr->typetable->type==TYPE_PTR){
                curr->typetable->base = (yyvsp[-2].typetable)->type;
                curr->typetable->size = max(curr->typetable->size,(yyvsp[-2].typetable)->size);
                curr->typetable->field = NULL;
            }
            curr = curr->next;
        }
        (yyval.symbolTable) = (yyvsp[-1].symbolTable);    
    }
#line 2358 "y.tab.c"
    break;

  case 50:
#line 434 "main.y"
                         {
            // Get symbol table pointer for varlist
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            // Append entry to the end of the symbol table
            curr->next = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->typetable,1,-1,LOCAL,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 2373 "y.tab.c"
    break;

  case 51:
#line 444 "main.y"
             {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->typetable,1,-1,LOCAL,NULL,NULL,NULL);
        }
#line 2381 "y.tab.c"
    break;

  case 52:
#line 447 "main.y"
                                 {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            int size = getArraySize((yyvsp[0].dim));
            (yyvsp[-1].node)->typetable->size = size;
            curr->next = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->typetable,size,-1,LOCAL,(yyvsp[0].dim),NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2396 "y.tab.c"
    break;

  case 53:
#line 457 "main.y"
                     {
            int size = getArraySize((yyvsp[0].dim));
            (yyvsp[-1].node)->typetable->size = size;
            (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->typetable,size,-1,LOCAL,(yyvsp[0].dim),NULL,NULL);
        }
#line 2406 "y.tab.c"
    break;

  case 54:
#line 462 "main.y"
                             {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            curr->next = createEntry((yyvsp[0].node)->varname,createTypeTable(TYPE_PTR,TYPE_NULL,1,NULL),1,-1,GLOBAL,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2419 "y.tab.c"
    break;

  case 55:
#line 470 "main.y"
                 {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,createTypeTable(TYPE_PTR,TYPE_NULL,1,NULL),1,-1,GLOBAL,NULL,NULL,NULL);
        }
#line 2427 "y.tab.c"
    break;

  case 56:
#line 498 "main.y"
                    {
        if((yyvsp[-2].node)->typetable->type!=TYPE_USR_DEF && (yyvsp[-2].node)->typetable->type!=TYPE_TUPLE)
        {
            yyerror("Can't access variables field: %s",(yyvsp[0].node)->varname);
        }

        char* typeName = (yyvsp[-2].node)->typetable->name;
        if (typeName == NULL) {
            yyerror("Type has no name.");
        }

        TypeTable* masterType = searchForUserDefinedType(typeName);
        if (!masterType) {
             yyerror("Type %s not found.", typeName);
        }

        if (masterType->field == NULL) {
            yyerror("Type %s has no fields but was accessed.", masterType->name);
        }

        int offset = 0;
        Field* curr = masterType->field;
        while(curr)
        {
            curr->offset = offset++;
            curr = curr->next;
        }
        Field *currField = getFieldFromType(masterType, (yyvsp[0].node)->varname);

        (yyval.node) = createTree(currField->offset,".",currField->typetable,NULL,NODETYPE_FIELD_ACCESS,(yyvsp[-2].node),NULL,(yyvsp[0].node),(yyvsp[-2].node)->STentry);
    }
#line 2463 "y.tab.c"
    break;

  case 57:
#line 529 "main.y"
                {
        SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
        if(st->typetable->type!=TYPE_USR_DEF && st->typetable->type!=TYPE_TUPLE)
        {
            yyerror("Can't access variables field: %s",(yyvsp[0].node)->varname);
        }

        TypeTable* baseType = st->typetable;

        TypeTable* masterType = searchForUserDefinedType(baseType->name);
        if (!masterType) {
             yyerror("Type %s not found.", baseType->name);
        }

        if (masterType->field == NULL) {
            yyerror("Type %s has no fields.", masterType->name);
        }

        int offset = 0;
        Field* curr = masterType->field;
        while(curr)
        {
            curr->offset = offset++;
            curr = curr->next;
        }

        Field *field = getFieldFromType(masterType, (yyvsp[0].node)->varname);
        
        (yyval.node) = createTree(field->offset,".",field->typetable,NULL,NODETYPE_FIELD_ACCESS,(yyvsp[-2].node),NULL,(yyvsp[0].node),st);
    }
#line 2498 "y.tab.c"
    break;

  case 58:
#line 561 "main.y"
                   {
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 2506 "y.tab.c"
    break;

  case 59:
#line 564 "main.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2512 "y.tab.c"
    break;

  case 60:
#line 567 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2520 "y.tab.c"
    break;

  case 61:
#line 570 "main.y"
                     {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2528 "y.tab.c"
    break;

  case 62:
#line 573 "main.y"
                  {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2536 "y.tab.c"
    break;

  case 63:
#line 576 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2544 "y.tab.c"
    break;

  case 64:
#line 579 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2552 "y.tab.c"
    break;

  case 65:
#line 582 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2560 "y.tab.c"
    break;

  case 66:
#line 585 "main.y"
                       {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2568 "y.tab.c"
    break;

  case 67:
#line 588 "main.y"
                      {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2576 "y.tab.c"
    break;

  case 68:
#line 591 "main.y"
                          {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2584 "y.tab.c"
    break;

  case 69:
#line 594 "main.y"
                           {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2592 "y.tab.c"
    break;

  case 70:
#line 597 "main.y"
                         {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2600 "y.tab.c"
    break;

  case 71:
#line 600 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2608 "y.tab.c"
    break;

  case 72:
#line 603 "main.y"
                   {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2616 "y.tab.c"
    break;

  case 73:
#line 606 "main.y"
                         {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2624 "y.tab.c"
    break;

  case 74:
#line 611 "main.y"
                                {
            SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
            (yyvsp[-2].node)->STentry = st;
            (yyvsp[-2].node)->typetable = st->typetable;
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2635 "y.tab.c"
    break;

  case 75:
#line 617 "main.y"
                                     {
            // Fetch record containing the varname in the symbol table
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyvsp[-3].node)->typetable = st->typetable;
            (yyvsp[-3].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-3].node)->dimNode = (yyvsp[-2].dim);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-3].node),NULL,NULL,NULL); 
        }
#line 2649 "y.tab.c"
    break;

  case 76:
#line 633 "main.y"
                                 {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-2].node),NULL,NULL,NULL);
        }
#line 2657 "y.tab.c"
    break;

  case 77:
#line 638 "main.y"
                                    {
           (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2665 "y.tab.c"
    break;

  case 78:
#line 643 "main.y"
                          {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyvsp[-3].node)->typetable = st->typetable;
            if(((yyvsp[-3].node)->typetable->type != (yyvsp[-1].node)->typetable->type)&&((yyvsp[-3].node)->typetable->type!=TYPE_PTR)){
                // fprintf(stderr,"Trying to assign %s to %s\n",getType($3->typetable->type),getType($1->typetable->type));
                yyerror("Trying to assign %s to %s\n",getType((yyvsp[-1].node)->typetable->type),getType((yyvsp[-3].node)->typetable->type));
                // exit(1);
            }
            (yyval.node) = createTree(0,"=",st->typetable,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-3].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2681 "y.tab.c"
    break;

  case 79:
#line 654 "main.y"
                                  {
            SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
            (yyvsp[-4].node)->STentry = st;
            (yyvsp[-4].node)->typetable = st->typetable;
            if((yyvsp[-4].node)->typetable->type != (yyvsp[-1].node)->typetable->type){
                // fprintf(stderr,"Trying to assign %s to %s\n",getType($4->typetable->type),getType($1->typetable->type));
                yyerror("Trying to assign %s to %s\n",getType((yyvsp[-1].node)->typetable->type),getType((yyvsp[-4].node)->typetable->type));
                // exit(1);
            }
            (yyvsp[-4].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-4].node)->dimNode = (yyvsp[-3].dim);
            (yyval.node) = createTree(0,"=",createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-4].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2699 "y.tab.c"
    break;

  case 80:
#line 673 "main.y"
                             {
            TypeTable* fieldType = (yyvsp[-3].node)->typetable;
            if(fieldType->type!=(yyvsp[-1].node)->typetable->type){
                yyerror("Assignment of wrong type to field: %s to %s",getType((yyvsp[-1].node)->typetable->type),getType(fieldType->type));
            }
            (yyval.node) = createTree(0,"=",fieldType,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-3].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2711 "y.tab.c"
    break;

  case 81:
#line 680 "main.y"
                                      {
            TypeTable* fieldType = (yyvsp[-5].node)->typetable;
            tnode* right = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_ALLOC,NULL,NULL,NULL,NULL);
            (yyval.node) = createTree(0,"=",fieldType,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-5].node),NULL,right,NULL);
        }
#line 2721 "y.tab.c"
    break;

  case 82:
#line 685 "main.y"
                                  {
            SymbolTable* st = lookupEntry((yyvsp[-5].node)->varname,sstop);
            (yyvsp[-5].node)->STentry = st;
            (yyvsp[-5].node)->typetable = st->typetable;
            tnode* right = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_ALLOC,NULL,NULL,NULL,NULL);
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-5].node),NULL,right,NULL);
        }
#line 2733 "y.tab.c"
    break;

  case 83:
#line 692 "main.y"
                                      {
            SymbolTable* st = lookupEntry((yyvsp[-5].node)->varname,sstop);
            (yyvsp[-5].node)->STentry = st;
            (yyvsp[-5].node)->typetable = st->typetable;
            tnode* left = createTree(0,"*",st->typetable,NULL,NODETYPE_ACCESS,(yyvsp[-5].node),NULL,NULL,NULL);
            tnode* right = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_ALLOC,NULL,NULL,NULL,NULL);
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,right,NULL);
        }
#line 2746 "y.tab.c"
    break;

  case 84:
#line 702 "main.y"
                                                 {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),NULL); 
        }
#line 2754 "y.tab.c"
    break;

  case 85:
#line 705 "main.y"
                                       { 
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-4].node),(yyvsp[-2].node),NULL,NULL);
        }
#line 2762 "y.tab.c"
    break;

  case 86:
#line 710 "main.y"
                                              {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WHILE,(yyvsp[-4].node),NULL,(yyvsp[-2].node),NULL);
          }
#line 2770 "y.tab.c"
    break;

  case 87:
#line 715 "main.y"
                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BREAK,NULL,NULL,NULL,NULL);
          }
#line 2778 "y.tab.c"
    break;

  case 88:
#line 719 "main.y"
                            {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONTINUE,NULL,NULL,NULL,NULL);
             }
#line 2786 "y.tab.c"
    break;

  case 89:
#line 723 "main.y"
                                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_DO_WHILE,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
            }
#line 2794 "y.tab.c"
    break;

  case 90:
#line 728 "main.y"
                                              {
                    (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_REPEAT_UNTIL,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
                }
#line 2802 "y.tab.c"
    break;

  case 91:
#line 731 "main.y"
                                         {
                    SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
                    checkargs((yyvsp[-2].args),st->paramList,(yyvsp[-4].node)->varname);
                    (yyvsp[-4].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-4].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,st);
                    (yyval.node)->argList = (yyvsp[-2].args);
                }
#line 2814 "y.tab.c"
    break;

  case 92:
#line 738 "main.y"
                               {
                    SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
                    checkargs(NULL,st->paramList,(yyvsp[-3].node)->varname);
                    (yyvsp[-3].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
                }
#line 2825 "y.tab.c"
    break;

  case 93:
#line 745 "main.y"
                            {
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_RETURN,(yyvsp[-1].node),NULL,NULL,NULL);
        }
#line 2833 "y.tab.c"
    break;

  case 94:
#line 750 "main.y"
                         {
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_BRKP,NULL,NULL,NULL,NULL);
            }
#line 2841 "y.tab.c"
    break;

  case 95:
#line 755 "main.y"
                             {
    (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_ALLOC,NULL,NULL,NULL,NULL);
}
#line 2849 "y.tab.c"
    break;

  case 96:
#line 758 "main.y"
                              {
        (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_FREE,(yyvsp[-2].node),NULL,NULL,NULL);
    }
#line 2857 "y.tab.c"
    break;

  case 97:
#line 761 "main.y"
                             {
        (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_FREE,(yyvsp[-2].node),NULL,NULL,NULL);
    }
#line 2865 "y.tab.c"
    break;

  case 98:
#line 766 "main.y"
                                       {
                (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_INITIALIZE,NULL,NULL,NULL,NULL);
            }
#line 2873 "y.tab.c"
    break;

  case 99:
#line 770 "main.y"
                             {
                (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
            }
#line 2881 "y.tab.c"
    break;

  case 100:
#line 773 "main.y"
                          {
                (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
            }
#line 2889 "y.tab.c"
    break;

  case 101:
#line 778 "main.y"
                               {
            if((yyvsp[-2].node)->typetable->type == TYPE_STR){
                yyerror("int type is required for indexing");
            }
            (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
        }
#line 2900 "y.tab.c"
    break;

  case 102:
#line 784 "main.y"
                       {
            if((yyvsp[-1].node)->typetable->type == TYPE_STR){
                yyerror("int type is required for indexing");
            }
            (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
        }
#line 2911 "y.tab.c"
    break;

  case 103:
#line 791 "main.y"
                          {
            (yyvsp[-2].args)->next = createArgList((yyvsp[0].node));
            (yyval.args) = (yyvsp[-2].args);
        }
#line 2920 "y.tab.c"
    break;

  case 104:
#line 795 "main.y"
               {
            (yyval.args) = createArgList((yyvsp[0].node));
        }
#line 2928 "y.tab.c"
    break;

  case 105:
#line 800 "main.y"
                   {
        (yyval.node) = createTree(0,"+",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2936 "y.tab.c"
    break;

  case 106:
#line 803 "main.y"
                      {
        (yyval.node) = createTree(0,"-",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2944 "y.tab.c"
    break;

  case 107:
#line 806 "main.y"
                    {
        (yyval.node) = createTree(0,"*",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2952 "y.tab.c"
    break;

  case 108:
#line 809 "main.y"
                    {
        (yyval.node) = createTree(0,"/",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2960 "y.tab.c"
    break;

  case 109:
#line 812 "main.y"
                    {
        (yyval.node) = createTree(0,"%",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2968 "y.tab.c"
    break;

  case 110:
#line 815 "main.y"
                   {
        (yyval.node) = createTree(0,"<",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2976 "y.tab.c"
    break;

  case 111:
#line 818 "main.y"
                   {
        (yyval.node) = createTree(0,"<=",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2984 "y.tab.c"
    break;

  case 112:
#line 821 "main.y"
                   {
        (yyval.node) = createTree(0,">",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2992 "y.tab.c"
    break;

  case 113:
#line 824 "main.y"
                   {
        (yyval.node) = createTree(0,">=",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 3000 "y.tab.c"
    break;

  case 114:
#line 827 "main.y"
                   {
        (yyval.node) = createTree(0,"!=",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 3008 "y.tab.c"
    break;

  case 115:
#line 830 "main.y"
                   {
        (yyval.node) = createTree(0,"==",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 3016 "y.tab.c"
    break;

  case 116:
#line 833 "main.y"
                   {
        (yyval.node) = createTree(0,"||",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 3024 "y.tab.c"
    break;

  case 117:
#line 836 "main.y"
                    {
        (yyval.node) = createTree(0,"&&",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 3032 "y.tab.c"
    break;

  case 118:
#line 839 "main.y"
                   {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3040 "y.tab.c"
    break;

  case 119:
#line 842 "main.y"
                 {
        SymbolTable* st = lookupEntry((yyvsp[-1].node)->varname,sstop);
        (yyvsp[-1].node)->STentry = st;
        (yyvsp[-1].node)->typetable = st->typetable;
        (yyvsp[-1].node)->nodetype = NODETYPE_ARRAY;
        (yyvsp[-1].node)->dimNode = (yyvsp[0].dim);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3053 "y.tab.c"
    break;

  case 120:
#line 850 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->typetable->type!=TYPE_PTR){
            yyerror("Trying to access non pointer values");
            exit(1);
        }
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->typetable = st->typetable;
        (yyval.node) = createTree(0,"*",createTypeTable(st->typetable->base,TYPE_NULL,st->typetable->size,NULL),NULL,NODETYPE_ACCESS,(yyvsp[0].node),NULL,NULL,st);
    }
#line 3068 "y.tab.c"
    break;

  case 121:
#line 860 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->typetable->type==TYPE_PTR){
            // fprintf(stderr,"Trying to reference a pointer\n");
            // exit(1);
            yyerror("Trying to reference a pointer");
        }
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->typetable = st->typetable;
        (yyval.node) = createTree(0,"&",createTypeTable(TYPE_PTR,(yyvsp[0].node)->typetable->type,st->typetable->size,NULL),NULL,NODETYPE_REF,(yyvsp[0].node),NULL,NULL,st);
    }
#line 3084 "y.tab.c"
    break;

  case 122:
#line 871 "main.y"
               {
        SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
        checkargs(NULL,st->paramList,(yyvsp[-2].node)->varname);
        (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-2].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,st);
    }
#line 3094 "y.tab.c"
    break;

  case 123:
#line 876 "main.y"
                      {
        SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
        checkargs((yyvsp[-1].args),st->paramList,(yyvsp[-3].node)->varname);
        (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,st);
        (yyval.node)->argList = (yyvsp[-1].args);
    }
#line 3105 "y.tab.c"
    break;

  case 124:
#line 882 "main.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3113 "y.tab.c"
    break;

  case 125:
#line 885 "main.y"
         {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->typetable = st->typetable;
        (yyval.node) = (yyvsp[0].node);
    }
#line 3124 "y.tab.c"
    break;

  case 126:
#line 891 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3132 "y.tab.c"
    break;

  case 127:
#line 894 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3140 "y.tab.c"
    break;


#line 3144 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 899 "main.y"


void code_generate(){
    codegen_generate_header();
    stack_top = initialStackTop;
    codegen_initialize_stack(initialStackTop);
    fprintf(target_file,"MOV BP, 4095\n");
    fprintf(target_file,"JMP L_EXIT\n");
    codegen(head,-1,-1);
    fprintf(target_file,"L_EXIT:");
    fprintf(target_file,"CALL F0\n");
    codegen_call_exit();
}

void free_memory(){
    freeTree(head);
}

int main(){
    yyin = fopen("../input.expl", "r");
    yyparse();
    printTree(head);
    target_file = fopen("../target_file.xsm","w");
    code_generate();
    /* free_memory(); */
    return 0;
}
