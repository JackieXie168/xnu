/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADDRMOD = 258,
     AND = 259,
     ANY = 260,
     ARGS = 261,
     AT = 262,
     BIN = 263,
     BUILDDIR = 264,
     COMMA = 265,
     CONFIG = 266,
     CONFIGDIR = 267,
     CONTROLLER = 268,
     CPU = 269,
     CSR = 270,
     DEVICE = 271,
     DISK = 272,
     DRIVE = 273,
     DST = 274,
     DUMPS = 275,
     EQUALS = 276,
     FLAGS = 277,
     HZ = 278,
     IDENT = 279,
     INIT = 280,
     MACHINE = 281,
     MAJOR = 282,
     MASTER = 283,
     MAXUSERS = 284,
     MAXDSIZ = 285,
     MBA = 286,
     MBII = 287,
     MINOR = 288,
     MINUS = 289,
     NEXUS = 290,
     OBJECTDIR = 291,
     ON = 292,
     OPTIONS = 293,
     MAKEOPTIONS = 294,
     PRIORITY = 295,
     PROFILE = 296,
     PSEUDO_DEVICE = 297,
     ROOT = 298,
     SEMICOLON = 299,
     SIZE = 300,
     SLAVE = 301,
     SOURCEDIR = 302,
     SWAP = 303,
     TIMEZONE = 304,
     TRACE = 305,
     UBA = 306,
     VECTOR = 307,
     VME = 308,
     VME16D16 = 309,
     VME24D16 = 310,
     VME32D16 = 311,
     VME16D32 = 312,
     VME24D32 = 313,
     VME32D32 = 314,
     LUN = 315,
     SLOT = 316,
     TAPE = 317,
     ID = 318,
     NUMBER = 319,
     FPNUMBER = 320
   };
#endif
/* Tokens.  */
#define ADDRMOD 258
#define AND 259
#define ANY 260
#define ARGS 261
#define AT 262
#define BIN 263
#define BUILDDIR 264
#define COMMA 265
#define CONFIG 266
#define CONFIGDIR 267
#define CONTROLLER 268
#define CPU 269
#define CSR 270
#define DEVICE 271
#define DISK 272
#define DRIVE 273
#define DST 274
#define DUMPS 275
#define EQUALS 276
#define FLAGS 277
#define HZ 278
#define IDENT 279
#define INIT 280
#define MACHINE 281
#define MAJOR 282
#define MASTER 283
#define MAXUSERS 284
#define MAXDSIZ 285
#define MBA 286
#define MBII 287
#define MINOR 288
#define MINUS 289
#define NEXUS 290
#define OBJECTDIR 291
#define ON 292
#define OPTIONS 293
#define MAKEOPTIONS 294
#define PRIORITY 295
#define PROFILE 296
#define PSEUDO_DEVICE 297
#define ROOT 298
#define SEMICOLON 299
#define SIZE 300
#define SLAVE 301
#define SOURCEDIR 302
#define SWAP 303
#define TIMEZONE 304
#define TRACE 305
#define UBA 306
#define VECTOR 307
#define VME 308
#define VME16D16 309
#define VME24D16 310
#define VME32D16 311
#define VME16D32 312
#define VME24D32 313
#define VME32D32 314
#define LUN 315
#define SLOT 316
#define TAPE 317
#define ID 318
#define NUMBER 319
#define FPNUMBER 320




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
{
	char	*str;
	int	val;
	struct	file_list *file;
	struct	idlst *lst;
}
/* Line 193 of yacc.c.  */
#line 234 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 117 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"


#include "config.h"
#include <ctype.h>
#include <stdio.h>

struct	device cur;
struct	device *curp = 0;
char	*temp_id;
char	*val_id;
/* char	*malloc(); */

int yylex(void);

int finddev(dev_t dev);
int alreadychecked(dev_t dev, dev_t list[], dev_t *last);
void deverror(const char *systemname, const char *devtype);
void mkconf(char *sysname);
struct file_list *newswap(void);
void mkswap(struct file_list *syslist, struct file_list *fl, int size);
struct device *huhcon(const char *dev);
void check_nexus(struct device *dev, int num);
void check_slot(struct device *dev, int num);
void checksystemspec(struct file_list *fl);
void verifysystemspecs(void);
dev_t *verifyswap(struct file_list *fl, dev_t checked[], dev_t *pchecked);
struct device *dconnect(const char *dev, int num);



