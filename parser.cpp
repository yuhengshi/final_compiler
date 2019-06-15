/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    #include <cstdlib>
    #include <cstdio>
    #include <iostream>
    #include "ast.hpp"
    
    #define YYDEBUG 1
    #define YYINITDEPTH 10000
    
    int yylex(void);
    void yyerror(const char *);
    extern ASTNode* astRoot;

#line 80 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_PTR = 258,
    T_LEQ = 259,
    T_EQUALS = 260,
    T_AND = 261,
    T_OR = 262,
    T_NOT = 263,
    T_NUMBER = 264,
    T_TRUE = 265,
    T_FALSE = 266,
    T_INTEGER = 267,
    T_BOOLEAN = 268,
    T_NONE = 269,
    T_PRINT = 270,
    T_RETURN = 271,
    T_IF = 272,
    T_ELSE = 273,
    T_DO = 274,
    T_WHILE = 275,
    T_NEW = 276,
    T_EXTENDS = 277,
    T_IDENTIFIER = 278,
    T_GEQ = 279,
    UMINUS = 280
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 152 "parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    28,    26,    36,    27,    38,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    37,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    55,    56,    58,    59,    61,    62,    64,
      66,    67,    69,    71,    72,    74,    75,    77,    79,    81,
      82,    84,    86,    87,    89,    90,    92,    93,    95,    96,
      97,    98,    99,   100,   102,   103,   105,   106,   108,   111,
     112,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   135,   136,   138,   139,   141,   142,   144,   146,   147,
     148,   150,   151
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PTR", "T_LEQ", "T_EQUALS", "T_AND",
  "T_OR", "T_NOT", "T_NUMBER", "T_TRUE", "T_FALSE", "T_INTEGER",
  "T_BOOLEAN", "T_NONE", "T_PRINT", "T_RETURN", "T_IF", "T_ELSE", "T_DO",
  "T_WHILE", "T_NEW", "T_EXTENDS", "T_IDENTIFIER", "'>'", "T_GEQ", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'='", "'.'", "$accept", "Start", "Classes", "Class", "Members",
  "Member", "Methods", "Method", "Parameters", "ParameterList",
  "Parameter", "Body", "Declarations", "Declaration", "IdentifierList",
  "Statements", "ReturnStatement", "Statement", "Assignment", "IfElse",
  "WhileLoop", "DoWhile", "Print", "Expression", "MethodCall", "Arguments",
  "ArgumentList", "Argument", "Type", "ReturnType", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    62,   279,    43,    45,    42,    47,
     280,   123,   125,    59,    40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -19,    34,  -105,     6,    13,  -105,  -105,  -105,    29,
      88,  -105,  -105,  -105,    27,  -105,    40,    50,    61,    88,
     163,  -105,    27,  -105,    65,    71,  -105,    62,  -105,    69,
     100,  -105,  -105,   109,   163,  -105,   154,  -105,  -105,  -105,
      93,  -105,   112,   142,  -105,   126,   126,    94,   126,   -23,
    -105,   116,   164,   113,  -105,  -105,   115,   119,   123,   135,
     126,  -105,  -105,  -105,   140,    -7,   126,   126,    14,  -105,
     102,   164,   114,   126,   126,   141,   126,  -105,   -23,  -105,
    -105,  -105,  -105,  -105,   144,   159,  -105,   160,   155,  -105,
      39,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     164,   164,   164,    14,   158,  -105,   161,    14,   148,    89,
     135,  -105,   126,   165,  -105,   162,    51,   145,   162,   162,
     -11,   -11,  -105,  -105,   164,   166,   164,  -105,   126,   126,
     126,  -105,  -105,   167,   168,   175,   169,  -105,   170,    14,
    -105,   178,   172,  -105,  -105,   173,   126,   164,    64,   164,
    -105,   171,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     8,     1,     3,     0,
      11,     8,    68,    69,    70,     7,     0,    11,     0,    11,
      14,     5,     0,    10,     0,     0,    70,     0,    13,    16,
       0,     9,     6,     0,     0,    17,     0,    15,    72,    71,
       0,    20,     0,    25,    12,     0,     0,     0,     0,    70,
      19,    27,    25,     0,    30,    31,     0,     0,     0,     0,
       0,    56,    57,    58,     0,    55,     0,     0,    40,    52,
       0,     0,     0,    64,     0,     0,     0,    18,     0,    24,
      28,    33,    32,    29,    23,     0,    50,    60,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    67,     0,    63,    66,    34,     0,     0,
       0,    21,    64,    53,    54,    47,    48,    49,    45,    46,
      41,    42,    43,    44,    25,     0,    25,    62,     0,    64,
       0,    26,    22,     0,     0,     0,     0,    65,     0,    35,
      59,    36,     0,    38,    61,     0,     0,     0,     0,    25,
      39,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,   203,  -105,   197,  -105,   -12,  -105,  -105,   176,
    -105,  -105,  -105,  -105,    99,   -39,  -105,   -65,  -105,  -105,
    -105,  -105,  -105,   -44,   -43,  -104,    83,  -105,   -10,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    15,    16,    17,    27,    28,
      29,    42,    43,    50,    85,    51,    77,    52,    53,    54,
      55,    56,    57,   103,    69,   104,   105,   106,    18,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    68,    70,     5,    72,    23,   101,    25,   133,    58,
      30,    73,     6,    79,    74,    75,    86,    98,    99,    91,
      92,    93,    89,    90,    30,   138,    39,    73,    58,     1,
     107,    88,   109,    59,     7,   124,     9,   126,    94,    95,
      96,    97,    98,    99,    91,    92,    93,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    91,    58,    58,    58,
      11,    20,   125,    94,    95,    96,    97,    98,    99,    91,
      92,    93,    21,    22,   114,    94,    95,    96,    97,    98,
      99,    58,   149,    58,    24,   134,   139,   136,    94,    95,
      96,    97,    98,    99,    91,    92,    93,    33,    31,   150,
      12,    13,   148,    32,    58,    34,    58,    91,    92,    93,
     151,    14,    36,    94,    95,    96,    97,    98,    99,    91,
      92,    93,   131,    35,    41,    71,    94,    95,    96,    97,
      98,    99,    76,   100,    60,    61,    62,    63,    94,    95,
      96,    97,    98,    99,    44,   102,    80,    64,    81,    65,
      91,    92,    82,    66,    12,    13,    83,    45,    84,    46,
      67,    47,    48,    87,   108,    49,    12,    13,    38,    94,
      95,    96,    97,    98,    99,    12,    13,    26,   113,    45,
     110,    46,   129,    47,    48,   130,    26,    78,    96,    97,
      98,    99,   111,   127,   112,   142,   145,   128,   135,   129,
     141,   143,   140,   152,   147,   144,   146,     8,    19,   132,
      37,   137
};

