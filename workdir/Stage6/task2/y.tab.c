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
    #include "node/library/node_library.h"
    #include "node/user_type/node_user_type.h"
    #include "node/pointer/node_pointer.h"
    #include "code_gen/code_gen.h"
    #include "code_gen/function/function.h"
    #include "define/constants.h"
    #include "g_symbol_table/g_symbol_table.h"
    #include "local_symbol_table/local_symbol_table.h"
    #include "util/util.h"
    #include "error_handler/error_handler.h"
    #include "type_table/type_table.h"
    #include "register/register.h"

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
#line 27 "parser.y"
typedef union YYSTYPE {
    struct tnode *node;
    struct FieldList *field;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 60 "y.tab.c"

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
#define KW_ALLOC 259
#define KW_FREE 260
#define PLUS 261
#define MUL 262
#define MINUS 263
#define DIV 264
#define MOD 265
#define ASSIGN 266
#define COMMA 267
#define SEMI 268
#define DOT 269
#define ARROW 270
#define AMPERSAND 271
#define GT 272
#define GE 273
#define LT 274
#define LE 275
#define NE 276
#define EQ 277
#define KW_BEGIN 278
#define KW_END 279
#define KW_IF 280
#define KW_THEN 281
#define KW_ELSE 282
#define KW_ENDIF 283
#define KW_WHILE 284
#define KW_DO 285
#define KW_ENDWHILE 286
#define KW_BREAK 287
#define KW_CONTINUE 288
#define KW_REPEAT 289
#define KW_UNTIL 290
#define KW_DECL 291
#define KW_ENDDECL 292
#define TYPE_INT 293
#define TYPE_STRING 294
#define TYPE_VOID 295
#define KW_TUPLE 296
#define AND 297
#define OR 298
#define NOT 299
#define INCREMENT 300
#define DECREMENT 301
#define ASSIGN_ADD 302
#define ASSIGN_SUB 303
#define ASSIGN_MUL 304
#define ASSIGN_DIV 305
#define ASSIGN_MOD 306
#define KW_RETURN 307
#define MAIN 308
#define KW_BRKP 309
#define KW_TYPE 310
#define KW_ENDTYPE 311
#define KW_NULL 312
#define ID 313
#define NUM 314
#define STRING_LITERAL 315
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,   47,   47,   47,   48,   48,   50,
   49,   20,   20,   19,   19,   19,    2,    2,    3,    3,
    4,    4,    6,    6,    6,    6,    6,    6,    6,    6,
    5,   42,   42,   43,   44,   44,   44,   44,   13,   13,
   13,   14,   14,   38,   38,   38,   38,   38,    7,    7,
   51,    8,   16,   11,   11,   11,   12,   12,   33,   33,
   33,   34,   34,   34,   34,   35,   36,   37,   37,   37,
   37,   39,   39,   15,   21,   21,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   31,   31,   32,   41,   29,   29,   30,   23,   23,   23,
   23,   23,   23,   23,   46,   46,   46,   45,   24,   24,
   24,   24,   24,   40,   40,   26,   26,   25,   27,   28,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,    9,    9,   10,   10,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,
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
    1,    2,    2,    1,    1,    2,    2,    2,    2,    2,
    5,    5,    4,    2,    5,    6,    5,    4,    5,    5,
    3,    3,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    4,    3,    9,    7,    7,    7,    7,
    3,    3,    3,    3,    3,    3,    1,    1,    1,    2,
    2,    2,    1,    1,    1,    3,    4,    3,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    4,    0,    0,    6,   10,    0,
    9,    0,    0,    0,    0,    5,    8,   18,   44,   45,
   47,    0,   48,    0,   20,    0,    0,    0,    0,    0,
   50,    3,    0,    0,    0,    0,   17,   19,   22,    0,
    0,    0,   46,   49,    2,    0,    0,    0,    0,    0,
   13,    0,    0,   28,    0,    0,    0,    0,   21,    0,
    0,    0,    0,    0,    0,   11,   12,    0,    0,   33,
    0,   40,    0,    0,    0,    0,    0,    0,   55,    0,
   60,    0,    0,   63,   65,    0,    0,    0,   14,   15,
   16,   34,    0,    0,    0,   30,    0,   42,   73,    0,
   25,    0,    0,    0,   51,    0,   57,    0,   59,   62,
   64,    0,   70,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   76,
   79,    0,   81,   80,   84,   85,   77,   78,    0,    0,
    0,    0,    0,   74,   32,    0,   38,    0,   39,   43,
   72,    0,   54,    0,   58,    0,   71,    0,   66,    0,
    0,    0,    0,    0,    0,    0,   82,   83,    0,    0,
    0,  135,    0,  127,  129,    0,  133,    0,    0,   86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   87,   53,   75,  103,   89,   90,   88,
  104,    0,    0,   37,    0,   26,    0,    0,    0,   68,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  131,  132,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  106,  107,  101,  102,    0,    0,    0,    0,
    0,  136,    0,    0,    0,    0,    0,    0,    0,  105,
    0,   35,    0,    0,   69,    0,    0,    0,   93,    0,
  148,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  126,    0,  123,    0,  124,
  125,    0,   98,    0,  137,  115,    0,    0,    0,   36,
    0,    0,   95,    0,   97,  100,  149,    0,    0,    0,
    0,    0,    0,  147,    0,    0,    0,    0,    0,   91,
    0,   99,  114,   92,   52,   67,   96,    0,    0,    0,
    0,    0,  117,  118,  120,  119,    0,  116,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  293,  310,  317,  318,  332,  364,  308,  311,  313,  365,
  366,  291,  319,   40,  367,  311,  366,  292,  293,  294,
  295,  296,  313,  320,  321,  322,  355,  293,  296,  324,
  325,  332,  355,   41,  123,  313,  292,  321,  268,  262,
  313,  323,  313,  325,  332,  313,  123,  293,  294,  313,
  336,  337,   40,  313,   40,   91,  356,  267,  268,   40,
  291,  350,  313,  313,  313,  125,  336,  355,  359,  360,
  330,  331,  355,  314,   91,  262,  313,  328,  329,  355,
  292,  296,  351,  352,  353,  355,  278,  333,  268,  268,
  268,  313,  267,   41,  267,   41,  262,  313,   93,  314,
  313,   40,  356,  267,   41,  262,  313,  313,  292,  352,
  353,  262,  313,  354,  257,  258,  260,  262,  280,  284,
  285,  287,  288,  289,  307,  309,  313,  326,  338,  339,
  340,  341,  342,  343,  344,  345,  346,  347,  348,  349,
  358,  362,  363,  125,  360,  262,  313,  361,  331,  313,
   93,  330,  329,  368,  313,   40,  313,  267,  268,   40,
   40,   40,  313,   40,   40,  338,  268,  268,  338,  262,
  271,  312,  313,  314,  315,   40,  326,  334,  363,  268,
  266,  269,  270,  300,  301,  302,  303,  304,  305,  306,
   40,   91,  357,  268,  279,  339,  268,  268,  268,  268,
  268,  266,  269,  313,  267,   41,  123,  359,  262,  313,
  313,  334,  313,  266,  299,   40,  334,  335,  335,  284,
  290,  313,  313,  357,  334,  261,  262,  263,  264,  265,
  259,  334,  313,  313,  268,  268,  334,  334,  334,  334,
  334,   41,  327,  334,  334,  266,   91,  259,  334,  313,
  262,  313,  350,   41,  313,   41,  357,   41,   41,  334,
  335,  334,  335,  272,  273,  274,  275,  276,  277,  297,
  298,   41,   41,   40,   40,   41,  334,  334,  334,  334,
  334,   40,  268,  267,   41,   93,  334,  334,   40,  313,
  333,  361,  268,   41,  268,  268,   41,  334,  334,  334,
  334,  334,  334,  335,  335,  281,  285,  335,  335,   41,
  334,  268,   93,   41,  125,  268,  268,  338,  338,   41,
   41,  282,  283,  286,  268,  268,  338,  283,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          3,
    4,   13,   24,   25,   26,   42,   30,   31,  177,  243,
   78,   79,   71,   72,    5,   88,  217,  218,   51,   52,
  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,
  139,  140,   62,   83,   84,   85,  114,   68,   57,  193,
  141,   69,   70,  148,  142,  179,    6,   10,   11,   15,
  154,
};
static const YYINT yysindex[] = {                      -256,
 -273, -216,    0,    0,    0, -240,   21,    0,    0, -203,
    0, -175, -128,   24,  -54,    0,    0,    0,    0,    0,
    0, -233,    0, -149,    0, -179, -247, -273, -217, -128,
    0,    0, -206,  -10, -251,   75,    0,    0,    0, -191,
   -7, -156,    0,    0,    0,   89, -167, -181, -177, -174,
    0, -120, -114,    0, -114, -180,   65, -239,    0, -114,
 -141, -116,  -93,  -76,  -73,    0,    0, -150,  -39,    0,
  -38,    0, -235,  105, -111, -113,   -4,  -35,    0, -231,
    0, -109, -135,    0,    0, -223,  395,   86,    0,    0,
    0,    0, -114, -222, -114,    0, -101,    0,    0,  121,
    0, -114,   65, -114,    0,  -98,    0,  176,    0,    0,
    0,  -95,    0, -127,  179,  180,  184,  -88,  187,  194,
  395,  -25,  -24,  395,  -22,  -20,   -6,   -3,  287,    0,
    0,   43,    0,    0,    0,    0,    0,    0,   55,   60,
   76,   85, -163,    0,    0,  -75,    0,   39,    0,    0,
    0,  -30,    0,  138,    0, -114,    0, -221,    0,   28,
  -22,   50,  106,  -40,  -40,  434,    0,    0,  326,   54,
   70,    0,  -23,    0,    0,  -22,    0,  278,  116,    0,
  -36,   77,   80,  118,  120,  -22,  -22,  -22,  -22,  -22,
  -32,  -22,  -90,    0,    0,    0,    0,    0,    0,    0,
    0,  -26,  103,    0, -214,    0, -167,  -17,  110,    0,
   11,  150,  356,  -22,  -40,  -40,  201,  -31,  -29,  384,
  387,    0,    0,  337,  172,  -22,  -22,  -22,  -22,  -22,
  391,  225,    0,    0,    0,    0,  278,  278,  278,  278,
  278,    0,  -16,  278,  -55,  -22,  -22,  398,  278,    0,
  131,    0, -116, -222,    0,  181,   14,  183,    0,  245,
    0,  145,  -13,  -22,  -22,  -22,  -22,  -22,  -22,  -40,
  -40,  165,  162,  -40,  -40,    0, -189,    0, -189,    0,
    0,  407,    0,  -22,    0,    0,  256,  178,  411,    0,
  328, -119,    0,  186,    0,    0,    0,  278,  278,  278,
  278,  278,  278,    0,  170,  395,  395,   12,   29,    0,
  278,    0,    0,    0,    0,    0,    0,  243,  341, -218,
  200,  395,    0,    0,    0,    0,  380,    0,
};
static const YYINT yyrindex[] = {                       188,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  156,    0,    0,
    0,    0,    0,    0,    0, -213,    0,    0,    0,    0,
  -97,    0,    0,    0,    0,    0,  192,    0,    0,    0,
    0,    0,    0,    0,  -15,    0,  -84,    0,    0,  -12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -80,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -15,  -78,    0,    0,    0,    0, -213,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  204,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   40,    0,    0,    0,    0,  212,   57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  192,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   84,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  213,  214,  216,  223,
  224,    0,    0,  -11,    0,    0,    0,    0,  226,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  101,    0,  128,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,   42,   45,
   68,   73,   82,    0,  -28,    0,    0,    0,    0,    0,
   -9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  478,    0,    0,    0,  474,  -65,    0,
    0,  408,  409,  419,   47,  276,  269, -144,  470,    0,
 -105, -122,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  339,    0,  465,  468,    0,   33,  477, -153,
    0,  399,  464,  304,    0,  263,    0,    0,  549,    0,
    0,
};
#define YYTABLESIZE 747
static const YYINT yytable[] = {                        216,
  247,   94,   96,  176,   66,  105,  196,  176,  242,  272,
  206,  273,  146,  176,   40,  166,  191,  176,  169,  224,
  219,  128,   76,  254,  285,   41,   97,  297,   56,  139,
  106,  138,   55,  191,    7,  102,    1,  286,  112,  146,
  209,   48,   49,  196,   27,   33,  196,  251,   46,  325,
   12,  256,  320,    2,  294,  128,   27,  257,  128,   32,
   14,   50,   33,  128,   34,   41,  307,  192,   35,  321,
  261,  263,  227,   77,  229,  230,   45,   98,  143,   36,
  128,  107,  142,   56,  192,  141,   56,   73,   39,  113,
  147,  210,   80,   86,    8,   43,    9,  134,  252,   46,
  128,  192,  202,  128,  247,  203,   46,   16,  140,    9,
   58,   59,   47,  144,   53,   86,   18,   19,   20,   21,
   22,   54,  145,   61,  130,  304,  305,   73,   60,  308,
  309,   63,  128,   74,   73,   64,   80,   23,   65,  158,
  159,  121,   37,   19,   20,   21,   22,  205,  316,  134,
   81,   19,   20,   21,   82,   75,  109,   19,   20,   21,
   82,   87,   92,   23,   28,   20,   21,   29,  122,   29,
   29,   23,   48,   49,   89,  246,  130,   23,   19,   20,
   21,   29,   27,   27,   23,  276,   23,   23,   24,   24,
  258,   90,   50,  121,   91,  196,  196,   99,   23,  101,
  318,  319,  100,  108,  196,  226,  227,  228,  229,  230,
  144,  150,  276,  151,  155,  156,  327,  157,  160,  161,
  122,  170,  231,  162,  163,  170,  164,   93,   95,  170,
  171,  104,  248,  165,  171,  170,   95,  204,  171,  170,
  128,  128,  167,  168,  171,  182,  183,  180,  171,   93,
  284,   41,  128,  128,   56,  139,  128,  138,  215,  181,
  207,  128,  182,  183,  194,  270,  271,  270,  271,  146,
  313,  172,  173,  174,  175,  172,  173,  174,  175,  172,
  173,  174,  175,  270,  271,  172,  173,  174,  175,  172,
  173,  174,  175,  184,  185,  186,  187,  188,  189,  190,
  128,  128,  128,  128,  128,  205,  128,  128,  270,  271,
  197,  128,  128,  128,  128,  128,  128,  134,  134,  134,
  134,  134,  198,  134,  134,  270,  271,  199,  134,  134,
  134,  134,  134,  134,  143,  143,  128,  128,  142,  142,
  211,  141,  141,  200,  130,  130,  130,  130,  130,  143,
  130,  130,  201,  134,  134,  130,  130,  130,  130,  130,
  130,  121,  213,  121,  140,  140,  222,  121,  121,  144,
  144,  214,  121,  121,  121,  121,  121,  121,  145,  145,
  130,  130,  223,  143,  203,  235,  143,  236,  122,  233,
  122,  143,  234,  178,  122,  122,  259,  121,  121,  122,
  122,  122,  122,  122,  122,  226,  227,  228,  229,  230,
  226,  227,  228,  229,  230,  250,  264,  265,  266,  267,
  268,  269,  255,  274,  122,  122,  275,  247,  143,  212,
  282,  143,  226,  227,  228,  229,  230,  289,  226,  227,
  228,  229,  230,  290,  225,  306,  307,  310,  293,  232,
  295,  314,  315,  317,  237,  238,  239,  240,  241,  244,
  245,  226,  227,  228,  229,  230,  270,  326,   44,   61,
  249,   31,  264,  265,  266,  267,  268,  269,    7,   94,
  109,  110,  260,  111,  262,  226,  227,  228,  229,  230,
  112,  113,  283,  108,  277,  278,  279,  280,  281,  115,
  116,   38,  117,   44,  118,  226,  227,  228,  229,  230,
  152,  153,  296,  149,  287,  288,  226,  227,  228,  229,
  230,   67,  119,  312,  322,  323,  120,  121,  291,  122,
  123,  124,  298,  299,  300,  301,  302,  303,  226,  227,
  228,  229,  230,  115,  116,  253,  117,  110,  118,  125,
  111,  126,  311,  103,  208,  127,  145,  292,   17,    0,
    0,    0,    0,    0,    0,  195,  119,    0,  143,  143,
  120,  121,    0,  122,  123,  124,    0,    0,    0,    0,
  143,  143,  115,  116,  143,  117,    0,  118,    0,  143,
    0,    0,    0,  125,    0,  126,    0,  115,  116,  127,
  117,    0,  118,    0,    0,  119,    0,    0,    0,  120,
  121,    0,  122,  123,  124,  221,    0,    0,    0,    0,
  119,    0,    0,    0,  120,  121,  324,  122,  123,  124,
    0,    0,  125,    0,  126,    0,  115,  116,  127,  117,
    0,  118,    0,    0,    0,    0,    0,  125,    0,  126,
    0,  115,  116,  127,  117,    0,  118,    0,    0,  119,
    0,    0,  328,  120,  121,    0,  122,  123,  124,    0,
    0,    0,    0,    0,  119,    0,    0,    0,  120,  121,
    0,  122,  123,  124,    0,    0,  125,    0,  126,    0,
  115,  116,  127,  117,    0,  118,    0,    0,    0,    0,
    0,  125,    0,  126,    0,    0,    0,  127,    0,    0,
    0,    0,    0,  119,    0,    0,    0,  220,  121,    0,
  122,  123,  124,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  125,    0,  126,    0,    0,    0,  127,
};
static const YYINT yycheck[] = {                         40,
   91,   41,   41,   40,  125,   41,  129,   40,   41,   41,
   41,   41,   41,   40,  262,  121,   40,   40,  124,  173,
  165,   87,  262,   41,   41,   41,  262,   41,   41,   41,
  262,   41,   40,   40,  308,   40,  293,   93,  262,  262,
  262,  293,  294,  166,   12,   13,  169,  262,  262,  268,
  291,   41,   41,  310,   41,  121,   24,  211,  124,   13,
   40,  313,   30,  129,   41,  313,  285,   91,  123,   41,
  215,  216,  262,  313,  264,  265,   30,  313,   41,  313,
   41,  313,   41,   91,   91,   41,   91,   55,  268,  313,
  313,  313,   60,   61,  311,  313,  313,   41,  313,  313,
  166,   91,  266,  169,   91,  269,  313,  311,   41,  313,
  267,  268,  123,   41,   40,   83,  292,  293,  294,  295,
  296,  313,   41,  291,   41,  270,  271,   95,   40,  274,
  275,  313,   93,  314,  102,  313,  104,  313,  313,  267,
  268,   41,  292,  293,  294,  295,  296,  267,  268,   93,
  292,  293,  294,  295,  296,   91,  292,  293,  294,  295,
  296,  278,  313,  313,  293,  294,  295,  296,   41,  267,
  268,  313,  293,  294,  268,  266,   93,  313,  293,  294,
  295,  296,  267,  268,  313,   41,  267,  268,  267,  268,
   41,  268,  313,   93,  268,  318,  319,   93,  313,  313,
  306,  307,  314,  313,  327,  261,  262,  263,  264,  265,
  125,  313,   41,   93,  313,   40,  322,  313,   40,   40,
   93,  262,  259,   40,  313,  262,   40,  267,  267,  262,
  271,  267,  259,   40,  271,  262,  267,  313,  271,  262,
  306,  307,  268,  268,  271,  269,  270,  268,  271,  267,
  267,  267,  318,  319,  267,  267,  322,  267,  299,  266,
  123,  327,  269,  270,  268,  297,  298,  297,  298,  298,
   93,  312,  313,  314,  315,  312,  313,  314,  315,  312,
  313,  314,  315,  297,  298,  312,  313,  314,  315,  312,
  313,  314,  315,  300,  301,  302,  303,  304,  305,  306,
  261,  262,  263,  264,  265,  267,  267,  268,  297,  298,
  268,  272,  273,  274,  275,  276,  277,  261,  262,  263,
  264,  265,  268,  267,  268,  297,  298,  268,  272,  273,
  274,  275,  276,  277,  297,  298,  297,  298,  297,  298,
  313,  297,  298,  268,  261,  262,  263,  264,  265,   87,
  267,  268,  268,  297,  298,  272,  273,  274,  275,  276,
  277,  261,  313,  263,  297,  298,  313,  267,  268,  297,
  298,  266,  272,  273,  274,  275,  276,  277,  297,  298,
  297,  298,  313,  121,  269,  268,  124,  268,  261,  313,
  263,  129,  313,  125,  267,  268,   41,  297,  298,  272,
  273,  274,  275,  276,  277,  261,  262,  263,  264,  265,
  261,  262,  263,  264,  265,  313,  272,  273,  274,  275,
  276,  277,  313,   40,  297,  298,   40,   91,  166,  161,
   40,  169,  261,  262,  263,  264,  265,   40,  261,  262,
  263,  264,  265,  313,  176,  281,  285,   41,  268,  181,
  268,   41,  125,  268,  186,  187,  188,  189,  190,  191,
  192,  261,  262,  263,  264,  265,  297,  268,  313,  278,
  202,  268,  272,  273,  274,  275,  276,  277,  291,  268,
  268,  268,  214,  268,  216,  261,  262,  263,  264,  265,
  268,  268,  268,  268,  226,  227,  228,  229,  230,  257,
  258,   24,  260,   30,  262,  261,  262,  263,  264,  265,
  102,  104,  268,   95,  246,  247,  261,  262,  263,  264,
  265,   52,  280,  268,  282,  283,  284,  285,  253,  287,
  288,  289,  264,  265,  266,  267,  268,  269,  261,  262,
  263,  264,  265,  257,  258,  207,  260,   83,  262,  307,
   83,  309,  284,   77,  156,  313,   93,  254,   10,   -1,
   -1,   -1,   -1,   -1,   -1,  279,  280,   -1,  306,  307,
  284,  285,   -1,  287,  288,  289,   -1,   -1,   -1,   -1,
  318,  319,  257,  258,  322,  260,   -1,  262,   -1,  327,
   -1,   -1,   -1,  307,   -1,  309,   -1,  257,  258,  313,
  260,   -1,  262,   -1,   -1,  280,   -1,   -1,   -1,  284,
  285,   -1,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
  280,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
   -1,   -1,  307,   -1,  309,   -1,  257,  258,  313,  260,
   -1,  262,   -1,   -1,   -1,   -1,   -1,  307,   -1,  309,
   -1,  257,  258,  313,  260,   -1,  262,   -1,   -1,  280,
   -1,   -1,  283,  284,  285,   -1,  287,  288,  289,   -1,
   -1,   -1,   -1,   -1,  280,   -1,   -1,   -1,  284,  285,
   -1,  287,  288,  289,   -1,   -1,  307,   -1,  309,   -1,
  257,  258,  313,  260,   -1,  262,   -1,   -1,   -1,   -1,
   -1,  307,   -1,  309,   -1,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,  280,   -1,   -1,   -1,  284,  285,   -1,
  287,  288,  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  307,   -1,  309,   -1,   -1,   -1,  313,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 315
#define YYUNDFTOKEN 369
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
"WRITE","KW_ALLOC","KW_FREE","PLUS","MUL","MINUS","DIV","MOD","ASSIGN","COMMA",
"SEMI","DOT","ARROW","AMPERSAND","GT","GE","LT","LE","NE","EQ","KW_BEGIN",
"KW_END","KW_IF","KW_THEN","KW_ELSE","KW_ENDIF","KW_WHILE","KW_DO",
"KW_ENDWHILE","KW_BREAK","KW_CONTINUE","KW_REPEAT","KW_UNTIL","KW_DECL",
"KW_ENDDECL","TYPE_INT","TYPE_STRING","TYPE_VOID","KW_TUPLE","AND","OR","NOT",
"INCREMENT","DECREMENT","ASSIGN_ADD","ASSIGN_SUB","ASSIGN_MUL","ASSIGN_DIV",
"ASSIGN_MOD","KW_RETURN","MAIN","KW_BRKP","KW_TYPE","KW_ENDTYPE","KW_NULL","ID",
"NUM","STRING_LITERAL","$accept","program","programBody",
"globalDeclarationsBlock","globalDeclarationList","globalDecl",
"globalTupleDeclaration","globalVarList","functionDefinitionBlock",
"functionDefinition","functionCall","argList","paramList","param",
"funcDeclParamList","funcDeclParam","mainBlock","body","expr","boolexpr",
"typeField","typeFieldList","statementList","statement","assignmentStatement",
"compoundAssignment","whileStatement","ifStatement","repeatUntilStatement",
"doWhileStatement","inputStatement","outputStatement","allocStatement",
"freeStatement","localDeclBlock","localDeclList","localDecl","localTupleDecl",
"idList","type","dimensionDecl","dimensionUsage","returnStatement",
"tupleFieldList","tupleField","tupleIdList","fieldAssignmentStatement",
"memberAccess","typeDefBlock","typeDefList","typeDef","$$1","$$2",
"illegal-symbol",
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
"statement : allocStatement SEMI",
"statement : freeStatement SEMI",
"allocStatement : ID ASSIGN KW_ALLOC '(' ')'",
"allocStatement : memberAccess ASSIGN KW_ALLOC '(' ')'",
"freeStatement : KW_FREE '(' ID ')'",
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
"expr : KW_NULL",
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
#line 332 "parser.y"

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
    initializeRegisters();
    generateHeader();
    initializeTypeTable();

    return yyparse();
}
#line 969 "y.tab.c"

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
#line 82 "parser.y"
	{ exit(0); }
