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

    #include<stdio.h>
    #include <stdlib.h>
    #include "code_generator.h"
    #include "../interpreter/interpreter.h"
    #include "../tree/tree.h"
    #include "../array/array.h"
    #include "../helper/helper.h"
    #include <string.h>

    extern int yylex();
    extern int yylineno;
    extern char *yytext; 
    void yyerror(char* s);
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

#line 231 "y.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      44,    45,     2,     2,    43,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    69,    72,    76,   101,   106,   115,   119,
     135,   144,   149,   153,   157,   160,   163,   169,   169,   180,
     183,   188,   188,   202,   202,   218,   226,   229,   234,   237,
     243,   246,   249,   261,   293,   296,   301,   309,   314,   344,
     354,   357,   367,   372,   380,   385,   388,   391,   394,   397,
     400,   403,   406,   409,   412,   415,   418,   421,   426,   432,
     441,   450,   455,   466,   479,   491,   499,   502,   507,   512,
     516,   520,   525,   528,   535,   542,   547,   552,   555,   560,
     567,   575,   579,   584,   587,   590,   593,   596,   599,   602,
     605,   608,   611,   614,   617,   620,   623,   626,   634,   644,
     654,   659,   665,   670,   676,   679
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
  "ENDSTMT", "';'", "','", "'('", "')'", "'{'", "'}'", "'.'", "'='", "'['",
  "']'", "'&'", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "Gid", "MainBlock", "$@1", "FDefBlock", "FDef", "$@2", "$@3",
  "ParamList", "Param", "Type", "LDeclBlock", "LDecList", "LDecl",
  "VarList", "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt",
  "IfStmt", "WhileStmt", "BreakStmt", "ContinueStmt", "DoWhileStmt",
  "RepeatUntilStmt", "FunctionCallStmt", "ReturnStmt", "BreakPointStmt",
  "DimDecl", "Dimlist", "ArgList", "expr", YY_NULLPTR
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
     295,   296,    59,    44,    40,    41,   123,   125,    46,    61,
      91,    93,    38
};
# endif

