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

#ifndef __CERES_BST_H
#define __CERES_BST_H

/******************************************************************************
 * Add here the headers for user-defined data types, 
 * then add the data def to anydata_t union
******************************************************************************/

#include <include/symbols.h>

/*****************************************************************************/

/** Binary search tree generic node
 *  It can store any data pointer  
 * */
typedef struct bstnode_t bstnode_t;

/** Generic data storage */
typedef union anydata_t anydata_t;

union anydata_t
{
    symbol_t *symbol;
    void *any;
};

struct bstnode_t
{
    bstnode_t *left;
    bstnode_t *right; 
    bstnode_t *subtree; /** Inner scope */
    anydata_t *data;
};

/** Allocate a BST node and return it's pointer
 *  @return Pointer to the allocated node
 */
astnode_t *allocate_node();

/** Inserts a BST node 
 * @param[_root] BST root 
 * @param[_data] Data pointer of the node to be inserted
 * @param[_cmpcallback] Function pointer to compare two user-defined data types
 * @return Pointer to the inserted node
 * */
bstnode_t *insert_bstnode(bstnode_t *_root, void *_data, int (*_cmpcallback)(void*,void*));

/** Find a bst node by its data (the search is not perform on subtrees)
 * @param[_root] BST root 
 * @param[_data] Data pointer of the node to be find
 * @param[_cmpcallback] Function pointer to compare two user-defined data types
 * @return Pointer to the found node or NULL if not found
 * */
bstnode_t *find_bstnode(bstnode_t *_root, void *_data, int (*_cmpcallback)(void*,void*));

/** Recursively free a tree 
 * @param[_root] Root of the tree to be freed
 * @param[_freecallback] Function pointer to perform a bstnode free
 * */ 
void free_bstnode_rec(bstnode_t *_root, void (*_freecallback)(void*));

/** Removes a bst node 
 * @brief Removes a bst node and then perform a 
 * proper linking between sucessor nodes.
 * Note that the node memory still allocated after removal.
 * @param[_node] Node to be deleted
 * @return Pointer to removed node or NULL if any error occur
 * */
bstnode_t *remove_bstnode(bstnode_t **_node);

/** Found and removes a bst node by its data
 * @param[_root] BST root
 * @param[_data] Data pointer of the node to be find
 * @param[_cmpcallback] Function pointer to compare two user-defined data types
 * @return Pointer to removed node or NULL if any error occur
 * */
bstnode_t *remove_bstnode_bydata(bstnode_t *_root, void *_data, int (*_cmpcallback)(void*,void*));



#endif