static const yytype_uint8 yycheck[] =
{
      43,    45,    46,    22,    48,    17,    71,    19,   112,    52,
      20,    34,    31,    52,    37,    38,    60,    28,    29,     5,
       6,     7,    66,    67,    34,   129,    36,    34,    71,    23,
      74,    38,    76,    43,     0,   100,    23,   102,    24,    25,
      26,    27,    28,    29,     5,     6,     7,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     5,   100,   101,   102,
      31,    34,   101,    24,    25,    26,    27,    28,    29,     5,
       6,     7,    32,    23,    35,    24,    25,    26,    27,    28,
      29,   124,   147,   126,    23,   124,   130,   126,    24,    25,
      26,    27,    28,    29,     5,     6,     7,    35,    33,    35,
      12,    13,   146,    32,   147,    36,   149,     5,     6,     7,
     149,    23,     3,    24,    25,    26,    27,    28,    29,     5,
       6,     7,    33,    23,    31,    31,    24,    25,    26,    27,
      28,    29,    16,    31,     8,     9,    10,    11,    24,    25,
      26,    27,    28,    29,    32,    31,    33,    21,    33,    23,
       5,     6,    33,    27,    12,    13,    33,    15,    23,    17,
      34,    19,    20,    23,    23,    23,    12,    13,    14,    24,
      25,    26,    27,    28,    29,    12,    13,    23,    23,    15,
      36,    17,    34,    19,    20,    37,    23,    23,    26,    27,
      28,    29,    33,    35,    34,    20,    18,    36,    32,    34,
      32,    32,    35,    32,    31,    35,    34,     4,    11,   110,
      34,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    40,    41,    42,    22,    31,     0,    41,    23,
      43,    31,    12,    13,    23,    44,    45,    46,    67,    43,
      34,    32,    23,    45,    23,    45,    23,    47,    48,    49,
      67,    33,    32,    35,    36,    23,     3,    48,    14,    67,
      68,    31,    50,    51,    32,    15,    17,    19,    20,    23,
      52,    54,    56,    57,    58,    59,    60,    61,    63,    67,
       8,     9,    10,    11,    21,    23,    27,    34,    62,    63,
      62,    31,    62,    34,    37,    38,    16,    55,    23,    54,
      33,    33,    33,    33,    23,    53,    62,    23,    38,    62,
      62,     5,     6,     7,    24,    25,    26,    27,    28,    29,
      31,    56,    31,    62,    64,    65,    66,    62,    23,    62,
      36,    33,    34,    23,    35,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    56,    54,    56,    35,    36,    34,
      37,    33,    53,    64,    54,    32,    54,    65,    64,    62,
      35,    32,    20,    32,    35,    18,    34,    31,    62,    56,
      35,    54,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    50,    51,
      51,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     7,     2,     0,     3,
       2,     0,     9,     1,     0,     3,     1,     2,     3,     2,
       0,     3,     3,     1,     2,     0,     3,     0,     2,     2,
       1,     1,     2,     2,     3,     5,     6,    11,     6,     9,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     3,     3,     1,     1,     1,     1,     5,
       2,     6,     4,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 53 "parser.y" /* yacc.c:1646  */
    { (yyval.program_ptr) = new ProgramNode((yyvsp[0].class_list_ptr)); astRoot = (yyval.program_ptr); }
#line 1344 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval.class_list_ptr) = (yyvsp[0].class_list_ptr); (yyval.class_list_ptr)->push_front((yyvsp[-1].class_ptr)); }
#line 1350 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval.class_list_ptr) = new std::list<ClassNode*>(); (yyval.class_list_ptr)->push_front((yyvsp[0].class_ptr)); }
#line 1356 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval.class_ptr) = new ClassNode((yyvsp[-4].identifier_ptr), NULL, (yyvsp[-2].declaration_list_ptr), (yyvsp[-1].method_list_ptr)); }
#line 1362 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval.class_ptr) = new ClassNode((yyvsp[-6].identifier_ptr), (yyvsp[-4].identifier_ptr), (yyvsp[-2].declaration_list_ptr), (yyvsp[-1].method_list_ptr)); }
#line 1368 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration_list_ptr) = (yyvsp[-1].declaration_list_ptr); (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr)); }
#line 1374 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration_list_ptr) = new std::list<DeclarationNode*>(); }
#line 1380 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 64 "parser.y" /* yacc.c:1646  */
    { std::list<IdentifierNode*>* list = new std::list<IdentifierNode*>(); list->push_front((yyvsp[-1].identifier_ptr)); (yyval.declaration_ptr) = new DeclarationNode((yyvsp[-2].type_ptr),list); }
#line 1386 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    { (yyval.method_list_ptr) = (yyvsp[0].method_list_ptr); (yyval.method_list_ptr)->push_front((yyvsp[-1].method_ptr)); }
#line 1392 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "parser.y" /* yacc.c:1646  */
    { (yyval.method_list_ptr) = new std::list<MethodNode*>(); }
#line 1398 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 69 "parser.y" /* yacc.c:1646  */
    { (yyval.method_ptr) = new MethodNode((yyvsp[-8].identifier_ptr), (yyvsp[-6].parameter_list_ptr), (yyvsp[-3].type_ptr), (yyvsp[-1].methodbody_ptr)); }
#line 1404 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 71 "parser.y" /* yacc.c:1646  */
    { (yyval.parameter_list_ptr) = (yyvsp[0].parameter_list_ptr); }
#line 1410 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval.parameter_list_ptr) = new std::list<ParameterNode*>(); }
#line 1416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "parser.y" /* yacc.c:1646  */
    { (yyval.parameter_list_ptr) = (yyvsp[0].parameter_list_ptr); (yyval.parameter_list_ptr)->push_front((yyvsp[-2].parameter_ptr)); }
#line 1422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval.parameter_list_ptr) = new std::list<ParameterNode*>(); (yyval.parameter_list_ptr)->push_front((yyvsp[0].parameter_ptr)); }
#line 1428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.parameter_ptr) = new ParameterNode((yyvsp[-1].type_ptr),(yyvsp[0].identifier_ptr)); }
#line 1434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 79 "parser.y" /* yacc.c:1646  */
    { (yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-2].declaration_list_ptr), (yyvsp[-1].statement_list_ptr), (yyvsp[0].returnstatement_ptr)); }