#define YYPACT_NINF (-174)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    64,   -29,    26,    85,  -174,  -174,  -174,  -174,    32,
     126,  -174,    12,     9,  -174,   -29,  -174,    85,  -174,    30,
      51,  -174,  -174,   -26,    80,    15,  -174,    45,  -174,  -174,
      57,   120,   154,   154,   136,  -174,    98,  -174,    12,  -174,
     154,    99,    42,  -174,    40,    82,    78,   154,  -174,   112,
      93,   154,   154,  -174,  -174,   174,  -174,   141,   132,   179,
    -174,   158,  -174,  -174,  -174,  -174,   130,   175,   168,  -174,
    -174,    60,   151,  -174,   438,   179,   170,   141,   209,    20,
    -174,  -174,     6,   223,   189,   190,    36,    36,   438,   193,
     216,   438,   224,   340,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,   225,   179,  -174,  -174,
    -174,    74,     7,   285,    36,    36,   247,   248,   316,    36,
    -174,   -27,  -174,   317,    36,   318,   484,   506,   458,  -174,
    -174,   369,  -174,    36,  -174,   282,   438,   288,   141,   321,
     287,   159,   528,   281,   222,   125,    36,    36,    46,   147,
      24,   335,  -174,  -174,   173,  -174,    36,    36,    36,    36,
      36,   438,    36,    36,    36,    36,    36,    36,    36,    36,
     438,    36,    36,   230,   293,   340,   438,  -174,  -174,  -174,
      36,   299,    36,  -174,   295,   253,   261,   300,   339,   301,
     312,  -174,   167,  -174,  -174,    65,  -174,  -174,    65,  -174,
     320,   558,   558,   558,   558,   558,   558,   536,   564,   398,
     199,   284,  -174,  -174,   314,   340,   528,  -174,   292,  -174,
    -174,  -174,  -174,   311,   319,  -174,  -174,   438,   322,   323,
    -174,  -174,   313,   325,  -174,   329,  -174,   418,  -174,  -174,
    -174,   315,  -174,   330,  -174,  -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    30,    31,     0,
       0,     8,     0,     0,     1,    30,     3,     0,    20,     0,
       0,     5,     7,    12,     0,     0,    11,     0,     2,    19,
       0,     0,    27,    27,     0,    13,    14,     9,     0,    17,
      27,     0,     0,    26,     0,     0,     0,    27,    10,     0,
       0,    27,     0,    32,    28,     0,    15,    78,     0,    35,
      21,     0,    25,    29,    77,    16,     0,     0,     0,    23,
      34,     0,     0,    37,     0,    35,     0,    40,     0,     0,
      33,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,    35,    42,    44,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   103,   105,     0,     0,     0,     0,     0,     0,    69,
      70,     0,    76,     0,    45,     0,     0,     0,    39,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    43,    74,
       0,     0,     0,    62,    80,     0,     0,     0,     0,     0,
       0,   100,     0,   102,    96,    83,    85,    86,    84,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    75,    18,     0,     0,    81,    73,     0,    79,
      63,    64,    58,     0,     0,    61,   101,     0,     0,     0,
      71,    72,     0,     0,    65,     0,    59,     0,    67,    68,
      22,     0,    60,     0,    24,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  -174,  -174,   353,  -174,   336,     3,  -174,  -174,
     350,  -174,  -174,    90,   331,     5,   -62,  -174,   303,  -174,
     -87,   -93,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -173,  -174,   -52,  -118,   227,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    10,    11,    25,    26,     5,    49,    17,
      18,    68,    76,    42,    43,    44,    67,    72,    73,    79,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   135,   105,    35,   116,   141,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   128,   214,   152,   131,    64,    12,    16,    13,    19,
     120,   121,   122,   106,   123,    12,    23,   150,    33,    24,
      28,   151,    19,   115,    34,   108,    14,   120,   121,   122,
     189,   123,   126,   127,    30,   134,    20,    31,   134,   120,
     121,   122,   233,   123,    54,   137,     1,    55,     2,   175,
     112,   124,   140,    27,   113,   114,   115,    37,    38,   125,
     144,   145,   110,   111,    77,   149,   219,    78,   124,   191,
     154,    71,   157,   158,   200,   160,   125,    71,   138,   173,
     124,   139,   134,   209,    36,    52,   177,    53,   125,   215,
      39,   187,   185,   186,   188,    32,   115,     6,     7,     8,
       9,    40,   195,   196,   197,   198,   199,   134,   201,   202,
     203,   204,   205,   206,   207,   208,   134,   210,   211,    15,
       8,     9,   134,    45,    41,    52,   216,    56,   218,    57,
      50,   156,   157,   158,   159,   160,    52,    58,    60,    46,
     237,    61,    47,    51,   134,   162,   163,   164,   165,   166,
     167,   168,   169,   156,   157,   158,   159,   160,    59,    21,
       7,     8,     9,    70,     7,     8,     9,   162,   163,   164,
     165,   166,   167,   168,   169,    52,   184,    65,    63,   156,
     157,   158,   159,   160,    80,     7,     8,     9,     7,     8,
       9,    34,   190,   162,   163,   164,   165,   166,   167,   168,
     169,    52,   180,    69,   181,   156,   157,   158,   159,   160,
     180,    66,   226,   109,    75,    74,   107,   170,   194,   162,
     163,   164,   165,   166,   167,   168,   169,   117,   156,   157,
     158,   159,   160,   118,   119,   129,   156,   157,   158,   159,
     160,   230,   162,   163,   164,   165,   166,   167,   168,   169,
     162,   163,   164,   165,   166,   167,   168,   169,   130,   156,
     157,   158,   159,   160,   183,   136,   132,   156,   157,   158,
     159,   160,   212,   162,   163,   164,   165,   166,   167,   168,
     169,   162,   163,   164,   165,   166,   167,   168,   169,   143,
     156,   157,   158,   159,   160,   220,   146,   147,   156,   157,
     158,   159,   160,   221,   162,   163,   164,   165,   166,   167,
     168,   169,   162,   163,   164,   165,   166,   167,   168,   169,
     148,   153,   155,   174,    82,   178,   231,    83,   176,   179,
     182,    84,    85,    86,   234,   227,   228,    87,    88,   193,
     213,   217,   222,   223,    82,   115,   224,    83,    89,    90,
      91,    84,    85,    86,   225,   232,   235,    87,    88,    92,
     240,   236,   244,    22,   238,   239,   241,    29,    89,    90,
      91,   242,   245,    82,    48,    81,    83,   192,   133,    92,
      84,    85,    86,    62,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
     172,     0,    82,     0,     0,    83,     0,     0,    92,    84,
      85,    86,     0,     0,     0,    87,    88,   229,     0,     0,
       0,     0,    82,     0,     0,    83,    89,    90,    91,    84,
      85,    86,     0,     0,   243,    87,    88,    92,     0,     0,
       0,     0,    82,     0,     0,    83,    89,    90,    91,    84,
      85,    86,     0,     0,     0,    87,    88,    92,     0,     0,
       0,     0,    82,     0,     0,    83,    89,    90,    91,    84,
      85,    86,     0,     0,     0,   171,    88,    92,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,     0,
     156,   157,   158,   159,   160,     0,     0,    92,   161,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,   170,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   156,   157,   158,   159,   160,     0,
       0,     0,   156,   157,   158,   159,   160,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   162,   163,   164,   165,
     166,   167,     0,   169,   156,   157,   158,   159,   160,     0,
     156,   157,   158,   159,   160,     0,     0,     0,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167
};

