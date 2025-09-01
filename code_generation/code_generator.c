#include <stdio.h>
#include <stdlib.h>
#include "code_generator.h"
#include <string.h>
#include <stdbool.h>
#include "../helper/helper.h"

reg_index current_register = -1;
int last_used_label = -1;

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

reg_index codeGen(tnode *t, int startLabel, int endLabel)
{
    if (t == NULL)
    {
        return current_register;
    }

    if (isOperatorNode(t))
    {
        if (isAssignmentNode(t))
        {
            int offset = 4096 + (t->left->varname[0] - 'a');
            reg_index r = codeGen_evaluate_expression(t->right);
            storeInStack(r, offset);
            return current_register;
        }
        else if (isAritmeticNode(t) || isRelationalNode(t))
        {
            reg_index r = codeGen_evaluate_expression(t);
            freeReg();
            return current_register;
        }
    }
    else if (isReadNode(t))
    {
        int offset = 4096 + t->left->varname[0] - 'a';
        readToAddress(offset);
        return current_register;
    }
    else if (isWriteNode(t))
    {
        reg_index r;
        if (isOperatorNode(t->left))
        {
            r = codeGen_evaluate_expression(t->left);
        }
        else
        {
            int offset = t->left->varname[0] - 'a';
            r = readFromStack(4096 + offset);
        }
        printRegister(r);
        return current_register;
    }
    else if (isIfElseNode(t))
    {
        if (t->right != NULL)
        {
            int elseLabel = getLabel();
            int finishLabel = getLabel();
            reg_index r = codeGen_evaluate_expression(t->left);
            codeGen_jump_to_label_if_zero(r, elseLabel);
            freeReg();
            codeGen(t->middle, startLabel, endLabel);
            codeGen_jump_to_label(finishLabel);
            codeGen_label_definition(elseLabel);
            codeGen(t->right, startLabel, endLabel);
            codeGen_label_definition(finishLabel);
        }
        else
        {
            int finishLabel = getLabel();
            reg_index r = codeGen_evaluate_expression(t->left);
            codeGen_jump_to_label_if_zero(r, finishLabel);
            codeGen(t->middle, startLabel, endLabel);
            codeGen_label_definition(finishLabel);
        }
        return current_register;
    }
    else if (isWhileNode(t))
    {
        int start_label = getLabel();
        int end_label = getLabel();
        codeGen_label_definition(start_label);
        reg_index r = codeGen_evaluate_expression(t->left);
        codeGen_jump_to_label_if_zero(r, end_label);
        codeGen(t->right, start_label, end_label);
        codeGen_jump_to_label(start_label);
        codeGen_label_definition(end_label);
        return current_register;
    }
    else if (isBreakNode(t))
    {
        codeGen_jump_to_label(endLabel);
        return current_register;
    }
    else if (isContinueNode(t))
    {
        codeGen_jump_to_label(startLabel);
        return current_register;
    }
    else if (isDoWhileNode(t))
    {
        int start_label = getLabel();
        int end_label = getLabel();
        codeGen_label_definition(start_label);
        codeGen(t->right, start_label, end_label);
        reg_index r = codeGen_evaluate_expression(t->left);
        codeGen_jump_to_label_if_not_zero(r, start_label);
        codeGen_label_definition(end_label);
        return current_register;
    }
    else if (isRepeatUntilNode(t))
    {
        int start_label = getLabel();
        int end_label = getLabel();
        codeGen_label_definition(start_label);
        codeGen(t->right, start_label, end_label);
        reg_index r = codeGen_evaluate_expression(t->left);
        codeGen_jump_to_label_if_zero(r, start_label);
        codeGen_label_definition(end_label);
        return current_register;
    }

    codeGen(t->left, startLabel, endLabel);
    codeGen(t->right, startLabel, endLabel);
    return current_register;
}

reg_index codeGen_evaluate_expression(tnode *t)
{
    if (t == NULL)
    {
        return current_register;
    }
    if (t->left == NULL && t->right == NULL)
    {
        reg_index r = getReg();
        if (t->varname == NULL)
        {
            fprintf(target_file, "MOV R%d, %d\n", r, t->val);
        }
        else
        {
            int offset = 4096 + (t->varname[0] - 'a');
            fprintf(target_file, "MOV R%d, [%d]\n", r, offset);
        }
        return current_register;
    }
    reg_index left_expression = codeGen_evaluate_expression(t->left);
    reg_index right_expression = codeGen_evaluate_expression(t->right);
    codeGen_operation(t, left_expression, right_expression);
    return current_register;
}

