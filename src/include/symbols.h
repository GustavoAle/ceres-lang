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

#ifndef __CERES_SYMBOLS_H
#define __CERES_SYMBOLS_H

<<<<<<< HEAD:src/include/symbols.h
#include <include/hash.h>
#include <include/tokens.h>

=======
#include <symbols/hash.h>
#include <compiler/compiler.h>
>>>>>>> master:src/symbols/symbols.h
/*
typedef enum
{
    AUTO,
    BOOL,
    BYTE,
    CHAR,
    CLASS,
    DOUBLE,
    FLOAT,
    INT,
    LONG,
    SHARED,
    TUPLE,
    VOID
} __symbol_type;

typedef enum 
{
    CONST,
    FUNCTION,
    POINTER,
    REGISTER,
    SIGNED,
    STATIC,
    SUB,
    UNSIGNED
} __atrr_type;
*/

/** Struct that hold a symbol entry*/
typedef struct symbol_t symbol_t;

struct symbol_t 
{
    nfa256hash hash;
    __ceres_token type;
    __ceres_token attr;
    int offset;
};

/** Allocate a symbol and return it's pointer
 *  @return Pointer to the allocated node
 */
symbol_t *allocate_symbol();

/** Recussively free a symbol and it's childs
 *  @param[_ptr] Pointer to symbol to be freed
 */
void free_symbol(symbol_t *_ptr);

/** Find symbol based on it's hash
 * @param[_hash] Symbol hash
 * @return Pointer to symbol
 */
symbol_t *find_symbol(nfa256hash _hash);


#endif