#line 1642 "y.tab.c"
break;
case 5:
#line 90 "parser.y"
	{ printTypeTable(); }
#line 1647 "y.tab.c"
break;
case 10:
#line 99 "parser.y"
	{ createNewType(yystack.l_mark[0].node->varName); }
#line 1652 "y.tab.c"
break;
case 11:
#line 99 "parser.y"
	{ setFieldsOfType(yystack.l_mark[-4].node->varName, yystack.l_mark[-1].field); }
#line 1657 "y.tab.c"
break;
case 12:
#line 102 "parser.y"
	{ yyval.field = mergeTypeFields(yystack.l_mark[-1].field, yystack.l_mark[0].field); }
#line 1662 "y.tab.c"
break;
case 13:
#line 103 "parser.y"
	{ yyval.field = yystack.l_mark[0].field; }
#line 1667 "y.tab.c"
break;
case 14:
#line 106 "parser.y"
	{ yyval.field = createNewTypeField(yystack.l_mark[-1].node->varName, typeTableLookup("INT")); }
#line 1672 "y.tab.c"
break;
case 15:
#line 107 "parser.y"
	{ yyval.field = createNewTypeField(yystack.l_mark[-1].node->varName, typeTableLookup("STRING")); }
#line 1677 "y.tab.c"
break;
case 16:
#line 108 "parser.y"
	{ yyval.field = createNewTypeField(yystack.l_mark[-1].node->varName, typeTableLookup(yystack.l_mark[-2].node->varName)); }
