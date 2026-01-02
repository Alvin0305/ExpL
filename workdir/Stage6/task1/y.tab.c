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
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "code_gen/code_gen.h"
    #include "code_gen/function/function.h"
    #include "define/constants.h"
    #include "g_symbol_table/g_symbol_table.h"
    #include "local_symbol_table/local_symbol_table.h"
    #include "util/util.h"
    #include "error_handler/error_handler.h"
    #include "type_table/type_table.h"

    int yylex(void);
    void yyerror(char const *msg);

    FILE *target_file;
    extern FILE *yyin;
    extern int lineNumber;
    extern char *yytext;

#line 92 "y.tab.c"

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
    READ = 258,
    WRITE = 259,
    PLUS = 260,
    MUL = 261,
    MINUS = 262,
    DIV = 263,
    MOD = 264,
    ASSIGN = 265,
    SEMI = 266,
    AMPERSAND = 267,
    GT = 268,
    GE = 269,
    LT = 270,
    LE = 271,
    NE = 272,
    EQ = 273,
    KW_BEGIN = 274,
    KW_END = 275,
    KW_IF = 276,
    KW_THEN = 277,
    KW_ELSE = 278,
    KW_ENDIF = 279,
    KW_WHILE = 280,
    KW_DO = 281,
    KW_ENDWHILE = 282,
    KW_BREAK = 283,
    KW_CONTINUE = 284,
    KW_REPEAT = 285,
    KW_UNTIL = 286,
    KW_DECL = 287,
    KW_ENDDECL = 288,
    TYPE_INT = 289,
    TYPE_STRING = 290,
    TYPE_VOID = 291,
    COMMA = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    INCREMENT = 296,
    DECREMENT = 297,
    ASSIGN_ADD = 298,
    ASSIGN_SUB = 299,
    ASSIGN_MUL = 300,
    ASSIGN_DIV = 301,
    ASSIGN_MOD = 302,
    KW_RETURN = 303,
    MAIN = 304,
    KW_BRKP = 305,
    KW_TUPLE = 306,
    DOT = 307,
    ARROW = 308,
    KW_TYPE = 309,
    KW_ENDTYPE = 310,
    ID = 311,
    NUM = 312,
    STRING_LITERAL = 313
  };
#endif
/* Tokens.  */
#define READ 258
#define WRITE 259
#define PLUS 260
#define MUL 261
#define MINUS 262
#define DIV 263
#define MOD 264
#define ASSIGN 265
#define SEMI 266
#define AMPERSAND 267
#define GT 268
#define GE 269
#define LT 270
#define LE 271
#define NE 272
#define EQ 273
#define KW_BEGIN 274
#define KW_END 275
#define KW_IF 276
#define KW_THEN 277
#define KW_ELSE 278
#define KW_ENDIF 279
#define KW_WHILE 280
#define KW_DO 281
#define KW_ENDWHILE 282
#define KW_BREAK 283
#define KW_CONTINUE 284
#define KW_REPEAT 285
#define KW_UNTIL 286
#define KW_DECL 287
#define KW_ENDDECL 288
#define TYPE_INT 289
#define TYPE_STRING 290
#define TYPE_VOID 291
#define COMMA 292
#define AND 293
#define OR 294
#define NOT 295
#define INCREMENT 296
#define DECREMENT 297
#define ASSIGN_ADD 298
#define ASSIGN_SUB 299
#define ASSIGN_MUL 300
#define ASSIGN_DIV 301
#define ASSIGN_MOD 302
#define KW_RETURN 303
#define MAIN 304
#define KW_BRKP 305
#define KW_TUPLE 306
#define DOT 307
#define ARROW 308
#define KW_TYPE 309
#define KW_ENDTYPE 310
#define ID 311
#define NUM 312
#define STRING_LITERAL 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    struct tnode *node;
    struct FieldList *field;

#line 265 "y.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

