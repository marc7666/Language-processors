/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 12 "array_if_while_adreces.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include"symtab.h"    // Conté la definicio de les Entrades a la TS

#define MAXNOM 30

#define TBOOL 0         // Tipus del IDENTIFICADORS: de més específic a més general
#define TCHAR 1
#define TINT 2
#define TREAL 3

#define MBOOL 1         // Mida en bytes per a cada tipus
#define MCHAR 1
#define MINT 2
#define MREAL 4


#define MAX(x,y) (x)>=(y)?x:y
#define NUL (void *)0

extern int nlin;
extern int yylex();

void yyerror (char const *);

extern FILE * yyin;
extern FILE * yyout;

info_TS tid;        // variable extreure atributs de la TS

long int offset=0;    // Desplaçament respecte el punter a la pila per a les variables locals

long int t_actual=0;  // Numeracio variables temporals

char *aux_l;  // Gestio dels noms de les etiquetes amb mem. dinàmica

int mida(int);   // Obtenir offset de cada tipus

char *new_temp();  // Gestió variables temporals
char *new_label(); // Gestió etiquetes de salt
void convertir(int , char *);
void afegir_temp_TS(char *, int);

typedef struct t_info_expr{
    char *nom;       // lexema amb memòria dinàmica
    int tipus;       // 4 tipus bàsics
} info_expr;

typedef struct t_info_aux{
    int tipus;           // 3 tipus bàsics
    long int despla;
} info_aux;

typedef struct _doble_cond{
    char label_V[MAXNOM+1];
    char label_F[MAXNOM+1];
} doble_cond;

typedef struct t_info_despla_temp{
    long int despla;           // Offset de l'àmbit
    long int temp;             // Numeració variables temporals de l'àmbit
} info_despla_temp;

int out=1;


