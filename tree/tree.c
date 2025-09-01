#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../helper/helper.h"

tnode *createTree(int val, char *op, Type type, char *c, int nodetype, tnode *l, tnode *m, tnode *r)
{
    if (nodetype == NODETYPE_OP_ARITHMETIC)
    {
        if ((l->type != TYPE_INT) || (r->type != TYPE_INT))
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            printNode(l);
            exit(1);
        }
    }
    else if (nodetype == NODETYPE_WHILE)
    {
        if (l->type != TYPE_INT)
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            printNode(l);
            exit(1);
        }
    }
    else if (nodetype == NODETYPE_IF)
    {
        if (l->type != TYPE_INT)
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            printNode(l);
            exit(1);
        }
    }
    tnode *tree = (tnode *)malloc(sizeof(tnode));
    tree->val = val;
    tree->type = type;
    tree->op = op;
    tree->varname = c;
    tree->nodetype = nodetype;
    tree->left = l;
    tree->right = r;
    tree->middle = m;
    return tree;
}
