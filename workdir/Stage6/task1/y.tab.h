#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    struct tnode *node;
    struct FieldList *field;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
