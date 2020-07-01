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

#include <include/bst.h>
#include <include/hash.h>
#include <include/tokens.h>

/** Struct that hold a symbol entry*/
typedef struct symbol_t symbol_t;

struct symbol_t 
{
    nfa256hash *hash;
    __ceres_token type;
    __ceres_token attr;
    int offset;
};

/** Allocate a symbol and return it's pointer
 *  @return Pointer to the allocated node
 */
symbol_t *allocate_symbol();

/** Free a symbol 
 *  @param[_ptr] Pointer to symbol to be freed
 */
void free_symbol(symbol_t *_ptr);

/** Find symbol based on it's hash
 * @param[_hash] Symbol hash
 * @return Pointer to symbol or NULL if not found
 */
symbol_t *find_symbol(bstnode_t *_root, nfa256hash *_hash);

/** Insert symbol on symbols tree
 * @param[_hash] Hash pointer
 * @return Pointer to the inserted symbol
 */
symbol_t *insert_symbol(bstnode_t *_root,nfa256hash *_hash);

/** Symbols tree analogue to strcmp 
 * Compare two symbols and return if they are equal, less than or greater than
 * @param[_symbola] First symbol
 * @param[_symbolb] Second symbol
 * @return  <0 if _symbola < _symbolb
 *           0 if _symbola == _symbolb
 *          >0 if _symbola > _symbolb 
 * */ 
int compare_symbol(symbol_t *_symbola, symbol_t *_symbolb);

/** Compare symbol hash with the given has and return if 
 * they are equal, less than or greater than
 * @param[_hash] Hash to compare
 * @param[_symbol] Symbol pointer
 * @return  <0 if _hash < _symbol->hash
 *           0 if _hash == _symbol->hash
 *          >0 if _hash > _symbol->hash
 * */ 
int compare_symbol_hash(nfa256hash *_hash, symbol_t *_symbol);

/** Get the symbol type 
 * @param[_ptr] Symbol pointer
 * @return Symbol type integer enum. See __ceres_token (include/tokens.h)
*/
int typeof_symbol(symbol_t *_ptr);

#endif
