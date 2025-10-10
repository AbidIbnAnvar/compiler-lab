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
    MAIN = 291,
    RETURN = 292
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
#define MAIN 291
#define RETURN 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "main.y"

    struct tnode* node;
    struct SymbolTable* symbolTable;
    int var_type;
    struct dimNode* dim;
    struct paramList* params;
    struct argList* args;

#line 223 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,     2,    47,     2,
      40,    41,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    67,    70,    74,    78,    83,    91,    95,
     109,   118,   123,   126,   130,   133,   139,   139,   150,   154,
     160,   160,   175,   183,   186,   191,   196,   199,   204,   216,
     221,   229,   234,   249,   259,   262,   272,   276,   284,   289,
     292,   295,   298,   301,   304,   307,   310,   313,   316,   319,
     322,   327,   331,   340,   345,   350,   358,   366,   369,   374,
     379,   383,   387,   392,   395,   402,   409,   413,   416,   421,
     428,   436,   440,   445,   448,   451,   454,   457,   460,   463,
     466,   469,   472,   475,   478,   481,   484,   487,   495,   504,
     514,   520,   527,   533,   536
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
  "STR_TYPE", "MAIN", "RETURN", "';'", "','", "'('", "')'", "'{'", "'}'",
  "'='", "'['", "']'", "'&'", "$accept", "Program", "GDeclBlock",
  "GDeclList", "GDecl", "GidList", "Gid", "MainBlock", "$@1", "FDefBlock",
  "FDef", "$@2", "ParamList", "Param", "Type", "LDeclBlock", "LDecList",
  "LDecl", "VarList", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt", "ContinueStmt",
  "DoWhileStmt", "RepeatUntilStmt", "FunctionCallStmt", "ReturnStmt",
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
     285,   286,   287,   288,   289,   290,   291,   292,    59,    44,
      40,    41,   123,   125,    61,    91,    93,    38
};
# endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     113,    30,     7,     4,   -24,   -95,   -95,   -95,   -95,    42,
     -95,    40,    14,   -95,     7,   -95,   -24,   -95,    57,   -95,
     -95,   -20,    65,   -21,   -95,    32,   -95,   -95,    45,    63,
      91,   -95,   -95,   -95,    40,   -95,    63,   105,   -95,   119,
      94,   -95,    99,   116,    63,   -95,   -95,   103,   124,   -95,
     -95,   -95,    67,   426,   130,   -95,    48,    82,   -95,   -32,
     177,   155,   158,    19,    19,   426,   150,   161,   426,   179,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   124,   103,   189,   -10,   -95,   -95,    27,    19,    19,
     156,   157,   198,    19,   -95,    -3,   -95,   199,    19,   200,
     459,   481,   446,   -95,   -95,   338,    19,   -95,   162,   426,
     -95,   -95,   -95,    49,   168,   143,   503,   226,   112,    19,
      19,    -6,   144,   102,   -95,   -95,   153,   -95,    19,    19,
      19,    19,    19,   426,    19,    19,    19,    19,    19,    19,
      19,    19,   426,    19,    19,   248,   -95,   179,   103,   211,
     -95,    19,   180,   -95,   172,   270,   292,   181,   182,   183,
     -95,   148,   -95,    41,   -95,   -95,    41,   -95,   366,   104,
     104,   104,   104,   104,   104,   511,   533,   386,   204,   314,
     -95,   194,   -95,   -95,   503,   -95,   -95,   -95,   -95,   -95,
     201,   -95,   -95,   426,   202,   203,   -95,   -95,   -95,   -95,
     406,   -95,   -95,   205,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    26,    27,     0,
       8,     0,     0,     1,    26,     3,     0,    19,     0,     5,
       7,    12,     0,     0,    11,     0,     2,    18,     0,    24,
       0,    13,    14,     9,     0,    16,    24,     0,    23,     0,
       0,    10,     0,     0,     0,    15,    25,    68,     0,    20,
      22,    67,     0,     0,     0,    29,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    34,     0,     0,    28,    30,     0,     0,     0,
       0,     0,     0,     0,    93,    92,    94,     0,     0,     0,
       0,     0,     0,    60,    61,     0,     0,    39,     0,     0,
      36,    38,    32,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,    87,    88,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,    33,     0,
      65,     0,     0,    54,    70,     0,     0,     0,     0,     0,
      90,     0,    86,    73,    75,    76,    74,    77,     0,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
      66,     0,    35,    37,    71,    64,    69,    55,    56,    51,
       0,    53,    91,     0,     0,     0,    62,    63,    21,    52,
       0,    58,    59,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,   229,   -95,   186,     3,   -95,   -95,
     228,   -95,   209,   215,     5,   184,   -95,   206,   -95,   -63,
     -69,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   114,   -44,   -94,   137,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    23,    24,     5,    42,    16,
      17,    54,    37,    38,    39,    53,    57,    58,    84,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   108,    31,    90,   115,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   124,   102,    51,    13,   105,    11,    15,    87,    18,
      14,     8,    88,    89,    11,   100,   101,    33,    34,    26,
      29,    18,    94,    95,    96,    30,    97,   158,   112,   113,
      94,    95,    96,   107,    97,   157,   107,   123,   110,    89,
     117,   118,    89,    12,    21,   122,   147,    22,   129,   130,
     126,   132,    82,   148,    25,    83,   149,    56,   145,    98,
     186,    28,    56,     6,     7,     8,    99,    98,   114,    32,
     168,   155,   156,    35,    99,    19,     7,     8,   107,   177,
     163,   164,   165,   166,   167,    36,   169,   170,   171,   172,
     173,   174,   175,   176,    40,   178,   179,     7,     8,   107,
      55,     7,     8,   184,   182,    94,    95,    96,   107,    97,
     128,   129,   130,   131,   132,    85,     7,     8,   128,   129,
     130,   131,   132,    46,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   107,   134,   135,   136,   137,   138,   139,   140,   141,
      47,    48,    98,   160,    44,     1,    45,     2,    30,    99,
     128,   129,   130,   131,   132,    44,    52,    49,   154,   128,
     129,   130,   131,   132,   134,   135,   136,   137,   138,   139,
     140,   141,    81,   134,   135,   136,   137,   138,   139,   140,
     141,    91,   151,    59,   152,   159,    60,   151,   103,   192,
      61,    62,    63,   111,   162,    92,    64,    65,    93,   104,
     119,   120,   121,   125,   127,   146,   150,    66,    67,    68,
     128,   129,   130,   131,   132,   183,   106,    89,   185,   189,
      41,   191,   142,   190,   134,   135,   136,   137,   138,   139,
     140,   141,   128,   129,   130,   131,   132,   198,    20,   199,
     201,   202,   196,   204,    27,    43,   134,   135,   136,   137,
     138,   139,   140,   141,   128,   129,   130,   131,   132,    50,
     161,   181,     0,    86,   153,   109,     0,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,   180,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
     188,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,    59,     0,     0,    60,     0,     0,     0,    61,
      62,    63,   197,     0,     0,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,   144,
      59,     0,     0,    60,     0,     0,     0,    61,    62,    63,
       0,   193,   194,    64,    65,     0,     0,     0,     0,     0,
      59,     0,     0,    60,    66,    67,    68,    61,    62,    63,
       0,     0,     0,    64,    65,   195,     0,     0,     0,     0,
      59,     0,     0,    60,    66,    67,    68,    61,    62,    63,
       0,     0,   203,    64,    65,     0,     0,     0,     0,     0,
      59,     0,     0,    60,    66,    67,    68,    61,    62,    63,
       0,     0,     0,    64,    65,     0,     0,     0,     0,     0,
      59,     0,     0,    60,    66,    67,    68,    61,    62,    63,
       0,     0,     0,   143,    65,   128,   129,   130,   131,   132,
       0,     0,     0,   133,    66,    67,    68,     0,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,   142,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   128,
     129,   130,   131,   132,     0,     0,     0,   128,   129,   130,
     131,   132,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   134,   135,   136,   137,   138,   139,     0,   141,   128,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139
};

