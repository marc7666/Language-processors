/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CINE_TAB_H_INCLUDED
# define YY_YY_CINE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    BOOL = 259,                    /* BOOL  */
    CHAR = 260,                    /* CHAR  */
    FLOAT = 261,                   /* FLOAT  */
    ENTER = 262,                   /* ENTER  */
    REAL = 263,                    /* REAL  */
    IDEN = 264,                    /* IDEN  */
    CARACTER = 265,                /* CARACTER  */
    BOOLEAN = 266,                 /* BOOLEAN  */
    STRING = 267,                  /* STRING  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    DO = 270,                      /* DO  */
    WHILE = 271,                   /* WHILE  */
    FOR1 = 272,                    /* FOR1  */
    FOR2 = 273,                    /* FOR2  */
    FOR3 = 274,                    /* FOR3  */
    ADDTO = 275,                   /* ADDTO  */
    SUBFROM = 276,                 /* SUBFROM  */
    MULTBY = 277,                  /* MULTBY  */
    DIVBY = 278,                   /* DIVBY  */
    NOT = 279,                     /* NOT  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    IMPLICA = 282,                 /* IMPLICA  */
    IMPLICADOB = 283,              /* IMPLICADOB  */
    LT = 284,                      /* LT  */
    GT = 285,                      /* GT  */
    GTE = 286,                     /* GTE  */
    LTE = 287,                     /* LTE  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    DIV = 290,                     /* DIV  */
    MOD = 291,                     /* MOD  */
    INTDIV = 292,                  /* INTDIV  */
    POWER = 293,                   /* POWER  */
    UMENYS = 294                   /* UMENYS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "cine.y"

  void *sense_atribut;
  int valor_enter;
  float valor_real;
  char caracter;
  char *lexema;

#line 111 "cine.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CINE_TAB_H_INCLUDED  */
