#include "table.h"
#include "../helper/constant.h"

scopeStack *sstop = NULL;
int nextBinding = 4096;
int currentFLabel = 0;

SymbolTable *createEntry(char *name, int type, int size, dimNode *dimNode, paramList *paramList, SymbolTable *next)
{
    SymbolTable *entry = (SymbolTable *)malloc(sizeof(SymbolTable));
    entry->name = name;
    entry->type = type;
    entry->size = size;
    entry->binding = nextBinding;
    nextBinding += size;
    entry->flabel = -1;
    entry->dimNode = dimNode;
    entry->paramList = paramList;
    entry->next = next;
    return entry;
}

struct SymbolTable *lookupEntry(char *name, scopeStack *top)
{
    scopeStack *curr = top;
    while (curr)
    {
        SymbolTable *currEntry = curr->symbolTable;
        while (currEntry)
        {
            if (strcmp(currEntry->name, name) == 0)
            {
                return currEntry;
            }
            currEntry = currEntry->next;
        }
        curr = curr->prev;
    }
    fprintf(stderr, "Error: variable %s not declared\n", name);
    exit(1);

    return NULL;
}

void createAndAppendEntry(char *name, int type, int size)
{
    if (!sstop)
    {
        sstop = (scopeStack *)malloc(sizeof(scopeStack));
        sstop->symbolTable = createEntry(name, type, size, NULL, NULL, NULL);
        sstop->prev = NULL;
        sstop->next = NULL;
        return;
    }
    SymbolTable *curr = sstop->symbolTable;
    if (curr == NULL)
    {
        sstop->symbolTable = createEntry(name, type, size, NULL, NULL, NULL);
    }
    else
    {
        while (curr->next != NULL)
        {
            if (strcmp(curr->name, name) == 0)
            {
                fprintf(stderr, "Error occurred in installing");
                exit(1);
            }
            curr = curr->next;
        }
        curr->next = createEntry(name, type, size, NULL, NULL, NULL);
    }
}

void appendEntry(SymbolTable *entry)
{
    if (!sstop)
    {
        sstop = (scopeStack *)malloc(sizeof(scopeStack));
        sstop->symbolTable = entry;
        sstop->prev = NULL;
        sstop->next = NULL;
        return;
    }
    SymbolTable *curr = sstop->symbolTable;
    if (curr == NULL)
    {
        sstop->symbolTable = entry;
    }
    else
    {
        while (curr->next != NULL)
        {
            if (strcmp(curr->name, entry->name) == 0)
            {
                fprintf(stderr, "Error occurred in installing");
                exit(1);
            }
            curr = curr->next;
        }
        curr->next = entry;
    }
}

// void appendEntryToGlobal(SymbolTable *entry)
// {
//     if (!sstop)
//     {
//         sstop = (scopeStack *)malloc(sizeof(scopeStack));
//         sstop->symbolTable = entry;
//         sstop->prev = NULL;
//         sstop->next = NULL;
//         return;
//     }
//     scopeStack *curr = sstop;
//     while (curr->prev)
//     {
//         curr = curr->prev;
//     }
//     SymbolTable *stTable = sstop->symbolTable;
//     if (!gTable)
//     {
//         gTable = entry;
//     }
//     else
//     {
//         SymbolTable *currEntry = gTable;
//         while (currEntry->next)
//         {
//             currEntry = currEntry->next;
//         }
//         currEntry->next = entry;
//     }
// }

void showTable(SymbolTable *st)
{
    SymbolTable *curr = st;
    printf("+----------------+--------+--------+------+---------+--------+\n");
    printf("| Name           | Type   | Base   | Size | Binding | FLabel |\n");
    printf("+----------------+--------+--------+------+---------+--------+\n");

    while (curr != NULL)
    {
        // Adjust field widths as needed for your actual data
        printf("| %-14s | %-6s | %-6s | %-4d | %-7d | %-6d |\n",
               curr->name, getType(curr->type), getType(curr->vartype), curr->size, curr->binding, curr->flabel);
        curr = curr->next;
    }

    printf("+----------------+--------+--------+------+---------+--------+\n");
}

char *getType(int type)
{
    switch (type)
    {
    case TYPE_INT:
        return "int";
    case TYPE_STR:
        return "string";
    case TYPE_BOOL:
        return "bool";
    case TYPE_PTR:
        return "ptr";
    default:
        return "-";
    }
}

void freeTable(SymbolTable *head)
{
    SymbolTable *curr = head;
    while (curr)
    {
        SymbolTable *tmp = curr;
        curr = curr->next;
        if (tmp->name)
            free(tmp->name);
        free(tmp);
    }
}

paramList *createParamList(Type type, char *name)
{
    paramList *node = (paramList *)malloc(sizeof(paramList));
    node->name = strdup(name);
    node->type = type;
    return node;
}

void pushToScopeStack(SymbolTable *scope, scopeStack **top)
{
    scopeStack *node = (scopeStack *)malloc(sizeof(scopeStack));
    node->symbolTable = scope;
    node->next = NULL;
    if (!(*top))
    {
        node->prev = NULL;
        *top = node;
    }
    else
    {
        node->prev = (*top);
        (*top)->next = node;
        (*top) = node;
    }
}

SymbolTable *convertParamListToSymbolTable(paramList *plist)
{
    if (!plist)
        return NULL;

    SymbolTable *head = NULL;
    SymbolTable *curr = NULL;
    while (plist)
    {
        if (exists(head, plist->name))
        {
            fprintf(stderr, "Error: Duplicate parameter name '%s'\n", plist->name);
            exit(1);
        }
        SymbolTable *node = (SymbolTable *)malloc(sizeof(SymbolTable));
        node->name = plist->name;
        node->type = plist->type;
        node->size = 1;
        node->binding = nextBinding;
        nextBinding += 1;
        node->flabel = -1;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            curr->next = node;
        }
        curr = node;
        plist = plist->next;
    }
    return head;
}

int exists(SymbolTable *head, char *name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
            return 1;
        head = head->next;
    }
    return 0;
}

void popFromScopeStack(scopeStack **top)
{
    if (!top || !(*top))
        return;
    (*top) = (*top)->prev;
    if (*top)
    {
        (*top)->next = NULL;
    }
}