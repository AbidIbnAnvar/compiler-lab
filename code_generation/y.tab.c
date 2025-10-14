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
    RETURN = 292,
    BRKP = 293,
    BEGINSTMT = 294,
    ENDSTMT = 295
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
#define BRKP 293
#define BEGINSTMT 294
#define ENDSTMT 295

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

#line 229 "y.tab.c"

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
#define YYLAST   595

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
      43,    44,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    69,    72,    76,    80,    85,    93,    97,
     111,   120,   125,   128,   132,   135,   138,   143,   143,   154,
     158,   164,   164,   179,   179,   195,   203,   206,   211,   214,
     219,   222,   227,   239,   242,   247,   255,   260,   275,   285,
     288,   298,   302,   310,   315,   318,   321,   324,   327,   330,
     333,   336,   339,   342,   345,   348,   351,   356,   360,   369,
     374,   379,   387,   395,   398,   403,   408,   412,   416,   421,
     424,   431,   438,   443,   448,   451,   456,   463,   471,   475,
     480,   483,   486,   489,   492,   495,   498,   501,   504,   507,
     510,   513,   516,   519,   522,   530,   539,   549,   555,   562,
     568,   571
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
  "STR_TYPE", "MAIN", "RETURN", "BRKP", "BEGINSTMT", "ENDSTMT", "';'",
  "','", "'('", "')'", "'{'", "'}'", "'='", "'['", "']'", "'&'", "$accept",
  "Program", "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid",
  "MainBlock", "$@1", "FDefBlock", "FDef", "$@2", "$@3", "ParamList",
  "Param", "Type", "LDeclBlock", "LDecList", "LDecl", "VarList", "Slist",
  "Stmt", "InputStmt", "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt",
  "BreakStmt", "ContinueStmt", "DoWhileStmt", "RepeatUntilStmt",
  "FunctionCallStmt", "ReturnStmt", "BreakPointStmt", "DimDecl", "Dimlist",
  "ArgList", "expr", YY_NULLPTR
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
     295,    59,    44,    40,    41,   123,   125,    61,    91,    93,
      38
};
# endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,    74,    -6,    40,   -14,  -162,  -162,  -162,  -162,    78,
    -162,    32,     2,  -162,    -6,  -162,   -14,  -162,    49,  -162,
    -162,   -16,    66,    58,  -162,    33,  -162,  -162,    52,   116,
     140,   123,  -162,    98,  -162,    32,  -162,   140,   137,    23,
    -162,    51,   118,   140,  -162,   133,    83,   140,   140,  -162,
    -162,   177,   143,    86,   160,  -162,    87,  -162,  -162,  -162,
    -162,    84,   154,   155,  -162,  -162,    57,    89,  -162,   437,
     160,   156,   143,   195,   135,  -162,  -162,   -24,   198,   161,
     162,     4,     4,   437,   180,   181,   437,   182,   325,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,   164,   160,  -162,  -162,  -162,    62,    71,     4,     4,
     205,   206,   278,     4,  -162,   -15,  -162,   279,     4,   280,
     490,   512,   465,  -162,  -162,   353,  -162,     4,  -162,   245,
     437,   247,   143,   283,   257,    91,   534,   210,   130,     4,
       4,   -13,   138,    99,  -162,  -162,   163,  -162,     4,     4,
       4,     4,     4,   437,     4,     4,     4,     4,     4,     4,
       4,     4,   437,     4,     4,   218,   242,   325,   437,  -162,
    -162,  -162,     4,   258,  -162,   252,   240,   248,   261,   259,
     264,  -162,   124,  -162,    42,  -162,  -162,    42,  -162,   297,
     564,   564,   564,   564,   564,   564,   542,   570,   381,   188,
     270,  -162,  -162,   266,   325,   534,  -162,  -162,  -162,  -162,
    -162,   275,  -162,  -162,   437,   276,   277,  -162,  -162,   273,
     267,  -162,   409,  -162,  -162,  -162,   274,   281,  -162,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    30,    31,     0,
       8,     0,     0,     1,    30,     3,     0,    20,     0,     5,
       7,    12,     0,     0,    11,     0,     2,    19,     0,     0,
      27,     0,    13,    14,     9,     0,    17,    27,     0,     0,
      26,     0,     0,    27,    10,     0,     0,    27,     0,    15,
      28,     0,    75,     0,    34,    21,     0,    25,    29,    74,
      16,     0,     0,     0,    23,    33,     0,     0,    36,     0,
      34,     0,    39,     0,     0,    32,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    34,    41,    43,    37,     0,     0,     0,     0,
       0,     0,     0,     0,   100,    99,   101,     0,     0,     0,
       0,     0,     0,    66,    67,     0,    73,     0,    44,     0,
       0,     0,    38,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      42,    71,     0,     0,    60,    77,     0,     0,     0,     0,
       0,    97,     0,    93,    80,    82,    83,    81,    84,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    72,    18,     0,     0,    78,    70,    76,    61,    62,
      57,     0,    59,    98,     0,     0,     0,    68,    69,     0,
       0,    58,     0,    64,    65,    22,     0,     0,    24,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,   312,  -162,   288,     9,  -162,  -162,
     308,  -162,  -162,   -21,   282,     1,   -58,  -162,   272,  -162,
     -82,   -88,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -161,  -162,   -34,  -112,   185,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    23,    24,     5,    45,    16,
      17,    63,    71,    39,    40,    41,    62,    67,    68,    74,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   129,   100,    32,   110,   135,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     128,   122,    11,   144,   125,    18,   203,   114,   115,   116,
      11,   117,   101,    15,   120,   121,    46,    18,    59,   107,
      14,     8,    53,   108,   109,    26,    56,    30,   143,   179,
      12,   178,    31,   109,   128,   109,    21,   128,   103,    22,
      13,   137,   138,   220,   131,    25,   142,   118,   167,   149,
     150,   146,   152,    28,   119,    50,    29,     1,    51,     2,
     165,    72,    66,   207,    73,    48,   132,    49,    66,   133,
      33,   189,   176,   177,   114,   115,   116,    36,   117,   128,
     198,   184,   185,   186,   187,   188,   204,   190,   191,   192,
     193,   194,   195,   196,   197,    37,   199,   200,   169,    34,
      35,   128,   114,   115,   116,   205,   117,     6,     7,     8,
     128,    19,     7,     8,   118,   134,   128,    65,     7,     8,
      38,   119,    75,     7,     8,    48,    42,    55,    48,    48,
      60,    64,   222,   172,   128,   173,   148,   149,   150,   151,
     152,    43,   118,   181,   148,   149,   150,   151,   152,   119,
     154,   155,   156,   157,   158,   159,   160,   161,   154,   155,
     156,   157,   158,   159,   160,   161,   172,    52,   213,   148,
     149,   150,   151,   152,     7,     8,   105,   106,    54,   175,
      47,    58,   180,   154,   155,   156,   157,   158,   159,   160,
     161,    31,    61,    69,   148,   149,   150,   151,   152,   104,
      70,   102,   111,   130,   112,   113,   162,   183,   154,   155,
     156,   157,   158,   159,   160,   161,   148,   149,   150,   151,
     152,   123,   124,   126,   148,   149,   150,   151,   152,   217,
     154,   155,   156,   157,   158,   159,   160,   161,   154,   155,
     156,   157,   158,   159,   160,   161,   148,   149,   150,   151,
     152,   174,   139,   140,   148,   149,   150,   151,   152,   201,
     154,   155,   156,   157,   158,   159,   160,   161,   154,   155,
     156,   157,   158,   159,   160,   161,   148,   149,   150,   151,
     152,   208,   141,   145,   147,   166,   168,   170,   202,   209,
     154,   155,   156,   157,   158,   159,   160,   161,   171,   206,
     109,    77,   210,   211,    78,   212,   219,   226,    79,    80,
      81,   218,   214,   215,    82,    83,   221,   223,   224,   225,
     228,    20,   229,    44,    27,    84,    85,    86,   182,    77,
      57,     0,    78,     0,     0,    87,    79,    80,    81,    76,
       0,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,     0,    77,     0,     0,
      78,     0,   127,    87,    79,    80,    81,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,   164,    77,     0,     0,    78,     0,
       0,    87,    79,    80,    81,     0,     0,     0,    82,    83,
     216,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,     0,    77,     0,     0,    78,     0,     0,    87,
      79,    80,    81,     0,     0,   227,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
       0,    77,     0,     0,    78,     0,     0,    87,    79,    80,
      81,     0,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,     0,    77,
       0,     0,    78,     0,     0,    87,    79,    80,    81,     0,
       0,     0,   163,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,   148,   149,   150,   151,
     152,     0,     0,    87,   153,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   148,   149,
     150,   151,   152,     0,     0,     0,     0,     0,     0,     0,
     162,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     148,   149,   150,   151,   152,     0,     0,     0,   148,   149,
     150,   151,   152,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   154,   155,   156,   157,   158,   159,     0,   161,
     148,   149,   150,   151,   152,     0,   148,   149,   150,   151,
     152,     0,     0,     0,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159
};

