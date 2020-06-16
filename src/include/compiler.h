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

#ifndef __CERES_COMPILER_H
#define __CERES_COMPILER_H

/** yylex function
 * @brief Get current char, count current line 
 * and column then return the current char 
 * @return Current char from file SOURCE_INPUT 
*/
int yylex();

/** yyerror function 
 * @brief Print a error message when a parsing error occurs
 * */
void yyerror();

#endif