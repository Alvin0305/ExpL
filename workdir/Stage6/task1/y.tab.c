/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20240109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 23 "parser.y"
typedef union YYSTYPE {
    struct tnode *node;
    struct FieldList *field;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
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

#define READ 257
#define WRITE 258
#define PLUS 259
#define MUL 260
#define MINUS 261
#define DIV 262
#define MOD 263
#define ASSIGN 264
#define SEMI 265
#define AMPERSAND 266
#define GT 267
#define GE 268
#define LT 269
#define LE 270
#define NE 271
#define EQ 272
#define KW_BEGIN 273
#define KW_END 274
#define KW_IF 275
#define KW_THEN 276
#define KW_ELSE 277
#define KW_ENDIF 278
#define KW_WHILE 279
#define KW_DO 280
#define KW_ENDWHILE 281
#define KW_BREAK 282
#define KW_CONTINUE 283
#define KW_REPEAT 284
#define KW_UNTIL 285
#define KW_DECL 286
#define KW_ENDDECL 287
#define TYPE_INT 288
#define TYPE_STRING 289
#define TYPE_VOID 290
#define COMMA 291
#define AND 292
#define OR 293
#define NOT 294
#define INCREMENT 295
#define DECREMENT 296
#define ASSIGN_ADD 297
#define ASSIGN_SUB 298
#define ASSIGN_MUL 299
#define ASSIGN_DIV 300
#define ASSIGN_MOD 301
#define KW_RETURN 302
#define MAIN 303
#define KW_BRKP 304
#define KW_TUPLE 305
#define DOT 306
#define ARROW 307
#define KW_TYPE 308
#define KW_ENDTYPE 309
#define ID 310
#define NUM 311
#define STRING_LITERAL 312
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   42,   42,   42,   45,   45,   45,   46,   46,   48,
   47,   44,   44,   43,   43,   43,   13,   13,   14,   14,
   15,   15,   16,   16,   16,   16,   16,   16,   16,   16,
   35,   36,   36,   38,   37,   37,   37,   37,   33,   33,
   33,   34,   34,   17,   17,   17,   17,   17,   24,   24,
   49,   25,   23,   20,   20,   20,   21,   21,   26,   26,
   26,   27,   27,   27,   27,   28,   39,   29,   29,   29,
   29,   18,   18,   22,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,   32,    4,
    4,    5,    6,    6,    6,    6,    6,    6,    6,   41,
   41,   41,   40,    7,    7,    7,    7,    7,   19,   19,
    9,    9,    8,   10,   11,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,   31,
   31,   30,   30,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,
};
static const YYINT yylen[] = {                            2,
    1,    4,    3,    1,    3,    2,    0,    2,    1,    0,
    5,    2,    1,    3,    3,    3,    3,    2,    2,    1,
    3,    2,    3,    4,    4,    6,    2,    2,    1,    4,
    6,    3,    1,    2,    3,    4,    2,    1,    3,    1,
    0,    2,    3,    1,    1,    2,    1,    1,    2,    1,
    0,   10,    3,    3,    1,    0,    2,    3,    3,    2,
    0,    2,    1,    2,    1,    3,    7,    3,    4,    1,
    2,    4,    3,    8,    2,    1,    1,    1,    1,    1,
    1,    2,    2,    1,    1,    2,    2,    2,    2,    5,
    6,    5,    4,    5,    5,    3,    3,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    4,    3,
    9,    7,    7,    7,    7,    3,    3,    3,    3,    3,
    3,    1,    1,    1,    2,    2,    2,    1,    1,    3,
    4,    3,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    4,    1,    0,    0,    6,   10,    0,
    9,    0,    0,    0,    0,    5,    8,   18,   44,   45,
   47,    0,   48,    0,   20,    0,    0,    0,    0,    0,
    3,    0,   50,    0,    0,    0,   17,   19,    0,    0,
    0,   22,   46,    0,    2,   49,    0,    0,    0,    0,
   13,    0,    0,   28,    0,    0,    0,   21,    0,    0,
    0,    0,    0,    0,    0,   11,   12,    0,    0,   33,
    0,    0,   40,    0,    0,    0,    0,    0,    0,   55,
   60,    0,    0,    0,   63,   65,    0,    0,   14,   15,
   16,   34,    0,    0,    0,   42,    0,   30,   73,    0,
   25,    0,    0,    0,   57,    0,   51,    0,    0,   70,
    0,   59,   62,   64,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   76,   77,   78,
   79,    0,   81,   80,   84,   85,    0,    0,    0,    0,
   74,   32,    0,   38,    0,   43,   39,   72,    0,   58,
   54,    0,    0,   71,   66,    0,    0,    0,    0,    0,
    0,    0,   82,   83,    0,    0,    0,    0,  122,  124,
    0,    0,  128,    0,   86,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   53,   75,
   98,   87,   88,   99,    0,    0,   37,    0,   26,    0,
    0,    0,   68,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  126,  127,    0,    0,    0,    0,    0,
    0,    0,    0,   96,   97,    0,    0,    0,    0,    0,
  101,  102,  130,    0,    0,    0,    0,    0,    0,  100,
    0,   35,    0,    0,   69,    0,    0,    0,    0,  142,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  121,    0,  118,    0,  119,  120,
   93,    0,  131,  110,    0,    0,   36,    0,    0,   90,
    0,   92,   95,  143,    0,    0,    0,    0,    0,    0,
  141,    0,    0,    0,    0,    0,    0,   94,  109,   52,
   67,   91,    0,    0,    0,    0,    0,  112,  113,  115,
  114,    0,  111,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  288,  308,  314,  336,  356,  359,  303,  309,  310,  360,
  361,  286,  327,   40,  362,  309,  361,  287,  288,  289,
  290,  305,  310,  328,  329,  331,  349,  288,  305,  331,
  336,  338,  339,   41,  123,  310,  287,  329,  260,  310,
  330,  265,  310,  310,  336,  339,  123,  288,  289,  310,
  357,  358,   40,  310,   40,   91,  332,  265,  291,   40,
  286,  340,  310,  310,  310,  125,  357,  331,  350,  352,
  331,  347,  348,  311,   91,  260,  310,  331,  334,  335,
  287,  305,  331,  341,  342,  353,  273,  337,  265,  265,
  265,  310,  291,   41,  260,  310,  291,   41,   93,  311,
  310,   40,  332,  260,  310,  291,   41,  310,  260,  310,
  343,  287,  342,  353,  257,  258,  260,  275,  279,  280,
  282,  283,  284,  302,  304,  310,  316,  317,  318,  319,
  320,  321,  322,  323,  324,  325,  345,  346,  354,  355,
  125,  352,  260,  310,  351,  310,  348,   93,  347,  310,
  335,  363,   40,  310,  265,  291,   40,   40,  310,   40,
   40,  316,  265,  265,  316,  260,  266,  310,  311,  312,
   40,  315,  345,  355,  265,  264,  295,  296,  297,  298,
  299,  300,  301,  306,  307,   40,   91,  333,  274,  317,
  265,  265,  265,  265,  264,  306,  310,  291,   41,  123,
  350,  260,  310,  310,  315,  264,  294,   40,  315,  326,
  326,  279,  285,  310,  310,  333,  315,  259,  260,  261,
  262,  263,  315,  265,  265,  315,  315,  315,  315,  315,
  310,  310,   41,  315,  344,  315,  264,   91,  315,  310,
  260,  310,  340,   41,  310,   41,  333,   41,  315,  326,
  315,  326,  267,  268,  269,  270,  271,  272,  292,  293,
   41,   41,   40,   40,   41,  315,  315,  315,  315,  315,
  265,  291,   41,   93,  315,  315,  310,  337,  351,  265,
   41,  265,  265,   41,  315,  315,  315,  315,  315,  315,
  326,  326,  276,  280,  326,  326,  315,  265,   93,  125,
  265,  265,  316,  316,   41,   41,  277,  278,  281,  265,
  265,  316,  278,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          3,
  209,  127,  128,  129,  130,  131,  132,  133,  134,  135,
  136,  210,   13,   24,   25,   41,   68,   57,  188,   79,
   80,    4,   88,   32,   33,   62,   84,   85,  111,  235,
  173,  138,   72,   73,   27,   69,  145,   70,   86,  139,
  174,    5,   51,   52,    6,   10,   11,   15,  152,
};
static const YYINT yysindex[] = {                      -232,
 -279, -280,    0,    0,    0, -251,   47,    0,    0, -156,
    0, -132,  181,   32,  -34,    0,    0,    0,    0,    0,
    0, -205,    0,  121,    0, -239, -154, -279, -201, -161,
    0,  181,    0,   38, -164,  120,    0,    0, -147,  -31,
 -255,    0,    0,  126,    0,    0, -118, -139, -138, -130,
    0, -119,  232,    0,  232, -122,   92,    0, -222,  232,
  127,  -69,  -62,  -54,  -52,    0,    0,  -98,  -36,    0,
 -219,  -25,    0,  128,  -87,  -88,   -6, -214,  -22,    0,
    0,  -82, -210,  134,    0,    0,  321,  105,    0,    0,
    0,    0,  232, -198,  -79,    0,  232,    0,    0,  139,
    0,  232,   92,  -76,    0,  232,    0,  200,  -68,    0,
 -237,    0,    0,    0,  201,  298,   42,  306,  319,  321,
   96,  111,  321,  -33,  117,  -39, -176,    0,    0,    0,
    0,  119,    0,    0,    0,    0,  122,  123,  124, -249,
    0,    0,   75,    0,  100,    0,    0,    0,  -15,    0,
    0,  279,  232,    0,    0, -177,   94,  -33,  141,  -40,
  -40,  354,    0,    0, -165,  102,  103,  -26,    0,    0,
  -33,  347,    0,  114,    0,  -33,  162,  164,  -33,  -33,
  -33,  -33,  -33,  131,  133,  -37,  -33,  -89,    0,    0,
    0,    0,    0,    0,  -33,  137,    0, -170,    0, -118,
   -4,  140,    0,   53,  -10,  -33,  -40,  -40,  -53,  -29,
   18,  366,  393,    0,    0,  343,  136,  -33,  -33,  -33,
  -33,  -33,  214,    0,    0,  347,  347,  347,  347,  347,
    0,    0,    0,  347,   -2,  -75,  -33,  -33,  347,    0,
  142,    0,  -69, -198,    0,  171,   60,  175,  299,    0,
  -24,   20,  -33,  -33,  -33,  -33,  -33,  -33,  -40,  -40,
  170,  169,  -40,  -40,    0,  -70,    0,  -70,    0,    0,
    0,  -33,    0,    0,  357,  -61,    0,  326, -144,    0,
  189,    0,    0,    0,  347,  347,  347,  347,  347,  347,
    0,  163,  321,  321,   25,   27,  347,    0,    0,    0,
    0,    0, -235,  244, -106,  197,  321,    0,    0,    0,
    0,  311,    0,
};
static const YYINT yyrindex[] = {                       179,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -161,    0,    0,
    0,    0,    0,    0,    0, -158,    0,    0,    0, -143,
    0,    0,    0,    0,    0,    0,  195,    0,    0,    0,
    0,    0,    0,    0,   10,    0, -127,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -124,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   10, -115,    0,    0,    0,    0, -158,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  213,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,    0,    0,
    0,  -62,    0,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  195,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   72,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  215,  216,  217,  219,  222,
    0,    0,    0,   36,    0,    0,    0,    0,  223,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   86,    0,  101,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,   31,   33,   56,   82,   88,
    0,  -28,    0,    0,    0,    0,   45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  277, -112, -107,    0,    0,    0,    0,    0,    0,    0,
    0, -128,    0,    0,  465,    0,  406,  415, -141,    0,
  387,  130,  251,    0,  468,  305,    0,  422,    0,    0,
  263,    0,  405,  412,    0,  358,  266,  420,  432,    0,
  280,    0,  466,    0,    0,    0,  507,    0,    0,
};
#define YYTABLESIZE 664
static const YYINT yytable[] = {                        208,
  186,  238,  171,  233,   94,   66,  171,  162,   55,   58,
  165,  261,  140,  186,  195,   98,  265,  274,  107,  190,
   39,  115,  116,    7,  117,  199,  216,  155,    8,    9,
  248,  299,  211,  102,   12,   59,  244,   76,  273,  118,
   95,  307,  308,  119,  120,  104,  121,  122,  123,  109,
   41,  187,   56,  156,  190,    1,  196,  190,  262,   56,
  284,  143,  247,  123,  187,  305,  124,  306,  125,  137,
   40,  136,   34,  135,  126,    2,  133,  129,  250,  252,
  115,  116,  202,  117,   56,  132,   14,   77,   35,  241,
   96,  115,  116,  246,  117,  105,  134,  189,  118,  110,
  281,   46,  119,  120,   36,  121,  122,  123,   43,  118,
   42,  144,  125,  119,  120,  123,  121,  122,  123,  213,
  301,   29,  138,   48,   49,  124,  116,  125,  139,  129,
  291,  292,  203,  126,  295,  296,  124,   27,  125,  242,
   23,  117,   31,  187,  126,   50,  198,   29,   44,   24,
  238,   46,   16,    9,   18,   19,   20,   21,  310,   53,
   47,   45,   54,   27,  125,   60,   23,   61,   48,   49,
   63,   64,   22,  294,  237,   24,  265,   23,  116,   65,
  303,  304,   75,  218,  219,  220,  221,  222,   74,  219,
   50,  221,  222,  117,  312,  190,  190,  218,  219,  220,
  221,  222,   89,   87,  190,  218,  219,  220,  221,  222,
   90,   92,   91,  253,  254,  255,  256,  257,  258,  166,
   99,  101,  166,  100,  176,  167,  166,  108,  167,  141,
  146,  148,  167,  150,  218,  219,  220,  221,  222,  153,
  157,  154,  253,  254,  255,  256,  257,  258,  218,  219,
  220,  221,  222,  207,   93,  177,  178,  179,  180,  181,
  182,  183,  259,  260,  140,   97,  184,  185,  106,  168,
  169,  170,  168,  169,  170,   97,  168,  169,  170,  184,
  185,  123,  123,  123,  123,  123,   93,  123,  272,  123,
  123,  123,  123,  123,  123,  129,  129,  129,  129,  129,
   41,  129,   56,  129,  129,  129,  129,  129,  129,  259,
  260,  259,  260,  123,  123,  123,  259,  260,  259,  260,
  137,  137,  136,  136,  135,  135,  133,  129,  129,  129,
  125,  125,  125,  125,  125,  132,  125,  158,  125,  125,
  125,  125,  125,  125,  116,  160,  116,  134,  134,  137,
  116,  159,  116,  116,  116,  116,  116,  116,  161,  117,
  163,  117,  125,  125,  125,  117,  140,  117,  117,  117,
  117,  117,  117,  138,  138,  164,  116,  116,  116,  139,
  139,  175,  137,  191,  197,  137,  192,  193,  194,  137,
  198,  117,  117,  117,  218,  219,  220,  221,  222,  140,
  172,  200,  140,  204,  206,  263,  140,   37,   19,   20,
   21,  214,  215,   81,   19,   20,   21,   26,   30,  196,
  112,   19,   20,   21,  137,   22,  224,  137,  225,   26,
   23,   82,  264,  238,  205,  280,   23,   30,   82,  282,
  231,  140,  232,   23,  140,  293,  240,  217,  294,  245,
  300,  277,  223,  302,  259,  226,  227,  228,  229,  230,
   71,  311,  234,  236,    7,   78,   83,   61,   28,   20,
   21,  239,  218,  219,  220,  221,  222,   31,  271,  104,
  105,  106,  249,  107,  251,   29,  108,  103,   38,   83,
   23,  103,  151,  278,  266,  267,  268,  269,  270,   46,
  115,  116,   71,  117,  243,  113,  149,   71,  147,  279,
  201,   78,  142,  275,  276,  114,   17,   67,  118,   19,
   20,   21,  119,  120,  309,  121,  122,  123,    0,  285,
  286,  287,  288,  289,  290,    0,   29,    0,    0,    0,
    0,   23,    0,    0,    0,  124,    0,  125,  297,    0,
    0,    0,    0,  126,    0,  137,  137,  218,  219,  220,
  221,  222,    0,  283,    0,  137,  137,  115,  116,  137,
  117,    0,  140,  140,  137,    0,    0,  115,  116,    0,
  117,    0,  140,  140,    0,  118,  140,    0,  313,  119,
  120,  140,  121,  122,  123,  118,    0,    0,    0,  119,
  120,    0,  121,  122,  123,  218,  219,  220,  221,  222,
  115,  116,  124,  117,  125,  218,  219,  220,  221,  222,
  126,  298,  124,    0,  125,    0,    0,    0,  118,    0,
  126,    0,  212,  120,    0,  121,  122,  123,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  124,    0,  125,    0,    0,
    0,    0,    0,  126,
};
static const YYINT yycheck[] = {                         40,
   40,   91,   40,   41,   41,  125,   40,  120,   40,  265,
  123,   41,   41,   40,  264,   41,   41,   93,   41,  127,
  260,  257,  258,  303,  260,   41,  168,  265,  309,  310,
   41,   93,  161,   40,  286,  291,   41,  260,   41,  275,
  260,  277,  278,  279,  280,  260,  282,  283,  284,  260,
   41,   91,   41,  291,  162,  288,  306,  165,   41,   91,
   41,  260,  204,   41,   91,   41,  302,   41,  304,   41,
  310,   41,   41,   41,  310,  308,   41,   41,  207,  208,
  257,  258,  260,  260,   91,   41,   40,  310,  123,  260,
  310,  257,  258,   41,  260,  310,   41,  274,  275,  310,
   41,  260,  279,  280,  310,  282,  283,  284,  310,  275,
  265,  310,   41,  279,  280,   93,  282,  283,  284,  285,
  265,  265,   41,  288,  289,  302,   41,  304,   41,   93,
  259,  260,  310,  310,  263,  264,  302,  265,  304,  310,
  265,   41,   13,   91,  310,  310,  291,  291,  310,  265,
   91,  310,  309,  310,  287,  288,  289,  290,  265,   40,
  123,   32,  310,  291,   93,   40,  291,  286,  288,  289,
  310,  310,  305,  280,  264,  291,   41,  310,   93,  310,
  293,  294,   91,  259,  260,  261,  262,  263,  311,  260,
  310,  262,  263,   93,  307,  303,  304,  259,  260,  261,
  262,  263,  265,  273,  312,  259,  260,  261,  262,  263,
  265,  310,  265,  267,  268,  269,  270,  271,  272,  260,
   93,  310,  260,  311,  264,  266,  260,  310,  266,  125,
  310,   93,  266,  310,  259,  260,  261,  262,  263,   40,
   40,  310,  267,  268,  269,  270,  271,  272,  259,  260,
  261,  262,  263,  294,  291,  295,  296,  297,  298,  299,
  300,  301,  292,  293,  293,  291,  306,  307,  291,  310,
  311,  312,  310,  311,  312,  291,  310,  311,  312,  306,
  307,  259,  260,  261,  262,  263,  291,  265,  291,  267,
  268,  269,  270,  271,  272,  259,  260,  261,  262,  263,
  291,  265,  291,  267,  268,  269,  270,  271,  272,  292,
  293,  292,  293,  291,  292,  293,  292,  293,  292,  293,
  292,  293,  292,  293,  292,  293,  291,  291,  292,  293,
  259,  260,  261,  262,  263,  291,  265,   40,  267,  268,
  269,  270,  271,  272,  259,   40,  261,  292,  293,   87,
  265,  310,  267,  268,  269,  270,  271,  272,   40,  259,
  265,  261,  291,  292,  293,  265,   87,  267,  268,  269,
  270,  271,  272,  292,  293,  265,  291,  292,  293,  292,
  293,  265,  120,  265,  310,  123,  265,  265,  265,  127,
  291,  291,  292,  293,  259,  260,  261,  262,  263,  120,
  124,  123,  123,  310,  264,   40,  127,  287,  288,  289,
  290,  310,  310,  287,  288,  289,  290,   12,   13,  306,
  287,  288,  289,  290,  162,  305,  265,  165,  265,   24,
  310,  305,   40,   91,  158,  265,  310,   32,  305,  265,
  310,  162,  310,  310,  165,  276,  310,  171,  280,  310,
  125,  310,  176,  265,  292,  179,  180,  181,  182,  183,
   55,  265,  186,  187,  286,   60,   61,  273,  288,  289,
  290,  195,  259,  260,  261,  262,  263,  265,  265,  265,
  265,  265,  206,  265,  208,  305,  265,  265,   24,   84,
  310,   77,  106,  243,  218,  219,  220,  221,  222,   32,
  257,  258,   97,  260,  200,   84,  102,  102,   97,  244,
  153,  106,   93,  237,  238,   84,   10,   52,  275,  288,
  289,  290,  279,  280,  281,  282,  283,  284,   -1,  253,
  254,  255,  256,  257,  258,   -1,  305,   -1,   -1,   -1,
   -1,  310,   -1,   -1,   -1,  302,   -1,  304,  272,   -1,
   -1,   -1,   -1,  310,   -1,  293,  294,  259,  260,  261,
  262,  263,   -1,  265,   -1,  303,  304,  257,  258,  307,
  260,   -1,  293,  294,  312,   -1,   -1,  257,  258,   -1,
  260,   -1,  303,  304,   -1,  275,  307,   -1,  278,  279,
  280,  312,  282,  283,  284,  275,   -1,   -1,   -1,  279,
  280,   -1,  282,  283,  284,  259,  260,  261,  262,  263,
  257,  258,  302,  260,  304,  259,  260,  261,  262,  263,
  310,  265,  302,   -1,  304,   -1,   -1,   -1,  275,   -1,
  310,   -1,  279,  280,   -1,  282,  283,  284,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  302,   -1,  304,   -1,   -1,
   -1,   -1,   -1,  310,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,
};
#endif
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 312
#define YYUNDFTOKEN 364
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","READ",
"WRITE","PLUS","MUL","MINUS","DIV","MOD","ASSIGN","SEMI","AMPERSAND","GT","GE",
"LT","LE","NE","EQ","KW_BEGIN","KW_END","KW_IF","KW_THEN","KW_ELSE","KW_ENDIF",
"KW_WHILE","KW_DO","KW_ENDWHILE","KW_BREAK","KW_CONTINUE","KW_REPEAT",
"KW_UNTIL","KW_DECL","KW_ENDDECL","TYPE_INT","TYPE_STRING","TYPE_VOID","COMMA",
"AND","OR","NOT","INCREMENT","DECREMENT","ASSIGN_ADD","ASSIGN_SUB","ASSIGN_MUL",
"ASSIGN_DIV","ASSIGN_MOD","KW_RETURN","MAIN","KW_BRKP","KW_TUPLE","DOT","ARROW",
"KW_TYPE","KW_ENDTYPE","ID","NUM","STRING_LITERAL","$accept","program","expr",
"statementList","statement","inputStatement","outputStatement",
"assignmentStatement","compoundAssignment","whileStatement","ifStatement",
"repeatUntilStatement","doWhileStatement","boolexpr","globalDeclarationsBlock",
"globalDeclarationList","globalDecl","globalVarList","type","dimensionDecl",
"dimensionUsage","paramList","param","mainBlock","body",
"functionDefinitionBlock","functionDefinition","localDeclBlock","localDeclList",
"localDecl","idList","argList","functionCall","returnStatement",
"funcDeclParamList","funcDeclParam","globalTupleDeclaration","tupleFieldList",
"tupleIdList","tupleField","localTupleDecl","fieldAssignmentStatement",
"memberAccess","programBody","typeField","typeFieldList","typeDefBlock",
"typeDefList","typeDef","$$1","$$2","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : programBody",
"programBody : typeDefBlock globalDeclarationsBlock functionDefinitionBlock mainBlock",
"programBody : typeDefBlock globalDeclarationsBlock mainBlock",
"programBody : mainBlock",
"typeDefBlock : KW_TYPE typeDefList KW_ENDTYPE",
"typeDefBlock : KW_TYPE KW_ENDTYPE",
"typeDefBlock :",
"typeDefList : typeDefList typeDef",
"typeDefList : typeDef",
"$$1 :",
"typeDef : ID $$1 '{' typeFieldList '}'",
"typeFieldList : typeFieldList typeField",
"typeFieldList : typeField",
"typeField : TYPE_INT ID SEMI",
"typeField : TYPE_STRING ID SEMI",
"typeField : ID ID SEMI",
"globalDeclarationsBlock : KW_DECL globalDeclarationList KW_ENDDECL",
"globalDeclarationsBlock : KW_DECL KW_ENDDECL",
"globalDeclarationList : globalDeclarationList globalDecl",
"globalDeclarationList : globalDecl",
"globalDecl : type globalVarList SEMI",
"globalDecl : globalTupleDeclaration SEMI",
"globalVarList : globalVarList COMMA ID",
"globalVarList : globalVarList COMMA ID dimensionDecl",
"globalVarList : globalVarList COMMA MUL ID",
"globalVarList : globalVarList COMMA ID '(' funcDeclParamList ')'",
"globalVarList : ID dimensionDecl",
"globalVarList : MUL ID",
"globalVarList : ID",
"globalVarList : ID '(' funcDeclParamList ')'",
"globalTupleDeclaration : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList",
"tupleFieldList : tupleFieldList COMMA tupleField",
"tupleFieldList : tupleField",
"tupleField : type ID",
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
"type : KW_TUPLE ID",
"type : TYPE_VOID",
"type : ID",
"functionDefinitionBlock : functionDefinitionBlock functionDefinition",
"functionDefinitionBlock : functionDefinition",
"$$2 :",
"functionDefinition : type ID '(' paramList ')' $$2 '{' localDeclBlock body '}'",
"body : KW_BEGIN statementList KW_END",
"paramList : paramList COMMA param",
"paramList : param",
"paramList :",
"param : type ID",
"param : type MUL ID",
"localDeclBlock : KW_DECL localDeclList KW_ENDDECL",
"localDeclBlock : KW_DECL KW_ENDDECL",
"localDeclBlock :",
"localDeclList : localDeclList localDecl",
"localDeclList : localDecl",
"localDeclList : localDeclList localTupleDecl",
"localDeclList : localTupleDecl",
"localDecl : type idList SEMI",
"localTupleDecl : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList SEMI",
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
"assignmentStatement : fieldAssignmentStatement SEMI",
"memberAccess : memberAccess DOT ID",
"memberAccess : ID DOT ID",
"memberAccess : ID ARROW ID",
"fieldAssignmentStatement : memberAccess ASSIGN expr",
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
"expr : memberAccess",
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
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
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
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
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
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 305 "parser.y"

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
#line 922 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

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

    i = (int) (data->s_mark - data->s_base);
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
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

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
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
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

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
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
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
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

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
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
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
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
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
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
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
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
            if (save->state != yystate) YYABORT;
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
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
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
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
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
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
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
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
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
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
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
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
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
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
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
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
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
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
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
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
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
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
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
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 65 "parser.y"
	{ exit(0); }
