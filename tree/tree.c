#include "tree.h"
#include "../helper/helper.h"

tnode *createTree(int val, char *op, Type type, char *c, NodeType nodetype, tnode *l, tnode *m, tnode *r, Gsymbol *Gentry)
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
    tree->Gentry = Gentry;
    return tree;
}

void freeTree(tnode *t)
{
    if (t == NULL)
        return;
    freeTree(t->left);
    freeTree(t->middle);
    freeTree(t->right);
    if (t->varname)
        free(t->varname);
    free(t);
}