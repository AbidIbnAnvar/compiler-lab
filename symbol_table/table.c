#include "table.h"

scopeStack *sstop = NULL;
int nextBinding = 4096;
int initialStackTop = 4095;
int currentFLabel = 1;

SymbolTable *createEntry(char *name, TypeTable *typetable, int size, int flabel, Scope scope, dimNode *dimNode, paramList *paramList, SymbolTable *next)
{
    SymbolTable *entry = (SymbolTable *)malloc(sizeof(SymbolTable));
    entry->name = name;
    entry->typetable = typetable;
    if (flabel == -1)
    {
        entry->size = size;
        entry->binding = nextBinding;
        nextBinding += size;
        initialStackTop = max(initialStackTop, nextBinding - 1);
    }
    else
    {
        entry->size = 0;
        entry->binding = -1;
    }
    entry->scope = scope;
    entry->flabel = flabel;
    entry->dimNode = dimNode;
    entry->paramList = paramList;
    entry->next = next;
    return entry;
}

SymbolTable *lookupEntry(char *name, scopeStack *top)
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

SymbolTable *lookupSymbolTable(char *name, SymbolTable *head)
{
    SymbolTable *currEntry = head;
    while (currEntry)
    {
        if (strcmp(currEntry->name, name) == 0)
        {
            return currEntry;
        }
        currEntry = currEntry->next;
    }
    return NULL;
}

void createAndAppendEntry(char *name, TypeTable *typetable, int size, int flabel, Scope scope)
{
    if (!sstop)
    {
        sstop = (scopeStack *)malloc(sizeof(scopeStack));
        sstop->symbolTable = createEntry(name, typetable, size, flabel, scope, NULL, NULL, NULL);
        sstop->prev = NULL;
        sstop->next = NULL;
        return;
    }
    SymbolTable *curr = sstop->symbolTable;
    if (curr == NULL)
    {
        sstop->symbolTable = createEntry(name, typetable, size, flabel, scope, NULL, NULL, NULL);
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
        curr->next = createEntry(name, typetable, size, flabel, scope, NULL, NULL, NULL);
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

void checkparams(paramList *decl, paramList *def, char *fname)
{
    while (decl && def)
    {
        if (decl->typetable->type != def->typetable->type)
        {
            fprintf(stderr, "Error: Invalid Parameter for %s()\n", fname);
            exit(1);
        }
        decl = decl->next;
        def = def->next;
    }
    if ((!decl && def) || (decl && !def))
    {
        fprintf(stderr, "Error: Invalid Parameter for %s()\n", fname);
        exit(1);
    }
}

void checkargs(argList *args, paramList *params, char *fname)
{
    while (args && params)
    {
        if (args->node->typetable->type != params->typetable->type)
        {
            fprintf(stderr, "Error: Invalid Argument for %s()\n", fname);
            exit(1);
        }
        args = args->next;
        params = params->next;
    }
    if ((args && !params) || (!args && params))
    {
        fprintf(stderr, "Error: Invalid Argument for %s()\n", fname);
        exit(1);
    }
}

void showTable(SymbolTable *st)
{
    SymbolTable *curr = st;
    printf("+----------------+--------+--------+------+---------+--------+--------+\n");
    printf("| Name           | Type   | Base   | Size | Binding | FLabel | Scope  |\n");
    printf("+----------------+--------+--------+------+---------+--------+--------+\n");

    while (curr != NULL)
    {
        // Adjust field widths as needed for your actual data
        printf("| %-14s | %-6s | %-6s | %-4d | %-7d | %-6d | %-6s |\n",
               curr->name, getType(curr->typetable->type), getType(curr->typetable->base), curr->size, curr->binding, curr->flabel, (curr->scope == LOCAL ? "Local" : "Global"));

        Field *f = curr->typetable->field;
        int index = 0;
        while (f != NULL)
        {
            printf("| └─ %-11.11s | %-6s | %-6s | %-4d | └─ %-4d | %-6d | %-6s |\n",
                   f->name, getType(f->typetable->type), getType(f->typetable->base), 1, curr->binding + index++, -1, (curr->scope == LOCAL ? "Local" : "Global"));
            f = f->next;
        }

        curr = curr->next;
    }

    printf("+----------------+--------+--------+------+---------+--------+--------+\n");
}

void printParamList(paramList *p)
{
    paramList *curr = p;
    printf("+----------------+--------+\n");
    printf("| Name           | Type   |\n");
    printf("+----------------+--------+\n");
    while (curr != NULL)
    {
        // Adjust field widths as needed for your actual data
        printf("| %-14s | %-6s |\n",
               curr->name, getType(curr->typetable->type));
        curr = curr->next;
    }
    printf("+----------------+--------+\n");
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
    case TYPE_TUPLE:
        return "tuple";
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

paramList *createParamList(TypeTable *typetable, char *name)
{
    paramList *node = (paramList *)malloc(sizeof(paramList));
    node->name = name;
    node->typetable = typetable;
    return node;
}

argList *createArgList(tnode *node)
{
    argList *arg = (argList *)malloc(sizeof(argList));
    arg->node = node;
    arg->next = NULL;
    return arg;
}

paramList *reverseParamList(paramList *head)
{
    paramList *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Field *createField(TypeTable *typetable, char *name)
{
    Field *node = (Field *)malloc(sizeof(Field));
    node->name = name;
    node->typetable = typetable;
    node->next = NULL;
    return node;
}
// TODO: Add size to type table
TypeTable *createTypeTable(Type type, Type base, int size, Field *field)
{
    TypeTable *node = (TypeTable *)malloc(sizeof(TypeTable));
    node->type = type;
    node->base = base;
    node->size = size;
    node->field = field;
    return node;
}

argList *reverseArgList(argList *head)
{
    argList *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
        if (existsInSymbolTable(head, plist->name))
        {
            fprintf(stderr, "Error: Duplicate parameter name '%s'\n", plist->name);
            exit(1);
        }
        SymbolTable *node = (SymbolTable *)malloc(sizeof(SymbolTable));
        node->name = plist->name;
        node->typetable = plist->typetable;
        node->size = 1;
        node->binding = nextBinding;
        nextBinding -= 1;
        node->flabel = -1;
        node->scope = LOCAL;
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

Field *convertToField(paramList *p)
{
    if (!p)
        return NULL;

    Field *head = NULL;
    Field *curr = NULL;
    while (p)
    {
        if (existsInParamList(head, p->name))
        {
            fprintf(stderr, "Error: Duplicate parameter name '%s'\n", p->name);
            exit(1);
        }
        Field *node = createField(p->typetable, p->name);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            curr->next = node;
        }
        curr = node;
        p = p->next;
    }
    return head;
}

TypeTable *getFieldType(Field *field, char *name)
{
    Field *curr = field;
    while (curr)
    {
        if (strcmp(curr->name, name) == 0)
        {
            return curr->typetable;
        }
        curr = curr->next;
    }
    fprintf(stderr, "Error: Field %s not found\n", name);
    exit(1);
}

int existsInSymbolTable(SymbolTable *head, char *name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
            return 1;
        head = head->next;
    }
    return 0;
}

int existsInParamList(Field *head, char *name)
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