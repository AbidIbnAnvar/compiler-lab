#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../helper/constant.h"

dimNode *addDimension(int val, tnode *tnode, dimNode *next);
int getArraySize(dimNode *node);
#endif