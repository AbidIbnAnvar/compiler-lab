#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdbool.h>

typedef enum Type
{
    TYPE_NULL,
    TYPE_BOOL,
    TYPE_INT,
    TYPE_STR,
    TYPE_PTR,
    TYPE_TUPLE
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
    NODETYPE_ARRAY,
    NODETYPE_ACCESS,
    NODETYPE_REF,
    NODETYPE_MAIN,
    NODETYPE_FUNC,
    NODETYPE_FUNC_CALL,
    NODETYPE_RETURN,
    NODETYPE_BRKP,
    NODETYPE_TUPLE_ACCESS
} NodeType;

typedef enum Scope
{
    LOCAL,
    GLOBAL
} Scope;

union constant
{
    int intval;
    char *strval;
};

typedef struct TypeTable
{
    Type type; // variable's type
    Type base; // variable's base type (for pointers)
    int size;
    struct Field *field;
} TypeTable;

typedef struct Field
{
    char *name;
    TypeTable *typetable;
    struct Field *next;
} Field;

typedef struct tnode
{
    int val;                     // for num
    char *strval;                // for str
    TypeTable *typetable;        // value type
    char *op;                    // operator symbol (for arithmetic operations)
    char *varname;               // variable name
    NodeType nodetype;           // to know info about node
    struct SymbolTable *STentry; // not used
    struct SymbolTable *Lentry;  // Local Entry (for functions)
    struct dimNode *dimNode;     // for accessing dimensions (for arrays)
    struct argList *argList;
    struct tnode *left, *right, *middle;
} tnode;

typedef struct SymbolTable
{
    char *name;                  // variable name
    TypeTable *typetable;        // variable type
    int size;                    // variable size
    int binding;                 // variable binding in stack
    int flabel;                  // function's label
    Scope scope;                 // scope of variable
    struct dimNode *dimNode;     // variable's declared dimension (for arrays)
    struct paramList *paramList; // for formal parameters (for functions)
    struct SymbolTable *next;
} SymbolTable;

typedef struct scopeStack
{
    SymbolTable *symbolTable;
    struct scopeStack *next, *prev;
} scopeStack;

typedef struct dimNode
{
    int val;
    tnode *tnode;
    struct dimNode *next;
} dimNode;

typedef struct paramList
{
    TypeTable *typetable;
    char *name;
    struct paramList *next;
} paramList;

typedef struct argList
{
    tnode *node;
    struct argList *next;
} argList;

#endif