#define YYUNDEFTOK  2
#define YYMAXUTOK   313


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      61,    62,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    68,    69,    70,    73,    74,    75,    78,
      79,    82,    82,    85,    86,    89,    90,    91,    94,    95,
      98,    99,   102,   103,   106,   107,   108,   109,   110,   111,
     112,   113,   116,   119,   120,   123,   126,   127,   128,   129,
     132,   133,   134,   137,   138,   141,   142,   143,   144,   145,
     148,   149,   153,   152,   158,   161,   162,   163,   166,   167,
     170,   171,   172,   175,   176,   177,   178,   181,   184,   187,
     188,   189,   190,   193,   194,   197,   200,   201,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     218,   221,   222,   225,   228,   229,   230,   231,   232,   233,
     235,   238,   239,   240,   255,   258,   259,   260,   261,   262,
     265,   266,   269,   270,   273,   276,   279,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     297,   300,   301,   303,   304,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "READ", "WRITE", "PLUS", "MUL", "MINUS",
  "DIV", "MOD", "ASSIGN", "SEMI", "AMPERSAND", "GT", "GE", "LT", "LE",
  "NE", "EQ", "KW_BEGIN", "KW_END", "KW_IF", "KW_THEN", "KW_ELSE",
  "KW_ENDIF", "KW_WHILE", "KW_DO", "KW_ENDWHILE", "KW_BREAK",
  "KW_CONTINUE", "KW_REPEAT", "KW_UNTIL", "KW_DECL", "KW_ENDDECL",
  "TYPE_INT", "TYPE_STRING", "TYPE_VOID", "COMMA", "AND", "OR", "NOT",
  "INCREMENT", "DECREMENT", "ASSIGN_ADD", "ASSIGN_SUB", "ASSIGN_MUL",
  "ASSIGN_DIV", "ASSIGN_MOD", "KW_RETURN", "MAIN", "KW_BRKP", "KW_TUPLE",
  "DOT", "ARROW", "KW_TYPE", "KW_ENDTYPE", "ID", "NUM", "STRING_LITERAL",
  "'{'", "'}'", "'('", "')'", "'['", "']'", "$accept", "program",
  "programBody", "typeDefBlock", "typeDefList", "typeDef", "$@1",
  "typeFieldList", "typeField", "globalDeclarationsBlock",
  "globalDeclarationList", "globalDecl", "globalVarList",
  "globalTupleDeclaration", "tupleFieldList", "tupleField", "tupleIdList",
  "funcDeclParamList", "funcDeclParam", "type", "functionDefinitionBlock",
  "functionDefinition", "$@2", "body", "paramList", "param",
  "localDeclBlock", "localDeclList", "localDecl", "localTupleDecl",
  "idList", "dimensionDecl", "mainBlock", "statementList", "statement",
  "returnStatement", "inputStatement", "outputStatement",
  "assignmentStatement", "memberAccess", "fieldAssignmentStatement",
  "compoundAssignment", "dimensionUsage", "ifStatement", "whileStatement",
  "repeatUntilStatement", "doWhileStatement", "expr", "functionCall",
  "argList", "boolexpr", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   123,
     125,    40,    41,    91,    93
};
# endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,   -40,    67,    16,  -150,     7,  -150,    -8,  -150,  -150,
     130,  -150,  -150,   344,   388,    64,    71,  -150,  -150,  -150,
    -150,  -150,  -150,    78,  -150,   354,  -150,   126,    -1,   -40,
     101,   104,   388,  -150,  -150,    91,   199,   160,  -150,  -150,
    -150,   131,   109,    -3,  -150,   165,  -150,  -150,   133,   190,
     202,   205,    93,  -150,   397,  -150,   397,   187,   189,  -150,
       1,   397,   379,   247,   261,   262,   263,  -150,  -150,    57,
    -150,   221,    76,  -150,     6,   217,   225,   227,   110,     8,
      94,  -150,  -150,   228,     9,   385,  -150,  -150,   346,   226,
    -150,  -150,  -150,   397,    26,  -150,   397,  -150,   232,  -150,
    -150,   230,  -150,   397,   189,   236,  -150,   397,  -150,   235,
     241,  -150,    61,  -150,  -150,  -150,   238,   242,   249,   246,
     248,   346,   299,   300,   346,   123,   303,   152,   250,  -150,
     309,  -150,  -150,  -150,     0,   310,   311,  -150,  -150,  -150,
    -150,   318,  -150,  -150,   284,  -150,   305,  -150,  -150,  -150,
      96,  -150,  -150,   285,   397,  -150,  -150,    45,   289,   123,
     337,    31,    31,   378,  -150,  -150,   287,   295,   297,   196,
    -150,  -150,   123,   306,   477,  -150,  -150,   123,   351,   355,
     123,   123,   123,   123,   123,   301,   312,    90,   123,    -7,
    -150,  -150,  -150,   123,   313,  -150,  -150,  -150,  -150,    48,
    -150,   133,    99,   314,  -150,   139,    22,   123,    31,    31,
     449,   116,   128,   294,   331,  -150,  -150,   323,    41,   123,
     123,   123,   123,   123,   325,  -150,  -150,   477,   477,   477,
     477,   477,  -150,  -150,  -150,   477,   127,    12,   123,   123,
     477,  -150,   317,  -150,   247,    26,  -150,   382,   188,   386,
     463,  -150,   223,   138,   123,   123,   123,   123,   123,   123,
      31,    31,   376,   375,    31,    31,  -150,    77,  -150,    77,
    -150,  -150,  -150,   123,  -150,  -150,   470,    17,  -150,   349,
      80,  -150,   400,  -150,  -150,  -150,   477,   477,   477,   477,
     477,   477,  -150,   387,   346,   346,   173,   185,   477,  -150,
    -150,  -150,  -150,  -150,   239,   298,    88,   405,   346,  -150,
    -150,  -150,  -150,   335,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     0,     2,     0,     5,     0,     7,    11,
       0,    10,     1,     0,     0,     0,     0,     6,     9,    19,
      45,    46,    48,     0,    49,     0,    21,     0,     0,    45,
       0,     0,     0,    51,     4,     0,     0,    47,    18,    20,
      23,     0,    30,     0,    47,     0,    50,     3,    62,     0,
       0,     0,     0,    14,     0,    29,    42,     0,    28,    22,
       0,    57,     0,     0,     0,     0,     0,    12,    13,     0,
      34,     0,     0,    41,     0,     0,     0,     0,    24,     0,
       0,    56,    61,     0,     0,     0,    64,    66,     0,     0,
      15,    16,    17,     0,     0,    35,     0,    31,     0,    43,
      74,     0,    26,    42,    25,     0,    58,     0,    52,    47,
       0,    71,     0,    60,    63,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,    78,    79,    80,     0,     0,     0,    81,    82,    85,
      86,     0,    75,    33,     0,    39,    32,    40,    44,    73,
       0,    59,    55,     0,     0,    72,    67,     0,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,   124,
     123,   125,     0,   130,    90,   129,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    76,    89,     0,     0,   100,    99,    88,    38,     0,
      27,    62,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,   126,     0,     0,
       0,     0,     0,     0,     0,    97,    98,   105,   106,   107,
     108,   109,   102,   103,   131,   134,     0,     0,     0,     0,
     104,   101,     0,    36,     0,     0,    70,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   117,   119,   118,
     120,   121,    94,     0,   132,   111,     0,     0,    37,     0,
       0,    91,     0,    93,    96,   144,   138,   137,   136,   135,
     139,   140,   142,   141,     0,     0,     0,     0,   133,    95,
     110,    53,    68,    92,     0,     0,     0,     0,     0,   113,
     114,   116,   115,     0,   112
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,  -150,  -150,   407,  -150,  -150,   377,  -150,
    -150,   402,  -150,  -150,   283,   345,   195,   339,   347,   107,
    -150,   413,  -150,   203,  -150,   342,   245,  -150,   365,   366,
    -150,   374,    86,  -120,  -122,  -150,  -150,  -150,  -150,   -88,
    -150,  -150,  -108,  -150,  -150,  -150,  -150,  -114,   -86,  -150,
    -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    16,    52,    53,    14,
      25,    26,    43,    27,    69,    70,   146,    72,    73,    71,
      32,    33,   153,    89,    80,    81,    63,    85,    86,    87,
     112,    58,     6,   128,   129,   130,   131,   132,   133,   173,
     135,   136,   189,   137,   138,   139,   140,   210,   175,   236,
     211
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   163,   141,   238,   166,    41,   191,    77,    59,     7,
     193,   174,    98,   212,   105,   110,    12,   219,   220,   221,
     222,   223,   219,   220,   221,   222,   223,   219,   220,   221,
     222,   223,   144,   134,    60,   141,   134,   167,   141,    13,
     134,   191,   141,   168,   191,   206,   219,   220,   221,   222,
     223,   203,   194,    15,   242,    42,   239,    78,   218,   251,
     253,   217,    99,   224,   106,   111,   227,   228,   229,   230,
     231,   208,   156,   235,   237,   134,   275,   141,   134,   240,
     141,   300,   145,   220,   249,   222,   223,   169,   170,   171,
       1,   302,   209,   250,    93,   252,   167,   248,   157,   311,
      34,   204,   168,   266,   243,   267,   268,   269,   270,   271,
       2,   292,   293,    96,   295,   296,   297,   199,    47,    94,
      28,    31,     8,     9,   276,   277,    35,    49,    50,   167,
      36,   107,    28,    96,    37,   168,    93,    40,    97,    31,
     286,   287,   288,   289,   290,   291,   169,   170,   171,    51,
      48,   172,   234,    67,   260,   261,   108,    44,   200,   298,
      45,   245,   177,    74,   273,    62,   260,   261,    79,    84,
      56,   103,    57,    57,   304,   305,   260,   261,   262,   169,
     170,   171,   191,   191,   172,    17,     9,    55,   313,   274,
     263,   191,    84,   178,   179,   180,   181,   182,   183,   184,
     285,   247,   188,    74,   185,   186,   134,   134,   141,   141,
      74,   260,   261,   187,    79,   188,   134,   134,   141,   141,
     134,    54,   141,   260,   261,   134,    61,   141,   219,   220,
     221,   222,   223,    49,    50,   306,   254,   255,   256,   257,
     258,   259,   116,   117,    75,   118,    64,   307,   185,   186,
     282,   239,    76,   116,   117,    51,   118,   187,    65,   188,
     119,    66,   308,   309,   120,   121,    88,   122,   123,   124,
     190,   119,    90,    91,    92,   120,   121,    95,   122,   123,
     124,   100,   101,   102,   109,   266,   142,   125,   148,   126,
     116,   117,   151,   118,   149,   127,   154,   155,   125,   158,
     126,   116,   117,   159,   118,   160,   127,   161,   119,   162,
     164,   165,   120,   121,   176,   122,   123,   124,   214,   119,
     192,   195,   196,   120,   121,   310,   122,   123,   124,   197,
     219,   220,   221,   222,   223,   125,   272,   126,   116,   117,
     198,   118,   199,   127,   201,   205,   125,   207,   126,   116,
     117,   215,   118,   216,   127,   264,   119,   232,   194,   314,
     120,   121,   225,   122,   123,   124,   226,   119,   233,   241,
     246,   120,   121,   278,   122,   123,   124,    19,    20,    21,
      22,   116,   117,   125,   118,   126,   239,    38,    20,    21,
      22,   127,   265,   281,   125,    23,   126,   283,   294,   119,
      24,   295,   127,   213,   121,    23,   122,   123,   124,   301,
      24,   303,    82,    20,    21,    22,   312,    18,   113,    20,
      21,    22,    29,    21,    22,   260,   125,    39,   126,    68,
      83,    20,    21,    22,   127,    24,    83,   202,   143,    30,
     280,    24,   150,   147,    24,    46,   244,   279,    30,   152,
     114,   115,   104,    24,   219,   220,   221,   222,   223,     0,
       0,     0,   254,   255,   256,   257,   258,   259,   219,   220,
     221,   222,   223,     0,   284,   219,   220,   221,   222,   223,
       0,   299,   219,   220,   221,   222,   223
};

