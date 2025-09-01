#ifndef HELPER_H
#define HELPER_H

#include "../tree/tree.h"
#include <stdbool.h>
#include <string.h>

bool isLeafNode(tnode *t);
bool isConnectorNode(tnode *t);
bool isArithmeticNode(tnode *t);
bool isRelationalNode(tnode *t);
bool isOperatorNode(tnode *t);
bool isReadNode(tnode *t);
bool isWriteNode(tnode *t);
bool isAssignmentNode(tnode *t);
bool isWhileNode(tnode *t);
bool isIfElseNode(tnode *t);
bool isBreakNode(tnode *t);
bool isContinueNode(tnode *t);
bool isRepeatUntilNode(tnode *t);
bool isDoWhileNode(tnode *t);
bool isDeclBlockNode(tnode *t);
bool isDeclNode(tnode *t);

bool matchesOperator(tnode *t, char *op);
bool isRelationalOperator(tnode *t);

void printArray(int arr[], int size);
void printNode(tnode *t);
void prefixprint(tnode *t);

#endif