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

reg_index get_register()
{
    ++current_register;
    return current_register % 20;
}

reg_index free_register()
{
    return --current_register;
}

int get_label()
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

            tnode *leftNode = t->left;
            // Assignment to array
            if (isArrayNode(leftNode))
            {
                reg_index r = codegen_evaluate_expression(t->right);
                reg_index binding = codegen_array(leftNode);
                codegen_store_in_stack_with_registers(r, binding);
                return current_register;
            }
            // Assignment to pointer
            else if (isAccessNode(leftNode))
            {
                reg_index r = codegen_evaluate_expression(t->right);
                SymbolTable *st = leftNode->left->STentry;
                int binding = st->binding;
                reg_index p = codegen_read_from_stack(binding, st->scope);
                codegen_store_in_stack_with_registers(r, p);
                free_register();
                return current_register;
            }
            // Assignment to variable
            else
            {
                SymbolTable *st1 = leftNode->STentry;
                SymbolTable *st2 = t->right->STentry;
                // Assigning tuple to tuple
                if (st1->typetable->field && st2->typetable->field)
                {
                    Field *f = st1->typetable->field;
                    reg_index r0 = get_register();
                    codegen_set_int_value_to_register(r0, st1->binding);
                    reg_index r1 = get_register();
                    codegen_set_int_value_to_register(r1, st2->binding);
                    while (f)
                    {
                        fprintf(target_file, "MOV [R%d],[R%d]\n", r0, r1);
                        fprintf(target_file, "ADD R%d,1\n", r0);
                        fprintf(target_file, "ADD R%d,1\n", r1);
                        f = f->next;
                    }
                    free_register();
                }
                // Assigning tuple's ptr value to tuple
                else if (isAccessNode(t->right) && st2->typetable->size > 1)
                {
                    reg_index r = get_register();
                    codegen_set_int_value_to_register(r, st1->binding);
                    SymbolTable *st = t->right->left->STentry;
                    reg_index ptr = codegen_read_from_stack(st->binding, st->scope);
                    Field *f = st1->typetable->field;
                    while (f)
                    {
                        fprintf(target_file, "MOV [R%d],[R%d]\n", r, ptr);
                        fprintf(target_file, "ADD R%d,1\n", r);
                        fprintf(target_file, "ADD R%d,1\n", ptr);
                        f = f->next;
                    }
                    free_register();
                }
                else
                {
                    reg_index r = codegen_evaluate_expression(t->right);
                    codegen_store_in_stack(r, st1->binding, st1->scope);
                }
                return current_register;
            }
        }
        else if (isArithmeticNode(t) || isRelationalNode(t))
        {
            reg_index r = codegen_evaluate_expression(t);
            free_register();
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
        if (isTupleAccessNode(t->left))
        {
            tnode *accessNode = t->left;
            SymbolTable *st = accessNode->STentry;
            reg_index r = get_register();
            codegen_set_int_value_to_register(r, st->binding);
            int offset = 0;
            Field *f = st->typetable->field;
            while (f)
            {
                if (strcmp(f->name, accessNode->varname) == 0)
                {
                    break;
                }
                offset++;
                f = f->next;
            }
            reg_index off = get_register();
            codegen_set_int_value_to_register(off, offset);
            codegen_add_two_registers(r, off);
            codegen_read_to_register(r);
        }
        else
        {
            // Get symbol table entry for the variable
            SymbolTable *st = t->left->STentry;
            codegen_read_to_address(st->binding, st->scope);
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
            SymbolTable *st = t->left->STentry;

            int offset = st->binding;
            r = codegen_read_from_stack(offset, st->scope);
        }
        // number is put inside write
        else if (isLeafNode(t->left) && t->left->typetable->type == TYPE_INT)
        {
            r = get_register();
            codegen_set_int_value_to_register(r, t->left->val);
        }
        // string is put inside write
        else if (isLeafNode(t->left) && t->left->typetable->type == TYPE_STR)
        {
            r = get_register();
            codegen_set_str_value_to_register(r, t->left->strval);
        }
        else if (isFuncCallNode(t->left))
        {
            r = codegen_function_call(t->left);
        }
        else if (isAccessNode(t->left))
        {
            tnode *leftNode = t->left;
            SymbolTable *st = leftNode->left->STentry;
            r = codegen_read_from_stack(st->binding, st->scope);
            codegen_read_from_stack_with_register(r);
            free_register();
        }
        else if (isTupleAccessNode(t->left))
        {
            tnode *accessNode = t->left;
            SymbolTable *st = accessNode->STentry;
            r = get_register();
            codegen_set_int_value_to_register(r, st->binding);
            int offset = 0;
            Field *f = st->typetable->field;
            while (f)
            {
                if (strcmp(f->name, accessNode->varname) == 0)
                {
                    break;
                }
                offset++;
                f = f->next;
            }
            reg_index off = get_register();
            codegen_set_int_value_to_register(off, offset);
            codegen_add_two_registers(r, off);
            codegen_read_from_stack_with_register(r);
        }
        codegen_print_register(r);
        return current_register;
    }
    else if (isIfElseNode(t))
    {
        if (t->right != NULL)
        {
            int elseLabel = get_label();
            int finishLabel = get_label();
            reg_index r = codegen_evaluate_expression(t->left);
            codegen_jump_to_label_if_zero(r, elseLabel);
            free_register();
            codegen(t->middle, startLabel, endLabel);
            codegen_jump_to_label(finishLabel);
            codegen_label_definition(elseLabel);
            codegen(t->right, startLabel, endLabel);
            codegen_label_definition(finishLabel);
        }
        else
        {
            int finishLabel = get_label();
            reg_index r = codegen_evaluate_expression(t->left);
            codegen_jump_to_label_if_zero(r, finishLabel);
            codegen(t->middle, startLabel, endLabel);
            codegen_label_definition(finishLabel);
        }
        return current_register;
    }
    else if (isWhileNode(t))
    {
        int start_label = get_label();
        int end_label = get_label();
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
        int start_label = get_label();
        int end_label = get_label();
        codegen_label_definition(start_label);
        codegen(t->right, start_label, end_label);
        reg_index r = codegen_evaluate_expression(t->left);
        codegen_jump_to_label_if_not_zero(r, start_label);
        codegen_label_definition(end_label);
        return current_register;
    }
    else if (isRepeatUntilNode(t))
    {
        int start_label = get_label();
        int end_label = get_label();
        codegen_label_definition(start_label);
        codegen(t->right, start_label, end_label);
        reg_index r = codegen_evaluate_expression(t->left);
        codegen_jump_to_label_if_zero(r, start_label);
        codegen_label_definition(end_label);
        return current_register;
    }
    else if (isMainNode(t))
    {
        codegen_main_function(t);
        return current_register;
    }
    else if (isFuncNode(t))
    {
        codegen_function(t);
        return current_register;
    }
    else if (isFuncCallNode(t))
    {
        codegen_function_call(t);
        return current_register;
    }
    // else if (isReturnNode(t))
    // {

    //     return current_register;
    // }
    else if (isBrkpNode(t))
    {
        codegen_add_breakpoint();
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
        SymbolTable *st = t->left->STentry;
        reg_index r = get_register();
        if (st->scope == GLOBAL)
        {
            codegen_set_int_value_to_register(r, st->binding);
        }
        else
        {
            fprintf(target_file, "MOV R%d, BP\n", r);
            fprintf(target_file, "ADD R%d, %d\n", r, st->binding);
        }
        return r;
    }
    else if (isAccessNode(t))
    {
        SymbolTable *st = t->left->STentry;
        reg_index p = codegen_read_from_stack(st->binding, st->scope);
        codegen_read_from_stack_with_register(p);
        return p;
    }
    // If the node is leaf node, then it is either a variable or a number or a string
    else if (isLeafNode(t))
    {
        // if the node is a number or string
        if (t->varname == NULL)
        {
            reg_index r = get_register();
            if (t->typetable->type == TYPE_INT)
            {
                codegen_set_int_value_to_register(r, t->val);
            }
            else if (t->typetable->type == TYPE_STR && t->strval != NULL)
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
            SymbolTable *st = t->STentry;
            int offset = st->binding;
            codegen_read_from_stack(offset, st->scope);
        }
        return current_register;
    }
    else if (isFuncCallNode(t))
    {
        reg_index r = codegen_function_call(t);
        return current_register;
    }
    else if (isTupleAccessNode(t))
    {
        tnode *accessNode = t;
        SymbolTable *st = accessNode->STentry;
        reg_index r = get_register();
        codegen_set_int_value_to_register(r, st->binding);
        int offset = 0;
        Field *f = st->typetable->field;
        while (f)
        {
            if (strcmp(f->name, accessNode->varname) == 0)
            {
                break;
            }
            offset++;
            f = f->next;
        }
        reg_index off = get_register();
        codegen_set_int_value_to_register(off, offset);
        codegen_add_two_registers(r, off);
        codegen_read_from_stack_with_register(r);
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
    SymbolTable *st = t->STentry;
    reg_index r = codegen_get_array_offset(st->dimNode, t->dimNode);
    reg_index binding = get_register();
    codegen_set_int_value_to_register(binding, st->binding);
    codegen_add_two_registers(r, binding);
    return r;
}

