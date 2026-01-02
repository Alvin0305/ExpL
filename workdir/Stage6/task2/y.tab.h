#ifndef _yy_defines_h_
#define _yy_defines_h_

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
