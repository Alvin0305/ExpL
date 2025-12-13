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
    #include "define/constants.h"
    #include "g_symbol_table/g_symbol_table.h"
    #include "util/util.h"

    int yylex(void);
    void yyerror(char const *msg);

    FILE *target_file;
    extern FILE *yyin;
    extern int lineNumber;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 18 "parser.y"
typedef union YYSTYPE {
    struct tnode *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   11,   11,   12,   12,   13,   15,   15,   14,
   14,   14,   14,   14,   14,   16,   16,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    4,    4,
    5,    6,    6,    6,   17,   17,    8,    8,    7,    9,
   10,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    4,    3,    3,    2,    2,    1,    3,    1,    1,    3,
    4,    4,    2,    2,    1,    4,    3,    2,    1,    1,
    1,    1,    1,    1,    2,    2,    1,    1,    5,    6,
    5,    4,    5,    5,    4,    3,    9,    7,    7,    7,
    7,    3,    3,    3,    3,    3,    3,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    2,    2,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    4,    8,    9,    0,    6,    0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   19,   20,   21,   22,   24,   23,   27,   28,
    3,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   25,   26,    0,    1,   18,    0,
    0,   14,    7,    0,    0,   48,   50,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   58,   59,    0,    0,
    0,    0,    0,    0,   32,    0,    0,    0,    0,    0,
    0,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   17,    0,    0,   12,   47,    0,    0,    0,
    0,    0,   52,   51,   53,   54,   55,   56,   33,   35,
   29,    0,   31,   34,    0,    0,    0,    0,   16,   30,
    0,    0,    0,    0,    0,   38,   39,   41,   40,    0,
   37,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  276,  295,  289,  306,  290,  291,  292,  307,  308,  310,
  257,  260,  261,  263,  277,  278,  282,  283,  285,  286,
  287,  297,  298,  299,  300,  301,  302,  303,  304,  305,
  290,  308,  257,  263,  309,  267,   91,  312,   40,   40,
  257,   40,   40,  297,  268,  268,  297,  277,  298,   91,
  311,  257,  268,  293,  257,  258,  259,  263,  269,   40,
  296,  296,  267,   91,  257,  296,  267,  296,  296,  282,
  288,  258,   91,  257,  263,  312,  257,  257,  296,  262,
  263,  264,  265,  266,  268,  270,  271,  272,  273,  274,
  275,   93,  296,  296,   41,  312,   41,  296,   41,   41,
   40,   40,   93,  258,  311,  257,   41,  296,  296,  296,
  296,  296,  296,  296,  296,  296,  296,  296,  268,   93,
  268,   41,  268,  268,  279,  283,  296,  296,   93,  268,
  297,  297,   41,   41,  280,  281,  284,  268,  268,  297,
  281,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   61,   22,   23,   24,   25,   26,   27,   28,   29,   30,
    4,    8,    9,   35,   10,   51,   38,
};
static const YYINT yysindex[] = {                      -247,
 -250,    0, -196, -210,    0,    0,    0, -156,    0, -241,
  -90,   -9,   -6, -209,    0,    9,   18,  177, -206, -204,
  177,  126,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -32, -192, -261,   76,   76,  -88, -188,   76,
 -193,   76,   76,  208,    0,    0, -242,    0,    0, -187,
    6,    0,    0, -240,    8,    0,    0, -178, -157,   76,
  210,  -68,   76,   76,  -37,  -13,   76,    1,   15,   62,
   63,   12, -150,  -32, -148,   19,    0,    0,   29,   76,
   76,   76,   76,   76,    0,   76,   76,   76,   76,   76,
   76,    0,  234,  107, -153,  -36, -151,  248, -161, -162,
   76,   76,    0,   32,    6,    0,    0,  -55, -182,  -55,
 -182, -182,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -146,    0,    0,  177,  177,   43,   57,    0,    0,
 -200,  136, -257, -139,  177,    0,    0,    0,    0,  167,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -260,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -258,    0,    0,    0,  -41,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -256,    0,  -27,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -255,    0,    0,   97,   78,  100,
   85,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
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
    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   64,  -12,  -20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  122,    0,    0,   58,  -35,
};
#define YYTABLESIZE 523
static const YYINT yytable[] = {                         49,
   37,   49,   64,   95,  122,   44,   53,   15,   47,   13,
  138,   10,   11,   57,   11,   33,   74,   12,   13,   76,
   14,   34,   75,   49,   92,  126,   49,   97,    1,   96,
   39,   54,   15,   40,   13,   16,   10,   11,    3,   17,
   18,   99,   19,   20,   21,   71,   11,   41,   42,   12,
   13,   49,   14,   37,   64,  100,   11,   43,   50,   12,
   13,   45,   14,   46,   52,   57,   15,   16,   65,  107,
   72,   17,   18,   67,   19,   20,   21,   16,   77,  135,
  136,   17,   18,  133,   19,   20,   21,   86,   87,   88,
   89,   90,   91,    5,    6,    7,   73,  134,   37,   78,
   62,  101,  102,   66,  103,   68,   69,  104,  106,   64,
   49,   49,  131,  132,  121,   60,  123,  125,   44,   49,
  126,  130,  140,   79,  129,   45,   93,   94,  139,   32,
   98,  105,   46,   31,    6,    7,    0,   42,    0,    0,
   43,    0,    0,  108,  109,  110,  111,  112,    0,  113,
  114,  115,  116,  117,  118,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  127,  128,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,   36,   45,   63,    0,
    0,    0,    0,    0,   46,    0,    0,    0,    0,   42,
    0,    0,   43,   80,   81,   82,   83,   84,    0,  120,
    0,   86,   87,   88,   89,   90,   91,   81,    0,   83,
   84,    0,    0,    0,   86,   87,   88,   89,   90,   91,
   49,   49,   49,   49,   49,    0,   49,    0,   49,   49,
   49,   49,   49,   49,   57,   57,   57,   57,   57,    0,
   57,    0,   57,   57,   57,   57,   57,   57,   80,   81,
   82,   83,   84,    0,    0,    0,   86,   87,   88,   89,
   90,   91,   80,   81,   82,   83,   84,    0,    0,    0,
   86,   87,   88,   89,   90,   91,   80,   81,   82,   83,
   84,    0,    0,    0,   86,   87,   88,   89,   90,   91,
   80,   81,   82,   83,   84,    0,    0,    0,   86,   87,
   88,   89,   90,   91,   80,   81,   82,   83,   84,    0,
    0,    0,   86,   87,   88,   89,   90,   91,   80,   81,
   82,   83,   84,    0,    0,    0,   86,   87,   88,   89,
   90,   91,   55,   56,   57,    0,    0,    0,   58,   44,
   44,   44,   44,   44,   59,   44,   45,   45,   45,   45,
   45,    0,   45,   46,   46,   46,   46,   46,   42,   46,
   42,   43,    0,   43,   42,    0,    0,   43,   80,   81,
   82,   83,   84,    0,    0,    0,   86,   87,   88,   89,
   90,   91,   11,    0,    0,   12,   13,    0,   14,    0,
    0,    0,   11,    0,    0,   12,   13,    0,   14,    0,
    0,    0,   48,   16,    0,    0,    0,   17,   18,    0,
   19,   20,   21,   16,    0,    0,    0,   17,   18,  137,
   19,   20,   21,   11,    0,    0,   12,   13,    0,   14,
    0,    0,    0,   11,    0,    0,   12,   13,    0,   14,
    0,    0,    0,    0,   16,    0,    0,  141,   17,   18,
    0,   19,   20,   21,   16,    0,    0,    0,   17,   18,
    0,   19,   20,   21,   11,    0,    0,   12,   13,    0,
   14,   80,   81,   82,   83,   84,    0,   85,    0,   86,
   87,   88,   89,   90,   91,   16,    0,    0,    0,   70,
   18,    0,   19,   20,   21,   80,   81,   82,   83,   84,
    0,  119,    0,   86,   87,   88,   89,   90,   91,   80,
   81,   82,   83,   84,    0,  124,    0,   86,   87,   88,
   89,   90,   91,
};
static const YYINT yycheck[] = {                         41,
   91,   22,   91,   41,   41,   18,  268,  268,   21,  268,
  268,  268,  268,   41,  257,  257,  257,  260,  261,   55,
  263,  263,  263,   44,   93,  283,   47,   41,  276,   65,
   40,  293,  293,   40,  293,  278,  293,  293,  289,  282,
  283,   41,  285,  286,  287,  288,  257,  257,   40,  260,
  261,   93,  263,   91,   91,   41,  257,   40,   91,  260,
  261,  268,  263,  268,  257,   93,  277,  278,  257,   41,
  258,  282,  283,  267,  285,  286,  287,  278,  257,  280,
  281,  282,  283,   41,  285,  286,  287,  270,  271,  272,
  273,  274,  275,  290,  291,  292,   91,   41,   91,  257,
   37,   40,   40,   40,   93,   42,   43,  258,  257,   91,
  131,  132,  125,  126,  268,   40,  268,  279,   41,  140,
  283,  268,  135,   60,   93,   41,   63,   64,  268,    8,
   67,   74,   41,  290,  291,  292,   -1,   41,   -1,   -1,
   41,   -1,   -1,   80,   81,   82,   83,   84,   -1,   86,
   87,   88,   89,   90,   91,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  101,  102,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   -1,   -1,  267,   93,  267,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   93,  262,  263,  264,  265,  266,   -1,   93,
   -1,  270,  271,  272,  273,  274,  275,  263,   -1,  265,
  266,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
  262,  263,  264,  265,  266,   -1,  268,   -1,  270,  271,
  272,  273,  274,  275,  262,  263,  264,  265,  266,   -1,
  268,   -1,  270,  271,  272,  273,  274,  275,  262,  263,
  264,  265,  266,   -1,   -1,   -1,  270,  271,  272,  273,
  274,  275,  262,  263,  264,  265,  266,   -1,   -1,   -1,
  270,  271,  272,  273,  274,  275,  262,  263,  264,  265,
  266,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
  262,  263,  264,  265,  266,   -1,   -1,   -1,  270,  271,
  272,  273,  274,  275,  262,  263,  264,  265,  266,   -1,
   -1,   -1,  270,  271,  272,  273,  274,  275,  262,  263,
  264,  265,  266,   -1,   -1,   -1,  270,  271,  272,  273,
  274,  275,  257,  258,  259,   -1,   -1,   -1,  263,  262,
  263,  264,  265,  266,  269,  268,  262,  263,  264,  265,
  266,   -1,  268,  262,  263,  264,  265,  266,  262,  268,
  264,  262,   -1,  264,  268,   -1,   -1,  268,  262,  263,
  264,  265,  266,   -1,   -1,   -1,  270,  271,  272,  273,
  274,  275,  257,   -1,   -1,  260,  261,   -1,  263,   -1,
   -1,   -1,  257,   -1,   -1,  260,  261,   -1,  263,   -1,
   -1,   -1,  277,  278,   -1,   -1,   -1,  282,  283,   -1,
  285,  286,  287,  278,   -1,   -1,   -1,  282,  283,  284,
  285,  286,  287,  257,   -1,   -1,  260,  261,   -1,  263,
   -1,   -1,   -1,  257,   -1,   -1,  260,  261,   -1,  263,
   -1,   -1,   -1,   -1,  278,   -1,   -1,  281,  282,  283,
   -1,  285,  286,  287,  278,   -1,   -1,   -1,  282,  283,
   -1,  285,  286,  287,  257,   -1,   -1,  260,  261,   -1,
  263,  262,  263,  264,  265,  266,   -1,  268,   -1,  270,
  271,  272,  273,  274,  275,  278,   -1,   -1,   -1,  282,
  283,   -1,  285,  286,  287,  262,  263,  264,  265,  266,
   -1,  268,   -1,  270,  271,  272,  273,  274,  275,  262,
  263,  264,  265,  266,   -1,  268,   -1,  270,  271,  272,
  273,  274,  275,
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
   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
#define YYUNDFTOKEN 313
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","ID","NUM",
"STRING_LITERAL","READ","WRITE","PLUS","MUL","MINUS","DIV","MOD","ASSIGN",
"SEMI","AMPERSAND","GT","GE","LT","LE","NE","EQ","KW_BEGIN","KW_END","KW_IF",
"KW_THEN","KW_ELSE","KW_ENDIF","KW_WHILE","KW_DO","KW_ENDWHILE","KW_BREAK",
"KW_CONTINUE","KW_REPEAT","KW_UNTIL","KW_DECL","KW_ENDDECL","TYPE_INT",
"TYPE_STRING","COMMA","$accept","program","expr","statementList","statement",
"inputStatement","outputStatement","assignmentStatement","whileStatement",
"ifStatement","repeatUntilStatement","doWhileStatement","declarations",
"declList","decl","varList","type","dimensionDecl","dimensionUsage",
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
"ifStatement : KW_IF '(' expr ')' KW_THEN statementList KW_ELSE statementList KW_ENDIF",
"ifStatement : KW_IF '(' expr ')' KW_THEN statementList KW_ENDIF",
"whileStatement : KW_WHILE '(' expr ')' KW_DO statementList KW_ENDWHILE",
"repeatUntilStatement : KW_REPEAT statementList KW_UNTIL '(' expr ')' SEMI",
"doWhileStatement : KW_DO statementList KW_WHILE '(' expr ')' SEMI",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MUL expr",
"expr : expr DIV expr",
"expr : expr MOD expr",
"expr : '(' expr ')'",
"expr : NUM",
"expr : ID",
"expr : STRING_LITERAL",
"expr : expr GE expr",
"expr : expr GT expr",
"expr : expr LT expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr EQ expr",
"expr : ID dimensionUsage",
"expr : MUL ID",
"expr : AMPERSAND ID",

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
#line 150 "parser.y"

void yyerror(char const *msg) {
    printf("[Error] : %s in line: %d\n", msg, lineNumber);
    return;
}

int main() {
    target_file = fopen(INTERMEDIATE_FILE, "w");
    FILE *source_file = fopen(SOURCE_FILE, "r");

    yyin = source_file;

    return yyparse();
}
#line 641 "y.tab.c"

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
#line 42 "parser.y"
	{
        yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node);
        generateCode(yystack.l_mark[-1].node);
        printf("Finished\n");
        exit(0);
    }
