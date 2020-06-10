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

number  [0-9]
alpha   [a-zA-Z]
hex     [a-fA-F0-9]
octa    [0-7]
bin     [0-1]

%{
#include <string.h>
#include <ast/ast.h>
#include <parser.tab.h>
%}

%%

"__asm"     { return ASM; }
"auto"      { return AUTO; }
"bool"      { return BOOL; }
"break"     { return BREAK; }
"byte"      { return BYTE; }
"const"     { return CONST; }
"else"      { return ELSE; }
"for"       { return FOR; }
"fun"       { return FUNCTION; }
"function"  { return FUNCTION; }
"if"        { return IF; }
"int"       { return INT; }
"loop"      { return LOOP; }
"mem"       { return POINTER; }
"pointer"   { return POINTER; }
"public"    { return PUBLIC; }
"reg"       { return REGISTER; }
"register"  { return REGISTER; }
"return"    { return RETURN; }
"scope"     { return SCOPE; }
"shared"    { return SHARED; }
"sizeof"    { return SIZEOF; }
"sub"       { return SUB; }
"tuple"     { return TUPLE; }
"var"       { return AUTO; }
"while"     { return WHILE; }

 /*treat string surronded by double quote*/
(\")[^(\")\n]*(\") {
    yylval.string_value = strdup(yytext);
    return STRING;
}

 /*treat string surronded by single quote*/
(\')[^(\')\n]*(\') {
    yylval.string_value = strdup(yytext);
    return STRING;
}

 /*ignore white spaces and tabs*/
[ \t] ;

 /*treat hexadecimal constants*/
[0'][xX]{hex}+ {
    yylval.const_value = (int)strtol(yytext+2,NULL,16);
    return CONSTANT;
}

 /*treat binary constants*/
[0']b{bin}+ {
    yylval.const_value = (int)strtol(yytext+2,NULL,2);
    return CONSTANT;
}

 /*treat octal constants*/
[0']{octa}+ {
    yylval.const_value = (int)strtol(yytext+1,NULL,8);
    return CONSTANT;
}

{alpha}({number}|{alpha})* {
    yylval.symbol_name = strdup(yytext);
    return IDENTIFIER;
}

%%