static const yytype_int16 yycheck[] =
{
      88,   121,    88,    10,   124,     6,   128,     6,    11,    49,
      10,   125,     6,   162,     6,     6,     0,     5,     6,     7,
       8,     9,     5,     6,     7,     8,     9,     5,     6,     7,
       8,     9,     6,   121,    37,   121,   124,     6,   124,    32,
     128,   163,   128,    12,   166,   159,     5,     6,     7,     8,
       9,     6,    52,    61,     6,    56,    63,    56,   172,   208,
     209,   169,    56,   177,    56,    56,   180,   181,   182,   183,
     184,    40,    11,   187,   188,   163,    64,   163,   166,   193,
     166,    64,    56,     6,    62,     8,     9,    56,    57,    58,
      34,    11,    61,   207,    37,   209,     6,   205,    37,    11,
      14,    56,    12,    62,    56,   219,   220,   221,   222,   223,
      54,   260,   261,    37,    26,   264,   265,    37,    32,    62,
      13,    14,    55,    56,   238,   239,    62,    34,    35,     6,
      59,    37,    25,    37,    56,    12,    37,    11,    62,    32,
     254,   255,   256,   257,   258,   259,    56,    57,    58,    56,
      59,    61,    62,    60,    38,    39,    62,    56,    62,   273,
      56,    62,    10,    56,    37,    32,    38,    39,    61,    62,
      61,    61,    63,    63,   294,   295,    38,    39,    62,    56,
      57,    58,   304,   305,    61,    55,    56,    56,   308,    62,
      62,   313,    85,    41,    42,    43,    44,    45,    46,    47,
      62,    62,    63,    96,    52,    53,   294,   295,   294,   295,
     103,    38,    39,    61,   107,    63,   304,   305,   304,   305,
     308,    61,   308,    38,    39,   313,    61,   313,     5,     6,
       7,     8,     9,    34,    35,    62,    13,    14,    15,    16,
      17,    18,     3,     4,    57,     6,    56,    62,    52,    53,
      62,    63,    63,     3,     4,    56,     6,    61,    56,    63,
      21,    56,    23,    24,    25,    26,    19,    28,    29,    30,
      20,    21,    11,    11,    11,    25,    26,    56,    28,    29,
      30,    64,    57,    56,    56,    62,    60,    48,    56,    50,
       3,     4,    56,     6,    64,    56,    61,    56,    48,    61,
      50,     3,     4,    61,     6,    56,    56,    61,    21,    61,
      11,    11,    25,    26,    11,    28,    29,    30,    31,    21,
      11,    11,    11,    25,    26,    27,    28,    29,    30,    11,
       5,     6,     7,     8,     9,    48,    11,    50,     3,     4,
      56,     6,    37,    56,    59,    56,    48,    10,    50,     3,
       4,    56,     6,    56,    56,    61,    21,    56,    52,    24,
      25,    26,    11,    28,    29,    30,    11,    21,    56,    56,
      56,    25,    26,    56,    28,    29,    30,    33,    34,    35,
      36,     3,     4,    48,     6,    50,    63,    33,    34,    35,
      36,    56,    61,    11,    48,    51,    50,    11,    22,    21,
      56,    26,    56,    25,    26,    51,    28,    29,    30,    60,
      56,    11,    33,    34,    35,    36,    11,    10,    33,    34,
      35,    36,    34,    35,    36,    38,    48,    25,    50,    52,
      51,    34,    35,    36,    56,    56,    51,   154,    93,    51,
     245,    56,   103,    96,    56,    32,   201,   244,    51,   107,
      85,    85,    78,    56,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,     5,     6,
       7,     8,     9,    -1,    11,     5,     6,     7,     8,     9,
      -1,    11,     5,     6,     7,     8,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    54,    66,    67,    68,    97,    49,    55,    56,
      69,    70,     0,    32,    74,    61,    71,    55,    70,    33,
      34,    35,    36,    51,    56,    75,    76,    78,    84,    34,
      51,    84,    85,    86,    97,    62,    59,    56,    33,    76,
      11,     6,    56,    77,    56,    56,    86,    97,    59,    34,
      35,    56,    72,    73,    61,    56,    61,    63,    96,    11,
      37,    61,    32,    91,    56,    56,    56,    60,    73,    79,
      80,    84,    82,    83,    84,    57,    63,     6,    56,    84,
      89,    90,    33,    51,    84,    92,    93,    94,    19,    88,
      11,    11,    11,    37,    62,    56,    37,    62,     6,    56,
      64,    57,    56,    61,    96,     6,    56,    37,    62,    56,
       6,    56,    95,    33,    93,    94,     3,     4,     6,    21,
      25,    26,    28,    29,    30,    48,    50,    56,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   108,   109,   110,
     111,   113,    60,    80,     6,    56,    81,    83,    56,    64,
      82,    56,    90,    87,    61,    56,    11,    37,    61,    61,
      56,    61,    61,    98,    11,    11,    98,     6,    12,    56,
      57,    58,    61,   104,   112,   113,    11,    10,    41,    42,
      43,    44,    45,    46,    47,    52,    53,    61,    63,   107,
      20,    99,    11,    10,    52,    11,    11,    11,    56,    37,
      62,    59,    79,     6,    56,    56,   112,    10,    40,    61,
     112,   115,   115,    25,    31,    56,    56,   107,   112,     5,
       6,     7,     8,     9,   112,    11,    11,   112,   112,   112,
     112,   112,    56,    56,    62,   112,   114,   112,    10,    63,
     112,    56,     6,    56,    91,    62,    56,    62,   107,    62,
     112,   115,   112,   115,    13,    14,    15,    16,    17,    18,
      38,    39,    62,    62,    61,    61,    62,   112,   112,   112,
     112,   112,    11,    37,    62,    64,   112,   112,    56,    88,
      81,    11,    62,    11,    11,    62,   112,   112,   112,   112,
     112,   112,   115,   115,    22,    26,   115,   115,   112,    11,
      64,    60,    11,    11,    98,    98,    62,    62,    23,    24,
      27,    11,    11,    98,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    68,    68,    69,
      69,    71,    70,    72,    72,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    79,    80,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      85,    85,    87,    86,    88,    89,    89,    89,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    93,    94,    95,
      95,    95,    95,    96,    96,    97,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   101,   101,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   110,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     3,     1,     3,     2,     0,     2,
       1,     0,     5,     2,     1,     3,     3,     3,     3,     2,
       2,     1,     3,     2,     3,     4,     4,     6,     2,     2,
       1,     4,     6,     3,     1,     2,     3,     4,     2,     1,
       3,     1,     0,     2,     3,     1,     1,     2,     1,     1,
       2,     1,     0,    10,     3,     3,     1,     0,     2,     3,
       3,     2,     0,     2,     1,     2,     1,     3,     7,     3,
       4,     1,     2,     4,     3,     8,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     2,
       2,     5,     6,     5,     4,     5,     5,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     9,     7,     7,     7,     7,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     2,     2,     2,     1,
       1,     3,     4,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3
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
#line 65 "parser.y"
                                                            { exit(0); }
#line 1701 "y.tab.c"
    break;

  case 6:
#line 73 "parser.y"
                                                                    { printTypeTable(); }
#line 1707 "y.tab.c"
    break;

  case 11:
#line 82 "parser.y"
             { createNewType((yyvsp[0].node)->varName); }
#line 1713 "y.tab.c"
    break;

  case 12:
#line 82 "parser.y"
                                                                    { setFieldsOfType((yyvsp[-4].node)->varName, (yyvsp[-1].field)); }
#line 1719 "y.tab.c"
    break;

  case 13:
#line 85 "parser.y"
                                                            { (yyval.field) = mergeTypeFields((yyvsp[-1].field), (yyvsp[0].field)); }
#line 1725 "y.tab.c"
    break;

  case 14:
#line 86 "parser.y"
                                                            { (yyval.field) = (yyvsp[0].field); }
#line 1731 "y.tab.c"
    break;

  case 15:
#line 89 "parser.y"
                                                            { (yyval.field) = createNewTypeField((yyvsp[-1].node)->varName, typeTableLookup("INT")); }
#line 1737 "y.tab.c"
    break;

  case 16:
#line 90 "parser.y"
                                                            { (yyval.field) = createNewTypeField((yyvsp[-1].node)->varName, typeTableLookup("STRING")); }
#line 1743 "y.tab.c"
    break;

  case 17:
#line 91 "parser.y"
                                                            { (yyval.field) = createNewTypeField((yyvsp[-1].node)->varName, typeTableLookup((yyvsp[-2].node)->varName)); }
#line 1749 "y.tab.c"
    break;

  case 18:
#line 94 "parser.y"
                                                                    { printGST(); (yyval.node) = NULL; }
#line 1755 "y.tab.c"
    break;

  case 19:
#line 95 "parser.y"
                                                                    { (yyval.node) = NULL; }
#line 1761 "y.tab.c"
    break;

  case 20:
#line 98 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1767 "y.tab.c"
    break;

  case 21:
#line 99 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1773 "y.tab.c"
    break;

  case 22:
#line 102 "parser.y"
                                                            { addToGST((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = NULL; }
#line 1779 "y.tab.c"
    break;

  case 23:
#line 103 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1785 "y.tab.c"
    break;

  case 24:
#line 106 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1791 "y.tab.c"
    break;

  case 25:
#line 107 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewArrayNode((yyvsp[-1].node), (yyvsp[0].node))); }
#line 1797 "y.tab.c"
    break;

  case 26:
#line 108 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node))); }
#line 1803 "y.tab.c"
    break;

  case 27:
#line 109 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-5].node), createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-1].node))); }
#line 1809 "y.tab.c"
    break;

  case 28:
#line 110 "parser.y"
                                                            { (yyval.node) = createNewArrayNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1815 "y.tab.c"
    break;

  case 29:
#line 111 "parser.y"
                                                            { (yyval.node) = createNewPointerNode((yyvsp[0].node)); }
#line 1821 "y.tab.c"
    break;

  case 30:
#line 112 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1827 "y.tab.c"
    break;

  case 31:
#line 113 "parser.y"
                                                            { (yyval.node) = createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1833 "y.tab.c"
    break;

  case 32:
#line 116 "parser.y"
                                                                               { addTupleTypeToGST((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = NULL; }
#line 1839 "y.tab.c"
    break;

  case 33:
#line 119 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1845 "y.tab.c"
    break;

  case 34:
#line 120 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1851 "y.tab.c"
    break;

  case 35:
#line 123 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1857 "y.tab.c"
    break;

  case 36:
#line 126 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1863 "y.tab.c"
    break;

  case 37:
#line 127 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node))); }
#line 1869 "y.tab.c"
    break;

  case 38:
#line 128 "parser.y"
                                                            { (yyval.node) = createNewPointerNode((yyvsp[0].node)); }
#line 1875 "y.tab.c"
    break;

  case 39:
#line 129 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1881 "y.tab.c"
    break;

  case 40:
#line 132 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1887 "y.tab.c"
    break;

  case 41:
#line 133 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1893 "y.tab.c"
    break;

  case 42:
#line 134 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1899 "y.tab.c"
    break;

  case 43:
#line 137 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-1].node), (yyvsp[0].node), false, false); }
#line 1905 "y.tab.c"
    break;

  case 44:
#line 138 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-2].node), (yyvsp[0].node), false, true); }
#line 1911 "y.tab.c"
    break;

  case 45:
#line 141 "parser.y"
                                                            { (yyval.node) = createTypeNode(INT); }
#line 1917 "y.tab.c"
    break;

  case 46:
#line 142 "parser.y"
                                                            { (yyval.node) = createTypeNode(STRING); }
#line 1923 "y.tab.c"
    break;

  case 47:
#line 143 "parser.y"
                                                            { (yyval.node) = createTupleTypeNode((yyvsp[0].node)); }
#line 1929 "y.tab.c"
    break;

  case 48:
#line 144 "parser.y"
                                                            { (yyval.node) = createTypeNode(VOID); }
#line 1935 "y.tab.c"
    break;

  case 49:
#line 145 "parser.y"
                                                            { (yyval.node) = createUserTypeNode((yyvsp[0].node)); }
#line 1941 "y.tab.c"
    break;

  case 50:
#line 148 "parser.y"
                                                                        { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1947 "y.tab.c"
    break;

  case 51:
#line 149 "parser.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1953 "y.tab.c"
    break;

  case 52:
#line 153 "parser.y"
        { currentFunction = lookupGST((yyvsp[-3].node)->varName); }
#line 1959 "y.tab.c"
    break;

  case 53:
#line 155 "parser.y"
        { (yyval.node) = createFunctionDefinitionNode((yyvsp[-9].node), (yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1965 "y.tab.c"
    break;

  case 54:
#line 158 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1971 "y.tab.c"
    break;

  case 55:
#line 161 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1977 "y.tab.c"
    break;

  case 56:
#line 162 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1983 "y.tab.c"
    break;

  case 57:
#line 163 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1989 "y.tab.c"
    break;

  case 58:
#line 166 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-1].node), (yyvsp[0].node), true, false); }
#line 1995 "y.tab.c"
    break;

  case 59:
#line 167 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-2].node), (yyvsp[0].node), true, true); }
#line 2001 "y.tab.c"
    break;

  case 60:
#line 170 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2007 "y.tab.c"
    break;

  case 61:
#line 171 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 2013 "y.tab.c"
    break;

  case 62:
#line 172 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 2019 "y.tab.c"
    break;

  case 63:
#line 175 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2025 "y.tab.c"
    break;

  case 64:
#line 176 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2031 "y.tab.c"
    break;

  case 65:
#line 177 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2037 "y.tab.c"
    break;

  case 66:
#line 178 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2043 "y.tab.c"
    break;

  case 67:
#line 181 "parser.y"
                                                            { addToLST((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = NULL; }
#line 2049 "y.tab.c"
    break;

  case 68:
#line 184 "parser.y"
                                                                            { addTupleTypeToLST((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); (yyval.node) = NULL; }
#line 2055 "y.tab.c"
    break;

  case 69:
#line 187 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2061 "y.tab.c"
    break;

  case 70:
#line 188 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node))); }
#line 2067 "y.tab.c"
    break;

  case 71:
#line 189 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2073 "y.tab.c"
    break;

  case 72:
#line 190 "parser.y"
                                                            { (yyval.node) = createNewPointerNode((yyvsp[0].node)); }
#line 2079 "y.tab.c"
    break;

  case 73:
#line 193 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2085 "y.tab.c"
    break;

  case 74:
#line 194 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2091 "y.tab.c"
    break;

  case 75:
#line 197 "parser.y"
                                                              { generateMainCode((yyvsp[-1].node)); printLocalSymbolTable(); freeLocalSymbolTable(); (yyval.node) = NULL; }
#line 2097 "y.tab.c"
    break;

  case 76:
#line 200 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2103 "y.tab.c"
    break;

  case 77:
#line 201 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2109 "y.tab.c"
    break;

  case 78:
#line 204 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2115 "y.tab.c"
    break;

  case 79:
#line 205 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2121 "y.tab.c"
    break;

  case 80:
#line 206 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2127 "y.tab.c"
    break;

  case 81:
#line 207 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2133 "y.tab.c"
    break;

  case 82:
#line 208 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2139 "y.tab.c"
    break;

  case 83:
#line 209 "parser.y"
                                                            { (yyval.node) = createBreakNode(); }
#line 2145 "y.tab.c"
    break;

  case 84:
#line 210 "parser.y"
                                                            { (yyval.node) = createContinueNode(); }
#line 2151 "y.tab.c"
    break;

  case 85:
#line 211 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2157 "y.tab.c"
    break;

  case 86:
#line 212 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2163 "y.tab.c"
    break;

  case 87:
#line 213 "parser.y"
                                                            { (yyval.node) = createBreakPointNode(); }
#line 2169 "y.tab.c"
    break;

  case 88:
#line 214 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2175 "y.tab.c"
    break;

  case 89:
#line 215 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2181 "y.tab.c"
    break;

  case 90:
#line 218 "parser.y"
                                                            { (yyval.node) = createReturnNode((yyvsp[0].node)); }
#line 2187 "y.tab.c"
    break;

  case 91:
#line 221 "parser.y"
                                                            { (yyval.node) = createReadNode((yyvsp[-2].node)); }
#line 2193 "y.tab.c"
    break;

  case 92:
#line 222 "parser.y"
                                                            { (yyval.node) = createReadToArrayNode((yyvsp[-3].node), (yyvsp[-2].node)); }
#line 2199 "y.tab.c"
    break;

  case 93:
#line 225 "parser.y"
                                                            { (yyval.node) = createWriteNode((yyvsp[-2].node)); }
#line 2205 "y.tab.c"
    break;

  case 94:
#line 228 "parser.y"
                                                            { (yyval.node) = createAssignNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2211 "y.tab.c"
    break;

  case 95:
#line 229 "parser.y"
                                                            { (yyval.node) = createArrayAssignNode((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2217 "y.tab.c"
    break;

  case 96:
#line 230 "parser.y"
                                                            { (yyval.node) = createAssignToDereferencedNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2223 "y.tab.c"
    break;

  case 97:
#line 231 "parser.y"
                                                            { (yyval.node) = createIncrementNode((yyvsp[-2].node)); }
#line 2229 "y.tab.c"
    break;

  case 98:
#line 232 "parser.y"
                                                            { (yyval.node) = createDecrementNode((yyvsp[-2].node)); }
#line 2235 "y.tab.c"
    break;

  case 99:
#line 233 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2241 "y.tab.c"
    break;

  case 100:
#line 235 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2247 "y.tab.c"
    break;

  case 101:
#line 238 "parser.y"
                                                            { (yyval.node) = createMemberAccessNode((yyvsp[-2].node), (yyvsp[0].node), ACCESS_DOT); }
#line 2253 "y.tab.c"
    break;

  case 102:
#line 239 "parser.y"
                                                            { (yyval.node) = createMemberAccessNode((yyvsp[-2].node), (yyvsp[0].node), ACCESS_DOT); }
#line 2259 "y.tab.c"
    break;

  case 103:
#line 240 "parser.y"
                                                            { (yyval.node) = createMemberAccessNode((yyvsp[-2].node), (yyvsp[0].node), ACCESS_ARROW); }
#line 2265 "y.tab.c"
    break;

  case 104:
#line 255 "parser.y"
                                                            { (yyval.node) = createMemberAssignmentNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2271 "y.tab.c"
    break;

  case 105:
#line 258 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2277 "y.tab.c"
    break;

  case 106:
#line 259 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2283 "y.tab.c"
    break;

  case 107:
#line 260 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2289 "y.tab.c"
    break;

  case 108:
#line 261 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2295 "y.tab.c"
    break;

  case 109:
#line 262 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2301 "y.tab.c"
    break;

  case 110:
#line 265 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2307 "y.tab.c"
    break;

  case 111:
#line 266 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2313 "y.tab.c"
    break;

  case 112:
#line 269 "parser.y"
                                                                                            { (yyval.node) = createIfElseNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2319 "y.tab.c"
    break;

  case 113:
#line 270 "parser.y"
                                                                                            { (yyval.node) = createIfNode((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2325 "y.tab.c"
    break;

  case 114:
#line 273 "parser.y"
                                                                                            { (yyval.node) = createWhileNode((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2331 "y.tab.c"
    break;

  case 115:
#line 276 "parser.y"
                                                                                            { (yyval.node) = createRepeatUntilNode((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 2337 "y.tab.c"
    break;

  case 116:
#line 279 "parser.y"
                                                                                            { (yyval.node) = createDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 2343 "y.tab.c"
    break;

  case 117:
#line 282 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2349 "y.tab.c"
    break;

  case 118:
#line 283 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2355 "y.tab.c"
    break;

  case 119:
#line 284 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2361 "y.tab.c"
    break;

  case 120:
#line 285 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2367 "y.tab.c"
    break;

  case 121:
#line 286 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2373 "y.tab.c"
    break;

  case 122:
#line 287 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2379 "y.tab.c"
    break;

  case 123:
#line 288 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2385 "y.tab.c"
    break;

  case 124:
#line 289 "parser.y"
                                                            { (yyval.node) = createVariableUsageNode((yyvsp[0].node)->varName); }
#line 2391 "y.tab.c"
    break;

  case 125:
#line 290 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2397 "y.tab.c"
    break;

  case 126:
#line 291 "parser.y"
                                                            { (yyval.node) = createArrayAccessNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2403 "y.tab.c"
    break;

  case 127:
#line 292 "parser.y"
                                                            { (yyval.node) = createDereferenceNode((yyvsp[0].node)); }
#line 2409 "y.tab.c"
    break;

  case 128:
#line 293 "parser.y"
                                                            { (yyval.node) = createAddressToNode((yyvsp[0].node)); }
#line 2415 "y.tab.c"
    break;

  case 129:
#line 294 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2421 "y.tab.c"
    break;

  case 130:
#line 297 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2427 "y.tab.c"
    break;

  case 131:
#line 300 "parser.y"
                                                            { (yyval.node) = createFunctionCallNode((yyvsp[-2].node), NULL); }
#line 2433 "y.tab.c"
    break;

  case 132:
#line 301 "parser.y"
                                                            { (yyval.node) = createFunctionCallNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2439 "y.tab.c"
    break;

  case 133:
#line 303 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2445 "y.tab.c"
    break;

  case 134:
#line 304 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2451 "y.tab.c"
    break;

  case 135:
#line 307 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2457 "y.tab.c"
    break;

  case 136:
#line 308 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2463 "y.tab.c"
    break;

  case 137:
#line 309 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2469 "y.tab.c"
    break;

  case 138:
#line 310 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2475 "y.tab.c"
    break;

  case 139:
#line 311 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2481 "y.tab.c"
    break;

  case 140:
#line 312 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2487 "y.tab.c"
    break;

  case 141:
#line 313 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2493 "y.tab.c"
    break;

  case 142:
#line 314 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2499 "y.tab.c"
    break;

  case 143:
#line 315 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_NOT, (yyvsp[0].node), NULL); }
#line 2505 "y.tab.c"
    break;

  case 144:
#line 316 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2511 "y.tab.c"
    break;


#line 2515 "y.tab.c"

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
#line 319 "parser.y"


void yyerror(char const *msg) {
    printf("[Error] : %s in line: %d [%s]\n", msg, lineNumber, yytext);
    return;
}

int main(int argc, char **argv) {
    FILE *source_file;
    if (argc == 2) {
        source_file = fopen(argv[1], "r");
    } else {
        source_file = fopen(SOURCE_FILE, "r");
    }

    if (!source_file) {
        compilerError(E_NO_SOURCE_FILE);
    }

    target_file = fopen(INTERMEDIATE_FILE, "w");

    yyin = source_file;
    generateHeader();
    initializeTypeTable();

    return yyparse();
}
