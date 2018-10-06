/******************************************************************************
*
* Name: Doug Morgan
*
* Date: 03/15/06
*
* File: prog3.l
*
* Description: This is a flex file that lexically analyzes a C program file
* and identifies lexical C words and characters and returns then to prog3.y 
* for syntactical analysis.
*****************************************************************************/

%{
#include<stdio.h>
#include<string.h>
#include "y.tab.h"

/*The current line number*/
int line_num = 1;

/*line_number placeholder*/
int line_curr = 1;

/*filename for current file scope read from cpp include statement*/
char *file = NULL;

int line_hold()
{
  return line_curr;
}

int line()
{
  return line_num;
}

char* file_name()
{
  return file;
}
%}

%x comment
%x string
%x include
%%

[ \t]  {}

\n     {line_num++;}

 /*CPP INCLUDE DIRECTIVE RULE*/
#   {BEGIN(include);}

<include>[ ] {}

<include>[0-9]+  {line_num = atoi(yytext) - 1;}

<include>[_a-zA-Z][_a-zA-Z0-9.]*  {file = strdup(yytext);
                                   BEGIN(INITIAL);}
                                    


 /*STRING RULE*/
\"   {yymore();
      BEGIN(string);}

 /*Any character except the '"' and the '\n'*/
<string>[^\\\"\n]   {yymore();}

<string>\n   {line_num++;
              yymore();}

 /*A quote escaped by a backslash*/
<string>\\\"   {yymore();}

 /*A backslash followed by anything not a '"'*/
<string>\\[^\"]   {yymore();}

<string>\"   {yylval.str = strdup(yytext);
              return STRING;
              BEGIN(INITIAL);}

 /*CHARACTER CONSTANT RULE*/
'[^']+'  {yylval.str = strdup(yytext);
         return CHAR;}

 /*KEYWORD RULES*/
"double"|"int"|"char"|"float"|"void" {yylval.str = strdup(yytext);
                                      return TYPE;}

"long"|"short"|"unsigned"|"signed" {yylval.str = strdup(yytext);
                                    return MODIFIER;}

"static" {yylval.str = strdup(yytext);
                       return STATIC;}

"enum"  {yylval.str = strdup(yytext);
         return ENUM;}

"typedef"  {yylval.str = strdup(yytext);
            return TYPEDEF;}

"union"|"struct"  {yylval.str = strdup(yytext);
                   return STRUCT;}

"const"  {yylval.str = strdup(yytext);
          return CONST;}

"goto"  {yylval.str = strdup(yytext);
         return GOTO;}

"sizeof"  {yylval.str = strdup(yytext);
           return SIZEOF;}

 /*C IDENTIFIER RULE*/
[_a-zA-Z][_a-zA-Z0-9]*   {yylval.str = strdup(yytext);
                          return C_ID;}

 /*BINARY INTEGER RULE*/
[01][01]*  {yylval.str = strdup(yytext);
                         return INT2;}

 /*OCTAL INTEGER RULE*/
0[0-7][0-7]*  {yylval.str = strdup(yytext);
               return INT8;}

 /*FLOAT RULE*/
[-+]?[0-9][0-9]*[.][0-9][0-9]*[Ee]?[-+]?[0-9]?[0-9]* {
  yylval.str = strdup(yytext);
  return FLOAT;}

 /*INTEGER INTEGER RULE*/
[-+]?[0-9][0-9]*  {yylval.str = strdup(yytext);
                return INT10;}

 /*HEXADECIMAL INTEGER RULE*/
0[xX][0-9A-Fa-f][0-9A-Fa-f]*  {yylval.str = strdup(yytext);
                               return INT16;}
  
 /*C characters*/
[{};.&,*+=//%=<>^|!~?:()-\[\]]  {return yytext[0];}

 /*COMMENT RULES*/
\/\*  {line_curr = line_num;
       yymore();
       BEGIN(comment);}

 /*anything but a '*' or '\n'*/
<comment>[^*\n]   {yymore();}

 /* '*'s not followed by a '/'*/
<comment>"*"[^*/\n]    {yymore();}

 /*newline character*/
<comment>\n  {line_num++;
              yymore();}

 /*one '*' and the closing '/'*/
<comment>"*""/"   {yylval.str = strdup(yytext);
                   BEGIN(INITIAL);
                   return COMMENT;}

 /*Unknown characters*/
. {yyerror("Illegal character\n");}
%%