#line 1319 "y.tab.c"
break;
case 2:
#line 48 "parser.y"
	{ 
        yyval.node = NULL;
        generateCode(NULL);
    }
#line 1327 "y.tab.c"
break;
case 3:
#line 54 "parser.y"
	{ 
        yyval.node = yystack.l_mark[-1].node; 
        populateGSymbolTable(yystack.l_mark[-1].node);
        printGSymbolTable(); 
    }
#line 1336 "y.tab.c"
break;
case 4:
#line 59 "parser.y"
	{ yyval.node = NULL; }
#line 1341 "y.tab.c"
break;
case 5:
#line 62 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1346 "y.tab.c"
break;
case 6:
#line 63 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1351 "y.tab.c"
break;
case 7:
#line 66 "parser.y"
	{ yyval.node = createDeclarationNode(yystack.l_mark[-2].node, yystack.l_mark[-1].node); }
#line 1356 "y.tab.c"
break;
case 8:
#line 69 "parser.y"
	{ yyval.node = createTypeNode(INT); }
#line 1361 "y.tab.c"
break;
case 9:
#line 70 "parser.y"
	{ yyval.node = createTypeNode(STRING); }
#line 1366 "y.tab.c"
break;
case 10:
#line 73 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1371 "y.tab.c"
break;
case 11:
#line 74 "parser.y"
	{ yyval.node = createNewArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1376 "y.tab.c"
break;
case 12:
#line 75 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1381 "y.tab.c"
break;
case 13:
#line 76 "parser.y"
	{ yyval.node = createNewArrayNode(NULL, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1386 "y.tab.c"
break;
case 14:
#line 77 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1391 "y.tab.c"
break;
case 15:
#line 78 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1396 "y.tab.c"
break;
case 16:
#line 81 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1401 "y.tab.c"
break;
case 17:
#line 82 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1406 "y.tab.c"
break;
case 18:
#line 85 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1411 "y.tab.c"
break;
case 19:
#line 86 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1416 "y.tab.c"
break;
case 20:
#line 89 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1421 "y.tab.c"
break;
case 21:
#line 90 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1426 "y.tab.c"
break;
case 22:
#line 91 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1431 "y.tab.c"
break;
case 23:
#line 92 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1436 "y.tab.c"
break;
case 24:
#line 93 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1441 "y.tab.c"
break;
case 25:
#line 94 "parser.y"
	{ yyval.node = createBreakNode(); }
#line 1446 "y.tab.c"
break;
case 26:
#line 95 "parser.y"
	{ yyval.node = createContinueNode(); }
#line 1451 "y.tab.c"
break;
case 27:
#line 96 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1456 "y.tab.c"
break;
case 28:
#line 97 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1461 "y.tab.c"
break;
case 29:
#line 100 "parser.y"
	{ yyval.node = createReadNode(yystack.l_mark[-2].node); }
#line 1466 "y.tab.c"
break;
case 30:
#line 101 "parser.y"
	{ yyval.node = createReadToArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node); }
#line 1471 "y.tab.c"
break;
case 31:
#line 104 "parser.y"
	{ yyval.node = createWriteNode(yystack.l_mark[-2].node); }
#line 1476 "y.tab.c"
break;
case 32:
#line 107 "parser.y"
	{ yyval.node = createAssignNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1481 "y.tab.c"
break;
case 33:
#line 108 "parser.y"
	{ yyval.node = createArrayAssignNode(yystack.l_mark[-4].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1486 "y.tab.c"
break;
case 34:
#line 109 "parser.y"
	{ yyval.node = createAssignToDereferencedNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1491 "y.tab.c"
break;
case 35:
#line 112 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1496 "y.tab.c"
break;
case 36:
#line 113 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1501 "y.tab.c"
break;
case 37:
#line 116 "parser.y"
	{ yyval.node = createIfElseNode(yystack.l_mark[-6].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1506 "y.tab.c"
break;
case 38:
#line 117 "parser.y"
	{ yyval.node = createIfNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 1511 "y.tab.c"
break;
case 39:
#line 120 "parser.y"
	{ yyval.node = createWhileNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 1516 "y.tab.c"
break;
case 40:
#line 123 "parser.y"
	{ yyval.node = createRepeatUntilNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 1521 "y.tab.c"
break;
case 41:
#line 126 "parser.y"
	{ yyval.node = createDoWhileNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 1526 "y.tab.c"
break;
case 42:
#line 129 "parser.y"
	{ yyval.node = createArithOpNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1531 "y.tab.c"
break;
case 43:
#line 130 "parser.y"
	{ yyval.node = createArithOpNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1536 "y.tab.c"
break;
case 44:
#line 131 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1541 "y.tab.c"
break;
case 45:
#line 132 "parser.y"
	{ yyval.node = createArithOpNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1546 "y.tab.c"
break;
case 46:
#line 133 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1551 "y.tab.c"
break;
case 47:
#line 134 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1556 "y.tab.c"
break;
case 48:
#line 135 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1561 "y.tab.c"
break;
case 49:
#line 136 "parser.y"
	{ yyval.node = createVariableUsageNode(yystack.l_mark[0].node->varName); }
#line 1566 "y.tab.c"
break;
case 50:
#line 137 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1571 "y.tab.c"
break;
case 51:
#line 138 "parser.y"
	{ yyval.node = createConditionNode(NODE_GE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1576 "y.tab.c"
break;
case 52:
#line 139 "parser.y"
	{ yyval.node = createConditionNode(NODE_GT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1581 "y.tab.c"
break;
case 53:
#line 140 "parser.y"
	{ yyval.node = createConditionNode(NODE_LT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1586 "y.tab.c"
break;
case 54:
#line 141 "parser.y"
	{ yyval.node = createConditionNode(NODE_LE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1591 "y.tab.c"
break;
case 55:
#line 142 "parser.y"
	{ yyval.node = createConditionNode(NODE_NE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1596 "y.tab.c"
break;
case 56:
#line 143 "parser.y"
	{ yyval.node = createConditionNode(NODE_EQ, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1601 "y.tab.c"
break;
case 57:
#line 144 "parser.y"
	{ yyval.node = createArrayAccessNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1606 "y.tab.c"
break;
case 58:
#line 145 "parser.y"
	{ yyval.node = createDereferenceNode(yystack.l_mark[0].node); }
#line 1611 "y.tab.c"
break;
case 59:
#line 146 "parser.y"
	{ yyval.node = createAddressToNode(yystack.l_mark[0].node); }
#line 1616 "y.tab.c"
break;
#line 1618 "y.tab.c"
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