#line 140 "array_if_while_adreces.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "array_if_while_adreces.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_VINT = 4,                       /* VINT  */
  YYSYMBOL_VREAL = 5,                      /* VREAL  */
  YYSYMBOL_VCHAR = 6,                      /* VCHAR  */
  YYSYMBOL_VBOOL = 7,                      /* VBOOL  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_REAL = 9,                       /* REAL  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_INICI = 12,                     /* INICI  */
  YYSYMBOL_FINAL = 13,                     /* FINAL  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_ENDIF = 17,                     /* ENDIF  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_ENDWHILE = 20,                  /* ENDWHILE  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_MAI = 24,                       /* MAI  */
  YYSYMBOL_MEI = 25,                       /* MEI  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_IG = 28,                        /* IG  */
  YYSYMBOL_DIF = 29,                       /* DIF  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_UMENYS = 34,                    /* UMENYS  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_llistainst = 44,                /* llistainst  */
  YYSYMBOL_ambit = 45,                     /* ambit  */
  YYSYMBOL_aux_ambit = 46,                 /* aux_ambit  */
  YYSYMBOL_inst = 47,                      /* inst  */
  YYSYMBOL_decla = 48,                     /* decla  */
  YYSYMBOL_tipus = 49,                     /* tipus  */
  YYSYMBOL_llistaid = 50,                  /* llistaid  */
  YYSYMBOL_aux_iden1 = 51,                 /* aux_iden1  */
  YYSYMBOL_aux_iden2 = 52,                 /* aux_iden2  */
  YYSYMBOL_iden_decla = 53,                /* iden_decla  */
  YYSYMBOL_asig = 54,                      /* asig  */
  YYSYMBOL_aux_error = 55,                 /* aux_error  */
  YYSYMBOL_expr = 56,                      /* expr  */
  YYSYMBOL_57_1 = 57,                      /* $@1  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_inst_if = 63,                   /* inst_if  */
  YYSYMBOL_64_7 = 64,                      /* $@7  */
  YYSYMBOL_65_8 = 65,                      /* $@8  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_aux_if = 67,                    /* aux_if  */
  YYSYMBOL_else_opcional = 68,             /* else_opcional  */
  YYSYMBOL_inst_while = 69,                /* inst_while  */
  YYSYMBOL_70_10 = 70,                     /* $@10  */
  YYSYMBOL_71_11 = 71,                     /* $@11  */
  YYSYMBOL_aux_while = 72                  /* aux_while  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    32,    30,    36,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      27,    39,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    28,    29,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   140,   145,   146,   147,   150,   163,   177,
     178,   179,   180,   181,   182,   188,   192,   193,   194,   195,
     198,   199,   202,   205,   208,   222,   244,   263,   275,   293,
     307,   319,   332,   345,   357,   372,   393,   396,   398,   400,
     402,   404,   416,   415,   432,   431,   448,   447,   466,   465,
     484,   483,   502,   501,   518,   530,   545,   551,   554,   544,
     570,   576,   586,   587,   601,   603,   600,   624,   630
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "VINT", "VREAL",
  "VCHAR", "VBOOL", "INT", "REAL", "CHAR", "BOOL", "INICI", "FINAL", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "NOT", "AND", "OR",
  "MAI", "MEI", "'>'", "'<'", "IG", "DIF", "'+'", "'-'", "'*'", "'/'",
  "UMENYS", "';'", "','", "'['", "']'", "'='", "'('", "')'", "$accept",
  "programa", "llistainst", "ambit", "aux_ambit", "inst", "decla", "tipus",
  "llistaid", "aux_iden1", "aux_iden2", "iden_decla", "asig", "aux_error",
  "expr", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "inst_if", "$@7",
  "$@8", "$@9", "aux_if", "else_opcional", "inst_while", "$@10", "$@11",
  "aux_while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   -30,     8,     4,   -30,   -14,    -1,   -30,   -30,   -30,
     -30,   -30,   -30,    20,   -30,   -30,   -30,   -30,   -16,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,    20,    20,   -30,     3,
     -30,   -30,   -30,   -30,    20,    20,    20,   164,   -30,   -30,
       6,    40,   130,   164,    81,    20,   164,   -30,   110,   -30,
     -30,   -30,   -30,   -30,   -30,    20,    20,    20,    20,    20,
      20,   -30,    20,   -30,     7,   -30,   -30,   -30,   147,   -30,
      20,    20,    20,    20,    20,    20,   134,   134,    -4,    -4,
     -30,   -30,   -30,   164,    40,    48,    16,   -30,   175,   185,
     117,   117,   117,   117,   -30,   -30,   -30,    19,    20,    43,
      49,   -30,   164,   -30,   -30,    53,    95,    56,   -30,   -30,
      42,   -30,   -30,   109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     0,     0,     1,     0,     0,    17,    18,    19,
      16,     8,     3,     0,    68,     9,     6,     5,     0,    22,
      11,    12,    13,    60,    67,    14,     0,     0,     4,    34,
      37,    38,    39,    40,     0,     0,     0,    56,    64,    10,
      15,     0,     0,    26,     0,     0,    41,    33,     0,    42,
      44,    50,    52,    46,    48,     0,     0,     0,     0,     0,
       0,    61,     0,    23,    24,    20,    28,     7,     0,    36,
       0,     0,     0,     0,     0,     0,    54,    55,    29,    30,
      31,    32,     8,    65,     0,     0,     0,    35,    43,    45,
      51,    53,    47,    49,    57,     8,    21,     0,     0,     0,
       0,    25,    27,     4,     4,     0,     0,    62,    66,     8,
       0,     4,    59,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -28,   -30,   -29,   -30,   -30,   -30,   -30,   -30,
     -30,   -10,   -30,   -30,   -25,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    16,    28,    17,    18,    19,    40,    41,
      84,    65,    20,    86,    37,    70,    71,    74,    75,    72,
      73,    21,    61,    99,   107,    82,   110,    22,    62,    95,
      38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    42,    43,    23,     1,     5,    24,     6,     4,    46,
      47,    48,     7,     8,     9,    10,    11,    12,    13,    39,
      68,    25,    14,    29,    30,    31,    32,    33,    59,    60,
      76,    77,    78,    79,    80,    81,    26,    83,    27,    15,
      45,    34,    63,    64,    85,    88,    89,    90,    91,    92,
      93,    35,    97,    94,     5,    98,     6,   101,   103,   112,
      36,     7,     8,     9,    10,    11,   100,    13,   104,   -58,
     -58,    14,   109,   102,    96,   105,   106,     0,     0,     0,
     111,     0,     5,   113,     6,     0,     0,     0,    15,     7,
       8,     9,    10,    11,    67,    13,     5,     0,     6,    14,
       0,     0,     0,     7,     8,     9,    10,    11,     0,    13,
       5,     0,     6,    14,     0,   108,    15,     7,     8,     9,
      10,    11,     0,    13,     0,     0,   -63,    14,     0,     0,
      15,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    15,    55,    56,    57,    58,    59,
      60,    69,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    57,    58,    59,    60,    66,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,    87,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60
};

static const yytype_int8 yycheck[] =
{
      28,    26,    27,    17,    12,     1,    20,     3,     0,    34,
      35,    36,     8,     9,    10,    11,    12,    13,    14,    35,
      45,    35,    18,     3,     4,     5,     6,     7,    32,    33,
      55,    56,    57,    58,    59,    60,    37,    62,    39,    35,
      37,    21,    36,     3,    37,    70,    71,    72,    73,    74,
      75,    31,     4,    82,     1,    39,     3,    38,    15,    17,
      40,     8,     9,    10,    11,    12,    95,    14,    19,    16,
      17,    18,    16,    98,    84,   103,   104,    -1,    -1,    -1,
     109,    -1,     1,   111,     3,    -1,    -1,    -1,    35,     8,
       9,    10,    11,    12,    13,    14,     1,    -1,     3,    18,
      -1,    -1,    -1,     8,     9,    10,    11,    12,    -1,    14,
       1,    -1,     3,    18,    -1,    20,    35,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    17,    18,    -1,    -1,
      35,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    35,    28,    29,    30,    31,    32,
      33,    41,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    30,    31,    32,    33,    38,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    43,    44,     0,     1,     3,     8,     9,    10,
      11,    12,    13,    14,    18,    35,    45,    47,    48,    49,
      54,    63,    69,    17,    20,    35,    37,    39,    46,     3,
       4,     5,     6,     7,    21,    31,    40,    56,    72,    35,
      50,    51,    56,    56,    44,    37,    56,    56,    56,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    64,    70,    36,     3,    53,    38,    13,    56,    41,
      57,    58,    61,    62,    59,    60,    56,    56,    56,    56,
      56,    56,    67,    56,    52,    37,    55,    38,    56,    56,
      56,    56,    56,    56,    46,    71,    53,     4,    39,    65,
      46,    38,    56,    15,    19,    44,    44,    66,    20,    16,
      68,    46,    17,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    45,    46,    47,
      47,    47,    47,    47,    47,    48,    49,    49,    49,    49,
      50,    50,    51,    52,    53,    53,    54,    54,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    56,    58,    56,    59,    56,    60,    56,
      61,    56,    62,    56,    56,    56,    64,    65,    66,    63,
      63,    67,    68,    68,    70,    71,    69,    69,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     4,     0,     1,
       2,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     4,     0,     0,     1,     4,     3,     7,     0,     3,
       3,     3,     3,     2,     1,     4,     3,     1,     1,     1,
       1,     2,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     3,     3,     0,     0,     0,    11,
       2,     0,     0,     3,     0,     0,     9,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: %empty  */