// Returns register containing offset
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
    reg_index productReg = get_register();
    codegen_set_int_value_to_register(productReg, product);
    codegen_multiply_two_registers(valReg, productReg);
    codegen_add_two_registers(offsetReg, valReg);
    return offsetReg;
}

reg_index codegen_function(tnode *t)
{
    // Function label
    SymbolTable *st = lookupEntry(t->varname, sstop);
    fprintf(target_file, "F%d:", st->flabel);

    // Pushing Old BP
    fprintf(target_file, "PUSH BP\n");
    // Changing BP to SP
    fprintf(target_file, "MOV BP, SP\n");

    SymbolTable *local = t->Lentry;
    int total_size = 0;
    while (local)
    {
        if (local->binding > 0)
        {
            total_size = max(total_size, local->binding + local->size - 1);
        }
        local = local->next;
    }
    if (total_size > 0)
    {
        fprintf(target_file, "ADD SP, %d\n", total_size);
    }
    codegen(t->left, -1, -1);
    if (total_size > 0)
    {
        fprintf(target_file, "SUB SP, %d\n", total_size);
    }

    // Return
    // Setting return value
    reg_index r = codegen_evaluate_expression(t->right);
    reg_index rel = get_register();
    fprintf(target_file, "MOV R%d, BP\n", rel);
    fprintf(target_file, "SUB R%d, 2\n", rel);
    fprintf(target_file, "MOV [R%d], R%d\n", rel, r);
    free_register();
    free_register();
    // Restoring old BP value
    fprintf(target_file, "POP BP\n");
    fprintf(target_file, "RET\n");

    return current_register;
}

