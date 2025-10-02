#include <stdio.h>
#include <stdlib.h>
#include "code_generator.h"
#include <string.h>
#include <stdbool.h>
#include "../helper/helper.h"
#include "../symbol_table/table.h"

reg_index current_register = -1;
int last_used_label = -1;
int stack_top = 4095;

reg_index getReg()
{
    return ++current_register;
}

reg_index freeReg()
{
    return --current_register;
}

int getLabel()
{
    return ++last_used_label;
}

reg_index codegen(tnode *t, int startLabel, int endLabel)
{
    if (t == NULL)
    {
        return current_register;
    }
    if (isOperatorNode(t))
    {
        if (isAssignmentNode(t))
        {
            reg_index r = codegen_evaluate_expression(t->right);
            tnode *leftNode = t->left;
            // Assignment to array
            if (isArrayNode(leftNode))
            {
                reg_index binding = codegen_array(leftNode);
                codegen_store_in_stack_with_registers(r, binding);
                return current_register;
            }
            // Assignment to pointer
            else if (isAccessNode(leftNode))
            {
                // TODO:
                Gsymbol *g = Lookup(leftNode->left->varname);
                int binding = g->binding;
                reg_index p = codegen_read_from_stack(binding);
                codegen_store_in_stack_with_registers(r, p);
                freeReg();
                return current_register;
            }
            // Assignment to variable
            else
            {
                Gsymbol *g = Lookup(leftNode->varname);
                int startOffset = g->binding;
                codegen_store_in_stack(r, startOffset);
                return current_register;
            }
        }
        else if (isArithmeticNode(t) || isRelationalNode(t))
        {
            reg_index r = codegen_evaluate_expression(t);
            freeReg();
            return current_register;
        }
    }
    else if (isReadNode(t))
    {
        if (isArrayNode(t->left))
        {
            tnode *arrayNode = t->left;
            reg_index r = codegen_array(arrayNode);
            codegen_read_to_register(r);
        }
        else
        {
            // Get symbol table entry for the variable
            Gsymbol *g = Lookup(t->left->varname);
            // Get starting offset of the variable
            int startOffset = g->binding;

            codegen_read_to_address(startOffset);
        }
        return current_register;
    }
    else if (isWriteNode(t))
    {
        reg_index r;
        // if expression is inside write()
        if (isOperatorNode(t->left))
        {
            r = codegen_evaluate_expression(t->left);
        }
        // array is inside write()
        else if (isArrayNode(t->left))
        {
            tnode *arrayNode = t->left;
            r = codegen_array(arrayNode);
            r = codegen_read_from_stack_with_register(r);
        }
        // variable is inside write()
        else if (isLeafNode(t->left) && t->left->varname != NULL)
        {
            Gsymbol *g = Lookup(t->left->varname);

            int offset = g->binding;
            r = codegen_read_from_stack(offset);
        }
        // number is put inside write
        else if (isLeafNode(t->left) && t->left->type == TYPE_INT)
        {
            r = getReg();
            codegen_set_int_value_to_register(r, t->left->val);
        }
        // string is put inside write
        else if (isLeafNode(t->left) && t->left->type == TYPE_STR)
        {
            r = getReg();
            codegen_set_str_value_to_register(r, t->left->strval);
        }
        codegen_print_register(r);
        return current_register;
    }
    else if (isIfElseNode(t))
    {
        if (t->right != NULL)
        {
            int elseLabel = getLabel();
            int finishLabel = getLabel();
            reg_index r = codegen_evaluate_expression(t->left);
            codegen_jump_to_label_if_zero(r, elseLabel);
            freeReg();
            codegen(t->middle, startLabel, endLabel);
            codegen_jump_to_label(finishLabel);
            codegen_label_definition(elseLabel);
            codegen(t->right, startLabel, endLabel);
            codegen_label_definition(finishLabel);
        }
        else
        {
            int finishLabel = getLabel();
            reg_index r = codegen_evaluate_expression(t->left);
            codegen_jump_to_label_if_zero(r, finishLabel);
            codegen(t->middle, startLabel, endLabel);
            codegen_label_definition(finishLabel);
        }
        return current_register;
    }
    else if (isWhileNode(t))
    {
        int start_label = getLabel();
        int end_label = getLabel();
        codegen_label_definition(start_label);
        reg_index r = codegen_evaluate_expression(t->left);
        codegen_jump_to_label_if_zero(r, end_label);
        codegen(t->right, start_label, end_label);
        codegen_jump_to_label(start_label);
        codegen_label_definition(end_label);
        return current_register;
    }
    else if (isBreakNode(t))
    {
        codegen_jump_to_label(endLabel);
        return current_register;
    }
    else if (isContinueNode(t))
    {
        codegen_jump_to_label(startLabel);
        return current_register;
    }
    else if (isDoWhileNode(t))
    {
        int start_label = getLabel();
        int end_label = getLabel();
        codegen_label_definition(start_label);
        codegen(t->right, start_label, end_label);
        reg_index r = codegen_evaluate_expression(t->left);
        codegen_jump_to_label_if_not_zero(r, start_label);
        codegen_label_definition(end_label);
        return current_register;
    }
    else if (isRepeatUntilNode(t))
    {
        int start_label = getLabel();
        int end_label = getLabel();
        codegen_label_definition(start_label);
        codegen(t->right, start_label, end_label);
        reg_index r = codegen_evaluate_expression(t->left);
        codegen_jump_to_label_if_zero(r, start_label);
        codegen_label_definition(end_label);
        return current_register;
    }

    codegen(t->left, startLabel, endLabel);
    codegen(t->right, startLabel, endLabel);
    return current_register;
}