static const yytype_int16 yycheck[] =
{
      93,    88,   175,   121,    91,    57,     1,     4,    37,     4,
       3,     4,     5,    75,     7,    10,     4,    44,    44,     7,
      17,    48,    17,    50,    50,    77,     0,     3,     4,     5,
     148,     7,    86,    87,     4,   128,     4,     7,   131,     3,
       4,     5,   215,     7,     4,   107,    32,     7,    34,   136,
      44,    44,    45,    44,    48,    49,    50,    42,    43,    52,
     114,   115,    42,    43,     4,   119,   184,     7,    44,    45,
     124,    66,     7,     8,   161,    10,    52,    72,     4,   133,
      44,     7,   175,   170,     4,    43,   138,    45,    52,   176,
      45,    45,   146,   147,    48,    44,    50,    33,    34,    35,
      36,    44,   156,   157,   158,   159,   160,   200,   162,   163,
     164,   165,   166,   167,   168,   169,   209,   171,   172,    34,
      35,    36,   215,    33,     4,    43,   180,    45,   182,    51,
      40,     6,     7,     8,     9,    10,    43,    47,    45,     3,
     227,    51,    44,    44,   237,    20,    21,    22,    23,    24,
      25,    26,    27,     6,     7,     8,     9,    10,    46,    33,
      34,    35,    36,    33,    34,    35,    36,    20,    21,    22,
      23,    24,    25,    26,    27,    43,    51,    45,     4,     6,
       7,     8,     9,    10,    33,    34,    35,    36,    34,    35,
      36,    50,    45,    20,    21,    22,    23,    24,    25,    26,
      27,    43,    43,    45,    45,     6,     7,     8,     9,    10,
      43,    32,    45,     4,    46,    40,    46,    18,    45,    20,
      21,    22,    23,    24,    25,    26,    27,     4,     6,     7,
       8,     9,    10,    44,    44,    42,     6,     7,     8,     9,
      10,    42,    20,    21,    22,    23,    24,    25,    26,    27,
      20,    21,    22,    23,    24,    25,    26,    27,    42,     6,
       7,     8,     9,    10,    42,    40,    42,     6,     7,     8,
       9,    10,    42,    20,    21,    22,    23,    24,    25,    26,
      27,    20,    21,    22,    23,    24,    25,    26,    27,     4,
       6,     7,     8,     9,    10,    42,    49,    49,     6,     7,
       8,     9,    10,    42,    20,    21,    22,    23,    24,    25,
      26,    27,    20,    21,    22,    23,    24,    25,    26,    27,
       4,     4,     4,    41,     4,     4,    42,     7,    40,    42,
      49,    11,    12,    13,    42,    15,    16,    17,    18,     4,
      47,    42,    42,     4,     4,    50,    45,     7,    28,    29,
      30,    11,    12,    13,    42,    41,    45,    17,    18,    39,
      47,    42,    47,    10,    42,    42,    41,    17,    28,    29,
      30,    42,    42,     4,    38,    72,     7,   150,    38,    39,
      11,    12,    13,    52,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,     4,    -1,    -1,     7,    -1,    -1,    39,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,
      -1,    -1,     4,    -1,    -1,     7,    28,    29,    30,    11,
      12,    13,    -1,    -1,    16,    17,    18,    39,    -1,    -1,
      -1,    -1,     4,    -1,    -1,     7,    28,    29,    30,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    39,    -1,    -1,
      -1,    -1,     4,    -1,    -1,     7,    28,    29,    30,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
       6,     7,     8,     9,    10,    -1,    -1,    39,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,     6,     7,     8,     9,    10,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    20,    21,    22,    23,
      24,    25,    -1,    27,     6,     7,     8,     9,    10,    -1,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,    54,    55,    60,    33,    34,    35,    36,
      56,    57,    68,    37,     0,    34,    60,    62,    63,    68,
       4,    33,    57,     4,     7,    58,    59,    44,    60,    63,
       4,     7,    44,    44,    50,    87,     4,    42,    43,    45,
      44,     4,    66,    67,    68,    66,     3,    44,    59,    61,
      66,    44,    43,    45,     4,     7,    45,    51,    66,    46,
      45,    66,    67,     4,    87,    45,    32,    69,    64,    45,
      33,    68,    70,    71,    40,    46,    65,     4,     7,    72,
      33,    71,     4,     7,    11,    12,    13,    17,    18,    28,
      29,    30,    39,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    86,    69,    46,    87,     4,
      42,    43,    44,    48,    49,    50,    88,     4,    44,    44,
       3,     4,     5,     7,    44,    52,    90,    90,    73,    42,
      42,    73,    42,    38,    74,    85,    40,    69,     4,     7,
      45,    89,    90,     4,    90,    90,    49,    49,     4,    90,
      44,    48,    88,     4,    90,     4,     6,     7,     8,     9,
      10,    14,    20,    21,    22,    23,    24,    25,    26,    27,
      18,    17,    31,    90,    41,    73,    40,    87,     4,    42,
      43,    45,    49,    42,    51,    90,    90,    45,    48,    88,
      45,    45,    89,     4,    45,    90,    90,    90,    90,    90,
      73,    90,    90,    90,    90,    90,    90,    90,    90,    73,
      90,    90,    42,    47,    85,    73,    90,    42,    90,    88,
      42,    42,    42,     4,    45,    42,    45,    15,    16,    19,
      42,    42,    41,    85,    42,    45,    42,    73,    42,    42,
      47,    41,    42,    16,    47,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      58,    58,    59,    59,    59,    59,    59,    61,    60,    62,
      62,    64,    63,    65,    63,    66,    66,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    76,    77,    77,    77,    77,    78,    78,    79,    80,
      81,    82,    83,    84,    84,    85,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     2,     2,     4,     5,     0,    12,     2,
       1,     0,    13,     0,    14,     3,     1,     0,     2,     3,
       1,     1,     5,     3,     2,     0,     2,     1,     3,     3,
       1,     4,     2,     4,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     6,
       7,     5,     4,     5,     5,     6,     8,     6,     6,     2,
       2,     5,     5,     5,     4,     3,     2,     4,     3,     4,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     4,     3,     1,     1,     1
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
#line 66 "main.y"
                                         {
            head = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1751 "y.tab.c"
    break;

  case 3:
#line 69 "main.y"
                              {
            head = (yyvsp[0].node);
        }
#line 1759 "y.tab.c"
    break;

  case 4:
#line 72 "main.y"
                   {
            head = (yyvsp[0].node);
        }
#line 1767 "y.tab.c"
    break;

  case 5:
#line 76 "main.y"
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
#line 1797 "y.tab.c"
    break;

  case 6:
#line 101 "main.y"
                          {
                pushToScopeStack(NULL,&sstop);
                showTable(sstop->symbolTable);
            }
#line 1806 "y.tab.c"
    break;

  case 7:
#line 106 "main.y"
                           {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
            // showTable($$);
        }
#line 1820 "y.tab.c"
    break;

  case 8:
#line 115 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1828 "y.tab.c"
    break;

  case 9:
#line 119 "main.y"
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
#line 1848 "y.tab.c"
    break;

  case 10:
#line 135 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            // Append id to the end of the symbol table
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 1862 "y.tab.c"
    break;

  case 11:
#line 144 "main.y"
              {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1870 "y.tab.c"
    break;

  case 12:
#line 149 "main.y"
        {
        int size = 1;
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->typetable,size,-1,GLOBAL,NULL,NULL,NULL);
    }
#line 1879 "y.tab.c"
    break;

  case 13:
#line 153 "main.y"
                 {
        int size = getArraySize((yyvsp[0].dim));
        (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->typetable,size,-1,GLOBAL,(yyvsp[0].dim),NULL,NULL);
    }
#line 1888 "y.tab.c"
    break;

  case 14:
#line 157 "main.y"
             {
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,createTypeTable(TYPE_PTR,TYPE_NULL,(yyvsp[0].node)->typetable->size,NULL),1,-1,GLOBAL,NULL,NULL,NULL);
    }
#line 1896 "y.tab.c"
    break;

  case 15:
#line 160 "main.y"
                         {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->typetable,1,currentFLabel++,GLOBAL,NULL,(yyvsp[-1].params),NULL);
    }
