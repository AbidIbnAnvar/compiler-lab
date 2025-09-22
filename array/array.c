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

int getArrayOffset(dimNode *head, dimNode *node)
{
    // Error checks
    if (head == NULL)
    {
        fprintf(stderr, "Trying to access invalid address\n");
        exit(1);
    }
    if (node == NULL)
    {
        fprintf(stderr, "Index expression is shorter than dimensions\n");
        exit(1);
    }
    if (node->val >= head->val)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    // If this is the last dimension, offset is simply index
    if (head->next == NULL)
    {
        return node->val;
    }

    // Otherwise, recursively compute offset for remaining dimensions
    int subOffset = getArrayOffset(head->next, node->next);
    if (subOffset == -1)
    {
        return -1; // propagate error from recursion
    }

    int product = 1;
    dimNode *temp = head->next;
    while (temp != NULL)
    {
        product *= temp->val;
        temp = temp->next;
    }

    return node->val * product + subOffset;
}