reg_index codegen_function_call(tnode *t)
{
    SymbolTable *st = lookupEntry(t->varname, sstop);
    // Push registers in reverse order to get the registers in order of popping
    int push_count = 0;
    for (int i = current_register; i >= 0; i--)
    {
        push_count++;
        fprintf(target_file, "PUSH R%d\n", i);
        free_register();
    }

    // Push arguments to the stack
    if (t->argList)
    {
        t->argList = reverseArgList(t->argList);
        argList *curr = t->argList;
        while (curr)
        {
            reg_index r = codegen_evaluate_expression(curr->node);
            codegen_push_register(r);
            free_register();
            curr = curr->next;
        }
        t->argList = reverseArgList(t->argList);
    }

    // Push empty space for return value
    codegen_push_register(0);
    fprintf(target_file, "CALL F%d\n", st->flabel);
    codegen_pop_register(push_count == 0 ? 1 : push_count);
    if (t->argList)
    {
        argList *curr = t->argList;
        while (curr)
        {
            codegen_pop_register(0);
            curr = curr->next;
        }
    }

    for (int i = 0; i < push_count; i++)
    {
        codegen_pop_register(i);
    }
    if (push_count == 0)
    {
        current_register = 1;
    }
    else
    {
        current_register = push_count;
    }
    return current_register;
}

reg_index codegen_main_function(tnode *t)
{
    fprintf(target_file, "F0:");

    // Pushing Old BP
    fprintf(target_file, "PUSH BP\n");
    // Changing BP to SP
    fprintf(target_file, "MOV BP, SP\n");

    SymbolTable *local = t->Lentry;
    int total_size = 0;
    while (local)
    {
        if (local->binding > 0)
        {
            total_size = max(total_size, local->binding + local->size - 1);
        }
        local = local->next;
    }
    if (total_size > 0)
    {
        fprintf(target_file, "ADD SP, %d\n", total_size);
    }
    codegen(t->left, -1, -1);
    if (total_size > 0)
    {
        fprintf(target_file, "SUB SP, %d\n", total_size);
    }

    // Restoring old BP value
    fprintf(target_file, "POP BP\n");

    fprintf(target_file, "RET\n");
    return current_register;
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
    else if (matchesOperator(t, "||"))
    {
        codegen_or_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "&&"))
    {
        codegen_and_two_registers(left_expression, right_expression);
    }

    return current_register;
}

reg_index codegen_add_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "ADD R%d,R%d\n", r1, r2);
    free_register();
    return r1;
}

reg_index codegen_add_two_numbers(int num1, int num2)
{
    reg_index r1 = get_register();
    fprintf(target_file, "MOV R%d,%d\n", r1, num1);
    reg_index r2 = get_register();
    fprintf(target_file, "MOV R%d,%d\n", r2, num2);
    fprintf(target_file, "ADD R%d,R%d\n", r1, r2);
    free_register();
    return r1;
}

reg_index codegen_subtract_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "SUB R%d,R%d\n", r1, r2);
    free_register();
    return r1;
}

reg_index codegen_multiply_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "MUL R%d,R%d\n", r1, r2);
    free_register();
    return r1;
}

reg_index codegen_divide_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "DIV R%d,R%d\n", r1, r2);
    free_register();
    return r1;
}

reg_index codegen_mod_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "MOD R%d,R%d\n", r1, r2);
    free_register();
    return r1;
}

