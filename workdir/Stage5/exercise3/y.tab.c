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

#include "code_gen/code_gen.h"
#include "define/constants.h"
#include "g_symbol_table/g_symbol_table.h"
#include "local_symbol_table/local_symbol_table.h"
#include "node/node.h"
#include "util/util.h"
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char const *msg);

FILE *target_file;
extern FILE *yyin;
extern int lineNumber;
extern char *yytext;

#line 89 "y.tab.c"

#ifndef YY_CAST
#ifdef __cplusplus
#define YY_CAST(Type, Val) static_cast<Type>(Val)
#define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type>(Val)
#else
#define YY_CAST(Type, Val) ((Type)(Val))
#define YY_REINTERPRET_CAST(Type, Val) ((Type)(Val))
#endif
#endif
#ifndef YY_NULLPTR
#if defined __cplusplus
#if 201103L <= __cplusplus
#define YY_NULLPTR nullptr
#else
#define YY_NULLPTR 0
#endif
#else
#define YY_NULLPTR ((void *)0)
#endif
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
#undef YYERROR_VERBOSE
#define YYERROR_VERBOSE 1
#else
#define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
#define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype {
    NUM = 258,
    ID = 259,
    STRING_LITERAL = 260,
    READ = 261,
    WRITE = 262,
    PLUS = 263,
    MUL = 264,
    MINUS = 265,
    DIV = 266,
    MOD = 267,
    ASSIGN = 268,
    SEMI = 269,
    AMPERSAND = 270,
    GT = 271,
    GE = 272,
    LT = 273,
    LE = 274,
    NE = 275,
    EQ = 276,
    KW_BEGIN = 277,
    KW_END = 278,
    KW_IF = 279,
    KW_THEN = 280,
    KW_ELSE = 281,
    KW_ENDIF = 282,
    KW_WHILE = 283,
    KW_DO = 284,
    KW_ENDWHILE = 285,
    KW_BREAK = 286,
    KW_CONTINUE = 287,
    KW_REPEAT = 288,
    KW_UNTIL = 289,
    KW_DECL = 290,
    KW_ENDDECL = 291,
    TYPE_INT = 292,
    TYPE_STRING = 293,
    COMMA = 294,
    AND = 295,
    OR = 296,
    NOT = 297,
    INCREMENT = 298,
    DECREMENT = 299,
    ASSIGN_ADD = 300,
    ASSIGN_SUB = 301,
    ASSIGN_MUL = 302,
    ASSIGN_DIV = 303,
    ASSIGN_MOD = 304,
    KW_RETURN = 305,
    MAIN = 306,
    KW_BRKP = 307,
    KW_TUPLE = 308,
    DOT = 309,
    ARROW = 310
};
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define STRING_LITERAL 260
#define READ 261
#define WRITE 262
#define PLUS 263
#define MUL 264
#define MINUS 265
#define DIV 266
#define MOD 267
#define ASSIGN 268
#define SEMI 269
#define AMPERSAND 270
#define GT 271
#define GE 272
#define LT 273
#define LE 274
#define NE 275
#define EQ 276
#define KW_BEGIN 277
#define KW_END 278
#define KW_IF 279
#define KW_THEN 280
#define KW_ELSE 281
#define KW_ENDIF 282
#define KW_WHILE 283
#define KW_DO 284
#define KW_ENDWHILE 285
#define KW_BREAK 286
#define KW_CONTINUE 287
#define KW_REPEAT 288
#define KW_UNTIL 289
#define KW_DECL 290
#define KW_ENDDECL 291
#define TYPE_INT 292
#define TYPE_STRING 293
#define COMMA 294
#define AND 295
#define OR 296
#define NOT 297
#define INCREMENT 298
#define DECREMENT 299
#define ASSIGN_ADD 300
#define ASSIGN_SUB 301
#define ASSIGN_MUL 302
#define ASSIGN_DIV 303
#define ASSIGN_MOD 304
#define KW_RETURN 305
#define MAIN 306
#define KW_BRKP 307
#define KW_TUPLE 308
#define DOT 309
#define ARROW 310

/* Value type.  */
#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
union YYSTYPE {
#line 20 "parser.y"

    struct tnode *node;

#line 255 "y.tab.c"
};
typedef union YYSTYPE YYSTYPE;
#define YYSTYPE_IS_TRIVIAL 1
#define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