static const yytype_int16 yycheck[] =
{
      88,    83,     1,   115,    86,     4,   167,     3,     4,     5,
       9,     7,    70,     4,    81,    82,    37,    16,    52,    43,
      34,    35,    43,    47,    48,    16,    47,    43,    43,   141,
      36,    44,    48,    48,   122,    48,     4,   125,    72,     7,
       0,   108,   109,   204,   102,    43,   113,    43,   130,     7,
       8,   118,    10,     4,    50,     4,     7,    32,     7,    34,
     127,     4,    61,   175,     7,    42,     4,    44,    67,     7,
       4,   153,   139,   140,     3,     4,     5,    44,     7,   167,
     162,   148,   149,   150,   151,   152,   168,   154,   155,   156,
     157,   158,   159,   160,   161,    43,   163,   164,   132,    41,
      42,   189,     3,     4,     5,   172,     7,    33,    34,    35,
     198,    33,    34,    35,    43,    44,   204,    33,    34,    35,
       4,    50,    33,    34,    35,    42,     3,    44,    42,    42,
      44,    44,   214,    42,   222,    44,     6,     7,     8,     9,
      10,    43,    43,    44,     6,     7,     8,     9,    10,    50,
      20,    21,    22,    23,    24,    25,    26,    27,    20,    21,
      22,    23,    24,    25,    26,    27,    42,    49,    44,     6,
       7,     8,     9,    10,    34,    35,    41,    42,    45,    49,
      43,     4,    44,    20,    21,    22,    23,    24,    25,    26,
      27,    48,    32,    39,     6,     7,     8,     9,    10,     4,
      45,    45,     4,    39,    43,    43,    18,    44,    20,    21,
      22,    23,    24,    25,    26,    27,     6,     7,     8,     9,
      10,    41,    41,    41,     6,     7,     8,     9,    10,    41,
      20,    21,    22,    23,    24,    25,    26,    27,    20,    21,
      22,    23,    24,    25,    26,    27,     6,     7,     8,     9,
      10,    41,    47,    47,     6,     7,     8,     9,    10,    41,
      20,    21,    22,    23,    24,    25,    26,    27,    20,    21,
      22,    23,    24,    25,    26,    27,     6,     7,     8,     9,
      10,    41,     4,     4,     4,    40,    39,     4,    46,    41,
      20,    21,    22,    23,    24,    25,    26,    27,    41,    41,
      48,     4,    41,    44,     7,    41,    40,    40,    11,    12,
      13,    41,    15,    16,    17,    18,    41,    41,    41,    46,
      46,     9,    41,    35,    16,    28,    29,    30,   143,     4,
      48,    -1,     7,    -1,    -1,    38,    11,    12,    13,    67,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    -1,     4,    -1,    -1,
       7,    -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,     4,    -1,    -1,     7,    -1,
      -1,    38,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    -1,     4,    -1,    -1,     7,    -1,    -1,    38,
      11,    12,    13,    -1,    -1,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      -1,     4,    -1,    -1,     7,    -1,    -1,    38,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,     4,
      -1,    -1,     7,    -1,    -1,    38,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,     6,     7,     8,     9,
      10,    -1,    -1,    38,    14,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
       6,     7,     8,     9,    10,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    20,    21,    22,    23,    24,    25,    -1,    27,
       6,     7,     8,     9,    10,    -1,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,    52,    53,    58,    33,    34,    35,    54,
      55,    66,    36,     0,    34,    58,    60,    61,    66,    33,
      55,     4,     7,    56,    57,    43,    58,    61,     4,     7,
      43,    48,    85,     4,    41,    42,    44,    43,     4,    64,
      65,    66,     3,    43,    57,    59,    64,    43,    42,    44,
       4,     7,    49,    64,    45,    44,    64,    65,     4,    85,
      44,    32,    67,    62,    44,    33,    66,    68,    69,    39,
      45,    63,     4,     7,    70,    33,    69,     4,     7,    11,
      12,    13,    17,    18,    28,    29,    30,    38,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      84,    67,    45,    85,     4,    41,    42,    43,    47,    48,
      86,     4,    43,    43,     3,     4,     5,     7,    43,    50,
      88,    88,    71,    41,    41,    71,    41,    37,    72,    83,
      39,    67,     4,     7,    44,    87,    88,    88,    88,    47,
      47,     4,    88,    43,    86,     4,    88,     4,     6,     7,
       8,     9,    10,    14,    20,    21,    22,    23,    24,    25,
      26,    27,    18,    17,    31,    88,    40,    71,    39,    85,
       4,    41,    42,    44,    41,    49,    88,    88,    44,    86,
      44,    44,    87,    44,    88,    88,    88,    88,    88,    71,
      88,    88,    88,    88,    88,    88,    88,    88,    71,    88,
      88,    41,    46,    83,    71,    88,    41,    86,    41,    41,
      41,    44,    41,    44,    15,    16,    19,    41,    41,    40,
      83,    41,    71,    41,    41,    46,    40,    16,    46,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    57,    57,    57,    59,    58,    60,
      60,    62,    61,    63,    61,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    68,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      75,    75,    75,    76,    76,    77,    78,    79,    80,    81,
      82,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     2,     2,     4,     5,     0,    12,     2,
       1,     0,    13,     0,    14,     3,     1,     0,     2,     3,
       1,     1,     3,     2,     0,     2,     1,     3,     3,     1,
       4,     2,     4,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     6,     5,
       4,     5,     5,     8,     6,     6,     2,     2,     5,     5,
       5,     4,     3,     2,     4,     3,     4,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     4,     1,
       1,     1
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
            head = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1745 "y.tab.c"
    break;

  case 3:
#line 69 "main.y"
                              {
            head = (yyvsp[0].node);
        }
#line 1753 "y.tab.c"
    break;

  case 4:
#line 72 "main.y"
                   {
            head = (yyvsp[0].node);
        }
#line 1761 "y.tab.c"
    break;

  case 5:
#line 76 "main.y"
                                   {
                pushToScopeStack((yyvsp[-1].symbolTable),&sstop);
                showTable((yyvsp[-1].symbolTable));
            }
#line 1770 "y.tab.c"
    break;

  case 6:
#line 80 "main.y"
                          {
                pushToScopeStack(NULL,&sstop);
                showTable(sstop->symbolTable);
            }
#line 1779 "y.tab.c"
    break;

  case 7:
#line 85 "main.y"
                           {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
        }
#line 1792 "y.tab.c"
    break;

  case 8:
#line 93 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1800 "y.tab.c"
    break;

  case 9:
#line 97 "main.y"
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
#line 1818 "y.tab.c"
    break;

  case 10:
#line 111 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }
            // Append id to the end of the symbol table
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 1832 "y.tab.c"
    break;

  case 11:
#line 120 "main.y"
              {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 1840 "y.tab.c"
    break;

  case 12:
#line 125 "main.y"
        {
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,-1,GLOBAL,NULL,NULL,NULL);
    }
#line 1848 "y.tab.c"
    break;

  case 13:
#line 128 "main.y"
                 {
        int size = getArraySize((yyvsp[0].dim));
        (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->type,size,-1,GLOBAL,(yyvsp[0].dim),NULL,NULL);
    }
#line 1857 "y.tab.c"
    break;

  case 14:
#line 132 "main.y"
             {
        (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,TYPE_PTR,1,-1,GLOBAL,NULL,NULL,NULL);
    }
#line 1865 "y.tab.c"
    break;

  case 15:
#line 135 "main.y"
                         {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->type,1,currentFLabel++,GLOBAL,NULL,(yyvsp[-1].params),NULL);
    }
