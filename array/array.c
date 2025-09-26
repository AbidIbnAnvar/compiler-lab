#include "array.h"

dimNode *addDimension(int val, tnode *tnode, dimNode *next)
{
    dimNode *node = (dimNode *)malloc(sizeof(dimNode));
    node->val = val;
    node->tnode = tnode;
    node->next = next;
    return node;
}

int getArraySize(dimNode *node)
{
    int size = 1;
    while (node != NULL)
    {
        size *= node->val;
        node = node->next;
    }
    return size;
}