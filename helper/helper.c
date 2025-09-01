#include "helper.h"
#include <stdio.h>
#include <stdbool.h>

bool isAritmeticNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_OP_ARITHMETIC;
}

bool isRelationalNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_OP_RELATIONAL;
}

bool isOperatorNode(tnode *t)
{
    return (isAritmeticNode(t) || isRelationalNode(t) || isAssignmentNode(t));
}

bool isWriteNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_WRITE;
}

bool isReadNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_READ;
}

bool isAssignmentNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_OP_ASSIGNMENT;
}

bool isIfElseNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_IF;
}

bool isWhileNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_WHILE;
}

bool matchesOperator(tnode *t, char *op)
{
    return t && (strcmp(t->op, op) == 0);
}

bool isRelationalOperator(tnode *t)
{
    return matchesOperator(t, "<") || matchesOperator(t, "<=") || matchesOperator(t, ">") || matchesOperator(t, ">=") || matchesOperator(t, "==") || matchesOperator(t, "!=");
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printNode(tnode *t)
{
    printf("(%d,%s,%d,%d) \n", t->val, t->varname, t->type, t->nodetype);
}