#line 1595 "y.tab.c"
break;
case 5:
#line 73 "parser.y"
	{ printTypeTable(); }
#line 1600 "y.tab.c"
break;
case 10:
#line 82 "parser.y"
	{ createNewType(yystack.l_mark[0].node->varName); }
#line 1605 "y.tab.c"
break;
case 11:
#line 82 "parser.y"
	{ setFieldsOfType(yystack.l_mark[-4].node->varName, yystack.l_mark[-1].field); }
#line 1610 "y.tab.c"
break;
case 12:
#line 85 "parser.y"
	{ yyval.field = mergeTypeFields(yystack.l_mark[-1].field, yystack.l_mark[0].field); }
#line 1615 "y.tab.c"
break;
case 13:
#line 86 "parser.y"
	{ yyval.field = yystack.l_mark[0].field; }
#line 1620 "y.tab.c"
break;
case 14:
#line 89 "parser.y"
	{ yyval.field = createNewTypeField(yystack.l_mark[-1].node->varName, typeTableLookup("INT")); }
#line 1625 "y.tab.c"
break;
case 15:
#line 90 "parser.y"
	{ yyval.field = createNewTypeField(yystack.l_mark[-1].node->varName, typeTableLookup("STRING")); }
#line 1630 "y.tab.c"
break;
case 16:
#line 91 "parser.y"
	{ yyval.field = createNewTypeField(yystack.l_mark[-1].node->varName, typeTableLookup(yystack.l_mark[-2].node->varName)); }
