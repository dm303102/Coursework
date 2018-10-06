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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 23 "prog3.y"
typedef union YYSTYPE {
  char* str;
} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 82 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



