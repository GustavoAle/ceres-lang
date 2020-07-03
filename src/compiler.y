 /******************************************************************************

    Ceres Language - A language for RISC based processor
    Copyright (C) 2020  Gustavo Ale

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    GitHub: https://github.com/GustavoAle
    Email: gustavo.engca@gmail.com

 ******************************************************************************/

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