#line 1904 "y.tab.c"
    break;

  case 16:
#line 163 "main.y"
                             {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->typetable,1,currentFLabel++,GLOBAL,NULL,(yyvsp[-1].params),NULL);
    }
#line 1912 "y.tab.c"
    break;

  case 17:
#line 169 "main.y"
                                 {
            nextBinding = 1;
            printf("main()\n");
            pushToScopeStack(NULL,&sstop);
        }
#line 1922 "y.tab.c"
    break;

  case 18:
#line 173 "main.y"
                                                                {
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),"main",NODETYPE_MAIN,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
            (yyval.node)->Lentry = sstop->symbolTable;
            popFromScopeStack(&sstop);
        }
#line 1932 "y.tab.c"
    break;

  case 19:
#line 180 "main.y"
                          {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1940 "y.tab.c"
    break;

  case 20:
#line 183 "main.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1948 "y.tab.c"
    break;

  case 21:
#line 188 "main.y"
                                {
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
#line 1962 "y.tab.c"
    break;

  case 22:
#line 197 "main.y"
                                                           {
        (yyval.node) = createTree(0,NULL,(yyvsp[-12].typetable),(yyvsp[-11].node)->varname,NODETYPE_FUNC,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 1972 "y.tab.c"
    break;

  case 23:
#line 202 "main.y"
                                    {
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
#line 1986 "y.tab.c"
    break;

  case 24:
#line 211 "main.y"
                                                           {
        (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_PTR,(yyvsp[-13].typetable)->type,1,NULL),(yyvsp[-11].node)->varname,NODETYPE_FUNC,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 1996 "y.tab.c"
    break;

  case 25:
#line 218 "main.y"
                               {
            paramList* curr = (yyvsp[-2].params);
            while(curr->next){
                curr = curr->next;
            }   
            curr->next = (yyvsp[0].params);
            (yyval.params) = (yyvsp[-2].params);
        }
#line 2009 "y.tab.c"
    break;

  case 26:
#line 226 "main.y"
                {
            (yyval.params) = (yyvsp[0].params);
        }
#line 2017 "y.tab.c"
    break;

  case 27:
#line 229 "main.y"
          { 
            (yyval.params) = NULL;
        }
#line 2025 "y.tab.c"
    break;

  case 28:
#line 234 "main.y"
               {
        (yyval.params) = createParamList((yyvsp[-1].typetable),(yyvsp[0].node)->varname);
    }
#line 2033 "y.tab.c"
    break;

  case 29:
#line 237 "main.y"
                  {
        (yyval.params) = createParamList(createTypeTable(TYPE_PTR,(yyvsp[-2].typetable)->type,max((yyvsp[-2].typetable)->size,(yyvsp[0].node)->typetable->size),NULL),(yyvsp[0].node)->varname);
        free((yyvsp[-2].typetable));
    }
#line 2042 "y.tab.c"
    break;

  case 30:
#line 243 "main.y"
                {
        (yyval.typetable) = createTypeTable(TYPE_INT,TYPE_NULL,1,NULL);
    }
#line 2050 "y.tab.c"
    break;

  case 31:
#line 246 "main.y"
               {
        (yyval.typetable) = createTypeTable(TYPE_STR,TYPE_NULL,1,NULL);
    }
#line 2058 "y.tab.c"
    break;

  case 32:
#line 249 "main.y"
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
#line 2073 "y.tab.c"
    break;

  case 33:
#line 261 "main.y"
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
                        }
                        temp = temp->next;
                    }
                }
                curr = curr->next;
            }
            showTable(sstop->symbolTable);
        }
#line 2110 "y.tab.c"
    break;

  case 34:
#line 293 "main.y"
                       {
            // showTable(sstop->symbolTable);
        }
#line 2118 "y.tab.c"
    break;

  case 35:
#line 296 "main.y"
          {
            // showTable(sstop->symbolTable);
        }
#line 2126 "y.tab.c"
    break;

  case 36:
#line 301 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
        }
