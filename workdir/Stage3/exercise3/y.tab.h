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
#define MOD 265
#define ASSIGN 266
#define SEMI 267
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