static const yytype_int16 yycheck[] =
{
      69,    95,    65,    47,     0,    68,     1,     4,    40,     4,
      34,    35,    44,    45,     9,    63,    64,    38,    39,    16,
      40,    16,     3,     4,     5,    45,     7,   121,    38,    39,
       3,     4,     5,   102,     7,    41,   105,    40,    82,    45,
      88,    89,    45,    36,     4,    93,   109,     7,     7,     8,
      98,    10,     4,     4,    40,     7,     7,    52,   106,    40,
     154,     4,    57,    33,    34,    35,    47,    40,    41,     4,
     133,   119,   120,    41,    47,    33,    34,    35,   147,   142,
     128,   129,   130,   131,   132,    40,   134,   135,   136,   137,
     138,   139,   140,   141,     3,   143,   144,    34,    35,   168,
      33,    34,    35,   151,   148,     3,     4,     5,   177,     7,
       6,     7,     8,     9,    10,    33,    34,    35,     6,     7,
       8,     9,    10,     4,    20,    21,    22,    23,    24,    25,
     193,   200,    20,    21,    22,    23,    24,    25,    26,    27,
      46,    42,    40,    41,    39,    32,    41,    34,    45,    47,
       6,     7,     8,     9,    10,    39,    32,    41,    46,     6,
       7,     8,     9,    10,    20,    21,    22,    23,    24,    25,
      26,    27,    42,    20,    21,    22,    23,    24,    25,    26,
      27,     4,    39,     4,    41,    41,     7,    39,    38,    41,
      11,    12,    13,     4,    41,    40,    17,    18,    40,    38,
      44,    44,     4,     4,     4,    43,    38,    28,    29,    30,
       6,     7,     8,     9,    10,     4,    37,    45,    38,    38,
      34,    38,    18,    41,    20,    21,    22,    23,    24,    25,
      26,    27,     6,     7,     8,     9,    10,    43,     9,    38,
      38,    38,    38,    38,    16,    36,    20,    21,    22,    23,
      24,    25,    26,    27,     6,     7,     8,     9,    10,    44,
     123,   147,    -1,    57,    38,    81,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,     4,    -1,    -1,     7,    -1,    -1,    -1,    11,
      12,    13,    38,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
       4,    -1,    -1,     7,    -1,    -1,    -1,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,     7,    28,    29,    30,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
       4,    -1,    -1,     7,    28,    29,    30,    11,    12,    13,
      -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,     7,    28,    29,    30,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,     7,    28,    29,    30,    11,    12,    13,
      -1,    -1,    -1,    17,    18,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    28,    29,    30,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,     6,
       7,     8,     9,    10,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    20,    21,    22,    23,    24,    25,    -1,    27,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,    49,    50,    55,    33,    34,    35,    51,
      52,    62,    36,     0,    34,    55,    57,    58,    62,    33,
      52,     4,     7,    53,    54,    40,    55,    58,     4,    40,
      45,    80,     4,    38,    39,    41,    40,    60,    61,    62,
       3,    54,    56,    60,    39,    41,     4,    46,    42,    41,
      61,    80,    32,    63,    59,    33,    62,    64,    65,     4,
       7,    11,    12,    13,    17,    18,    28,    29,    30,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    42,     4,     7,    66,    33,    65,    40,    44,    45,
      81,     4,    40,    40,     3,     4,     5,     7,    40,    47,
      83,    83,    67,    38,    38,    67,    37,    68,    79,    63,
      80,     4,    38,    39,    41,    82,    83,    83,    83,    44,
      44,     4,    83,    40,    81,     4,    83,     4,     6,     7,
       8,     9,    10,    14,    20,    21,    22,    23,    24,    25,
      26,    27,    18,    17,    31,    83,    43,    67,     4,     7,
      38,    39,    41,    38,    46,    83,    83,    41,    81,    41,
      41,    82,    41,    83,    83,    83,    83,    83,    67,    83,
      83,    83,    83,    83,    83,    83,    83,    67,    83,    83,
      38,    79,    80,     4,    83,    38,    81,    38,    38,    38,
      41,    38,    41,    15,    16,    19,    38,    38,    43,    38,
      67,    38,    38,    16,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    56,    55,    57,    57,
      59,    58,    60,    60,    60,    61,    62,    62,    63,    63,
      64,    64,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    70,    71,    71,    71,    72,    72,    73,
      74,    75,    76,    77,    78,    78,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     2,     2,     4,     0,    10,     2,     1,
       0,    11,     3,     1,     0,     2,     1,     1,     3,     2,
       2,     1,     3,     3,     1,     4,     2,     4,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     6,     5,     4,     5,     5,     8,     6,     6,
       2,     2,     5,     5,     5,     4,     3,     4,     3,     4,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     4,     1,     1,     1
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
#line 64 "main.y"
                                         {
            head = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1720 "y.tab.c"
    break;

  case 3:
#line 67 "main.y"
                              {
            head = (yyvsp[0].node);
        }
#line 1728 "y.tab.c"
    break;

  case 4:
#line 70 "main.y"
                   {
            head = (yyvsp[0].node);
        }
#line 1736 "y.tab.c"
    break;

  case 5:
#line 74 "main.y"
                                   {
                pushToScopeStack((yyvsp[-1].symbolTable),&sstop);
                showTable((yyvsp[-1].symbolTable));
            }
#line 1745 "y.tab.c"
    break;

  case 6:
#line 78 "main.y"
                          {
                pushToScopeStack(NULL,&sstop);
                showTable(sstop->symbolTable);
            }
#line 1754 "y.tab.c"
    break;

  case 7:
#line 83 "main.y"
                           {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
        }
#line 1767 "y.tab.c"
    break;

  case 8:
#line 91 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1775 "y.tab.c"
    break;

  case 9:
#line 95 "main.y"
                       {
        SymbolTable* curr = (yyvsp[-1].symbolTable);
        while(curr){
            // set type to all except ptr variables
            if(!curr->type || curr->type!=TYPE_PTR){
                curr->type = (yyvsp[-2].var_type);
            }else if(curr->type && curr->type==TYPE_PTR){
                curr->vartype = (yyvsp[-2].var_type);
            }
            curr = curr->next;
        }
        (yyval.symbolTable) = (yyvsp[-1].symbolTable);
    }
#line 1793 "y.tab.c"
    break;

  case 10:
#line 109 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }
            // Append id to the end of the symbol table
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 1807 "y.tab.c"
    break;

  case 11:
#line 118 "main.y"
              {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1815 "y.tab.c"
    break;

  case 12:
#line 123 "main.y"
        {
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,NULL,NULL,NULL);
    }
#line 1823 "y.tab.c"
    break;

  case 13:
#line 126 "main.y"
                 {
        int size = getArraySize((yyvsp[0].dim));
        (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->type,size,(yyvsp[0].dim),NULL,NULL);
    }
#line 1832 "y.tab.c"
    break;

  case 14:
#line 130 "main.y"
             {
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,TYPE_PTR,1,NULL,NULL,NULL);
    }
#line 1840 "y.tab.c"
    break;

  case 15:
#line 133 "main.y"
                         {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->type,1,NULL,(yyvsp[-1].params),NULL);
        (yyval.symbolTable)->flabel = currentFLabel++;
    }
