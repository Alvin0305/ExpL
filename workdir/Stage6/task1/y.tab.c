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

    int yylex(void);
    void yyerror(char const *msg);

    FILE *target_file;
    extern FILE *yyin;
    extern int lineNumber;
    extern char *yytext;

#line 91 "y.tab.c"

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
    ID = 309,
    NUM = 310,
    STRING_LITERAL = 311
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
#define ID 309
#define NUM 310
#define STRING_LITERAL 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "parser.y"

    struct tnode *node;

#line 259 "y.tab.c"

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


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
      57,    58,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    62,    63,    64,    67,    68,    71,    72,
      75,    76,    79,    80,    81,    82,    83,    84,    85,    86,
      89,    92,    93,    96,    99,   100,   101,   102,   105,   106,
     107,   110,   111,   114,   115,   116,   117,   120,   121,   125,
     124,   130,   133,   134,   135,   138,   139,   142,   143,   144,
     147,   148,   149,   150,   153,   156,   159,   160,   161,   162,
     165,   166,   169,   172,   173,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   190,   193,   194,
     197,   200,   201,   202,   203,   204,   205,   206,   209,   210,
     213,   214,   215,   216,   217,   220,   221,   224,   225,   228,
     231,   234,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   253,   254,   257,   258,
     260,   261,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273
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
  "DOT", "ARROW", "ID", "NUM", "STRING_LITERAL", "'('", "')'", "'{'",
  "'}'", "'['", "']'", "$accept", "program", "programBody",
  "globalDeclarationsBlock", "globalDeclarationList", "globalDecl",
  "globalVarList", "globalTupleDeclaration", "tupleFieldList",
  "tupleField", "tupleIdList", "funcDeclParamList", "funcDeclParam",
  "type", "functionDefinitionBlock", "functionDefinition", "$@1", "body",
  "paramList", "param", "localDeclBlock", "localDeclList", "localDecl",
  "localTupleDecl", "idList", "dimensionDecl", "mainBlock",
  "statementList", "statement", "returnStatement", "inputStatement",
  "outputStatement", "assignmentStatement", "tupleAssignmentStatement",
  "compoundAssignment", "dimensionUsage", "ifStatement", "whileStatement",
  "repeatUntilStatement", "doWhileStatement", "expr", "tupleAccess",
  "functionCall", "argList", "boolexpr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,    40,    41,   123,
     125,    91,    93
};
# endif

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,   330,   -39,    17,  -148,   348,  -148,  -148,  -148,  -148,
    -148,   -32,   334,  -148,    34,     1,   -11,  -148,   -39,    -2,
      22,   348,  -148,  -148,    64,  -148,  -148,  -148,    35,   -42,
      -5,    93,  -148,   107,  -148,  -148,   360,  -148,   360,    67,
      97,  -148,     8,   119,   360,   -24,  -148,   125,    65,  -148,
      18,   129,   132,   146,   104,   170,    20,   101,  -148,   360,
      23,  -148,   360,  -148,   150,  -148,  -148,   147,  -148,   360,
      97,   353,   194,   160,  -148,   360,  -148,  -148,   166,  -148,
     184,  -148,  -148,  -148,   112,  -148,   174,    24,   357,  -148,
    -148,   266,   171,  -148,  -148,   180,  -148,    27,  -148,   190,
     203,  -148,     7,  -148,  -148,  -148,   206,   210,   214,   221,
     225,   266,   253,   263,   266,   100,   275,   280,   169,  -148,
     282,  -148,  -148,  -148,   286,   289,  -148,  -148,  -148,  -148,
     293,  -148,   170,   258,  -148,   360,  -148,  -148,    37,   259,
     100,   297,   305,   305,   325,  -148,  -148,   212,   261,   265,
     249,  -148,  -148,   100,   442,  -148,  -148,  -148,   100,   319,
     323,   100,   100,   100,   100,   100,   281,   284,    87,   100,
       2,  -148,  -148,  -148,  -148,  -148,  -148,   194,  -148,   113,
     285,  -148,   108,    32,   100,   305,   305,   407,   196,   207,
     279,   283,  -148,  -148,   288,   290,   287,   126,   100,   100,
     100,   100,   100,   421,  -148,  -148,   442,   442,   442,   442,
     442,   333,   337,  -148,   442,   116,    62,   100,   100,   292,
      23,  -148,   338,   122,   345,   428,  -148,   102,   217,   100,
     100,   100,   100,   100,   100,   305,   305,   335,   332,   305,
     305,  -148,  -148,  -148,   216,  -148,   216,  -148,  -148,  -148,
     100,   100,   100,  -148,  -148,   435,    78,  -148,    10,  -148,
     361,  -148,  -148,  -148,   442,   442,   442,   442,   442,   442,
    -148,   336,   266,   266,   250,   260,   442,   442,   442,  -148,
    -148,  -148,  -148,   182,   223,    77,   365,   266,  -148,  -148,
    -148,  -148,   255,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,     5,     7,    33,    34,
      36,     0,     0,     9,     0,     0,     0,     1,    33,     0,
       0,     0,    38,     4,    35,     6,     8,    11,     0,    18,
       0,     0,    35,     0,    37,     3,     0,    17,    30,     0,
      16,    10,     0,     0,    44,     0,    22,     0,     0,    29,
       0,     0,     0,     0,    12,    49,     0,     0,    43,     0,
       0,    23,     0,    19,     0,    31,    61,     0,    14,    30,
      13,     0,     0,     0,    45,     0,    39,    21,     0,    27,
      20,    28,    32,    60,     0,    48,     0,     0,     0,    51,
      53,     0,     0,    46,    42,     0,    26,     0,    15,    35,
       0,    58,     0,    47,    50,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,    65,    66,    67,     0,     0,    68,    69,    72,    73,
       0,    62,    49,     0,    24,     0,    59,    54,     0,     0,
       0,     0,     0,     0,     0,    70,    71,     0,     0,     0,
     109,   108,   110,     0,    77,   115,   114,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    63,    76,    87,    86,    75,     0,    25,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    90,    91,    92,    93,
      94,     0,     0,   118,   121,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   107,   102,   104,   103,   105,   106,    81,
       0,     0,     0,   119,    96,     0,     0,    40,     0,    78,
       0,    80,    83,   131,   125,   124,   123,   122,   126,   127,
     129,   128,     0,     0,     0,     0,    88,    89,   120,    82,
      95,    55,    79,     0,     0,     0,     0,     0,    98,    99,
     101,   100,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,   359,  -148,  -148,   242,   321,
     158,   328,   339,     4,  -148,   377,  -148,   226,  -148,   327,
     268,  -148,   317,   318,  -148,   355,   131,  -110,  -116,  -148,
    -148,  -148,  -148,  -148,  -148,  -147,  -148,  -148,  -148,  -148,
    -104,  -148,   -91,  -148,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    13,    30,    14,    45,    46,
      80,    48,    49,    47,    21,    22,    95,    92,    57,    58,
      72,    88,    89,    90,   102,    40,     6,   118,   119,   120,
     121,   122,   123,   124,   125,   170,   126,   127,   128,   129,
     187,   155,   156,   215,   188
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,   144,   172,   196,   147,    15,    41,    28,   189,    20,
      16,   154,   217,    59,    53,    38,    15,    17,   137,    39,
     130,   281,    24,   130,    64,    20,    73,   130,   172,    78,
     100,   172,    42,   133,    60,   223,   183,   198,   199,   200,
     201,   202,    50,   180,   138,    27,    31,    97,    56,   197,
     226,   228,    32,   130,   203,    29,   130,   206,   207,   208,
     209,   210,    54,   218,   214,   216,    50,   198,   199,   200,
     201,   202,    65,    50,    74,    87,    33,    79,   101,    56,
     225,   134,   227,   198,   199,   200,   201,   202,   290,    37,
     224,   181,    87,   148,   244,   245,   246,   247,   248,   149,
     270,   271,    62,   273,   274,   275,   148,   198,   199,   200,
     201,   202,   149,   255,   256,   229,   230,   231,   232,   233,
     234,    36,    51,    63,   254,   264,   265,   266,   267,   268,
     269,   198,   199,   200,   201,   202,    23,     1,    75,     2,
     280,   150,   151,   152,   153,   213,   276,   277,   278,    62,
      59,    43,    35,   252,   150,   151,   152,   153,    52,    76,
     243,    69,   283,   284,    44,    39,   222,   172,   172,   169,
      98,   220,   106,   107,   253,   108,   172,   292,    55,    61,
     260,   130,   130,   218,   243,   106,   107,    67,   108,   171,
     109,    66,   130,   130,   110,   111,   130,   112,   113,   114,
      68,   130,    71,   109,    82,   287,   288,   110,   111,    83,
     112,   113,   114,    91,    93,   106,   107,   115,   108,   116,
      96,    97,   199,   117,   201,   202,   106,   107,    99,   108,
     115,   131,   116,   109,   235,   236,   117,   110,   111,   132,
     112,   113,   114,   191,   109,   235,   236,   135,   110,   111,
     289,   112,   113,   114,   237,   235,   236,   136,   106,   107,
     115,   108,   116,   139,   145,   238,   117,   140,   141,   106,
     107,   115,   108,   116,   146,   263,   109,   117,   142,   293,
     110,   111,   143,   112,   113,   114,   157,   109,   235,   236,
     158,   110,   111,   173,   112,   113,   114,   174,   235,   236,
     175,   194,   195,   115,   176,   116,   168,   184,   285,   117,
     169,   148,   178,   182,   115,   192,   116,   149,   286,   193,
     117,   159,   160,   161,   162,   163,   164,   165,   106,   107,
     204,   108,   166,   167,   205,   211,   239,   168,   212,   221,
     240,   169,   241,   250,   242,   185,   109,   251,   218,   259,
     190,   111,   257,   112,   113,   114,   261,   272,   273,   150,
     151,   152,   186,     7,     8,     9,    10,    25,     8,     9,
      10,    26,   282,   115,   235,   116,   291,   179,   258,   117,
      77,    11,    18,     9,    10,    11,    85,     8,     9,    10,
     103,     8,     9,    10,     8,     9,    10,    84,    34,    19,
     177,    81,    94,   219,    86,   104,   105,     0,    86,    70,
       0,    19,   198,   199,   200,   201,   202,     0,     0,     0,
     229,   230,   231,   232,   233,   234,   198,   199,   200,   201,
     202,     0,   249,   198,   199,   200,   201,   202,     0,   262,
     198,   199,   200,   201,   202,     0,   279,   198,   199,   200,
     201,   202
};