/* Line 216 of yacc.c.  */
#line 276 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    15,    18,    20,
      23,    26,    29,    32,    35,    38,    40,    43,    46,    49,
      52,    55,    57,    59,    62,    65,    68,    70,    72,    74,
      76,    78,    82,    86,    88,    91,    93,    95,    99,   101,
     103,   107,   109,   111,   115,   117,   119,   124,   126,   127,
     130,   131,   133,   136,   140,   144,   146,   148,   152,   154,
     156,   157,   159,   163,   165,   167,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   198,   203,
     208,   213,   218,   222,   227,   233,   240,   244,   245,   248,
     249,   253,   257,   261,   264,   265,   268,   271,   274,   277,
     280,   283,   286,   289,   291,   294,   296,   299,   303,   307,
     308,   311,   313,   316,   319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,    68,    -1,    68,    69,    -1,    -1,    96,
      44,    -1,    70,    44,    -1,    50,    44,    -1,    44,    -1,
       1,    44,    -1,    26,    92,    -1,    14,    92,    -1,    38,
      89,    -1,    39,    93,    -1,    24,    63,    -1,    71,    -1,
      29,    64,    -1,     9,    92,    -1,    12,    92,    -1,    36,
      92,    -1,    47,    92,    -1,    41,    -1,    72,    -1,    72,
      73,    -1,    11,    92,    -1,    73,    74,    -1,    74,    -1,
      75,    -1,    79,    -1,    81,    -1,    83,    -1,    48,    86,
      76,    -1,    76,     4,    77,    -1,    77,    -1,    78,    87,
      -1,    88,    -1,    85,    -1,    43,    86,    80,    -1,    88,
      -1,    85,    -1,    20,    86,    82,    -1,    88,    -1,    85,
      -1,     6,    86,    84,    -1,    88,    -1,    85,    -1,    27,
      64,    33,    64,    -1,    37,    -1,    -1,    45,    64,    -1,
      -1,    92,    -1,    92,    64,    -1,    92,    64,    63,    -1,
      89,    10,    90,    -1,    90,    -1,    92,    -1,    92,    21,
      91,    -1,    63,    -1,    64,    -1,    -1,    63,    -1,    93,
      10,    94,    -1,    94,    -1,    92,    -1,    92,    21,    91,
      -1,    51,    -1,    31,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    53,    -1,    32,
      -1,    63,    -1,    16,    97,    99,   104,    -1,    28,    97,
      99,   104,    -1,    17,    97,    99,   104,    -1,    62,    97,
      99,   104,    -1,    13,    97,    99,   104,    -1,    42,    98,
      95,    -1,    42,    98,    95,    64,    -1,    42,    98,    95,
      25,    63,    -1,    42,    98,    95,    64,    25,    63,    -1,
      98,    95,    64,    -1,    -1,   100,   101,    -1,    -1,     7,
      95,    64,    -1,     7,    61,    64,    -1,     7,    35,    64,
      -1,   101,   102,    -1,    -1,    15,    64,    -1,    18,    64,
      -1,    46,    64,    -1,     3,    64,    -1,    60,    64,    -1,
      22,    64,    -1,     8,    64,    -1,    95,   103,    -1,    64,
      -1,    34,    64,    -1,   105,    -1,    40,    64,    -1,    40,
      64,   105,    -1,   105,    40,    64,    -1,    -1,    52,   106,
      -1,    92,    -1,    92,   106,    -1,    92,    64,    -1,    92,
      64,   106,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   153,   154,   159,   161,   163,   165,   167,
     171,   246,   255,   257,   259,   262,   264,   267,   270,   273,
     276,   279,   284,   286,   291,   296,   297,   301,   302,   303,
     304,   308,   312,   313,   317,   322,   334,   345,   357,   359,
     363,   376,   378,   382,   394,   396,   400,   405,   406,   410,
     413,   417,   419,   426,   436,   438,   442,   455,   472,   474,
     480,   484,   489,   491,   495,   504,   521,   523,   525,   532,
     539,   546,   552,   558,   564,   570,   576,   581,   583,   585,
     588,   590,   592,   597,   603,   609,   618,   634,   637,   638,
     643,   656,   662,   666,   667,   672,   679,   686,   695,   698,
     708,   715,   726,   734,   736,   741,   743,   745,   747,   748,
     753,   758,   764,   770,   776
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADDRMOD", "AND", "ANY", "ARGS", "AT",
  "BIN", "BUILDDIR", "COMMA", "CONFIG", "CONFIGDIR", "CONTROLLER", "CPU",
  "CSR", "DEVICE", "DISK", "DRIVE", "DST", "DUMPS", "EQUALS", "FLAGS",
  "HZ", "IDENT", "INIT", "MACHINE", "MAJOR", "MASTER", "MAXUSERS",
  "MAXDSIZ", "MBA", "MBII", "MINOR", "MINUS", "NEXUS", "OBJECTDIR", "ON",
  "OPTIONS", "MAKEOPTIONS", "PRIORITY", "PROFILE", "PSEUDO_DEVICE", "ROOT",
  "SEMICOLON", "SIZE", "SLAVE", "SOURCEDIR", "SWAP", "TIMEZONE", "TRACE",
  "UBA", "VECTOR", "VME", "VME16D16", "VME24D16", "VME32D16", "VME16D32",
  "VME24D32", "VME32D32", "LUN", "SLOT", "TAPE", "ID", "NUMBER",
  "FPNUMBER", "$accept", "Configuration", "Many_specs", "Spec",
  "Config_spec", "System_spec", "System_id", "System_parameter_list",
  "System_parameter", "swap_spec", "swap_device_list", "swap_device",
  "swap_device_spec", "root_spec", "root_device_spec", "dump_spec",
  "dump_device_spec", "arg_spec", "arg_device_spec", "major_minor",
  "optional_on", "optional_size", "device_name", "Opt_list", "Option",
  "Opt_value", "Save_id", "Mkopt_list", "Mkoption", "Dev", "Device_spec",
  "Dev_name", "Init_dev", "Dev_info", "Con_info", "Info_list", "Info",
  "Value", "Int_spec", "Vec_spec", "Id_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    73,    73,    74,    74,    74,
      74,    75,    76,    76,    77,    78,    78,    79,    80,    80,
      81,    82,    82,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    98,    99,    99,
     100,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   104,
     105,   106,   106,   106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     3,     3,     1,     2,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     4,     1,     0,     2,
       0,     1,     2,     3,     3,     1,     1,     3,     1,     1,
       0,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     3,     4,     5,     6,     3,     0,     2,     0,
       3,     3,     3,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     2,     3,     3,     0,
       2,     1,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,    87,     0,
      87,    87,     0,     0,    87,     0,     0,     0,     0,    21,
      87,     8,     0,     0,    87,     3,     0,    15,    22,     0,
       9,    61,    17,    24,    18,    89,     0,    11,    89,    89,
      14,    10,    89,    16,    19,    12,    55,    56,    64,    13,
      63,     0,    20,     7,    89,     6,    48,    48,    48,    48,
      23,    26,    27,    28,    29,    30,     5,     0,   109,    94,
      67,    75,    66,    74,    68,    69,    70,    71,    72,    73,
      76,     0,   109,   109,   109,     0,    60,    60,     0,    82,
     109,    47,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    81,   105,    88,    86,    77,    79,    78,    54,
      58,    59,    57,    65,    62,     0,    83,    80,     0,    43,
      45,    44,    51,    40,    42,    41,    37,    39,    38,    31,
      33,    50,    36,    35,    92,    91,    90,   106,   111,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      84,     0,     0,    52,     0,     0,    34,   107,   113,   112,
     108,    98,   101,    95,    96,   100,    97,    99,     0,   103,
     102,    85,     0,    53,    32,    49,   114,   104,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    27,    28,    60,    61,    62,
     129,   130,   131,    63,   126,    64,   123,    65,   119,   132,
      92,   156,   133,    45,    46,   112,   122,    49,    50,    81,
      29,    35,    36,    68,    69,   104,   149,   170,   102,   103,
     139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
    -132,    24,     9,  -132,   -12,   -29,   -29,   -29,  -132,   -29,
    -132,  -132,   -17,   -29,  -132,   -21,   -29,   -29,   -29,  -132,
    -132,  -132,   -29,    -4,  -132,  -132,     8,  -132,    22,    11,
    -132,  -132,  -132,  -132,  -132,    53,    92,  -132,    53,    53,
    -132,  -132,    53,  -132,  -132,    62,  -132,    48,    58,    72,
    -132,    92,  -132,  -132,    53,  -132,    56,    56,    56,    56,
      22,  -132,  -132,  -132,  -132,  -132,  -132,    59,   -11,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,    31,   -11,   -11,   -11,   -29,    -6,    -6,   -29,   -20,
     -11,  -132,   -24,   -24,   -24,   -24,  -132,    34,    47,    55,
      57,   -29,  -132,    88,    46,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,    66,   105,  -132,    67,  -132,
    -132,  -132,    68,  -132,  -132,  -132,  -132,  -132,  -132,   130,
    -132,    90,  -132,  -132,  -132,  -132,  -132,    84,    44,  -132,
      73,    74,    75,    76,    77,    78,    80,    93,   -28,  -132,
    -132,    89,   121,    95,   -24,    96,  -132,  -132,   -29,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    97,  -132,
    -132,  -132,    98,  -132,  -132,  -132,  -132,  -132,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    99,  -132,
    -132,     2,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    -8,
      30,  -132,    33,  -132,    79,    81,    -5,  -132,    82,   -37,
    -132,    52,   143,   -23,  -132,  -132,  -132,  -132,    -9,    28,
    -131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      32,    33,    34,   118,    37,   115,   168,   159,    41,    -2,
       4,    44,    47,    48,    89,    82,    83,    52,     5,    84,
       6,     7,     8,     9,     3,    10,    11,   176,    56,   100,
      99,    90,    30,    12,    31,    13,   169,    14,    15,    31,
      53,   101,    57,    43,   116,    16,    40,    17,    18,   141,
      19,    20,    55,    21,   142,    66,    22,   110,   111,    23,
      67,   143,    38,    39,   144,    58,    42,   148,   145,    86,
      59,    24,    85,   106,   107,   108,    54,    70,    71,    87,
      47,   117,    88,    48,   120,   124,   127,    93,    94,    95,
      70,    71,   146,    91,    97,   105,   138,    72,   134,    73,
      74,    75,    76,    77,    78,    79,   147,    31,   158,    80,
      72,   135,    73,    74,    75,    76,    77,    78,    79,   136,
      98,   137,    80,    70,    71,   121,   125,   128,   140,   150,
     151,   152,   153,   138,   154,   155,   101,   160,   161,   162,
     163,   164,   165,    72,   166,    73,    74,    75,    76,    77,
      78,    79,   171,   138,   172,    80,   174,   167,   173,    96,
     175,   177,   178,    51,   109,   157,     0,     0,   113,     0,
     114
};