#line 2139 "y.tab.c"
    break;

  case 37:
#line 309 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 2147 "y.tab.c"
    break;

  case 38:
#line 314 "main.y"
                        {
        SymbolTable* curr = (yyvsp[-1].symbolTable);
        while(curr){
            if(!curr->typetable || curr->typetable->type!=TYPE_PTR){
                curr->typetable = (yyvsp[-2].typetable);
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
                        temp->binding = temp->binding + (size-1);
                        temp = temp->next;
                    }
                }
            }else if(curr->typetable && curr->typetable->type==TYPE_PTR){
                curr->typetable->base = (yyvsp[-2].typetable)->type;
                curr->typetable->size = max(curr->typetable->size,(yyvsp[-2].typetable)->size);
                curr->typetable->field = NULL;
            }
            curr = curr->next;
        }
        (yyval.symbolTable) = (yyvsp[-1].symbolTable);    
    }
#line 2180 "y.tab.c"
    break;

  case 39:
#line 344 "main.y"
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
#line 2195 "y.tab.c"
    break;

  case 40:
#line 354 "main.y"
             {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->typetable,1,-1,LOCAL,NULL,NULL,NULL);
        }
#line 2203 "y.tab.c"
    break;

  case 41:
#line 357 "main.y"
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
#line 2218 "y.tab.c"
    break;

  case 42:
