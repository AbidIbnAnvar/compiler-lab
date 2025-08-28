#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef enum Type
{
    TYPE_NULL,
    TYPE_BOOL,
    TYPE_INT,
    TYPE_STRING
} Type;

typedef enum NodeType
{
    NODETYPE_LEAF = -1,
    NODETYPE_READ,
    NODETYPE_WRITE,
    NODETYPE_CONNECTOR,
    NODETYPE_OPERATOR,
    NODETYPE_ASSIGNMENT
} NodeType;

typedef struct tnode
{
    int val;
    Type type;
    char *op;
    char *varname;
    NodeType nodetype;
    struct tnode *left, *right;
} tnode;

tnode *createTree(int val, char *op, Type type, char *c, NodeType nodetype, tnode *l, tnode *r);

#endif