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
    NUM = 258,
    ID = 259,
    STRING_LITERAL = 260,
    READ = 261,
    WRITE = 262,
    PLUS = 263,
    MUL = 264,
    MINUS = 265,
    DIV = 266,
    MOD = 267,
    ASSIGN = 268,
    SEMI = 269,
    AMPERSAND = 270,
    GT = 271,
    GE = 272,
    LT = 273,
    LE = 274,
    NE = 275,
    EQ = 276,
    KW_BEGIN = 277,
    KW_END = 278,
    KW_IF = 279,
    KW_THEN = 280,
    KW_ELSE = 281,
    KW_ENDIF = 282,
    KW_WHILE = 283,
    KW_DO = 284,
    KW_ENDWHILE = 285,
    KW_BREAK = 286,
    KW_CONTINUE = 287,
    KW_REPEAT = 288,
    KW_UNTIL = 289,
    KW_DECL = 290,
    KW_ENDDECL = 291,
    TYPE_INT = 292,
    TYPE_STRING = 293,
    COMMA = 294,
    AND = 295,
    OR = 296,
    NOT = 297,
    INCREMENT = 298,
    DECREMENT = 299,
    ASSIGN_ADD = 300,
    ASSIGN_SUB = 301,
    ASSIGN_MUL = 302,
    ASSIGN_DIV = 303,
    ASSIGN_MOD = 304,
    KW_RETURN = 305,
    MAIN = 306,
    KW_BRKP = 307,
    KW_TUPLE = 308,
    DOT = 309,
    ARROW = 310
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define STRING_LITERAL 260
#define READ 261
#define WRITE 262
#define PLUS 263
#define MUL 264
#define MINUS 265
#define DIV 266
#define MOD 267
#define ASSIGN 268
#define SEMI 269
#define AMPERSAND 270
#define GT 271
#define GE 272
#define LT 273
#define LE 274
#define NE 275
#define EQ 276
#define KW_BEGIN 277
#define KW_END 278
#define KW_IF 279
#define KW_THEN 280
#define KW_ELSE 281
#define KW_ENDIF 282
#define KW_WHILE 283
#define KW_DO 284
#define KW_ENDWHILE 285
#define KW_BREAK 286
#define KW_CONTINUE 287
#define KW_REPEAT 288
#define KW_UNTIL 289
#define KW_DECL 290
#define KW_ENDDECL 291
#define TYPE_INT 292
#define TYPE_STRING 293
#define COMMA 294
#define AND 295
#define OR 296
#define NOT 297
#define INCREMENT 298
#define DECREMENT 299
#define ASSIGN_ADD 300
#define ASSIGN_SUB 301
#define ASSIGN_MUL 302
#define ASSIGN_DIV 303
#define ASSIGN_MOD 304
#define KW_RETURN 305
#define MAIN 306
#define KW_BRKP 307
#define KW_TUPLE 308
#define DOT 309
#define ARROW 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    struct tnode *node;

#line 171 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
