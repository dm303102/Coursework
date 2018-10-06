/******************************************************************************
*
* Name: Doug Morgan
*
* Date: 03/15/06
*
* File: prog3.y
*
* Description: This is a yacc file that analyzes the syntax of C file and 
* recognizes binary, octal, decimal and hexadecimal integers, character, string,
* and float constants, and varaible declarations, reference and assignments 
* involving these. It also recognizes label, struct and typedef definitions and
* references. It outputs these patterns in the following format:
*
* lexicaltext function_name(scope) descriptive_parameter filename line_number
* 
* Note: For some reason I could not figure out, I got a bunch of shift/reduce
* errors when trying to optionally have a refernced type in a function definition.
* The only thing that worked was to match at least one refernce(* or &) only at
* the beginning of the type keyword. It is in the FUNCTION RULES section
*****************************************************************************/

%union{
  char* str;
}

%token C_ID STRING TYPE MODIFIER ENUM TYPEDEF STRUCTCONST GOTO SIZEOF
%token INT2 INT8 INT16 COMMENT FLOAT CHAR INT10 CONST STRUCT STATIC

%type<str> C_ID STRING TYPE MODIFIER ENUM TYPEDEF STRUCTCONST GOTO SIZEOF
%type<str> INT2 INT8 INT16 COMMENT FLOAT CHAR INT10 variable assign_op
%type<str> CONST STRUCT array_element op1 const STATIC mod_static
%type<str> function_call statements
%type<str> statement structure declaration struct_ref typedef typedef_ref
%type<str> modifiers mod_const mod_type assign id_list list struct_def
%type<str> struct_body struct_declarations typedef_body label_ref
%type<str> comment struct typedef_id

%left '*' '/' 
%left '+' '-'

%start program

%{
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

  char* scope = "GLOBAL";
  %}
%%
 /*PROGRAM SYNTAX*/
program : assignment program | declaration program
| structure program | struct_ref program | typedef program
| typedef_ref program | comment program
| function_dec program | label program | label_ref program | end
;

end : assignment | declaration | structure | struct_ref
| typedef | typedef_ref | comment | function_dec | label
| label_ref
;

 /*COMMENTS*/
comment : COMMENT 
  {printf("%s %s %s %d\n", scope, "COMMENT" , file_name(), line_hold());}
;
 
 /*VARIABLE ASSIGNMENT*/
assignment : variable assign_op expression ';'
{printf("%s %s %s %s %d\n", $1, scope, "LVAL" , file_name(), line());}
;

variable : C_ID | array_element

| ptr_ref C_ID {$$ = $2;
 printf("%s %s %s %s %d\n", $2, scope, "REF" , file_name(), line());}
;

array_element : C_ID array {$$ = $1;}
;

array : '[' INT10 ']' array 
  {printf("%s %s %s %s %d\n", $2, scope, "INT10" , file_name(), line());}

| '[' INT10 ']' 
{printf("%s %s %s %s %d\n", $2, scope, "INT10" , file_name(), line());}

| '[' ']'
;

 /*POINTER AND REFERENCE CONVENTIONS*/
ptr_ref : '*' ptr_ref
| '&' ptr_ref
| '*'
| '&'
;

assign_op : '=' {$$ = "=";}
| '*' '=' {$$ = "*=";}
|  '/' '=' {$$ = "/=";}
|  '+' '=' {$$ = "+=";}
| '-' '=' {$$ = "-=";}
|  '<' '<' '=' {$$ = "<<";}
|  '>' '>' '=' {$$ = ">>";}
|  '&' '=' {$$ = "&=";}
| '^' '=' {$$ = "^=";}
| '|' '=' {$$ = "|=";}
;

 /*C EXPRESSION(precedence in delaration)*/
expression : expression op1 term
| term
;

op1 : '+' {$$ = "+";}
| '-' {$$ = "-";}
|'*' {$$ = "*";}
| '/' {$$ = "/";}
;

term : '(' expression ')'
| variable
| const
;

const : INT2 
  {printf("%s %s %s %s %d\n", $1, scope, "INT2" , file_name(), line());}
| INT8 
  {printf("%s %s %s %s %d\n", $1, scope, "INT8" , file_name(), line());}
| INT10 
  {printf("%s %s %s %s %d\n", $1, scope, "INT10" , file_name(), line());}
| INT16 
  {printf("%s %s %s %s %d\n", $1, scope, "INT16" , file_name(), line());}
