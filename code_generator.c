#include <stdio.h>
#include <stdlib.h>
#include "code_generator.h"
#include <string.h>
#include <stdbool.h>
#include "helper.h"

reg_index current_register = -1;

reg_index getReg()
{
    return ++current_register;
}

reg_index freeReg()
{
    return --current_register;
}

reg_index codeGen(tnode *t)
{
    if (t == NULL)
    {
        return current_register;
    }

    if (isOperatorNode(t))
    {
        reg_index r = codeGen_evaluate_expression(t);
        freeReg();
        return current_register;
    }
    if (isReadNode(t))
    {
        int offset = t->left->varname[0] - 'a';
        readToAddress(4096 + offset);
        return current_register;
    }
    if (isWriteNode(t))
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
    if (isAssignmentNode(t))
    {
        int offset = 4096 + (t->left->varname[0] - 'a');
        storeInStack(codeGen_evaluate_expression(t->right), offset);
        return current_register;
    }
    codeGen(t->left);
    codeGen(t->right);
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

void generateHeader()
{
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
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