reg_index codeGen_operation(tnode *t, reg_index left_expression, reg_index right_expression)
{
    if (matchesOperator(t, "+"))
    {
        codeGen_add_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "-"))
    {
        codeGen_subtract_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "*"))
    {
        codeGen_multiply_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "/"))
    {
        codeGen_divide_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "<"))
    {
        codeGen_less_than_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "<="))
    {
        codeGen_less_than_equal_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, ">"))
    {
        codeGen_greater_than_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, ">="))
    {
        codeGen_greater_than_equal_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "!="))
    {
        codeGen_not_equal_two_registers(left_expression, right_expression);
    }
    else if (matchesOperator(t, "=="))
    {
        codeGen_equal_two_registers(left_expression, right_expression);
    }
    return current_register;
}

reg_index codeGen_add_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "ADD R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codeGen_add_two_numbers(int num1, int num2)
{
    reg_index r1 = getReg();
    fprintf(target_file, "MOV R%d,%d\n", r1, num1);
    reg_index r2 = getReg();
    fprintf(target_file, "MOV R%d,%d\n", r2, num2);
    fprintf(target_file, "ADD R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codeGen_subtract_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "SUB R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codeGen_multiply_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "MUL R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codeGen_divide_two_registers(reg_index r1, reg_index r2)
{
    fprintf(target_file, "DIV R%d,R%d\n", r1, r2);
    freeReg();
    return current_register;
}

reg_index codeGen_less_than_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "LT R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codeGen_less_than_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "LE R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codeGen_greater_than_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "GT R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codeGen_greater_than_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "GE R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codeGen_not_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "NE R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

reg_index codeGen_equal_two_registers(reg_index left_expression, reg_index right_expression)
{
    fprintf(target_file, "EQ R%d,R%d\n", left_expression, right_expression);
    freeReg();
    return current_register;
}

void codeGen_jump_to_label(int label)
{
    fprintf(target_file, "JMP L%d\n", label);
}

void codeGen_jump_to_label_if_zero(reg_index r, int label)
{
    fprintf(target_file, "JZ R%d,L%d\n", r, label);
}

void codeGen_jump_to_label_if_not_zero(reg_index r, int label)
{
    fprintf(target_file, "JNZ R%d,L%d\n", r, label);
}

void codeGen_label_definition(int label)
{
    fprintf(target_file, "L%d:", label);
}

void generateHeader()
{
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}

void addBreakpoint()
{
    fprintf(target_file, "BRKP\n");
}

void initializeStack(int addr)
{
    fprintf(target_file, "MOV SP,%d\n", addr);
}

void storeInStack(reg_index reg, int addr)
{
    fprintf(target_file, "MOV [%d],R%d\n", addr, reg);
}

reg_index readFromStack(int addr)
{
    reg_index r = getReg();
    fprintf(target_file, "MOV R%d,[%d]\n", r, addr);
    return r;
}

void printAddress(int addr)
{
    int push_count = 0;
    while (current_register != -1)
    {
        fprintf(target_file, "PUSH R%d\n", current_register);
        freeReg();
        push_count++;
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
    getReg();
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    while (push_count > 0)
    {
        fprintf(target_file, "POP R%d\n", current_register);
        push_count--;
    }
}

void printRegister(reg_index reg)
{
    int reg_address = 4096 + 26;
    int push_count = 0;
    fprintf(target_file, "PUSH R%d\n", reg);
    push_count++;
    while (current_register != -1)
    {
        fprintf(target_file, "PUSH R%d\n", current_register);
        freeReg();
        push_count++;
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
    getReg();
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    while (push_count > 0)
    {
        fprintf(target_file, "POP R%d\n", current_register);
        push_count--;
    }
}

void readToAddress(int addr)
{
    int push_count = 0;
    while (current_register != -1)
    {
        fprintf(target_file, "PUSH R%d\n", current_register);
        freeReg();
        push_count++;
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
    getReg();
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    while (push_count > 0)
    {
        fprintf(target_file, "POP R%d\n", current_register);
        push_count--;
    }
}

void callExit()
{
    fprintf(target_file, "MOV R0,\"Exit\"\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL 0\n");
}