static const yytype_int16 yycheck[] =
{
       5,     6,     7,    27,     9,    25,    34,   138,    13,     0,
       1,    16,    17,    18,    51,    38,    39,    22,     9,    42,
      11,    12,    13,    14,     0,    16,    17,   158,     6,    40,
      67,    54,    44,    24,    63,    26,    64,    28,    29,    63,
      44,    52,    20,    64,    64,    36,    63,    38,    39,     3,
      41,    42,    44,    44,     8,    44,    47,    63,    64,    50,
       7,    15,    10,    11,    18,    43,    14,   104,    22,    21,
      48,    62,    10,    82,    83,    84,    24,    31,    32,    21,
      85,    90,    10,    88,    92,    93,    94,    57,    58,    59,
      31,    32,    46,    37,    35,    64,   101,    51,    64,    53,
      54,    55,    56,    57,    58,    59,    60,    63,    64,    63,
      51,    64,    53,    54,    55,    56,    57,    58,    59,    64,
      61,    64,    63,    31,    32,    92,    93,    94,    40,    63,
      25,    64,    64,   138,     4,    45,    52,    64,    64,    64,
      64,    64,    64,    51,    64,    53,    54,    55,    56,    57,
      58,    59,    63,   158,    33,    63,   154,    64,    63,    60,
      64,    64,    64,    20,    85,   137,    -1,    -1,    87,    -1,
      88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     9,    11,    12,    13,    14,
      16,    17,    24,    26,    28,    29,    36,    38,    39,    41,
      42,    44,    47,    50,    62,    69,    70,    71,    72,    96,
      44,    63,    92,    92,    92,    97,    98,    92,    97,    97,
      63,    92,    97,    64,    92,    89,    90,    92,    92,    93,
      94,    98,    92,    44,    97,    44,     6,    20,    43,    48,
      73,    74,    75,    79,    81,    83,    44,     7,    99,   100,
      31,    32,    51,    53,    54,    55,    56,    57,    58,    59,
      63,    95,    99,    99,    99,    10,    21,    21,    10,    95,
      99,    37,    86,    86,    86,    86,    74,    35,    61,    95,
      40,    52,   104,   105,   101,    64,   104,   104,   104,    90,
      63,    64,    91,    91,    94,    25,    64,   104,    27,    84,
      85,    88,    92,    82,    85,    88,    80,    85,    88,    76,
      77,    78,    85,    88,    64,    64,    64,    64,    92,   106,
      40,     3,     8,    15,    18,    22,    46,    60,    95,   102,
      63,    25,    64,    64,     4,    45,    87,   105,    64,   106,
      64,    64,    64,    64,    64,    64,    64,    64,    34,    64,
     103,    63,    33,    63,    77,    64,   106,    64,    64
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 149 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { verifysystemspecs(); }
    break;

  case 5:
#line 160 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { newdev(&cur); }
    break;

  case 7:
#line 164 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { do_trace = !do_trace; }
    break;

  case 10:
#line 172 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (!strcmp((yyvsp[(2) - (2)].str), "vax")) {
			machine = MACHINE_VAX;
			machinename = "vax";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "sun")) {
			/* default to Sun 3 */
			machine = MACHINE_SUN3;
			machinename = "sun3";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "sun2")) {
			machine = MACHINE_SUN2;
			machinename = "sun2";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "sun3")) {
			machine = MACHINE_SUN3;
			machinename = "sun3";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "sun4")) {
			machine = MACHINE_SUN4;
			machinename = "sun4";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "romp")) {
			machine = MACHINE_ROMP;
			machinename = "romp";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "ca")) {
			machine = MACHINE_ROMP;
			machinename = "ca";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "mmax")) {
			machine = MACHINE_MMAX;
			machinename = "mmax";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "sqt")) {
			machine = MACHINE_SQT;
			machinename = "sqt";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "i")) {
			machine = MACHINE_I386;
			machinename = "i386";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "i386")) {
			machine = MACHINE_I386;
			machinename = "i386";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "ix")) {
			machine = MACHINE_IX;
			machinename = "ix";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "mipsy")) {
			machine = MACHINE_MIPSY;
			machinename = "mipsy";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "mips")) {
			machine = MACHINE_MIPS;
			machinename = "mips";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "i860")) {
			machine = MACHINE_I860;
			machinename = "i860";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "m68k")) {
			machine = MACHINE_M68K;
			machinename = "m68k";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "m88k")) {
			machine = MACHINE_M88K;
			machinename = "m88k";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "m98k")) {
			machine = MACHINE_M98K;
			machinename = "m98k";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "hppa")) {
			machine = MACHINE_HPPA;
			machinename = "hppa";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "sparc")) {
			machine = MACHINE_SPARC;
			machinename = "sparc";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "ppc")) {
			machine = MACHINE_PPC;
			machinename = "ppc";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "arm")) {
			machine = MACHINE_ARM;
			machinename = "arm";
		} else if (!strcmp((yyvsp[(2) - (2)].str), "x86_64")) {
			machine = MACHINE_X86_64;
			machinename = "x86_64";
		} else
			yyerror("Unknown machine type");
	      }
    break;

  case 11:
