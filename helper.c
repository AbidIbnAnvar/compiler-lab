#include "helper.h"
#include <stdio.h>
#include <stdbool.h>

bool isOperatorNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_OPERATOR;
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
    return t && t->nodetype == NODETYPE_ASSIGNMENT;
}

bool matchesOperator(tnode *t, char *op)
{
    return t && (strcmp(t->op, op) == 0);
}