int yyparse(void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

#ifdef short
#undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
#include <limits.h> /* INFRINGES ON USER NAME SPACE */
#if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#define YY_STDINT_H
#endif
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
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
#if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#define YYPTRDIFF_T __PTRDIFF_TYPE__
#define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
#elif defined PTRDIFF_MAX
#ifndef ptrdiff_t
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#endif
#define YYPTRDIFF_T ptrdiff_t
#define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
#else
#define YYPTRDIFF_T long
#define YYPTRDIFF_MAXIMUM LONG_MAX
#endif
#endif

#ifndef YYSIZE_T
#ifdef __SIZE_TYPE__
#define YYSIZE_T __SIZE_TYPE__
#elif defined size_t
#define YYSIZE_T size_t
#elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#define YYSIZE_T size_t
#else
#define YYSIZE_T unsigned
#endif
#endif

#define YYSIZE_MAXIMUM                                 \
    YY_CAST(YYPTRDIFF_T,                               \
            (YYPTRDIFF_MAXIMUM < YY_CAST(YYSIZE_T, -1) \
                 ? YYPTRDIFF_MAXIMUM                   \
                 : YY_CAST(YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST(YYPTRDIFF_T, sizeof(X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
#if defined YYENABLE_NLS && YYENABLE_NLS
#if ENABLE_NLS
#include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#define YY_(Msgid) dgettext("bison-runtime", Msgid)
#endif
#endif
#ifndef YY_
#define YY_(Msgid) Msgid
#endif
#endif

#ifndef YY_ATTRIBUTE_PURE
#if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#define YY_ATTRIBUTE_PURE __attribute__((__pure__))
#else
#define YY_ATTRIBUTE_PURE
#endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
#if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#define YY_ATTRIBUTE_UNUSED __attribute__((__unused__))
#else
#define YY_ATTRIBUTE_UNUSED
#endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
#define YYUSE(E) ((void)(E))
#else
#define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && !defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                   \
    _Pragma("GCC diagnostic push")                            \
        _Pragma("GCC diagnostic ignored \"-Wuninitialized\"") \
            _Pragma("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
#define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma("GCC diagnostic pop")
#else
#define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
#define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
#define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && !defined __ICC && 6 <= __GNUC__
#define YY_IGNORE_USELESS_CAST_BEGIN \
    _Pragma("GCC diagnostic push")   \
        _Pragma("GCC diagnostic ignored \"-Wuseless-cast\"")
#define YY_IGNORE_USELESS_CAST_END \
    _Pragma("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
#define YY_IGNORE_USELESS_CAST_BEGIN
#define YY_IGNORE_USELESS_CAST_END
#endif

#define YY_ASSERT(E) ((void)(0 && (E)))

#if !defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#ifdef YYSTACK_USE_ALLOCA
#if YYSTACK_USE_ALLOCA
#ifdef __GNUC__
#define YYSTACK_ALLOC __builtin_alloca
#elif defined __BUILTIN_VA_ARG_INCR
#include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#elif defined _AIX
#define YYSTACK_ALLOC __alloca
#elif defined _MSC_VER
#include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#define alloca _alloca
#else
#define YYSTACK_ALLOC alloca
#if !defined _ALLOCA_H && !defined EXIT_SUCCESS
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
/* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#endif
#endif
#endif
#endif

#ifdef YYSTACK_ALLOC
/* Pacify GCC's 'empty if-body' warning.  */
#define YYSTACK_FREE(Ptr) \
    do { /* empty */      \
        ;                 \
    } while (0)
#ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
   and a page size can be as small as 4096 bytes.  So we cannot safely
   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
   to allow for a few compiler-allocated temporary stack slots.  */
#define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#endif
#else
#define YYSTACK_ALLOC YYMALLOC
#define YYSTACK_FREE YYFREE
#ifndef YYSTACK_ALLOC_MAXIMUM
#define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#endif
#if (defined __cplusplus && !defined EXIT_SUCCESS && !((defined YYMALLOC || defined malloc) && (defined YYFREE || defined free)))
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#endif
#ifndef YYMALLOC
#define YYMALLOC malloc
#if !defined malloc && !defined EXIT_SUCCESS
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#ifndef YYFREE
#define YYFREE free
#if !defined free && !defined EXIT_SUCCESS
void free(void *); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

#if (!defined yyoverflow && (!defined __cplusplus || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc {
    yy_state_t yyss_alloc;
    YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
#define YYSTACK_GAP_MAXIMUM (YYSIZEOF(union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
#define YYSTACK_BYTES(N) \
    ((N) * (YYSIZEOF(yy_state_t) + YYSIZEOF(YYSTYPE)) + YYSTACK_GAP_MAXIMUM)

#define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
#define YYSTACK_RELOCATE(Stack_alloc, Stack)                               \
    do {                                                                   \
        YYPTRDIFF_T yynewbytes;                                            \
        YYCOPY(&yyptr->Stack_alloc, Stack, yysize);                        \
        Stack = &yyptr->Stack_alloc;                                       \
        yynewbytes = yystacksize * YYSIZEOF(*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF(*yyptr);                            \
    } while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
#ifndef YYCOPY
#if defined __GNUC__ && 1 < __GNUC__
#define YYCOPY(Dst, Src, Count) \
    __builtin_memcpy(Dst, Src, YY_CAST(YYSIZE_T, (Count)) * sizeof(*(Src)))
#else
#define YYCOPY(Dst, Src, Count)             \
    do {                                    \
        YYPTRDIFF_T yyi;                    \
        for (yyi = 0; yyi < (Count); yyi++) \
            (Dst)[yyi] = (Src)[yyi];        \
    } while (0)
#endif
#endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 44
/* YYNRULES -- Number of rules.  */
#define YYNRULES 128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES 292

#define YYUNDEFTOK 2
#define YYMAXUTOK 310

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX) \
    (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
    {
        0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        56, 57, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 60, 2, 61, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 58, 2, 59, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
        5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
        35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
        45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
        55};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
    {
        0, 57, 57, 60, 63, 68, 75, 78, 79, 82,
        83, 86, 87, 88, 89, 90, 91, 92, 93, 96,
        99, 100, 103, 106, 107, 108, 109, 112, 113, 114,
        117, 118, 121, 122, 123, 126, 127, 131, 130, 136,
        139, 140, 141, 144, 145, 148, 149, 152, 153, 154,
        155, 158, 161, 164, 165, 166, 167, 170, 171, 174,
        177, 178, 181, 182, 183, 184, 185, 186, 187, 188,
        189, 190, 191, 192, 195, 198, 199, 202, 205, 206,
        207, 208, 209, 210, 211, 214, 215, 218, 219, 220,
        221, 222, 225, 226, 229, 230, 233, 236, 239, 242,
        243, 244, 245, 246, 247, 248, 249, 250, 251, 252,
        253, 254, 255, 258, 259, 262, 263, 265, 266, 269,
        270, 271, 272, 273, 274, 275, 276, 277, 278};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
    {
        "$end", "error", "$undefined", "NUM", "ID", "STRING_LITERAL", "READ",
        "WRITE", "PLUS", "MUL", "MINUS", "DIV", "MOD", "ASSIGN", "SEMI",
        "AMPERSAND", "GT", "GE", "LT", "LE", "NE", "EQ", "KW_BEGIN", "KW_END",
        "KW_IF", "KW_THEN", "KW_ELSE", "KW_ENDIF", "KW_WHILE", "KW_DO",
        "KW_ENDWHILE", "KW_BREAK", "KW_CONTINUE", "KW_REPEAT", "KW_UNTIL",
        "KW_DECL", "KW_ENDDECL", "TYPE_INT", "TYPE_STRING", "COMMA", "AND", "OR",
        "NOT", "INCREMENT", "DECREMENT", "ASSIGN_ADD", "ASSIGN_SUB",
        "ASSIGN_MUL", "ASSIGN_DIV", "ASSIGN_MOD", "KW_RETURN", "MAIN", "KW_BRKP",
        "KW_TUPLE", "DOT", "ARROW", "'('", "')'", "'{'", "'}'", "'['", "']'",
        "$accept", "program", "globalDeclarationsBlock", "globalDeclarationList",
        "globalDecl", "globalVarList", "globalTupleDeclaration",
        "tupleParamList", "tupleParam", "tupleIdList", "funcDeclParamList",
        "funcDeclParam", "type", "functionDefinitionBlock", "functionDefinition",
        "$@1", "body", "paramList", "param", "localDeclBlock", "localDeclList",
        "localDecl", "localTupleDecl", "idList", "dimensionDecl", "mainBlock",
        "statementList", "statement", "returnStatement", "inputStatement",
        "outputStatement", "assignmentStatement", "tupleAssignmentStatement",
        "compoundAssignment", "dimensionUsage", "ifStatement", "whileStatement",
        "repeatUntilStatement", "doWhileStatement", "expr", "tupleAccess",
        "functionCall", "argList", "boolexpr", YY_NULLPTR};
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
    {
        0, 256, 257, 258, 259, 260, 261, 262, 263, 264,
        265, 266, 267, 268, 269, 270, 271, 272, 273, 274,
        275, 276, 277, 278, 279, 280, 281, 282, 283, 284,
        285, 286, 287, 288, 289, 290, 291, 292, 293, 294,
        295, 296, 297, 298, 299, 300, 301, 302, 303, 304,
        305, 306, 307, 308, 309, 310, 40, 41, 123, 125,
        91, 93};
#endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
    ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
    0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
    {
        50, 84, -40, 17, 223, -151, -151, -151, -151, 45,
        299, -151, 54, 75, 52, -151, -40, 102, 125, 223,
        -151, -151, 98, -151, -151, -151, -19, 127, -5, 108,
        -151, 99, -151, -151, 265, 265, 138, 115, -151, -151,
        131, 130, 265, -17, -151, 193, 33, -151, 190, 143,
        212, -13, 217, 202, 287, 34, -151, 265, 301, -151,
        265, -151, -151, 237, -151, 182, 265, 115, -151, 311,
        228, -151, 250, 265, -151, -151, -151, 259, 225, -151,
        -151, -151, 37, -151, 261, 312, 320, -151, -151, 291,
        215, -151, -151, 227, -151, 329, -151, 219, -151, 279,
        -1, -151, -151, -151, 135, 236, 258, 289, 269, 271,
        291, 292, 303, 291, 129, 326, 207, -151, 352, -151,
        -151, -151, 372, 379, -151, -151, -151, -151, 386, -151,
        202, -151, 290, 265, -151, -151, 330, 129, 388, 389,
        129, 129, 129, 129, 129, 397, 400, 3, 129, 10,
        401, 129, 393, 11, 11, 322, -151, -151, 238, -151,
        152, -151, 403, 404, 129, 387, -151, -151, -151, -151,
        -151, -151, -151, -151, -151, 228, -151, 38, -151, 405,
        351, -151, -151, 387, 387, 387, 387, 387, 398, 399,
        -151, 387, 42, 46, 129, 129, 18, 107, 129, 11,
        11, 359, 106, 169, 354, 357, 410, 411, 356, -151,
        -151, 162, 129, 129, 129, 129, 129, 358, 301, -151,
        -151, 129, 129, 129, -151, -151, 373, 53, 406, 85,
        407, 380, -151, 141, 177, 129, 129, 129, 129, 129,
        129, 11, 11, 394, 395, 11, 11, -151, -151, -151,
        333, -151, 333, -151, -151, -151, 5, 387, 387, 387,
        -151, -151, -151, 408, -151, -151, -151, 387, 387, 387,
        387, 387, 387, -151, 378, 291, 291, 192, 211, -151,
        -151, 196, 249, 19, 409, 291, -151, -151, -151, -151,
        280, -151};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
    {
        0, 0, 0, 0, 0, 4, 6, 32, 33, 0,
        0, 8, 0, 0, 0, 1, 32, 0, 0, 0,
        36, 3, 34, 5, 7, 10, 17, 0, 0, 0,
        34, 0, 35, 2, 0, 29, 0, 15, 16, 9,
        0, 0, 42, 0, 21, 0, 0, 28, 0, 0,
        0, 11, 0, 0, 0, 0, 41, 0, 0, 22,
        0, 18, 30, 0, 58, 0, 29, 12, 13, 0,
        0, 43, 0, 0, 37, 20, 26, 0, 19, 27,
        31, 57, 0, 46, 0, 0, 0, 48, 50, 0,
        0, 44, 40, 0, 25, 0, 14, 34, 55, 0,
        0, 45, 47, 49, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 61, 0, 62,
        63, 64, 0, 0, 65, 66, 69, 70, 0, 59,
        0, 23, 0, 0, 56, 51, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 67, 68, 0, 105,
        106, 107, 0, 0, 0, 74, 112, 111, 71, 39,
        60, 73, 84, 83, 72, 0, 24, 0, 53, 0,
        0, 81, 82, 87, 88, 89, 90, 91, 0, 0,
        115, 118, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 108, 109,
        110, 0, 0, 0, 0, 0, 0, 0, 0, 54,
        78, 0, 0, 0, 116, 93, 0, 0, 0, 0,
        0, 0, 127, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 113, 114, 104,
        99, 101, 100, 102, 103, 38, 0, 85, 86, 117,
        79, 92, 75, 0, 77, 80, 128, 122, 121, 120,
        119, 123, 124, 126, 125, 0, 0, 0, 0, 52,
        76, 0, 0, 0, 0, 0, 95, 96, 98, 97,
        0, 94};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
    {
        -151, -151, -151, -151, 415, -151, -151, 293, 370, 210,
        363, 371, 70, -151, 413, -151, 255, -151, 360, 304,
        -151, 349, 350, -151, 390, 94, -109, -113, -151, -151,
        -151, -151, -151, -151, -150, -151, -151, -151, -151, -112,
        -151, -89, -151, -149};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
    {
        -1, 3, 4, 10, 11, 28, 12, 43, 44, 78,
        46, 47, 45, 19, 20, 93, 90, 55, 56, 70,
        86, 87, 88, 100, 37, 5, 116, 117, 118, 119,
        120, 121, 122, 123, 149, 124, 125, 126, 127, 201,
        166, 167, 192, 202};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
    {
        128, 155, 165, 170, 158, 203, 159, 160, 161, 39,
        208, 14, 162, 135, 159, 160, 161, 15, 163, 279,
        162, 128, 57, 194, 128, 180, 163, 128, 183, 184,
        185, 186, 187, 288, 40, 191, 193, 35, 136, 197,
        58, 36, 170, 66, 95, 170, 229, 36, 276, 22,
        232, 234, 211, 199, 212, 213, 214, 215, 216, 164,
        190, 212, 213, 214, 215, 216, 128, 200, 25, 128,
        195, 13, 60, 73, 18, 228, 60, 57, 148, 26,
        13, 223, 226, 227, 27, 1, 231, 2, 233, 18,
        61, 74, 273, 274, 96, 218, 277, 278, 21, 224,
        250, 251, 252, 253, 254, 48, 30, 225, 29, 257,
        258, 259, 54, 33, 261, 212, 213, 214, 215, 216,
        6, 7, 8, 267, 268, 269, 270, 271, 272, 31,
        48, 38, 159, 160, 161, 51, 48, 9, 162, 85,
        52, 49, 263, 54, 163, 195, 241, 242, 137, 212,
        213, 214, 215, 216, 34, 42, 85, 235, 236, 237,
        238, 239, 240, 243, 230, 41, 281, 282, 170, 170,
        212, 213, 214, 215, 216, 50, 290, 170, 138, 139,
        140, 141, 142, 143, 144, 164, 128, 128, 53, 145,
        146, 147, 128, 128, 62, 148, 128, 59, 249, 63,
        104, 128, 105, 106, 64, 107, 206, 207, 147, 241,
        242, 104, 148, 105, 106, 65, 107, 241, 242, 249,
        108, 68, 285, 286, 109, 110, 244, 111, 112, 113,
        169, 108, 241, 242, 266, 109, 110, 69, 111, 112,
        113, 80, 104, 81, 105, 106, 114, 107, 115, 283,
        89, 241, 242, 104, 91, 105, 106, 114, 107, 115,
        16, 8, 108, 94, 95, 97, 109, 110, 284, 111,
        112, 113, 205, 108, 129, 133, 17, 109, 110, 287,
        111, 112, 113, 134, 104, 130, 105, 106, 114, 107,
        115, 71, 150, 152, 176, 104, 72, 105, 106, 114,
        107, 115, 7, 8, 108, 76, 156, 291, 109, 110,
        77, 111, 112, 113, 151, 108, 98, 157, 17, 109,
        110, 99, 111, 112, 113, 153, 104, 154, 105, 106,
        114, 107, 115, 131, 178, 23, 7, 8, 132, 179,
        168, 114, 213, 115, 215, 216, 108, 83, 7, 8,
        204, 110, 9, 111, 112, 113, 101, 7, 8, 212,
        213, 214, 215, 216, 84, 220, 171, 212, 213, 214,
        215, 216, 114, 84, 115, 235, 236, 237, 238, 239,
        240, 212, 213, 214, 215, 216, 172, 260, 212, 213,
        214, 215, 216, 173, 265, 212, 213, 214, 215, 216,
        174, 188, 181, 182, 189, 196, 198, 209, 210, 219,
        245, 221, 222, 246, 247, 248, 195, 255, 241, 275,
        262, 264, 280, 289, 276, 24, 177, 75, 256, 82,
        217, 79, 32, 92, 175, 102, 103, 0, 0, 0,
        0, 67};

static const yytype_int16 yycheck[] =
    {
        89, 110, 114, 116, 113, 154, 3, 4, 5, 14,
        160, 51, 9, 14, 3, 4, 5, 0, 15, 14,
        9, 110, 39, 13, 113, 137, 15, 116, 140, 141,
        142, 143, 144, 14, 39, 147, 148, 56, 39, 151,
        57, 60, 155, 56, 39, 158, 196, 60, 29, 4,
        199, 200, 164, 42, 8, 9, 10, 11, 12, 56,
        57, 8, 9, 10, 11, 12, 155, 56, 14, 158,
        60, 1, 39, 39, 4, 57, 39, 39, 60, 4,
        10, 39, 194, 195, 9, 35, 198, 37, 200, 19,
        57, 57, 241, 242, 57, 57, 245, 246, 4, 57,
        212, 213, 214, 215, 216, 35, 4, 61, 56, 221,
        222, 223, 42, 19, 61, 8, 9, 10, 11, 12,
        36, 37, 38, 235, 236, 237, 238, 239, 240, 4,
        60, 4, 3, 4, 5, 4, 66, 53, 9, 69,
        9, 3, 57, 73, 15, 60, 40, 41, 13, 8,
        9, 10, 11, 12, 56, 56, 86, 16, 17, 18,
        19, 20, 21, 57, 57, 57, 275, 276, 281, 282,
        8, 9, 10, 11, 12, 60, 285, 290, 43, 44,
        45, 46, 47, 48, 49, 56, 275, 276, 58, 54,
        55, 56, 281, 282, 4, 60, 285, 4, 57, 9,
        4, 290, 6, 7, 61, 9, 54, 55, 56, 40,
        41, 4, 60, 6, 7, 3, 9, 40, 41, 57,
        24, 4, 26, 27, 28, 29, 57, 31, 32, 33,
        23, 24, 40, 41, 57, 28, 29, 35, 31, 32,
        33, 4, 4, 61, 6, 7, 50, 9, 52, 57,
        22, 40, 41, 4, 4, 6, 7, 50, 9, 52,
        37, 38, 24, 4, 39, 4, 28, 29, 57, 31,
        32, 33, 34, 24, 59, 56, 53, 28, 29, 30,
        31, 32, 33, 4, 4, 58, 6, 7, 50, 9,
        52, 4, 56, 4, 4, 4, 9, 6, 7, 50,
        9, 52, 37, 38, 24, 4, 14, 27, 28, 29,
        9, 31, 32, 33, 56, 24, 4, 14, 53, 28,
        29, 9, 31, 32, 33, 56, 4, 56, 6, 7,
        50, 9, 52, 4, 4, 36, 37, 38, 9, 9,
        14, 50, 9, 52, 11, 12, 24, 36, 37, 38,
        28, 29, 53, 31, 32, 33, 36, 37, 38, 8,
        9, 10, 11, 12, 53, 14, 14, 8, 9, 10,
        11, 12, 50, 53, 52, 16, 17, 18, 19, 20,
        21, 8, 9, 10, 11, 12, 14, 14, 8, 9,
        10, 11, 12, 14, 14, 8, 9, 10, 11, 12,
        14, 4, 14, 14, 4, 4, 13, 4, 4, 4,
        56, 13, 13, 56, 4, 4, 60, 59, 40, 25,
        14, 14, 14, 14, 29, 10, 133, 57, 218, 66,
        175, 60, 19, 73, 130, 86, 86, -1, -1, -1,
        -1, 51};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
    {
        0, 35, 37, 63, 64, 87, 36, 37, 38, 53,
        65, 66, 68, 74, 51, 0, 37, 53, 74, 75,
        76, 87, 4, 36, 66, 14, 4, 9, 67, 56,
        4, 4, 76, 87, 56, 56, 60, 86, 4, 14,
        39, 57, 56, 69, 70, 74, 72, 73, 74, 3,
        60, 4, 9, 58, 74, 79, 80, 39, 57, 4,
        39, 57, 4, 9, 61, 3, 56, 86, 4, 35,
        81, 4, 9, 39, 57, 70, 4, 9, 71, 73,
        4, 61, 72, 36, 53, 74, 82, 83, 84, 22,
        78, 4, 80, 77, 4, 39, 57, 4, 4, 9,
        85, 36, 83, 84, 4, 6, 7, 9, 24, 28,
        29, 31, 32, 33, 50, 52, 88, 89, 90, 91,
        92, 93, 94, 95, 97, 98, 99, 100, 103, 59,
        58, 4, 9, 56, 4, 14, 39, 13, 43, 44,
        45, 46, 47, 48, 49, 54, 55, 56, 60, 96,
        56, 56, 4, 56, 56, 88, 14, 14, 88, 3,
        4, 5, 9, 15, 56, 101, 102, 103, 14, 23,
        89, 14, 14, 14, 14, 81, 4, 69, 4, 9,
        101, 14, 14, 101, 101, 101, 101, 101, 4, 4,
        57, 101, 104, 101, 13, 60, 4, 101, 13, 42,
        56, 101, 105, 105, 28, 34, 54, 55, 96, 4,
        4, 101, 8, 9, 10, 11, 12, 78, 57, 4,
        14, 13, 13, 39, 57, 61, 101, 101, 57, 96,
        57, 101, 105, 101, 105, 16, 17, 18, 19, 20,
        21, 40, 41, 57, 57, 56, 56, 4, 4, 57,
        101, 101, 101, 101, 101, 59, 71, 101, 101, 101,
        14, 61, 14, 57, 14, 14, 57, 101, 101, 101,
        101, 101, 101, 105, 105, 25, 29, 105, 105, 14,
        14, 88, 88, 57, 57, 26, 27, 30, 14, 14,
        88, 27};

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
    {
        0, 62, 63, 63, 63, 64, 64, 65, 65, 66,
        66, 67, 67, 67, 67, 67, 67, 67, 67, 68,
        69, 69, 70, 71, 71, 71, 71, 72, 72, 72,
        73, 73, 74, 74, 74, 75, 75, 77, 76, 78,
        79, 79, 79, 80, 80, 81, 81, 82, 82, 82,
        82, 83, 84, 85, 85, 85, 85, 86, 86, 87,
        88, 88, 89, 89, 89, 89, 89, 89, 89, 89,
        89, 89, 89, 89, 90, 91, 91, 92, 93, 93,
        93, 93, 93, 93, 93, 94, 94, 95, 95, 95,
        95, 95, 96, 96, 97, 97, 98, 99, 100, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 102, 102, 103, 103, 104, 104, 105,
        105, 105, 105, 105, 105, 105, 105, 105, 105};

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
    {
        0, 2, 3, 2, 1, 3, 2, 2, 1, 3,
        2, 3, 4, 4, 6, 2, 2, 1, 4, 6,
        3, 1, 2, 3, 4, 2, 1, 3, 1, 0,
        2, 3, 1, 1, 2, 2, 1, 0, 10, 3,
        3, 1, 0, 2, 3, 3, 2, 2, 1, 2,
        1, 3, 7, 3, 4, 1, 2, 4, 3, 8,
        2, 1, 1, 1, 1, 1, 1, 2, 2, 1,
        1, 2, 2, 2, 2, 5, 6, 5, 4, 5,
        5, 3, 3, 2, 2, 5, 5, 3, 3, 3,
        3, 3, 4, 3, 9, 7, 7, 7, 7, 3,
        3, 3, 3, 3, 3, 1, 1, 1, 2, 2,
        2, 1, 1, 3, 3, 3, 4, 3, 1, 3,
        3, 3, 3, 3, 3, 3, 3, 2, 3};

#define yyerrok (yyerrstatus = 0)
#define yyclearin (yychar = YYEMPTY)
#define YYEMPTY (-2)
#define YYEOF 0

#define YYACCEPT goto yyacceptlab
#define YYABORT goto yyabortlab
#define YYERROR goto yyerrorlab

#define YYRECOVERING() (!!yyerrstatus)

#define YYBACKUP(Token, Value)                            \
    do                                                    \
        if (yychar == YYEMPTY) {                          \
            yychar = (Token);                             \
            yylval = (Value);                             \
            YYPOPSTACK(yylen);                            \
            yystate = *yyssp;                             \
            goto yybackup;                                \
        } else {                                          \
            yyerror(YY_("syntax error: cannot back up")); \
            YYERROR;                                      \
        }                                                 \
    while (0)

/* Error token number */
#define YYTERROR 1
#define YYERRCODE 256

/* Enable debugging if requested.  */
#if YYDEBUG

#ifndef YYFPRINTF
#include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#define YYFPRINTF fprintf
#endif

#define YYDPRINTF(Args)     \
    do {                    \
        if (yydebug)        \
            YYFPRINTF Args; \
    } while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
#define YY_LOCATION_PRINT(File, Loc) ((void)0)
#endif

#define YY_SYMBOL_PRINT(Title, Type, Value, Location) \
    do {                                              \
        if (yydebug) {                                \
            YYFPRINTF(stderr, "%s ", Title);          \
            yy_symbol_print(stderr,                   \
                            Type, Value);             \
            YYFPRINTF(stderr, "\n");                  \
        }                                             \
    } while (0)

/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print(FILE *yyo, int yytype, YYSTYPE const *const yyvaluep) {
    FILE *yyoutput = yyo;
    YYUSE(yyoutput);
    if (!yyvaluep)
        return;
#ifdef YYPRINT
    if (yytype < YYNTOKENS)
        YYPRINT(yyo, yytoknum[yytype], *yyvaluep);
#endif
    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YYUSE(yytype);
    YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print(FILE *yyo, int yytype, YYSTYPE const *const yyvaluep) {
    YYFPRINTF(yyo, "%s %s (",
              yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

    yy_symbol_value_print(yyo, yytype, yyvaluep);
    YYFPRINTF(yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print(yy_state_t *yybottom, yy_state_t *yytop) {
    YYFPRINTF(stderr, "Stack now");
    for (; yybottom <= yytop; yybottom++) {
        int yybot = *yybottom;
        YYFPRINTF(stderr, " %d", yybot);
    }
    YYFPRINTF(stderr, "\n");
}

#define YY_STACK_PRINT(Bottom, Top)          \
    do {                                     \
        if (yydebug)                         \
            yy_stack_print((Bottom), (Top)); \
    } while (0)

/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print(yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule) {
    int yylno = yyrline[yyrule];
    int yynrhs = yyr2[yyrule];
    int yyi;
    YYFPRINTF(stderr, "Reducing stack by rule %d (line %d):\n",
              yyrule - 1, yylno);
    /* The symbols being reduced.  */
    for (yyi = 0; yyi < yynrhs; yyi++) {
        YYFPRINTF(stderr, "   $%d = ", yyi + 1);
        yy_symbol_print(stderr,
                        yystos[+yyssp[yyi + 1 - yynrhs]],
                        &yyvsp[(yyi + 1) - (yynrhs)]);
        YYFPRINTF(stderr, "\n");
    }
}

#define YY_REDUCE_PRINT(Rule)                    \
    do {                                         \
        if (yydebug)                             \
            yy_reduce_print(yyssp, yyvsp, Rule); \
    } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
#define YYDPRINTF(Args)
#define YY_SYMBOL_PRINT(Title, Type, Value, Location)
#define YY_STACK_PRINT(Bottom, Top)
#define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if YYERROR_VERBOSE

#ifndef yystrlen
#if defined __GLIBC__ && defined _STRING_H
#define yystrlen(S) (YY_CAST(YYPTRDIFF_T, strlen(S)))
#else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen(const char *yystr) {
    YYPTRDIFF_T yylen;
    for (yylen = 0; yystr[yylen]; yylen++)
        continue;
    return yylen;
}
#endif
#endif

#ifndef yystpcpy
#if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#define yystpcpy stpcpy
#else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy(char *yydest, const char *yysrc) {
    char *yyd = yydest;
    const char *yys = yysrc;

    while ((*yyd++ = *yys++) != '\0')
        continue;

    return yyd - 1;
}
#endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr(char *yyres, const char *yystr) {
    if (*yystr == '"') {
        YYPTRDIFF_T yyn = 0;
        char const *yyp = yystr;

        for (;;)
            switch (*++yyp) {
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
    do_not_strip_quotes:;
    }

    if (yyres)
        return yystpcpy(yyres, yystr) - yyres;
    else
        return yystrlen(yystr);
}
#endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error(YYPTRDIFF_T *yymsg_alloc, char **yymsg,
               yy_state_t *yyssp, int yytoken) {
    enum {
        YYERROR_VERBOSE_ARGS_MAXIMUM = 5
    };
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
    if (yytoken != YYEMPTY) {
        int yyn = yypact[+*yyssp];
        YYPTRDIFF_T yysize0 = yytnamerr(YY_NULLPTR, yytname[yytoken]);
        yysize = yysize0;
        yyarg[yycount++] = yytname[yytoken];
        if (!yypact_value_is_default(yyn)) {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = YYLAST - yyn + 1;
            int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
            int yyx;

            for (yyx = yyxbegin; yyx < yyxend; ++yyx)
                if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR && !yytable_value_is_error(yytable[yyx + yyn])) {
                    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM) {
                        yycount = 1;
                        yysize = yysize0;
                        break;
                    }
                    yyarg[yycount++] = yytname[yyx];
                    {
                        YYPTRDIFF_T yysize1 = yysize + yytnamerr(YY_NULLPTR, yytname[yyx]);
                        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                            yysize = yysize1;
                        else
                            return 2;
                    }
                }
        }
    }

    switch (yycount) {
#define YYCASE_(N, S) \
    case N:           \
        yyformat = S; \
        break
    default: /* Avoid compiler warnings. */
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

    {
        /* Don't count the "%s"s in the final size, but reserve room for
           the terminator.  */
        YYPTRDIFF_T yysize1 = yysize + (yystrlen(yyformat) - 2 * yycount) + 1;
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
            yysize = yysize1;
        else
            return 2;
    }

    if (*yymsg_alloc < yysize) {
        *yymsg_alloc = 2 * yysize;
        if (!(yysize <= *yymsg_alloc && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
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
            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount) {
                yyp += yytnamerr(yyp, yyarg[yyi++]);
                yyformat += 2;
            } else {
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
yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep) {
    YYUSE(yyvaluep);
    if (!yymsg)
        yymsg = "Deleting";
    YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YYUSE(yytype);
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

int yyparse(void) {
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

#define YYPOPSTACK(N) (yyvsp -= (N), yyssp -= (N))

    /* The number of symbols on the RHS of the reduced rule.
       Keep to zero when no symbol should be popped.  */
    int yylen = 0;

    yyssp = yyss = yyssa;
    yyvsp = yyvs = yyvsa;
    yystacksize = YYINITDEPTH;

    YYDPRINTF((stderr, "Starting parse\n"));

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
    YYDPRINTF((stderr, "Entering state %d\n", yystate));
    YY_ASSERT(0 <= yystate && yystate < YYNSTATES);
    YY_IGNORE_USELESS_CAST_BEGIN
    *yyssp = YY_CAST(yy_state_t, yystate);
    YY_IGNORE_USELESS_CAST_END

    if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
        goto yyexhaustedlab;
#else
    {
        /* Get the current used size of the three stacks, in elements.  */
        YYPTRDIFF_T yysize = yyssp - yyss + 1;

#if defined yyoverflow
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
            yyoverflow(YY_("memory exhausted"),
                       &yyss1, yysize * YYSIZEOF(*yyssp),
                       &yyvs1, yysize * YYSIZEOF(*yyvsp),
                       &yystacksize);
            yyss = yyss1;
            yyvs = yyvs1;
        }
#else /* defined YYSTACK_RELOCATE */
        /* Extend the stack our own way.  */
        if (YYMAXDEPTH <= yystacksize)
            goto yyexhaustedlab;
        yystacksize *= 2;
        if (YYMAXDEPTH < yystacksize)
            yystacksize = YYMAXDEPTH;

        {
            yy_state_t *yyss1 = yyss;
            union yyalloc *yyptr =
                YY_CAST(union yyalloc *,
                        YYSTACK_ALLOC(YY_CAST(YYSIZE_T, YYSTACK_BYTES(yystacksize))));
            if (!yyptr)
                goto yyexhaustedlab;
            YYSTACK_RELOCATE(yyss_alloc, yyss);
            YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#undef YYSTACK_RELOCATE
            if (yyss1 != yyssa)
                YYSTACK_FREE(yyss1);
        }
#endif

        yyssp = yyss + yysize - 1;
        yyvsp = yyvs + yysize - 1;

        YY_IGNORE_USELESS_CAST_BEGIN
        YYDPRINTF((stderr, "Stack size increased to %ld\n",
                   YY_CAST(long, yystacksize)));
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
    if (yypact_value_is_default(yyn))
        goto yydefault;

    /* Not known => get a lookahead token if don't already have one.  */

    /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
    if (yychar == YYEMPTY) {
        YYDPRINTF((stderr, "Reading a token: "));
        yychar = yylex();
    }

    if (yychar <= YYEOF) {
        yychar = yytoken = YYEOF;
        YYDPRINTF((stderr, "Now at end of input.\n"));
    } else {
        yytoken = YYTRANSLATE(yychar);
        YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
    }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
        goto yydefault;
    yyn = yytable[yyn];
    if (yyn <= 0) {
        if (yytable_value_is_error(yyn))
            goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
    }

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus)
        yyerrstatus--;

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);
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
    yyval = yyvsp[1 - yylen];

    YY_REDUCE_PRINT(yyn);
    switch (yyn) {
    case 2:
#line 57 "parser.y"
    {
        exit(0);
    }
#line 1668 "y.tab.c"
    break;

    case 3:
#line 60 "parser.y"
    {
        exit(0);
    }
#line 1676 "y.tab.c"
    break;

    case 4:
#line 63 "parser.y"
    {
        exit(0);
    }
#line 1684 "y.tab.c"
    break;

    case 5:
#line 68 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        populateGST((yyvsp[-1].node));
        printGSymbolTable();

        generateHeader();
    }
#line 1696 "y.tab.c"
    break;

    case 6:
#line 75 "parser.y"
    {
        (yyval.node) = NULL;
        generateHeader();
    }
#line 1702 "y.tab.c"
    break;

    case 7:
#line 78 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1708 "y.tab.c"
    break;

    case 8:
#line 79 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1714 "y.tab.c"
    break;

    case 9:
#line 82 "parser.y"
    {
        (yyval.node) = createDeclarationNode((yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1720 "y.tab.c"
    break;

    case 10:
#line 83 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1726 "y.tab.c"
    break;

    case 11:
#line 86 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1732 "y.tab.c"
    break;

    case 12:
#line 87 "parser.y"
    {
        (yyval.node) = createNewArrayNode((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1738 "y.tab.c"
    break;

    case 13:
#line 88 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node)));
    }
#line 1744 "y.tab.c"
    break;

    case 14:
#line 89 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-5].node), createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-1].node)));
    }
#line 1750 "y.tab.c"
    break;

    case 15:
#line 90 "parser.y"
    {
        (yyval.node) = createNewArrayNode(NULL, (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1756 "y.tab.c"
    break;

    case 16:
#line 91 "parser.y"
    {
        (yyval.node) = createNewPointerNode((yyvsp[0].node));
    }
#line 1762 "y.tab.c"
    break;

    case 17:
#line 92 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1768 "y.tab.c"
    break;

    case 18:
#line 93 "parser.y"
    {
        (yyval.node) = createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 1774 "y.tab.c"
    break;

    case 19:
#line 96 "parser.y"
    {
        (yyval.node) = createGlobalTupleTypeNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1780 "y.tab.c"
    break;

    case 20:
#line 99 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1786 "y.tab.c"
    break;

    case 21:
#line 100 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1792 "y.tab.c"
    break;

    case 22:
#line 103 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1798 "y.tab.c"
    break;

    case 23:
#line 106 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1804 "y.tab.c"
    break;

    case 24:
#line 107 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node)));
    }
#line 1810 "y.tab.c"
    break;

    case 25:
#line 108 "parser.y"
    {
        (yyval.node) = createNewPointerNode((yyvsp[0].node));
    }
#line 1816 "y.tab.c"
    break;

    case 26:
#line 109 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1822 "y.tab.c"
    break;

    case 27:
#line 112 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1828 "y.tab.c"
    break;

    case 28:
#line 113 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1834 "y.tab.c"
    break;

    case 29:
#line 114 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1840 "y.tab.c"
    break;

    case 30:
#line 117 "parser.y"
    {
        (yyval.node) = createParamNode((yyvsp[-1].node), (yyvsp[0].node), false, false);
    }
#line 1846 "y.tab.c"
    break;

    case 31:
#line 118 "parser.y"
    {
        (yyval.node) = createParamNode((yyvsp[-2].node), (yyvsp[0].node), false, true);
    }
#line 1852 "y.tab.c"
    break;

    case 32:
#line 121 "parser.y"
    {
        (yyval.node) = createTypeNode(INT);
    }
#line 1858 "y.tab.c"
    break;

    case 33:
#line 122 "parser.y"
    {
        (yyval.node) = createTypeNode(STRING);
    }
#line 1864 "y.tab.c"
    break;

    case 34:
#line 123 "parser.y"
    {
        (yyval.node) = createTupleTypeNode((yyvsp[0].node));
    }
#line 1870 "y.tab.c"
    break;

    case 35:
#line 126 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1876 "y.tab.c"
    break;

    case 36:
#line 127 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1882 "y.tab.c"
    break;

    case 37:
#line 131 "parser.y"
    {
        currentFunction = lookupGST((yyvsp[-3].node)->varName);
    }
#line 1888 "y.tab.c"
    break;

    case 38:
#line 133 "parser.y"
    {
        (yyval.node) = createFunctionDefinitionNode((yyvsp[-9].node), (yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1894 "y.tab.c"
    break;

    case 39:
#line 136 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1900 "y.tab.c"
    break;

    case 40:
#line 139 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1906 "y.tab.c"
    break;

    case 41:
#line 140 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1912 "y.tab.c"
    break;

    case 42:
#line 141 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1918 "y.tab.c"
    break;

    case 43:
#line 144 "parser.y"
    {
        (yyval.node) = createParamNode((yyvsp[-1].node), (yyvsp[0].node), true, false);
    }
#line 1924 "y.tab.c"
    break;

    case 44:
#line 145 "parser.y"
    {
        (yyval.node) = createParamNode((yyvsp[-2].node), (yyvsp[0].node), true, true);
    }
#line 1930 "y.tab.c"
    break;

    case 45:
#line 148 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1936 "y.tab.c"
    break;

    case 46:
#line 149 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1942 "y.tab.c"
    break;

    case 47:
#line 152 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1948 "y.tab.c"
    break;

    case 48:
#line 153 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1954 "y.tab.c"
    break;

    case 49:
#line 154 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1960 "y.tab.c"
    break;

    case 50:
#line 155 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1966 "y.tab.c"
    break;

    case 51:
#line 158 "parser.y"
    {
        (yyval.node) = createLocalDeclarationNode((yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1972 "y.tab.c"
    break;

    case 52:
#line 161 "parser.y"
    {
        (yyval.node) = createLocalTupleTypeDeclarationNode((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 1978 "y.tab.c"
    break;

    case 53:
#line 164 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1984 "y.tab.c"
    break;

    case 54:
#line 165 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-3].node), createNewPointerNode((yyvsp[0].node)));
    }
#line 1990 "y.tab.c"
    break;

    case 55:
#line 166 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1996 "y.tab.c"
    break;

    case 56:
#line 167 "parser.y"
    {
        (yyval.node) = createNewPointerNode((yyvsp[0].node));
    }
#line 2002 "y.tab.c"
    break;

    case 57:
#line 170 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2008 "y.tab.c"
    break;

    case 58:
#line 171 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2014 "y.tab.c"
    break;

    case 59:
#line 174 "parser.y"
    {
        (yyval.node) = createMainNode((yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 2020 "y.tab.c"
    break;

    case 60:
#line 177 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2026 "y.tab.c"
    break;

    case 61:
#line 178 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2032 "y.tab.c"
    break;

    case 62:
#line 181 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2038 "y.tab.c"
    break;

    case 63:
#line 182 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2044 "y.tab.c"
    break;

    case 64:
#line 183 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2050 "y.tab.c"
    break;

    case 65:
#line 184 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2056 "y.tab.c"
    break;

    case 66:
#line 185 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2062 "y.tab.c"
    break;

    case 67:
#line 186 "parser.y"
    {
        (yyval.node) = createBreakNode();
    }
#line 2068 "y.tab.c"
    break;

    case 68:
#line 187 "parser.y"
    {
        (yyval.node) = createContinueNode();
    }
#line 2074 "y.tab.c"
    break;

    case 69:
#line 188 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2080 "y.tab.c"
    break;

    case 70:
#line 189 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2086 "y.tab.c"
    break;

    case 71:
#line 190 "parser.y"
    {
        (yyval.node) = createBreakPointNode();
    }
#line 2092 "y.tab.c"
    break;

    case 72:
#line 191 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2098 "y.tab.c"
    break;

    case 73:
#line 192 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2104 "y.tab.c"
    break;

    case 74:
#line 195 "parser.y"
    {
        (yyval.node) = createReturnNode((yyvsp[0].node));
    }
#line 2110 "y.tab.c"
    break;

    case 75:
#line 198 "parser.y"
    {
        (yyval.node) = createReadNode((yyvsp[-2].node));
    }
#line 2116 "y.tab.c"
    break;

    case 76:
#line 199 "parser.y"
    {
        (yyval.node) = createReadToArrayNode((yyvsp[-3].node), (yyvsp[-2].node));
    }
#line 2122 "y.tab.c"
    break;

    case 77:
#line 202 "parser.y"
    {
        (yyval.node) = createWriteNode((yyvsp[-2].node));
    }
#line 2128 "y.tab.c"
    break;

    case 78:
#line 205 "parser.y"
    {
        (yyval.node) = createAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2134 "y.tab.c"
    break;

    case 79:
#line 206 "parser.y"
    {
        (yyval.node) = createArrayAssignNode((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2140 "y.tab.c"
    break;

    case 80:
#line 207 "parser.y"
    {
        (yyval.node) = createAssignToDereferencedNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2146 "y.tab.c"
    break;

    case 81:
#line 208 "parser.y"
    {
        (yyval.node) = createIncrementNode((yyvsp[-2].node));
    }
#line 2152 "y.tab.c"
    break;

    case 82:
#line 209 "parser.y"
    {
        (yyval.node) = createDecrementNode((yyvsp[-2].node));
    }
#line 2158 "y.tab.c"
    break;

    case 83:
#line 210 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2164 "y.tab.c"
    break;

    case 84:
#line 211 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2170 "y.tab.c"
    break;

    case 85:
#line 214 "parser.y"
    {
        (yyval.node) = createTupleAssignmentNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2176 "y.tab.c"
    break;

    case 86:
#line 215 "parser.y"
    {
        (yyval.node) = createTuplePointerAssignmentNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2182 "y.tab.c"
    break;

    case 87:
#line 218 "parser.y"
    {
        (yyval.node) = createCompoundAssignNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2188 "y.tab.c"
    break;

    case 88:
#line 219 "parser.y"
    {
        (yyval.node) = createCompoundAssignNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2194 "y.tab.c"
    break;

    case 89:
#line 220 "parser.y"
    {
        (yyval.node) = createCompoundAssignNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2200 "y.tab.c"
    break;

    case 90:
#line 221 "parser.y"
    {
        (yyval.node) = createCompoundAssignNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2206 "y.tab.c"
    break;

    case 91:
#line 222 "parser.y"
    {
        (yyval.node) = createCompoundAssignNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2212 "y.tab.c"
    break;

    case 92:
#line 225 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2218 "y.tab.c"
    break;

    case 93:
#line 226 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2224 "y.tab.c"
    break;

    case 94:
#line 229 "parser.y"
    {
        (yyval.node) = createIfElseNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2230 "y.tab.c"
    break;

    case 95:
#line 230 "parser.y"
    {
        (yyval.node) = createIfNode((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2236 "y.tab.c"
    break;

    case 96:
#line 233 "parser.y"
    {
        (yyval.node) = createWhileNode((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2242 "y.tab.c"
    break;

    case 97:
#line 236 "parser.y"
    {
        (yyval.node) = createRepeatUntilNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2248 "y.tab.c"
    break;

    case 98:
#line 239 "parser.y"
    {
        (yyval.node) = createDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2254 "y.tab.c"
    break;

    case 99:
#line 242 "parser.y"
    {
        (yyval.node) = createArithOpNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2260 "y.tab.c"
    break;

    case 100:
#line 243 "parser.y"
    {
        (yyval.node) = createArithOpNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2266 "y.tab.c"
    break;

    case 101:
#line 244 "parser.y"
    {
        (yyval.node) = createArithOpNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2272 "y.tab.c"
    break;

    case 102:
#line 245 "parser.y"
    {
        (yyval.node) = createArithOpNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2278 "y.tab.c"
    break;

    case 103:
#line 246 "parser.y"
    {
        (yyval.node) = createArithOpNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2284 "y.tab.c"
    break;

    case 104:
#line 247 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2290 "y.tab.c"
    break;

    case 105:
#line 248 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2296 "y.tab.c"
    break;

    case 106:
#line 249 "parser.y"
    {
        (yyval.node) = createVariableUsageNode((yyvsp[0].node)->varName);
    }
#line 2302 "y.tab.c"
    break;

    case 107:
#line 250 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2308 "y.tab.c"
    break;

    case 108:
#line 251 "parser.y"
    {
        (yyval.node) = createArrayAccessNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2314 "y.tab.c"
    break;

    case 109:
#line 252 "parser.y"
    {
        (yyval.node) = createDereferenceNode((yyvsp[0].node));
    }
#line 2320 "y.tab.c"
    break;

    case 110:
#line 253 "parser.y"
    {
        (yyval.node) = createAddressToNode((yyvsp[0].node));
    }
#line 2326 "y.tab.c"
    break;

    case 111:
#line 254 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2332 "y.tab.c"
    break;

    case 112:
#line 255 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2338 "y.tab.c"
    break;

    case 113:
#line 258 "parser.y"
    {
        (yyval.node) = createTupleAccessNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2344 "y.tab.c"
    break;

    case 114:
#line 259 "parser.y"
    {
        (yyval.node) = createTuplePointerAccessNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2350 "y.tab.c"
    break;

    case 115:
#line 262 "parser.y"
    {
        (yyval.node) = createFunctionCallNode((yyvsp[-2].node), NULL);
    }
#line 2356 "y.tab.c"
    break;

    case 116:
#line 263 "parser.y"
    {
        (yyval.node) = createFunctionCallNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2362 "y.tab.c"
    break;

    case 117:
#line 265 "parser.y"
    {
        (yyval.node) = createConnectorNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2368 "y.tab.c"
    break;

    case 118:
#line 266 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2374 "y.tab.c"
    break;

    case 119:
#line 269 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2380 "y.tab.c"
    break;

    case 120:
#line 270 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2386 "y.tab.c"
    break;

    case 121:
#line 271 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2392 "y.tab.c"
    break;

    case 122:
#line 272 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2398 "y.tab.c"
    break;

    case 123:
#line 273 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2404 "y.tab.c"
    break;

    case 124:
#line 274 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2410 "y.tab.c"
    break;

    case 125:
#line 275 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2416 "y.tab.c"
    break;

    case 126:
#line 276 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2422 "y.tab.c"
    break;

    case 127:
#line 277 "parser.y"
    {
        (yyval.node) = createConditionNode(NODE_NOT, (yyvsp[0].node), NULL);
    }
#line 2428 "y.tab.c"
    break;

    case 128:
#line 278 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2434 "y.tab.c"
    break;

#line 2438 "y.tab.c"

    default:
        break;
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
    YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);

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
    yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE(yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus) {
        ++yynerrs;
#if !YYERROR_VERBOSE
        yyerror(YY_("syntax error"));
#else
#define YYSYNTAX_ERROR yysyntax_error(&yymsg_alloc, &yymsg, \
                                      yyssp, yytoken)
        {
            char const *yymsgp = YY_("syntax error");
            int yysyntax_error_status;
            yysyntax_error_status = YYSYNTAX_ERROR;
            if (yysyntax_error_status == 0)
                yymsgp = yymsg;
            else if (yysyntax_error_status == 1) {
                if (yymsg != yymsgbuf)
                    YYSTACK_FREE(yymsg);
                yymsg = YY_CAST(char *, YYSTACK_ALLOC(YY_CAST(YYSIZE_T, yymsg_alloc)));
                if (!yymsg) {
                    yymsg = yymsgbuf;
                    yymsg_alloc = sizeof yymsgbuf;
                    yysyntax_error_status = 2;
                } else {
                    yysyntax_error_status = YYSYNTAX_ERROR;
                    yymsgp = yymsg;
                }
            }
            yyerror(yymsgp);
            if (yysyntax_error_status == 2)
                goto yyexhaustedlab;
        }
#undef YYSYNTAX_ERROR
#endif
    }

    if (yyerrstatus == 3) {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        if (yychar <= YYEOF) {
            /* Return failure if at end of input.  */
            if (yychar == YYEOF)
                YYABORT;
        } else {
            yydestruct("Error: discarding",
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
    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);
    yystate = *yyssp;
    goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
    yyerrstatus = 3; /* Each real token shifted decrements this.  */

    for (;;) {
        yyn = yypact[yystate];
        if (!yypact_value_is_default(yyn)) {
            yyn += YYTERROR;
            if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR) {
                yyn = yytable[yyn];
                if (0 < yyn)
                    break;
            }
        }

        /* Pop the current state because it cannot handle the error token.  */
        if (yyssp == yyss)
            YYABORT;

        yydestruct("Error: popping",
                   yystos[yystate], yyvsp);
        YYPOPSTACK(1);
        yystate = *yyssp;
        YY_STACK_PRINT(yyss, yyssp);
    }

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    *++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END

    /* Shift the error token.  */
    YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

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
    yyerror(YY_("memory exhausted"));
    yyresult = 2;
    /* Fall through.  */
#endif

/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
    if (yychar != YYEMPTY) {
        /* Make sure we have latest lookahead translation.  See comments at
           user semantic actions for why this is necessary.  */
        yytoken = YYTRANSLATE(yychar);
        yydestruct("Cleanup: discarding lookahead",
                   yytoken, &yylval);
    }
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    YYPOPSTACK(yylen);
    YY_STACK_PRINT(yyss, yyssp);
    while (yyssp != yyss) {
        yydestruct("Cleanup: popping",
                   yystos[+*yyssp], yyvsp);
        YYPOPSTACK(1);
    }
#ifndef yyoverflow
    if (yyss != yyssa)
        YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
    if (yymsg != yymsgbuf)
        YYSTACK_FREE(yymsg);
#endif
    return yyresult;
}
#line 281 "parser.y"

void yyerror(char const *msg) {
    printf("[Error] : %s in line: %d [%s]\n", msg, lineNumber, yytext);
    return;
}

int main(int argc, char **argv) {
    FILE *source_file;
    if (argc == 2) {
        source_file = fopen(argv[1], "r");
    } else {
        printf("source file: %s\n", SOURCE_FILE);
        source_file = fopen(SOURCE_FILE, "r");
    }

    if (!source_file) {
        printf("[ERROR]: source file is NULL\n");
        exit(1);
    }

    target_file = fopen(INTERMEDIATE_FILE, "w");

    yyin = source_file;

    return yyparse();
}
