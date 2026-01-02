#ifndef _yy_defines_h_
#define _yy_defines_h_

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