#line 1849 "y.tab.c"
    break;

  case 16:
#line 139 "main.y"
                                 {
            nextBinding = 0;
            printf("main()\n");
            pushToScopeStack(NULL,&sstop);
        }
#line 1859 "y.tab.c"
    break;

  case 17:
#line 143 "main.y"
                                              {
            (yyval.node) = createTree(0,NULL,TYPE_INT,"main",NODETYPE_MAIN,NULL,NULL,(yyvsp[-2].node),NULL);
            (yyval.node)->Lentry = sstop->symbolTable;
            popFromScopeStack(&sstop);
        }
#line 1869 "y.tab.c"
    break;

  case 18:
#line 150 "main.y"
                          {
            // TODO: Check if the declared function and defined function types and parameters are same
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1878 "y.tab.c"
    break;

  case 19:
#line 154 "main.y"
               {
            // TODO: Check if the declared function and defined function types and parameters are same
            (yyval.node) = (yyvsp[0].node);
        }
#line 1887 "y.tab.c"
    break;

  case 20:
#line 160 "main.y"
                                {
            nextBinding = 0;
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            printParamList((yyvsp[-1].params));
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
    }
#line 1901 "y.tab.c"
    break;

  case 21:
#line 169 "main.y"
                                         {
        (yyval.node) = createTree(0,NULL,TYPE_NULL,(yyvsp[-9].node)->varname,NODETYPE_FUNC,NULL,(yyvsp[-2].node),(yyvsp[-1].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 1911 "y.tab.c"
    break;

  case 22:
#line 175 "main.y"
                               {
            paramList* curr = (yyvsp[-2].params);
            while(curr->next){
                curr = curr->next;
            }   
            curr->next = (yyvsp[0].params);
            (yyval.params) = (yyvsp[-2].params);
        }
#line 1924 "y.tab.c"
    break;

  case 23:
#line 183 "main.y"
                {
            (yyval.params) = (yyvsp[0].params);
        }
#line 1932 "y.tab.c"
    break;

  case 24:
#line 186 "main.y"
          { 
            (yyval.params) = NULL;
        }
#line 1940 "y.tab.c"
    break;

  case 25:
#line 191 "main.y"
               {
        (yyval.params) = createParamList((yyvsp[-1].var_type),(yyvsp[0].node)->varname);
    }
#line 1948 "y.tab.c"
    break;

  case 26:
#line 196 "main.y"
                {
        (yyval.var_type) = TYPE_INT;
    }
#line 1956 "y.tab.c"
    break;

  case 27:
#line 199 "main.y"
               {
        (yyval.var_type) = TYPE_STR;
    }
#line 1964 "y.tab.c"
    break;

  case 28:
#line 204 "main.y"
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
            showTable(sstop->symbolTable);
        }
#line 1981 "y.tab.c"
    break;

  case 29:
#line 216 "main.y"
                       {
            showTable(sstop->symbolTable);
        }
#line 1989 "y.tab.c"
    break;

  case 30:
#line 221 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
        }
#line 2002 "y.tab.c"
    break;

  case 31:
#line 229 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 2010 "y.tab.c"
    break;

  case 32:
#line 234 "main.y"
                        {
        SymbolTable* curr = (yyvsp[-1].symbolTable);
        while(curr){
            // set type to all except ptr variables
            if(!curr->type || curr->type!=TYPE_PTR){
                curr->type = (yyvsp[-2].var_type);
            }else if(curr->type && curr->type==TYPE_PTR){
                curr->vartype = (yyvsp[-2].var_type);
            }
            curr = curr->next;
        }
        (yyval.symbolTable) = (yyvsp[-1].symbolTable);    
    }
#line 2028 "y.tab.c"
    break;

  case 33:
#line 249 "main.y"
                         {
            // Get symbol table pointer for varlist
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            // Append entry to the end of the symbol table
            curr->next = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 2043 "y.tab.c"
    break;

  case 34:
#line 259 "main.y"
             {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,NULL,NULL,NULL);
        }
#line 2051 "y.tab.c"
    break;

  case 35:
#line 262 "main.y"
                                 {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }

            int size = getArraySize((yyvsp[0].dim));
            curr->next = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->type,size,(yyvsp[0].dim),NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2066 "y.tab.c"
    break;

  case 36:
#line 272 "main.y"
                     {
            int size = getArraySize((yyvsp[0].dim));
            (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->type,size,(yyvsp[0].dim),NULL,NULL);
        }
#line 2075 "y.tab.c"
    break;

  case 37:
#line 276 "main.y"
                             {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            curr->next = createEntry((yyvsp[0].node)->varname,TYPE_PTR,1,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2088 "y.tab.c"
    break;

  case 38:
#line 284 "main.y"
                 {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,TYPE_PTR,1,NULL,NULL,NULL);
        }
#line 2096 "y.tab.c"
    break;

  case 39:
#line 289 "main.y"
                   {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 2104 "y.tab.c"
    break;

  case 40:
#line 292 "main.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2110 "y.tab.c"
    break;

  case 41:
#line 295 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2118 "y.tab.c"
    break;

  case 42:
#line 298 "main.y"
                     {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2126 "y.tab.c"
    break;

  case 43:
#line 301 "main.y"
                  {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2134 "y.tab.c"
    break;

  case 44:
#line 304 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2142 "y.tab.c"
    break;

  case 45:
#line 307 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2150 "y.tab.c"
    break;

  case 46:
#line 310 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2158 "y.tab.c"
    break;

  case 47:
#line 313 "main.y"
                       {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2166 "y.tab.c"
    break;

  case 48:
#line 316 "main.y"
                      {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2174 "y.tab.c"
    break;

  case 49:
#line 319 "main.y"
                          {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2182 "y.tab.c"
    break;

  case 50:
#line 322 "main.y"
                           {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2190 "y.tab.c"
    break;

  case 51:
#line 327 "main.y"
                                {
            (yyvsp[-2].node)->STentry = lookupEntry((yyvsp[-2].node)->varname,sstop);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2199 "y.tab.c"
    break;

  case 52:
#line 331 "main.y"
                                     {
            // Fetch record containing the varname in the symbol table
            (yyvsp[-3].node)->STentry = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-3].node)->dimNode = (yyvsp[-2].dim);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-3].node),NULL,NULL,NULL); 
        }
#line 2211 "y.tab.c"
    break;

  case 53:
#line 340 "main.y"
                                    {
           (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2219 "y.tab.c"
    break;

  case 54:
#line 345 "main.y"
                          {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyval.node) = createTree(0,"=",st->type,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-3].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2229 "y.tab.c"
    break;

  case 55:
#line 350 "main.y"
                                  {
            SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
            (yyvsp[-4].node)->STentry = st;
            (yyvsp[-4].node)->type = st->type;
            (yyvsp[-4].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-4].node)->dimNode = (yyvsp[-3].dim);
            (yyval.node) = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-4].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2242 "y.tab.c"
    break;

  case 56:
#line 358 "main.y"
                              {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            tnode* left = createTree(0,"*",st->type,NULL,NODETYPE_ACCESS,(yyvsp[-3].node),NULL,NULL,NULL);
            (yyval.node) = createTree(0,"=",st->type,NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,(yyvsp[-1].node),NULL);
        }
#line 2253 "y.tab.c"
    break;

  case 57:
#line 366 "main.y"
                                                 {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),NULL); 
        }
#line 2261 "y.tab.c"
    break;

  case 58:
#line 369 "main.y"
                                       { 
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-4].node),(yyvsp[-2].node),NULL,NULL);
        }
#line 2269 "y.tab.c"
    break;

  case 59:
#line 374 "main.y"
                                              {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WHILE,(yyvsp[-4].node),NULL,(yyvsp[-2].node),NULL);
          }
#line 2277 "y.tab.c"
    break;

  case 60:
#line 379 "main.y"
                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BREAK,NULL,NULL,NULL,NULL);
          }
