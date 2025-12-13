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
