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
#include <stdio.h>
#include <stdlib.h>
#include "node/node.h"
#include "code_gen/code_gen.h"
#include "define/constants.h"
#include "g_symbol_table/g_symbol_table.h"
#include "util/util.h"

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
#line 18 "parser.y"
typedef union YYSTYPE
{
    struct tnode *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {
    -1,
    0,
    0,
    12,
    12,
    13,
    13,
    14,
    16,
    16,
    15,
    15,
    15,
    15,
    15,
    15,
    17,
    17,
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
    4,
    4,
    5,
    6,
    6,
    6,
    18,
    18,
    8,
    8,
    7,
    9,
    10,
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
    11,
    11,
    11,
    11,
    11,
    11,
    11,
    11,
    11,
    11,
};
static const YYINT yylen[] = {
    2,
    4,
    3,
    3,
    2,
    2,
    1,
    3,
    1,
    1,
    3,
    4,
    4,
    2,
    2,
    1,
    4,
    3,
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
    5,
    6,
    5,
    4,
    5,
    5,
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
    4,
    8,
    9,
    0,
    6,
    0,
    0,
    0,
    0,
    0,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    19,
    20,
    21,
    22,
    24,
    23,
    27,
    28,
    3,
    5,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    25,
    26,
    0,
    1,
    18,
    0,
    0,
    14,
    7,
    0,
    0,
    48,
    50,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    52,
    53,
    0,
    0,
    0,
    0,
    0,
    0,
    32,
    36,
    0,
    0,
    0,
    0,
    0,
    0,
    62,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    17,
    0,
    0,
    12,
    47,
    0,
    44,
    0,
    45,
    46,
    33,
    35,
    29,
    0,
    31,
    34,
    63,
    0,
    0,
    0,
    0,
    0,
    0,
    61,
    0,
    0,
    0,
    0,
    0,
    16,
    30,
    0,
    0,
    0,
    0,
    0,
    38,
    39,
    41,
    40,
    0,
    37,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {
    0,
    276,
    298,
    289,
    310,
    290,
    291,
    292,
    311,
    312,
    314,
    257,
    260,
    261,
    263,
    277,
    278,
    282,
    283,
    285,
    286,
    287,
    300,
    301,
    302,
    303,
    304,
    305,
    306,
    307,
    308,
    290,
    312,
    257,
    263,
    313,
    267,
    91,
    316,
    40,
    40,
    257,
    40,
    40,
    300,
    268,
    268,
    300,
    277,
    301,
    91,
    315,
    257,
    268,
    293,
    257,
    258,
    259,
    263,
    269,
    40,
    299,
    299,
    267,
    91,
    257,
    299,
    267,
    296,
    40,
    299,
    309,
    309,
    282,
    288,
    258,
    91,
    257,
    263,
    316,
    257,
    257,
    299,
    262,
    263,
    264,
    265,
    266,
    268,
    93,
    299,
    299,
    41,
    316,
    41,
    299,
    309,
    299,
    309,
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
    93,
    258,
    315,
    257,
    41,
    299,
    299,
    299,
    299,
    299,
    268,
    93,
    268,
    41,
    268,
    268,
    41,
    299,
    299,
    299,
    299,
    299,
    299,
    309,
    309,
    279,
    283,
    309,
    309,
    93,
    268,
    300,
    300,
    41,
    41,
    280,
    281,
    284,
    268,
    268,
    300,
    281,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {
    2,
    70,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    71,
    4,
    8,
    9,
    35,
    10,
    51,
    38,
};
static const YYINT yysindex[] = {
    -271,
    -245,
    0,
    -152,
    -127,
    0,
    0,
    0,
    -143,
    0,
    -223,
    -90,
    8,
    20,
    -222,
    0,
    37,
    45,
    140,
    -250,
    -210,
    140,
    89,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -28,
    -192,
    -257,
    85,
    85,
    -89,
    -185,
    85,
    -179,
    -40,
    -40,
    171,
    0,
    0,
    -236,
    0,
    0,
    -169,
    1,
    0,
    0,
    -187,
    3,
    0,
    0,
    -151,
    -131,
    85,
    -182,
    -83,
    85,
    85,
    -24,
    -38,
    85,
    -40,
    -40,
    173,
    -37,
    -35,
    65,
    74,
    34,
    -123,
    -28,
    -113,
    54,
    0,
    0,
    -18,
    85,
    85,
    85,
    85,
    85,
    0,
    0,
    -166,
    -78,
    -116,
    -22,
    -115,
    -144,
    0,
    66,
    -13,
    85,
    85,
    85,
    85,
    85,
    85,
    -40,
    -40,
    -125,
    -126,
    -40,
    -40,
    0,
    75,
    1,
    0,
    0,
    -162,
    0,
    -162,
    0,
    0,
    0,
    0,
    0,
    -97,
    0,
    0,
    0,
    -101,
    -101,
    -101,
    -101,
    -101,
    -101,
    0,
    -122,
    140,
    140,
    12,
    14,
    0,
    0,
    -170,
    99,
    -242,
    -94,
    140,
    0,
    0,
    0,
    0,
    130,
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
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -254,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -248,
    0,
    0,
    0,
    -32,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -239,
    0,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -237,
    0,
    0,
    16,
    0,
    30,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    18,
    21,
    23,
    25,
    27,
    32,
    0,
    -34,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
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
};
#endif
static const YYINT yygindex[] = {
    0,
    106,
    -5,
    -14,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -31,
    0,
    0,
    159,
    0,
    0,
    117,
    -33,
};
#define YYTABLESIZE 458
static const YYINT yytable[] = {
    69,
    37,
    64,
    94,
    107,
    1,
    108,
    60,
    49,
    49,
    89,
    53,
    72,
    44,
    15,
    122,
    47,
    92,
    45,
    124,
    13,
    11,
    79,
    115,
    12,
    13,
    149,
    14,
    127,
    10,
    49,
    11,
    93,
    49,
    33,
    41,
    54,
    96,
    98,
    15,
    34,
    137,
    16,
    51,
    3,
    13,
    17,
    18,
    39,
    19,
    20,
    21,
    74,
    144,
    10,
    145,
    11,
    42,
    46,
    57,
    40,
    49,
    56,
    50,
    55,
    52,
    54,
    37,
    58,
    64,
    77,
    43,
    65,
    59,
    134,
    135,
    78,
    42,
    138,
    139,
    83,
    84,
    85,
    86,
    87,
    43,
    88,
    11,
    67,
    75,
    12,
    13,
    76,
    14,
    37,
    51,
    83,
    84,
    85,
    86,
    87,
    84,
    121,
    86,
    87,
    109,
    80,
    115,
    16,
    42,
    146,
    147,
    17,
    18,
    110,
    19,
    20,
    21,
    83,
    84,
    85,
    86,
    87,
    43,
    126,
    60,
    81,
    111,
    49,
    49,
    11,
    142,
    143,
    12,
    13,
    112,
    14,
    49,
    5,
    6,
    7,
    151,
    61,
    62,
    114,
    64,
    66,
    31,
    6,
    7,
    15,
    16,
    123,
    125,
    136,
    17,
    18,
    137,
    19,
    20,
    21,
    83,
    84,
    85,
    86,
    87,
    82,
    32,
    140,
    90,
    91,
    141,
    105,
    95,
    150,
    97,
    0,
    36,
    63,
    83,
    84,
    85,
    86,
    87,
    83,
    84,
    85,
    86,
    87,
    116,
    117,
    118,
    119,
    120,
    113,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    128,
    129,
    130,
    131,
    132,
    133,
    0,
    0,
    0,
    0,
    0,
    0,
    55,
    56,
    57,
    0,
    0,
    0,
    58,
    83,
    84,
    85,
    86,
    87,
    59,
    49,
    49,
    49,
    49,
    49,
    0,
    49,
    0,
    49,
    49,
    49,
    49,
    49,
    49,
    83,
    84,
    85,
    86,
    87,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    68,
    105,
    106,
    105,
    106,
    60,
    49,
    49,
    51,
    51,
    51,
    51,
    51,
    0,
    51,
    0,
    51,
    51,
    51,
    51,
    51,
    51,
    42,
    0,
    42,
    105,
    106,
    0,
    42,
    0,
    42,
    42,
    42,
    42,
    42,
    42,
    43,
    0,
    43,
    0,
    51,
    51,
    43,
    0,
    43,
    43,
    43,
    43,
    43,
    43,
    105,
    106,
    105,
    106,
    42,
    42,
    57,
    57,
    0,
    56,
    56,
    55,
    55,
    54,
    54,
    58,
    58,
    0,
    43,
    43,
    59,
    59,
    83,
    84,
    85,
    86,
    87,
    0,
    0,
    0,
    99,
    100,
    101,
    102,
    103,
    104,
    55,
    56,
    57,
    0,
    11,
    0,
    58,
    12,
    13,
    0,
    14,
    0,
    59,
    0,
    11,
    0,
    0,
    12,
    13,
    0,
    14,
    0,
    0,
    0,
    48,
    16,
    0,
    0,
    0,
    17,
    18,
    0,
    19,
    20,
    21,
    16,
    0,
    0,
    0,
    17,
    18,
    148,
    19,
    20,
    21,
    11,
    0,
    0,
    12,
    13,
    0,
    14,
    0,
    0,
    0,
    11,
    0,
    0,
    12,
    13,
    0,
    14,
    0,
    0,
    0,
    0,
    16,
    0,
    0,
    152,
    17,
    18,
    0,
    19,
    20,
    21,
    16,
    0,
    0,
    0,
    17,
    18,
    0,
    19,
    20,
    21,
    11,
    0,
    0,
    12,
    13,
    0,
    14,
    83,
    84,
    85,
    86,
    87,
    0,
    0,
    0,
    99,
    100,
    101,
    102,
    103,
    104,
    16,
    0,
    0,
    0,
    73,
    18,
    0,
    19,
    20,
    21,
};
static const YYINT yycheck[] = {
    40,
    91,
    91,
    41,
    41,
    276,
    41,
    41,
    22,
    41,
    93,
    268,
    43,
    18,
    268,
    93,
    21,
    41,
    268,
    41,
    268,
    257,
    55,
    41,
    260,
    261,
    268,
    263,
    41,
    268,
    44,
    268,
    65,
    47,
    257,
    257,
    293,
    68,
    69,
    293,
    263,
    283,
    278,
    41,
    289,
    293,
    282,
    283,
    40,
    285,
    286,
    287,
    288,
    41,
    293,
    41,
    293,
    41,
    268,
    41,
    40,
    93,
    41,
    91,
    41,
    257,
    41,
    91,
    41,
    91,
    257,
    41,
    257,
    41,
    105,
    106,
    263,
    40,
    109,
    110,
    262,
    263,
    264,
    265,
    266,
    40,
    268,
    257,
    267,
    258,
    260,
    261,
    91,
    263,
    91,
    93,
    262,
    263,
    264,
    265,
    266,
    263,
    268,
    265,
    266,
    40,
    257,
    41,
    278,
    93,
    280,
    281,
    282,
    283,
    40,
    285,
    286,
    287,
    262,
    263,
    264,
    265,
    266,
    93,
    268,
    40,
    257,
    93,
    142,
    143,
    257,
    136,
    137,
    260,
    261,
    258,
    263,
    151,
    290,
    291,
    292,
    146,
    36,
    37,
    257,
    91,
    40,
    290,
    291,
    292,
    277,
    278,
    268,
    268,
    279,
    282,
    283,
    283,
    285,
    286,
    287,
    262,
    263,
    264,
    265,
    266,
    60,
    8,
    93,
    63,
    64,
    268,
    294,
    67,
    268,
    69,
    -1,
    267,
    267,
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
    83,
    84,
    85,
    86,
    87,
    77,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    99,
    100,
    101,
    102,
    103,
    104,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    257,
    258,
    259,
    -1,
    -1,
    -1,
    263,
    262,
    263,
    264,
    265,
    266,
    269,
    262,
    263,
    264,
    265,
    266,
    -1,
    268,
    -1,
    270,
    271,
    272,
    273,
    274,
    275,
    262,
    263,
    264,
    265,
    266,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    296,
    294,
    295,
    294,
    295,
    295,
    294,
    295,
    262,
    263,
    264,
    265,
    266,
    -1,
    268,
    -1,
    270,
    271,
    272,
    273,
    274,
    275,
    262,
    -1,
    264,
    294,
    295,
    -1,
    268,
    -1,
    270,
    271,
    272,
    273,
    274,
    275,
    262,
    -1,
    264,
    -1,
    294,
    295,
    268,
    -1,
    270,
    271,
    272,
    273,
    274,
    275,
    294,
    295,
    294,
    295,
    294,
    295,
    294,
    295,
    -1,
    294,
    295,
    294,
    295,
    294,
    295,
    294,
    295,
    -1,
    294,
    295,
    294,
    295,
    262,
    263,
    264,
    265,
    266,
    -1,
    -1,
    -1,
    270,
    271,
    272,
    273,
    274,
    275,
    257,
    258,
    259,
    -1,
    257,
    -1,
    263,
    260,
    261,
    -1,
    263,
    -1,
    269,
    -1,
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
    277,
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
    284,
    285,
    286,
    287,
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
    -1,
    263,
    -1,
    -1,
    -1,
    -1,
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
    257,
    -1,
    -1,
    260,
    261,
    -1,
    263,
    262,
    263,
    264,
    265,
    266,
    -1,
    -1,
    -1,
    270,
    271,
    272,
    273,
    274,
    275,
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
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#define YYUNDFTOKEN 317
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
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
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
    "$accept",
    "program",
    "expr",
    "statementList",
    "statement",
    "inputStatement",
    "outputStatement",
    "assignmentStatement",
    "whileStatement",
    "ifStatement",
    "repeatUntilStatement",
    "doWhileStatement",
    "boolexpr",
    "declarations",
    "declList",
    "decl",
    "varList",
    "type",
    "dimensionDecl",
    "dimensionUsage",
    "illegal-symbol",
};
static const char *const yyrule[] = {
    "$accept : program",
    "program : KW_BEGIN declarations statementList KW_END",
    "program : KW_BEGIN declarations KW_END",
    "declarations : KW_DECL declList KW_ENDDECL",
    "declarations : KW_DECL KW_ENDDECL",
    "declList : declList decl",
    "declList : decl",
    "decl : type varList SEMI",
    "type : TYPE_INT",
    "type : TYPE_STRING",
    "varList : varList COMMA ID",
    "varList : varList COMMA ID dimensionDecl",
    "varList : varList COMMA MUL ID",
    "varList : ID dimensionDecl",
    "varList : MUL ID",
    "varList : ID",
    "dimensionDecl : dimensionDecl '[' NUM ']'",
    "dimensionDecl : '[' NUM ']'",
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
    "inputStatement : READ '(' ID ')' SEMI",
    "inputStatement : READ '(' ID dimensionUsage ')' SEMI",
    "outputStatement : WRITE '(' expr ')' SEMI",
    "assignmentStatement : ID ASSIGN expr SEMI",
    "assignmentStatement : ID dimensionUsage ASSIGN expr SEMI",
    "assignmentStatement : MUL ID ASSIGN expr SEMI",
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
    do                                                          \
    {                                                           \
        if (n == 0)                                             \
        {                                                       \
            (loc).first_line = YYRHSLOC(rhs, 0).last_line;      \
            (loc).first_column = YYRHSLOC(rhs, 0).last_column;  \
            (loc).last_line = YYRHSLOC(rhs, 0).last_line;       \
            (loc).last_column = YYRHSLOC(rhs, 0).last_column;   \
        }                                                       \
        else                                                    \
        {                                                       \
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

struct YYParseState_s
{
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
#line 161 "parser.y"

void yyerror(char const *msg)
{
    printf("[Error] : %s in line: %d\n", msg, lineNumber);
    return;
}

int main()
{
    target_file = fopen(INTERMEDIATE_FILE, "w");
    FILE *source_file = fopen(SOURCE_FILE, "r");

    yyin = source_file;

    return yyparse();
}
#line 634 "y.tab.c"

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
static int yygrowstack(YYSTACKDATA *data)
{
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
static void yyfreestack(YYSTACKDATA *data)
{
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
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *)malloc(sizeof(YYParseState));
    if (p == NULL)
        return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
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
yyFreeState(YYParseState *p)
{
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
    do                    \
    {                     \
        if (yyps->save)   \
            goto yyvalid; \
    } while (0)
#define YYVALID_NESTED             \
    do                             \
    {                              \
        if (yyps->save &&          \
            yyps->save->save == 0) \
            goto yyvalid;          \
    } while (0)
#endif /* YYBTYACC */

int YYPARSE_DECL()
{
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

    if ((yys = getenv("YYDEBUG")) != 0)
    {
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
    if (yychar < 0)
    {
#if YYBTYACC
        do
        {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                { /* Enlarge lexical value queue */
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
        if (yydebug)
        {
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
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yychar)
    {
        YYINT ctry;

        if (yypath)
        {
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
        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
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
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
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
                if (yylvp == yylve)
                {
                    yylvp = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp = (YYINT)yychar;
                        yychar = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
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
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                        YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
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
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yychar)
    {
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
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)yychar)
    {
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
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                    YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
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
        if (!yyps->save)
        {
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
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT)YYERRCODE)
            {
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
            }
            else
            {
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
    }
    else
    {
        if (yychar == YYEOF)
            goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
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
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
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

    switch (yyn)
    {
    case 1:
#line 47 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node);
        generateCode(yystack.l_mark[-1].node);
        printf("Finished\n");
        exit(0);
    }
#line 1312 "y.tab.c"
    break;
    case 2:
#line 53 "parser.y"
    {
        yyval.node = NULL;
        generateCode(NULL);
    }
#line 1320 "y.tab.c"
    break;
    case 3:
#line 59 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
        populateGST(yystack.l_mark[-1].node);
        printGSymbolTable();
    }
#line 1329 "y.tab.c"
    break;
    case 4:
#line 64 "parser.y"
    {
        yyval.node = NULL;
    }
#line 1334 "y.tab.c"
    break;
    case 5:
#line 67 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1339 "y.tab.c"
    break;
    case 6:
#line 68 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1344 "y.tab.c"
    break;
    case 7:
#line 71 "parser.y"
    {
        yyval.node = createDeclarationNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node);
    }
#line 1349 "y.tab.c"
    break;
    case 8:
#line 74 "parser.y"
    {
        yyval.node = createTypeNode(INT);
    }
#line 1354 "y.tab.c"
    break;
    case 9:
#line 75 "parser.y"
    {
        yyval.node = createTypeNode(STRING);
    }
#line 1359 "y.tab.c"
    break;
    case 10:
#line 78 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1364 "y.tab.c"
    break;
    case 11:
#line 79 "parser.y"
    {
        yyval.node = createNewArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1369 "y.tab.c"
    break;
    case 12:
#line 80 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node));
    }
#line 1374 "y.tab.c"
    break;
    case 13:
#line 81 "parser.y"
    {
        yyval.node = createNewArrayNode(NULL, yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1379 "y.tab.c"
    break;
    case 14:
#line 82 "parser.y"
    {
        yyval.node = createNewPointerNode(yystack.l_mark[0].node);
    }
#line 1384 "y.tab.c"
    break;
    case 15:
#line 83 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1389 "y.tab.c"
    break;
    case 16:
#line 86 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1394 "y.tab.c"
    break;
    case 17:
#line 87 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1399 "y.tab.c"
    break;
    case 18:
#line 90 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1404 "y.tab.c"
    break;
    case 19:
#line 91 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1409 "y.tab.c"
    break;
    case 20:
#line 94 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1414 "y.tab.c"
    break;
    case 21:
#line 95 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1419 "y.tab.c"
    break;
    case 22:
#line 96 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1424 "y.tab.c"
    break;
    case 23:
#line 97 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1429 "y.tab.c"
    break;
    case 24:
#line 98 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1434 "y.tab.c"
    break;
    case 25:
#line 99 "parser.y"
    {
        yyval.node = createBreakNode();
    }
#line 1439 "y.tab.c"
    break;
    case 26:
#line 100 "parser.y"
    {
        yyval.node = createContinueNode();
    }
#line 1444 "y.tab.c"
    break;
    case 27:
#line 101 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1449 "y.tab.c"
    break;
    case 28:
#line 102 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1454 "y.tab.c"
    break;
    case 29:
#line 105 "parser.y"
    {
        yyval.node = createReadNode(yystack.l_mark[-2].node);
    }
#line 1459 "y.tab.c"
    break;
    case 30:
#line 106 "parser.y"
    {
        yyval.node = createReadToArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node);
    }
#line 1464 "y.tab.c"
    break;
    case 31:
#line 109 "parser.y"
    {
        yyval.node = createWriteNode(yystack.l_mark[-2].node);
    }
#line 1469 "y.tab.c"
    break;
    case 32:
#line 112 "parser.y"
    {
        yyval.node = createAssignNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1474 "y.tab.c"
    break;
    case 33:
#line 113 "parser.y"
    {
        yyval.node = createArrayAssignNode(yystack.l_mark[-4].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1479 "y.tab.c"
    break;
    case 34:
#line 114 "parser.y"
    {
        yyval.node = createAssignToDereferencedNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1484 "y.tab.c"
    break;
    case 35:
#line 117 "parser.y"
    {
        yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1489 "y.tab.c"
    break;
    case 36:
#line 118 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1494 "y.tab.c"
    break;
    case 37:
#line 121 "parser.y"
    {
        yyval.node = createIfElseNode(yystack.l_mark[-6].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
    }
#line 1499 "y.tab.c"
    break;
    case 38:
#line 122 "parser.y"
    {
        yyval.node = createIfNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node);
    }
#line 1504 "y.tab.c"
    break;
    case 39:
#line 125 "parser.y"
    {
        yyval.node = createWhileNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node);
    }
#line 1509 "y.tab.c"
    break;
    case 40:
#line 128 "parser.y"
    {
        yyval.node = createRepeatUntilNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node);
    }
#line 1514 "y.tab.c"
    break;
    case 41:
#line 131 "parser.y"
    {
        yyval.node = createDoWhileNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node);
    }
#line 1519 "y.tab.c"
    break;
    case 42:
#line 134 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1524 "y.tab.c"
    break;
    case 43:
#line 135 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1529 "y.tab.c"
    break;
    case 44:
#line 136 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1534 "y.tab.c"
    break;
    case 45:
#line 137 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1539 "y.tab.c"
    break;
    case 46:
#line 138 "parser.y"
    {
        yyval.node = createArithOpNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1544 "y.tab.c"
    break;
    case 47:
#line 139 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1549 "y.tab.c"
    break;
    case 48:
#line 140 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1554 "y.tab.c"
    break;
    case 49:
#line 141 "parser.y"
    {
        yyval.node = createVariableUsageNode(yystack.l_mark[0].node->varName);
    }
#line 1559 "y.tab.c"
    break;
    case 50:
#line 142 "parser.y"
    {
        yyval.node = yystack.l_mark[0].node;
    }
#line 1564 "y.tab.c"
    break;
    case 51:
#line 143 "parser.y"
    {
        yyval.node = createArrayAccessNode(yystack.l_mark[-1].node, yystack.l_mark[0].node);
    }
#line 1569 "y.tab.c"
    break;
    case 52:
#line 144 "parser.y"
    {
        yyval.node = createDereferenceNode(yystack.l_mark[0].node);
    }
#line 1574 "y.tab.c"
    break;
    case 53:
#line 145 "parser.y"
    {
        yyval.node = createAddressToNode(yystack.l_mark[0].node);
    }
#line 1579 "y.tab.c"
    break;
    case 54:
#line 148 "parser.y"
    {
        yyval.node = createConditionNode(NODE_LE, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1584 "y.tab.c"
    break;
    case 55:
#line 149 "parser.y"
    {
        yyval.node = createConditionNode(NODE_LT, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1589 "y.tab.c"
    break;
    case 56:
#line 150 "parser.y"
    {
        yyval.node = createConditionNode(NODE_GE, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1594 "y.tab.c"
    break;
    case 57:
#line 151 "parser.y"
    {
        yyval.node = createConditionNode(NODE_GT, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1599 "y.tab.c"
    break;
    case 58:
#line 152 "parser.y"
    {
        yyval.node = createConditionNode(NODE_NE, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1604 "y.tab.c"
    break;
    case 59:
#line 153 "parser.y"
    {
        yyval.node = createConditionNode(NODE_EQ, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1609 "y.tab.c"
    break;
    case 60:
#line 154 "parser.y"
    {
        yyval.node = createConditionNode(NODE_OR, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1614 "y.tab.c"
    break;
    case 61:
#line 155 "parser.y"
    {
        yyval.node = createConditionNode(NODE_AND, yystack.l_mark[-2].node, yystack.l_mark[0].node);
    }
#line 1619 "y.tab.c"
    break;
    case 62:
#line 156 "parser.y"
    {
        yyval.node = createConditionNode(NODE_NOT, yystack.l_mark[0].node, NULL);
    }
#line 1624 "y.tab.c"
    break;
    case 63:
#line 157 "parser.y"
    {
        yyval.node = yystack.l_mark[-1].node;
    }
#line 1629 "y.tab.c"
    break;
#line 1631 "y.tab.c"
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
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
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
        if (yychar < 0)
        {
#if YYBTYACC
            do
            {
                if (yylvp < yylve)
                {
                    /* we're currently re-reading tokens */
                    yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylloc = *yylpp++;
#endif
                    yychar = *yylexp++;
                    break;
                }
                if (yyps->save)
                {
                    /* in trial mode; save scanner results for future parse attempts */
                    if (yylvp == yylvlim)
                    { /* Enlarge lexical value queue */
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
            if (yydebug)
            {
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
    if (yydebug)
    {
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
    while (yyps->save)
    {
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
    if (yyerrctx)
    {
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
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