#line 1873 "y.tab.c"
    break;

  case 16:
#line 138 "main.y"
                             {
        (yyval.symbolTable) = createEntry((yyvsp[-3].node)->varname,(yyvsp[-3].node)->type,1,currentFLabel++,GLOBAL,NULL,(yyvsp[-1].params),NULL);
    }
#line 1881 "y.tab.c"
    break;

  case 17:
#line 143 "main.y"
                                 {
            nextBinding = 1;
            printf("main()\n");
            pushToScopeStack(NULL,&sstop);
        }
#line 1891 "y.tab.c"
    break;

  case 18:
#line 147 "main.y"
                                                                {
            (yyval.node) = createTree(0,NULL,TYPE_INT,"main",NODETYPE_MAIN,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
            (yyval.node)->Lentry = sstop->symbolTable;
            popFromScopeStack(&sstop);
        }
#line 1901 "y.tab.c"
    break;

  case 19:
#line 154 "main.y"
                          {
            // TODO: Check if the declared function and defined function types and parameters are same
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 1910 "y.tab.c"
    break;

  case 20:
#line 158 "main.y"
               {
            // TODO: Check if the declared function and defined function types and parameters are same
            (yyval.node) = (yyvsp[0].node);
        }
#line 1919 "y.tab.c"
    break;

  case 21:
#line 164 "main.y"
                                {
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            // printParamList($4);
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
#line 1934 "y.tab.c"
    break;

  case 22:
#line 174 "main.y"
                                                           {
        (yyval.node) = createTree(0,NULL,TYPE_NULL,(yyvsp[-11].node)->varname,NODETYPE_FUNC,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 1944 "y.tab.c"
    break;

  case 23:
#line 179 "main.y"
                                    {
            printf("%s()\n",(yyvsp[-3].node)->varname);
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            checkparams(st->paramList,(yyvsp[-1].params),(yyvsp[-3].node)->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable((yyvsp[-1].params));
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
#line 1958 "y.tab.c"
    break;

  case 24:
#line 188 "main.y"
                                                           {
        (yyval.node) = createTree(0,NULL,TYPE_NULL,(yyvsp[-11].node)->varname,NODETYPE_FUNC,(yyvsp[-3].node),NULL,(yyvsp[-2].node),NULL);
        (yyval.node)->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
#line 1968 "y.tab.c"
    break;

  case 25:
#line 195 "main.y"
                               {
            paramList* curr = (yyvsp[-2].params);
            while(curr->next){
                curr = curr->next;
            }   
            curr->next = (yyvsp[0].params);
            (yyval.params) = (yyvsp[-2].params);
        }
#line 1981 "y.tab.c"
    break;

  case 26:
#line 203 "main.y"
                {
            (yyval.params) = (yyvsp[0].params);
        }
#line 1989 "y.tab.c"
    break;

  case 27:
#line 206 "main.y"
          { 
            (yyval.params) = NULL;
        }
#line 1997 "y.tab.c"
    break;

  case 28:
#line 211 "main.y"
               {
        (yyval.params) = createParamList((yyvsp[-1].var_type),TYPE_NULL,(yyvsp[0].node)->varname);
    }
#line 2005 "y.tab.c"
    break;

  case 29:
#line 214 "main.y"
                  {
        (yyval.params) = createParamList(TYPE_PTR,(yyvsp[-2].var_type),(yyvsp[0].node)->varname);
    }
#line 2013 "y.tab.c"
    break;

  case 30:
#line 219 "main.y"
                {
        (yyval.var_type) = TYPE_INT;
    }
#line 2021 "y.tab.c"
    break;

  case 31:
#line 222 "main.y"
               {
        (yyval.var_type) = TYPE_STR;
    }
#line 2029 "y.tab.c"
    break;

  case 32:
#line 227 "main.y"
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
#line 2046 "y.tab.c"
    break;

  case 33:
#line 239 "main.y"
                       {
            // showTable(sstop->symbolTable);
        }
#line 2054 "y.tab.c"
    break;

  case 34:
#line 242 "main.y"
          {
            // showTable(sstop->symbolTable);
        }
#line 2062 "y.tab.c"
    break;

  case 35:
#line 247 "main.y"
                         {
            SymbolTable* curr = (yyvsp[-1].symbolTable);
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = (yyvsp[0].symbolTable);
            (yyval.symbolTable) = (yyvsp[-1].symbolTable);
        }
#line 2075 "y.tab.c"
    break;

  case 36:
#line 255 "main.y"
                {
            (yyval.symbolTable) = (yyvsp[0].symbolTable);
        }
#line 2083 "y.tab.c"
    break;

  case 37:
#line 260 "main.y"
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
#line 2101 "y.tab.c"
    break;

  case 38:
#line 275 "main.y"
                         {
            // Get symbol table pointer for varlist
            SymbolTable* curr = (yyvsp[-2].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            // Append entry to the end of the symbol table
            curr->next = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,-1,LOCAL,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-2].symbolTable);
        }
#line 2116 "y.tab.c"
    break;

  case 39:
#line 285 "main.y"
             {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,-1,LOCAL,NULL,NULL,NULL);
        }
#line 2124 "y.tab.c"
    break;

  case 40:
#line 288 "main.y"
                                 {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }

            int size = getArraySize((yyvsp[0].dim));
            curr->next = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->type,size,-1,LOCAL,(yyvsp[0].dim),NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2139 "y.tab.c"
    break;

  case 41:
#line 298 "main.y"
                     {
            int size = getArraySize((yyvsp[0].dim));
            (yyval.symbolTable) = createEntry((yyvsp[-1].node)->varname,(yyvsp[-1].node)->type,size,-1,LOCAL,(yyvsp[0].dim),NULL,NULL);
        }
#line 2148 "y.tab.c"
    break;

  case 42:
#line 302 "main.y"
                             {
            SymbolTable* curr = (yyvsp[-3].symbolTable);
            while(curr->next){
                curr = curr->next;
            }
            curr->next = createEntry((yyvsp[0].node)->varname,TYPE_PTR,1,-1,GLOBAL,NULL,NULL,NULL);
            (yyval.symbolTable) = (yyvsp[-3].symbolTable);
        }
#line 2161 "y.tab.c"
    break;

  case 43:
#line 310 "main.y"
                 {
            (yyval.symbolTable) = createEntry((yyvsp[0].node)->varname,TYPE_PTR,1,-1,GLOBAL,NULL,NULL,NULL);
        }
#line 2169 "y.tab.c"
    break;

  case 44:
#line 315 "main.y"
                   {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,(yyvsp[-1].node),NULL,(yyvsp[0].node),NULL);
        }
#line 2177 "y.tab.c"
    break;

  case 45:
#line 318 "main.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2183 "y.tab.c"
    break;

  case 46:
#line 321 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2191 "y.tab.c"
    break;

  case 47:
#line 324 "main.y"
                     {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2199 "y.tab.c"
    break;

  case 48:
#line 327 "main.y"
                  {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2207 "y.tab.c"
    break;

  case 49:
#line 330 "main.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2215 "y.tab.c"
    break;

  case 50:
#line 333 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2223 "y.tab.c"
    break;

  case 51:
#line 336 "main.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2231 "y.tab.c"
    break;

  case 52:
#line 339 "main.y"
                       {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2239 "y.tab.c"
    break;

  case 53:
#line 342 "main.y"
                      {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2247 "y.tab.c"
    break;

  case 54:
#line 345 "main.y"
                          {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2255 "y.tab.c"
    break;

  case 55:
#line 348 "main.y"
                           {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2263 "y.tab.c"
    break;

  case 56:
#line 351 "main.y"
                         {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2271 "y.tab.c"
    break;

  case 57:
#line 356 "main.y"
                                {
            (yyvsp[-2].node)->STentry = lookupEntry((yyvsp[-2].node)->varname,sstop);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2280 "y.tab.c"
    break;

  case 58:
#line 360 "main.y"
                                     {
            // Fetch record containing the varname in the symbol table
            (yyvsp[-3].node)->STentry = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-3].node)->dimNode = (yyvsp[-2].dim);
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,(yyvsp[-3].node),NULL,NULL,NULL); 
        }
#line 2292 "y.tab.c"
    break;

  case 59:
#line 369 "main.y"
                                    {
           (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,(yyvsp[-2].node),NULL,NULL,NULL); 
        }
#line 2300 "y.tab.c"
    break;

  case 60:
#line 374 "main.y"
                          {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            (yyval.node) = createTree(0,"=",st->type,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-3].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2310 "y.tab.c"
    break;

  case 61:
#line 379 "main.y"
                                  {
            SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
            (yyvsp[-4].node)->STentry = st;
            (yyvsp[-4].node)->type = st->type;
            (yyvsp[-4].node)->nodetype = NODETYPE_ARRAY;
            (yyvsp[-4].node)->dimNode = (yyvsp[-3].dim);
            (yyval.node) = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,(yyvsp[-4].node),NULL,(yyvsp[-1].node),NULL);
        }
#line 2323 "y.tab.c"
    break;

  case 62:
#line 387 "main.y"
                              {
            SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
            (yyvsp[-3].node)->STentry = st;
            tnode* left = createTree(0,"*",st->type,NULL,NODETYPE_ACCESS,(yyvsp[-3].node),NULL,NULL,NULL);
            (yyval.node) = createTree(0,"=",st->type,NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,(yyvsp[-1].node),NULL);
        }
#line 2334 "y.tab.c"
    break;

  case 63:
#line 395 "main.y"
                                                 {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),NULL); 
        }
#line 2342 "y.tab.c"
    break;

  case 64:
#line 398 "main.y"
                                       { 
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,(yyvsp[-4].node),(yyvsp[-2].node),NULL,NULL);
        }
#line 2350 "y.tab.c"
    break;

  case 65:
#line 403 "main.y"
                                              {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WHILE,(yyvsp[-4].node),NULL,(yyvsp[-2].node),NULL);
          }
#line 2358 "y.tab.c"
    break;

  case 66:
#line 408 "main.y"
                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BREAK,NULL,NULL,NULL,NULL);
          }
#line 2366 "y.tab.c"
    break;

  case 67:
#line 412 "main.y"
                            {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONTINUE,NULL,NULL,NULL,NULL);
             }
#line 2374 "y.tab.c"
    break;

  case 68:
#line 416 "main.y"
                                      {
                (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_DO_WHILE,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
            }
#line 2382 "y.tab.c"
    break;

  case 69:
#line 421 "main.y"
                                              {
                    (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_REPEAT_UNTIL,(yyvsp[-1].node),NULL,(yyvsp[-3].node),NULL);
                }
#line 2390 "y.tab.c"
    break;

  case 70:
#line 424 "main.y"
                                         {
                    SymbolTable* st = lookupEntry((yyvsp[-4].node)->varname,sstop);
                    checkargs((yyvsp[-2].args),st->paramList,(yyvsp[-4].node)->varname);
                    (yyvsp[-4].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-4].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
                    (yyval.node)->argList = (yyvsp[-2].args);
                }
#line 2402 "y.tab.c"
    break;

  case 71:
#line 431 "main.y"
                               {
                    SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
                    checkargs(NULL,st->paramList,(yyvsp[-3].node)->varname);
                    (yyvsp[-3].node)->STentry = st;
                    (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
                }
#line 2413 "y.tab.c"
    break;

  case 72:
#line 438 "main.y"
                            {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_RETURN,(yyvsp[-1].node),NULL,NULL,NULL);
        }
#line 2421 "y.tab.c"
    break;

  case 73:
#line 443 "main.y"
                         {
            (yyval.node) = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BRKP,NULL,NULL,NULL,NULL);
            }
#line 2429 "y.tab.c"
    break;

  case 74:
#line 448 "main.y"
                             {
                (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
            }
#line 2437 "y.tab.c"
    break;

  case 75:
#line 451 "main.y"
                          {
                (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
            }
#line 2445 "y.tab.c"
    break;

  case 76:
#line 456 "main.y"
                               {
            if((yyvsp[-2].node)->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            (yyval.dim) = addDimension((yyvsp[-2].node)->val,(yyvsp[-2].node),(yyvsp[0].dim));
        }
#line 2457 "y.tab.c"
    break;

  case 77:
#line 463 "main.y"
                       {
            if((yyvsp[-1].node)->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            (yyval.dim) = addDimension((yyvsp[-1].node)->val,(yyvsp[-1].node),NULL);
        }
#line 2469 "y.tab.c"
    break;

  case 78:
#line 471 "main.y"
                          {
            (yyvsp[-2].args)->next = createArgList((yyvsp[0].node));
            (yyval.args) = (yyvsp[-2].args);
        }
#line 2478 "y.tab.c"
    break;

  case 79:
#line 475 "main.y"
               {
            (yyval.args) = createArgList((yyvsp[0].node));
        }
#line 2486 "y.tab.c"
    break;

  case 80:
#line 480 "main.y"
                   {
        (yyval.node) = createTree(0,"+",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2494 "y.tab.c"
    break;

  case 81:
#line 483 "main.y"
                      {
        (yyval.node) = createTree(0,"-",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2502 "y.tab.c"
    break;

  case 82:
#line 486 "main.y"
                    {
        (yyval.node) = createTree(0,"*",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2510 "y.tab.c"
    break;

  case 83:
#line 489 "main.y"
                    {
        (yyval.node) = createTree(0,"/",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2518 "y.tab.c"
    break;

  case 84:
#line 492 "main.y"
                    {
        (yyval.node) = createTree(0,"%",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2526 "y.tab.c"
    break;

  case 85:
#line 495 "main.y"
                   {
        (yyval.node) = createTree(0,"<",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2534 "y.tab.c"
    break;

  case 86:
#line 498 "main.y"
                   {
        (yyval.node) = createTree(0,"<=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2542 "y.tab.c"
    break;

  case 87:
#line 501 "main.y"
                   {
        (yyval.node) = createTree(0,">",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2550 "y.tab.c"
    break;

  case 88:
#line 504 "main.y"
                   {
        (yyval.node) = createTree(0,">=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2558 "y.tab.c"
    break;

  case 89:
#line 507 "main.y"
                   {
        (yyval.node) = createTree(0,"!=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2566 "y.tab.c"
    break;

  case 90:
#line 510 "main.y"
                   {
        (yyval.node) = createTree(0,"==",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2574 "y.tab.c"
    break;

  case 91:
#line 513 "main.y"
                   {
        (yyval.node) = createTree(0,"||",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2582 "y.tab.c"
    break;

  case 92:
#line 516 "main.y"
                    {
        (yyval.node) = createTree(0,"&&",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,(yyvsp[-2].node),NULL,(yyvsp[0].node),NULL);
    }
#line 2590 "y.tab.c"
    break;

  case 93:
#line 519 "main.y"
                   {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2598 "y.tab.c"
    break;

  case 94:
#line 522 "main.y"
                 {
        SymbolTable* st = lookupEntry((yyvsp[-1].node)->varname,sstop);
        (yyvsp[-1].node)->STentry = st;
        (yyvsp[-1].node)->type = st->type;
        (yyvsp[-1].node)->nodetype = NODETYPE_ARRAY;
        (yyvsp[-1].node)->dimNode = (yyvsp[0].dim);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2611 "y.tab.c"
    break;

  case 95:
#line 530 "main.y"
             {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        if(st->type!=TYPE_PTR){
            fprintf(stderr,"Error: Trying to access non pointer values\n");
            exit(1);
        }
        (yyvsp[0].node)->STentry = st;
        (yyval.node) = createTree(0,"*",st->vartype,NULL,NODETYPE_ACCESS,(yyvsp[0].node),NULL,NULL,NULL);
    }
#line 2625 "y.tab.c"
    break;

  case 96:
#line 539 "main.y"
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
#line 2640 "y.tab.c"
    break;

  case 97:
#line 549 "main.y"
               {
        SymbolTable* st = lookupEntry((yyvsp[-2].node)->varname,sstop);
        checkargs(NULL,st->paramList,(yyvsp[-2].node)->varname);
        (yyval.node)->STentry = st;
        (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-2].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
    }
#line 2651 "y.tab.c"
    break;

  case 98:
#line 555 "main.y"
                      {
        SymbolTable* st = lookupEntry((yyvsp[-3].node)->varname,sstop);
        checkargs((yyvsp[-1].args),st->paramList,(yyvsp[-3].node)->varname);
        (yyval.node)->STentry = st;
        (yyval.node) = createTree(0,NULL,st->type,(yyvsp[-3].node)->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
        (yyval.node)->argList = (yyvsp[-1].args);
    }
#line 2663 "y.tab.c"
    break;

  case 99:
#line 562 "main.y"
         {
        SymbolTable* st = lookupEntry((yyvsp[0].node)->varname,sstop);
        (yyvsp[0].node)->STentry = st;
        (yyvsp[0].node)->type = st->type;
        (yyval.node) = (yyvsp[0].node);
    }
#line 2674 "y.tab.c"
    break;

  case 100:
#line 568 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2682 "y.tab.c"
    break;

  case 101:
#line 571 "main.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2690 "y.tab.c"
    break;


#line 2694 "y.tab.c"

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
#line 576 "main.y"


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
    fprintf(target_file,"CALL F0\n");
    fprintf(target_file,"JMP L_EXIT\n");
    codegen(head,-1,-1);
    fprintf(target_file,"L_EXIT:");
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
