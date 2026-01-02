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

#define KW_READ 257
#define KW_WRITE 258
#define KW_ALLOC 259
#define KW_FREE 260
#define KW_INIT 261
#define PLUS 262
#define MUL 263
#define MINUS 264
#define DIV 265
#define MOD 266
#define ASSIGN 267
#define COMMA 268
#define SEMI 269
#define DOT 270
#define ARROW 271
#define AMPERSAND 272
#define GT 273
#define GE 274
#define LT 275
#define LE 276
#define NE 277
#define EQ 278
#define KW_BEGIN 279
#define KW_END 280
#define KW_IF 281
#define KW_THEN 282
#define KW_ELSE 283
#define KW_ENDIF 284
#define KW_WHILE 285
#define KW_DO 286
#define KW_ENDWHILE 287
#define KW_BREAK 288
#define KW_CONTINUE 289
#define KW_REPEAT 290
#define KW_UNTIL 291
#define KW_DECL 292
#define KW_ENDDECL 293
#define TYPE_INT 294
#define TYPE_STRING 295
#define TYPE_VOID 296
#define KW_TUPLE 297
#define AND 298
#define OR 299
#define NOT 300
#define INCREMENT 301
#define DECREMENT 302
#define ASSIGN_ADD 303
#define ASSIGN_SUB 304
#define ASSIGN_MUL 305
#define ASSIGN_DIV 306
#define ASSIGN_MOD 307
#define KW_RETURN 308
#define MAIN 309
#define KW_BRKP 310
#define KW_TYPE 311
#define KW_ENDTYPE 312
#define KW_NULL 313
#define ID 314
#define NUM 315
#define STRING_LITERAL 316
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,   43,   43,   43,   45,   45,   47,
   46,   18,   18,   17,   17,   17,   44,   44,   48,   48,
    2,    2,    4,    4,    4,    4,    4,    4,    4,    4,
    3,   38,   38,   39,   40,   40,   40,   40,   11,   11,
   11,   12,   12,   34,   34,   34,   34,   34,    5,    5,
   49,    6,   14,    9,    9,    9,   10,   10,   32,   32,
   32,   50,   50,   50,   50,   51,   52,   33,   33,   33,
   33,   35,   35,   13,   19,   19,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   31,   29,   29,   29,   30,   37,   27,   27,   28,
   21,   21,   21,   21,   21,   21,   21,   42,   42,   42,
   42,   41,   22,   22,   22,   22,   22,   36,   36,   24,
   24,   23,   25,   26,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,    7,
    7,    8,    8,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,
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
    2,    5,    5,    5,    6,    4,    2,    5,    6,    5,
    4,    5,    5,    3,    3,    2,    2,    3,    4,    3,
    3,    3,    3,    3,    3,    3,    3,    4,    3,    9,
    7,    7,    7,    7,    3,    3,    3,    3,    3,    3,
    1,    1,    1,    2,    2,    2,    1,    1,    1,    3,
    4,    3,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    4,    0,    0,    6,   10,    0,
    9,    0,    0,    0,    0,    5,    8,   18,   44,   45,
   47,    0,   48,   20,    0,    0,    0,    0,    0,    0,
   50,    3,    0,    0,    0,    0,   22,    0,    0,    0,
   17,   19,   46,   49,    2,    0,    0,    0,    0,    0,
   13,    0,    0,   28,    0,    0,    0,    0,   21,    0,
    0,    0,    0,    0,    0,   11,   12,    0,    0,   33,
    0,   40,    0,    0,    0,    0,    0,    0,   55,    0,
   60,    0,    0,    0,   63,   65,    0,    0,   14,   15,
   16,   34,    0,    0,    0,   30,    0,   42,   73,    0,
   25,    0,    0,    0,   51,    0,   57,    0,    0,   70,
    0,   59,   62,   64,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   76,
   79,    0,   81,   80,   84,   85,   77,   78,    0,    0,
    0,    0,    0,    0,   74,   32,    0,   38,    0,   39,
   43,   72,    0,   54,    0,   58,    0,   71,    0,   66,
    0,    0,    0,    0,    0,    0,    0,   82,   83,    0,
    0,    0,  139,    0,  131,  133,    0,  137,    0,    0,
   86,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   87,   53,   75,  106,   89,   90,
   91,   88,  107,    0,    0,   37,    0,   26,    0,    0,
    0,   68,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  135,  136,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  110,  111,  104,  105,    0,
    0,    0,    0,    0,  140,    0,    0,    0,    0,    0,
    0,    0,    0,  108,    0,   35,    0,    0,   69,    0,
    0,    0,   96,    0,  152,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  130,
    0,  127,    0,  128,  129,    0,    0,  101,    0,  141,
  119,    0,    0,  109,    0,    0,   36,    0,    0,   98,
    0,  100,  103,  153,    0,    0,    0,    0,    0,    0,
  151,    0,    0,    0,    0,    0,   93,   92,    0,    0,
  102,  118,   94,   52,   67,   99,    0,    0,    0,    0,
   95,    0,  121,  122,  124,  123,    0,  120,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  294,  311,  318,  319,  331,  361,  309,  312,  314,  363,
  364,  292,  362,   40,  365,  312,  364,  293,  294,  295,
  296,  297,  314,  320,  321,  352,  366,  294,  297,  323,
  324,  331,  352,   41,  123,  314,  269,  263,  314,  322,
  293,  320,  314,  324,  331,  314,  123,  294,  295,  314,
  335,  336,   40,  314,   40,   91,  353,  268,  269,   40,
  292,  350,  314,  314,  314,  125,  335,  352,  356,  357,
  329,  330,  352,  315,   91,  263,  314,  327,  328,  352,
  293,  297,  352,  368,  369,  370,  279,  332,  269,  269,
  269,  314,  268,   41,  268,   41,  263,  314,   93,  315,
  314,   40,  353,  268,   41,  263,  314,  314,  263,  314,
  351,  293,  369,  370,  257,  258,  260,  263,  281,  285,
  286,  288,  289,  290,  308,  310,  314,  325,  337,  338,
  339,  340,  341,  342,  343,  344,  345,  346,  347,  348,
  349,  355,  359,  360,  125,  357,  263,  314,  358,  330,
  314,   93,  329,  328,  367,  314,   40,  314,  268,  269,
   40,   40,   40,  314,   40,   40,  337,  269,  269,  337,
  263,  272,  313,  314,  315,  316,   40,  325,  333,  360,
  269,  267,  270,  271,  301,  302,  303,  304,  305,  306,
  307,   40,   91,  354,  269,  280,  338,  269,  269,  269,
  269,  269,  269,  267,  270,  314,  268,   41,  123,  356,
  263,  314,  314,  333,  314,  267,  300,   40,  333,  334,
  334,  285,  291,  314,  314,  354,  333,  262,  263,  264,
  265,  266,  259,  261,  333,  314,  314,  269,  269,  333,
  333,  333,  333,  333,   41,  326,  333,  333,  267,  270,
   91,  259,  333,  314,  263,  314,  350,   41,  314,   41,
  354,   41,   41,  333,  334,  333,  334,  273,  274,  275,
  276,  277,  278,  298,  299,   41,   41,   40,   40,   41,
  333,  333,  333,  333,  333,   40,   40,  269,  268,   41,
   93,  259,  333,  314,  333,   40,  314,  332,  358,  269,
   41,  269,  269,   41,  333,  333,  333,  333,  333,  333,
  334,  334,  282,  286,  334,  334,   41,   41,  333,   40,
  269,   93,   41,  125,  269,  269,  337,  337,   41,   41,
   41,  283,  284,  287,  269,  269,  337,  284,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          3,
    4,   24,   25,   40,   30,   31,  178,  246,   78,   79,
   71,   72,    5,   88,  219,  220,   51,   52,  129,  130,
  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,
  141,   62,  111,   68,   57,  194,  142,   69,   70,  149,
  143,  180,    6,   13,   10,   11,   15,   27,  155,   84,
   85,   86,
};
static const YYINT yysindex[] = {                      -261,
 -279, -244,    0,    0,    0, -255,    2,    0,    0, -176,
    0, -150, -136,   34,  -27,    0,    0,    0,    0,    0,
    0, -225,    0,    0, -165, -243,  176, -279, -202, -136,
    0,    0, -192,   16, -181,   68,    0, -166,  -19, -212,
    0,    0,    0,    0,    0,  123, -123, -139, -137, -133,
    0, -115,  162,    0,  162, -132,   97, -241,    0,  162,
  202,  -90,  -77,  -75,  -74,    0,    0, -118,  -34,    0,
  -18,    0, -238,  104, -107, -114,  -11,  -15,    0, -232,
    0, -104, -231,  224,    0,    0,  355,   82,    0,    0,
    0,    0,  162, -229,  162,    0, -102,    0,    0,  127,
    0,  162,   97,  162,    0,  -89,    0,  186,  -84,    0,
 -206,    0,    0,    0,  189,  195,  199,  -73,  205,  212,
  355,   27,   50,  355,  -16,   62,    1,   67, -179,    0,
    0,   83,    0,    0,    0,    0,    0,    0,   92,  102,
  106,  111,  122, -209,    0,    0,  -59,    0,   81,    0,
    0,    0,  -14,    0,  270,    0,  162,    0, -223,    0,
   87,  -16,   88,  129,  -36,  -36,  390,    0,    0,  268,
  110,  117,    0,  -22,    0,    0,  -16,    0, -112,  124,
    0,  -40,  118,  125,  136,  167,  -16,  -16,  -16,  -16,
  -16,  -32,  -16,  -85,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -26,  126,    0, -219,    0, -123,   -5,
  128,    0,    8,  157,  396,  -16,  -36,  -36,  419,  -39,
  -29,  408,  409,    0,    0,  -80,  181,  -16,  -16,  -16,
  -16,  -16,  411,  412,  308,    0,    0,    0,    0, -112,
 -112, -112, -112, -112,    0,   -3, -112,  -92,  -21,  139,
  -16,  414, -112,    0,  153,    0,  -90, -229,    0,  206,
   12,  209,    0,  443,    0,  152,  -13,  -16,  -16,  -16,
  -16,  -16,  -16,  -36,  -36,  192,  182,  -36,  -36,    0,
 -148,    0, -148,    0,    0,  438,  439,    0,  -16,    0,
    0,  441,  451,    0,  -48,  445,    0,  359, -143,    0,
  218,    0,    0,    0, -112, -112, -112, -112, -112, -112,
    0,  194,  355,  355,   19,   36,    0,    0, -112,  452,
    0,    0,    0,    0,    0,    0,  225,  306, -234,  231,
    0,  355,    0,    0,    0,    0,  344,    0,
};
static const YYINT yyrindex[] = {                       215,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  180,    0,    0,
    0,    0,    0,    0,    0, -216,    0,    0, -127,    0,
    0,    0,    0,    0,    0,    0,  233,    0,    0,    0,
    0,    0,    0,    0,   -2,    0, -113,    0,    0,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -103,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -2,  -82,    0,    0,    0,    0, -216,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  254,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   47,    0,    0,    0,    0,  258,   64,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  233,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   91,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  260,
  261,  263,  265,  267,    0,    0,   33,    0,    0,    0,
    0,    0,  278,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  108,    0,  135,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,   49,   52,   75,   80,   89,
    0,  -38,    0,    0,    0,    0,    0,    0,   46,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  510,    0,    0,    0,  518,  -70,    0,    0,  436,
  448,  456,   35,  295,  273, -151,  503,    0, -108, -124,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  351,    0,  107,  484, -119,    0,  410,  472,  310,
    0,  271,    0,    0,    0,  565,    0,    0,    0,    0,
  495,  496,
};
#define YYTABLESIZE 720
static const YYINT yytable[] = {                        177,
  291,  276,  150,  218,  197,  251,   94,  177,  245,   66,
  251,  277,  167,  177,  221,  170,  128,  192,  177,   38,
   55,   76,   96,  177,   97,  105,  208,  304,  102,    7,
  106,  109,    1,  147,  335,  258,   12,  290,   41,  211,
  192,   14,  197,  255,  322,  197,   46,   32,  260,    2,
  128,  314,  301,  128,  226,   58,   59,  204,  128,  329,
  205,  159,  160,   56,   45,  265,  267,    8,  193,    9,
   39,   56,   77,  143,   34,   98,  330,  115,  116,   56,
  117,  107,  110,  118,  148,  147,  142,  132,   36,  146,
  212,  193,  145,  261,  256,   35,  128,   46,  193,  128,
  196,  119,  251,   37,  138,  120,  121,   53,  122,  123,
  124,   43,   48,   49,  229,  144,  231,  232,   26,   33,
  148,   46,  311,  312,  207,  325,  315,  316,  125,  149,
  126,  134,   50,   26,  127,   16,   33,    9,   47,  132,
   29,   29,   18,   19,   20,   21,   22,   54,  125,  228,
  229,  230,  231,  232,   27,   27,  138,   28,   20,   21,
   29,   73,   60,   23,   23,   23,   80,   83,   61,  228,
  229,  230,  231,  232,   63,  126,   64,   23,   48,   49,
   65,  249,   74,  134,  250,   24,   24,   75,   87,  250,
   83,   89,  280,   90,   91,   92,   99,  262,   50,  101,
  125,   73,  197,  197,  327,  328,  145,  100,   73,  108,
   80,  151,  197,  228,  229,  230,  231,  232,  233,  152,
  234,  280,  171,  337,  156,  157,  171,  126,  161,  158,
  171,  172,  252,   93,  162,  172,  171,  292,  163,  172,
  164,  171,  128,  128,  165,  172,  171,  183,  184,   95,
  172,  166,  104,   95,  206,  172,  128,  128,  274,  275,
  150,  128,   93,  217,  289,   41,  128,  182,  274,  275,
  183,  184,  173,  174,  175,  176,  173,  174,  175,  176,
  173,  174,  175,  176,  274,  275,  173,  174,  175,  176,
   56,  173,  174,  175,  176,  168,  173,  174,  175,  176,
  143,  185,  186,  187,  188,  189,  190,  191,  132,  132,
  132,  132,  132,  142,  132,  132,  274,  275,  169,  132,
  132,  132,  132,  132,  132,  138,  138,  138,  138,  138,
  181,  138,  138,  274,  275,  195,  138,  138,  138,  138,
  138,  138,  147,  147,  132,  132,  146,  146,  207,  145,
  145,  198,  134,  134,  134,  134,  134,  144,  134,  134,
  199,  138,  138,  134,  134,  134,  134,  134,  134,  125,
  200,  125,  144,  144,  201,  125,  125,  148,  148,  202,
  125,  125,  125,  125,  125,  125,  149,  149,  134,  134,
  203,  144,  209,  205,  144,  216,  126,  179,  126,  144,
  213,  215,  126,  126,  238,  125,  125,  126,  126,  126,
  126,  126,  126,  228,  229,  230,  231,  232,  228,  229,
  230,  231,  232,  224,  268,  269,  270,  271,  272,  273,
  225,  236,  126,  126,  214,  239,  263,  144,  237,  254,
  144,  259,  228,  229,  230,  231,  232,  278,  279,  227,
  286,  287,  294,  296,  235,   19,   20,   21,   29,  240,
  241,  242,  243,  244,  247,  248,  297,  314,   41,   19,
   20,   21,   22,  313,  300,   23,  253,  302,  317,  318,
  320,  115,  116,  324,  117,  323,  326,  118,  264,   23,
  266,  274,  331,   44,   81,   19,   20,   21,   82,  336,
  281,  282,  283,  284,  285,  119,    7,  332,  333,  120,
  121,   61,  122,  123,  124,   23,  112,   19,   20,   21,
   82,  293,   31,  295,  115,  116,   97,  117,  113,  114,
  118,  115,  125,  116,  126,  117,   42,   23,  127,  154,
  305,  306,  307,  308,  309,  310,  112,   44,  119,  153,
  150,  298,  120,  121,   67,  122,  123,  124,  223,  257,
  103,  319,  115,  116,  146,  117,  210,  299,  118,  228,
  229,  230,  231,  232,   17,  125,  288,  126,  113,  114,
    0,  127,    0,  144,  144,    0,  119,    0,    0,    0,
  120,  121,  334,  122,  123,  124,    0,  144,  144,    0,
  115,  116,  144,  117,    0,    0,  118,  144,    0,    0,
    0,  115,  116,  125,  117,  126,    0,  118,    0,  127,
    0,    0,    0,    0,  119,    0,    0,  338,  120,  121,
    0,  122,  123,  124,    0,  119,    0,    0,    0,  120,
  121,    0,  122,  123,  124,    0,  115,  116,    0,  117,
    0,  125,  118,  126,    0,    0,    0,  127,    0,    0,
    0,    0,  125,    0,  126,    0,    0,    0,  127,    0,
  119,    0,    0,    0,  222,  121,    0,  122,  123,  124,
  228,  229,  230,  231,  232,    0,    0,    0,    0,    0,
    0,  268,  269,  270,  271,  272,  273,  125,    0,  126,
    0,    0,    0,  127,  228,  229,  230,  231,  232,    0,
    0,  303,  228,  229,  230,  231,  232,    0,    0,  321,
};
static const YYINT yycheck[] = {                         40,
   93,   41,   41,   40,  129,   91,   41,   40,   41,  125,
   91,   41,  121,   40,  166,  124,   87,   40,   40,  263,
   40,  263,   41,   40,  263,   41,   41,   41,   40,  309,
  263,  263,  294,  263,  269,   41,  292,   41,   41,  263,
   40,   40,  167,  263,   93,  170,  263,   13,   41,  311,
  121,  286,   41,  124,  174,  268,  269,  267,  129,   41,
  270,  268,  269,   41,   30,  217,  218,  312,   91,  314,
  314,   91,  314,   41,   41,  314,   41,  257,  258,   91,
  260,  314,  314,  263,  314,   41,   41,   41,  314,   41,
  314,   91,   41,  213,  314,  123,  167,  314,   91,  170,
  280,  281,   91,  269,   41,  285,  286,   40,  288,  289,
  290,  314,  294,  295,  263,   41,  265,  266,   12,   13,
   41,  314,  274,  275,  268,  269,  278,  279,  308,   41,
  310,   41,  314,   27,  314,  312,   30,  314,  123,   93,
  268,  269,  293,  294,  295,  296,  297,  314,   41,  262,
  263,  264,  265,  266,  268,  269,   93,  294,  295,  296,
  297,   55,   40,  314,  268,  269,   60,   61,  292,  262,
  263,  264,  265,  266,  314,   41,  314,  314,  294,  295,
  314,  267,  315,   93,  270,  268,  269,   91,  279,  270,
   84,  269,   41,  269,  269,  314,   93,   41,  314,  314,
   93,   95,  327,  328,  313,  314,  125,  315,  102,  314,
  104,  314,  337,  262,  263,  264,  265,  266,  259,   93,
  261,   41,  263,  332,  314,   40,  263,   93,   40,  314,
  263,  272,  259,  268,   40,  272,  263,  259,   40,  272,
  314,  263,  313,  314,   40,  272,  263,  270,  271,  268,
  272,   40,  268,  268,  314,  272,  327,  328,  298,  299,
  299,  332,  268,  300,  268,  268,  337,  267,  298,  299,
  270,  271,  313,  314,  315,  316,  313,  314,  315,  316,
  313,  314,  315,  316,  298,  299,  313,  314,  315,  316,
  268,  313,  314,  315,  316,  269,  313,  314,  315,  316,
  268,  301,  302,  303,  304,  305,  306,  307,  262,  263,
  264,  265,  266,  268,  268,  269,  298,  299,  269,  273,
  274,  275,  276,  277,  278,  262,  263,  264,  265,  266,
  269,  268,  269,  298,  299,  269,  273,  274,  275,  276,
  277,  278,  298,  299,  298,  299,  298,  299,  268,  298,
  299,  269,  262,  263,  264,  265,  266,   87,  268,  269,
  269,  298,  299,  273,  274,  275,  276,  277,  278,  262,
  269,  264,  298,  299,  269,  268,  269,  298,  299,  269,
  273,  274,  275,  276,  277,  278,  298,  299,  298,  299,
  269,  121,  123,  270,  124,  267,  262,  125,  264,  129,
  314,  314,  268,  269,  269,  298,  299,  273,  274,  275,
  276,  277,  278,  262,  263,  264,  265,  266,  262,  263,
  264,  265,  266,  314,  273,  274,  275,  276,  277,  278,
  314,  314,  298,  299,  162,  269,   41,  167,  314,  314,
  170,  314,  262,  263,  264,  265,  266,   40,   40,  177,
   40,   40,  314,   40,  182,  294,  295,  296,  297,  187,
  188,  189,  190,  191,  192,  193,  314,  286,  293,  294,
  295,  296,  297,  282,  269,  314,  204,  269,   41,   41,
   40,  257,  258,  125,  260,   41,  269,  263,  216,  314,
  218,  298,   41,  314,  293,  294,  295,  296,  297,  269,
  228,  229,  230,  231,  232,  281,  292,  283,  284,  285,
  286,  279,  288,  289,  290,  314,  293,  294,  295,  296,
  297,  249,  269,  251,  257,  258,  269,  260,  269,  269,
  263,  269,  308,  269,  310,  269,   27,  314,  314,  104,
  268,  269,  270,  271,  272,  273,  269,   30,  281,  102,
   95,  257,  285,  286,   52,  288,  289,  290,  291,  209,
   77,  289,  257,  258,   93,  260,  157,  258,  263,  262,
  263,  264,  265,  266,   10,  308,  269,  310,   84,   84,
   -1,  314,   -1,  313,  314,   -1,  281,   -1,   -1,   -1,
  285,  286,  287,  288,  289,  290,   -1,  327,  328,   -1,
  257,  258,  332,  260,   -1,   -1,  263,  337,   -1,   -1,
   -1,  257,  258,  308,  260,  310,   -1,  263,   -1,  314,
   -1,   -1,   -1,   -1,  281,   -1,   -1,  284,  285,  286,
   -1,  288,  289,  290,   -1,  281,   -1,   -1,   -1,  285,
  286,   -1,  288,  289,  290,   -1,  257,  258,   -1,  260,
   -1,  308,  263,  310,   -1,   -1,   -1,  314,   -1,   -1,
   -1,   -1,  308,   -1,  310,   -1,   -1,   -1,  314,   -1,
  281,   -1,   -1,   -1,  285,  286,   -1,  288,  289,  290,
  262,  263,  264,  265,  266,   -1,   -1,   -1,   -1,   -1,
   -1,  273,  274,  275,  276,  277,  278,  308,   -1,  310,
   -1,   -1,   -1,  314,  262,  263,  264,  265,  266,   -1,
   -1,  269,  262,  263,  264,  265,  266,   -1,   -1,  269,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 316
#define YYUNDFTOKEN 371
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","KW_READ",
"KW_WRITE","KW_ALLOC","KW_FREE","KW_INIT","PLUS","MUL","MINUS","DIV","MOD",
"ASSIGN","COMMA","SEMI","DOT","ARROW","AMPERSAND","GT","GE","LT","LE","NE","EQ",
"KW_BEGIN","KW_END","KW_IF","KW_THEN","KW_ELSE","KW_ENDIF","KW_WHILE","KW_DO",
"KW_ENDWHILE","KW_BREAK","KW_CONTINUE","KW_REPEAT","KW_UNTIL","KW_DECL",
"KW_ENDDECL","TYPE_INT","TYPE_STRING","TYPE_VOID","KW_TUPLE","AND","OR","NOT",
"INCREMENT","DECREMENT","ASSIGN_ADD","ASSIGN_SUB","ASSIGN_MUL","ASSIGN_DIV",
"ASSIGN_MOD","KW_RETURN","MAIN","KW_BRKP","KW_TYPE","KW_ENDTYPE","KW_NULL","ID",
"NUM","STRING_LITERAL","$accept","program","programBody","globalDecl",
"globalTupleDecl","globalVarList","funcDefBlock","funcDef","funcCall","argList",
"paramList","param","funcDeclParamList","funcDeclParam","mainBlock","body",
"expr","boolexpr","typeField","typeFieldList","stmtList","stmt",
"assignmentStmt","compoundAssignment","whileStmt","ifStmt","repeatUntilStmt",
"doWhileStmt","inputStmt","outputStmt","allocStmt","freeStmt","initStmt",
"localDeclBlock","idList","type","dimensionDecl","dimensionUsage","returnStmt",
"tupleFieldList","tupleField","tupleIdList","fieldAssignStmt","fieldAccess",
"typeDefBlock","globalDeclBlock","typeDefList","typeDef","$$1","globalDeclList",
"$$2","localDeclList","localDecl","localTupleDecl","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : programBody",
"programBody : typeDefBlock globalDeclBlock funcDefBlock mainBlock",
"programBody : typeDefBlock globalDeclBlock mainBlock",
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
"globalDeclBlock : KW_DECL globalDeclList KW_ENDDECL",
"globalDeclBlock : KW_DECL KW_ENDDECL",
"globalDeclList : globalDeclList globalDecl",
"globalDeclList : globalDecl",
"globalDecl : type globalVarList SEMI",
"globalDecl : globalTupleDecl SEMI",
"globalVarList : globalVarList COMMA ID",
"globalVarList : globalVarList COMMA ID dimensionDecl",
"globalVarList : globalVarList COMMA MUL ID",
"globalVarList : globalVarList COMMA ID '(' funcDeclParamList ')'",
"globalVarList : ID dimensionDecl",
"globalVarList : MUL ID",
"globalVarList : ID",
"globalVarList : ID '(' funcDeclParamList ')'",
"globalTupleDecl : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList",
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
"funcDefBlock : funcDefBlock funcDef",
"funcDefBlock : funcDef",
"$$2 :",
"funcDef : type ID '(' paramList ')' $$2 '{' localDeclBlock body '}'",
"body : KW_BEGIN stmtList KW_END",
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
"stmtList : stmtList stmt",
"stmtList : stmt",
"stmt : inputStmt",
"stmt : outputStmt",
"stmt : assignmentStmt",
"stmt : ifStmt",
"stmt : whileStmt",
"stmt : KW_BREAK SEMI",
"stmt : KW_CONTINUE SEMI",
"stmt : repeatUntilStmt",
"stmt : doWhileStmt",
"stmt : KW_BRKP SEMI",
"stmt : funcCall SEMI",
"stmt : returnStmt SEMI",
"stmt : allocStmt SEMI",
"stmt : freeStmt SEMI",
"stmt : initStmt SEMI",
"initStmt : ID ASSIGN KW_INIT '(' ')'",
"allocStmt : ID ASSIGN KW_ALLOC '(' ')'",
"allocStmt : fieldAccess ASSIGN KW_ALLOC '(' ')'",
"allocStmt : ID dimensionUsage ASSIGN KW_ALLOC '(' ')'",
"freeStmt : KW_FREE '(' ID ')'",
"returnStmt : KW_RETURN expr",
"inputStmt : KW_READ '(' ID ')' SEMI",
"inputStmt : KW_READ '(' ID dimensionUsage ')' SEMI",
"outputStmt : KW_WRITE '(' expr ')' SEMI",
"assignmentStmt : ID ASSIGN expr SEMI",
"assignmentStmt : ID dimensionUsage ASSIGN expr SEMI",
"assignmentStmt : MUL ID ASSIGN expr SEMI",
"assignmentStmt : ID INCREMENT SEMI",
"assignmentStmt : ID DECREMENT SEMI",
"assignmentStmt : compoundAssignment SEMI",
"assignmentStmt : fieldAssignStmt SEMI",
"fieldAccess : fieldAccess DOT ID",
"fieldAccess : ID dimensionUsage DOT ID",
"fieldAccess : ID DOT ID",
"fieldAccess : ID ARROW ID",
"fieldAssignStmt : fieldAccess ASSIGN expr",
"compoundAssignment : ID ASSIGN_ADD expr",
"compoundAssignment : ID ASSIGN_SUB expr",
"compoundAssignment : ID ASSIGN_MUL expr",
"compoundAssignment : ID ASSIGN_DIV expr",
"compoundAssignment : ID ASSIGN_MOD expr",
"dimensionUsage : dimensionUsage '[' expr ']'",
"dimensionUsage : '[' expr ']'",
"ifStmt : KW_IF '(' boolexpr ')' KW_THEN stmtList KW_ELSE stmtList KW_ENDIF",
"ifStmt : KW_IF '(' boolexpr ')' KW_THEN stmtList KW_ENDIF",
"whileStmt : KW_WHILE '(' boolexpr ')' KW_DO stmtList KW_ENDWHILE",
"repeatUntilStmt : KW_REPEAT stmtList KW_UNTIL '(' boolexpr ')' SEMI",
"doWhileStmt : KW_DO stmtList KW_WHILE '(' boolexpr ')' SEMI",
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
"expr : funcCall",
"expr : fieldAccess",
"expr : KW_NULL",
"funcCall : ID '(' ')'",
"funcCall : ID '(' argList ')'",
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
#line 339 "parser.y"

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
	{ printGST(); }
#line 1687 "y.tab.c"
break;
case 21:
#line 119 "parser.y"
	{ addToGST(yystack.l_mark[-2].node, yystack.l_mark[-1].node); }
#line 1692 "y.tab.c"
break;
case 23:
#line 123 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1697 "y.tab.c"
break;
case 24:
#line 124 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewArrayNode(yystack.l_mark[-1].node, yystack.l_mark[0].node)); }
#line 1702 "y.tab.c"
break;
case 25:
#line 125 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1707 "y.tab.c"
break;
case 26:
#line 126 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-5].node, createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node)); }
#line 1712 "y.tab.c"
break;
case 27:
#line 127 "parser.y"
	{ yyval.node = createNewArrayNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1717 "y.tab.c"
break;
case 28:
#line 128 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1722 "y.tab.c"
break;
case 29:
#line 129 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1727 "y.tab.c"
break;
case 30:
#line 130 "parser.y"
	{ yyval.node = createFunctionDeclarationNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1732 "y.tab.c"
break;
case 31:
#line 133 "parser.y"
	{ addTupleTypeToGST(yystack.l_mark[-4].node, yystack.l_mark[-2].node, yystack.l_mark[0].node); yyval.node = NULL; }
#line 1737 "y.tab.c"
break;
case 32:
#line 136 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1742 "y.tab.c"
break;
case 33:
#line 137 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1747 "y.tab.c"
break;
case 34:
#line 140 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1752 "y.tab.c"
break;
case 35:
#line 143 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1757 "y.tab.c"
break;
case 36:
#line 144 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1762 "y.tab.c"
break;
case 37:
#line 145 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1767 "y.tab.c"
break;
case 38:
#line 146 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1772 "y.tab.c"
break;
case 39:
#line 149 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1777 "y.tab.c"
break;
case 40:
#line 150 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1782 "y.tab.c"
break;
case 41:
#line 151 "parser.y"
	{ yyval.node = NULL; }
#line 1787 "y.tab.c"
break;
case 42:
#line 154 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, false, false); }
#line 1792 "y.tab.c"
break;
case 43:
#line 155 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, false, true); }
#line 1797 "y.tab.c"
break;
case 44:
#line 158 "parser.y"
	{ yyval.node = createTypeNode(INT); }
#line 1802 "y.tab.c"
break;
case 45:
#line 159 "parser.y"
	{ yyval.node = createTypeNode(STRING); }
#line 1807 "y.tab.c"
break;
case 46:
#line 160 "parser.y"
	{ yyval.node = createTupleTypeNode(yystack.l_mark[0].node); }
#line 1812 "y.tab.c"
break;
case 47:
#line 161 "parser.y"
	{ yyval.node = createTypeNode(VOID); }
#line 1817 "y.tab.c"
break;
case 48:
#line 162 "parser.y"
	{ yyval.node = createUserTypeNode(yystack.l_mark[0].node); }
#line 1822 "y.tab.c"
break;
case 49:
#line 165 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1827 "y.tab.c"
break;
case 50:
#line 166 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1832 "y.tab.c"
break;
case 51:
#line 170 "parser.y"
	{ currentFunction = lookupGST(yystack.l_mark[-3].node->varName); }
#line 1837 "y.tab.c"
break;
case 52:
#line 172 "parser.y"
	{ yyval.node = createFunctionDefinitionNode(yystack.l_mark[-9].node, yystack.l_mark[-8].node, yystack.l_mark[-6].node, yystack.l_mark[-2].node, yystack.l_mark[-1].node); }
#line 1842 "y.tab.c"
break;
case 53:
#line 175 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1847 "y.tab.c"
break;
case 54:
#line 178 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1852 "y.tab.c"
break;
case 55:
#line 179 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1857 "y.tab.c"
break;
case 56:
#line 180 "parser.y"
	{ yyval.node = NULL; }
#line 1862 "y.tab.c"
break;
case 57:
#line 183 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-1].node, yystack.l_mark[0].node, true, false); }
#line 1867 "y.tab.c"
break;
case 58:
#line 184 "parser.y"
	{ yyval.node = createParamNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, true, true); }
#line 1872 "y.tab.c"
break;
case 59:
#line 187 "parser.y"
	{ yyval.node = NULL; }
#line 1877 "y.tab.c"
break;
case 60:
#line 188 "parser.y"
	{ yyval.node = NULL; }
#line 1882 "y.tab.c"
break;
case 61:
#line 189 "parser.y"
	{ yyval.node = NULL; }
#line 1887 "y.tab.c"
break;
case 66:
#line 198 "parser.y"
	{ addToLST(yystack.l_mark[-2].node, yystack.l_mark[-1].node); }
#line 1892 "y.tab.c"
break;
case 67:
#line 201 "parser.y"
	{ addTupleTypeToLST(yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1897 "y.tab.c"
break;
case 68:
#line 204 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 1902 "y.tab.c"
break;
case 69:
#line 205 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, createNewPointerNode(yystack.l_mark[0].node)); }
#line 1907 "y.tab.c"
break;
case 70:
#line 206 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1912 "y.tab.c"
break;
case 71:
#line 207 "parser.y"
	{ yyval.node = createNewPointerNode(yystack.l_mark[0].node); }
#line 1917 "y.tab.c"
break;
case 72:
#line 210 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 1922 "y.tab.c"
break;
case 73:
#line 211 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1927 "y.tab.c"
break;
case 74:
#line 214 "parser.y"
	{ generateMainCode(yystack.l_mark[-1].node); printLocalSymbolTable(); 
                                                                    freeLocalSymbolTable(); yyval.node = NULL; }
#line 1933 "y.tab.c"
break;
case 75:
#line 218 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 1938 "y.tab.c"
break;
case 76:
#line 219 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1943 "y.tab.c"
break;
case 77:
#line 222 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1948 "y.tab.c"
break;
case 78:
#line 223 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1953 "y.tab.c"
break;
case 79:
#line 224 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1958 "y.tab.c"
break;
case 80:
#line 225 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1963 "y.tab.c"
break;
case 81:
#line 226 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1968 "y.tab.c"
break;
case 82:
#line 227 "parser.y"
	{ yyval.node = createBreakNode(); }
#line 1973 "y.tab.c"
break;
case 83:
#line 228 "parser.y"
	{ yyval.node = createContinueNode(); }
#line 1978 "y.tab.c"
break;
case 84:
#line 229 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1983 "y.tab.c"
break;
case 85:
#line 230 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 1988 "y.tab.c"
break;
case 86:
#line 231 "parser.y"
	{ yyval.node = createBreakPointNode(); }
#line 1993 "y.tab.c"
break;
case 87:
#line 232 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 1998 "y.tab.c"
break;
case 88:
#line 233 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2003 "y.tab.c"
break;
case 89:
#line 234 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2008 "y.tab.c"
break;
case 90:
#line 235 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2013 "y.tab.c"
break;
case 91:
#line 236 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2018 "y.tab.c"
break;
case 92:
#line 239 "parser.y"
	{ yyval.node = createInitNode(yystack.l_mark[-4].node); }
#line 2023 "y.tab.c"
break;
case 93:
#line 242 "parser.y"
	{ yyval.node = createAllocNode(yystack.l_mark[-4].node); }
#line 2028 "y.tab.c"
break;
case 94:
#line 243 "parser.y"
	{ yyval.node = createAllocNode(yystack.l_mark[-4].node); }
#line 2033 "y.tab.c"
break;
case 95:
#line 244 "parser.y"
	{ yyval.node = createAllocNode(createArrayAccessNode(yystack.l_mark[-5].node, yystack.l_mark[-4].node)); }
#line 2038 "y.tab.c"
break;
case 96:
#line 247 "parser.y"
	{ yyval.node = createFreeNode(yystack.l_mark[-1].node); }
#line 2043 "y.tab.c"
break;
case 97:
#line 250 "parser.y"
	{ yyval.node = createReturnNode(yystack.l_mark[0].node); }
#line 2048 "y.tab.c"
break;
case 98:
#line 253 "parser.y"
	{ yyval.node = createReadNode(yystack.l_mark[-2].node); }
#line 2053 "y.tab.c"
break;
case 99:
#line 254 "parser.y"
	{ yyval.node = createReadToArrayNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node); }
#line 2058 "y.tab.c"
break;
case 100:
#line 257 "parser.y"
	{ yyval.node = createWriteNode(yystack.l_mark[-2].node); }
#line 2063 "y.tab.c"
break;
case 101:
#line 260 "parser.y"
	{ yyval.node = createAssignNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2068 "y.tab.c"
break;
case 102:
#line 261 "parser.y"
	{ yyval.node = createArrayAssignNode(yystack.l_mark[-4].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2073 "y.tab.c"
break;
case 103:
#line 262 "parser.y"
	{ yyval.node = createAssignToDereferencedNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2078 "y.tab.c"
break;
case 104:
#line 263 "parser.y"
	{ yyval.node = createIncrementNode(yystack.l_mark[-2].node); }
#line 2083 "y.tab.c"
break;
case 105:
#line 264 "parser.y"
	{ yyval.node = createDecrementNode(yystack.l_mark[-2].node); }
#line 2088 "y.tab.c"
break;
case 106:
#line 265 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2093 "y.tab.c"
break;
case 107:
#line 266 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2098 "y.tab.c"
break;
case 108:
#line 269 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_DOT); }
#line 2103 "y.tab.c"
break;
case 109:
#line 270 "parser.y"
	{ yyval.node = createMemberAccessNode(createArrayAccessNode(yystack.l_mark[-3].node, yystack.l_mark[-2].node), yystack.l_mark[0].node, ACCESS_DOT); }
#line 2108 "y.tab.c"
break;
case 110:
#line 271 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_DOT); }
#line 2113 "y.tab.c"
break;
case 111:
#line 272 "parser.y"
	{ yyval.node = createMemberAccessNode(yystack.l_mark[-2].node, yystack.l_mark[0].node, ACCESS_ARROW); }
#line 2118 "y.tab.c"
break;
case 112:
#line 275 "parser.y"
	{ yyval.node = createMemberAssignmentNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2123 "y.tab.c"
break;
case 113:
#line 278 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2128 "y.tab.c"
break;
case 114:
#line 279 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2133 "y.tab.c"
break;
case 115:
#line 280 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2138 "y.tab.c"
break;
case 116:
#line 281 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2143 "y.tab.c"
break;
case 117:
#line 282 "parser.y"
	{ yyval.node = createCompoundAssignNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2148 "y.tab.c"
break;
case 118:
#line 285 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2153 "y.tab.c"
break;
case 119:
#line 286 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2158 "y.tab.c"
break;
case 120:
#line 289 "parser.y"
	{ yyval.node = createIfElseNode(yystack.l_mark[-6].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2163 "y.tab.c"
break;
case 121:
#line 290 "parser.y"
	{ yyval.node = createIfNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 2168 "y.tab.c"
break;
case 122:
#line 293 "parser.y"
	{ yyval.node = createWhileNode(yystack.l_mark[-4].node, yystack.l_mark[-1].node); }
#line 2173 "y.tab.c"
break;
case 123:
#line 296 "parser.y"
	{ yyval.node = createRepeatUntilNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 2178 "y.tab.c"
break;
case 124:
#line 299 "parser.y"
	{ yyval.node = createDoWhileNode(yystack.l_mark[-5].node, yystack.l_mark[-2].node); }
#line 2183 "y.tab.c"
break;
case 125:
#line 302 "parser.y"
	{ yyval.node = createArithOpNode(NODE_ADD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2188 "y.tab.c"
break;
case 126:
#line 303 "parser.y"
	{ yyval.node = createArithOpNode(NODE_SUB, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2193 "y.tab.c"
break;
case 127:
#line 304 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MUL, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2198 "y.tab.c"
break;
case 128:
#line 305 "parser.y"
	{ yyval.node = createArithOpNode(NODE_DIV, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2203 "y.tab.c"
break;
case 129:
#line 306 "parser.y"
	{ yyval.node = createArithOpNode(NODE_MOD, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2208 "y.tab.c"
break;
case 130:
#line 307 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2213 "y.tab.c"
break;
case 131:
#line 308 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2218 "y.tab.c"
break;
case 132:
#line 309 "parser.y"
	{ yyval.node = createVariableUsageNode(yystack.l_mark[0].node->varName); }
#line 2223 "y.tab.c"
break;
case 133:
#line 310 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2228 "y.tab.c"
break;
case 134:
#line 311 "parser.y"
	{ yyval.node = createArrayAccessNode(yystack.l_mark[-1].node, yystack.l_mark[0].node); }
#line 2233 "y.tab.c"
break;
case 135:
#line 312 "parser.y"
	{ yyval.node = createDereferenceNode(yystack.l_mark[0].node); }
#line 2238 "y.tab.c"
break;
case 136:
#line 313 "parser.y"
	{ yyval.node = createAddressToNode(yystack.l_mark[0].node); }
#line 2243 "y.tab.c"
break;
case 137:
#line 314 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2248 "y.tab.c"
break;
case 138:
#line 315 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2253 "y.tab.c"
break;
case 139:
#line 316 "parser.y"
	{ yyval.node = createNullNode(); }
#line 2258 "y.tab.c"
break;
case 140:
#line 319 "parser.y"
	{ yyval.node = createFunctionCallNode(yystack.l_mark[-2].node, NULL); }
#line 2263 "y.tab.c"
break;
case 141:
#line 320 "parser.y"
	{ yyval.node = createFunctionCallNode(yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
#line 2268 "y.tab.c"
break;
case 142:
#line 322 "parser.y"
	{ yyval.node = createConnectorNode(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2273 "y.tab.c"
break;
case 143:
#line 323 "parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
#line 2278 "y.tab.c"
break;
case 144:
#line 326 "parser.y"
	{ yyval.node = createConditionNode(NODE_LE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2283 "y.tab.c"
break;
case 145:
#line 327 "parser.y"
	{ yyval.node = createConditionNode(NODE_LT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2288 "y.tab.c"
break;
case 146:
#line 328 "parser.y"
	{ yyval.node = createConditionNode(NODE_GE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2293 "y.tab.c"
break;
case 147:
#line 329 "parser.y"
	{ yyval.node = createConditionNode(NODE_GT, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2298 "y.tab.c"
break;
case 148:
#line 330 "parser.y"
	{ yyval.node = createConditionNode(NODE_NE, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2303 "y.tab.c"
break;
case 149:
#line 331 "parser.y"
	{ yyval.node = createConditionNode(NODE_EQ, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2308 "y.tab.c"
break;
case 150:
#line 332 "parser.y"
	{ yyval.node = createConditionNode(NODE_OR, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2313 "y.tab.c"
break;
case 151:
#line 333 "parser.y"
	{ yyval.node = createConditionNode(NODE_AND, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
#line 2318 "y.tab.c"
break;
case 152:
#line 334 "parser.y"
	{ yyval.node = createConditionNode(NODE_NOT, yystack.l_mark[0].node, NULL); }
#line 2323 "y.tab.c"
break;
case 153:
#line 335 "parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
#line 2328 "y.tab.c"
break;
#line 2330 "y.tab.c"
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
