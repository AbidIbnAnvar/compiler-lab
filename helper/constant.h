#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdbool.h>

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
    NODETYPE_REPEAT_UNTIL,
    NODETYPE_TYPE,
    NODETYPE_DECLARATION,
    NODETYPE_DECLARATION_BLOCK,
    NODETYPE_ARRAY
} NodeType;

typedef struct tnode
{
    int val;
    int offset;
    Type type;
    char *op;
    char *varname;
    NodeType nodetype;
    struct Gsymbol *Gentry;
    struct dimNode *dimNode;
    struct tnode *left, *right, *middle;
} tnode;

typedef struct Gsymbol
{
    char *name;
    int type;
    int size;
    int binding;
    struct dimNode *dimNode;
    struct Gsymbol *next;
} Gsymbol;

typedef struct dimNode
{
    int val;
    tnode *tnode;
    struct dimNode *next;
} dimNode;

#endif