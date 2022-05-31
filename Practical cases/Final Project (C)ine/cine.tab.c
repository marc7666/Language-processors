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
#line 1 "cine.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "symtab.h"

  #define NOVAL -1

  #define TINT 0
  #define TREAL 1
  #define TCHAR 2
  #define TBOOL 3
  #define TSTRING 4

  extern int yylex();
  void yyerror (char const *);

  extern FILE * yyin;
  extern FILE * yyout;

#line 91 "cine.tab.c"

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

#include "cine.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_ENTER = 7,                      /* ENTER  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_IDEN = 9,                       /* IDEN  */
  YYSYMBOL_CARACTER = 10,                  /* CARACTER  */
  YYSYMBOL_BOOLEAN = 11,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_CADENA = 13,                    /* CADENA  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_FOR1 = 18,                      /* FOR1  */
  YYSYMBOL_FOR2 = 19,                      /* FOR2  */
  YYSYMBOL_FOR3 = 20,                      /* FOR3  */
  YYSYMBOL_ADDTO = 21,                     /* ADDTO  */
  YYSYMBOL_SUBFROM = 22,                   /* SUBFROM  */
  YYSYMBOL_MULTBY = 23,                    /* MULTBY  */
  YYSYMBOL_DIVBY = 24,                     /* DIVBY  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_IMPLICA = 28,                   /* IMPLICA  */
  YYSYMBOL_IMPLICADOB = 29,                /* IMPLICADOB  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_GTE = 32,                       /* GTE  */
  YYSYMBOL_LTE = 33,                       /* LTE  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NE = 35,                        /* NE  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_MOD = 40,                       /* MOD  */
  YYSYMBOL_INTDIV = 41,                    /* INTDIV  */
  YYSYMBOL_POWER = 42,                     /* POWER  */
  YYSYMBOL_UMENYS = 43,                    /* UMENYS  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_programa = 52,                  /* programa  */
  YYSYMBOL_llista_inst = 53,               /* llista_inst  */
  YYSYMBOL_instruccio = 54,                /* instruccio  */
  YYSYMBOL_instruccio_for = 55,            /* instruccio_for  */
  YYSYMBOL_instruccio_do = 56,             /* instruccio_do  */
  YYSYMBOL_instruccio_while = 57,          /* instruccio_while  */
  YYSYMBOL_crida_a_funcio = 58,            /* crida_a_funcio  */
  YYSYMBOL_parametres = 59,                /* parametres  */
  YYSYMBOL_operacio = 60,                  /* operacio  */
  YYSYMBOL_operador_assignador = 61,       /* operador_assignador  */
  YYSYMBOL_instruccio_if = 62,             /* instruccio_if  */
  YYSYMBOL_final_if = 63,                  /* final_if  */
  YYSYMBOL_assignacio = 64,                /* assignacio  */
  YYSYMBOL_assignacio_dec = 65,            /* assignacio_dec  */
  YYSYMBOL_declaracio = 66,                /* declaracio  */
  YYSYMBOL_declaracio_variable = 67,       /* declaracio_variable  */
  YYSYMBOL_declaracio_amb_IDEN = 68,       /* declaracio_amb_IDEN  */
  YYSYMBOL_expr = 69,                      /* expr  */
  YYSYMBOL_condicio = 70,                  /* condicio  */
  YYSYMBOL_comparacio = 71,                /* comparacio  */
  YYSYMBOL_tipus = 72                      /* tipus  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      45,    46,    38,    36,    49,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    65,    67,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    83,    85,    87,    89,    90,
      92,    93,    95,   140,   141,   142,   143,   145,   147,   148,
     149,   151,   155,   159,   169,   170,   186,   187,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   208,   209,   210,   211,   212,   213,
     214,   215,   217,   218,   219,   220,   221,   222,   224,   225,
     226,   227,   228
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "BOOL", "CHAR",
  "FLOAT", "ENTER", "REAL", "IDEN", "CARACTER", "BOOLEAN", "STRING",
  "CADENA", "IF", "ELSE", "DO", "WHILE", "FOR1", "FOR2", "FOR3", "ADDTO",
  "SUBFROM", "MULTBY", "DIVBY", "NOT", "AND", "OR", "IMPLICA",
  "IMPLICADOB", "LT", "GT", "GTE", "LTE", "EQ", "NE", "'+'", "'-'", "'*'",
  "DIV", "MOD", "INTDIV", "POWER", "UMENYS", "';'", "'('", "')'", "'{'",
  "'}'", "','", "'='", "$accept", "programa", "llista_inst", "instruccio",
  "instruccio_for", "instruccio_do", "instruccio_while", "crida_a_funcio",
  "parametres", "operacio", "operador_assignador", "instruccio_if",
  "final_if", "assignacio", "assignacio_dec", "declaracio",
  "declaracio_variable", "declaracio_amb_IDEN", "expr", "condicio",
  "comparacio", "tipus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     304,   -42,   -50,   -50,   -50,   -50,   143,   -50,   -36,   -24,
     -30,   -19,    28,   323,   -50,   -50,   -50,   -50,   -12,   -10,
     -50,    -7,    -3,    27,   -50,   -50,   -50,   -50,   -50,    95,
     150,   150,   247,   341,   247,   341,   -50,   -50,   -50,   -50,
     -50,   -50,    -4,   -50,    -2,   -50,   -50,   -50,     4,   -50,
     -50,   -50,   150,   150,   -50,   -50,     6,   342,   380,   380,
     122,   247,   247,   362,   -22,    13,   239,   217,   150,    27,
     -50,   369,   -50,   150,   150,   150,   150,   150,   150,   150,
     150,   359,   330,   248,   -50,   -50,   -50,   -50,   -50,   -50,
     150,   247,   247,   247,   247,     3,    37,    11,    40,   380,
     -50,   -50,    34,    34,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   380,    -8,    -8,   -50,   -50,   341,    15,   341,    17,
      39,   247,    76,   341,    48,   -50,   260,   -50,   235,   -37,
      45,    58,   247,   341,   -50,    38,   269,   180,   247,    49,
     -50,   273,   341,    50,    39,   341,   -50,   198,   -50
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    68,    69,    70,    71,     0,    72,     0,     0,
       0,     0,     0,     0,     4,    12,    11,    10,     0,     0,
       9,     0,     0,     0,    14,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     1,     5,    13,     8,
       7,     6,    37,    36,    33,    34,    50,    51,    38,    52,
      53,    49,     0,     0,    19,    48,     0,    20,    31,    22,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,    64,    66,    67,    65,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      35,    39,    40,    41,    43,    42,    44,    45,    46,    21,
      54,    60,    56,    57,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    27,     0,    17,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,    29,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -32,    -1,   -50,   -50,   -50,     0,    19,   -50,
     -50,   -50,   -49,   -50,   -50,   -50,   -50,    31,   100,   -23,
     -50,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    17,    55,    56,    19,
      31,    20,   125,    21,    43,    22,    44,    45,    63,    64,
      90,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    65,    24,    67,    91,    92,    93,    94,   132,    32,
     133,    66,    37,    18,     1,    34,     2,     3,     4,     5,
      93,    94,     6,    33,    95,     7,    35,     8,    36,     9,
      10,    11,    38,    18,    39,    18,    42,    40,    81,    83,
       1,    41,     2,     3,     4,     5,    68,    69,     6,    29,
     116,     7,    72,     8,   117,     9,    10,    11,   118,   119,
     121,    96,   123,   129,    37,    18,    37,    18,   112,   113,
     114,   115,    75,    76,    77,    78,    79,     1,   135,     2,
       3,     4,     5,   138,   120,     6,   122,   124,     7,   134,
       8,   128,     9,    10,    11,   146,   142,   145,   126,   109,
     100,   137,    46,    47,    48,    49,    50,     0,    51,   136,
     144,     0,     0,   147,     0,   141,    18,     0,    18,    37,
      18,    37,    18,    18,   127,     0,     0,    37,    18,    57,
      58,    59,    52,    18,     0,     0,    37,    18,     0,     0,
      53,    54,    18,    37,    18,    18,    37,    18,   -61,   -61,
     -61,   -61,    70,    71,     0,     0,     0,    46,    47,    48,
      49,    50,    82,    51,    25,    26,    27,    28,    99,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
      57,     1,     0,     2,     3,     4,     5,    52,    29,     6,
     111,     0,     7,    30,     8,    53,     9,    10,    11,     1,
       0,     2,     3,     4,     5,     0,     0,     6,     0,     0,
       7,     0,     8,     0,     9,    10,    11,     0,     1,     0,
       2,     3,     4,     5,     0,     0,     6,     0,   140,     7,
       0,     8,     0,     9,    10,    11,     1,     0,     2,     3,
       4,     5,     0,     0,     6,     0,   148,     7,     0,     8,
       0,     9,    10,    11,    46,    47,    48,    49,    60,     0,
      51,     0,     0,    98,     0,    91,    92,    93,    94,     0,
       0,     0,    61,     0,    91,    92,    93,    94,     0,     0,
       0,   131,     0,     0,    52,    97,    91,    92,    93,    94,
       0,     0,    62,     0,   110,    91,    92,    93,    94,    91,
      92,    93,    94,     0,    -2,     1,   130,     2,     3,     4,
       5,     0,     0,     6,     0,   139,     7,     0,     8,   143,
       9,    10,    11,    -3,     1,     0,     2,     3,     4,     5,
       0,     0,     6,     0,     0,     7,     0,     8,     0,     9,
      10,    11,     1,     0,     2,     3,     4,     5,     0,     0,
       6,     0,     0,     7,     0,     8,     0,     9,    10,    11,
      84,    85,    86,    87,    88,    89,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,   101,     0,    73,    74,
      75,    76,    77,    78,    79,    91,    92,    93,    94,     0,
       0,    80,    84,    85,    86,    87,    88,    89,    73,    74,
      75,    76,    77,    78,    79,    73,    74,    75,    76,    77,
      78,    79,     0,     0,     0,   101,    73,    74,    75,    76,
      77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       0,    33,    44,    35,    26,    27,    28,    29,    45,    45,
      47,    34,    13,    13,     1,    45,     3,     4,     5,     6,
      28,    29,     9,    47,    46,    12,    45,    14,     0,    16,
      17,    18,    44,    33,    44,    35,     9,    44,    61,    62,
       1,    44,     3,     4,     5,     6,    50,    49,     9,    45,
      47,    12,    46,    14,    17,    16,    17,    18,    47,    19,
      45,    48,    45,    15,    65,    65,    67,    67,    91,    92,
      93,    94,    38,    39,    40,    41,    42,     1,    20,     3,
       4,     5,     6,    45,   116,     9,   118,    48,    12,    44,
      14,   123,    16,    17,    18,   144,    47,    47,   121,    80,
      69,   133,     7,     8,     9,    10,    11,    -1,    13,   132,
     142,    -1,    -1,   145,    -1,   138,   116,    -1,   118,   120,
     120,   122,   122,   123,    48,    -1,    -1,   128,   128,    29,
      30,    31,    37,   133,    -1,    -1,   137,   137,    -1,    -1,
      45,    46,   142,   144,   144,   145,   147,   147,    26,    27,
      28,    29,    52,    53,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    62,    13,    21,    22,    23,    24,    68,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,     1,    -1,     3,     4,     5,     6,    37,    45,     9,
      90,    -1,    12,    50,    14,    45,    16,    17,    18,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    -1,    14,    -1,    16,    17,    18,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    48,    12,
      -1,    14,    -1,    16,    17,    18,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    48,    12,    -1,    14,
      -1,    16,    17,    18,     7,     8,     9,    10,    11,    -1,
      13,    -1,    -1,    46,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    25,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    46,    -1,    -1,    37,    46,    26,    27,    28,    29,
      -1,    -1,    45,    -1,    46,    26,    27,    28,    29,    26,
      27,    28,    29,    -1,     0,     1,    46,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    46,    12,    -1,    14,    46,
      16,    17,    18,     0,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    -1,    14,    -1,    16,
      17,    18,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    -1,    14,    -1,    16,    17,    18,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    -1,    36,    37,
      38,    39,    40,    41,    42,    26,    27,    28,    29,    -1,
      -1,    49,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    46,    36,    37,    38,    39,
      40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     9,    12,    14,    16,
      17,    18,    52,    53,    54,    55,    56,    57,    58,    60,
      62,    64,    66,    72,    44,    21,    22,    23,    24,    45,
      50,    61,    45,    47,    45,    45,     0,    54,    44,    44,
      44,    44,     9,    65,    67,    68,     7,     8,     9,    10,
      11,    13,    37,    45,    46,    58,    59,    69,    69,    69,
      11,    25,    45,    69,    70,    53,    70,    53,    50,    49,
      69,    69,    46,    36,    37,    38,    39,    40,    41,    42,
      49,    70,    69,    70,    30,    31,    32,    33,    34,    35,
      71,    26,    27,    28,    29,    46,    48,    46,    46,    69,
      68,    46,    69,    69,    69,    69,    69,    69,    69,    59,
      46,    69,    70,    70,    70,    70,    47,    17,    47,    19,
      53,    45,    53,    45,    48,    63,    70,    48,    53,    15,
      46,    46,    45,    47,    44,    20,    70,    53,    45,    46,
      48,    70,    47,    46,    53,    47,    63,    53,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    56,    57,    58,    58,
      59,    59,    60,    61,    61,    61,    61,    62,    63,    63,
      63,    64,    65,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     2,    15,     9,     7,     4,     3,
       1,     3,     3,     1,     1,     1,     1,     7,     1,     8,
       5,     3,     3,     2,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 64 "cine.y"
            {;}
#line 1301 "cine.tab.c"
    break;

  case 3: /* programa: llista_inst  */