#line 139 "array_if_while_adreces.y"
                { (yyval.sense_atribut)=NUL; }
#line 1295 "array_if_while_adreces.tab.c"
    break;

  case 3: /* programa: INICI llistainst FINAL  */
#line 141 "array_if_while_adreces.y"
                            {fprintf(yyout,"%d\tHalt\n",out);
                            (yyval.sense_atribut)=NUL; }
#line 1302 "array_if_while_adreces.tab.c"
    break;

  case 4: /* llistainst: %empty  */
#line 145 "array_if_while_adreces.y"
                                    { (yyval.sense_atribut)=NUL; }
#line 1308 "array_if_while_adreces.tab.c"
    break;

  case 5: /* llistainst: llistainst inst  */
#line 146 "array_if_while_adreces.y"
                                    { (yyval.sense_atribut)=NUL; }
#line 1314 "array_if_while_adreces.tab.c"
    break;

  case 6: /* llistainst: llistainst ambit  */
#line 147 "array_if_while_adreces.y"
                                    { (yyval.sense_atribut)=NUL; }
#line 1320 "array_if_while_adreces.tab.c"
    break;

  case 7: /* ambit: INICI aux_ambit llistainst FINAL  */
#line 151 "array_if_while_adreces.y"
                { if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                        fprintf(stderr,"ERROR compilador!!\n");
                        YYERROR;    // ERROR del sistema!!
                    }
                    offset = (yyvsp[-2].despla_temp).despla;
                    t_actual = (yyvsp[-2].despla_temp).temp;
                    // Restaurar el desplaçament de l'àmbit anterior
                    fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);
                    (yyval.sense_atribut)=NUL;
                }
#line 1335 "array_if_while_adreces.tab.c"
    break;

  case 8: /* aux_ambit: %empty  */
#line 163 "array_if_while_adreces.y"
                    { if (sym_push_scope()==SYMTAB_STACK_OVERFLOW){
                    //Empilar àmbit i verificar espai pila àmbits disponible
                            fprintf(stderr,"ERROR NO es pot crear nou àmbit de definició. Línea %d \n", nlin);
                            YYERROR;
                        }
                     (yyval.despla_temp).despla = offset;
                     (yyval.despla_temp).temp = t_actual;
                // Salvar el desplaçament de l'àmbit anterior (actual abans empilar)
                // Salvar la numeració generada de les variables temporals a l'àmbit actual
                fprintf(yyout,"\n// Empila àmbit. Salva offset actual %ld. Salva temporal actual %ld\n\n", offset, t_actual);
                     }
#line 1351 "array_if_while_adreces.tab.c"
    break;

  case 9: /* inst: ';'  */
#line 177 "array_if_while_adreces.y"
                            { (yyval.sense_atribut)=NUL; }
#line 1357 "array_if_while_adreces.tab.c"
    break;

  case 10: /* inst: decla ';'  */
#line 178 "array_if_while_adreces.y"
                            { (yyval.sense_atribut)=NUL; }
#line 1363 "array_if_while_adreces.tab.c"
    break;

  case 11: /* inst: asig  */
#line 179 "array_if_while_adreces.y"
                            {(yyval.sense_atribut)=NUL;}
#line 1369 "array_if_while_adreces.tab.c"
    break;

  case 12: /* inst: inst_if  */
#line 180 "array_if_while_adreces.y"
                            {(yyval.sense_atribut)=NUL;}
#line 1375 "array_if_while_adreces.tab.c"
    break;

  case 13: /* inst: inst_while  */
#line 181 "array_if_while_adreces.y"
                            {(yyval.sense_atribut)=NUL;}
#line 1381 "array_if_while_adreces.tab.c"
    break;

  case 14: /* inst: error ';'  */
#line 183 "array_if_while_adreces.y"
            {(yyval.sense_atribut)=NUL;
            fprintf(stderr,"ERROR INSTRUCCIÓ INCORRECTA: línea %d\n", nlin);
            yyerrok; }
#line 1389 "array_if_while_adreces.tab.c"
    break;

  case 15: /* decla: tipus llistaid  */
#line 188 "array_if_while_adreces.y"
                                 {(yyval.sense_atribut)=NUL;}
#line 1395 "array_if_while_adreces.tab.c"
    break;

  case 16: /* tipus: BOOL  */
#line 192 "array_if_while_adreces.y"
                 {(yyval.tipus_b) = TBOOL;}
#line 1401 "array_if_while_adreces.tab.c"
    break;

  case 17: /* tipus: INT  */
#line 193 "array_if_while_adreces.y"
                 {(yyval.tipus_b) = TINT;}
#line 1407 "array_if_while_adreces.tab.c"
    break;

  case 18: /* tipus: REAL  */
#line 194 "array_if_while_adreces.y"
                 {(yyval.tipus_b) = TREAL;}
#line 1413 "array_if_while_adreces.tab.c"
    break;

  case 19: /* tipus: CHAR  */
#line 195 "array_if_while_adreces.y"
                 {(yyval.tipus_b) = TCHAR;}
#line 1419 "array_if_while_adreces.tab.c"
    break;

  case 20: /* llistaid: aux_iden1 iden_decla  */
#line 198 "array_if_while_adreces.y"
                                                     {(yyval.tipus_b)=(yyvsp[-1].tipus_b);}
#line 1425 "array_if_while_adreces.tab.c"
    break;

  case 21: /* llistaid: llistaid ',' aux_iden2 iden_decla  */
