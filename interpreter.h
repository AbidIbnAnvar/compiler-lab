#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include "tree.h"

void evaluate_tree(tnode *tree);
int evaluate_expression(tnode *t);
int doOperation(char *op, int left, int right);

#endif