#line 1440 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration_list_ptr) = (yyvsp[-1].declaration_list_ptr); (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr)); }
#line 1446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration_list_ptr) = new std::list<DeclarationNode*>(); }
#line 1452 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration_ptr) = new DeclarationNode((yyvsp[-2].type_ptr), (yyvsp[-1].identifier_list_ptr)); }
#line 1458 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 86 "parser.y" /* yacc.c:1646  */
    { (yyval.identifier_list_ptr) = (yyvsp[0].identifier_list_ptr); (yyval.identifier_list_ptr)->push_front((yyvsp[-2].identifier_ptr)); }
#line 1464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyval.identifier_list_ptr) = new std::list<IdentifierNode*>(); (yyval.identifier_list_ptr)->push_front((yyvsp[0].identifier_ptr)); }
#line 1470 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_list_ptr) = (yyvsp[0].statement_list_ptr); (yyval.statement_list_ptr)->push_front((yyvsp[-1].statement_ptr)); }
#line 1476 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_list_ptr) = new std::list<StatementNode*>(); }
#line 1482 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval.returnstatement_ptr) = new ReturnStatementNode((yyvsp[-1].expression_ptr)); }
#line 1488 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.returnstatement_ptr) = NULL; }
#line 1494 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = (yyvsp[-1].assignment_ptr); }
#line 1500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new CallNode((yyvsp[-1].methodcall_ptr)); }
#line 1506 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = (yyvsp[0].ifelse_ptr); }
#line 1512 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = (yyvsp[0].while_ptr); }
#line 1518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = (yyvsp[-1].print_ptr); }
#line 1524 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = (yyvsp[-1].dowhile_ptr); }
#line 1530 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.assignment_ptr) = new AssignmentNode((yyvsp[-2].identifier_ptr), NULL, (yyvsp[0].expression_ptr));}
#line 1536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.assignment_ptr) = new AssignmentNode((yyvsp[-4].identifier_ptr), (yyvsp[-2].identifier_ptr), (yyvsp[0].expression_ptr)); }
#line 1542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].statement_list_ptr)->push_front((yyvsp[-2].statement_ptr)); (yyval.ifelse_ptr) = new IfElseNode((yyvsp[-4].expression_ptr), (yyvsp[-1].statement_list_ptr), new std::list<StatementNode*>()); }
#line 1548 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-6].statement_list_ptr)->push_front((yyvsp[-7].statement_ptr)); (yyvsp[-1].statement_list_ptr)->push_front((yyvsp[-2].statement_ptr)); (yyval.ifelse_ptr) = new IfElseNode((yyvsp[-9].expression_ptr), (yyvsp[-6].statement_list_ptr), (yyvsp[-1].statement_list_ptr)); }
#line 1554 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].statement_list_ptr)->push_front((yyvsp[-2].statement_ptr)); (yyval.while_ptr) = new WhileNode((yyvsp[-4].expression_ptr), (yyvsp[-1].statement_list_ptr)); }
#line 1560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-5].statement_list_ptr)->push_front((yyvsp[-6].statement_ptr)); (yyval.dowhile_ptr) = new DoWhileNode((yyvsp[-5].statement_list_ptr),(yyvsp[-1].expression_ptr)); }
#line 1566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.print_ptr) = new PrintNode((yyvsp[0].expression_ptr)); }
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new PlusNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new MinusNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new TimesNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new DivideNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new GreaterNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new GreaterEqualNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1608 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new EqualNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr)); }
#line 1614 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new AndNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr)); }
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new OrNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr)); }
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new NotNode((yyvsp[0].expression_ptr));}
#line 1632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new NegationNode((yyvsp[0].expression_ptr)); }
#line 1638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = (yyvsp[0].methodcall_ptr); }
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new MemberAccessNode((yyvsp[-2].identifier_ptr), (yyvsp[0].identifier_ptr)); }
#line 1650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = (yyvsp[-1].expression_ptr); }
#line 1656 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new VariableNode((yyvsp[0].identifier_ptr)); }
#line 1662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new IntegerLiteralNode((yyvsp[0].integer_ptr)); }
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(1)); }
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(0)); }
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new NewNode((yyvsp[-3].identifier_ptr), (yyvsp[-1].expression_list_ptr)); }
#line 1686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = new NewNode((yyvsp[0].identifier_ptr), new std::list<ExpressionNode*>()); }
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.methodcall_ptr) = new MethodCallNode((yyvsp[-5].identifier_ptr), (yyvsp[-3].identifier_ptr), (yyvsp[-1].expression_list_ptr)); }
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.methodcall_ptr) = new MethodCallNode((yyvsp[-3].identifier_ptr), NULL, (yyvsp[-1].expression_list_ptr)); }
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_list_ptr) = (yyvsp[0].expression_list_ptr); }
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_list_ptr) = new std::list<ExpressionNode*>(); }
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_list_ptr) = (yyvsp[0].expression_list_ptr); (yyval.expression_list_ptr)->push_front((yyvsp[-2].expression_ptr)); }
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_list_ptr) = new std::list<ExpressionNode*>(); (yyval.expression_list_ptr)->push_front((yyvsp[0].expression_ptr)); }
#line 1728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_ptr) = (yyvsp[0].expression_ptr); }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.type_ptr) = new IntegerTypeNode(); }
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.type_ptr) = new BooleanTypeNode(); }
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.type_ptr) = new ObjectTypeNode((yyvsp[0].identifier_ptr)); }
#line 1752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.type_ptr) = (yyvsp[0].type_ptr); }
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.type_ptr) = new NoneNode(); }
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1768 "parser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
  return yyresult;
}
#line 153 "parser.y" /* yacc.c:1906  */

extern int yylineno;
void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(1);
}