reg_index codegen_less_than_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "LT R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_less_than_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "LE R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_greater_than_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "GT R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_greater_than_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "GE R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_not_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "NE R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "EQ R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_or_two_registers(reg_index left_expression, reg_index right_expression)
{
    reg_index zero = get_register();
    fprintf(target_file, "MOV R%d, 0\n", zero);
    fprintf(target_file, "NE R%d, R%d\n", left_expression, zero);
    fprintf(target_file, "NE R%d, R%d\n", right_expression, zero);
    free_register();
    fprintf(target_file, "ADD R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
}

reg_index codegen_and_two_registers(reg_index left_expression, reg_index right_expression)
{
    reg_index zero = get_register();
    fprintf(target_file, "MOV R%d, 0\n", zero);
    fprintf(target_file, "NE R%d, R%d\n", left_expression, zero);
    fprintf(target_file, "NE R%d, R%d\n", right_expression, zero);
    free_register();
    fprintf(target_file, "MUL R%d,R%d\n", left_expression, right_expression);
    free_register();
    return left_expression;
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

void codegen_store_in_stack(reg_index reg, int addr, Scope scope)
{
    if (scope == GLOBAL)
    {
        fprintf(target_file, "MOV [%d],R%d\n", addr, reg);
    }
    else
    {
        reg_index addr_reg = get_register();
        fprintf(target_file, "MOV R%d, BP\n", addr_reg);
        fprintf(target_file, "ADD R%d, %d\n", addr_reg, addr);
        fprintf(target_file, "MOV [R%d],R%d\n", addr_reg, reg);
        free_register();
    }
    free_register();
}

void codegen_store_in_stack_with_registers(reg_index src, reg_index dest)
{
    fprintf(target_file, "MOV [R%d],R%d\n", dest, src);
}

reg_index codegen_read_from_stack(int addr, Scope scope)
{
    reg_index r = get_register();
    if (scope == GLOBAL)
    {
        fprintf(target_file, "MOV R%d,[%d]\n", r, addr);
    }
    else
    {
        fprintf(target_file, "MOV R%d, BP\n", r);
        fprintf(target_file, "ADD R%d,%d\n", r, addr);
        fprintf(target_file, "MOV R%d,[R%d]\n", r, r);
    }
    return r;
}

reg_index codegen_read_from_stack_with_register(reg_index addr)
{
    fprintf(target_file, "MOV R%d,[R%d]\n", addr, addr);
    return addr;
}

void codegen_print_address(int addr, Scope scope)
{
    while (current_register != -1)
    {
        free_register();
    }
    reg_index r0 = get_register();
    reg_index r1 = get_register();
    if (scope == GLOBAL)
    {
        fprintf(target_file, "MOV R%d, %d\n", r1, addr);
    }
    else
    {
        fprintf(target_file, "MOV R%d, BP\n", r1);
        fprintf(target_file, "ADD R%d, %d\n", r1, addr);
    }
    fprintf(target_file, "MOV R%d,\"Write\"\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "MOV R%d,-2\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "MOV R%d,[%d]\n", r0, r1);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    free_register();
}

void codegen_print_register(reg_index reg)
{
    fprintf(target_file, "PUSH R%d\n", reg);
    stack_top++;
    int reg_address = stack_top;
    while (current_register != -1)
    {
        free_register();
    }
    reg_index r0 = get_register();
    reg_index r1 = get_register();
    fprintf(target_file, "MOV R%d, SP\n", r1);
    fprintf(target_file, "MOV R%d,\"Write\"\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "MOV R%d,-2\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "MOV R%d,[R%d]\n", r0, r1);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    free_register();
    free_register();
    stack_top--;
}

void codegen_read_to_address(int addr, Scope scope)
{
    int push_count = 0;
    while (current_register != -1)
    {
        free_register();
    }
    reg_index r0 = get_register();
    fprintf(target_file, "MOV R%d,\"Read\"\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "MOV R%d,-1\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    if (scope == GLOBAL)
    {
        fprintf(target_file, "MOV R%d,%d\n", r0, addr);
    }
    else
    {
        reg_index r1 = get_register();
        fprintf(target_file, "MOV R%d,BP\n", r1);
        fprintf(target_file, "ADD R%d,%d\n", r1, addr);
        fprintf(target_file, "MOV R%d,R%d\n", r0, r1);
        free_register();
    }
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "PUSH R%d\n", r0);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    fprintf(target_file, "POP R%d\n", r0);
    free_register();
}

void codegen_read_to_register(reg_index reg)
{
    get_register();
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
        free_register();
    }
}

void codegen_push_register(reg_index reg)
{
    fprintf(target_file, "PUSH R%d\n", reg);
}

void codegen_pop_register(reg_index reg)
{
    fprintf(target_file, "POP R%d\n", reg);
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