| STRING 
  {printf("%s %s %s %s %d\n", $1, scope, "STRING" , file_name(), line());}
| CHAR
  {printf("%s %s %s %s %d\n", $1, scope, "CHAR" , file_name(), line());}
| FLOAT 
  {printf("%s %s %s %s %d\n", $1, scope, "FLOAT" , file_name(), line());}
| function_call
;

 /*FUNCTION RULES*/
function_call : C_ID '(' arguments ')' ';'
;

arguments : expression ',' arguments | expression
;

 /*removing the ptr_ref will give shift/reduce errors ???*/
function_dec : ptr_ref TYPE C_ID '(' parameters ')' '{' 
{scope = strdup($3);}

statements '}'
{scope = "GLOBAL";}
;

parameters : parameter ',' parameters | parameter
|;

parameter : mod_const mod_type param_type C_ID
;

param_type : ptr_ref TYPE | TYPE ptr_ref | TYPE;

statements : statement statements | statement
;

statement : assignment {$$ = NULL;}
| declaration {$$ = NULL;}
| structure {$$ = NULL;}
| struct_ref {$$ = NULL;}
| typedef {$$ = NULL;}
| typedef_ref {$$ = NULL;}
| comment {$$ = NULL;}
| label {$$ = NULL;}
| label_ref {$$ = NULL;}
| function_call {$$ = NULL;}
;

 /*DECLARATION RULES*/
declaration : modifiers variable assign ';'
{printf("%s %s %s %s %d\n", $2, scope, "DECL" , file_name(), line());}
;

modifiers : mod_static mod_const mod_type TYPE
; 

mod_static : STATIC {$$ = NULL;}
| {$$ = NULL;}
;

mod_const : CONST {$$ = NULL;}
| {$$ = NULL;}
;

mod_type : MODIFIER {$$ = NULL;}
| {$$ = NULL;}
;

 /*optional assignment for declaration*/
assign : assign_op expression {$$ = NULL;}
| assign_op id_list {$$ = NULL;}
| {$$ = NULL;}
;

 /*ENUM OR ARRAY ASSIGNMENT*/
id_list : '{' list '}' {$$ = NULL;}

list : const list | const
;

 /*STRUCT RULES*/
structure : struct ';'
{printf("%s %s %s %s %d\n", $1, scope, "STRUCT_DEF" , file_name(), line());}
| struct '=' expression ';'
{printf("%s %s %s %s %d\n", $1, scope, "STRUCT_DEF" , file_name(), line());}
;

struct : STRUCT struct_def {$$ = $2;}
;

struct_def : C_ID struct_body {$$ = $1;} 
| struct_body C_ID {$$ = $2;}
| C_ID C_ID {$$ = $2;}
;

struct_body : '{' struct_declarations '}'
{$$ = NULL;}
;

struct_declarations : declaration struct_declarations | declaration
;

 /*STRUCTURE REFERENCE*/
struct_ref : variable '.' variable {strcat($$, $1);
                                    strcat($$, ".");
                                    strcat($$, $3);
printf("%s.%s %s %s %s %d\n", $1, $3, scope, "STRUCT_REF" , file_name(), line());}

| variable '-' '>' variable {strcat($$, $1);
                             strcat($$, "-");
                             strcat($$, ">");
                             strcat($$, $4);
printf("%s->%s %s %s %s %d\n", $1, $4, scope, "STRUCT_REF" , file_name(), line());}
;


 /*TYPEDEF RULES*/
typedef : TYPEDEF typedef_body typedef_id ';'
{printf("%s %s %s %s %d\n", $3, scope, "TYPEDEF_DEF" , file_name(), line());}
;

typedef_body : modifiers | ENUM id_list | STRUCT struct_body
;

typedef_id : id_ref C_ID {$$ = $2;}
;

id_ref : ptr_ref |
;

 /*TYPEDEF REFERENCE*/
typedef_ref : C_ID C_ID ';' 
{printf("%s %s %s %s %d\n", $1, scope, "TYPEDEF_REF" , file_name(), line());}
| C_ID C_ID '=' expression ';'
{printf("%s %s %s %s %d\n", $1, scope, "TYPEDEF_REF" , file_name(), line());}
;

 /*LABEL RULES*/
label : C_ID ':' {
printf("%s %s %s %s %d\n", $1, scope, "LABEL_DEF" , file_name(), line());}
;

label_ref : GOTO C_ID ';' 
{printf("%s %s %s %s %d\n", $2, scope, "LABEL_REF" , file_name(), line());}
;
%%
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