#line 199 "array_if_while_adreces.y"
                                                 {(yyval.tipus_b)=(yyvsp[-3].tipus_b);}
#line 1431 "array_if_while_adreces.tab.c"
    break;

  case 22: /* aux_iden1: %empty  */
#line 202 "array_if_while_adreces.y"
                       { (yyval.tipus_b) = (yyvsp[0].tipus_b);}
#line 1437 "array_if_while_adreces.tab.c"
    break;

  case 23: /* aux_iden2: %empty  */
#line 205 "array_if_while_adreces.y"
                       { (yyval.tipus_b) = (yyvsp[(-1) - (0)].tipus_b);}
#line 1443 "array_if_while_adreces.tab.c"
    break;

  case 24: /* iden_decla: ID  */
#line 209 "array_if_while_adreces.y"
            {  if (sym_lookup((yyvsp[0].name), &tid)==SYMTAB_OK){
                //verificar duplicat
                fprintf(stderr,"ERROR ID %s ja definit. Línea %d \n", (yyvsp[0].name), nlin);
                YYERROR;
                }else{
                    tid.tipus=(yyvsp[-1].tipus_b);
                    tid.despla=offset;
                    offset=offset+(mida(tid.tipus)*1); // Un valor
                    tid.mida=0; // tipus basic
                    sym_add((yyvsp[0].name),&tid);
                    fprintf(yyout,"\n// Declara Identificador: %s\t Tipus: %d\t ADREÇA: %ld\n\n", (yyvsp[0].name), tid.tipus,tid.despla);
                    (yyval.sense_atribut) = NUL;}
            }
#line 1461 "array_if_while_adreces.tab.c"
    break;

  case 25: /* iden_decla: ID '[' VINT ']'  */
#line 223 "array_if_while_adreces.y"
        {  if (sym_lookup((yyvsp[-3].name), &tid)==SYMTAB_OK){
            //verificar duplicat
            fprintf(stderr,"ERROR ID %s ja definit. Línea %d \n", (yyvsp[-3].name), nlin);
            YYERROR;
            }else { int v = atoi((yyvsp[-1].name));
                    if (v <= 0){
                        fprintf(stderr,"ERROR MIDA %d ARRAY %s. Línea %d \n",v , (yyvsp[-3].name), nlin);
                        YYERROR;
                    }else{
                        tid.tipus=(yyvsp[-4].tipus_b);
                        tid.despla=offset;
                        offset=offset+(mida(tid.tipus)*v);  // VINT valors
                        tid.mida=v; // tipus array
                        sym_add((yyvsp[-3].name),&tid);
                        fprintf(yyout,"\n// Declara ARRAY: %s\t Tipus: %d\t ADREÇA: %ld\t MIDA: %d\n\n", (yyvsp[-3].name), tid.tipus,tid.despla,v);
                        (yyval.sense_atribut) = NUL;
                    }
                }
        }
#line 1485 "array_if_while_adreces.tab.c"
    break;

  case 26: /* asig: ID '=' expr  */
#line 245 "array_if_while_adreces.y"
            { if (sym_lookup((yyvsp[-2].name), &tid) != SYMTAB_OK){
                    //verificar ID definit a l'àmbit actual
                    fprintf(stderr,"ERROR ID %s NO definit. Línea %d \n", (yyvsp[-2].name), nlin);
                    YYERROR;
                }else if (tid.mida!=0){
                        // verificar variable simple
                        fprintf(stderr,"Línea %d: Error accés a array sense índex %s: \n", nlin, (yyvsp[-2].name));
                        YYERROR; }
                        else if (((yyvsp[0].vbles).tipus==TBOOL && tid.tipus!=TBOOL) || ((yyvsp[0].vbles).tipus > tid.tipus)){
                            // verificar casament de tipus entre ID i exp
                            // expressions logiques només assignables a ID de tipus bool
                                fprintf(stderr,"Línea %d: Error tipus ID %s:  tipus %d = tipus %d\n", nlin, (yyvsp[-2].name), tid.tipus, (yyvsp[0].vbles).tipus);
                                YYERROR; }
                            else{ // assignacio OK
                                fprintf(yyout,"%d\t%s  = %s \n", out, (yyvsp[-2].name),  (yyvsp[0].vbles).nom); out++;
                                (yyval.sense_atribut)=NUL;
                                }
            }
#line 1508 "array_if_while_adreces.tab.c"
    break;

  case 27: /* asig: ID '[' expr ']' aux_error '=' expr  */
#line 264 "array_if_while_adreces.y"
            { if (((yyvsp[0].vbles).tipus==TBOOL && (yyvsp[-2].info).tipus!=TBOOL) || ((yyvsp[0].vbles).tipus > (yyvsp[-2].info).tipus)){
    // verificar casament de tipus entre ID i exp
    // expressions logiques només només assignables a ID de tipus bool
                fprintf(stderr,"Línea %d: Error tipus ID %s:  tipus %d = tipus %d\n", nlin, (yyvsp[-6].name), (yyvsp[-2].info).tipus, (yyvsp[0].vbles).tipus);
                YYERROR; }
            else{
                fprintf(yyout, "%d\t%s @ %ld + %s * %d = %s \n",out, (yyvsp[-6].name),(yyvsp[-2].info).despla, (yyvsp[-4].vbles).nom,mida((yyvsp[-2].info).tipus),(yyvsp[0].vbles).nom); out++;
                (yyval.sense_atribut)=NUL; }
            }
#line 1522 "array_if_while_adreces.tab.c"
    break;

  case 28: /* aux_error: %empty  */
