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

bool isArrayNode(tnode *t)
{
    return t && t->nodetype == NODETYPE_ARRAY;
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

const char *type_to_string(Type type)
{
    switch (type)
    {
    case TYPE_NULL:
        return "NULL";
    case TYPE_BOOL:
        return "BOOL";
    case TYPE_INT:
        return "INT";
    case TYPE_STRING:
        return "STRING";
    default:
        return "UNKNOWN";
    }
}

const char *nodetype_to_string(NodeType nodetype)
{
    switch (nodetype)
    {
    case NODETYPE_LEAF:
        return "LEAF";
    case NODETYPE_READ:
        return "READ";
    case NODETYPE_WRITE:
        return "WRITE";
    case NODETYPE_CONNECTOR:
        return "CONNECTOR";
    case NODETYPE_OP_ARITHMETIC:
        return "ARITHMETIC";
    case NODETYPE_OP_ASSIGNMENT:
        return "ASSIGNMENT";
    case NODETYPE_OP_RELATIONAL:
        return "RELATIONAL";
    case NODETYPE_IF:
        return "IF";
    case NODETYPE_WHILE:
        return "WHILE";
    case NODETYPE_BREAK:
        return "BREAK";
    case NODETYPE_CONTINUE:
        return "CONTINUE";
    case NODETYPE_DO_WHILE:
        return "DO_WHILE";
    case NODETYPE_REPEAT_UNTIL:
        return "REPEAT_UNTIL";
    case NODETYPE_TYPE:
        return "TYPE";
    case NODETYPE_DECLARATION:
        return "DECLARATION";
    case NODETYPE_DECLARATION_BLOCK:
        return "DECL_BLOCK";
    case NODETYPE_ARRAY:
        return "ARRAY";
    default:
        return "UNKNOWN";
    }
}