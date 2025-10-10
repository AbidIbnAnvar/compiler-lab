#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/constant.h"

scopeStack *sstop;
int nextBinding;
int currentFLabel;

SymbolTable *createEntry(char *name, int type, int size, dimNode *dimNode, paramList *paramList, SymbolTable *next);
SymbolTable *lookupEntry(char *name, scopeStack *top);
void createAndAppendEntry(char *name, int type, int size);
void appendEntry(SymbolTable *entry);
// void appendEntryToGlobal(SymbolTable *entry);
void showTable(SymbolTable *st);
int exists(SymbolTable *head, char *name);
void checkparams(paramList *decl, paramList *def, char *fname);
void checkargs(argList *args, paramList *params, char *fname);
void printParamList(paramList *p);
char *getType(int type);
void freeTable(SymbolTable *head);
paramList *createParamList(Type type, char *name);
argList *createArgList(tnode *node);
void pushToScopeStack(SymbolTable *scope, scopeStack **top);
SymbolTable *convertParamListToSymbolTable(paramList *paramList);
void popFromScopeStack(scopeStack **top);

#endif