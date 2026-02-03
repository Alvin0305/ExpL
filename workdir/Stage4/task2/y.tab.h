#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#define GT 269
#define GE 270
#define LT 271
#define LE 272
#define NE 273
#define EQ 274
#define KW_BEGIN 275
#define KW_END 276
#define KW_IF 277
#define KW_THEN 278
#define KW_ELSE 279
#define KW_ENDIF 280
#define KW_WHILE 281
#define KW_DO 282
#define KW_ENDWHILE 283
#define KW_BREAK 284
#define KW_CONTINUE 285
#define KW_REPEAT 286
#define KW_UNTIL 287
#define KW_DECL 288
#define KW_ENDDECL 289
#define TYPE_INT 290
#define TYPE_STRING 291
#define COMMA 292
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
