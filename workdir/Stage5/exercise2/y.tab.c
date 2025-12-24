/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20240109

#define YYEMPTY (-1)
#define yyclearin (yychar = YYEMPTY)
#define yyerrok (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM (-2)
#define YYEOF 0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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
#ifdef YYSTYPE
#undef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 19 "parser.y"
typedef union YYSTYPE {
    struct tnode *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 51 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
#define YYLEX_DECL() yylex(void *YYLEX_PARAM)
#define YYLEX yylex(YYLEX_PARAM)
#else
#define YYLEX_DECL() yylex(void)
#define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define NUM 258
#define STRING_LITERAL 259
#define READ 260
#define WRITE 261
#define PLUS 262
#define MUL 263
#define MINUS 264
#define DIV 265
#define MOD 266
#define ASSIGN 267
#define SEMI 268
#define AMPERSAND 269
#define GT 270
#define GE 271
#define LT 272
#define LE 273
#define NE 274
#define EQ 275
#define KW_BEGIN 276
#define KW_END 277
#define KW_IF 278
#define KW_THEN 279
#define KW_ELSE 280
#define KW_ENDIF 281
#define KW_WHILE 282
#define KW_DO 283
#define KW_ENDWHILE 284
#define KW_BREAK 285
#define KW_CONTINUE 286
#define KW_REPEAT 287
#define KW_UNTIL 288
#define KW_DECL 289
#define KW_ENDDECL 290
#define TYPE_INT 291
#define TYPE_STRING 292
#define COMMA 293
#define AND 294
#define OR 295
#define NOT 296
#define INCREMENT 297
#define DECREMENT 298
#define ASSIGN_ADD 299
#define ASSIGN_SUB 300
#define ASSIGN_MUL 301
#define ASSIGN_DIV 302
#define ASSIGN_MOD 303
#define KW_RETURN 304
#define MAIN 305
#define KW_BRKP 306
#define KW_TUPLE 307
#define DOT 308
#define ARROW 309
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {
    -1,
    0,
    0,
    0,
    13,
    13,
    14,
    14,
    15,
    15,
    16,
    16,
    16,
    16,
    16,
    16,
    16,
    16,
    35,
    36,
    36,
    38,
    37,
    37,
    37,
    37,
    33,
    33,
    33,
    34,
    34,
    17,
    17,
    24,
    24,
    42,
    25,
    23,
    20,
    20,
    20,
    21,
    21,
    26,
    26,
    27,
    27,
    27,
    28,
    39,
    29,
    29,
    29,
    29,
    18,
    18,
    22,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    32,
    4,
    4,
    5,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    40,
    40,
    7,
    7,
    7,
    7,
    7,
    19,
    19,
    9,
    9,
    8,
    10,
    11,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    41,
    41,
    31,
    31,
    30,
    30,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
};
static const YYINT yylen[] = {
    2,
    3,
    2,
    1,
    3,
    2,
    2,
    1,
    3,
    1,
    3,
    4,
    4,
    6,
    2,
    2,
    1,
    4,
    7,
    3,
    1,
    2,
    3,
    4,
    2,
    1,
    3,
    1,
    0,
    2,
    3,
    1,
    1,
    2,
    1,
    0,
    10,
    3,
    3,
    1,
    0,
    2,
    3,
    3,
    2,
    2,
    1,
    1,
    3,
    7,
    3,
    4,
    1,
    2,
    4,
    3,
    8,
    2,
    1,
    1,
    1,
    1,
    1,
    1,
    2,
    2,
    1,
    1,
    2,
    2,
    2,
    2,
    5,
    6,
    5,
    4,
    5,
    5,
    3,
    3,
    2,
    2,
    5,
    5,
    3,
    3,
    3,
    3,
    3,
    4,
    3,
    9,
    7,
    7,
    7,
    7,
    3,
    3,
    3,
    3,
    3,
    3,
    1,
    1,
    1,
    2,
    2,
    2,
    1,
    1,
    3,
    3,
    3,
    4,
    3,
    1,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    3,
};
static const YYINT yydefred[] = {
    0,
    0,
    0,
    0,
    0,
    3,
    5,
    31,
    32,
    0,
    0,
    7,
    0,
    9,
    0,
    0,
    0,
    2,
    0,
    34,
    0,
    4,
    6,
    0,
    0,
    0,
    0,
    0,
    1,
    33,
    0,
    0,
    0,
    0,
    15,
    8,
    0,
    0,
    0,
    0,
    0,
    20,
    0,
    0,
    27,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    39,
    21,
    0,
    0,
    29,
    0,
    0,
    17,
    55,
    0,
    0,
    0,
    12,
    0,
    0,
    41,
    0,
    0,
    35,
    19,
    25,
    0,
    0,
    30,
    26,
    54,
    0,
    44,
    0,
    0,
    0,
    46,
    47,
    0,
    0,
    42,
    38,
    0,
    24,
    18,
    0,
    13,
    0,
    52,
    0,
    0,
    43,
    45,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    58,
    59,
    60,
    61,
    0,
    63,
    62,
    66,
    67,
    0,
    0,
    0,
    56,
    0,
    22,
    0,
    0,
    53,
    48,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    64,
    65,
    0,
    0,
    102,
    104,
    0,
    0,
    0,
    0,
    108,
    109,
    68,
    37,
    57,
    80,
    69,
    70,
    81,
    0,
    23,
    0,
    50,
    0,
    0,
    78,
    79,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    112,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    106,
    107,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    51,
    75,
    0,
    0,
    0,
    113,
    90,
    0,
    0,
    0,
    0,
    0,
    0,
    124,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    110,
    111,
    101,
    0,
    98,
    0,
    99,
    100,
    36,
    0,
    0,
    0,
    0,
    76,
    89,
    72,
    0,
    74,
    77,
    125,
    0,
    0,
    0,
    0,
    0,
    0,
    123,
    0,
    0,
    0,
    0,
    0,
    49,
    73,
    0,
    0,
    0,
    0,
    0,
    92,
    93,
    95,
    94,
    0,
    91,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {
    0,
    289,
    291,
    311,
    324,
    333,
    290,
    291,
    292,
    307,
    325,
    326,
    328,
    346,
    305,
    291,
    328,
    333,
    335,
    336,
    257,
    290,
    326,
    257,
    263,
    327,
    40,
    257,
    333,
    336,
    40,
    40,
    91,
    329,
    257,
    268,
    293,
    41,
    40,
    328,
    347,
    349,
    328,
    344,
    345,
    258,
    91,
    257,
    263,
    123,
    328,
    331,
    332,
    257,
    293,
    41,
    257,
    263,
    293,
    41,
    93,
    258,
    40,
    329,
    257,
    289,
    337,
    257,
    263,
    293,
    41,
    349,
    257,
    263,
    348,
    257,
    345,
    93,
    344,
    290,
    307,
    328,
    338,
    339,
    350,
    276,
    334,
    257,
    332,
    353,
    257,
    268,
    293,
    41,
    257,
    257,
    263,
    340,
    290,
    339,
    257,
    260,
    261,
    263,
    278,
    282,
    283,
    285,
    286,
    287,
    304,
    306,
    313,
    314,
    315,
    316,
    317,
    318,
    319,
    320,
    321,
    322,
    342,
    343,
    351,
    125,
    123,
    257,
    263,
    40,
    257,
    268,
    293,
    267,
    297,
    298,
    299,
    300,
    301,
    302,
    303,
    308,
    309,
    40,
    91,
    330,
    40,
    40,
    257,
    40,
    40,
    313,
    268,
    268,
    313,
    257,
    258,
    259,
    263,
    269,
    40,
    312,
    342,
    352,
    268,
    277,
    314,
    268,
    268,
    268,
    268,
    337,
    257,
    347,
    257,
    263,
    312,
    268,
    268,
    312,
    312,
    312,
    312,
    312,
    257,
    257,
    41,
    312,
    341,
    312,
    267,
    91,
    257,
    312,
    267,
    296,
    40,
    312,
    323,
    323,
    282,
    288,
    308,
    309,
    330,
    257,
    257,
    312,
    262,
    263,
    264,
    265,
    266,
    334,
    41,
    257,
    268,
    267,
    267,
    293,
    41,
    93,
    312,
    312,
    41,
    330,
    41,
    312,
    323,
    312,
    323,
    270,
    271,
    272,
    273,
    274,
    275,
    294,
    295,
    41,
    41,
    40,
    40,
    257,
    257,
    41,
    312,
    312,
    312,
    312,
    312,
    125,
    348,
    312,
    312,
    312,
    268,
    93,
    268,
    41,
    268,
    268,
    41,
    312,
    312,
    312,
    312,
    312,
    312,
    323,
    323,
    279,
    283,
    323,
    323,
    268,
    268,
    313,
    313,
    41,
    41,
    280,
    281,
    284,
    268,
    268,
    313,
    281,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {
    3,
    197,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121,
    198,
    4,
    10,
    11,
    25,
    39,
    33,
    145,
    51,
    52,
    5,
    86,
    18,
    19,
    66,
    82,
    83,
    97,
    188,
    162,
    123,
    43,
    44,
    13,
    40,
    74,
    41,
    84,
    124,
    163,
    89,
};
static const YYINT yysindex[] = {
    -226,
    -198,
    -281,
    0,
    -145,
    0,
    0,
    0,
    0,
    -212,
    -179,
    0,
    -230,
    0,
    15,
    -281,
    -170,
    0,
    -145,
    0,
    55,
    0,
    0,
    -32,
    -159,
    -259,
    37,
    60,
    0,
    0,
    -135,
    -135,
    -140,
    67,
    0,
    0,
    -172,
    7,
    -135,
    -117,
    -37,
    0,
    -161,
    -28,
    0,
    74,
    -98,
    -22,
    -87,
    -118,
    -158,
    -27,
    0,
    0,
    -135,
    -138,
    0,
    -83,
    -135,
    0,
    0,
    82,
    -135,
    67,
    0,
    -176,
    -97,
    0,
    -81,
    -135,
    0,
    0,
    0,
    -77,
    -256,
    0,
    0,
    0,
    -13,
    0,
    -75,
    -131,
    -169,
    0,
    0,
    293,
    58,
    0,
    0,
    66,
    0,
    0,
    -130,
    0,
    150,
    0,
    -64,
    -246,
    0,
    0,
    -40,
    154,
    155,
    -61,
    159,
    160,
    293,
    -66,
    -65,
    293,
    105,
    -63,
    157,
    0,
    0,
    0,
    0,
    -60,
    0,
    0,
    0,
    0,
    -49,
    -47,
    -46,
    0,
    -118,
    0,
    -50,
    -135,
    0,
    0,
    -128,
    105,
    -45,
    -44,
    105,
    105,
    105,
    105,
    105,
    -26,
    -25,
    102,
    105,
    -90,
    -20,
    105,
    -42,
    -29,
    -29,
    303,
    0,
    0,
    219,
    -38,
    0,
    0,
    -19,
    -18,
    105,
    -100,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -97,
    0,
    -11,
    0,
    -9,
    -113,
    0,
    0,
    -100,
    -100,
    -100,
    -100,
    -100,
    -41,
    -34,
    0,
    -100,
    -3,
    -78,
    105,
    105,
    -24,
    113,
    105,
    -29,
    -29,
    330,
    -2,
    23,
    164,
    195,
    62,
    68,
    259,
    0,
    0,
    118,
    105,
    105,
    105,
    105,
    105,
    111,
    -138,
    0,
    0,
    105,
    105,
    105,
    0,
    0,
    -48,
    -53,
    84,
    -10,
    99,
    147,
    0,
    83,
    29,
    105,
    105,
    105,
    105,
    105,
    105,
    -29,
    -29,
    -33,
    86,
    -29,
    -29,
    0,
    0,
    0,
    -127,
    0,
    -127,
    0,
    0,
    0,
    -245,
    -100,
    -100,
    -100,
    0,
    0,
    0,
    104,
    0,
    0,
    0,
    -100,
    -100,
    -100,
    -100,
    -100,
    -100,
    0,
    -39,
    293,
    293,
    32,
    34,
    0,
    0,
    145,
    251,
    -247,
    117,
    293,
    0,
    0,
    0,
    0,
    261,
    0,
};
static const YYINT yyrindex[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    94,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -243,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    -233,
    0,
    0,
    0,
    0,
    3,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -227,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    -192,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -21,
    0,
    0,
    0,
    0,
    0,
    119,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    120,
    122,
    123,
    129,
    130,
    0,
    0,
    0,
    11,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    13,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    27,
    0,
    41,
    0,
    0,
    0,
    0,
    133,
    136,
    17,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    36,
    38,
    43,
    45,
    47,
    49,
    0,
    -31,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
#endif
static const YYINT yygindex[] = {
    0,
    256,
    -103,
    -105,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -134,
    0,
    0,
    360,
    0,
    79,
    326,
    -136,
    0,
    317,
    39,
    236,
    0,
    401,
    295,
    0,
    340,
    0,
    0,
    -80,
    0,
    362,
    371,
    0,
    304,
    222,
    383,
    0,
    0,
    0,
    0,
};
#define YYTABLESIZE 609
static const YYINT yytable[] = {
    143,
    191,
    143,
    151,
    55,
    122,
    154,
    166,
    31,
    35,
    122,
    196,
    91,
    59,
    70,
    221,
    199,
    224,
    62,
    204,
    103,
    284,
    131,
    275,
    14,
    16,
    122,
    23,
    93,
    122,
    214,
    259,
    122,
    24,
    36,
    14,
    272,
    92,
    220,
    239,
    257,
    10,
    28,
    17,
    40,
    20,
    166,
    132,
    92,
    166,
    16,
    144,
    115,
    144,
    105,
    26,
    225,
    28,
    114,
    32,
    14,
    228,
    230,
    1,
    240,
    2,
    10,
    144,
    96,
    32,
    262,
    122,
    103,
    279,
    122,
    280,
    11,
    119,
    37,
    118,
    12,
    191,
    97,
    16,
    117,
    47,
    116,
    27,
    120,
    12,
    121,
    48,
    6,
    7,
    8,
    30,
    56,
    16,
    34,
    67,
    38,
    11,
    57,
    269,
    270,
    68,
    105,
    273,
    274,
    9,
    42,
    21,
    7,
    8,
    79,
    7,
    8,
    50,
    45,
    72,
    96,
    98,
    7,
    8,
    245,
    73,
    95,
    127,
    9,
    174,
    49,
    80,
    96,
    128,
    97,
    175,
    209,
    42,
    211,
    212,
    53,
    42,
    160,
    186,
    81,
    160,
    15,
    8,
    50,
    208,
    209,
    210,
    211,
    212,
    226,
    216,
    7,
    8,
    46,
    245,
    61,
    81,
    208,
    209,
    210,
    211,
    212,
    60,
    277,
    278,
    64,
    65,
    166,
    166,
    75,
    77,
    87,
    190,
    286,
    85,
    90,
    166,
    94,
    125,
    208,
    209,
    210,
    211,
    212,
    126,
    129,
    122,
    122,
    130,
    146,
    147,
    148,
    122,
    122,
    149,
    150,
    122,
    152,
    153,
    241,
    164,
    122,
    172,
    167,
    208,
    209,
    210,
    211,
    212,
    208,
    209,
    210,
    211,
    212,
    168,
    256,
    169,
    170,
    177,
    178,
    194,
    217,
    133,
    155,
    156,
    157,
    184,
    185,
    218,
    158,
    242,
    251,
    192,
    205,
    206,
    159,
    103,
    103,
    103,
    103,
    103,
    271,
    103,
    215,
    103,
    103,
    103,
    103,
    103,
    103,
    237,
    54,
    134,
    135,
    136,
    137,
    138,
    139,
    140,
    122,
    58,
    69,
    195,
    141,
    142,
    202,
    203,
    103,
    103,
    103,
    105,
    105,
    105,
    105,
    105,
    58,
    105,
    54,
    105,
    105,
    105,
    105,
    105,
    105,
    96,
    219,
    96,
    237,
    238,
    28,
    96,
    40,
    96,
    96,
    96,
    96,
    96,
    96,
    97,
    115,
    97,
    105,
    105,
    105,
    97,
    114,
    97,
    97,
    97,
    97,
    97,
    97,
    237,
    238,
    243,
    96,
    96,
    96,
    237,
    238,
    244,
    237,
    238,
    237,
    238,
    119,
    119,
    118,
    118,
    97,
    97,
    97,
    117,
    117,
    116,
    116,
    120,
    120,
    121,
    121,
    208,
    209,
    210,
    211,
    212,
    191,
    31,
    258,
    231,
    232,
    233,
    234,
    235,
    236,
    155,
    156,
    157,
    155,
    156,
    157,
    158,
    161,
    260,
    158,
    272,
    22,
    159,
    276,
    63,
    159,
    208,
    209,
    210,
    211,
    212,
    208,
    209,
    210,
    211,
    212,
    285,
    88,
    71,
    84,
    176,
    85,
    86,
    179,
    180,
    181,
    182,
    183,
    87,
    88,
    187,
    189,
    82,
    100,
    193,
    83,
    101,
    102,
    213,
    103,
    208,
    209,
    210,
    211,
    212,
    100,
    261,
    207,
    101,
    102,
    29,
    103,
    171,
    99,
    104,
    78,
    281,
    282,
    105,
    106,
    76,
    107,
    108,
    109,
    173,
    165,
    104,
    252,
    71,
    0,
    105,
    106,
    0,
    107,
    108,
    109,
    0,
    222,
    223,
    0,
    110,
    227,
    111,
    229,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    110,
    0,
    111,
    246,
    247,
    248,
    249,
    250,
    0,
    0,
    0,
    0,
    253,
    254,
    255,
    100,
    0,
    0,
    101,
    102,
    0,
    103,
    0,
    0,
    0,
    0,
    263,
    264,
    265,
    266,
    267,
    268,
    0,
    0,
    0,
    0,
    104,
    0,
    0,
    0,
    105,
    106,
    0,
    107,
    108,
    109,
    201,
    100,
    0,
    0,
    101,
    102,
    0,
    103,
    0,
    0,
    0,
    100,
    0,
    0,
    101,
    102,
    110,
    103,
    111,
    0,
    0,
    0,
    104,
    0,
    0,
    0,
    105,
    106,
    283,
    107,
    108,
    109,
    104,
    0,
    0,
    287,
    105,
    106,
    0,
    107,
    108,
    109,
    0,
    100,
    0,
    0,
    101,
    102,
    110,
    103,
    111,
    0,
    0,
    100,
    0,
    0,
    101,
    102,
    110,
    103,
    111,
    0,
    0,
    0,
    104,
    0,
    0,
    0,
    105,
    106,
    0,
    107,
    108,
    109,
    104,
    0,
    0,
    0,
    200,
    106,
    0,
    107,
    108,
    109,
    0,
    208,
    209,
    210,
    211,
    212,
    110,
    0,
    111,
    231,
    232,
    233,
    234,
    235,
    236,
    0,
    110,
    0,
    111,
};
static const YYINT yycheck[] = {
    40,
    91,
    40,
    106,
    41,
    85,
    109,
    112,
    40,
    268,
    41,
    40,
    268,
    41,
    41,
    93,
    150,
    41,
    40,
    155,
    41,
    268,
    268,
    268,
    305,
    268,
    106,
    257,
    41,
    109,
    41,
    41,
    112,
    263,
    293,
    268,
    283,
    293,
    41,
    41,
    93,
    268,
    41,
    4,
    41,
    257,
    151,
    293,
    293,
    154,
    293,
    91,
    41,
    91,
    41,
    40,
    192,
    18,
    41,
    91,
    293,
    195,
    196,
    289,
    41,
    291,
    293,
    91,
    41,
    91,
    41,
    151,
    93,
    41,
    154,
    41,
    268,
    41,
    41,
    41,
    1,
    91,
    41,
    4,
    41,
    257,
    41,
    257,
    41,
    10,
    41,
    263,
    290,
    291,
    292,
    40,
    257,
    18,
    257,
    257,
    40,
    293,
    263,
    237,
    238,
    263,
    93,
    241,
    242,
    307,
    31,
    290,
    291,
    292,
    290,
    291,
    292,
    38,
    258,
    257,
    93,
    290,
    291,
    292,
    41,
    263,
    257,
    257,
    307,
    257,
    123,
    307,
    263,
    263,
    93,
    263,
    263,
    58,
    265,
    266,
    257,
    62,
    40,
    41,
    65,
    40,
    291,
    292,
    69,
    262,
    263,
    264,
    265,
    266,
    41,
    268,
    291,
    292,
    91,
    41,
    258,
    82,
    262,
    263,
    264,
    265,
    266,
    93,
    271,
    272,
    257,
    289,
    277,
    278,
    257,
    93,
    257,
    267,
    281,
    276,
    257,
    286,
    257,
    125,
    262,
    263,
    264,
    265,
    266,
    123,
    40,
    271,
    272,
    257,
    40,
    40,
    257,
    277,
    278,
    40,
    40,
    281,
    268,
    268,
    40,
    268,
    286,
    257,
    268,
    262,
    263,
    264,
    265,
    266,
    262,
    263,
    264,
    265,
    266,
    268,
    268,
    268,
    268,
    268,
    268,
    267,
    267,
    267,
    257,
    258,
    259,
    257,
    257,
    267,
    263,
    40,
    125,
    257,
    257,
    257,
    269,
    262,
    263,
    264,
    265,
    266,
    279,
    268,
    257,
    270,
    271,
    272,
    273,
    274,
    275,
    294,
    293,
    297,
    298,
    299,
    300,
    301,
    302,
    303,
    295,
    293,
    293,
    296,
    308,
    309,
    308,
    309,
    293,
    294,
    295,
    262,
    263,
    264,
    265,
    266,
    293,
    268,
    293,
    270,
    271,
    272,
    273,
    274,
    275,
    262,
    293,
    264,
    294,
    295,
    293,
    268,
    293,
    270,
    271,
    272,
    273,
    274,
    275,
    262,
    293,
    264,
    293,
    294,
    295,
    268,
    293,
    270,
    271,
    272,
    273,
    274,
    275,
    294,
    295,
    257,
    293,
    294,
    295,
    294,
    295,
    257,
    294,
    295,
    294,
    295,
    294,
    295,
    294,
    295,
    293,
    294,
    295,
    294,
    295,
    294,
    295,
    294,
    295,
    294,
    295,
    262,
    263,
    264,
    265,
    266,
    91,
    257,
    268,
    270,
    271,
    272,
    273,
    274,
    275,
    257,
    258,
    259,
    257,
    258,
    259,
    263,
    110,
    268,
    263,
    283,
    10,
    269,
    268,
    47,
    269,
    262,
    263,
    264,
    265,
    266,
    262,
    263,
    264,
    265,
    266,
    268,
    69,
    268,
    268,
    133,
    268,
    268,
    136,
    137,
    138,
    139,
    140,
    268,
    268,
    143,
    144,
    268,
    257,
    147,
    268,
    260,
    261,
    171,
    263,
    262,
    263,
    264,
    265,
    266,
    257,
    268,
    160,
    260,
    261,
    18,
    263,
    126,
    82,
    278,
    62,
    280,
    281,
    282,
    283,
    58,
    285,
    286,
    287,
    129,
    277,
    278,
    214,
    54,
    -1,
    282,
    283,
    -1,
    285,
    286,
    287,
    -1,
    190,
    191,
    -1,
    304,
    194,
    306,
    196,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    304,
    -1,
    306,
    208,
    209,
    210,
    211,
    212,
    -1,
    -1,
    -1,
    -1,
    217,
    218,
    219,
    257,
    -1,
    -1,
    260,
    261,
    -1,
    263,
    -1,
    -1,
    -1,
    -1,
    231,
    232,
    233,
    234,
    235,
    236,
    -1,
    -1,
    -1,
    -1,
    278,
    -1,
    -1,
    -1,
    282,
    283,
    -1,
    285,
    286,
    287,
    288,
    257,
    -1,
    -1,
    260,
    261,
    -1,
    263,
    -1,
    -1,
    -1,
    257,
    -1,
    -1,
    260,
    261,
    304,
    263,
    306,
    -1,
    -1,
    -1,
    278,
    -1,
    -1,
    -1,
    282,
    283,
    284,
    285,
    286,
    287,
    278,
    -1,
    -1,
    281,
    282,
    283,
    -1,
    285,
    286,
    287,
    -1,
    257,
    -1,
    -1,
    260,
    261,
    304,
    263,
    306,
    -1,
    -1,
    257,
    -1,
    -1,
    260,
    261,
    304,
    263,
    306,
    -1,
    -1,
    -1,
    278,
    -1,
    -1,
    -1,
    282,
    283,
    -1,
    285,
    286,
    287,
    278,
    -1,
    -1,
    -1,
    282,
    283,
    -1,
    285,
    286,
    287,
    -1,
    262,
    263,
    264,
    265,
    266,
    304,
    -1,
    306,
    270,
    271,
    272,
    273,
    274,
    275,
    -1,
    304,
    -1,
    306,
};
#if YYBTYACC
static const YYINT yyctable[] = {
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
};
#endif
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 309
#define YYUNDFTOKEN 354
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

    "$end",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "'('",
    "')'",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "'['",
    0,
    "']'",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "'{'",
    0,
    "'}'",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "error",
    "ID",
    "NUM",
    "STRING_LITERAL",
    "READ",
    "WRITE",
    "PLUS",
    "MUL",
    "MINUS",
    "DIV",
    "MOD",
    "ASSIGN",
    "SEMI",
    "AMPERSAND",
    "GT",
    "GE",
    "LT",
    "LE",
    "NE",
    "EQ",
    "KW_BEGIN",
    "KW_END",
    "KW_IF",
    "KW_THEN",
    "KW_ELSE",
    "KW_ENDIF",
    "KW_WHILE",
    "KW_DO",
    "KW_ENDWHILE",
    "KW_BREAK",
    "KW_CONTINUE",
    "KW_REPEAT",
    "KW_UNTIL",
    "KW_DECL",
    "KW_ENDDECL",
    "TYPE_INT",
    "TYPE_STRING",
    "COMMA",
    "AND",
    "OR",
    "NOT",
    "INCREMENT",
    "DECREMENT",
    "ASSIGN_ADD",
    "ASSIGN_SUB",
    "ASSIGN_MUL",
    "ASSIGN_DIV",
    "ASSIGN_MOD",
    "KW_RETURN",
    "MAIN",
    "KW_BRKP",
    "KW_TUPLE",
    "DOT",
    "ARROW",
    "$accept",
    "program",
    "expr",
    "statementList",
    "statement",
    "inputStatement",
    "outputStatement",
    "assignmentStatement",
    "compoundAssignment",
    "whileStatement",
    "ifStatement",
    "repeatUntilStatement",
    "doWhileStatement",
    "boolexpr",
    "globalDeclarationsBlock",
    "globalDeclarationList",
    "globalDecl",
    "globalVarList",
    "type",
    "dimensionDecl",
    "dimensionUsage",
    "paramList",
    "param",
    "mainBlock",
    "body",
    "functionDefinitionBlock",
    "functionDefinition",
    "localDeclBlock",
    "localDeclList",
    "localDecl",
    "idList",
    "argList",
    "functionCall",
    "returnStatement",
    "funcDeclParamList",
    "funcDeclParam",
    "globalTupleDeclaration",
    "tupleParamList",
    "tupleIdList",
    "tupleParam",
    "localTupleDecl",
    "tupleAssignmentStatement",
    "tupleAccess",
    "$$1",
    "illegal-symbol",
};
static const char *const yyrule[] = {
    "$accept : program",
    "program : globalDeclarationsBlock functionDefinitionBlock mainBlock",
    "program : globalDeclarationsBlock mainBlock",
    "program : mainBlock",
    "globalDeclarationsBlock : KW_DECL globalDeclarationList KW_ENDDECL",
    "globalDeclarationsBlock : KW_DECL KW_ENDDECL",
    "globalDeclarationList : globalDeclarationList globalDecl",
    "globalDeclarationList : globalDecl",
    "globalDecl : type globalVarList SEMI",
    "globalDecl : globalTupleDeclaration",
    "globalVarList : globalVarList COMMA ID",
    "globalVarList : globalVarList COMMA ID dimensionDecl",
    "globalVarList : globalVarList COMMA MUL ID",
    "globalVarList : globalVarList COMMA ID '(' funcDeclParamList ')'",
    "globalVarList : ID dimensionDecl",
    "globalVarList : MUL ID",
    "globalVarList : ID",
    "globalVarList : ID '(' funcDeclParamList ')'",
    "globalTupleDeclaration : KW_TUPLE ID '(' tupleParamList ')' tupleIdList SEMI",
    "tupleParamList : tupleParamList COMMA tupleParam",
    "tupleParamList : tupleParam",
    "tupleParam : type ID",
    "tupleIdList : tupleIdList COMMA ID",
    "tupleIdList : tupleIdList COMMA MUL ID",
    "tupleIdList : MUL ID",
    "tupleIdList : ID",
    "funcDeclParamList : funcDeclParamList COMMA funcDeclParam",
    "funcDeclParamList : funcDeclParam",
    "funcDeclParamList :",
    "funcDeclParam : type ID",
    "funcDeclParam : type MUL ID",
    "type : TYPE_INT",
    "type : TYPE_STRING",
    "functionDefinitionBlock : functionDefinitionBlock functionDefinition",
    "functionDefinitionBlock : functionDefinition",
    "$$1 :",
    "functionDefinition : type ID '(' paramList ')' $$1 '{' localDeclBlock body '}'",
    "body : KW_BEGIN statementList KW_END",
    "paramList : paramList COMMA param",
    "paramList : param",
    "paramList :",
    "param : type ID",
    "param : type MUL ID",
    "localDeclBlock : KW_DECL localDeclList KW_ENDDECL",
    "localDeclBlock : KW_DECL KW_ENDDECL",
    "localDeclList : localDeclList localDecl",
    "localDeclList : localDecl",
    "localDeclList : localTupleDecl",
    "localDecl : type idList SEMI",
    "localTupleDecl : KW_TUPLE ID '(' tupleParamList ')' tupleIdList SEMI",
    "idList : idList COMMA ID",
    "idList : idList COMMA MUL ID",
    "idList : ID",
    "idList : MUL ID",
    "dimensionDecl : dimensionDecl '[' NUM ']'",
    "dimensionDecl : '[' NUM ']'",
    "mainBlock : TYPE_INT MAIN '(' ')' '{' localDeclBlock body '}'",
    "statementList : statementList statement",
    "statementList : statement",
    "statement : inputStatement",
    "statement : outputStatement",
    "statement : assignmentStatement",
    "statement : ifStatement",
    "statement : whileStatement",
    "statement : KW_BREAK SEMI",
    "statement : KW_CONTINUE SEMI",
    "statement : repeatUntilStatement",
    "statement : doWhileStatement",
    "statement : KW_BRKP SEMI",
    "statement : functionCall SEMI",
    "statement : returnStatement SEMI",
    "returnStatement : KW_RETURN expr",
    "inputStatement : READ '(' ID ')' SEMI",
    "inputStatement : READ '(' ID dimensionUsage ')' SEMI",
    "outputStatement : WRITE '(' expr ')' SEMI",
    "assignmentStatement : ID ASSIGN expr SEMI",
    "assignmentStatement : ID dimensionUsage ASSIGN expr SEMI",
    "assignmentStatement : MUL ID ASSIGN expr SEMI",
    "assignmentStatement : ID INCREMENT SEMI",
    "assignmentStatement : ID DECREMENT SEMI",
    "assignmentStatement : compoundAssignment SEMI",
    "assignmentStatement : tupleAssignmentStatement SEMI",
    "tupleAssignmentStatement : ID DOT ID ASSIGN expr",
    "tupleAssignmentStatement : ID ARROW ID ASSIGN expr",
    "compoundAssignment : ID ASSIGN_ADD expr",
    "compoundAssignment : ID ASSIGN_SUB expr",
    "compoundAssignment : ID ASSIGN_MUL expr",
    "compoundAssignment : ID ASSIGN_DIV expr",
    "compoundAssignment : ID ASSIGN_MOD expr",
    "dimensionUsage : dimensionUsage '[' expr ']'",
    "dimensionUsage : '[' expr ']'",
    "ifStatement : KW_IF '(' boolexpr ')' KW_THEN statementList KW_ELSE statementList KW_ENDIF",
    "ifStatement : KW_IF '(' boolexpr ')' KW_THEN statementList KW_ENDIF",
    "whileStatement : KW_WHILE '(' boolexpr ')' KW_DO statementList KW_ENDWHILE",
    "repeatUntilStatement : KW_REPEAT statementList KW_UNTIL '(' boolexpr ')' SEMI",
    "doWhileStatement : KW_DO statementList KW_WHILE '(' boolexpr ')' SEMI",
    "expr : expr PLUS expr",
    "expr : expr MINUS expr",
    "expr : expr MUL expr",
    "expr : expr DIV expr",
    "expr : expr MOD expr",
    "expr : '(' expr ')'",
    "expr : NUM",
    "expr : ID",
    "expr : STRING_LITERAL",
    "expr : ID dimensionUsage",
    "expr : MUL ID",
    "expr : AMPERSAND ID",
    "expr : functionCall",
    "expr : tupleAccess",
    "tupleAccess : ID DOT ID",
    "tupleAccess : ID ARROW ID",
    "functionCall : ID '(' ')'",
    "functionCall : ID '(' argList ')'",
    "argList : argList COMMA expr",
    "argList : expr",
    "boolexpr : expr LE expr",
    "boolexpr : expr LT expr",
    "boolexpr : expr GE expr",
    "boolexpr : expr GT expr",
    "boolexpr : expr NE expr",
    "boolexpr : expr EQ expr",
    "boolexpr : boolexpr OR boolexpr",
    "boolexpr : boolexpr AND boolexpr",
    "boolexpr : NOT boolexpr",
    "boolexpr : '(' boolexpr ')'",

};
#endif

#if YYDEBUG
int yydebug;
#endif

int yyerrflag;
int yychar;
YYSTYPE yyval;
YYSTYPE yylval;
int yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE yyloc;  /* position returned by actions */
YYLTYPE yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n)                             \
    do {                                                        \
        if (n == 0) {                                           \
            (loc).first_line = YYRHSLOC(rhs, 0).last_line;      \
            (loc).first_column = YYRHSLOC(rhs, 0).last_column;  \
            (loc).last_line = YYRHSLOC(rhs, 0).last_line;       \
            (loc).last_column = YYRHSLOC(rhs, 0).last_column;   \
        } else {                                                \
            (loc).first_line = YYRHSLOC(rhs, 1).first_line;     \
            (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
            (loc).last_line = YYRHSLOC(rhs, n).last_line;       \
            (loc).last_column = YYRHSLOC(rhs, n).last_column;   \
        }                                                       \
    } while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct
{
    unsigned stacksize;
    YYINT *s_base;
    YYINT *s_mark;
    YYINT *s_last;
    YYSTYPE *l_base;
    YYSTYPE *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *p_base;
    YYLTYPE *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s {
    struct YYParseState_s *save; /* Previously saved parser state */
    YYSTACKDATA yystack;         /* saved parser stack */
    int state;                   /* saved parser state */
    int errflag;                 /* saved error recovery status */
    int lexeme;                  /* saved index of the conflict lexeme in the lexical queue */
    YYINT ctry;                  /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT *yylexp = 0;

static YYINT *yylexemes = 0;
#endif /* YYBTYACC */
#line 280 "parser.y"

void yyerror(char const *msg) {
    printf("[Error] : %s in line: %d\n", msg, lineNumber);
    return;
}

int main() {
    target_file = fopen(INTERMEDIATE_FILE, "w");
    FILE *source_file = fopen(SOURCE_FILE, "r");

    yyin = source_file;

    generateHeader();
    fprintf(target_file, "CALL MAIN\n");

    return yyparse();
}
#line 849 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h> /* needed for printf */
#endif

#include <stdlib.h> /* needed for malloc, etc */
#include <string.h> /* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data) {
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int)(data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data) {
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif                    /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size) {
    YYParseState *p = (YYParseState *)malloc(sizeof(YYParseState));
    if (p == NULL)
        return NULL;

    p->yystack.stacksize = size;
    if (size == 0) {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base = (YYINT *)malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL)
        return NULL;
    p->yystack.l_base = (YYSTYPE *)malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL)
        return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base = (YYLTYPE *)malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL)
        return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p) {
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
#if YYBTYACC
#define YYVALID           \
    do {                  \
        if (yyps->save)   \
            goto yyvalid; \
    } while (0)
#define YYVALID_NESTED             \
    do {                           \
        if (yyps->save &&          \
            yyps->save->save == 0) \
            goto yyvalid;          \
    } while (0)
#endif /* YYBTYACC */

int YYPARSE_DECL() {
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0) {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0);
    if (yyps == 0)
        goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM)
        goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0)
        goto yyreduce;
    if (yychar < 0) {
#if YYBTYACC
        do {
            if (yylvp < yylve) {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save) {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim) { /* Enlarge lexical value queue */
                    size_t p = (size_t)(yylvp - yylvals);
                    size_t s = (size_t)(yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp = yylexemes + p;
                }
                *yylexp = (YYINT)YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0)
            yychar = YYEOF;
#if YYDEBUG
        if (yydebug) {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL)
                yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                    YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yychar) {
        YYINT ctry;

        if (yypath) {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                        YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate)
                YYABORT;
            yyFreeState(save);
        } else {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug) {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL)
                goto yyenomem;
            save->save = yyps->save;
            save->state = yystate;
            save->errflag = yyerrflag;
            save->yystack.s_mark = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy(save->yystack.s_base, yystack.s_base, (size_t)(yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy(save->yystack.l_base, yystack.l_base, (size_t)(yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy(save->yystack.p_base, yystack.p_base, (size_t)(yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry = yytable[yyn];
            if (yyctable[ctry] == -1) {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL) {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes) {
                    yylexemes = (YYINT *)malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL)
                        goto yyenomem;
                    yylvals = (YYSTYPE *)malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL)
                        goto yyenomem;
                    yylvlim = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns = (YYLTYPE *)malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL)
                        goto yyenomem;
                    yylplim = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve) {
                    yylvp = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF) {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp = (YYINT)yychar;
                        yychar = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF) {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int)(yylvp - yylvals);
            yyps->save = save;
        }
        if (yytable[yyn] == ctry) {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                        YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0) {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT)yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar = YYEMPTY;
            if (yyerrflag > 0)
                --yyerrflag;
            goto yyloop;
        } else {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yychar) {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                    YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
            goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)
            --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yychar) {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0)
        goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save) {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                    YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals) {
            /* Free old saved error context state */
            if (yyerrctx)
                yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL)
                goto yyenomem;
            yyerrctx->save = yyps->save;
            yyerrctx->state = yystate;
            yyerrctx->errflag = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy(yyerrctx->yystack.s_base, yystack.s_base, (size_t)(yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy(yyerrctx->yystack.l_base, yystack.l_base, (size_t)(yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy(yyerrctx->yystack.p_base, yystack.p_base, (size_t)(yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme = (int)(yylvp - yylvals);
        }
        yylvp = yylvals + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp = yylpsns + save->lexeme;
#endif
        yylexp = yylexemes + save->lexeme;
        yychar = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy(yystack.s_base, save->yystack.s_base, (size_t)(yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy(yystack.l_base, save->yystack.l_base, (size_t)(yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy(yystack.p_base, save->yystack.p_base, (size_t)(yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry = ++save->ctry;
        yystate = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0)
            goto yyreduce;
        yyps->save = save->save;
        save->save = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save) {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                        YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp = yylvals + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp = yylpsns + yyerrctx->lexeme;
#endif
            yylexp = yylexemes + yyerrctx->lexeme;
            yychar = yylexp[-1];
            yylval = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy(yystack.s_base, yyerrctx->yystack.s_base, (size_t)(yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy(yystack.l_base, yyerrctx->yystack.l_base, (size_t)(yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy(yystack.p_base, yyerrctx->yystack.p_base, (size_t)(yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0)
        goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3) {
        yyerrflag = 3;
        for (;;) {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)YYERRCODE) {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                            YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                    goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            } else {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                            YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base)
                    goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                YYDESTRUCT_CALL("error: discarding state",
                                yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    } else {
        if (yychar == YYEOF)
            goto yyabort;
#if YYDEBUG
        if (yydebug) {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL)
                yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                    YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug) {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0) {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--) {
                    if (i != yym)
                        fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1 - i]],
                                           yystack.l_mark[1 - i]),
                          stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1 - yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1 - yym];
    }
#endif

    switch (yyn) {
    case 1:
#line 56 "parser.y"
    {
        printf("Finished\n");
        exit(0);
    }
#line 1525 "y.tab.c"
    break;
    case 2:
#line 60 "parser.y"
    {
        /* $$ = NULL;*/
        /* generateCode(NULL);*/
    }
#line 1533 "y.tab.c"
    break;
    case 3:
#line 64 "parser.y"
    {
    }
#line 1540 "y.tab.c"
    break;
    case 4:
#line 69 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
        printf("reduced global decl\n");
        populateGST(yystack.l_mark[-1].node);
        printGSymbolTable();
    }
#line 1550 "y.tab.c"
    break;
    case 5:
#line 75 "parser.y"
    {
        yyval.node = NULL;
    }
#line 1555 "y.tab.c"
    break;
    case 6:
#line 78 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1560 "y.tab.c"
    break;
    case 7:
#line 79 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1565 "y.tab.c"
    break;
    case 8:
#line 82 "parser.y"
    {
        yyval.node = createDeclarationNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node);
    }
#line 1570 "y.tab.c"
    break;
    case 9:
#line 83 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1575 "y.tab.c"
    break;
    case 10:
#line 86 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1580 "y.tab.c"
    break;
    case 11:
#line 87 "parser.y"
    {
        yyval.node = createNewArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1585 "y.tab.c"
    break;
    case 12:
#line 88 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node));
    }
#line 1590 "y.tab.c"
    break;
    case 13:
#line 89 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-5].node, createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node));
    }
#line 1595 "y.tab.c"
    break;
    case 14:
#line 90 "parser.y"
    {
        yyval.node = createNewArrayNode(NULL, yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1600 "y.tab.c"
    break;
    case 15:
#line 91 "parser.y"
    {
        yyval.node = createNewPointerNode(yystack.l_mark[0].node);
    }
#line 1605 "y.tab.c"
    break;
    case 16:
#line 92 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1610 "y.tab.c"
    break;
    case 17:
#line 93 "parser.y"
    {
        yyval.node = createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1615 "y.tab.c"
    break;
    case 18:
#line 96 "parser.y"
    {
        yyval.node = createGlobalTupleTypeNode(yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1620 "y.tab.c"
    break;
    case 19:
#line 99 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1625 "y.tab.c"
    break;
    case 20:
#line 100 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1630 "y.tab.c"
    break;
    case 21:
#line 103 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1635 "y.tab.c"
    break;
    case 22:
#line 106 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1640 "y.tab.c"
    break;
    case 23:
#line 107 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node));
    }
#line 1645 "y.tab.c"
    break;
    case 24:
#line 108 "parser.y"
    {
        yyval.node = createNewPointerNode(yystack.l_mark[0].node);
    }
#line 1650 "y.tab.c"
    break;
    case 25:
#line 109 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1655 "y.tab.c"
    break;
    case 26:
#line 112 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1660 "y.tab.c"
    break;
    case 27:
#line 113 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1665 "y.tab.c"
    break;
    case 28:
#line 114 "parser.y"
    {
        yyval.node = NULL;
    }
#line 1670 "y.tab.c"
    break;
    case 29:
#line 117 "parser.y"
    {
        yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, false);
    }
#line 1675 "y.tab.c"
    break;
    case 30:
#line 118 "parser.y"
    {
        yyval.node = createPointerParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, false);
    }
#line 1680 "y.tab.c"
    break;
    case 31:
#line 121 "parser.y"
    {
        yyval.node = createTypeNode(INT);
    }
#line 1685 "y.tab.c"
    break;
    case 32:
#line 122 "parser.y"
    {
        yyval.node = createTypeNode(STRING);
    }
#line 1690 "y.tab.c"
    break;
    case 33:
#line 125 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1695 "y.tab.c"
    break;
    case 34:
#line 126 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1700 "y.tab.c"
    break;
    case 35:
#line 130 "parser.y"
    {
        currentFunction = lookupGST(yystack.l_mark[-3].node->varName);
    }
#line 1705 "y.tab.c"
    break;
    case 36:
#line 132 "parser.y"
    {
        yyval.node = createFunctionDefinitionNode(yystack.l_mark[-9].node, yystack.l_mark[-8].node, yystack.l_mark[-6].node, yystack.l_mark[-2].node, yystack.l_mark[-1].node);
    }
#line 1710 "y.tab.c"
    break;
    case 37:
#line 135 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1715 "y.tab.c"
    break;
    case 38:
#line 138 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1720 "y.tab.c"
    break;
    case 39:
#line 139 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1725 "y.tab.c"
    break;
    case 40:
#line 140 "parser.y"
    {
        yyval.node = NULL;
    }
#line 1730 "y.tab.c"
    break;
    case 41:
#line 143 "parser.y"
    {
        yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, true);
    }
#line 1735 "y.tab.c"
    break;
    case 42:
#line 144 "parser.y"
    {
        yyval.node = createPointerParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, true);
    }
#line 1740 "y.tab.c"
    break;
    case 43:
#line 147 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1745 "y.tab.c"
    break;
    case 44:
#line 148 "parser.y"
    {
        yyval.node = NULL;
    }
#line 1750 "y.tab.c"
    break;
    case 45:
#line 151 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1755 "y.tab.c"
    break;
    case 46:
#line 152 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1760 "y.tab.c"
    break;
    case 47:
#line 153 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1765 "y.tab.c"
    break;
    case 48:
#line 156 "parser.y"
    {
        yyval.node = createLocalDeclarationNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node);
    }
#line 1770 "y.tab.c"
    break;
    case 49:
#line 159 "parser.y"
    {
        yyval.node = createLocalTupleTypeDeclarationNode(yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1775 "y.tab.c"
    break;
    case 50:
#line 162 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1780 "y.tab.c"
    break;
    case 51:
#line 163 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node));
    }
#line 1785 "y.tab.c"
    break;
    case 52:
#line 164 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1790 "y.tab.c"
    break;
    case 53:
#line 165 "parser.y"
    {
        yyval.node = createNewPointerNode(yystack.l_mark[0].node);
    }
#line 1795 "y.tab.c"
    break;
    case 54:
#line 168 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1800 "y.tab.c"
    break;
    case 55:
#line 169 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1805 "y.tab.c"
    break;
    case 56:
#line 172 "parser.y"
    {
        yyval.node = createMainNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node);
    }
#line 1810 "y.tab.c"
    break;
    case 57:
#line 175 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1815 "y.tab.c"
    break;
    case 58:
#line 176 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1820 "y.tab.c"
    break;
    case 59:
#line 179 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1825 "y.tab.c"
    break;
    case 60:
#line 180 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1830 "y.tab.c"
    break;
    case 61:
#line 181 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1835 "y.tab.c"
    break;
    case 62:
#line 182 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1840 "y.tab.c"
    break;
    case 63:
#line 183 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1845 "y.tab.c"
    break;
    case 64:
#line 184 "parser.y"
    {
        yyval.node = createBreakNode();
    }
#line 1850 "y.tab.c"
    break;
    case 65:
#line 185 "parser.y"
    {
        yyval.node = createContinueNode();
    }
#line 1855 "y.tab.c"
    break;
    case 66:
#line 186 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1860 "y.tab.c"
    break;
    case 67:
#line 187 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1865 "y.tab.c"
    break;
    case 68:
#line 188 "parser.y"
    {
        yyval.node = createBreakPointNode();
    }
#line 1870 "y.tab.c"
    break;
    case 69:
#line 189 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1875 "y.tab.c"
    break;
    case 70:
#line 190 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1880 "y.tab.c"
    break;
    case 71:
#line 193 "parser.y"
    {
        yyval.node = createReturnNode(yystack.l_mark[0].node);
    }
#line 1885 "y.tab.c"
    break;
    case 72:
#line 196 "parser.y"
    {
        yyval.node = createReadNode(yystack.l_mark[-2].node);
    }
#line 1890 "y.tab.c"
    break;
    case 73:
#line 197 "parser.y"
    {
        yyval.node = createReadToArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node);
    }
#line 1895 "y.tab.c"
    break;
    case 74:
#line 200 "parser.y"
    {
        yyval.node = createWriteNode(yystack.l_mark[-2].node);
    }
#line 1900 "y.tab.c"
    break;
    case 75:
#line 203 "parser.y"
    {
        yyval.node = createAssignNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1905 "y.tab.c"
    break;
    case 76:
#line 204 "parser.y"
    {
        yyval.node = createArrayAssignNode(yystack.l_mark[-4].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1910 "y.tab.c"
    break;
    case 77:
#line 205 "parser.y"
    {
        yyval.node = createAssignToDereferencedNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1915 "y.tab.c"
    break;
    case 78:
#line 206 "parser.y"
    {
        yyval.node = createIncrementNode(yystack.l_mark[-2].node);
    }
#line 1920 "y.tab.c"
    break;
    case 79:
#line 207 "parser.y"
    {
        yyval.node = createDecrementNode(yystack.l_mark[-2].node);
    }
#line 1925 "y.tab.c"
    break;
    case 80:
#line 208 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1930 "y.tab.c"
    break;
    case 81:
#line 209 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1935 "y.tab.c"
    break;
    case 82:
#line 212 "parser.y"
    {
        yyval.node = createTupleAssignmentNode(yystack.l_mark[-4].node, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1940 "y.tab.c"
    break;
    case 83:
#line 213 "parser.y"
    {
        yyval.node = createTuplePointerAssignmentNode(yystack.l_mark[-4].node, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1945 "y.tab.c"
    break;
    case 84:
#line 216 "parser.y"
    {
        yyval.node = createCompoundAssignNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1950 "y.tab.c"
    break;
    case 85:
#line 217 "parser.y"
    {
        yyval.node = createCompoundAssignNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1955 "y.tab.c"
    break;
    case 86:
#line 218 "parser.y"
    {
        yyval.node = createCompoundAssignNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1960 "y.tab.c"
    break;
    case 87:
#line 219 "parser.y"
    {
        yyval.node = createCompoundAssignNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1965 "y.tab.c"
    break;
    case 88:
#line 220 "parser.y"
    {
        yyval.node = createCompoundAssignNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1970 "y.tab.c"
    break;
    case 89:
#line 223 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1975 "y.tab.c"
    break;
    case 90:
#line 224 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1980 "y.tab.c"
    break;
    case 91:
#line 227 "parser.y"
    {
        yyval.node = createIfElseNode(yystack.l_mark[-6].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1985 "y.tab.c"
    break;
    case 92:
#line 228 "parser.y"
    {
        yyval.node = createIfNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node);
    }
#line 1990 "y.tab.c"
    break;
    case 93:
#line 231 "parser.y"
    {
        yyval.node = createWhileNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node);
    }
#line 1995 "y.tab.c"
    break;
    case 94:
#line 234 "parser.y"
    {
        yyval.node = createRepeatUntilNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node);
    }
#line 2000 "y.tab.c"
    break;
    case 95:
#line 237 "parser.y"
    {
        yyval.node = createDoWhileNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node);
    }
#line 2005 "y.tab.c"
    break;
    case 96:
#line 240 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2010 "y.tab.c"
    break;
    case 97:
#line 241 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2015 "y.tab.c"
    break;
    case 98:
#line 242 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2020 "y.tab.c"
    break;
    case 99:
#line 243 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2025 "y.tab.c"
    break;
    case 100:
#line 244 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2030 "y.tab.c"
    break;
    case 101:
#line 245 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 2035 "y.tab.c"
    break;
    case 102:
#line 246 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 2040 "y.tab.c"
    break;
    case 103:
#line 247 "parser.y"
    {
        yyval.node = createVariableUsageNode(yystack.l_mark[0].node->varName);
    }
#line 2045 "y.tab.c"
    break;
    case 104:
#line 248 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 2050 "y.tab.c"
    break;
    case 105:
#line 249 "parser.y"
    {
        yyval.node = createArrayAccessNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 2055 "y.tab.c"
    break;
    case 106:
#line 250 "parser.y"
    {
        yyval.node = createDereferenceNode(yystack.l_mark[0].node);
    }
#line 2060 "y.tab.c"
    break;
    case 107:
#line 251 "parser.y"
    {
        yyval.node = createAddressToNode(yystack.l_mark[0].node);
    }
#line 2065 "y.tab.c"
    break;
    case 108:
#line 252 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 2070 "y.tab.c"
    break;
    case 109:
#line 253 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 2075 "y.tab.c"
    break;
    case 110:
#line 256 "parser.y"
    {
        yyval.node = createTupleAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2080 "y.tab.c"
    break;
    case 111:
#line 257 "parser.y"
    {
        yyval.node = createTuplePointerAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2085 "y.tab.c"
    break;
    case 112:
#line 260 "parser.y"
    {
        yyval.node = createFunctionCallNode(yystack.l_mark[-2].node, NULL);
    }
#line 2090 "y.tab.c"
    break;
    case 113:
#line 261 "parser.y"
    {
        yyval.node = createFunctionCallNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 2095 "y.tab.c"
    break;
    case 114:
#line 263 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2100 "y.tab.c"
    break;
    case 115:
#line 264 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 2105 "y.tab.c"
    break;
    case 116:
#line 267 "parser.y"
    {
        yyval.node = createConditionNode(NODE_LE, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2110 "y.tab.c"
    break;
    case 117:
#line 268 "parser.y"
    {
        yyval.node = createConditionNode(NODE_LT, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2115 "y.tab.c"
    break;
    case 118:
#line 269 "parser.y"
    {
        yyval.node = createConditionNode(NODE_GE, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2120 "y.tab.c"
    break;
    case 119:
#line 270 "parser.y"
    {
        yyval.node = createConditionNode(NODE_GT, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2125 "y.tab.c"
    break;
    case 120:
#line 271 "parser.y"
    {
        yyval.node = createConditionNode(NODE_NE, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2130 "y.tab.c"
    break;
    case 121:
#line 272 "parser.y"
    {
        yyval.node = createConditionNode(NODE_EQ, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2135 "y.tab.c"
    break;
    case 122:
#line 273 "parser.y"
    {
        yyval.node = createConditionNode(NODE_OR, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2140 "y.tab.c"
    break;
    case 123:
#line 274 "parser.y"
    {
        yyval.node = createConditionNode(NODE_AND, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 2145 "y.tab.c"
    break;
    case 124:
#line 275 "parser.y"
    {
        yyval.node = createConditionNode(NODE_NOT, yystack.l_mark[0].node, NULL);
    }
#line 2150 "y.tab.c"
    break;
    case 125:
#line 276 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 2155 "y.tab.c"
    break;
#line 2157 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0) {
#if YYDEBUG
        if (yydebug) {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0) {
#if YYBTYACC
            do {
                if (yylvp < yylve) {
                    /* we're currently re-reading tokens */
                    yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylloc = *yylpp++;
#endif
                    yychar = *yylexp++;
                    break;
                }
                if (yyps->save) {
                    /* in trial mode; save scanner results for future parse attempts */
                    if (yylvp == yylvlim) { /* Enlarge lexical value queue */
                        size_t p = (size_t)(yylvp - yylvals);
                        size_t s = (size_t)(yylvlim - yylvals);

                        s += YYLVQUEUEGROWTH;
                        if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                            goto yyenomem;
                        if ((yylvals = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                            goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        if ((yylpsns = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                            goto yyenomem;
#endif
                        yylvp = yylve = yylvals + p;
                        yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        yylpp = yylpe = yylpsns + p;
                        yylplim = yylpsns + s;
#endif
                        yylexp = yylexemes + p;
                    }
                    *yylexp = (YYINT)YYLEX;
                    *yylvp++ = yylval;
                    yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    *yylpp++ = yylloc;
                    yylpe++;
#endif
                    yychar = *yylexp++;
                    break;
                }
                /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
                yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0)
                yychar = YYEOF;
#if YYDEBUG
            if (yydebug) {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL)
                    yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                        YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF)
            goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug) {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        goto yyoverflow;
    *++yystack.s_mark = (YYINT)yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath)
        YYABORT;
    while (yyps->save) {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx) {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp = yylpsns + yypath->lexeme;
#endif
    yylexp = yylexemes + yypath->lexeme;
    yychar = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy(yystack.s_base, yypath->yystack.s_base, (size_t)(yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy(yystack.l_base, yypath->yystack.l_base, (size_t)(yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy(yystack.p_base, yypath->yystack.p_base, (size_t)(yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save)
        goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
            YYDESTRUCT_CALL("cleanup: discarding state",
                            yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
            YYDESTRUCT_CALL("cleanup: discarding state",
                            yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx) {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps) {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath) {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