#line 247 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct cputype *cp =
		    (struct cputype *)malloc(sizeof (struct cputype));
		cp->cpu_name = ns((yyvsp[(2) - (2)].str));
		cp->cpu_next = cputype;
		cputype = cp;
		free(temp_id);
	      }
    break;

  case 14:
#line 260 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { ident = ns((yyvsp[(2) - (2)].str)); }
    break;

  case 16:
#line 265 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { maxusers = (yyvsp[(2) - (2)].val); }
    break;

  case 17:
#line 268 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { build_directory = ns((yyvsp[(2) - (2)].str)); }
    break;

  case 18:
#line 271 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { config_directory = ns((yyvsp[(2) - (2)].str)); }
    break;

  case 19:
#line 274 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { object_directory = ns((yyvsp[(2) - (2)].str)); }
    break;

  case 20:
#line 277 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { source_directory = ns((yyvsp[(2) - (2)].str)); }
    break;

  case 21:
#line 280 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { profiling++; }
    break;

  case 22:
#line 285 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { checksystemspec(*confp); }
    break;

  case 23:
#line 287 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { checksystemspec(*confp); }
    break;

  case 24:
#line 292 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { mkconf((yyvsp[(2) - (2)].str)); }
    break;

  case 34:
#line 318 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { mkswap(*confp, (yyvsp[(1) - (2)].file), (yyvsp[(2) - (2)].val)); }
    break;

  case 35:
#line 323 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			struct file_list *fl = newswap();

			if (eq((yyvsp[(1) - (1)].str), "generic"))
				fl->f_fn = (yyvsp[(1) - (1)].str);
			else {
				fl->f_swapdev = nametodev((yyvsp[(1) - (1)].str), 0, 'b');
				fl->f_fn = devtoname(fl->f_swapdev);
			}
			(yyval.file) = fl;
		}
    break;

  case 36:
#line 335 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			struct file_list *fl = newswap();

			fl->f_swapdev = (yyvsp[(1) - (1)].val);
			fl->f_fn = devtoname((yyvsp[(1) - (1)].val));
			(yyval.file) = fl;
		}
    break;

  case 37:
#line 346 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			struct file_list *fl = *confp;

			if (fl && fl->f_rootdev != NODEV)
				yyerror("extraneous root device specification");
			else
				fl->f_rootdev = (yyvsp[(3) - (3)].val);
		}
    break;

  case 38:
#line 358 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = nametodev((yyvsp[(1) - (1)].str), 0, 'a'); }
    break;

  case 40:
#line 364 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			struct file_list *fl = *confp;

			if (fl && fl->f_dumpdev != NODEV)
				yyerror("extraneous dump device specification");
			else
				fl->f_dumpdev = (yyvsp[(3) - (3)].val);
		}
    break;

  case 41:
#line 377 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = nametodev((yyvsp[(1) - (1)].str), 0, 'b'); }
    break;

  case 43:
#line 383 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			struct file_list *fl = *confp;

			if (fl && fl->f_argdev != NODEV)
				yyerror("extraneous arg device specification");
			else
				fl->f_argdev = (yyvsp[(3) - (3)].val);
		}
    break;

  case 44:
#line 395 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = nametodev((yyvsp[(1) - (1)].str), 0, 'b'); }
    break;

  case 46:
#line 401 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = makedev((yyvsp[(2) - (4)].val), (yyvsp[(4) - (4)].val)); }
    break;

  case 49:
#line 411 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); }
    break;

  case 50:
#line 413 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = 0; }
    break;

  case 51:
#line 418 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 52:
#line 420 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			char buf[80];

			(void) sprintf(buf, "%s%d", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].val));
			(yyval.str) = ns(buf); free((yyvsp[(1) - (2)].str));
		}
    break;

  case 53:
#line 427 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			char buf[80];

			(void) sprintf(buf, "%s%d%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].val), (yyvsp[(3) - (3)].str));
			(yyval.str) = ns(buf); free((yyvsp[(1) - (3)].str));
		}
    break;

  case 56:
