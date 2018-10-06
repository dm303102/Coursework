/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

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
     C_ID = 258,
     STRING = 259,
     TYPE = 260,
     MODIFIER = 261,
     ENUM = 262,
     TYPEDEF = 263,
     STRUCTCONST = 264,
     GOTO = 265,
     SIZEOF = 266,
     INT2 = 267,
     INT8 = 268,
     INT16 = 269,
     COMMENT = 270,
     FLOAT = 271,
     CHAR = 272,
     INT10 = 273,
     CONST = 274,
     STRUCT = 275,
     STATIC = 276
   };
#endif
#define C_ID 258
#define STRING 259
#define TYPE 260
#define MODIFIER 261
#define ENUM 262
#define TYPEDEF 263
#define STRUCTCONST 264
#define GOTO 265
#define SIZEOF 266
#define INT2 267
#define INT8 268
#define INT16 269
#define COMMENT 270
#define FLOAT 271
#define CHAR 272
#define INT10 273
#define CONST 274
#define STRUCT 275
#define STATIC 276




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 23 "prog3.y"
typedef union YYSTYPE {
  char* str;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 122 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 44 "prog3.y"

#include <stdlib.h>
#include <stdio.h>
#include<string.h>

  char* scope = "GLOBAL";
  

/* Line 214 of yacc.c.  */
#line 141 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  44
/* YYNRULES -- Number of rules. */
#define YYNRULES  122
/* YYNRULES -- Number of states. */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
      35,    36,    22,    24,    37,    25,    40,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    26,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    34,    39,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    18,    21,    24,
      27,    30,    33,    35,    37,    39,    41,    43,    45,    47,
      49,    51,    53,    55,    57,    62,    64,    66,    69,    72,
      77,    81,    84,    87,    90,    92,    94,    96,    99,   102,
     105,   108,   112,   116,   119,   122,   125,   129,   131,   133,
     135,   137,   139,   143,   145,   147,   149,   151,   153,   155,
     157,   159,   161,   163,   169,   173,   175,   176,   187,   191,
     193,   194,   199,   202,   205,   207,   210,   212,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   237,   242,
     244,   245,   247,   248,   250,   251,   254,   257,   258,   262,
     265,   267,   270,   275,   278,   281,   284,   287,   291,   294,
     296,   300,   305,   310,   312,   315,   318,   321,   323,   324,
     328,   334,   337
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      43,     0,    -1,    46,    43,    -1,    65,    43,    -1,    73,
      43,    -1,    78,    43,    -1,    79,    43,    -1,    83,    43,
      -1,    45,    43,    -1,    58,    43,    -1,    84,    43,    -1,
      85,    43,    -1,    44,    -1,    46,    -1,    65,    -1,    73,
      -1,    78,    -1,    79,    -1,    83,    -1,    45,    -1,    58,
      -1,    84,    -1,    85,    -1,    15,    -1,    47,    51,    52,
      26,    -1,     3,    -1,    48,    -1,    50,     3,    -1,     3,
      49,    -1,    27,    18,    28,    49,    -1,    27,    18,    28,
      -1,    27,    28,    -1,    22,    50,    -1,    29,    50,    -1,
      22,    -1,    29,    -1,    30,    -1,    22,    30,    -1,    23,
      30,    -1,    24,    30,    -1,    25,    30,    -1,    31,    31,
      30,    -1,    32,    32,    30,    -1,    29,    30,    -1,    33,
      30,    -1,    34,    30,    -1,    52,    53,    54,    -1,    54,
      -1,    24,    -1,    25,    -1,    22,    -1,    23,    -1,    35,
      52,    36,    -1,    47,    -1,    55,    -1,    12,    -1,    13,
      -1,    18,    -1,    14,    -1,     4,    -1,    17,    -1,    16,
      -1,    56,    -1,     3,    35,    57,    36,    26,    -1,    52,
      37,    57,    -1,    52,    -1,    -1,    50,     5,     3,    35,
      60,    36,    38,    59,    63,    39,    -1,    61,    37,    60,
      -1,    61,    -1,    -1,    68,    69,    62,     3,    -1,    50,
       5,    -1,     5,    50,    -1,     5,    -1,    64,    63,    -1,
      64,    -1,    46,    -1,    65,    -1,    73,    -1,    78,    -1,
      79,    -1,    83,    -1,    45,    -1,    84,    -1,    85,    -1,
      56,    -1,    66,    47,    70,    26,    -1,    67,    68,    69,
       5,    -1,    21,    -1,    -1,    19,    -1,    -1,     6,    -1,
      -1,    51,    52,    -1,    51,    71,    -1,    -1,    38,    72,
      39,    -1,    55,    72,    -1,    55,    -1,    74,    26,    -1,
      74,    30,    52,    26,    -1,    20,    75,    -1,     3,    76,
      -1,    76,     3,    -1,     3,     3,    -1,    38,    77,    39,
      -1,    65,    77,    -1,    65,    -1,    47,    40,    47,    -1,
      47,    25,    32,    47,    -1,     8,    80,    81,    26,    -1,
      66,    -1,     7,    71,    -1,    20,    76,    -1,    82,     3,
      -1,    50,    -1,    -1,     3,     3,    26,    -1,     3,     3,
      30,    52,    26,    -1,     3,    41,    -1,    10,     3,    26,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    53,    53,    53,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    61,    65,    70,    74,    74,    76,    80,    83,
      86,    89,    93,    94,    95,    96,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   112,   113,   116,   117,
     118,   119,   122,   123,   124,   127,   129,   131,   133,   135,
     137,   139,   141,   145,   148,   148,   153,   152,   159,   159,
     160,   162,   165,   165,   165,   167,   167,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   183,   187,   190,
     191,   194,   195,   198,   199,   203,   204,   205,   209,   211,
     211,   215,   217,   221,   224,   225,   226,   229,   233,   233,
     237,   242,   251,   255,   255,   255,   258,   261,   261,   265,
     267,   272,   276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "C_ID", "STRING", "TYPE", "MODIFIER", 
  "ENUM", "TYPEDEF", "STRUCTCONST", "GOTO", "SIZEOF", "INT2", "INT8", 
  "INT16", "COMMENT", "FLOAT", "CHAR", "INT10", "CONST", "STRUCT", 
  "STATIC", "'*'", "'/'", "'+'", "'-'", "';'", "'['", "']'", "'&'", "'='", 
  "'<'", "'>'", "'^'", "'|'", "'('", "')'", "','", "'{'", "'}'", "'.'", 
  "':'", "$accept", "program", "end", "comment", "assignment", "variable", 
  "array_element", "array", "ptr_ref", "assign_op", "expression", "op1", 
  "term", "const", "function_call", "arguments", "function_dec", "@1", 
  "parameters", "parameter", "param_type", "statements", "statement", 
  "declaration", "modifiers", "mod_static", "mod_const", "mod_type", 
  "assign", "id_list", "list", "structure", "struct", "struct_def", 
  "struct_body", "struct_declarations", "struct_ref", "typedef", 
  "typedef_body", "typedef_id", "id_ref", "typedef_ref", "label", 
  "label_ref", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    42,    47,    43,    45,    59,    91,    93,    38,
      61,    60,    62,    94,   124,    40,    41,    44,   123,   125,
      46,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    45,    46,    47,    47,    47,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    57,    57,    59,    58,    60,    60,
      60,    61,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    71,    72,
      72,    73,    73,    74,    75,    75,    75,    76,    77,    77,
      78,    78,    79,    80,    80,    80,    81,    82,    82,    83,
      83,    84,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     2,     2,     4,
       3,     2,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     1,     0,    10,     3,     1,
       0,     4,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       0,     1,     0,     1,     0,     2,     2,     0,     3,     2,
       1,     2,     4,     2,     2,     2,     2,     3,     2,     1,
       3,     4,     4,     1,     2,     2,     2,     1,     0,     3,
       5,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
      90,    25,    90,     0,    23,     0,    89,    34,    35,     0,
      12,    90,    90,     0,    26,     0,    90,    90,     0,    92,
      90,     0,    90,    90,    90,    90,    90,     0,     0,   121,
      28,     0,     0,   113,   118,     0,     0,    90,   103,     0,
      32,    33,     1,     8,     2,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,    27,     0,     9,
       3,    25,    97,     0,    91,    94,     4,   101,     0,     5,
       6,     7,    10,    11,   119,     0,     0,    31,     0,   114,
     115,   117,     0,     0,   122,   106,   104,    90,     0,   105,
      37,    38,    39,    40,     0,    43,     0,     0,    44,    45,
     110,    25,    59,    55,    56,    58,    61,    60,    57,     0,
      53,     0,    47,    54,    62,     0,     0,     0,     0,    93,
       0,     0,     0,    30,     0,   100,     0,   112,   116,   108,
     107,   111,    41,    42,     0,     0,    50,    51,    48,    49,
      24,     0,    92,    95,    96,    87,    88,   102,   120,    29,
      99,    98,    65,     0,    52,    46,     0,    69,    94,     0,
       0,     0,    92,     0,    64,    63,    66,    68,    74,     0,
       0,    90,    73,    72,    71,    25,    83,    77,    86,     0,
      90,    78,    79,    80,    81,    82,    84,    85,    67,    75
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    30,    63,    56,
     152,   141,   112,   113,   114,   153,    16,   171,   156,   157,
     170,   179,   180,    17,    18,    19,   158,   120,   118,    79,
     126,    20,    21,    38,    39,    88,    22,    23,    34,    82,
      83,    24,    25,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -154
static const short yypact[] =
{
     286,     3,    56,     1,  -154,     7,  -154,    46,    46,    19,
    -154,   130,   154,   296,  -154,    53,   170,   186,    32,    22,
     202,    97,   218,   234,   250,   266,   282,   106,    18,  -154,
    -154,    31,    86,  -154,    46,    12,    11,    36,  -154,   123,
    -154,  -154,  -154,  -154,  -154,   109,   112,   125,    76,   126,
    -154,   122,   129,   128,   135,    32,    99,  -154,   163,  -154,
    -154,   140,   333,   168,  -154,   166,  -154,  -154,    99,  -154,
    -154,  -154,  -154,  -154,  -154,    99,   149,  -154,   336,  -154,
    -154,  -154,   153,   178,  -154,  -154,  -154,    -8,   143,  -154,
    -154,  -154,  -154,  -154,    32,  -154,   157,   158,  -154,  -154,
    -154,    65,  -154,  -154,  -154,  -154,  -154,  -154,  -154,    99,
    -154,   346,  -154,  -154,  -154,   160,   167,    69,   172,  -154,
     179,   351,   356,   140,   165,   336,   164,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,    99,   124,  -154,  -154,  -154,  -154,
    -154,    99,    -4,   361,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,    72,   173,  -154,  -154,   175,   156,   166,    99,
     187,   176,    -4,    42,  -154,  -154,  -154,  -154,    46,   199,
     213,   302,  -154,  -154,  -154,     2,  -154,  -154,  -154,   180,
      45,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -154,   321,  -154,  -153,  -138,   -16,  -154,   102,     0,   174,
     -47,  -154,    79,   -75,   -92,    68,  -154,  -154,    67,  -154,
    -154,    50,  -154,   -36,   230,  -154,   216,    83,  -154,   131,
     118,   -91,  -154,  -154,   105,   159,   -81,   -66,  -154,  -154,
    -154,   -61,   -51,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -110
static const short yytable[] =
{
      15,    87,    62,   125,    35,    27,    27,    40,    41,   111,
      36,    15,    15,     6,    85,    64,    15,    15,   176,    42,
      15,   121,    15,    15,    15,    15,    15,   176,   122,    28,
      28,  -109,   -70,   177,    81,    61,    76,   134,    84,   100,
     110,    64,   177,    29,    29,    37,    77,   168,   175,    37,
     125,    87,   110,     2,     7,     3,    57,     6,    58,   110,
       4,     8,   135,    31,     7,     5,     6,     7,     7,    78,
     143,     8,   101,   102,     8,     8,    32,     6,   131,   178,
     182,   103,   104,   105,   -76,   106,   107,   108,   178,   182,
     183,     7,    28,   110,   136,   137,   138,   139,     8,   183,
     134,   110,   101,   102,   109,   184,    93,    78,    94,   159,
     185,   103,   104,   105,   184,   106,   107,   108,   110,   185,
     186,     7,   187,    67,    37,   110,    89,    68,     8,   186,
     -19,   187,    74,     1,   109,   181,    75,    80,     2,    90,
       3,    86,    91,   110,   181,     4,   136,   137,   138,   139,
       5,     6,     7,    96,   -13,    92,    95,     1,    98,     8,
     154,    97,     2,   169,     3,    99,   115,    28,   172,     4,
     -20,    57,   119,     1,     5,     6,     7,   123,     2,   127,
       3,   128,   130,     8,   146,     4,   -14,   132,   133,     1,
       5,     6,     7,   162,     2,   142,     3,    93,   145,     8,
     134,     4,   -15,   151,   173,     1,     5,     6,     7,   160,
       2,   161,     3,   165,   166,     8,   174,     4,   -16,   188,
     155,     1,     5,     6,     7,   149,     2,   164,     3,   167,
     189,     8,    33,     4,   -17,    65,   117,     1,     5,     6,
       7,   163,     2,   150,     3,     0,   129,     8,   144,     4,
     -18,     0,     0,     1,     5,     6,     7,     0,     2,     0,
       3,     0,     0,     8,     0,     4,   -21,     0,     0,     1,
       5,     6,     7,     0,     2,     0,     3,     0,     0,     8,
       0,     4,   -22,     0,     0,     1,     5,     6,     7,     1,
       2,     0,     3,     0,     2,     8,     3,     4,     0,     0,
       0,     4,     5,     6,     7,   175,     5,     6,     7,     0,
       2,     8,     3,     0,     0,     8,     0,     4,    45,    46,
      47,    48,     5,     6,     7,    49,    50,    51,    52,    53,
      54,     8,    43,    44,     0,     0,    55,    59,    60,   124,
     102,    66,     0,    69,    70,    71,    72,    73,   103,   104,
     105,     0,   106,   107,   108,    45,    46,    47,   116,     0,
       0,     0,    49,    50,    51,    52,    53,    54,   136,   137,
     138,   139,   140,   136,   137,   138,   139,   147,   136,   137,
     138,   139,   148,   136,   137,   138,   139
};

static const short yycheck[] =
{
       0,    37,    18,    78,     3,     3,     3,     7,     8,    56,
       3,    11,    12,    21,     3,    19,    16,    17,   171,     0,
      20,    68,    22,    23,    24,    25,    26,   180,    75,    27,
      27,    39,    36,   171,    34,     3,    18,    35,    26,    55,
      56,    19,   180,    41,    41,    38,    28,     5,     3,    38,
     125,    87,    68,     8,    22,    10,     3,    21,     5,    75,
      15,    29,   109,     7,    22,    20,    21,    22,    22,    38,
     117,    29,     3,     4,    29,    29,    20,    21,    94,   171,
     171,    12,    13,    14,    39,    16,    17,    18,   180,   180,
     171,    22,    27,   109,    22,    23,    24,    25,    29,   180,
      35,   117,     3,     4,    35,   171,    30,    38,    32,    37,
     171,    12,    13,    14,   180,    16,    17,    18,   134,   180,
     171,    22,   171,    26,    38,   141,     3,    30,    29,   180,
       0,   180,    26,     3,    35,   171,    30,    32,     8,    30,
      10,    36,    30,   159,   180,    15,    22,    23,    24,    25,
      20,    21,    22,    31,     0,    30,    30,     3,    30,    29,
      36,    32,     8,   163,    10,    30,     3,    27,   168,    15,
       0,     3,     6,     3,    20,    21,    22,    28,     8,    26,
      10,     3,    39,    29,     5,    15,     0,    30,    30,     3,
      20,    21,    22,    37,     8,    35,    10,    30,    26,    29,
      35,    15,     0,    39,     5,     3,    20,    21,    22,    36,
       8,    36,    10,    26,    38,    29,     3,    15,     0,    39,
     141,     3,    20,    21,    22,   123,     8,   159,    10,   162,
     180,    29,     2,    15,     0,    19,    62,     3,    20,    21,
      22,   158,     8,   125,    10,    -1,    87,    29,   117,    15,
       0,    -1,    -1,     3,    20,    21,    22,    -1,     8,    -1,
      10,    -1,    -1,    29,    -1,    15,     0,    -1,    -1,     3,
      20,    21,    22,    -1,     8,    -1,    10,    -1,    -1,    29,
      -1,    15,     0,    -1,    -1,     3,    20,    21,    22,     3,
       8,    -1,    10,    -1,     8,    29,    10,    15,    -1,    -1,
      -1,    15,    20,    21,    22,     3,    20,    21,    22,    -1,
       8,    29,    10,    -1,    -1,    29,    -1,    15,    22,    23,
      24,    25,    20,    21,    22,    29,    30,    31,    32,    33,
      34,    29,    11,    12,    -1,    -1,    40,    16,    17,     3,
       4,    20,    -1,    22,    23,    24,    25,    26,    12,    13,
      14,    -1,    16,    17,    18,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    22,    23,
      24,    25,    26,    22,    23,    24,    25,    26,    22,    23,
      24,    25,    26,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     8,    10,    15,    20,    21,    22,    29,    43,
      44,    45,    46,    47,    48,    50,    58,    65,    66,    67,
      73,    74,    78,    79,    83,    84,    85,     3,    27,    41,
      49,     7,    20,    66,    80,     3,     3,    38,    75,    76,
      50,    50,     0,    43,    43,    22,    23,    24,    25,    29,
      30,    31,    32,    33,    34,    40,    51,     3,     5,    43,
      43,     3,    47,    50,    19,    68,    43,    26,    30,    43,
      43,    43,    43,    43,    26,    30,    18,    28,    38,    71,
      76,    50,    81,    82,    26,     3,    76,    65,    77,     3,
      30,    30,    30,    30,    32,    30,    31,    32,    30,    30,
      47,     3,     4,    12,    13,    14,    16,    17,    18,    35,
      47,    52,    54,    55,    56,     3,    25,    51,    70,     6,
      69,    52,    52,    28,     3,    55,    72,    26,     3,    77,
      39,    47,    30,    30,    35,    52,    22,    23,    24,    25,
      26,    53,    35,    52,    71,    26,     5,    26,    26,    49,
      72,    39,    52,    57,    36,    54,    60,    61,    68,    37,
      36,    36,    37,    69,    57,    26,    38,    60,     5,    50,
      62,    59,    50,     5,     3,     3,    45,    46,    56,    63,
      64,    65,    73,    78,    79,    83,    84,    85,    39,    63
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 23:
#line 66 "prog3.y"
    {printf("%s %s %s %d\n", scope, "COMMENT" , file_name(), line_hold());}
    break;

  case 24:
#line 71 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-3].str, scope, "LVAL" , file_name(), line());}
    break;

  case 27:
#line 76 "prog3.y"
    {yyval.str = yyvsp[0].str;
 printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "REF" , file_name(), line());}
    break;

  case 28:
#line 80 "prog3.y"
    {yyval.str = yyvsp[-1].str;}
    break;

  case 29:
#line 84 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-2].str, scope, "INT10" , file_name(), line());}
    break;

  case 30:
#line 87 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-1].str, scope, "INT10" , file_name(), line());}
    break;

  case 36:
#line 99 "prog3.y"
    {yyval.str = "=";}
    break;

  case 37:
#line 100 "prog3.y"
    {yyval.str = "*=";}
    break;

  case 38:
#line 101 "prog3.y"
    {yyval.str = "/=";}
    break;

  case 39:
#line 102 "prog3.y"
    {yyval.str = "+=";}
    break;

  case 40:
#line 103 "prog3.y"
    {yyval.str = "-=";}
    break;

  case 41:
#line 104 "prog3.y"
    {yyval.str = "<<";}
    break;

  case 42:
#line 105 "prog3.y"
    {yyval.str = ">>";}
    break;

  case 43:
#line 106 "prog3.y"
    {yyval.str = "&=";}
    break;

  case 44:
#line 107 "prog3.y"
    {yyval.str = "^=";}
    break;

  case 45:
#line 108 "prog3.y"
    {yyval.str = "|=";}
    break;

  case 48:
#line 116 "prog3.y"
    {yyval.str = "+";}
    break;

  case 49:
#line 117 "prog3.y"
    {yyval.str = "-";}
    break;

  case 50:
#line 118 "prog3.y"
    {yyval.str = "*";}
    break;

  case 51:
#line 119 "prog3.y"
    {yyval.str = "/";}
    break;

  case 55:
#line 128 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "INT2" , file_name(), line());}
    break;

  case 56:
#line 130 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "INT8" , file_name(), line());}
    break;

  case 57:
#line 132 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "INT10" , file_name(), line());}
    break;

  case 58:
#line 134 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "INT16" , file_name(), line());}
    break;

  case 59:
#line 136 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "STRING" , file_name(), line());}
    break;

  case 60:
#line 138 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "CHAR" , file_name(), line());}
    break;

  case 61:
#line 140 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[0].str, scope, "FLOAT" , file_name(), line());}
    break;

  case 66:
#line 153 "prog3.y"
    {scope = strdup(yyvsp[-4].str);}
    break;

  case 67:
#line 156 "prog3.y"
    {scope = "GLOBAL";}
    break;

  case 77:
#line 170 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 78:
#line 171 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 79:
#line 172 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 80:
#line 173 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 81:
#line 174 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 82:
#line 175 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 83:
#line 176 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 84:
#line 177 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 85:
#line 178 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 86:
#line 179 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 87:
#line 184 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-2].str, scope, "DECL" , file_name(), line());}
    break;

  case 89:
#line 190 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 90:
#line 191 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 91:
#line 194 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 92:
#line 195 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 93:
#line 198 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 94:
#line 199 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 95:
#line 203 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 96:
#line 204 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 97:
#line 205 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 98:
#line 209 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 101:
#line 216 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-1].str, scope, "STRUCT_DEF" , file_name(), line());}
    break;

  case 102:
#line 218 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-3].str, scope, "STRUCT_DEF" , file_name(), line());}
    break;

  case 103:
#line 221 "prog3.y"
    {yyval.str = yyvsp[0].str;}
    break;

  case 104:
#line 224 "prog3.y"
    {yyval.str = yyvsp[-1].str;}
    break;

  case 105:
#line 225 "prog3.y"
    {yyval.str = yyvsp[0].str;}
    break;

  case 106:
#line 226 "prog3.y"
    {yyval.str = yyvsp[0].str;}
    break;

  case 107:
#line 230 "prog3.y"
    {yyval.str = NULL;}
    break;

  case 110:
#line 237 "prog3.y"
    {strcat(yyval.str, yyvsp[-2].str);
                                    strcat(yyval.str, ".");
                                    strcat(yyval.str, yyvsp[0].str);
printf("%s.%s %s %s %s %d\n", yyvsp[-2].str, yyvsp[0].str, scope, "STRUCT_REF" , file_name(), line());}
    break;

  case 111:
#line 242 "prog3.y"
    {strcat(yyval.str, yyvsp[-3].str);
                             strcat(yyval.str, "-");
                             strcat(yyval.str, ">");
                             strcat(yyval.str, yyvsp[0].str);
printf("%s->%s %s %s %s %d\n", yyvsp[-3].str, yyvsp[0].str, scope, "STRUCT_REF" , file_name(), line());}
    break;

  case 112:
#line 252 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-1].str, scope, "TYPEDEF_DEF" , file_name(), line());}
    break;

  case 116:
#line 258 "prog3.y"
    {yyval.str = yyvsp[0].str;}
    break;

  case 119:
#line 266 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-2].str, scope, "TYPEDEF_REF" , file_name(), line());}
    break;

  case 120:
#line 268 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-4].str, scope, "TYPEDEF_REF" , file_name(), line());}
    break;

  case 121:
#line 272 "prog3.y"
    {
printf("%s %s %s %s %d\n", yyvsp[-1].str, scope, "LABEL_DEF" , file_name(), line());}
    break;

  case 122:
#line 277 "prog3.y"
    {printf("%s %s %s %s %d\n", yyvsp[-1].str, scope, "LABEL_REF" , file_name(), line());}
    break;


    }

/* Line 991 of yacc.c.  */
#line 1573 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 279 "prog3.y"

int yywrap(void)
{
  return 1;
}

yyerror(char *error_string)
{
  printf("Error : %s on line %d \n", error_string,line());
  exit(-1);
}

main(){
  yyparse();
}


