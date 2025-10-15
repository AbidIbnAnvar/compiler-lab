#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "../helper/constant.h"
#include "../symbol_table/table.h"
#include "../array/array.h"

tnode *createTree(int val, char *op, TypeTable *type, char *varname, NodeType nodetype, tnode *l, tnode *m, tnode *r, SymbolTable *STentry);
void print_tree_structure(tnode *root, char *prefix, int is_last, int is_root);
void printTree(tnode *root);
void print_tree_compact(tnode *root, int depth);
void printTreeCompact(tnode *root);
void freeTree(tnode *t);

#endif