#line 443 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns((yyvsp[(1) - (1)].str));
		op->op_next = (struct opt *) 0;
		op->op_value = 0;
		if (opt == (struct opt *) 0)
			opt = op;
		else
			opt_tail->op_next = op;
		opt_tail = op;
		free(temp_id);
	      }
    break;

  case 57:
#line 456 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns((yyvsp[(1) - (3)].str));
		op->op_next = (struct opt *) 0;
		op->op_value = ns((yyvsp[(3) - (3)].str));
		if (opt == (struct opt *) 0)
			opt = op;
		else
			opt_tail->op_next = op;
		opt_tail = op;
		free(temp_id);
		if (val_id)
			free(val_id);
	      }
    break;

  case 58:
#line 473 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = val_id = ns((yyvsp[(1) - (1)].str)); }
    break;

  case 59:
#line 475 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { char nb[16];
	          (void) sprintf(nb, "%u", (yyvsp[(1) - (1)].val));
	      	  (yyval.str) = val_id = ns(nb);
	      }
    break;

  case 60:
#line 480 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = val_id = ns(""); }
    break;

  case 61:
#line 485 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = temp_id = ns((yyvsp[(1) - (1)].str)); }
    break;

  case 64:
#line 496 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns((yyvsp[(1) - (1)].str));
		op->op_next =  (struct opt *) 0;
		op->op_value = 0;
		mkopt = op;
		free(temp_id);
	      }
    break;

  case 65:
#line 505 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns((yyvsp[(1) - (3)].str));
		op->op_next =  (struct opt *) 0;
		op->op_value = ns((yyvsp[(3) - (3)].str));
		if (mkopt == (struct opt *) 0)
			mkopt = op;
		else
			mkopt_tail->op_next = op;
		mkopt_tail = op;
		free(temp_id);
		if (val_id)
			free(val_id);
	      }
    break;

  case 66:
#line 522 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = ns("uba"); }
    break;

  case 67:
#line 524 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = ns("mba"); }
    break;

  case 68:
#line 526 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_SUN2 && machine != MACHINE_SUN3
		    && machine != MACHINE_SUN4)
			yyerror("wrong machine type for vme16d16");
		(yyval.str) = ns("vme16d16");
		}
    break;

  case 69:
#line 533 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_SUN2 && machine != MACHINE_SUN3
		    && machine != MACHINE_SUN4)
			yyerror("wrong machine type for vme24d16");
			(yyval.str) = ns("vme24d16");
		}
    break;

  case 70:
#line 540 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_SUN3 && machine != MACHINE_SUN4)

                        yyerror("wrong machine type for vme32d16");
                (yyval.str) = ns("vme32d16");
                }
    break;

  case 71:
#line 547 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
                if (machine != MACHINE_SUN3  && machine != MACHINE_SUN4)
                        yyerror("wrong machine type for vme16d32");
                (yyval.str) = ns("vme16d32");
                }
    break;

  case 72:
#line 553 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_SUN3 && machine != MACHINE_SUN4)
			yyerror("wrong machine type for vme24d32");
		(yyval.str) = ns("vme24d32");
		}
    break;

  case 73:
#line 559 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_SUN3 && machine != MACHINE_SUN4)
			yyerror("wrong machine type for vme32d32");
		(yyval.str) = ns("vme32d32");
		}
    break;

  case 74:
#line 565 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_MIPSY && machine != MACHINE_MIPS)
			yyerror("wrong machine type for vme");
			(yyval.str) = ns("vme");
		}
    break;

  case 75:
#line 571 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_MIPSY && machine != MACHINE_MIPS)
			yyerror("wrong machine type for mbii");
			(yyval.str) = ns("mbii");
		}
    break;

  case 76:
#line 577 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.str) = ns((yyvsp[(1) - (1)].str)); }
    break;

  case 77:
#line 582 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_type = DEVICE; }
    break;

  case 78:
#line 584 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_type = MASTER; }
    break;

  case 79:
#line 586 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_dk = 1; cur.d_type = DEVICE; }
    break;

  case 80:
#line 589 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_type = DEVICE; }
    break;

  case 81:
#line 591 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_type = CONTROLLER; }
    break;

  case 82:
#line 593 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_name = (yyvsp[(3) - (3)].str);
		cur.d_type = PSEUDO_DEVICE;
		}
    break;

  case 83:
#line 598 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_name = (yyvsp[(3) - (4)].str);
		cur.d_type = PSEUDO_DEVICE;
		cur.d_slave = (yyvsp[(4) - (4)].val);
		}
    break;

  case 84:
#line 604 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_name = (yyvsp[(3) - (5)].str);
		cur.d_type = PSEUDO_DEVICE;
		cur.d_init = ns((yyvsp[(5) - (5)].str));
		}
    break;

  case 85:
#line 610 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_name = (yyvsp[(3) - (6)].str);
		cur.d_type = PSEUDO_DEVICE;
		cur.d_slave = (yyvsp[(4) - (6)].val);
		cur.d_init = ns((yyvsp[(6) - (6)].str));
		}
    break;

  case 86:
#line 619 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_name = (yyvsp[(2) - (3)].str);
		if (eq((yyvsp[(2) - (3)].str), "mba"))
			seen_mba = 1;
		else if (eq((yyvsp[(2) - (3)].str), "uba"))
			seen_uba = 1;
		else if (eq((yyvsp[(2) - (3)].str), "mbii"))
			seen_mbii = 1;
		else if (eq((yyvsp[(2) - (3)].str), "vme"))
			seen_vme = 1;
		cur.d_unit = (yyvsp[(3) - (3)].val);
		}
    break;

  case 87:
#line 634 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { init_dev(&cur); }
    break;

  case 90:
#line 644 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (eq(cur.d_name, "mba") || eq(cur.d_name, "uba")
		    || eq(cur.d_name, "mbii") || eq(cur.d_name, "vme")) {
			(void) sprintf(errbuf,
			    "%s must be connected to a nexus", cur.d_name);
			yyerror(errbuf);
		}
		cur.d_conn = dconnect((yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].val));
		if (machine == MACHINE_SQT)
			dev_param(&cur, "index", cur.d_unit);
		}
    break;

  case 91:
#line 657 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { 
		check_slot(&cur, (yyvsp[(3) - (3)].val));
		cur.d_addr = (yyvsp[(3) - (3)].val);
		cur.d_conn = TO_SLOT; 
		 }
    break;

  case 92:
