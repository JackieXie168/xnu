/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "/Users/admin/Code/xnu/xnu-2422.115.4/SETUP/config/parser.y"
{
	char	*str;
	int	val;
	struct	file_list *file;
	struct	idlst *lst;
}
/* Line 1529 of yacc.c.  */
#line 186 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

