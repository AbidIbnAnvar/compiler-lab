#include <stdio.h>
#include <stdlib.h>
#include "stage1.h"

reg_index current_register = -1;

struct tnode *makeLeafNode(int n)
{
    tnode *leaf = malloc(sizeof(tnode));
    leaf->val = n;
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->op = NULL;
    return leaf;
}

struct tnode *makeOperatorNode(char *op, struct tnode *l, struct tnode *r)
{
    tnode *opnode = malloc(sizeof(tnode));
    opnode->left = l;
    opnode->right = r;
    opnode->op = strdup(op);
    opnode->val = 0;
    return opnode;
}

reg_index getReg()
{
    return ++current_register;
}

reg_index freeReg()
{
    return --current_register;
}

void generateHeader()
{
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}

reg_index codeGen(tnode *t)
{
    if (t->left == NULL && t->right == NULL)
    {
        reg_index r = getReg();
        fprintf(target_file, "MOV R%d,%d\n", r, t->val);
        return r;
    }
    reg_index leftReg = codeGen(t->left);
    reg_index rightReg = codeGen(t->right);
    if (strcmp(t->op, "+") == 0)
    {
        fprintf(target_file, "ADD R%d,R%d\n", leftReg, rightReg);
    }
    else if (strcmp(t->op, "-") == 0)
    {
        fprintf(target_file, "SUB R%d,R%d\n", leftReg, rightReg);
    }
    else if (strcmp(t->op, "*") == 0)
    {
        fprintf(target_file, "MUL R%d,R%d\n", leftReg, rightReg);
    }
    else if (strcmp(t->op, "/") == 0)
    {
        fprintf(target_file, "DIV R%d,R%d\n", leftReg, rightReg);
    }
    freeReg();
    return leftReg;
}

void initializeStack(int addr)
{
    fprintf(target_file, "MOV SP,%d\n", addr);
}

void storeInStack(reg_index reg, int addr)
{
    fprintf(target_file, "MOV [%d],R%d\n", addr, reg);
}

void printAddress(int addr)
{

    while (current_register != -1)
    {
        fprintf(target_file, "PUSH R%d\n", current_register);
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
    getReg();
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
    fprintf(target_file, "POP R%d\n", current_register);
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