#line 275 "array_if_while_adreces.y"
                {  if (sym_lookup((yyvsp[(-3) - (0)].name), &tid) != SYMTAB_OK){
                    //verificar existeix ID
                       fprintf(stderr,"ERROR ID %s NO definit. Línea %d \n", (yyvsp[(-3) - (0)].name), nlin);
                       YYERROR;
                    }else if (tid.mida==0){
                        //verificar si està declarat a tipus ARRAY
                             fprintf(stderr,"ERROR ID %s NO definit com ARRAY. Línea %d \n", (yyvsp[(-3) - (0)].name), nlin);
                             YYERROR;
                          }else if ((yyvsp[(-1) - (0)].vbles).tipus > TINT){
                              // index ARRAY TIPUS enter o char (codi 8 bits)
                               fprintf(stderr,"Index tipus %d incorrecte ARRAY %s. Línea %d \n", (yyvsp[(-1) - (0)].vbles).tipus, (yyvsp[(-3) - (0)].name), nlin);
                               YYERROR;
                               }
                          (yyval.info).tipus=tid.tipus;
                          (yyval.info).despla=tid.despla;
                    }
#line 1543 "array_if_while_adreces.tab.c"
    break;

  case 29: /* expr: expr '+' expr  */
#line 294 "array_if_while_adreces.y"
            { if ((yyvsp[-2].vbles).tipus==TBOOL || (yyvsp[0].vbles).tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
            }else{
                (yyval.vbles).nom=new_temp();      // Nova variable temporal
               // Afegir temporal a la TS + gestió offset
                afegir_temp_TS((yyval.vbles).nom,MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus) );
                // tipus expressió més general
                fprintf(yyout, "%d\t%s =  %s ADD %s\n", out, (yyval.vbles).nom,(yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom); out++;
                (yyval.vbles).tipus = MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus);
                }
            }
#line 1561 "array_if_while_adreces.tab.c"
    break;

  case 30: /* expr: expr '-' expr  */
#line 308 "array_if_while_adreces.y"
            { if ((yyvsp[-2].vbles).tipus==TBOOL || (yyvsp[0].vbles).tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
                }else{  (yyval.vbles).nom=new_temp();      // Nova variable temporal
                    afegir_temp_TS((yyval.vbles).nom,MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus) );
                    // tipus expressió més general
                    fprintf(yyout, "%d\t%s =  %s DIF %s\n", out, (yyval.vbles).nom,(yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom); out++;
                    (yyval.vbles).tipus = MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus);
                }
            }
#line 1577 "array_if_while_adreces.tab.c"
    break;

  case 31: /* expr: expr '*' expr  */
#line 320 "array_if_while_adreces.y"
            { if ((yyvsp[-2].vbles).tipus==TBOOL || (yyvsp[0].vbles).tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
            }else{
                (yyval.vbles).nom=new_temp();      // Nova variable temporal
                afegir_temp_TS((yyval.vbles).nom,MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus) );
                // tipus expressió més general
                fprintf(yyout, "%d\t%s =  %s MULT %s\n",out, (yyval.vbles).nom,(yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom); out++;
                (yyval.vbles).tipus = MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus);
            }
        }
#line 1594 "array_if_while_adreces.tab.c"
    break;

  case 32: /* expr: expr '/' expr  */
#line 333 "array_if_while_adreces.y"
            { if ((yyvsp[-2].vbles).tipus==TBOOL || (yyvsp[0].vbles).tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();      // Nova variable temporal
                    afegir_temp_TS((yyval.vbles).nom,MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus) );
                    // tipus expressió més general
                    fprintf(yyout, "%s =  %s ADD %s\n",(yyval.vbles).nom,(yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom); out++;
                    (yyval.vbles).tipus = MAX((yyvsp[-2].vbles).tipus,(yyvsp[0].vbles).tipus);
                }
            }
#line 1611 "array_if_while_adreces.tab.c"
    break;

  case 33: /* expr: '-' expr  */
#line 346 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus==TBOOL){
                // No es permet operar aritmèticament els BOOL
                fprintf(stderr,"ERROR TIPUS: aritmètica amb BOOL. Línea %d \n",nlin);
                YYERROR;
                }else{  (yyval.vbles).nom=new_temp();      // Nova variable temporal
                    afegir_temp_TS((yyval.vbles).nom, (yyvsp[0].vbles).tipus );
                    // tipus expressió
                    fprintf(yyout, "%d\t%s = MINUS %s\n",out, (yyval.vbles).nom,(yyvsp[0].vbles).nom); out++;
                    (yyval.vbles).tipus = (yyvsp[0].vbles).tipus;
                    }
            }
#line 1627 "array_if_while_adreces.tab.c"
    break;

  case 34: /* expr: ID  */
#line 358 "array_if_while_adreces.y"
            { if (sym_lookup((yyvsp[0].name),&tid) != SYMTAB_OK){
                //verificar existeix entrada TS
                fprintf(stderr,"Línea %d: ERROR ID %s NO definit\n", nlin, (yyvsp[0].name));
                YYERROR;
            }else if (tid.mida!=0){
                // verificar variable simple
                fprintf(stderr,"Línea %d: Error accés a array sense índex %s: \n", nlin, (yyvsp[0].name));
                YYERROR; }
                    else { // entrada correcta
                        (yyval.vbles).nom=(yyvsp[0].name);   // Actualitzar el * lexema de l'id
                        (yyval.vbles).tipus = tid.tipus;
                        
                    }
            }
#line 1646 "array_if_while_adreces.tab.c"
    break;

  case 35: /* expr: ID '[' expr ']'  */
