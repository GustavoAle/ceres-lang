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
#include "ast/ast.h"
%}

%union {
    int const_value;
    char *string_value;
    char *symbol_name;
    node_t *ast_node;
}

%token <const_value> CONSTANT_T
%token <symbol_name> IDENTIFIER_T
%token <string_value> STRING
%type <ast_node> expr stat stat_list

%token IF
%token ELSE
%token FOR
%token WHILE
%token LOOP
%token BREAK
%token REGISTER
%token SUB
%token RETURN
%token AUTO
%token INT
%token BYTE
%token BOOL
%token POINTER
%token SHARED
%token TUPLE



%%

program:
   ;

%%
