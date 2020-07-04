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

#include <stdlib.h>

#include <include/symbols.h>
#include <include/tokens.h>

symbol_t *allocate_symbol()
{
    symbol_t *new;

    new = (symbol_t*)malloc(sizeof(symbol_t));

    if(new == NULL){
        simple_error_wrapper("Allocation error, this is not supposed to happen\n");
    }

    return new;
}

void free_symbol(symbol_t *_ptr)
{
    if(_ptr != NULL) free(_ptr);
}

symbol_t *find_symbol(bstnode_t *_root, nfa256hash *_hash)
{
    symbol_t *_ptr;

    _ptr = find_bstnode(_root, _hash, compare_symbol_hash);

    return _ptr;
}

symbol_t *insert_symbol(bstnode_t *_root, nfa256hash *_hash)
{
    symbol_t *new;
    new = allocate_symbol();

    new->hash = _hash;
    new->type = NONE;

    insert_bstnode(_root, new, compare_symbol_hash);

    return new;
}

int compare_symbol(symbol_t *_symbola, symbol_t *_symbolb)
{
    if(_symbola == NULL || _symbolb == NULL)
    {
        simple_error_wrapper("One of passed symbols are NULL\n");
    }
    return compare_nfa256_hash(_symbola->hash, _symbolb->hash);
}

int compare_symbol_hash(nfa256hash *_hash, symbol_t *_symbol)
{
    if(_hash == NULL || _symbol == NULL )
    {
        simple_error_wrapper("One of passed args are NULL\n");
    }
    return compare_nfa256_hash(_hash, _symbol->hash);
}

//Quite useless
int typeof_symbol(symbol_t *_ptr)
{
    if(_ptr == NULL){
        return -1;    
    }
    return _ptr->type;
}