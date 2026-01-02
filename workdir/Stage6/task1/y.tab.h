/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    READ = 258,
    WRITE = 259,
    PLUS = 260,
    MUL = 261,
    MINUS = 262,
    DIV = 263,
    MOD = 264,
    ASSIGN = 265,
    SEMI = 266,
    AMPERSAND = 267,
    GT = 268,
    GE = 269,
    LT = 270,
    LE = 271,
    NE = 272,
    EQ = 273,
    KW_BEGIN = 274,
    KW_END = 275,
    KW_IF = 276,
    KW_THEN = 277,
    KW_ELSE = 278,
    KW_ENDIF = 279,
    KW_WHILE = 280,
    KW_DO = 281,
    KW_ENDWHILE = 282,
    KW_BREAK = 283,
    KW_CONTINUE = 284,
    KW_REPEAT = 285,
    KW_UNTIL = 286,
    KW_DECL = 287,
    KW_ENDDECL = 288,
    TYPE_INT = 289,
    TYPE_STRING = 290,
    TYPE_VOID = 291,
    COMMA = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    INCREMENT = 296,
    DECREMENT = 297,
    ASSIGN_ADD = 298,
    ASSIGN_SUB = 299,
    ASSIGN_MUL = 300,
    ASSIGN_DIV = 301,
    ASSIGN_MOD = 302,
    KW_RETURN = 303,
    MAIN = 304,
    KW_BRKP = 305,
    KW_TUPLE = 306,
    DOT = 307,
    ARROW = 308,
    KW_TYPE = 309,
    KW_ENDTYPE = 310,
    ID = 311,
    NUM = 312,
    STRING_LITERAL = 313
  };
#endif
/* Tokens.  */
#define READ 258
#define WRITE 259
#define PLUS 260
#define MUL 261
#define MINUS 262
#define DIV 263
#define MOD 264
#define ASSIGN 265
#define SEMI 266
#define AMPERSAND 267
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
#define KW_DECL 287
#define KW_ENDDECL 288
#define TYPE_INT 289
#define TYPE_STRING 290
#define TYPE_VOID 291
#define COMMA 292
#define AND 293
#define OR 294
#define NOT 295
#define INCREMENT 296
#define DECREMENT 297
#define ASSIGN_ADD 298
#define ASSIGN_SUB 299
#define ASSIGN_MUL 300
#define ASSIGN_DIV 301
#define ASSIGN_MOD 302
#define KW_RETURN 303
#define MAIN 304
#define KW_BRKP 305
#define KW_TUPLE 306
#define DOT 307
#define ARROW 308
#define KW_TYPE 309
#define KW_ENDTYPE 310
#define ID 311
#define NUM 312
#define STRING_LITERAL 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    struct tnode *node;
    struct FieldList *field;

#line 178 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
