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
    CONSTANT_TYPE,
    IDENTIFIER_TYPE,
    OPERATOR_TYPE
} __astnode_type;

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
    IF_STAT, ELSE_STAT, FOR_STAT, WHILE_STAT, RETURN_STAT,
    /** Other operators*/
    LOOP_OP, BREAK_OP,
    ASSIGN_OP, CALL_OP, LIST_OP,
    /** Arithmetic assign operators*/
    AADD_OP, ASUB_OP, AMUL_OP, ADIV_OP,
    /** Bitwise assign operators*/
    AAND_OP, AOR_OP, AXOR_OP, ANOT_OP, ARSH_OP, ALSH_OP
} __ceres_opcode;

/** Basic AST node structure
 *  Pre-definition for cross reference
 */
typedef struct astnode_t astnode_t;

/** Constant node structure
 *  Pre-definition for cross reference
 */
typedef struct const_astnode_t const_astnode_t;

/** Identifier node structure
 *  Pre-definition for cross reference
 */
typedef struct id_astnode_t id_astnode_t;

/** Operator node structure
 *  Pre-definition for cross reference
 */
typedef struct op_astnode_t op_astnode_t;

struct const_astnode_t
{
    int value;
};

struct id_astnode_t
{
    char *name;
};

struct op_astnode_t
{
    __ceres_opcode opcode;
    astnode_t *right;
    astnode_t *left;
};

struct astnode_t
{
    __astnode_type type;
    union
    {
        const_astnode_t    constant;
        id_astnode_t       identifier;
        op_astnode_t       operator;
    };
};

/** Allocate a node and return it's pointer
 *  @return Pointer to the allocated node
 */
astnode_t *allocate_node();

/** Recursively free a node
 *  @param[_ptr] Pointer to node to be freed
 */
void free_node(astnode_t *_ptr);

/** Create a operator node
 *  @param[_opcode] operator opcode
 *  @param[_left] left leaf
 *  @param[_right] right lead
 *  @return Pointer to the created operator node
 */
astnode_t *new_operator_node(__ceres_opcode _opcode, astnode_t *_left, astnode_t *_right);

/** Create a constant node
 *  @param[_value] Constant's value
 *  @return Pointer to the created constant node
 */
astnode_t *new_constant_node(int _value);

/** Create a identifier node
 *  @param[_name] identifier name
 *
 *  Note: As a convention the _name pointer must be a copy of the original value
 *  @return Pointer to the created identifier node
 */
astnode_t *new_identifier_node(char *_name);

#endif