#line 663 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { check_nexus(&cur, (yyvsp[(3) - (3)].val)); cur.d_conn = TO_NEXUS; }
    break;

  case 95:
#line 673 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_addr = (yyvsp[(2) - (2)].val);
		if (machine == MACHINE_SQT) {
			dev_param(&cur, "csr", (yyvsp[(2) - (2)].val));
		}
		}
    break;

  case 96:
#line 680 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
			cur.d_drive = (yyvsp[(2) - (2)].val);
			if (machine == MACHINE_SQT) {
				dev_param(&cur, "drive", (yyvsp[(2) - (2)].val));
			}
		}
    break;

  case 97:
#line 687 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (cur.d_conn != 0 && cur.d_conn != TO_NEXUS &&
		    cur.d_conn->d_type == MASTER)
			cur.d_slave = (yyvsp[(2) - (2)].val);
		else
			yyerror("can't specify slave--not to master");
		}
    break;

  case 98:
#line 696 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_addrmod = (yyvsp[(2) - (2)].val); }
    break;

  case 99:
#line 699 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if ((cur.d_conn != 0) && (cur.d_conn != TO_SLOT) &&
			(cur.d_conn->d_type == CONTROLLER)) {
			cur.d_addr = (yyvsp[(2) - (2)].val); 
		}
		else {
			yyerror("device requires controller card");
		    }
		}
    break;

  case 100:
#line 709 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		cur.d_flags = (yyvsp[(2) - (2)].val);
		if (machine == MACHINE_SQT) {
			dev_param(&cur, "flags", (yyvsp[(2) - (2)].val));
		}
	      }
    break;

  case 101:
#line 716 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { 
		 if (machine != MACHINE_SQT)
			yyerror("bin specification only valid on Sequent Balance");
		 if ((yyvsp[(2) - (2)].val) < 1 || (yyvsp[(2) - (2)].val) > 7)  
			yyerror("bogus bin number");
		 else {
			cur.d_bin = (yyvsp[(2) - (2)].val);
			dev_param(&cur, "bin", (yyvsp[(2) - (2)].val));
		}
	       }
    break;

  case 102:
#line 727 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		if (machine != MACHINE_SQT)
			yyerror("bad device spec");
		dev_param(&cur, (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].val));
		}
    break;

  case 104:
#line 737 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { (yyval.val) = -((yyvsp[(2) - (2)].val)); }
    break;

  case 105:
#line 742 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_pri = 0; }
    break;

  case 106:
#line 744 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_pri = (yyvsp[(2) - (2)].val); }
    break;

  case 107:
#line 746 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_pri = (yyvsp[(2) - (3)].val); }
    break;

  case 108:
#line 748 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_pri = (yyvsp[(3) - (3)].val); }
    break;

  case 110:
#line 754 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    { cur.d_vec = (yyvsp[(2) - (2)].lst); }
    break;

  case 111:
#line 759 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
		a->id = (yyvsp[(1) - (1)].str); a->id_next = 0; (yyval.lst) = a;
		a->id_vec = 0;
		}
    break;

  case 112:
#line 765 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
	        a->id = (yyvsp[(1) - (2)].str); a->id_next = (yyvsp[(2) - (2)].lst); (yyval.lst) = a;
		a->id_vec = 0;
		}
    break;

  case 113:
#line 771 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
		a->id_next = 0; a->id = (yyvsp[(1) - (2)].str); (yyval.lst) = a;
		a->id_vec = (yyvsp[(2) - (2)].val);
		}
    break;

  case 114:
#line 777 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
    {
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
		a->id_next = (yyvsp[(3) - (3)].lst); a->id = (yyvsp[(1) - (3)].str); (yyval.lst) = a;
		a->id_vec = (yyvsp[(2) - (3)].val);
		}
    break;


/* Line 1267 of yacc.c.  */
#line 2366 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 783 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"


void
yyerror(const char *s)
{
	fprintf(stderr, "config: line %d: %s\n", yyline, s);
}

/*
 * return the passed string in a new space
 */
char *
ns(const char *str)
{
	register char *cp;

	cp = malloc((unsigned)(strlen(str)+1));
	(void) strcpy(cp, str);
	return (cp);
}

/*
 * add a device to the list of devices
 */
void
newdev(struct device *dp)
{
	register struct device *np;

	np = (struct device *) malloc(sizeof *np);
	*np = *dp;
	if (curp == 0)
		dtab = np;
	else
		curp->d_next = np;
	curp = np;
	curp->d_next = 0;
}

/*
 * note that a configuration should be made
 */
void
mkconf(char *sysname)
{
	register struct file_list *fl, **flp;

	fl = (struct file_list *) malloc(sizeof *fl);
	fl->f_type = SYSTEMSPEC;
	fl->f_needs = sysname;
	fl->f_rootdev = NODEV;
	fl->f_argdev = NODEV;
	fl->f_dumpdev = NODEV;
	fl->f_fn = 0;
	fl->f_next = 0;
	for (flp = confp; *flp; flp = &(*flp)->f_next)
		;
	*flp = fl;
	confp = flp;
}

struct file_list *
newswap(void)
{
	struct file_list *fl = (struct file_list *)malloc(sizeof (*fl));

	fl->f_type = SWAPSPEC;
	fl->f_next = 0;
	fl->f_swapdev = NODEV;
	fl->f_swapsize = 0;
	fl->f_needs = 0;
	fl->f_fn = 0;
	return (fl);
}

/*
 * Add a swap device to the system's configuration
 */
void
mkswap(struct file_list *syslist, struct file_list *fl, int size)
{
	register struct file_list **flp;

	if (syslist == 0 || syslist->f_type != SYSTEMSPEC) {
		yyerror("\"swap\" spec precedes \"config\" specification");
		return;
	}
	if (size < 0) {
		yyerror("illegal swap partition size");
		return;
	}
	/*
	 * Append swap description to the end of the list.
	 */
	flp = &syslist->f_next;
	for (; *flp && (*flp)->f_type == SWAPSPEC; flp = &(*flp)->f_next)
		;
	fl->f_next = *flp;
	*flp = fl;
	fl->f_swapsize = size;
	/*
	 * If first swap device for this system,
	 * set up f_fn field to insure swap
	 * files are created with unique names.
	 */
	if (syslist->f_fn)
		return;
	if (eq(fl->f_fn, "generic"))
		syslist->f_fn = ns(fl->f_fn);
	else
		syslist->f_fn = ns(syslist->f_needs);
}

