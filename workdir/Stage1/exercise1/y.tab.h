#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NUM 257
#define END 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    struct tnode *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