#line 1682 "y.tab.c"
break;
case 17:
#line 111 "parser.y"
	{ printGST(); yyval.node = NULL; }
#line 1687 "y.tab.c"
break;
case 18:
#line 112 "parser.y"
	{ yyval.node = NULL; }
#line 1692 "y.tab.c"
break;
case 19:
#line 115 "parser.y"
	{ yyval.node = NULL; }
#line 1697 "y.tab.c"
break;
case 20:
#line 116 "parser.y"
	{ yyval.node = NULL; }
#line 1702 "y.tab.c"
break;
case 21:
#line 119 "parser.y"
	{ addToGST(yystack.l_mark[-2].node, yystack.l_mark[-1].node); yyval.node = NULL; }
#line 1707 "y.tab.c"
break;
case 22:
#line 120 "parser.y"
	{ yyval.node = NULL; }
#line 1712 "y.tab.c"
break;
case 23:
#line 123 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1717 "y.tab.c"
break;
case 24:
#line 124 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewArrayNode(yystack.l_mark[-1].node, yystack.l_mark[0].node)); }
#line 1722 "y.tab.c"
break;
case 25:
#line 125 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1727 "y.tab.c"
break;
case 26:
#line 126 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-5].node, createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node)); }
#line 1732 "y.tab.c"
break;
case 27:
#line 127 "parser.y"
	{ yyval.node = createNewArrayNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1737 "y.tab.c"
break;
case 28:
#line 128 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1742 "y.tab.c"
break;
case 29:
#line 129 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1747 "y.tab.c"
break;
case 30:
#line 130 "parser.y"
	{ yyval.node = createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1752 "y.tab.c"
break;
case 31:
#line 133 "parser.y"
	{ addTupleTypeToGST(yystack.l_mark[-4].node, yystack.l_mark[-2].node, yystack.l_mark[0].node); yyval.node = NULL; }
#line 1757 "y.tab.c"
break;
case 32:
#line 136 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1762 "y.tab.c"
break;
case 33:
#line 137 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1767 "y.tab.c"
break;
case 34:
#line 140 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1772 "y.tab.c"
break;
case 35:
#line 143 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1777 "y.tab.c"
break;
case 36:
#line 144 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1782 "y.tab.c"
break;
case 37:
#line 145 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1787 "y.tab.c"
break;
case 38:
#line 146 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1792 "y.tab.c"
break;
case 39:
#line 149 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1797 "y.tab.c"
break;
case 40:
#line 150 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1802 "y.tab.c"
break;
case 41:
#line 151 "parser.y"
	{ yyval.node = NULL; }
#line 1807 "y.tab.c"
break;
case 42:
#line 154 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, false, false); }
#line 1812 "y.tab.c"
break;
case 43:
#line 155 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, false, true); }
#line 1817 "y.tab.c"
break;
case 44:
#line 158 "parser.y"
	{ yyval.node = createTypeNode(INT); }
#line 1822 "y.tab.c"
break;
case 45:
#line 159 "parser.y"
	{ yyval.node = createTypeNode(STRING); }
#line 1827 "y.tab.c"
break;
case 46:
#line 160 "parser.y"
	{ yyval.node = createTupleTypeNode(yystack.l_mark[0].node); }
#line 1832 "y.tab.c"
break;
case 47:
#line 161 "parser.y"
	{ yyval.node = createTypeNode(VOID); }
#line 1837 "y.tab.c"
break;
case 48:
#line 162 "parser.y"
	{ yyval.node = createUserTypeNode(yystack.l_mark[0].node); }
#line 1842 "y.tab.c"
break;
case 49:
#line 165 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1847 "y.tab.c"
break;
case 50:
#line 166 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1852 "y.tab.c"
break;
case 51:
#line 170 "parser.y"
	{ currentFunction = lookupGST(yystack.l_mark[-3].node->varName); }
#line 1857 "y.tab.c"
break;
case 52:
#line 172 "parser.y"
	{ yyval.node = createFunctionDefinitionNode(yystack.l_mark[-9].node, yystack.l_mark[-8].node, yystack.l_mark[-6].node, yystack.l_mark[-2].node, yystack.l_mark[-1].node); }
#line 1862 "y.tab.c"
break;
case 53:
#line 175 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1867 "y.tab.c"
break;
case 54:
#line 178 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1872 "y.tab.c"
break;
case 55:
#line 179 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1877 "y.tab.c"
break;
case 56:
#line 180 "parser.y"
	{ yyval.node = NULL; }
#line 1882 "y.tab.c"
break;
case 57:
#line 183 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, true, false); }
#line 1887 "y.tab.c"
break;
case 58:
#line 184 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, true, true); }
#line 1892 "y.tab.c"
break;
case 59:
#line 187 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1897 "y.tab.c"
break;
case 60:
#line 188 "parser.y"
	{ yyval.node = NULL; }
#line 1902 "y.tab.c"
break;
case 61:
#line 189 "parser.y"
	{ yyval.node = NULL; }
#line 1907 "y.tab.c"
break;
case 62:
#line 192 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1912 "y.tab.c"
break;
case 63:
#line 193 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1917 "y.tab.c"
break;
case 64:
#line 194 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1922 "y.tab.c"
break;
case 65:
#line 195 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1927 "y.tab.c"
break;
case 66:
#line 198 "parser.y"
	{ addToLST(yystack.l_mark[-2].node, yystack.l_mark[-1].node); yyval.node = NULL; }
#line 1932 "y.tab.c"
break;
case 67:
#line 201 "parser.y"
	{ addTupleTypeToLST(yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); yyval.node = NULL; }
#line 1937 "y.tab.c"
break;
case 68:
#line 204 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1942 "y.tab.c"
break;
case 69:
#line 205 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1947 "y.tab.c"
break;
case 70:
#line 206 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1952 "y.tab.c"
break;
case 71:
#line 207 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1957 "y.tab.c"
break;
case 72:
#line 210 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1962 "y.tab.c"
break;
case 73:
#line 211 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1967 "y.tab.c"
break;
case 74:
#line 214 "parser.y"
	{ generateMainCode(yystack.l_mark[-1].node); printLocalSymbolTable(); freeLocalSymbolTable(); yyval.node = NULL; }
#line 1972 "y.tab.c"
break;
case 75:
#line 217 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1977 "y.tab.c"
break;
case 76:
#line 218 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1982 "y.tab.c"
break;
case 77:
#line 221 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1987 "y.tab.c"
break;
case 78:
#line 222 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1992 "y.tab.c"
break;
case 79:
#line 223 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1997 "y.tab.c"
break;
case 80:
#line 224 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2002 "y.tab.c"
break;
case 81:
#line 225 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2007 "y.tab.c"
break;
case 82:
#line 226 "parser.y"
	{ yyval.node = createBreakNode(); }
#line 2012 "y.tab.c"
break;
case 83:
#line 227 "parser.y"
	{ yyval.node = createContinueNode(); }
#line 2017 "y.tab.c"
break;
case 84:
#line 228 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2022 "y.tab.c"
break;
case 85:
#line 229 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2027 "y.tab.c"
break;
case 86:
#line 230 "parser.y"
	{ yyval.node = createBreakPointNode(); }
#line 2032 "y.tab.c"
break;
case 87:
#line 231 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2037 "y.tab.c"
break;
case 88:
#line 232 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2042 "y.tab.c"
break;
case 89:
#line 233 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2047 "y.tab.c"
break;
case 90:
#line 234 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2052 "y.tab.c"
break;
case 91:
#line 237 "parser.y"
	{ yyval.node = createAllocNode(yystack.l_mark[-4].node); }
#line 2057 "y.tab.c"
break;
case 92:
#line 238 "parser.y"
	{ yyval.node = createAllocNode(yystack.l_mark[-4].node); }
#line 2062 "y.tab.c"
break;
case 93:
#line 241 "parser.y"
	{ yyval.node = createFreeNode(yystack.l_mark[-1].node); }
#line 2067 "y.tab.c"
break;
case 94:
#line 244 "parser.y"
	{ yyval.node = createReturnNode(yystack.l_mark[0].node); }
#line 2072 "y.tab.c"
break;
case 95:
#line 247 "parser.y"
	{ yyval.node = createReadNode(yystack.l_mark[-2].node); }
#line 2077 "y.tab.c"
break;
case 96:
#line 248 "parser.y"
	{ yyval.node = createReadToArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node); }
#line 2082 "y.tab.c"
break;
case 97:
#line 251 "parser.y"
	{ yyval.node = createWriteNode(yystack.l_mark[-2].node); }
#line 2087 "y.tab.c"
break;
case 98:
#line 254 "parser.y"
	{ yyval.node = createAssignNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2092 "y.tab.c"
break;
case 99:
#line 255 "parser.y"
	{ yyval.node = createArrayAssignNode(yystack.l_mark[-4].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2097 "y.tab.c"
break;
case 100:
#line 256 "parser.y"
	{ yyval.node = createAssignToDereferencedNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2102 "y.tab.c"
break;
case 101:
#line 257 "parser.y"
	{ yyval.node = createIncrementNode(yystack.l_mark[-2].node); }
#line 2107 "y.tab.c"
break;
case 102:
#line 258 "parser.y"
	{ yyval.node = createDecrementNode(yystack.l_mark[-2].node); }
#line 2112 "y.tab.c"
break;
case 103:
#line 259 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2117 "y.tab.c"
break;
case 104:
#line 260 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2122 "y.tab.c"
break;
case 105:
#line 263 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_DOT); }
#line 2127 "y.tab.c"
break;
case 106:
#line 264 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_DOT); }
#line 2132 "y.tab.c"
break;
case 107:
#line 265 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_ARROW); }
#line 2137 "y.tab.c"
break;
case 108:
#line 268 "parser.y"
	{ yyval.node = createMemberAssignmentNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2142 "y.tab.c"
break;
case 109:
#line 271 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2147 "y.tab.c"
break;
case 110:
#line 272 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2152 "y.tab.c"
break;
case 111:
#line 273 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2157 "y.tab.c"
break;
case 112:
#line 274 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2162 "y.tab.c"
break;
case 113:
#line 275 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2167 "y.tab.c"
break;
case 114:
#line 278 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2172 "y.tab.c"
break;
case 115:
#line 279 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2177 "y.tab.c"
break;
case 116:
#line 282 "parser.y"
	{ yyval.node = createIfElseNode(yystack.l_mark[-6].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2182 "y.tab.c"
break;
case 117:
#line 283 "parser.y"
	{ yyval.node = createIfNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 2187 "y.tab.c"
break;
case 118:
#line 286 "parser.y"
	{ yyval.node = createWhileNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 2192 "y.tab.c"
break;
case 119:
#line 289 "parser.y"
	{ yyval.node = createRepeatUntilNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 2197 "y.tab.c"
break;
case 120:
#line 292 "parser.y"
	{ yyval.node = createDoWhileNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 2202 "y.tab.c"
break;
case 121:
#line 295 "parser.y"
	{ yyval.node = createArithOpNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2207 "y.tab.c"
break;
case 122:
#line 296 "parser.y"
	{ yyval.node = createArithOpNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2212 "y.tab.c"
break;
case 123:
#line 297 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2217 "y.tab.c"
break;
case 124:
#line 298 "parser.y"
	{ yyval.node = createArithOpNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2222 "y.tab.c"
break;
case 125:
#line 299 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2227 "y.tab.c"
break;
case 126:
#line 300 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2232 "y.tab.c"
break;
case 127:
#line 301 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2237 "y.tab.c"
break;
case 128:
#line 302 "parser.y"
	{ yyval.node = createVariableUsageNode(yystack.l_mark[0].node->varName); }
#line 2242 "y.tab.c"
break;
case 129:
#line 303 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2247 "y.tab.c"
break;
case 130:
#line 304 "parser.y"
	{ yyval.node = createArrayAccessNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 2252 "y.tab.c"
break;
case 131:
#line 305 "parser.y"
	{ yyval.node = createDereferenceNode(yystack.l_mark[0].node); }
#line 2257 "y.tab.c"
break;
case 132:
#line 306 "parser.y"
	{ yyval.node = createAddressToNode(yystack.l_mark[0].node); }
#line 2262 "y.tab.c"
break;
case 133:
#line 307 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2267 "y.tab.c"
break;
case 134:
#line 308 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2272 "y.tab.c"
break;
case 135:
#line 309 "parser.y"
	{ yyval.node = createNullNode(); }
#line 2277 "y.tab.c"
break;
case 136:
#line 312 "parser.y"
	{ yyval.node = createFunctionCallNode(yystack.l_mark[-2].node, NULL); }
#line 2282 "y.tab.c"
break;
case 137:
#line 313 "parser.y"
	{ yyval.node = createFunctionCallNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2287 "y.tab.c"
break;
case 138:
#line 315 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2292 "y.tab.c"
break;
case 139:
#line 316 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2297 "y.tab.c"
break;
case 140:
#line 319 "parser.y"
	{ yyval.node = createConditionNode(NODE_LE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2302 "y.tab.c"
break;
case 141:
#line 320 "parser.y"
	{ yyval.node = createConditionNode(NODE_LT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2307 "y.tab.c"
break;
case 142:
#line 321 "parser.y"
	{ yyval.node = createConditionNode(NODE_GE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2312 "y.tab.c"
break;
case 143:
#line 322 "parser.y"
	{ yyval.node = createConditionNode(NODE_GT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2317 "y.tab.c"
break;
case 144:
#line 323 "parser.y"
	{ yyval.node = createConditionNode(NODE_NE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2322 "y.tab.c"
break;
case 145:
#line 324 "parser.y"
	{ yyval.node = createConditionNode(NODE_EQ, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2327 "y.tab.c"
break;
case 146:
#line 325 "parser.y"
	{ yyval.node = createConditionNode(NODE_OR, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2332 "y.tab.c"
break;
case 147:
#line 326 "parser.y"
	{ yyval.node = createConditionNode(NODE_AND, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2337 "y.tab.c"
break;
case 148:
#line 327 "parser.y"
	{ yyval.node = createConditionNode(NODE_NOT, yystack.l_mark[0].node, NULL); }
#line 2342 "y.tab.c"
break;
case 149:
#line 328 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2347 "y.tab.c"
break;
#line 2349 "y.tab.c"
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
