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

#include <ast/ast.h>
#include <stdlib.h>
#include <stdio.h>

/** Temporary*/
#define STDERR_FILE stdout

node_t *allocate_node()
{
    node_t *new;
    
    new = (node_t*)malloc(sizeof(node_t));
    
    if(new == NULL)
    {
        fprintf(STDERR_FILE,"Allocation error, this is not supposed to happen\n");
        fprintf(STDERR_FILE,"FILE: %s \tLINE: %d",__FILE__,__LINE__);
        exit(0);
    }

    return new;
}

void free_node(node_t *_ptr)
{
    if(_ptr == NULL){ return; }

    switch(_ptr->type)
    {
        case OPERATOR_TYPE:
            free_node(_ptr->operator.left);
            free_node(_ptr->operator.right);
            break;
        case IDENTIFIER_TYPE:
            /** Note that this line frees the memory allocated to hold
            the identifier name thus when assigning a value to name make
            a copy o the string instead of pointing to it with strdup*/
            free(_ptr->identifier.name);
            break;
        default:
            break;
    }
    free(_ptr);

}

node_t *new_operator_node(__ceres_opcode _opcode, node_t *_left, node_t *_right)
{
    node_t *new = allocate_node();

    new->type = OPERATOR_TYPE;

    /** Initialize the node with the passed arguments*/
    new->operator.left = _left;
    new->operator.right = _right;
    new->operator.opcode = _opcode;

    return new;
}

node_t *new_constant_node(int _value)
{
    node_t *new = allocate_node();

    new->type = CONSTANT_TYPE;

    /** Initialize the node with passed arguments*/
    new->constant.value = _value;

    return new;
}

node_t *new_identifier_node(char *_name)
{
    node_t *new = allocate_node();

    new->type = IDENTIFIER_TYPE;

    /** Initialize the node with passed argument*/
    new->identifier.name = _name;

    return new;
}
