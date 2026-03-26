#ifndef _yy_defines_h_
#define _yy_defines_h_

#define KW_READ 257
#define KW_WRITE 258
#define KW_ALLOC 259
#define KW_FREE 260
#define KW_INIT 261
#define KW_NEW 262
#define PLUS 263
#define MUL 264
#define MINUS 265
#define DIV 266
#define MOD 267
#define ASSIGN 268
#define COMMA 269
#define SEMI 270
#define DOT 271
#define ARROW 272
#define AMPERSAND 273
#define GT 274
#define GE 275
#define LT 276
#define LE 277
#define NE 278
#define EQ 279
#define KW_BEGIN 280
#define KW_END 281
#define KW_IF 282
#define KW_THEN 283
#define KW_ELSE 284
#define KW_ENDIF 285
#define KW_WHILE 286
#define KW_DO 287
#define KW_ENDWHILE 288
#define KW_BREAK 289
#define KW_CONTINUE 290
#define KW_REPEAT 291
#define KW_UNTIL 292
#define KW_DECL 293
#define KW_ENDDECL 294
#define TYPE_INT 295
#define TYPE_STRING 296
#define TYPE_VOID 297
#define KW_TUPLE 298
#define AND 299
#define OR 300
#define NOT 301
#define INCREMENT 302
#define DECREMENT 303
#define ASSIGN_ADD 304
#define ASSIGN_SUB 305
#define ASSIGN_MUL 306
#define ASSIGN_DIV 307
#define ASSIGN_MOD 308
#define KW_RETURN 309
#define MAIN 310
#define KW_TYPE 311
#define KW_ENDTYPE 312
#define KW_NULL 313
#define KW_BRKP 314
#define KW_CLASS 315
#define KW_ENDCLASS 316
#define ID 317
#define NUM 318
#define STRING_LITERAL 319
#define UMINUS 320
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    struct Node *node;

    struct TypeInfo *typeInfo;
    struct TupleField *tupleField;
    struct TypeField *field;
    
    struct ClassField *classField;
    struct ClassMethod *classMethod;
    
    struct Param *param;

    struct Dimension *dimension;
    struct VarList *varList;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
