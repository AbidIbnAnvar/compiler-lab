#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/constant.h"

int nextBinding = 4096;

Gsymbol *createEntry(char *name, int type, int size, dimNode *dimNode, Gsymbol *next)
{
    Gsymbol *entry = (Gsymbol *)malloc(sizeof(Gsymbol));
    entry->name = name;
    entry->type = type;
    entry->size = size;
    entry->binding = nextBinding;
    nextBinding += size;
    entry->dimNode = dimNode;
    entry->next = next;
    return entry;
}

struct Gsymbol *Lookup(char *name)
{
    Gsymbol *curr = tableHead;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
        {
            return curr;
        }
        curr = curr->next;
    }
        printf("Error: variable %s not declared", name);
        exit(1);

    return NULL;
}

void Install(char *name, int type, int size)
{
    Gsymbol *curr = tableHead;
    if (curr == NULL)
    {
        tableHead = createEntry(name, type, size, NULL, NULL);
    }
    else
    {
        while (curr->next != NULL)
        {
            if (strcmp(curr->name, name) == 0)
            {
                perror("Error occurred in installing");
                return;
            }
            curr = curr->next;
        }
        curr->next = createEntry(name, type, size, NULL, NULL);
    }
}

void ShowTable(Gsymbol *g)
{
    Gsymbol *curr = g;
    printf("+----------------+--------+------+---------+\n");
    printf("| Name           | Type   | Size | Binding |\n");
    printf("+----------------+--------+------+---------+\n");

    while (curr != NULL)
    {
        // Adjust field widths as needed for your actual data
        printf("| %-14s | %-6s | %-4d | %-7d |\n",
               curr->name, GetType(curr->type), curr->size, curr->binding);
        curr = curr->next;
    }

    printf("+----------------+--------+------+---------+\n");
}

char *GetType(int type)
{
    switch (type)
    {
    case TYPE_INT:
        return "int";
    case TYPE_STRING:
        return "string";
    default:
        return "";
    }
}

void FreeGsymbolList(Gsymbol *head)
{
    Gsymbol *curr = head;
    while (curr)
    {
        Gsymbol *tmp = curr;
        curr = curr->next;
        if (tmp->name)
            free(tmp->name);
        free(tmp);
    }
}