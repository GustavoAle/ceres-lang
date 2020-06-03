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

#ifndef __CERES_AST_H
#define __CERES_AST_H

/** Define available token types
 *  CONSTANT - integers, floats, strings statically allocated
 *  IDENTIFIER - variable and function names
 *  OPERATOR - binary and unary operators, structures: if, for and while
 *
 *  CONSTANT and IDENTIFIER are terminal nodes.
 */
typedef enum
{
    CONSTANT,
    IDENTIFIER,
    OPERATOR
} __node_type;

/** Define available opcodes
 *  binary operators, assign operator, structure and statements
 *  note: there's no block statement opcode, every block statement is
 *  parsed as a tree of LIST_OP thus a block statement opcode would be redundant
 */
typedef enum
{
    /** Arithmetic */
    ADD_OP, SUB_OP, MUL_OP, DIV_OP,
    /** Bitwise */
    AND_OP, OR_OP, XOR_OP, NOT_OP, RSH_OP, LSH_OP,
    /** Logical */
    LAND_OP, LOR_OP, LNOT_OP,
    /** Statements */
    IF_STAT, FOR_STAT, WHILE_STAT, RETURN_STAT,
    /** Other operators*/
    ASSIGN_OP, CALL_OP, LIST_OP,
    /** Arithmetic assign operators*/
    AADD_OP, ASUB_OP, AMUL_OP, ADIV_OP,
    /** Bitwise assign operators*/
    AAND_OP, AOR_OP, AXOR_OP, ANOT_OP, ARSH_OP, ALSH_OP
} __ceres_opcode;

/** Basic AST node structure
 *  Pre-definition for cross reference
 */
typedef struct node_t node_t;

/** Constant node structure
 *  Pre-definition for cross reference
 */
typedef struct const_node_t const_node_t;

/** Identifier node structure
 *  Pre-definition for cross reference
 */
typedef struct id_node_t id_node_t;

/** Operator node structure
 *  Pre-definition for cross reference
 */
typedef struct op_node_t op_node_t;

struct const_node_t
{
    int value;
};

struct id_node_t
{
    char *name;
};

struct op_node_t
{
    __ceres_opcode opcode;
    node_t *right;
    node_t *left;
};

struct node_t
{
    __node_type type;
    union
    {
        const_node_t    constant;
        id_node_t       identifier;
        op_node_t       operator;
    };
};

/** Allocate a node and return it's pointer
 *  @return Pointer to the allocated node
 */
node_t *allocate_node();

/** Recursively free a node
 *  @param[_ptr] Pointer do node to be freed
 */
void free_node(node_t *_ptr);

/** Create a operator node
 *  @param[_opcode] operator opcode
 *  @param[_left] left leaf
 *  @param[_right] right lead
 *  @return Pointer to the created operator node
 */
node_t *new_operator_node(__ceres_opcode _opcode, node_t *_left, node_t *_right);

/** Create a constant node
 *  @param[_value] Constant's value
 *  @return Pointer to the created constant node
 */
node_t *new_constant_node(int _value);

/** Create a identifier node
 *  @param[_name] identifier name
 *
 *  Note: As a convention the _name pointer must be a copy of the original value
 *  @return Pointer to the created identifier node
 */
node_t *new_identifier_node(char *_name);

#endif