#line 367 "main.y"
                     {
            int size = getArraySize((yyvsp[0].dim));
            (yyvsp[-1].node)->typetable->size = size;
            (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->typetable,size,-1,LOCAL,(yyvsp[0].dim),NULL,NULL);
        }
#line 2228 "y.tab.c"
    break;

  case 43:
#line 372 "main.y"
                             {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            curr->next = createEntry((yyvsp[0].node)->varname,createTypeTable(TYPE_PTR,TYPE_NULL,1,NULL),1,-1,GLOBAL,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2241 "y.tab.c"
    break;

  case 44:
#line 380 "main.y"
                 {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,createTypeTable(TYPE_PTR,TYPE_NULL,1,NULL),1,-1,GLOBAL,NULL,NULL,NULL);
        }
#line 2249 "y.tab.c"
    break;

  case 45:
#line 385 "main.y"
                   {
            (yyval.node) = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 2257 "y.tab.c"
    break;

  case 46:
#line 388 "main.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2263 "y.tab.c"
    break;

  case 47:
#line 391 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2271 "y.tab.c"
    break;

  case 48:
#line 394 "main.y"
                     {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2279 "y.tab.c"
    break;

  case 49:
#line 397 "main.y"
                  {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2287 "y.tab.c"
    break;

  case 50:
#line 400 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2295 "y.tab.c"
    break;

  case 51:
#line 403 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2303 "y.tab.c"
    break;

  case 52:
#line 406 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2311 "y.tab.c"
    break;

  case 53:
#line 409 "main.y"
                       {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2319 "y.tab.c"
    break;

  case 54:
#line 412 "main.y"
                      {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2327 "y.tab.c"
    break;

  case 55:
#line 415 "main.y"
                          {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2335 "y.tab.c"
    break;

  case 56:
#line 418 "main.y"
                           {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2343 "y.tab.c"
    break;

  case 57:
#line 421 "main.y"
                         {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2351 "y.tab.c"
    break;

  case 58:
#line 426 "main.y"
                                {
            SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
            (yyvsp[-2].node)->STentry = st;
            (yyvsp[-2].node)->typetable = st->typetable;
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2362 "y.tab.c"
    break;

  case 59:
#line 432 "main.y"
                                     {
            // Fetch record containing the varname in the symbol table
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyvsp[-3].node)->typetable = st->typetable;
            (yyvsp[-3].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-3].node)->dimNode = (yyvsp[-2].dim);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-3].node),NULL,NULL,NULL); 
        }
#line 2376 "y.tab.c"
    break;

  case 60:
#line 441 "main.y"
                                    {
            // Fetch record containing the varname in the symbol table
            SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
            TypeTable* fieldType = getFieldType(st->typetable->field,(yyvsp[-2].node)->varname);
            tnode* access = createTree(0,NULL,fieldType,(yyvsp[-2].node)->varname,NODETYPE_TUPLE_ACCESS,NULL,NULL,NULL,st);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,access,NULL,NULL,NULL); 
        }
#line 2388 "y.tab.c"
    break;

  case 61:
#line 450 "main.y"
                                    {
           (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2396 "y.tab.c"
    break;

  case 62:
#line 455 "main.y"
                          {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyvsp[-3].node)->typetable = st->typetable;
            if(((yyvsp[-3].node)->typetable->type != (yyvsp[-1].node)->typetable->type)&&((yyvsp[-3].node)->typetable->type!=TYPE_PTR)){
                fprintf(stderr,"Error: Trying to assign %s to %s\n",getType((yyvsp[-1].node)->typetable->type),getType((yyvsp[-3].node)->typetable->type));
                yyerror("");
                exit(1);
            }
            (yyval.node) = createTree(0,"=",st->typetable,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-3].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2412 "y.tab.c"
    break;

  case 63:
#line 466 "main.y"
                                  {
            SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
            (yyvsp[-4].node)->STentry = st;
            (yyvsp[-4].node)->typetable = st->typetable;
            if((yyvsp[-4].node)->typetable->type != (yyvsp[-1].node)->typetable->type){
                fprintf(stderr,"Error: Trying to assign %s to %s\n",getType((yyvsp[-1].node)->typetable->type),getType((yyvsp[-4].node)->typetable->type));
                yyerror("");
                exit(1);
            }
            (yyvsp[-4].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-4].node)->dimNode = (yyvsp[-3].dim);
            (yyval.node) = createTree(0,"=",createTypeTable(TYPE_NULL,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-4].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2430 "y.tab.c"
    break;

  case 64:
#line 479 "main.y"
                              {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyvsp[-3].node)->typetable = st->typetable;
            if((yyvsp[-3].node)->typetable->base != (yyvsp[-1].node)->typetable->type){
                fprintf(stderr,"Error: Trying to assign %s to %s\n",getType((yyvsp[-1].node)->typetable->type),getType((yyvsp[-3].node)->typetable->base));
                yyerror("");
                exit(1);
            }
            tnode* left = createTree(0,"*",st->typetable,NULL,NODETYPE_ACCESS,(yyvsp[-3].node),NULL,NULL,NULL);
            (yyval.node) = createTree(0,"=",st->typetable,NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,(yyvsp[-1].node),NULL);
        }
#line 2447 "y.tab.c"
    break;

  case 65:
#line 491 "main.y"
                                 {
            SymbolTable* st = lookupEntry((yyvsp[-5].node)->varname,sstop);
            TypeTable* fieldType = getFieldType(st->typetable->field,(yyvsp[-3].node)->varname);
            tnode* left = createTree(0,NULL,fieldType,(yyvsp[-3].node)->varname,NODETYPE_TUPLE_ACCESS,NULL,NULL,NULL,st);
            (yyval.node) = createTree(0,"=",fieldType,NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,(yyvsp[-1].node),NULL);
        }
#line 2458 "y.tab.c"
    break;

  case 66:
#line 499 "main.y"
                                                 {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),NULL); 
        }
#line 2466 "y.tab.c"
    break;

  case 67:
#line 502 "main.y"
                                       { 
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-4].node),(yyvsp[-2].node),NULL,NULL);
        }
#line 2474 "y.tab.c"
    break;

  case 68:
#line 507 "main.y"
                                              {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WHILE,(yyvsp[-4].node),NULL,(yyvsp[-2].node),NULL);
          }