/*
 * find the pointer to connect to the given device and number.
 * returns 0 if no such device and prints an error message
 */
struct device *
dconnect(const char *dev, int num)
{
	register struct device *dp;

	if (num == QUES)
		return (huhcon(dev));
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		if ((num != dp->d_unit) || !eq(dev, dp->d_name))
			continue;
		if (dp->d_type != CONTROLLER && dp->d_type != MASTER) {
			(void) sprintf(errbuf,
			    "%s connected to non-controller", dev);
			yyerror(errbuf);
			return (0);
		}
		return (dp);
	}
	(void) sprintf(errbuf, "%s %d not defined", dev, num);
	yyerror(errbuf);
	return (0);
}

/*
 * connect to an unspecific thing
 */
struct device *
huhcon(const char *dev)
{
	register struct device *dp, *dcp;
	struct device rdev;	/* only used if dp is NULL */
	int oldtype;

	memset(&rdev, 0, sizeof rdev);

	/*
	 * First make certain that there are some of these to wildcard on
	 */
	for (dp = dtab; dp != 0; dp = dp->d_next)
		if (eq(dp->d_name, dev))
			break;
	if (dp == 0) {
		(void) sprintf(errbuf, "no %s's to wildcard", dev);
		yyerror(errbuf);
		return (0);
	}
	oldtype = dp->d_type;
	dcp = dp->d_conn;
	/*
	 * Now see if there is already a wildcard entry for this device
	 * (e.g. Search for a "uba ?")
	 */
	for (; dp != 0; dp = dp->d_next)
		if (eq(dev, dp->d_name) && dp->d_unit == -1)
			break;
	/*
	 * If there isn't, make one because everything needs to be connected
	 * to something.
	 */
	if (dp == 0) {
		dp = &rdev;
		init_dev(dp);
		dp->d_unit = QUES;
		dp->d_name = ns(dev);
		dp->d_type = oldtype;
		newdev(dp);
		dp = curp;
		/*
		 * Connect it to the same thing that other similar things are
		 * connected to, but make sure it is a wildcard unit
		 * (e.g. up connected to sc ?, here we make connect sc? to a
		 * uba?).  If other things like this are on the NEXUS or
		 * if they aren't connected to anything, then make the same
		 * connection, else call ourself to connect to another
		 * unspecific device.
		 */
		if (dcp == TO_NEXUS || dcp == 0)
			dp->d_conn = dcp;
		else
			dp->d_conn = dconnect(dcp->d_name, QUES);
	}
	return (dp);
}

void
init_dev(struct device *dp)
{

	dp->d_name = "OHNO!!!";
	dp->d_type = DEVICE;
	dp->d_conn = 0;
	dp->d_vec = 0;
	dp->d_addr = dp->d_pri = dp->d_flags = dp->d_dk = 0;
	dp->d_slave = dp->d_drive = dp->d_unit = UNKNOWN;
	if (machine == MACHINE_SUN2 || machine == MACHINE_SUN3
	    || machine == MACHINE_SUN4){
		dp->d_addr = UNKNOWN;
		dp->d_mach = dp->d_bus = 0;
	}
	if (machine == MACHINE_MIPSY || machine == MACHINE_MIPS){
		dp->d_addrmod = 0;
	}
	dp->d_init = 0;
}

/*
 * make certain that this is a reasonable type of thing to connect to a nexus
 */
void
check_nexus(struct device *dev, int num)
{

	switch (machine) {

	case MACHINE_VAX:
		if (!eq(dev->d_name, "uba") && !eq(dev->d_name, "mba"))
			yyerror("only uba's and mba's should be connected to the nexus");
		if (num != QUES)
			yyerror("can't give specific nexus numbers");
		break;

	case MACHINE_SUN:
		if (!eq(dev->d_name, "mb"))
			yyerror("only mb's should be connected to the nexus");
		break;

	case MACHINE_ROMP:
		if (!eq(dev->d_name, "iocc"))
			yyerror("only iocc's should be connected to the nexus");
		break;
        case MACHINE_SUN2:
		if (!eq(dev->d_name, "virtual") &&
		    !eq(dev->d_name, "obmem") &&
		    !eq(dev->d_name, "obio") &&
		    !eq(dev->d_name, "mbmem") &&
		    !eq(dev->d_name, "mbio") &&
		    !eq(dev->d_name, "vme16d16") &&
		    !eq(dev->d_name, "vme24d16")) {
			(void)sprintf(errbuf,
			    "unknown bus type `%s' for nexus connection on %s",
			    dev->d_name, machinename);
			yyerror(errbuf);
		}

	case MACHINE_MMAX:
		yyerror("don't grok 'nexus' on mmax -- try 'slot'.");
		break;
        case MACHINE_SUN3:
        case MACHINE_SUN4:
		if (!eq(dev->d_name, "virtual") &&
		    !eq(dev->d_name, "obmem") &&
		    !eq(dev->d_name, "obio") &&
		    !eq(dev->d_name, "mbmem") &&
		    !eq(dev->d_name, "mbio") &&
		    !eq(dev->d_name, "vme16d16") &&
		    !eq(dev->d_name, "vme24d16") &&
                    !eq(dev->d_name, "vme32d16") &&
		    !eq(dev->d_name, "vme16d32") &&
		    !eq(dev->d_name, "vme24d32") &&
		    !eq(dev->d_name, "vme32d32")) {
			(void)sprintf(errbuf,
			    "unknown bus type `%s' for nexus connection on %s",
			    dev->d_name, machinename);
			yyerror(errbuf);
		}
		break;
	case MACHINE_MIPSY:
	case MACHINE_MIPS:
		if (!eq(dev->d_name, "vme") && !eq(dev->d_name, "mbii"))
			yyerror("only vme's and mbii's should be connected to the nexus");
		if (num != QUES)
			yyerror("can't give specific nexus numbers");
		break;
	}
}

