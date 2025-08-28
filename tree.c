#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tnode *createTree(int val, char *op, Type type, char *c, int nodetype, tnode *l, tnode *r)
{
    tnode *tree = (tnode *)malloc(sizeof(tnode));
    tree->val = val;
    tree->type = type;
    tree->op = op;
    tree->varname = c;
    tree->nodetype = nodetype;
    tree->left = l;
    tree->right = r;
    return tree;
}