#line 2482 "y.tab.c"
    break;

  case 69:
#line 512 "main.y"
                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BREAK,NULL,NULL,NULL,NULL);
          }
#line 2490 "y.tab.c"
    break;

  case 70:
#line 516 "main.y"
                            {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONTINUE,NULL,NULL,NULL,NULL);
             }
#line 2498 "y.tab.c"
    break;

  case 71:
#line 520 "main.y"
                                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_DO_WHILE,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
            }
#line 2506 "y.tab.c"
    break;

  case 72:
#line 525 "main.y"
                                              {
                    (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_REPEAT_UNTIL,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
                }
#line 2514 "y.tab.c"
    break;

  case 73:
#line 528 "main.y"
                                         {
                    SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
                    checkargs((yyvsp[-2].args),st->paramList,(yyvsp[-4].node)->varname);
                    (yyvsp[-4].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-4].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,st);
                    (yyval.node)->argList = (yyvsp[-2].args);
                }
#line 2526 "y.tab.c"
    break;

  case 74:
#line 535 "main.y"
                               {
                    SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
                    checkargs(NULL,st->paramList,(yyvsp[-3].node)->varname);
                    (yyvsp[-3].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
                }
#line 2537 "y.tab.c"
    break;

  case 75:
#line 542 "main.y"
                            {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_RETURN,(yyvsp[-1].node),NULL,NULL,NULL);
        }
#line 2545 "y.tab.c"
    break;

  case 76:
#line 547 "main.y"
                         {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BRKP,NULL,NULL,NULL,NULL);
            }
#line 2553 "y.tab.c"
    break;

  case 77:
