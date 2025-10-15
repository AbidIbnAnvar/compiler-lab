#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/constant.h"
#include "../helper/helper.h"
#include "../tree/tree.h"

scopeStack *sstop;
int nextBinding;
int currentFLabel;
int initialStackTop;

SymbolTable *createEntry(char *name, TypeTable *typetable, int size, int flabel, Scope scope, dimNode *dimNode, paramList *paramList, SymbolTable *next);
SymbolTable *lookupEntry(char *name, scopeStack *top);
SymbolTable *lookupSymbolTable(char *name, SymbolTable *head);
void createAndAppendEntry(char *name, TypeTable *typetable, int size, int flabel, Scope scope);
void appendEntry(SymbolTable *entry);
void showTable(SymbolTable *st);
int existsInSymbolTable(SymbolTable *head, char *name);
int existsInParamList(Field *head, char *name);
void checkparams(paramList *decl, paramList *def, char *fname);
void checkargs(argList *args, paramList *params, char *fname);
void printParamList(paramList *p);
char *getType(int type);
void freeTable(SymbolTable *head);
paramList *createParamList(TypeTable *typetable, char *name);
Field *createField(TypeTable *typetable, char *name);
argList *createArgList(tnode *node);
TypeTable *createTypeTable(Type type, Type base, int size, Field *field);
paramList *reverseParamList(paramList *head);
argList *reverseArgList(argList *head);
void pushToScopeStack(SymbolTable *scope, scopeStack **top);
SymbolTable *convertParamListToSymbolTable(paramList *paramList);
Field *convertToField(paramList *p);
void popFromScopeStack(scopeStack **top);
TypeTable *getFieldType(Field *field, char *name);

#endif