%{
#include <include/ast.h>
#include <include/tokens.h>
#include <include/compiler.h>

%}

%union {
    int int_value;
    long long_value;
    float float_value;
    double double_value;
    char *string_value;
    void *pointer_value;
    char *symbol_name;
    astnode_t *ast_node;
}

%token <int_value> INT_CONSTANT
%token <long_value> LONG_CONSTANT
%token <float_value> FLOAT_CONSTANT
%token <double_value> DOUBLE_CONSTANT
%token <ptr_value> PTR_CONSTANT

%token <symbol_name> IDENTIFIER
%token <string_value> STRING_LITERAL
%type <ast_node> expr stat stat_list

 /*
%token AUTO BOOL BYTE DOUBLE FLOAT INT LONG
%token CONST UNSIGNED SIGNED PUBLIC STATIC REGISTER POINTER
%token ELSE IF FOR BREAK LOOP WHILE
%token ASM FUNCTION RETURN SCOPE SUB
%token SHARED TUPLE TYPE
%token SIZEOF
 */

%%

program:
   ;

%%