#line 552 "main.y"
                             {
                (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
            }
#line 2561 "y.tab.c"
    break;

  case 78:
#line 555 "main.y"
                          {
                (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
            }
#line 2569 "y.tab.c"
    break;

  case 79:
#line 560 "main.y"
                               {
            if((yyvsp[-2].node)->typetable->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
        }
#line 2581 "y.tab.c"
    break;

  case 80:
#line 567 "main.y"
                       {
            if((yyvsp[-1].node)->typetable->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
        }
#line 2593 "y.tab.c"
    break;

  case 81:
#line 575 "main.y"
                          {
            (yyvsp[-2].args)->next = createArgList((yyvsp[0].node));
            (yyval.args) = (yyvsp[-2].args);
        }
#line 2602 "y.tab.c"
    break;

  case 82:
#line 579 "main.y"
               {
            (yyval.args) = createArgList((yyvsp[0].node));
        }
#line 2610 "y.tab.c"
    break;

  case 83:
#line 584 "main.y"
                   {
        (yyval.node) = createTree(0,"+",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2618 "y.tab.c"
    break;

  case 84:
#line 587 "main.y"
                      {
        (yyval.node) = createTree(0,"-",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2626 "y.tab.c"
    break;

  case 85:
#line 590 "main.y"
                    {
        (yyval.node) = createTree(0,"*",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2634 "y.tab.c"
    break;

  case 86:
#line 593 "main.y"
                    {
        (yyval.node) = createTree(0,"/",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2642 "y.tab.c"
    break;

  case 87:
#line 596 "main.y"
                    {
        (yyval.node) = createTree(0,"%",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2650 "y.tab.c"
    break;

  case 88:
#line 599 "main.y"
                   {
        (yyval.node) = createTree(0,"<",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2658 "y.tab.c"
    break;

  case 89:
#line 602 "main.y"
                   {
        (yyval.node) = createTree(0,"<=",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2666 "y.tab.c"
    break;

  case 90:
#line 605 "main.y"
                   {
        (yyval.node) = createTree(0,">",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2674 "y.tab.c"
    break;

  case 91:
#line 608 "main.y"
                   {
        (yyval.node) = createTree(0,">=",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2682 "y.tab.c"
    break;

  case 92:
#line 611 "main.y"
                   {
        (yyval.node) = createTree(0,"!=",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2690 "y.tab.c"
    break;

  case 93:
#line 614 "main.y"
                   {
        (yyval.node) = createTree(0,"==",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2698 "y.tab.c"
    break;

  case 94:
#line 617 "main.y"
                   {
        (yyval.node) = createTree(0,"||",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2706 "y.tab.c"
    break;

  case 95:
#line 620 "main.y"
                    {
        (yyval.node) = createTree(0,"&&",createTypeTable(TYPE_INT,TYPE_NULL,0,NULL),NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2714 "y.tab.c"
    break;

  case 96:
#line 623 "main.y"
                   {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2722 "y.tab.c"
    break;

  case 97:
#line 626 "main.y"
                 {
        SymbolTable* st = lookupEntry((yyvsp[-1].node)->varname,sstop);
        (yyvsp[-1].node)->STentry = st;
        (yyvsp[-1].node)->typetable = st->typetable;
        (yyvsp[-1].node)->nodetype = NODETYPE_ARRAY;
        (yyvsp[-1].node)->dimNode = (yyvsp[0].dim);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2735 "y.tab.c"
    break;

  case 98:
#line 634 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->typetable->type!=TYPE_PTR){
            yyerror("Error: Trying to access non pointer values\n");
            exit(1);
        }
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->typetable = st->typetable;
        (yyval.node) = createTree(0,"*",createTypeTable(st->typetable->base,TYPE_NULL,st->typetable->size,NULL),NULL,NODETYPE_ACCESS,(yyvsp[0].node),NULL,NULL,st);
    }
#line 2750 "y.tab.c"
    break;

  case 99:
#line 644 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->typetable->type==TYPE_PTR){
            fprintf(stderr,"Error: Trying to reference a pointer\n");
            exit(1);
        }
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->typetable = st->typetable;
        (yyval.node) = createTree(0,"&",createTypeTable(TYPE_PTR,(yyvsp[0].node)->typetable->type,st->typetable->size,NULL),NULL,NODETYPE_REF,(yyvsp[0].node),NULL,NULL,st);
    }
#line 2765 "y.tab.c"
    break;

  case 100:
#line 654 "main.y"
               {
        SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
        checkargs(NULL,st->paramList,(yyvsp[-2].node)->varname);
        (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-2].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,st);
    }
#line 2775 "y.tab.c"
    break;

  case 101:
#line 659 "main.y"
                      {
        SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
        checkargs((yyvsp[-1].args),st->paramList,(yyvsp[-3].node)->varname);
        (yyval.node) = createTree(0,NULL,st->typetable,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,st);
        (yyval.node)->argList = (yyvsp[-1].args);
    }
#line 2786 "y.tab.c"
    break;

  case 102:
#line 665 "main.y"
                {
        SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
        TypeTable* fieldType = getFieldType(st->typetable->field,(yyvsp[0].node)->varname);
        (yyval.node) = createTree(0,NULL,fieldType,(yyvsp[0].node)->varname,NODETYPE_TUPLE_ACCESS,NULL,NULL,NULL,st);
    }
#line 2796 "y.tab.c"
    break;

  case 103:
#line 670 "main.y"
         {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->typetable = st->typetable;
        (yyval.node) = (yyvsp[0].node);
    }
#line 2807 "y.tab.c"
    break;

  case 104:
#line 676 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2815 "y.tab.c"
    break;

  case 105:
#line 679 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2823 "y.tab.c"
    break;


#line 2827 "y.tab.c"

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
#line 684 "main.y"


void yyerror(char *s) {
    fprintf(stderr,
        "Syntax error: %s at line %d near '%s'\n",
        s,
        yylloc.first_line,
        yytext
    );
}

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
