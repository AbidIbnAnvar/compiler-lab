#ifndef STAGE1_H
#define STAGE1_H

#include <stdio.h>

typedef struct tnode
{
    int val;
    char *op;                   // indicates the name of the operator for a non leaf node
    struct tnode *left, *right; // left and right branches
} tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode *makeLeafNode(int n);

/*Make a tnode with operator, left and right branches set*/
struct tnode *makeOperatorNode(char *op, struct tnode *l, struct tnode *r);

typedef int reg_index;

reg_index current_register;

FILE *target_file;

reg_index codeGen(tnode *t);
reg_index getReg();
reg_index freeReg();

void generateHeader();
void initializeStack(int addr);
void storeInStack(reg_index reg, int addr);
void printAddress(int addr);
void callExit();

#endif