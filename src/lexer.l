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
%}

%%

"if"        { return IF; }
"else"      { return ELSE; }
"for"       { return FOR; }
"while"     { return WHILE; }
"loop"      { return LOOP; }
"break"     { return BREAK; }
"reg"       { return REGISTER; }
"sub"       { return SUB; }
"return"    { return RETURN; }
"auto"      { return AUTO; }
"int"       { return INT; }
"byte"      { return BYTE; }
"bool"      { return BOOL; }
"mem"       { return POINTER; }
"pointer"   { return POINTER; }
"shared"    { return SHARED; }
"tuple"     { return STRUCT; }

 /*treat string surronded by double quote*/
(\")[^(\")\n]*(\") {
    yyval.string_value = strdup(yytext);
    return STRING;
}

 /*treat string surronded by single quote*/
(\')[^(\')\n]*(\') {
    yyval.string_value = strdup(yytext);
    return STRING;
}

 /*ignore white spaces and tabs*/
[ \t] ;

 /*treat hexadecimal constants*/
[0'][xX]{hex}+ {
    yyval.const_value = (int)strtol(yytext,NULL,16);
    return CONSTANT;
}

 /*treat binary constants*/
[0']b{bin}+ {
    yyval.const_value = (int)strtol(yytext+2,NULL,2);
    return CONSTANT;
}

 /*treat octal constants*/
[0']{octa}+ {
    yyval.const_value = (int)strtol(yytext,NULL,8);
    return CONSTANT;
}



%%