#line 373 "array_if_while_adreces.y"
        {  if (sym_lookup((yyvsp[-3].name), &tid) != SYMTAB_OK){
            //verificar existeix
            fprintf(stderr,"ERROR ID %s NO definit. Línea %d \n", (yyvsp[-3].name), nlin);
            YYERROR;
            }else if (tid.mida==0){
                //verificar definit tipus ARRAY
                fprintf(stderr,"ERROR ID %s NO definit com ARRAY. Línea %d \n", (yyvsp[-3].name), nlin);
                YYERROR;
            }else if ((yyvsp[-1].vbles).tipus != TINT){
                // index enter
                fprintf(stderr,"Index tipus %d incorrecte ARRAY %s. Línea %d \n", (yyvsp[-1].vbles).tipus, (yyvsp[-3].name), nlin);
                YYERROR;
                }else{ // NOVA temporal per garantir màxim 3 adreces
                    (yyval.vbles).nom=new_temp();    // Nova variable temporal
                    afegir_temp_TS((yyval.vbles).nom,tid.tipus);
                    // tipus expressió més general
                    fprintf(yyout, "%d\t%s =  *(%s @ %ld + %s * %d)\n",out, (yyval.vbles).nom,(yyvsp[-3].name),tid.despla,(yyvsp[-1].vbles).nom, mida(tid.tipus)); out++;
                    (yyval.vbles).tipus = tid.tipus;
                }
        }
#line 1671 "array_if_while_adreces.tab.c"
    break;

  case 36: /* expr: '(' expr ')'  */
#line 393 "array_if_while_adreces.y"
                    { (yyval.vbles).nom=(yyvsp[-1].vbles).nom;
                    // Actualitzar el * nom variable expressio
                    (yyval.vbles).tipus = (yyvsp[-1].vbles).tipus; }
#line 1679 "array_if_while_adreces.tab.c"
    break;

  case 37: /* expr: VINT  */
#line 396 "array_if_while_adreces.y"
                { (yyval.vbles).nom=(yyvsp[0].name);  // lexema del valor enter
                (yyval.vbles).tipus=TINT; }
#line 1686 "array_if_while_adreces.tab.c"
    break;

  case 38: /* expr: VREAL  */
#line 398 "array_if_while_adreces.y"
                { (yyval.vbles).nom=(yyvsp[0].name);    // lexema del valor real
                (yyval.vbles).tipus = TREAL;}
#line 1693 "array_if_while_adreces.tab.c"
    break;

  case 39: /* expr: VCHAR  */
#line 400 "array_if_while_adreces.y"
                {  (yyval.vbles).nom=(yyvsp[0].name);  // lexema del caràcter
                (yyval.vbles).tipus = TCHAR; }
#line 1700 "array_if_while_adreces.tab.c"
    break;

  case 40: /* expr: VBOOL  */
#line 402 "array_if_while_adreces.y"
                {  (yyval.vbles).nom=(yyvsp[0].name);  // lexema: true  / false
                (yyval.vbles).tipus = TBOOL; }
#line 1707 "array_if_while_adreces.tab.c"
    break;

  case 41: /* expr: NOT expr  */
#line 405 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus != TBOOL){
                        fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                        YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = NOT %s\n",out,(yyval.vbles).nom,(yyvsp[0].vbles).nom); out++;
                    }
            }
#line 1722 "array_if_while_adreces.tab.c"
    break;

  case 42: /* $@1: %empty  */
#line 416 "array_if_while_adreces.y"
        { if ((yyvsp[-1].vbles).tipus != TBOOL){
            fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[-1].vbles).nom, nlin);
            YYERROR;}
        }
#line 1731 "array_if_while_adreces.tab.c"
    break;

  case 43: /* expr: expr AND $@1 expr  */
#line 421 "array_if_while_adreces.y"
        { if ((yyvsp[0].vbles).tipus != TBOOL){
            fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
            YYERROR;
            }else{
                (yyval.vbles).nom=new_temp();
                (yyval.vbles).tipus = TBOOL;
                afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                fprintf(yyout, "%d\t%s = %s AND %s\n",out,(yyval.vbles).nom,(yyvsp[-3].vbles).nom,(yyvsp[0].vbles).nom);
                out++; }
        }
#line 1746 "array_if_while_adreces.tab.c"
    break;

  case 44: /* $@2: %empty  */
#line 432 "array_if_while_adreces.y"
            { if ((yyvsp[-1].vbles).tipus != TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[-1].vbles).nom, nlin);
                YYERROR;}
            }
#line 1755 "array_if_while_adreces.tab.c"
    break;

  case 45: /* expr: expr OR $@2 expr  */
#line 437 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus != TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s OR %s\n",out,(yyval.vbles).nom,(yyvsp[-3].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
            }
#line 1770 "array_if_while_adreces.tab.c"
    break;

  case 46: /* $@3: %empty  */
#line 448 "array_if_while_adreces.y"
            { if ((yyvsp[-1].vbles).tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[-1].vbles).nom, nlin);
                YYERROR;}
            }
#line 1780 "array_if_while_adreces.tab.c"
    break;

  case 47: /* expr: expr '>' $@3 expr  */
#line 454 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s GT %s\n",out,(yyval.vbles).nom,(yyvsp[-3].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
            }
#line 1796 "array_if_while_adreces.tab.c"
    break;

  case 48: /* $@4: %empty  */
#line 466 "array_if_while_adreces.y"
            { if ((yyvsp[-1].vbles).tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[-1].vbles).nom, nlin);
                YYERROR;}
            }
#line 1806 "array_if_while_adreces.tab.c"
    break;

  case 49: /* expr: expr '<' $@4 expr  */