reg_index codegen_evaluate_expression(tnode *t)
{
    if (t == NULL)
    {
        return current_register;
    }
    // If the node is an array node
    else if (isArrayNode(t))
    {
        reg_index binding = codegen_array(t);
        codegen_read_from_stack_with_register(binding);
        return binding;
    }
    else if (isRefNode(t))
    {
        // TODO:
        Gsymbol *g = Lookup(t->left->varname);
        int binding = g->binding;
        reg_index r = getReg();
        codegen_set_int_value_to_register(r, binding);
        return r;
    }
    else if (isAccessNode(t))
    {
        // TODO:
        Gsymbol *g = Lookup(t->left->varname);
        int binding = g->binding;
        reg_index p = codegen_read_from_stack(binding); // contains values' address
        codegen_read_from_stack_with_register(p);
        return p;
    }
    // If the node is leaf node, then it is either a variable or a number or a string
    else if (isLeafNode(t))
    {
        reg_index r = getReg();
        // if the node is a number or string
        if (t->varname == NULL)
        {
            if (t->type == TYPE_INT)
            {
                codegen_set_int_value_to_register(r, t->val);
            }
            else if (t->type == TYPE_STR && t->strval != NULL)
            {
                codegen_set_str_value_to_register(r, t->strval);
            }
            else
            {
                printTree(t);
                fprintf(stderr, "Invalid expression");
                exit(1);
            }
        }
        // If the node is a variable
        else
        {
            Gsymbol *g = Lookup(t->varname);
            int offset = g->binding;
            fprintf(target_file, "MOV R%d,[%d]\n", r, offset);
        }
        return current_register;
    }
    reg_index left_expression = codegen_evaluate_expression(t->left);
    reg_index right_expression = codegen_evaluate_expression(t->right);
    codegen_operation(t, left_expression, right_expression);
    return current_register;
}

// Returns register containing address
reg_index codegen_array(tnode *t)
{
    Gsymbol *g = Lookup(t->varname);
    reg_index r = codegen_get_array_offset(g->dimNode, t->dimNode);
    reg_index binding = getReg();
    codegen_set_int_value_to_register(binding, g->binding);
    codegen_add_two_registers(r, binding);
    return r;
}

reg_index codegen_get_array_offset(dimNode *decl, dimNode *node)
{
    if (decl == NULL)
    {
        fprintf(stderr, "Trying to access invalid address\n");
        exit(1);
    }
    if (node == NULL)
    {
        fprintf(stderr, "Index expression is shorter than dimensions\n");
        exit(1);
    }
    if (node->val >= decl->val)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    if (decl->next == NULL)
    {
        return codegen_evaluate_expression(node->tnode);
    }

    // Otherwise, recursively compute offset for remaining dimensions
    reg_index offsetReg = codegen_get_array_offset(decl->next, node->next);

    int product = 1;
    dimNode *temp = decl->next;
    while (temp != NULL)
    {
        product *= temp->val;
        temp = temp->next;
    }

    reg_index valReg = codegen_evaluate_expression(node->tnode);
    reg_index productReg = getReg();
    codegen_set_int_value_to_register(productReg, product);
    codegen_multiply_two_registers(valReg, productReg);
    codegen_add_two_registers(offsetReg, valReg);
    return offsetReg;
}

