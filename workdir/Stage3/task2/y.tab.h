#ifndef _yy_defines_h_
#define _yy_defines_h_

#define ID 257
#define NUM 258
#define READ 259
#define WRITE 260
#define PLUS 261
#define MUL 262
#define MINUS 263
#define DIV 264
#define ASSIGN 265
#define SEMI 266
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
