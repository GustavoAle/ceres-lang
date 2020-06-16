/******************************************************************************

   NFA-256 Hash Function
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
#ifndef __NFA256_HASH
#define __NFA256_HASH

#include <stdint.h>

typedef union nfa256hash_u nfa256hash;

union nfa256hash_u {
    struct {
        uint32_t block_a;
        uint32_t block_b;
        uint32_t block_c;
        uint32_t block_d;
        uint32_t block_e;
        uint32_t block_f;
        uint32_t block_g; 
        uint32_t block_h; 
    };
    char hash[32];
};

/** Create a nfa-256 hash based on _string and return it's value
 * @param[_string] String to generate the hash
 * @return NFA-256 hash
 * */ 
nfa256hash new_nfa256_hash(char *_string);
int compare_nfa256_hash(nfa256hash _hasha, nfa256hash _hashb);

#endif