#line 65 "cine.y"
                        {;}
#line 1307 "cine.tab.c"
    break;

  case 4: /* llista_inst: instruccio  */
#line 67 "cine.y"
                         {;}
#line 1313 "cine.tab.c"
    break;

  case 5: /* llista_inst: llista_inst instruccio  */
#line 68 "cine.y"
                                      {;}
#line 1319 "cine.tab.c"
    break;

  case 6: /* instruccio: declaracio ';'  */
#line 70 "cine.y"
                           {printf("(DECLARACIÓ EXITOSA)");}
#line 1325 "cine.tab.c"
    break;

  case 7: /* instruccio: assignacio ';'  */
#line 71 "cine.y"
                           {printf("(ASSIGNACIÓ EXITOSA)");}
#line 1331 "cine.tab.c"
    break;

  case 8: /* instruccio: operacio ';'  */
#line 72 "cine.y"
                          {printf("(OPERACIÓ EXITOSA)");}
#line 1337 "cine.tab.c"
    break;

  case 9: /* instruccio: instruccio_if  */
#line 73 "cine.y"
                          {printf("(IF EXITÓS)");}
#line 1343 "cine.tab.c"
    break;

  case 10: /* instruccio: instruccio_while  */
#line 74 "cine.y"
                             {printf("(WHILE EXITÓS)");}
