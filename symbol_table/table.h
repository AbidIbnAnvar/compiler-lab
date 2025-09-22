#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include "../helper/constant.h"

Gsymbol *tableHead;
int nextBinding;

Gsymbol *createEntry(char *name, int type, int size, dimNode *dimNode, Gsymbol *next);
Gsymbol *Lookup(char *name);
void Install(char *name, int type, int size);
void ShowTable(Gsymbol *g);
char *GetType(int type);
void FreeGsymbolList(Gsymbol *head);
#endif