reg_index codegen_operation(tnode *t, reg_index left_expression, reg_index right_expression)
{
    if (matchesOperator(t, "+"))
    {
        codegen_add_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "-"))
    {
        codegen_subtract_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "*"))
    {
        codegen_multiply_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "/"))
    {
        codegen_divide_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "%"))
    {
        codegen_mod_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "<"))
    {
        codegen_less_than_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "<="))
    {
        codegen_less_than_equal_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, ">"))
    {
        codegen_greater_than_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, ">="))
    {
        codegen_greater_than_equal_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "!="))
    {
        codegen_not_equal_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "=="))
    {
        codegen_equal_two_registers(left_expression, right_expression);
    }
    return current_register;
}

reg_index codegen_add_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "ADD R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codegen_add_two_numbers(int num1, int num2)
{
    reg_index r1 = getReg();
    fprintf(target_file, "MOV R%d,%d\n", r1, num1);
    reg_index r2 = getReg();
    fprintf(target_file, "MOV R%d,%d\n", r2, num2);
    fprintf(target_file, "ADD R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codegen_subtract_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "SUB R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codegen_multiply_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "MUL R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codegen_divide_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "DIV R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codegen_mod_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "MOD R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codegen_less_than_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "LT R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codegen_less_than_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "LE R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codegen_greater_than_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "GT R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codegen_greater_than_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "GE R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codegen_not_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "NE R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codegen_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "EQ R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

void codegen_jump_to_label(int label)
{
    fprintf(target_file, "JMP L%d\n", label);
}

void codegen_jump_to_label_if_zero(reg_index r, int label)
{
    fprintf(target_file, "JZ R%d,L%d\n", r, label);
}

void codegen_jump_to_label_if_not_zero(reg_index r, int label)
{
    fprintf(target_file, "JNZ R%d,L%d\n", r, label);
}

void codegen_label_definition(int label)
{
    fprintf(target_file, "L%d:", label);
}

void codegen_set_int_value_to_register(reg_index r, int value)
{
    fprintf(target_file, "MOV R%d,%d\n", r, value);
}

void codegen_set_str_value_to_register(reg_index r, char *value)
{
    fprintf(target_file, "MOV R%d,%s\n", r, value);
}

void codegen_generate_header()
{
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}

void codegen_add_breakpoint()
{
    fprintf(target_file, "BRKP\n");
}

void codegen_initialize_stack(int addr)
{
    fprintf(target_file, "MOV SP,%d\n", addr);
}

void codegen_store_in_stack(reg_index reg, int addr)
{
    fprintf(target_file, "MOV [%d],R%d\n", addr, reg);
    freeReg();
}

void codegen_store_in_stack_with_registers(reg_index src, reg_index dest)
{
    fprintf(target_file, "MOV [R%d],R%d\n", dest, src);
}

reg_index codegen_read_from_stack(int addr)
{
    reg_index r = getReg();
    fprintf(target_file, "MOV R%d,[%d]\n", r, addr);
    return r;
}

reg_index codegen_read_from_stack_with_register(reg_index addr)
{
    fprintf(target_file, "MOV R%d,[R%d]\n", addr, addr);
    return addr;
}

void codegen_print_address(int addr)
{
    while (current_register != -1)
    {
        freeReg();
    }
    getReg();
    fprintf(target_file, "MOV R%d,\"Write\"\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,-2\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,[%d]\n", current_register, addr);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
}

void codegen_print_register(reg_index reg)
{
    fprintf(target_file, "PUSH R%d\n", reg);
    stack_top++;
    int reg_address = stack_top;
    while (current_register != -1)
    {
        freeReg();
    }
    getReg();
    fprintf(target_file, "MOV R%d,\"Write\"\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,-2\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,[%d]\n", current_register, reg_address);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    stack_top--;
}

void codegen_read_to_address(int addr)
{
    int push_count = 0;
    while (current_register != -1)
    {
        freeReg();
    }
    getReg();
    fprintf(target_file, "MOV R%d,\"Read\"\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,-1\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,%d\n", current_register, addr);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    freeReg();
}

void codegen_read_to_register(reg_index reg)
{
    getReg();
    fprintf(target_file, "MOV R%d,\"Read\"\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,-1\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "MOV R%d,R%d\n", current_register, reg);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "PUSH R%d\n", current_register);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    while (current_register != -1)
    {
        freeReg();
    }
}

void codegen_call_exit()
{
    fprintf(target_file, "MOV R0,\"Exit\"\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL 0\n");
}
