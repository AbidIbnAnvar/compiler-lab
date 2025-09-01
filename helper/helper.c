#include "helper.h"
#include <stdio.h>
#include <stdbool.h>

bool isLeafNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_LEAF;
}

bool isConnectorNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_CONNECTOR;
}

bool isArithmeticNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_OP_ARITHMETIC;
}

bool isRelationalNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_OP_RELATIONAL;
}

bool isOperatorNode(tnode *t)
{
    return (isArithmeticNode(t) || isRelationalNode(t) || isAssignmentNode(t));
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

bool isBreakNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_BREAK;
}

bool isContinueNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_CONTINUE;
}

bool isRepeatUntilNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_REPEAT_UNTIL;
}

bool isDoWhileNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_DO_WHILE;
}

bool isDeclBlockNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_DECLARATION_BLOCK;
}

bool isDeclNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_DECLARATION;
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

void prefixprint(tnode *t)
{
    if (t == NULL)
    {
        return;
    }
    if (!t->left && !t->right)
    {
        if (t->varname)
            printf("%s ", t->varname);
        else
            printf("%d ", t->val);
        return;
    }
    prefixprint(t->left);
    if (t->op && strlen(t->op) > 0)
    {
        printf("%s ", t->op);
    }
    else
    {
        printf("__ ");
    }
    prefixprint(t->right);
    return;
}