#line 1349 "cine.tab.c"
    break;

  case 11: /* instruccio: instruccio_do  */
#line 75 "cine.y"
                          {printf("(DO WHILE EXITÓS)");}
#line 1355 "cine.tab.c"
    break;

  case 12: /* instruccio: instruccio_for  */
#line 76 "cine.y"
                           {printf("(FOR EXITÓS)");}
#line 1361 "cine.tab.c"
    break;

  case 13: /* instruccio: crida_a_funcio ';'  */
#line 77 "cine.y"
                               {printf("(CRIDA A FUNCIÓ EXITOSA)");}
#line 1367 "cine.tab.c"
    break;

  case 14: /* instruccio: error ';'  */
#line 78 "cine.y"
                      {
                        printf("(TORNANT A NORMALITAT DESPRÉS D'ERROR)");
                        yyerrok;
                      }
#line 1376 "cine.tab.c"
    break;

  case 15: /* instruccio_for: FOR1 '(' llista_inst ')' FOR2 '(' llista_inst ')' FOR3 '(' condicio ')' '{' llista_inst '}'  */
#line 83 "cine.y"
                                                                                                            {;}
#line 1382 "cine.tab.c"
    break;

  case 16: /* instruccio_do: DO '{' llista_inst '}' WHILE '(' condicio ')' ';'  */