#line 1635 "y.tab.c"
break;
case 17:
#line 94 "parser.y"
	{ printGST(); yyval.node = NULL; }
#line 1640 "y.tab.c"
break;
case 18:
#line 95 "parser.y"
	{ yyval.node = NULL; }
#line 1645 "y.tab.c"
break;
case 19:
#line 98 "parser.y"
	{ yyval.node = NULL; }
#line 1650 "y.tab.c"
break;
case 20:
#line 99 "parser.y"
	{ yyval.node = NULL; }
#line 1655 "y.tab.c"
break;
case 21:
#line 102 "parser.y"
	{ addToGST(yystack.l_mark[-2].node, yystack.l_mark[-1].node); yyval.node = NULL; }
#line 1660 "y.tab.c"
break;
case 22:
#line 103 "parser.y"
	{ yyval.node = NULL; }
#line 1665 "y.tab.c"
break;
case 23:
#line 106 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1670 "y.tab.c"
break;
case 24:
#line 107 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewArrayNode(yystack.l_mark[-1].node, yystack.l_mark[0].node)); }
#line 1675 "y.tab.c"
break;
case 25:
#line 108 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1680 "y.tab.c"
break;
case 26:
#line 109 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-5].node, createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node)); }
#line 1685 "y.tab.c"
break;
case 27:
#line 110 "parser.y"
	{ yyval.node = createNewArrayNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1690 "y.tab.c"
break;
case 28:
#line 111 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1695 "y.tab.c"
break;
case 29:
#line 112 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1700 "y.tab.c"
break;
case 30:
#line 113 "parser.y"
	{ yyval.node = createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1705 "y.tab.c"
break;
case 31:
#line 116 "parser.y"
	{ addTupleTypeToGST(yystack.l_mark[-4].node, yystack.l_mark[-2].node, yystack.l_mark[0].node); yyval.node = NULL; }
#line 1710 "y.tab.c"
break;
case 32:
#line 119 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1715 "y.tab.c"
break;
case 33:
#line 120 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1720 "y.tab.c"
break;
case 34:
#line 123 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1725 "y.tab.c"
break;
case 35:
#line 126 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1730 "y.tab.c"
break;
case 36:
#line 127 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1735 "y.tab.c"
break;
case 37:
#line 128 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1740 "y.tab.c"
break;
case 38:
#line 129 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1745 "y.tab.c"
break;
case 39:
#line 132 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1750 "y.tab.c"
break;
case 40:
#line 133 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1755 "y.tab.c"
break;
case 41:
#line 134 "parser.y"
	{ yyval.node = NULL; }
#line 1760 "y.tab.c"
break;
case 42:
#line 137 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, false, false); }
#line 1765 "y.tab.c"
break;
case 43:
#line 138 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, false, true); }
#line 1770 "y.tab.c"
break;
case 44:
#line 141 "parser.y"
	{ yyval.node = createTypeNode(INT); }
#line 1775 "y.tab.c"
break;
case 45:
#line 142 "parser.y"
	{ yyval.node = createTypeNode(STRING); }
#line 1780 "y.tab.c"
break;
case 46:
#line 143 "parser.y"
	{ yyval.node = createTupleTypeNode(yystack.l_mark[0].node); }
#line 1785 "y.tab.c"
break;
case 47:
#line 144 "parser.y"
	{ yyval.node = createTypeNode(VOID); }
#line 1790 "y.tab.c"
break;
case 48:
#line 145 "parser.y"
	{ yyval.node = createUserTypeNode(yystack.l_mark[0].node); }
#line 1795 "y.tab.c"
break;
case 49:
#line 148 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1800 "y.tab.c"
break;
case 50:
#line 149 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1805 "y.tab.c"
break;
case 51:
#line 153 "parser.y"
	{ currentFunction = lookupGST(yystack.l_mark[-3].node->varName); }
#line 1810 "y.tab.c"
break;
case 52:
#line 155 "parser.y"
	{ yyval.node = createFunctionDefinitionNode(yystack.l_mark[-9].node, yystack.l_mark[-8].node, yystack.l_mark[-6].node, yystack.l_mark[-2].node, yystack.l_mark[-1].node); }
#line 1815 "y.tab.c"
break;
case 53:
#line 158 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1820 "y.tab.c"
break;
case 54:
#line 161 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1825 "y.tab.c"
break;
case 55:
#line 162 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1830 "y.tab.c"
break;
case 56:
#line 163 "parser.y"
	{ yyval.node = NULL; }
#line 1835 "y.tab.c"
break;
case 57:
#line 166 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, true, false); }
#line 1840 "y.tab.c"
break;
case 58:
#line 167 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, true, true); }
#line 1845 "y.tab.c"
break;
case 59:
#line 170 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1850 "y.tab.c"
break;
case 60:
#line 171 "parser.y"
	{ yyval.node = NULL; }
#line 1855 "y.tab.c"
break;
case 61:
#line 172 "parser.y"
	{ yyval.node = NULL; }
#line 1860 "y.tab.c"
break;
case 62:
#line 175 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1865 "y.tab.c"
break;
case 63:
#line 176 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1870 "y.tab.c"
break;
case 64:
#line 177 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1875 "y.tab.c"
break;
case 65:
#line 178 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1880 "y.tab.c"
break;
case 66:
#line 181 "parser.y"
	{ addToLST(yystack.l_mark[-2].node, yystack.l_mark[-1].node); yyval.node = NULL; }
#line 1885 "y.tab.c"
break;
case 67:
#line 184 "parser.y"
	{ addTupleTypeToLST(yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); yyval.node = NULL; }
#line 1890 "y.tab.c"
break;
case 68:
#line 187 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1895 "y.tab.c"
break;
case 69:
#line 188 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1900 "y.tab.c"
break;
case 70:
#line 189 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1905 "y.tab.c"
break;
case 71:
#line 190 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1910 "y.tab.c"
break;
case 72:
#line 193 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1915 "y.tab.c"
break;
case 73:
#line 194 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1920 "y.tab.c"
break;
case 74:
#line 197 "parser.y"
	{ generateMainCode(yystack.l_mark[-1].node); printLocalSymbolTable(); freeLocalSymbolTable(); yyval.node = NULL; }
#line 1925 "y.tab.c"
break;
case 75:
#line 200 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1930 "y.tab.c"
break;
case 76:
#line 201 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1935 "y.tab.c"
break;
case 77:
#line 204 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1940 "y.tab.c"
break;
case 78:
#line 205 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1945 "y.tab.c"
break;
case 79:
#line 206 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1950 "y.tab.c"
break;
case 80:
#line 207 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1955 "y.tab.c"
break;
case 81:
#line 208 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1960 "y.tab.c"
break;
case 82:
#line 209 "parser.y"
	{ yyval.node = createBreakNode(); }
#line 1965 "y.tab.c"
break;
case 83:
#line 210 "parser.y"
	{ yyval.node = createContinueNode(); }
#line 1970 "y.tab.c"
break;
case 84:
#line 211 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1975 "y.tab.c"
break;
case 85:
#line 212 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1980 "y.tab.c"
break;
case 86:
#line 213 "parser.y"
	{ yyval.node = createBreakPointNode(); }
#line 1985 "y.tab.c"
break;
case 87:
#line 214 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1990 "y.tab.c"
break;
case 88:
#line 215 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1995 "y.tab.c"
break;
case 89:
#line 218 "parser.y"
	{ yyval.node = createReturnNode(yystack.l_mark[0].node); }
#line 2000 "y.tab.c"
break;
case 90:
#line 221 "parser.y"
	{ yyval.node = createReadNode(yystack.l_mark[-2].node); }
#line 2005 "y.tab.c"
break;
case 91:
#line 222 "parser.y"
	{ yyval.node = createReadToArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node); }
#line 2010 "y.tab.c"
break;
case 92:
#line 225 "parser.y"
	{ yyval.node = createWriteNode(yystack.l_mark[-2].node); }
#line 2015 "y.tab.c"
break;
case 93:
#line 228 "parser.y"
	{ yyval.node = createAssignNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2020 "y.tab.c"
break;
case 94:
#line 229 "parser.y"
	{ yyval.node = createArrayAssignNode(yystack.l_mark[-4].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2025 "y.tab.c"
break;
case 95:
#line 230 "parser.y"
	{ yyval.node = createAssignToDereferencedNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2030 "y.tab.c"
break;
case 96:
#line 231 "parser.y"
	{ yyval.node = createIncrementNode(yystack.l_mark[-2].node); }
#line 2035 "y.tab.c"
break;
case 97:
#line 232 "parser.y"
	{ yyval.node = createDecrementNode(yystack.l_mark[-2].node); }
#line 2040 "y.tab.c"
break;
case 98:
#line 233 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2045 "y.tab.c"
break;
case 99:
#line 234 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2050 "y.tab.c"
break;
case 100:
#line 237 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_DOT); }
#line 2055 "y.tab.c"
break;
case 101:
#line 238 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_DOT); }
#line 2060 "y.tab.c"
break;
case 102:
#line 239 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_ARROW); }
#line 2065 "y.tab.c"
break;
case 103:
#line 242 "parser.y"
	{ yyval.node = createMemberAssignmentNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2070 "y.tab.c"
break;
case 104:
#line 245 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2075 "y.tab.c"
break;
case 105:
#line 246 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2080 "y.tab.c"
break;
case 106:
#line 247 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2085 "y.tab.c"
break;
case 107:
#line 248 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2090 "y.tab.c"
break;
case 108:
#line 249 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2095 "y.tab.c"
break;
case 109:
#line 252 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2100 "y.tab.c"
break;
case 110:
#line 253 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2105 "y.tab.c"
break;
case 111:
#line 256 "parser.y"
	{ yyval.node = createIfElseNode(yystack.l_mark[-6].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2110 "y.tab.c"
break;
case 112:
#line 257 "parser.y"
	{ yyval.node = createIfNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 2115 "y.tab.c"
break;
case 113:
#line 260 "parser.y"
	{ yyval.node = createWhileNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 2120 "y.tab.c"
break;
case 114:
#line 263 "parser.y"
	{ yyval.node = createRepeatUntilNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 2125 "y.tab.c"
break;
case 115:
#line 266 "parser.y"
	{ yyval.node = createDoWhileNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 2130 "y.tab.c"
break;
case 116:
#line 269 "parser.y"
	{ yyval.node = createArithOpNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2135 "y.tab.c"
break;
case 117:
#line 270 "parser.y"
	{ yyval.node = createArithOpNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2140 "y.tab.c"
break;
case 118:
#line 271 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2145 "y.tab.c"
break;
case 119:
#line 272 "parser.y"
	{ yyval.node = createArithOpNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2150 "y.tab.c"
break;
case 120:
#line 273 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2155 "y.tab.c"
break;
case 121:
#line 274 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2160 "y.tab.c"
break;
case 122:
#line 275 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2165 "y.tab.c"
break;
case 123:
#line 276 "parser.y"
	{ yyval.node = createVariableUsageNode(yystack.l_mark[0].node->varName); }
#line 2170 "y.tab.c"
break;
case 124:
#line 277 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2175 "y.tab.c"
break;
case 125:
#line 278 "parser.y"
	{ yyval.node = createArrayAccessNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 2180 "y.tab.c"
break;
case 126:
#line 279 "parser.y"
	{ yyval.node = createDereferenceNode(yystack.l_mark[0].node); }
#line 2185 "y.tab.c"
break;
case 127:
#line 280 "parser.y"
	{ yyval.node = createAddressToNode(yystack.l_mark[0].node); }
#line 2190 "y.tab.c"
break;
case 128:
#line 281 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2195 "y.tab.c"
break;
case 129:
#line 282 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2200 "y.tab.c"
break;
case 130:
#line 285 "parser.y"
	{ yyval.node = createFunctionCallNode(yystack.l_mark[-2].node, NULL); }
#line 2205 "y.tab.c"
break;
case 131:
#line 286 "parser.y"
	{ yyval.node = createFunctionCallNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2210 "y.tab.c"
break;
case 132:
#line 288 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2215 "y.tab.c"
break;
case 133:
#line 289 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2220 "y.tab.c"
break;
case 134:
#line 292 "parser.y"
	{ yyval.node = createConditionNode(NODE_LE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2225 "y.tab.c"
break;
case 135:
#line 293 "parser.y"
	{ yyval.node = createConditionNode(NODE_LT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2230 "y.tab.c"
break;
case 136:
#line 294 "parser.y"
	{ yyval.node = createConditionNode(NODE_GE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2235 "y.tab.c"
break;
case 137:
#line 295 "parser.y"
	{ yyval.node = createConditionNode(NODE_GT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2240 "y.tab.c"
break;
case 138:
#line 296 "parser.y"
	{ yyval.node = createConditionNode(NODE_NE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2245 "y.tab.c"
break;
case 139:
#line 297 "parser.y"
	{ yyval.node = createConditionNode(NODE_EQ, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2250 "y.tab.c"
break;
case 140:
#line 298 "parser.y"
	{ yyval.node = createConditionNode(NODE_OR, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2255 "y.tab.c"
break;
case 141:
#line 299 "parser.y"
	{ yyval.node = createConditionNode(NODE_AND, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2260 "y.tab.c"
break;
case 142:
#line 300 "parser.y"
	{ yyval.node = createConditionNode(NODE_NOT, yystack.l_mark[0].node, NULL); }
#line 2265 "y.tab.c"
break;
case 143:
#line 301 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2270 "y.tab.c"
break;
#line 2272 "y.tab.c"
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
            do {
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
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
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
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
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
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
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
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
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
    if (yyps->save) goto yyvalid;
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
