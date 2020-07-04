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

#include <include/hash.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/** Initial hash values */
#define BLOCK_A_INIT 0x442262bb
#define BLOCK_B_INIT 0x8f9224c5
#define BLOCK_C_INIT 0x88d36e0c
#define BLOCK_D_INIT 0x7579f789
#define BLOCK_E_INIT 0x7601d2fe
#define BLOCK_F_INIT 0x4d52f47f
#define BLOCK_G_INIT 0x92e8f968
#define BLOCK_H_INIT 0xa66c2d0c

nfa256hash new_nfa256_hash(char *_string)
{
    int _len = 0;
    nfa256hash _hash;

    /*
    _hash = (nfa256hash*)malloc(sizeof(nfa256hash));
    if(_hash == NULL){ return NULL; }
    */

    _hash.block_a = BLOCK_A_INIT;
    _hash.block_b = BLOCK_B_INIT;
    _hash.block_c = BLOCK_C_INIT;
    _hash.block_d = BLOCK_D_INIT;
    _hash.block_e = BLOCK_E_INIT;
    _hash.block_f = BLOCK_F_INIT;
    _hash.block_g = BLOCK_G_INIT;
    _hash.block_h = BLOCK_H_INIT;

    while(_string[_len]) _len++;
    if(_len == 0){ return _hash; }

    printf("String: %s(%d)\n",_string,_len);
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < _len; j++)
        {
            _hash.hash[i] ^= ((_string[j] & 0xF0) ^ 0xF0 ) | ((_string[j] & 0x0A) ^ 0x0A)  ; 
            _hash.hash[i] ^= _hash.hash[i] << 3 + _hash.hash[i] + _string[j];
        }
    }

    return;
}

int compare_nfa256_hash(nfa256hash *_hasha, nfa256hash *_hashb)
{
    int aux;

    for(aux = 0; aux < 32; aux++)
    {
        if(_hasha->hash[aux] > _hashb->hash[aux]){
            return 1;
        }else if(_hasha->hash[aux] < _hashb->hash[aux]){
            return -1;    
        }
    }

    /** Congratulations in 1 chance out of 2^256 your hashs are equal*/
    return 0;

    /*
    //Lemme comment my mistakes before taking the trash out
    int _bool = 1;
    
    if(!(_bool = _bool && (_hasha.block_a == _hashb.block_a))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_b == _hashb.block_b))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_c == _hashb.block_c))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_d == _hashb.block_d))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_e == _hashb.block_e))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_f == _hashb.block_f))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_g == _hashb.block_g))){ return 0; };
    if(!(_bool = _bool && (_hasha.block_h == _hashb.block_h))){ return 0; };

    return _bool;   
    */
}

