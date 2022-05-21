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

#ifndef YY_YY_ARRAY_IF_WHILE_ADRECES_TAB_H_INCLUDED
# define YY_YY_ARRAY_IF_WHILE_ADRECES_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    VINT = 259,                    /* VINT  */
    VREAL = 260,                   /* VREAL  */
    VCHAR = 261,                   /* VCHAR  */
    VBOOL = 262,                   /* VBOOL  */
    INT = 263,                     /* INT  */
    REAL = 264,                    /* REAL  */
    CHAR = 265,                    /* CHAR  */
    BOOL = 266,                    /* BOOL  */
    INICI = 267,                   /* INICI  */
    FINAL = 268,                   /* FINAL  */
    IF = 269,                      /* IF  */
    THEN = 270,                    /* THEN  */
    ELSE = 271,                    /* ELSE  */
    ENDIF = 272,                   /* ENDIF  */
    WHILE = 273,                   /* WHILE  */
    DO = 274,                      /* DO  */
    ENDWHILE = 275,                /* ENDWHILE  */
    NOT = 276,                     /* NOT  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    MAI = 279,                     /* MAI  */
    MEI = 280,                     /* MEI  */
    IG = 281,                      /* IG  */
    DIF = 282,                     /* DIF  */
    UMENYS = 283                   /* UMENYS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "array_if_while_adreces.y"

    char *name;       // lexema amb memòria dinàmica
    int tipus_b;           // 4 tipus bàsics
    info_expr vbles;    // gestio variables temporals expressions (TOTS els tipus)!!
    info_aux info;      // informacio gestio errors accés array
    info_despla_temp despla_temp;    // Desplaçament per a cada àmbit
    doble_cond bloc_cond;   // Adreces de salt if/else i while
    void *sense_atribut;    // constructors sense atribut
    

#line 103 "array_if_while_adreces.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ARRAY_IF_WHILE_ADRECES_TAB_H_INCLUDED  */
