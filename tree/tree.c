#include "tree.h"
#include "../helper/helper.h"

tnode *createTree(int val, char *op, Type type, char *varname, NodeType nodetype, tnode *l, tnode *m, tnode *r, SymbolTable *STentry)
{
    if (nodetype == NODETYPE_OP_ASSIGNMENT)
    {
        if (type == TYPE_PTR)
        {
            // if(r->nodetype!=NODETYPE_REF){
            //     fprintf();
            // }
        }
    }
    else if (nodetype == NODETYPE_OP_ARITHMETIC)
    {
        if (l->type == TYPE_STR || r->type == TYPE_STR)
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            exit(1);
        }
        else if (strcmp(op, "+") == 0 && ((l->type != TYPE_INT && l->nodetype != NODETYPE_ACCESS) || (r->type != TYPE_INT && r->nodetype != NODETYPE_ACCESS)))
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            exit(1);
        }
    }
    else if (nodetype == NODETYPE_WHILE)
    {
        if (l->type != TYPE_INT)
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            printNode(l);
            exit(1);
        }
    }
    else if (nodetype == NODETYPE_IF)
    {
        if (l->type != TYPE_INT)
        {
            fprintf(stderr, "Error: Type Mismatch. Expected Integer\n");
            printNode(l);
            exit(1);
        }
    }
    tnode *tree = (tnode *)malloc(sizeof(tnode));
    tree->val = val;
    tree->type = type;
    tree->op = op;
    tree->varname = varname;
    tree->nodetype = nodetype;
    tree->left = l;
    tree->right = r;
    tree->middle = m;
    tree->STentry = STentry;
    tree->Lentry = NULL;
    tree->argList = NULL;
    return tree;
}

void print_tree_structure(tnode *root, char *prefix, int is_last, int is_root)
{
    if (root == NULL)
        return;

    // Print current node with connection lines
    if (!is_root)
    {
        printf("%s", prefix);
        printf("%s", is_last ? "└── " : "├── ");
    }

    // Print node information
    printf("[%s] ", nodetype_to_string(root->nodetype));
    if (root->varname)
        printf("name:%s ", root->varname);
    if (root->op)
        printf("op:%s ", root->op);
    printf("type:%s ", type_to_string(root->type));
    if (root->type == TYPE_INT)
    {
        printf("val:%d ", root->val);
    }
    if (root->type == TYPE_STR)
    {
        printf("val:%s ", root->strval);
    }
    printf("\n");

    // Count non-null children
    int child_count = 0;
    if (root->left)
        child_count++;
    if (root->middle)
        child_count++;
    if (root->right)
        child_count++;

    // Prepare prefix for children
    char new_prefix[256];
    if (is_root)
    {
        strcpy(new_prefix, "");
    }
    else
    {
        strcpy(new_prefix, prefix);
        strcat(new_prefix, is_last ? "    " : "│   ");
    }

    // Print children in order: left, middle, right
    int printed_children = 0;

    if (root->left)
    {
        printed_children++;
        print_tree_structure(root->left, new_prefix,
                             printed_children == child_count, 0);
    }

    if (root->middle)
    {
        printed_children++;
        print_tree_structure(root->middle, new_prefix,
                             printed_children == child_count, 0);
    }

    if (root->right)
    {
        printed_children++;
        print_tree_structure(root->right, new_prefix,
                             printed_children == child_count, 0);
    }
}

void printTree(tnode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("\nTree Structure:\n");
    printf("================\n");
    print_tree_structure(root, "", 1, 1);
    printf("\n");
}

void print_tree_compact(tnode *root, int depth)
{
    if (root == NULL)
        return;

    // Print indentation
    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }

    // Print node info compactly
    printf("|- [%s]", nodetype_to_string(root->nodetype));
    if (root->varname)
        printf(" %s", root->varname);
    if (root->op)
        printf(" (%s)", root->op);
    if (root->val != 0)
        printf(" val=%d", root->val);
    printf("\n");

    // Recursively print children
    if (root->left)
        print_tree_compact(root->left, depth + 1);
    if (root->middle)
        print_tree_compact(root->middle, depth + 1);
    if (root->right)
        print_tree_compact(root->right, depth + 1);
}

void printTreeCompact(tnode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("\nCompact Tree View:\n");
    printf("==================\n");
    print_tree_compact(root, 0);
    printf("\n");
}

void freeTree(tnode *t)
{
    if (t == NULL)
        return;
    freeTree(t->left);
    freeTree(t->middle);
    freeTree(t->right);
    if (t->varname)
        free(t->varname);
    free(t);
}