#line 85 "cine.y"
                                                                 {;}
#line 1388 "cine.tab.c"
    break;

  case 17: /* instruccio_while: WHILE '(' condicio ')' '{' llista_inst '}'  */
#line 87 "cine.y"
                                                             {;}
#line 1394 "cine.tab.c"
    break;

  case 18: /* crida_a_funcio: IDEN '(' parametres ')'  */
#line 89 "cine.y"
                                        {;}
#line 1400 "cine.tab.c"
    break;

  case 19: /* crida_a_funcio: IDEN '(' ')'  */
#line 90 "cine.y"
                             {;}
#line 1406 "cine.tab.c"
    break;

  case 20: /* parametres: expr  */
#line 92 "cine.y"
                 {;}
#line 1412 "cine.tab.c"
    break;

  case 21: /* parametres: expr ',' parametres  */
#line 93 "cine.y"
                                {;}
#line 1418 "cine.tab.c"
    break;

  case 22: /* operacio: IDEN operador_assignador expr  */
#line 95 "cine.y"
                                        {
                                          if((yyvsp[-2].variable).tipus == TBOOL){
                                            fprintf(stderr, "ERROR: Tipus incorrecte a l'esquerra\n");
                                            YYERROR;
                                          }
                                          if((yyvsp[0].valor_enter) == TBOOL){
                                            fprintf(stderr, "ERROR: Tipus incorrecte a la dreta\n");
                                            YYERROR;
                                          }else{
                                            if((yyvsp[-2].variable).tipus == TINT || (yyvsp[-2].variable).tipus == TREAL){
                                              if((yyvsp[0].valor_enter) == TSTRING || (yyvsp[0].valor_enter) == TCHAR){
                                                fprintf(stderr, "ERROR: Tipus incorrecte a la dreta\n");
                                                YYERROR;
                                              }else{
                                                if ((yyvsp[-2].variable).tipus == TREAL || (yyvsp[0].valor_enter) == TREAL){
                                                  (yyval.valor_enter)=TREAL;
                                                }else{
                                                  (yyval.valor_enter)=TINT;
                                                }
                                              }
                                            }else{
                                              if((yyvsp[-1].valor_enter) == NOVAL){
                                                fprintf(stderr, "ERROR: Operador no vàlid\n");
                                                YYERROR;
                                              }else{
                                                if ((yyvsp[-1].valor_enter) == TINT){
                                                  if((yyvsp[0].valor_enter) == TINT || (yyvsp[0].valor_enter) == TREAL){
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta\n");
                                                    YYERROR;
                                                  }else{
                                                    (yyval.valor_enter)=TSTRING;
                                                  }
                                                }else{
                                                  if((yyvsp[0].valor_enter) == TINT || (yyvsp[0].valor_enter) == TREAL){
                                                    (yyval.valor_enter)=TSTRING;
                                                  }else{
                                                    fprintf(stderr, "ERROR: Tipus incorrecte a la dreta\n");
                                                    YYERROR;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
#line 1467 "cine.tab.c"
    break;

  case 23: /* operador_assignador: ADDTO  */
#line 140 "cine.y"
                            {(yyval.valor_enter)=TINT;}
#line 1473 "cine.tab.c"
    break;

  case 24: /* operador_assignador: SUBFROM  */
#line 141 "cine.y"
                              {(yyval.valor_enter)=NOVAL;}
#line 1479 "cine.tab.c"
    break;

  case 25: /* operador_assignador: MULTBY  */
#line 142 "cine.y"
                             {(yyval.valor_enter)=TREAL;}
#line 1485 "cine.tab.c"
    break;

  case 26: /* operador_assignador: DIVBY  */
#line 143 "cine.y"
                            {(yyval.valor_enter)=NOVAL;}
#line 1491 "cine.tab.c"
    break;

  case 27: /* instruccio_if: IF '(' condicio ')' '{' llista_inst final_if  */
#line 145 "cine.y"
                                                              {;}
#line 1497 "cine.tab.c"
    break;

  case 28: /* final_if: '}'  */
#line 147 "cine.y"
              {;}
#line 1503 "cine.tab.c"
    break;

  case 29: /* final_if: '}' ELSE '(' condicio ')' '{' llista_inst final_if  */
#line 148 "cine.y"
                                                              {;}
#line 1509 "cine.tab.c"
    break;

  case 30: /* final_if: '}' ELSE '{' llista_inst '}'  */
#line 149 "cine.y"
                                       {;}
#line 1515 "cine.tab.c"
    break;

  case 31: /* assignacio: IDEN '=' expr  */
#line 151 "cine.y"
                          {/*Mirar si l'identificador esta a la TS, si no esta mal*/
                            (yyval.valor_enter)=(yyvsp[0].valor_enter);
                          }
#line 1523 "cine.tab.c"
    break;

  case 32: /* assignacio_dec: IDEN '=' expr  */
#line 155 "cine.y"
                              {/*Mirar si l'identificador esta a la TS, si esta mal*/
                                (yyval.valor_enter)=(yyvsp[0].valor_enter);
                              }
#line 1531 "cine.tab.c"
    break;

  case 33: /* declaracio: tipus declaracio_variable  */
#line 159 "cine.y"
                                      {
                                        if((yyvsp[0].valor_enter) != NOVAL){
                                          if((yyvsp[-1].valor_enter) != (yyvsp[0].valor_enter)){
                                            //ERROR DE TIPUS
                                            fprintf(stderr, "ERROR: Expressió de tipus incorrecte!\n");
                                            YYERROR;
                                          }
                                        }
                                      }
#line 1545 "cine.tab.c"
    break;

  case 34: /* declaracio_variable: declaracio_amb_IDEN  */
#line 169 "cine.y"
                                          {(yyval.valor_enter)=(yyvsp[0].valor_enter);}
#line 1551 "cine.tab.c"
    break;

  case 35: /* declaracio_variable: declaracio_variable ',' declaracio_amb_IDEN  */
#line 170 "cine.y"
                                                                  {
                                                                    if((yyvsp[-2].valor_enter)==NOVAL){
                                                                      (yyval.valor_enter)=(yyvsp[0].valor_enter);
                                                                    }else if ((yyvsp[0].valor_enter)==NOVAL){
                                                                      (yyval.valor_enter)=(yyvsp[-2].valor_enter);
                                                                    }else{
                                                                      if((yyvsp[-2].valor_enter) != (yyvsp[0].valor_enter)){
                                                                        // ERROR del tipus d'expressió
                                                                        fprintf(stderr, "ERROR: Expressió de tipus incorrecte!\n");
                                                                        YYERROR;
                                                                      }else{
                                                                        (yyval.valor_enter)=(yyvsp[-2].valor_enter);
                                                                      }
                                                                    }
                                                                  }
#line 1571 "cine.tab.c"
    break;

  case 36: /* declaracio_amb_IDEN: assignacio_dec  */
#line 186 "cine.y"
                                     {(yyval.valor_enter)=(yyvsp[0].valor_enter);}
#line 1577 "cine.tab.c"
    break;

  case 37: /* declaracio_amb_IDEN: IDEN  */
#line 187 "cine.y"
                           {/*Mirar si aquest Identificador esta a la taula de simbols, si ho esta mal, sino be*/
                              (yyval.valor_enter)=NOVAL;
                            }
#line 1585 "cine.tab.c"
    break;

  case 38: /* expr: IDEN  */
#line 191 "cine.y"
           {(yyval.valor_enter)=(yyvsp[0].variable).tipus;}
#line 1591 "cine.tab.c"
    break;

  case 39: /* expr: '(' expr ')'  */
#line 192 "cine.y"
                   {(yyval.valor_enter)=(yyvsp[-1].valor_enter);}
#line 1597 "cine.tab.c"
    break;

  case 40: /* expr: expr '+' expr  */
#line 193 "cine.y"
                    {;}
#line 1603 "cine.tab.c"
    break;

  case 41: /* expr: expr '-' expr  */
#line 194 "cine.y"
                    {;}
#line 1609 "cine.tab.c"
    break;

  case 42: /* expr: expr DIV expr  */
#line 195 "cine.y"
                    {;}
#line 1615 "cine.tab.c"
    break;

  case 43: /* expr: expr '*' expr  */
#line 196 "cine.y"
                    {;}
#line 1621 "cine.tab.c"
    break;

  case 44: /* expr: expr MOD expr  */
#line 197 "cine.y"
                    {;}
#line 1627 "cine.tab.c"
    break;

  case 45: /* expr: expr INTDIV expr  */
#line 198 "cine.y"
                       {;}
#line 1633 "cine.tab.c"
    break;

  case 46: /* expr: expr POWER expr  */
#line 199 "cine.y"
                      {;}
#line 1639 "cine.tab.c"
    break;

  case 47: /* expr: '-' expr  */
#line 200 "cine.y"
                            {;}
#line 1645 "cine.tab.c"
    break;

  case 48: /* expr: crida_a_funcio  */
#line 201 "cine.y"
                     {;}
#line 1651 "cine.tab.c"
    break;

  case 49: /* expr: CADENA  */
#line 202 "cine.y"
             {(yyval.valor_enter)=TSTRING;}
#line 1657 "cine.tab.c"
    break;

  case 50: /* expr: ENTER  */
#line 203 "cine.y"
            {(yyval.valor_enter)=TINT;}
#line 1663 "cine.tab.c"
    break;

  case 51: /* expr: REAL  */
#line 204 "cine.y"
           {(yyval.valor_enter)=TREAL;}
#line 1669 "cine.tab.c"
    break;

  case 52: /* expr: CARACTER  */
#line 205 "cine.y"
               {(yyval.valor_enter)=TCHAR;}
#line 1675 "cine.tab.c"
    break;

  case 53: /* expr: BOOLEAN  */
#line 206 "cine.y"
              {(yyval.valor_enter)=TBOOL;}
#line 1681 "cine.tab.c"
    break;

  case 54: /* condicio: '(' condicio ')'  */
#line 208 "cine.y"
                           {;}
#line 1687 "cine.tab.c"
    break;

  case 55: /* condicio: NOT condicio  */
#line 209 "cine.y"
                       {;}
#line 1693 "cine.tab.c"
    break;

  case 56: /* condicio: condicio AND condicio  */
#line 210 "cine.y"
                                {;}
#line 1699 "cine.tab.c"
    break;

  case 57: /* condicio: condicio OR condicio  */
#line 211 "cine.y"
                                {;}
#line 1705 "cine.tab.c"
    break;

  case 58: /* condicio: condicio IMPLICA condicio  */
#line 212 "cine.y"
                                     {;}
#line 1711 "cine.tab.c"
    break;

  case 59: /* condicio: condicio IMPLICADOB condicio  */
#line 213 "cine.y"
                                        {;}
#line 1717 "cine.tab.c"
    break;

  case 60: /* condicio: expr comparacio expr  */
#line 214 "cine.y"
                                {;}
#line 1723 "cine.tab.c"
    break;

  case 61: /* condicio: BOOLEAN  */
#line 215 "cine.y"
                  {;}
#line 1729 "cine.tab.c"
    break;

  case 62: /* comparacio: EQ  */
#line 217 "cine.y"
                {;}
#line 1735 "cine.tab.c"
    break;

  case 63: /* comparacio: NE  */
#line 218 "cine.y"
                {;}
#line 1741 "cine.tab.c"
    break;

  case 64: /* comparacio: LT  */
#line 219 "cine.y"
                {;}
#line 1747 "cine.tab.c"
    break;

  case 65: /* comparacio: LTE  */
#line 220 "cine.y"
                {;}
#line 1753 "cine.tab.c"
    break;

  case 66: /* comparacio: GT  */
#line 221 "cine.y"
                {;}
#line 1759 "cine.tab.c"
    break;

  case 67: /* comparacio: GTE  */
#line 222 "cine.y"
                {;}
#line 1765 "cine.tab.c"
    break;

  case 68: /* tipus: INT  */
#line 224 "cine.y"
            {(yyval.valor_enter)=TINT;}
#line 1771 "cine.tab.c"
    break;

  case 69: /* tipus: BOOL  */
#line 225 "cine.y"
             {(yyval.valor_enter)=TBOOL;}
#line 1777 "cine.tab.c"
    break;

  case 70: /* tipus: CHAR  */
#line 226 "cine.y"
             {(yyval.valor_enter)=TCHAR;}
#line 1783 "cine.tab.c"
    break;

  case 71: /* tipus: FLOAT  */
#line 227 "cine.y"
              {(yyval.valor_enter)=FLOAT;}
#line 1789 "cine.tab.c"
    break;

  case 72: /* tipus: STRING  */
#line 228 "cine.y"
               {(yyval.valor_enter)=STRING;}
#line 1795 "cine.tab.c"
    break;


#line 1799 "cine.tab.c"

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

#line 230 "cine.y"

void yyerror (char const *s){
    printf("YYERROR diu: ");
    fprintf (stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
    return(yyparse());
}
