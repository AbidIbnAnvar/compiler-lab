#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "../helper/constant.h"
#include "../symbol_table/table.h"

typedef struct tnode
{
    int val;
    Type type;
    char *op;
    char *varname;
    NodeType nodetype;
    Gsymbol *Gentry;
    struct tnode *left, *right, *middle;
} tnode;

tnode *createTree(int val, char *op, Type type, char *c, NodeType nodetype, tnode *l, tnode *m, tnode *r);

#endif