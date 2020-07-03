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

#ifndef __CERES_TOKENS_H
#define __CERES_TOKENS_H

typedef enum 
{
    NONE,
    /* Types*/
    BOOL, BYTE, CHAR, DOUBLE, FLOAT, 
    INT, LONG, SHARED, STRING, TUPLE, 
    /* Type modifiers */
    AUTO, CONST, LOCAL, POINTER, PROTECTED, PUBLIC, 
    REGISTER, STATIC, SIGNED, UNSIGNED,
    /* Statements */
    ASM, BREAK, CLASS, ELSE, FOR, IF, FUNCTION, 
    LOOP, RETURN, SCOPE, SUB, TYPE, WHILE,
    /* Operators */ 
    SIZEOF 
} __ceres_token;

#endif