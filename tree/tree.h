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
    NODETYPE_OP_ARITHMETIC,
    NODETYPE_OP_ASSIGNMENT,
    NODETYPE_OP_RELATIONAL,
    NODETYPE_IF,
    NODETYPE_WHILE,
    NODETYPE_BREAK,
    NODETYPE_CONTINUE,
    NODETYPE_DO_WHILE,
    NODETYPE_REPEAT_UNTIL
} NodeType;

typedef struct tnode
{
    int val;
    Type type;
    char *op;
    char *varname;
    NodeType nodetype;
    struct tnode *left, *right, *middle;
} tnode;

tnode *createTree(int val, char *op, Type type, char *c, NodeType nodetype, tnode *l, tnode *m, tnode *r);

#endif