#line 2285 "y.tab.c"
    break;

  case 61:
#line 383 "main.y"
                            {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONTINUE,NULL,NULL,NULL,NULL);
             }
#line 2293 "y.tab.c"
    break;

  case 62:
#line 387 "main.y"
                                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_DO_WHILE,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
            }
#line 2301 "y.tab.c"
    break;

  case 63:
#line 392 "main.y"
                                              {
                    (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_REPEAT_UNTIL,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
                }
#line 2309 "y.tab.c"
    break;

  case 64:
#line 395 "main.y"
                                         {
                    SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
                    checkargs((yyvsp[-2].args),st->paramList,(yyvsp[-4].node)->varname);
                    (yyvsp[-4].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-4].node)->varname,NODETYPE_FUNC,NULL,NULL,NULL,NULL);
                    (yyval.node)->argList = (yyvsp[-2].args);
                }
#line 2321 "y.tab.c"
    break;

  case 65:
#line 402 "main.y"
                               {
                    SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
                    checkargs(NULL,st->paramList,(yyvsp[-3].node)->varname);
                    (yyvsp[-3].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-3].node)->varname,NODETYPE_FUNC,NULL,NULL,NULL,NULL);
                }
#line 2332 "y.tab.c"
    break;

  case 66:
#line 409 "main.y"
                            {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_RETURN,NULL,NULL,(yyvsp[-1].node),NULL);
        }