#line 472 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s LT %s\n",out,(yyval.vbles).nom,(yyvsp[-3].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
            }
#line 1822 "array_if_while_adreces.tab.c"
    break;

  case 50: /* $@5: %empty  */
#line 484 "array_if_while_adreces.y"
            { if ((yyvsp[-1].vbles).tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[-1].vbles).nom, nlin);
                YYERROR;}
            }
#line 1832 "array_if_while_adreces.tab.c"
    break;

  case 51: /* expr: expr MAI $@5 expr  */
#line 490 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus == TBOOL){
                // No es permet operadors relacionals amb BOOL
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s GEQ %s\n",out,(yyval.vbles).nom,(yyvsp[-3].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
            }
#line 1848 "array_if_while_adreces.tab.c"
    break;

  case 52: /* $@6: %empty  */
#line 502 "array_if_while_adreces.y"
            { if ((yyvsp[-1].vbles).tipus == TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[-1].vbles).nom, nlin);
                YYERROR;}
                }
#line 1857 "array_if_while_adreces.tab.c"
    break;

  case 53: /* expr: expr MEI $@6 expr  */
#line 507 "array_if_while_adreces.y"
            { if ((yyvsp[0].vbles).tipus == TBOOL){
                fprintf(stderr,"Error tipus %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s LEQ %s\n",out,(yyval.vbles).nom,(yyvsp[-3].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
            }
#line 1872 "array_if_while_adreces.tab.c"
    break;

  case 54: /* expr: expr IG expr  */
#line 519 "array_if_while_adreces.y"
            { if ((yyvsp[-2].vbles).tipus != (yyvsp[0].vbles).tipus){
                // comparacions d'igualtat amb tipatge estricte
                fprintf(stderr,"Error tipus %s comparació amb %s. Línea %d \n", (yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s EQ %s\n",out,(yyval.vbles).nom,(yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
            }
#line 1888 "array_if_while_adreces.tab.c"
    break;

  case 55: /* expr: expr DIF expr  */
#line 531 "array_if_while_adreces.y"
            { if ((yyvsp[-2].vbles).tipus != (yyvsp[0].vbles).tipus){
                // comparacions amb tipatge estricte
                fprintf(stderr,"Error tipus %s comparació amb %s. Línea %d \n", (yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom, nlin);
                YYERROR;
                }else{
                    (yyval.vbles).nom=new_temp();
                    (yyval.vbles).tipus = TBOOL;
                    afegir_temp_TS((yyval.vbles).nom,(yyval.vbles).tipus);
                    fprintf(yyout, "%d\t%s = %s DIFF %s\n",out,(yyval.vbles).nom,(yyvsp[-2].vbles).nom,(yyvsp[0].vbles).nom);
                    out++; }
                }
#line 1904 "array_if_while_adreces.tab.c"
    break;

  case 56: /* $@7: %empty  */
#line 545 "array_if_while_adreces.y"
                { if ((yyvsp[0].vbles).tipus != TBOOL){
                    fprintf(stderr,"Error tipus condició IF %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                    YYERROR;}
                }
#line 1913 "array_if_while_adreces.tab.c"
    break;

  case 57: /* $@8: %empty  */
#line 551 "array_if_while_adreces.y"
                { fprintf(yyout,"%d\tif false %s goto %s\n",out,(yyvsp[-3].vbles).nom,(yyvsp[-1].bloc_cond).label_F);
                out++; }
#line 1920 "array_if_while_adreces.tab.c"
    break;

  case 58: /* $@9: %empty  */
#line 554 "array_if_while_adreces.y"
                { fprintf(yyout, "%d\tgoto %s\n",out,(yyvsp[-4].bloc_cond).label_V); out++;
                fprintf(yyout, "%d Label %s:\n",out,(yyvsp[-4].bloc_cond).label_F); out++;
                offset = (yyvsp[-3].despla_temp).despla;
                t_actual = (yyvsp[-3].despla_temp).temp;
                // Restaurar el desplaçament de l'àmbit actual (abans d'empilar)
                // Desempilar ambit IF
                if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                    fprintf(stderr,"ERROR compilador!!\n");
                    YYERROR;    // ERROR del sistema!!
                }
                else{fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);}
                }
#line 1937 "array_if_while_adreces.tab.c"
    break;

  case 59: /* inst_if: IF expr $@7 aux_if aux_ambit $@8 THEN llistainst $@9 else_opcional ENDIF  */
#line 568 "array_if_while_adreces.y"
                { fprintf(yyout, "%d Label %s:\n",out,(yyvsp[-7].bloc_cond).label_V); out++;
                (yyval.sense_atribut)=NUL; }
#line 1944 "array_if_while_adreces.tab.c"
    break;

  case 60: /* inst_if: error ENDIF  */
#line 571 "array_if_while_adreces.y"
                    {  (yyval.sense_atribut)=NUL;
                    fprintf(stderr,"ERROR IF/ELSE INCORRECTE: línea %d\n", nlin);
                    yyerrok; }
#line 1952 "array_if_while_adreces.tab.c"
    break;

  case 61: /* aux_if: %empty  */
#line 576 "array_if_while_adreces.y"
                   {    // constructor auxiliar per les etiquetes IF
                    aux_l = new_label();
                    strcpy((yyval.bloc_cond).label_V, aux_l);
                    free(aux_l);
                    aux_l = new_label();
                    strcpy((yyval.bloc_cond).label_F, aux_l);
                    free(aux_l);
                    }
#line 1965 "array_if_while_adreces.tab.c"
    break;

  case 62: /* else_opcional: %empty  */
#line 586 "array_if_while_adreces.y"
                       { (yyval.sense_atribut)=NUL; }
#line 1971 "array_if_while_adreces.tab.c"
    break;

  case 63: /* else_opcional: ELSE aux_ambit llistainst  */
#line 588 "array_if_while_adreces.y"
                        { offset = (yyvsp[-1].despla_temp).despla;
                        t_actual = (yyvsp[-1].despla_temp).temp;
                        // Restaurar el desplaçament de l'àmbit actual (abans d'empilar l'àmbit del ELSE)
                        (yyval.sense_atribut)=NUL;
                        // Desempilar ambit ELSE
                        if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                            fprintf(stderr,"ERROR compilador!!\n");
                            YYERROR;    // ERROR del sistema!!
                            }else{fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);}
                        }
#line 1986 "array_if_while_adreces.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 601 "array_if_while_adreces.y"
                    { fprintf(yyout, "%d Label %s:\n",out,(yyvsp[0].bloc_cond).label_V); out++; }
#line 1992 "array_if_while_adreces.tab.c"
    break;

  case 65: /* $@11: %empty  */
#line 603 "array_if_while_adreces.y"
                    { if ((yyvsp[0].vbles).tipus != TBOOL){
                        fprintf(stderr,"Error tipus condició WHILE %s. Línea %d \n", (yyvsp[0].vbles).nom, nlin);
                        YYERROR;
                        }else{
                            fprintf(yyout,"%d\tif false %s goto %s\n",out,(yyvsp[0].vbles).nom,(yyvsp[-2].bloc_cond).label_F);
                            out++; }
                    }
#line 2004 "array_if_while_adreces.tab.c"
    break;

  case 66: /* inst_while: WHILE aux_while $@10 expr $@11 aux_ambit DO llistainst ENDWHILE  */
#line 612 "array_if_while_adreces.y"
                    { fprintf(yyout, "%d\tgoto %s\n",out,(yyvsp[-7].bloc_cond).label_V); out++;
                    fprintf(yyout, "%d Label %s:\n",out,(yyvsp[-7].bloc_cond).label_F); out++;
                    offset = (yyvsp[-3].despla_temp).despla;
                    t_actual = (yyvsp[-3].despla_temp).temp;
                    // Restaurar el desplaçament de l'àmbit actual (abans d'empilar l'àmbit del WHILE)
                    (yyval.sense_atribut)=NUL;
                    // Desempilar ambit IF
                    if (sym_pop_scope()==SYMTAB_STACK_UNDERFLOW){
                        fprintf(stderr,"ERROR compilador!!\n");
                        YYERROR;    // ERROR del sistema!!
                        }else{fprintf(yyout,"\n// Desempila àmbit. Restaura offset a %ld. Restaura temporal actual %ld\n\n", offset, t_actual);}
                    }
#line 2021 "array_if_while_adreces.tab.c"
    break;

  case 67: /* inst_while: error ENDWHILE  */
#line 625 "array_if_while_adreces.y"
                    { (yyval.sense_atribut)=NUL;
                    fprintf(stderr,"ERROR WHILE/DO INCORRECTE: línea %d\n", nlin);
                    yyerrok; }
#line 2029 "array_if_while_adreces.tab.c"
    break;

  case 68: /* aux_while: %empty  */
#line 630 "array_if_while_adreces.y"
                   { // constructor auxiliar etiquetes WHILE
                    aux_l = new_label();
                    strcpy((yyval.bloc_cond).label_V, aux_l);
                    free(aux_l);
                    aux_l = new_label();
                    strcpy((yyval.bloc_cond).label_F, aux_l);
                    free(aux_l);
                    }
#line 2042 "array_if_while_adreces.tab.c"
    break;


#line 2046 "array_if_while_adreces.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 640 "array_if_while_adreces.y"


    // Called by yyparse on error

void yyerror (char const *s){
    fprintf (stderr, "%s\n", s);
}


int main(int argc, char *argv[]){
    if (argc>=2){
        yyin = fopen( argv[1], "r" );
    }
    if (argc==3){
        yyout = fopen( argv[2], "w" );
    }
    if (argc > 3){
        fprintf(stderr, "Error paràmetres línia comanda");
        return 1;
    }
    return(yyparse());
    
}

int mida(int t){
    int m;
    switch (t){
        case TCHAR: m= MCHAR; break;
        case TINT: m= MINT; break;
        case TREAL: m= MREAL; break;
    }
    return m;
}

char *new_temp() {
    char *etiq;
    
    t_actual++;
    etiq = (char *)malloc(MAXNOM+1);
    strcpy(etiq,"temp");
    convertir(t_actual, etiq+4);
    return etiq;
}

char *new_label(){
    char *temp;
    static int actual=0;
    
    actual++;
    temp = (char *)malloc(MAXNOM+1);
    strcpy(temp,"etiq");
    convertir(actual, temp+4);
    return temp;
}

void convertir(int valor, char *etiq){
    int c,r;
    char aux[MAXNOM+1];
    int i=0;
    
    c=valor;
    
    while (c>=10){
        r= c%10;
        c= c/10;
        aux[i]= r+'0';
        i++;
    }
    aux[i]= c+'0';
    
    while (i>=0){
        *etiq=aux[i];
        i--;
        etiq++;
    }
    *etiq='\0';
    
}

void afegir_temp_TS(char *temp_nom, int temp_tipus){
    info_TS info_temp;
    // variable local crear atributs de la variable temporal a la TS
    
    info_temp.tipus=temp_tipus;
    info_temp.despla=offset;
    offset=offset+mida(temp_tipus); // Un valor
    info_temp.mida=0; // tipus basic
    sym_add(temp_nom,&info_temp);
}