static const yytype_int16 yycheck[] =
{
      91,   111,   118,   150,   114,     1,    11,     6,   143,     5,
      49,   115,    10,    37,     6,    57,    12,     0,    11,    61,
     111,    11,    54,   114,     6,    21,     6,   118,   144,     6,
       6,   147,    37,     6,    58,   182,   140,     5,     6,     7,
       8,     9,    38,     6,    37,    11,    57,    37,    44,   153,
     185,   186,    54,   144,   158,    54,   147,   161,   162,   163,
     164,   165,    54,    61,   168,   169,    62,     5,     6,     7,
       8,     9,    54,    69,    54,    71,    54,    54,    54,    75,
     184,    54,   186,     5,     6,     7,     8,     9,    11,    54,
      58,    54,    88,     6,   198,   199,   200,   201,   202,    12,
     235,   236,    37,    26,   239,   240,     6,     5,     6,     7,
       8,     9,    12,   217,   218,    13,    14,    15,    16,    17,
      18,    57,    55,    58,    62,   229,   230,   231,   232,   233,
     234,     5,     6,     7,     8,     9,     5,    32,    37,    34,
      62,    54,    55,    56,    57,    58,   250,   251,   252,    37,
      37,    58,    21,    37,    54,    55,    56,    57,    61,    58,
      58,    57,   272,   273,    57,    61,    58,   283,   284,    61,
      58,    58,     3,     4,    58,     6,   292,   287,    59,    54,
      58,   272,   273,    61,    58,     3,     4,    55,     6,    20,
      21,    62,   283,   284,    25,    26,   287,    28,    29,    30,
      54,   292,    32,    21,    54,    23,    24,    25,    26,    62,
      28,    29,    30,    19,    54,     3,     4,    48,     6,    50,
      54,    37,     6,    54,     8,     9,     3,     4,    54,     6,
      48,    60,    50,    21,    38,    39,    54,    25,    26,    59,
      28,    29,    30,    31,    21,    38,    39,    57,    25,    26,
      27,    28,    29,    30,    58,    38,    39,    54,     3,     4,
      48,     6,    50,    57,    11,    58,    54,    57,    54,     3,
       4,    48,     6,    50,    11,    58,    21,    54,    57,    24,
      25,    26,    57,    28,    29,    30,    11,    21,    38,    39,
      10,    25,    26,    11,    28,    29,    30,    11,    38,    39,
      11,    52,    53,    48,    11,    50,    57,    10,    58,    54,
      61,     6,    54,    54,    48,    54,    50,    12,    58,    54,
      54,    41,    42,    43,    44,    45,    46,    47,     3,     4,
      11,     6,    52,    53,    11,    54,    57,    57,    54,    54,
      57,    61,    54,    10,    54,    40,    21,    10,    61,    11,
      25,    26,    60,    28,    29,    30,    11,    22,    26,    54,
      55,    56,    57,    33,    34,    35,    36,    33,    34,    35,
      36,    12,    11,    48,    38,    50,    11,   135,   220,    54,
      59,    51,    34,    35,    36,    51,    33,    34,    35,    36,
      33,    34,    35,    36,    34,    35,    36,    69,    21,    51,
     132,    62,    75,   177,    51,    88,    88,    -1,    51,    54,
      -1,    51,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,     5,     6,     7,     8,
       9,    -1,    11,     5,     6,     7,     8,     9,    -1,    11,
       5,     6,     7,     8,     9,    -1,    11,     5,     6,     7,
       8,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,    64,    65,    66,    89,    33,    34,    35,
      36,    51,    67,    68,    70,    76,    49,     0,    34,    51,
      76,    77,    78,    89,    54,    33,    68,    11,     6,    54,
      69,    57,    54,    54,    78,    89,    57,    54,    57,    61,
      88,    11,    37,    58,    57,    71,    72,    76,    74,    75,
      76,    55,    61,     6,    54,    59,    76,    81,    82,    37,
      58,    54,    37,    58,     6,    54,    62,    55,    54,    57,
      88,    32,    83,     6,    54,    37,    58,    72,     6,    54,
      73,    75,    54,    62,    74,    33,    51,    76,    84,    85,
      86,    19,    80,    54,    82,    79,    54,    37,    58,    54,
       6,    54,    87,    33,    85,    86,     3,     4,     6,    21,
      25,    26,    28,    29,    30,    48,    50,    54,    90,    91,
      92,    93,    94,    95,    96,    97,    99,   100,   101,   102,
     105,    60,    59,     6,    54,    57,    54,    11,    37,    57,
      57,    54,    57,    57,    90,    11,    11,    90,     6,    12,
      54,    55,    56,    57,   103,   104,   105,    11,    10,    41,
      42,    43,    44,    45,    46,    47,    52,    53,    57,    61,
      98,    20,    91,    11,    11,    11,    11,    83,    54,    71,
       6,    54,    54,   103,    10,    40,    57,   103,   107,   107,
      25,    31,    54,    54,    52,    53,    98,   103,     5,     6,
       7,     8,     9,   103,    11,    11,   103,   103,   103,   103,
     103,    54,    54,    58,   103,   106,   103,    10,    61,    80,
      58,    54,    58,    98,    58,   103,   107,   103,   107,    13,
      14,    15,    16,    17,    18,    38,    39,    58,    58,    57,
      57,    54,    54,    58,   103,   103,   103,   103,   103,    11,
      10,    10,    37,    58,    62,   103,   103,    60,    73,    11,
      58,    11,    11,    58,   103,   103,   103,   103,   103,   103,
     107,   107,    22,    26,   107,   107,   103,   103,   103,    11,
      62,    11,    11,    90,    90,    58,    58,    23,    24,    27,
      11,    11,    90,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    71,    71,    72,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    79,
      78,    80,    81,    81,    81,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    85,    86,    87,    87,    87,    87,
      88,    88,    89,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    93,    93,
      94,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     101,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     3,     2,     2,     1,
       3,     2,     3,     4,     4,     6,     2,     2,     1,     4,
       6,     3,     1,     2,     3,     4,     2,     1,     3,     1,
       0,     2,     3,     1,     1,     2,     1,     2,     1,     0,
      10,     3,     3,     1,     0,     2,     3,     3,     2,     0,
       2,     1,     2,     1,     3,     7,     3,     4,     1,     2,
       4,     3,     8,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     2,     2,     5,     6,
       5,     4,     5,     5,     3,     3,     2,     2,     5,     5,
       3,     3,     3,     3,     3,     4,     3,     9,     7,     7,
       7,     7,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     2,     2,     1,     1,     3,     3,     3,     4,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3
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
#line 59 "parser.y"
                                                            { exit(0); }
#line 1676 "y.tab.c"
    break;

  case 6:
#line 67 "parser.y"
                                                                    { printGSymbolTable(); (yyval.node) = NULL; }
#line 1682 "y.tab.c"
    break;

  case 7:
#line 68 "parser.y"
                                                                    { (yyval.node) = NULL; }
#line 1688 "y.tab.c"
    break;

  case 8:
#line 71 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1694 "y.tab.c"
    break;

  case 9:
#line 72 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1700 "y.tab.c"
    break;

  case 10:
#line 75 "parser.y"
                                                            { addToGST((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = NULL; }
#line 1706 "y.tab.c"
    break;

  case 11:
#line 76 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1712 "y.tab.c"
    break;

  case 12:
#line 79 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1718 "y.tab.c"
    break;

  case 13:
#line 80 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewArrayNode((yyvsp[-1].node), (yyvsp[0].node))); }
#line 1724 "y.tab.c"
    break;

  case 14:
#line 81 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node))); }
#line 1730 "y.tab.c"
    break;

  case 15:
#line 82 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-5].node), createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-1].node))); }
#line 1736 "y.tab.c"
    break;

  case 16:
#line 83 "parser.y"
                                                            { (yyval.node) = createNewArrayNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1742 "y.tab.c"
    break;

  case 17:
#line 84 "parser.y"
                                                            { (yyval.node) = createNewPointerNode((yyvsp[0].node)); }
#line 1748 "y.tab.c"
    break;

  case 18:
#line 85 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1754 "y.tab.c"
    break;

  case 19:
#line 86 "parser.y"
                                                            { (yyval.node) = createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1760 "y.tab.c"
    break;

  case 20:
#line 89 "parser.y"
                                                                               { addTupleTypeToGST((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = NULL; }
#line 1766 "y.tab.c"
    break;

  case 21:
#line 92 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1772 "y.tab.c"
    break;

  case 22:
#line 93 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1778 "y.tab.c"
    break;

  case 23:
#line 96 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1784 "y.tab.c"
    break;

  case 24:
#line 99 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1790 "y.tab.c"
    break;

  case 25:
#line 100 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node))); }
#line 1796 "y.tab.c"
    break;

  case 26:
#line 101 "parser.y"
                                                            { (yyval.node) = createNewPointerNode((yyvsp[0].node)); }
#line 1802 "y.tab.c"
    break;

  case 27:
#line 102 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1808 "y.tab.c"
    break;

  case 28:
#line 105 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1814 "y.tab.c"
    break;

  case 29:
#line 106 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1820 "y.tab.c"
    break;

  case 30:
#line 107 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1826 "y.tab.c"
    break;

  case 31:
#line 110 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-1].node), (yyvsp[0].node), false, false); }
#line 1832 "y.tab.c"
    break;

  case 32:
#line 111 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-2].node), (yyvsp[0].node), false, true); }
#line 1838 "y.tab.c"
    break;

  case 33:
#line 114 "parser.y"
                                                            { (yyval.node) = createTypeNode(INT); }
#line 1844 "y.tab.c"
    break;

  case 34:
#line 115 "parser.y"
                                                            { (yyval.node) = createTypeNode(STRING); }
#line 1850 "y.tab.c"
    break;

  case 35:
#line 116 "parser.y"
                                                            { (yyval.node) = createTupleTypeNode((yyvsp[0].node)); }
#line 1856 "y.tab.c"
    break;

  case 36:
#line 117 "parser.y"
                                                            { (yyval.node) = createTypeNode(VOID); }
#line 1862 "y.tab.c"
    break;

  case 37:
#line 120 "parser.y"
                                                                        { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1868 "y.tab.c"
    break;

  case 38:
#line 121 "parser.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1874 "y.tab.c"
    break;

  case 39:
#line 125 "parser.y"
        { currentFunction = lookupGST((yyvsp[-3].node)->varName); }
#line 1880 "y.tab.c"
    break;

  case 40:
#line 127 "parser.y"
        { (yyval.node) = createFunctionDefinitionNode((yyvsp[-9].node), (yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1886 "y.tab.c"
    break;

  case 41:
#line 130 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1892 "y.tab.c"
    break;

  case 42:
#line 133 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1898 "y.tab.c"
    break;

  case 43:
#line 134 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1904 "y.tab.c"
    break;

  case 44:
#line 135 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1910 "y.tab.c"
    break;

  case 45:
#line 138 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-1].node), (yyvsp[0].node), true, false); }
#line 1916 "y.tab.c"
    break;

  case 46:
#line 139 "parser.y"
                                                            { (yyval.node) = createParamNode((yyvsp[-2].node), (yyvsp[0].node), true, true); }
#line 1922 "y.tab.c"
    break;

  case 47:
#line 142 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1928 "y.tab.c"
    break;

  case 48:
#line 143 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1934 "y.tab.c"
    break;

  case 49:
#line 144 "parser.y"
                                                            { (yyval.node) = NULL; }
#line 1940 "y.tab.c"
    break;

  case 50:
#line 147 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1946 "y.tab.c"
    break;

  case 51:
#line 148 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1952 "y.tab.c"
    break;

  case 52:
#line 149 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1958 "y.tab.c"
    break;

  case 53:
#line 150 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1964 "y.tab.c"
    break;

  case 54:
#line 153 "parser.y"
                                                            { addToLST((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = NULL; }
#line 1970 "y.tab.c"
    break;

  case 55:
#line 156 "parser.y"
                                                                            { addTupleTypeToLST((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); (yyval.node) = NULL; }
#line 1976 "y.tab.c"
    break;

  case 56:
#line 159 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1982 "y.tab.c"
    break;

  case 57:
#line 160 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node))); }
#line 1988 "y.tab.c"
    break;

  case 58:
#line 161 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 1994 "y.tab.c"
    break;

  case 59:
#line 162 "parser.y"
                                                            { (yyval.node) = createNewPointerNode((yyvsp[0].node)); }
#line 2000 "y.tab.c"
    break;

  case 60:
#line 165 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2006 "y.tab.c"
    break;

  case 61:
#line 166 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2012 "y.tab.c"
    break;

  case 62:
#line 169 "parser.y"
                                                              { generateMainCode((yyvsp[-1].node)); freeLocalSymbolTable(); (yyval.node) = NULL; }
#line 2018 "y.tab.c"
    break;

  case 63:
#line 172 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2024 "y.tab.c"
    break;

  case 64:
#line 173 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2030 "y.tab.c"
    break;

  case 65:
#line 176 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2036 "y.tab.c"
    break;

  case 66:
#line 177 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2042 "y.tab.c"
    break;

  case 67:
#line 178 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2048 "y.tab.c"
    break;

  case 68:
#line 179 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2054 "y.tab.c"
    break;

  case 69:
#line 180 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2060 "y.tab.c"
    break;

  case 70:
#line 181 "parser.y"
                                                            { (yyval.node) = createBreakNode(); }
#line 2066 "y.tab.c"
    break;

  case 71:
#line 182 "parser.y"
                                                            { (yyval.node) = createContinueNode(); }
#line 2072 "y.tab.c"
    break;

  case 72:
#line 183 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2078 "y.tab.c"
    break;

  case 73:
#line 184 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2084 "y.tab.c"
    break;

  case 74:
#line 185 "parser.y"
                                                            { (yyval.node) = createBreakPointNode(); }
#line 2090 "y.tab.c"
    break;

  case 75:
#line 186 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2096 "y.tab.c"
    break;

  case 76:
#line 187 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2102 "y.tab.c"
    break;

  case 77:
#line 190 "parser.y"
                                                            { (yyval.node) = createReturnNode((yyvsp[0].node)); }
#line 2108 "y.tab.c"
    break;

  case 78:
#line 193 "parser.y"
                                                            { (yyval.node) = createReadNode((yyvsp[-2].node)); }
#line 2114 "y.tab.c"
    break;

  case 79:
#line 194 "parser.y"
                                                            { (yyval.node) = createReadToArrayNode((yyvsp[-3].node), (yyvsp[-2].node)); }
#line 2120 "y.tab.c"
    break;

  case 80:
#line 197 "parser.y"
                                                            { (yyval.node) = createWriteNode((yyvsp[-2].node)); }
#line 2126 "y.tab.c"
    break;

  case 81:
#line 200 "parser.y"
                                                            { (yyval.node) = createAssignNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2132 "y.tab.c"
    break;

  case 82:
#line 201 "parser.y"
                                                            { (yyval.node) = createArrayAssignNode((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2138 "y.tab.c"
    break;

  case 83:
#line 202 "parser.y"
                                                            { (yyval.node) = createAssignToDereferencedNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2144 "y.tab.c"
    break;

  case 84:
#line 203 "parser.y"
                                                            { (yyval.node) = createIncrementNode((yyvsp[-2].node)); }
#line 2150 "y.tab.c"
    break;

  case 85:
#line 204 "parser.y"
                                                            { (yyval.node) = createDecrementNode((yyvsp[-2].node)); }
#line 2156 "y.tab.c"
    break;

  case 86:
#line 205 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2162 "y.tab.c"
    break;

  case 87:
#line 206 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2168 "y.tab.c"
    break;

  case 88:
#line 209 "parser.y"
                                                            { (yyval.node) = createTupleAssignmentNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2174 "y.tab.c"
    break;

  case 89:
#line 210 "parser.y"
                                                            { (yyval.node) = createTuplePointerAssignmentNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2180 "y.tab.c"
    break;

  case 90:
#line 213 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2186 "y.tab.c"
    break;

  case 91:
#line 214 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2192 "y.tab.c"
    break;

  case 92:
#line 215 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2198 "y.tab.c"
    break;

  case 93:
#line 216 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2204 "y.tab.c"
    break;

  case 94:
#line 217 "parser.y"
                                                            { (yyval.node) = createCompoundAssignNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2210 "y.tab.c"
    break;

  case 95:
#line 220 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2216 "y.tab.c"
    break;

  case 96:
#line 221 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2222 "y.tab.c"
    break;

  case 97:
#line 224 "parser.y"
                                                                                            { (yyval.node) = createIfElseNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2228 "y.tab.c"
    break;

  case 98:
#line 225 "parser.y"
                                                                                            { (yyval.node) = createIfNode((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2234 "y.tab.c"
    break;

  case 99:
#line 228 "parser.y"
                                                                                            { (yyval.node) = createWhileNode((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2240 "y.tab.c"
    break;

  case 100:
#line 231 "parser.y"
                                                                                            { (yyval.node) = createRepeatUntilNode((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 2246 "y.tab.c"
    break;

  case 101:
#line 234 "parser.y"
                                                                                            { (yyval.node) = createDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 2252 "y.tab.c"
    break;

  case 102:
#line 237 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2258 "y.tab.c"
    break;

  case 103:
#line 238 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2264 "y.tab.c"
    break;

  case 104:
#line 239 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2270 "y.tab.c"
    break;

  case 105:
#line 240 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2276 "y.tab.c"
    break;

  case 106:
#line 241 "parser.y"
                                                            { (yyval.node) = createArithOpNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2282 "y.tab.c"
    break;

  case 107:
#line 242 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2288 "y.tab.c"
    break;

  case 108:
#line 243 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2294 "y.tab.c"
    break;

  case 109:
#line 244 "parser.y"
                                                            { (yyval.node) = createVariableUsageNode((yyvsp[0].node)->varName); }
#line 2300 "y.tab.c"
    break;

  case 110:
#line 245 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2306 "y.tab.c"
    break;

  case 111:
#line 246 "parser.y"
                                                            { (yyval.node) = createArrayAccessNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2312 "y.tab.c"
    break;

  case 112:
#line 247 "parser.y"
                                                            { (yyval.node) = createDereferenceNode((yyvsp[0].node)); }
#line 2318 "y.tab.c"
    break;

  case 113:
#line 248 "parser.y"
                                                            { (yyval.node) = createAddressToNode((yyvsp[0].node)); }
#line 2324 "y.tab.c"
    break;

  case 114:
#line 249 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2330 "y.tab.c"
    break;

  case 115:
#line 250 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2336 "y.tab.c"
    break;

  case 116:
#line 253 "parser.y"
                                                            { (yyval.node) = createTupleAccessNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2342 "y.tab.c"
    break;

  case 117:
#line 254 "parser.y"
                                                            { (yyval.node) = createTuplePointerAccessNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2348 "y.tab.c"
    break;

  case 118:
#line 257 "parser.y"
                                                            { (yyval.node) = createFunctionCallNode((yyvsp[-2].node), NULL); }
#line 2354 "y.tab.c"
    break;

  case 119:
#line 258 "parser.y"
                                                            { (yyval.node) = createFunctionCallNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2360 "y.tab.c"
    break;

  case 120:
#line 260 "parser.y"
                                                            { (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2366 "y.tab.c"
    break;

  case 121:
#line 261 "parser.y"
                                                            { (yyval.node) = (yyvsp[0].node); }
#line 2372 "y.tab.c"
    break;

  case 122:
#line 264 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2378 "y.tab.c"
    break;

  case 123:
#line 265 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2384 "y.tab.c"
    break;

  case 124:
#line 266 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2390 "y.tab.c"
    break;

  case 125:
#line 267 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2396 "y.tab.c"
    break;

  case 126:
#line 268 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2402 "y.tab.c"
    break;

  case 127:
#line 269 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2408 "y.tab.c"
    break;

  case 128:
#line 270 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2414 "y.tab.c"
    break;

  case 129:
#line 271 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2420 "y.tab.c"
    break;

  case 130:
#line 272 "parser.y"
                                                            { (yyval.node) = createConditionNode(NODE_NOT, (yyvsp[0].node), NULL); }
#line 2426 "y.tab.c"
    break;

  case 131:
#line 273 "parser.y"
                                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2432 "y.tab.c"
    break;


#line 2436 "y.tab.c"

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
#line 276 "parser.y"


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

    return yyparse();
}