#line 2340 "y.tab.c"
    break;

  case 67:
#line 413 "main.y"
                             {
                (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
            }
#line 2348 "y.tab.c"
    break;

  case 68:
#line 416 "main.y"
                          {
                (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
            }
#line 2356 "y.tab.c"
    break;

  case 69:
#line 421 "main.y"
                               {
            if((yyvsp[-2].node)->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
        }
#line 2368 "y.tab.c"
    break;

  case 70:
#line 428 "main.y"
                       {
            if((yyvsp[-1].node)->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
        }
#line 2380 "y.tab.c"
    break;

  case 71:
#line 436 "main.y"
                          {
            (yyvsp[-2].args)->next = createArgList((yyvsp[0].node));
            (yyval.args) = (yyvsp[-2].args);
        }
#line 2389 "y.tab.c"
    break;

  case 72:
#line 440 "main.y"
               {
            (yyval.args) = createArgList((yyvsp[0].node));
        }
#line 2397 "y.tab.c"
    break;

  case 73:
#line 445 "main.y"
                   {
        (yyval.node) = createTree(0,"+",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2405 "y.tab.c"
    break;

  case 74:
#line 448 "main.y"
                      {
        (yyval.node) = createTree(0,"-",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2413 "y.tab.c"
    break;

  case 75:
#line 451 "main.y"
                    {
        (yyval.node) = createTree(0,"*",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2421 "y.tab.c"
    break;

  case 76:
#line 454 "main.y"
                    {
        (yyval.node) = createTree(0,"/",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2429 "y.tab.c"
    break;

  case 77:
#line 457 "main.y"
                    {
        (yyval.node) = createTree(0,"%",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2437 "y.tab.c"
    break;

  case 78:
#line 460 "main.y"
                   {
        (yyval.node) = createTree(0,"<",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2445 "y.tab.c"
    break;

  case 79:
#line 463 "main.y"
                   {
        (yyval.node) = createTree(0,"<=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2453 "y.tab.c"
    break;

  case 80:
#line 466 "main.y"
                   {
        (yyval.node) = createTree(0,">",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2461 "y.tab.c"
    break;

  case 81:
#line 469 "main.y"
                   {
        (yyval.node) = createTree(0,">=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2469 "y.tab.c"
    break;

  case 82:
#line 472 "main.y"
                   {
        (yyval.node) = createTree(0,"!=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2477 "y.tab.c"
    break;

  case 83:
#line 475 "main.y"
                   {
        (yyval.node) = createTree(0,"==",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2485 "y.tab.c"
    break;

  case 84:
#line 478 "main.y"
                   {
        (yyval.node) = createTree(0,"||",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2493 "y.tab.c"
    break;

  case 85:
#line 481 "main.y"
                    {
        (yyval.node) = createTree(0,"&&",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2501 "y.tab.c"
    break;

  case 86:
#line 484 "main.y"
                   {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2509 "y.tab.c"
    break;

  case 87:
#line 487 "main.y"
                 {
        SymbolTable* st = lookupEntry((yyvsp[-1].node)->varname,sstop);
        (yyvsp[-1].node)->STentry = st;
        (yyvsp[-1].node)->type = st->type;
        (yyvsp[-1].node)->nodetype = NODETYPE_ARRAY;
        (yyvsp[-1].node)->dimNode = (yyvsp[0].dim);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2522 "y.tab.c"
    break;

  case 88:
#line 495 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->type!=TYPE_PTR){
            fprintf(stderr,"Error: Trying to access non pointer values\n");
            exit(1);
        }
        (yyvsp[0].node)->STentry = st;
        (yyval.node) = createTree(0,"*",st->vartype,NULL,NODETYPE_ACCESS,(yyvsp[0].node),NULL,NULL,NULL);
    }
#line 2536 "y.tab.c"
    break;

  case 89:
#line 504 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->type==TYPE_PTR){
            fprintf(stderr,"Error: Trying to reference a pointer\n");
            exit(1);
        }
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->type = st->type;
        (yyval.node) = createTree(0,"&",st->type,NULL,NODETYPE_REF,(yyvsp[0].node),NULL,NULL,NULL);
    }
#line 2551 "y.tab.c"
    break;

  case 90:
#line 514 "main.y"
               {
        SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
        checkargs(NULL,st->paramList,(yyvsp[-2].node)->varname);
        (yyval.node)->STentry = st;
        (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-2].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
    }
#line 2562 "y.tab.c"
    break;

  case 91:
#line 520 "main.y"
                      {
        SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
        checkargs((yyvsp[-1].args),st->paramList,(yyvsp[-3].node)->varname);
        (yyval.node)->STentry = st;
        (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
        (yyval.node)->argList = (yyvsp[-1].args);
    }
#line 2574 "y.tab.c"
    break;

  case 92:
#line 527 "main.y"
         {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->type = st->type;
        (yyval.node) = (yyvsp[0].node);
    }
#line 2585 "y.tab.c"
    break;

  case 93:
#line 533 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2593 "y.tab.c"
    break;

  case 94:
#line 536 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2601 "y.tab.c"
    break;


#line 2605 "y.tab.c"

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
#line 541 "main.y"


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
    stack_top = nextBinding-1;
    codegen_initialize_stack(stack_top);
    codegen(head,-1,-1);
    codegen_add_breakpoint();
    codegen_call_exit();
}

void free_memory(){
    freeTree(head);
}

int main(){
    yyin = fopen("../input.txt", "r");
    yyparse();
    printTree(head);
    target_file = fopen("../target_file.xsm","w");
    code_generate();
    /* free_memory(); */
    return 0;
}
