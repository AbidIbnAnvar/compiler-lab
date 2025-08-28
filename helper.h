#ifndef HELPER_H
#define HELPER_H

#include "tree.h"
#include <stdbool.h>

bool isOperatorNode(tnode *t);
bool isReadNode(tnode *t);
bool isWriteNode(tnode *t);
bool isAssignmentNode(tnode *t);
bool matchesOperator(tnode *t, char *op);

#endif