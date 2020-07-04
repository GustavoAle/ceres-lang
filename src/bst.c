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

#include <include/bst.h>
#include <include/error.h>

bstnode_t *allocate_bstnode()
{
    bstnode_t *new;
    
    new = (bstnode_t*)malloc(sizeof(bstnode_t));
    
    if(new == NULL)
    {
        simple_error_wrapper("Allocation error, this is not supposed to happen\n");
        /*fprintf(STDERR_FILE,"Allocation error, this is not supposed to happen\n");
        fprintf(STDERR_FILE,"FILE: %s \tLINE: %d",__FILE__,__LINE__);
        exit(0);*/
    }
    new->right = NULL;
    new->left = NULL;
    new->subtree = NULL;
    new->data = NULL;

    return new;
}

bstnode_t *insert_bstnode(bstnode_t *_root, void *_data, int (*_cmpcallback)(void*,void*))
{
    int res;
    bstnode_t *aux;
    bstnode_t *new;

    new = allocate_bstnode();

    new->data = _data;

    aux = _root;
    while(aux != NULL)
    {
        if(res = _cmpcallback(_data,aux->data))
        {
            if(res < 0)
            { 
                if(aux->left != NULL){
                    /* Inner ode, still searching*/
                    aux = aux->left;
                }else{
                    /* Leaf node, point to node and exit loop*/
                    aux->left = new;
                    break;
                }

            }else{ 

                if(aux->right != NULL){
                    /* Inner node, still searching*/
                    aux = aux->right;
                }else{
                    /* Leaf node, point to node and exit loop*/
                    aux->right = new;
                    break;
                }    
            }
        }else{
            /* This is not supposed to happen */
            simple_error_wrapper("\nBST Node already exist");
            break;
        }
    }

    return new;
}

bstnode_t *find_bstnode(bstnode_t *_root, void *_data, int (*_cmpcallback)(void*,void*))
{
    int res;
    bstnode_t *aux;

    aux = _root;
    while(aux != NULL)
    {
        if(res = _cmpcallback(_data,aux->data))
        {
            if(res < 0)
            { 
                aux = aux->left;
            }else{ 
                aux = aux->right; 
            }
        }else{
            break;
        }
    }

    return aux;
}

void free_bstnode_rec(bstnode_t *_root, void (*_freecallback)(void*))
{
    if(_root == NULL) return;

    /** @TBI Change to non-recursive traversal*/ 
    free_bstnode_rec(_root->subtree,_freecallback);
    free_bstnode_rec(_root->right,_freecallback);
    free_bstnode_rec(_root->left,_freecallback);

    _freecallback(_root->data);

}

// @TBR Review this thing
bstnode_t *remove_bstnode(bstnode_t **_node)
{
    bstnode_t *bkp = *_node;
    
    if(bkp->left)
    {
        if(bkp->right)
        {
            //find sucessor
            bstnode_t *sucessor, *parent;

            parent = bkp;
            sucessor = bkp->right;

            while(sucessor->left != NULL)
            {
                parent = sucessor;
                sucessor = sucessor->left;
            }

            if(parent != bkp){
                parent->left = sucessor->right;
            }
            
            sucessor->right = bkp->right;
            sucessor->left = bkp->left;
            *_node = sucessor;

        }else{
            *_node = bkp->left;
        }
    }else{
        /* if empty bkp->right must be NULL too
        */
        *_node = bkp->right;
    }

    return bkp;
}

bstnode_t *remove_bstnode_bydata(bstnode_t *_root, void *_data, int (*_cmpcallback)(void*,void*))
{
    bstnode_t *aux;
    aux = find_bstnode(_root,_data,_cmpcallback);
    return remove_bstnode(aux);
}