/*
 * make certain that this is a reasonable type of thing to connect to a slot
 */

void
check_slot(struct device *dev, int num)
{

	switch (machine) {

	case MACHINE_MMAX:
		if (!eq(dev->d_name, "emc"))
			yyerror("only emc's plug into backplane slots.");
		if (num == QUES)
			yyerror("specific slot numbers must be given");
		break;

	case MACHINE_SQT:
		if (!eq(dev->d_name, "mbad") &&
		    !eq(dev->d_name, "zdc") &&
		    !eq(dev->d_name, "sec")) {
			(void)sprintf(errbuf,
			    "unknown bus type `%s' for slot on %s",
			    dev->d_name, machinename);
			yyerror(errbuf);
		}
		break;

	default:
		yyerror("don't grok 'slot' for this machine -- try 'nexus'.");
		break;
	}
}

/*
 * Check system specification and apply defaulting
 * rules on root, argument, dump, and swap devices.
 */
void
checksystemspec(struct file_list *fl)
{
	char buf[BUFSIZ];
	register struct file_list *swap;
	int generic;

	if (fl == 0 || fl->f_type != SYSTEMSPEC) {
		yyerror("internal error, bad system specification");
		exit(1);
	}
	swap = fl->f_next;
	generic = swap && swap->f_type == SWAPSPEC && eq(swap->f_fn, "generic");
	if (fl->f_rootdev == NODEV && !generic) {
		yyerror("no root device specified");
		exit(1);
	}
	/*
	 * Default swap area to be in 'b' partition of root's
	 * device.  If root specified to be other than on 'a'
	 * partition, give warning, something probably amiss.
	 */
	if (swap == 0 || swap->f_type != SWAPSPEC) {
		dev_t dev;

		swap = newswap();
		dev = fl->f_rootdev;
		if (minor(dev) & DEV_MASK) {
			(void) sprintf(buf,
"Warning, swap defaulted to 'b' partition with root on '%c' partition",
				(minor(dev) & DEV_MASK) + 'a');
			yyerror(buf);
		}
		swap->f_swapdev =
		   makedev(major(dev), (minor(dev) &~ DEV_MASK) | ('b' - 'a'));
		swap->f_fn = devtoname(swap->f_swapdev);
		mkswap(fl, swap, 0);
	}
	/*
	 * Make sure a generic swap isn't specified, along with
	 * other stuff (user must really be confused).
	 */
	if (generic) {
		if (fl->f_rootdev != NODEV)
			yyerror("root device specified with generic swap");
		if (fl->f_argdev != NODEV)
			yyerror("arg device specified with generic swap");
		if (fl->f_dumpdev != NODEV)
			yyerror("dump device specified with generic swap");
		return;
	}
	/*
	 * Default argument device and check for oddball arrangements.
	 */
	if (fl->f_argdev == NODEV)
		fl->f_argdev = swap->f_swapdev;
	if (fl->f_argdev != swap->f_swapdev)
		yyerror("Warning, arg device different than primary swap");
	/*
	 * Default dump device and warn if place is not a
	 * swap area or the argument device partition.
	 */
	if (fl->f_dumpdev == NODEV)
		fl->f_dumpdev = swap->f_swapdev;
	if (fl->f_dumpdev != swap->f_swapdev && fl->f_dumpdev != fl->f_argdev) {
		struct file_list *p = swap->f_next;

		for (; p && p->f_type == SWAPSPEC; p = p->f_next)
			if (fl->f_dumpdev == p->f_swapdev)
				return;
		(void) sprintf(buf, "Warning, orphaned dump device, %s",
			"do you know what you're doing");
		yyerror(buf);
	}
}

/*
 * Verify all devices specified in the system specification
 * are present in the device specifications.
 */
void
verifysystemspecs(void)
{
	register struct file_list *fl;
	dev_t checked[50];
	register dev_t *pchecked = checked;

	for (fl = conf_list; fl; fl = fl->f_next) {
		if (fl->f_type != SYSTEMSPEC)
			continue;
		if (!finddev(fl->f_rootdev))
			deverror(fl->f_needs, "root");
		*pchecked++ = fl->f_rootdev;
		pchecked = verifyswap(fl->f_next, checked, pchecked);
#define	samedev(dev1, dev2) \
	((minor(dev1) &~ DEV_MASK) != (minor(dev2) &~ DEV_MASK))
		if (!alreadychecked(fl->f_dumpdev, checked, pchecked)) {
			if (!finddev(fl->f_dumpdev))
				deverror(fl->f_needs, "dump");
			*pchecked++ = fl->f_dumpdev;
		}
		if (!alreadychecked(fl->f_argdev, checked, pchecked)) {
			if (!finddev(fl->f_argdev))
				deverror(fl->f_needs, "arg");
			*pchecked++ = fl->f_argdev;
		}
	}
}

/*
 * Do as above, but for swap devices.
 */
dev_t *
verifyswap(struct file_list *fl, dev_t checked[], dev_t *pchecked)
{

	for (;fl && fl->f_type == SWAPSPEC; fl = fl->f_next) {
		if (eq(fl->f_fn, "generic"))
			continue;
		if (alreadychecked(fl->f_swapdev, checked, pchecked))
			continue;
		if (!finddev(fl->f_swapdev))
			fprintf(stderr,
			   "config: swap device %s not configured", fl->f_fn);
		*pchecked++ = fl->f_swapdev;
	}
	return (pchecked);
}

/*
 * Has a device already been checked
 * for it's existence in the configuration?
 */
int
alreadychecked(dev_t dev, dev_t list[], dev_t *last)
{
	register dev_t *p;

	for (p = list; p < last; p++)
		if (samedev(*p, dev))
			return (1);
	return (0);
}

void
deverror(const char *systemname, const char *devtype)
{

	fprintf(stderr, "config: %s: %s device not configured\n",
		systemname, devtype);
}

/*
 * Look for the device in the list of
 * configured hardware devices.  Must
 * take into account stuff wildcarded.
 */
/*ARGSUSED*/
int
finddev(__unused dev_t dev)
{

	/* punt on this right now */
	return (1);
}

