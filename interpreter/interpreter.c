#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "interpreter.h"
#include <stdbool.h>

int variables[26];

void evaluate_tree(tnode *t)
{
    if (t == NULL)
        return;
    if (isOperatorNode(t))
    {
        if (isAssignmentNode(t))
        {
            int offset = (t->left->varname[0] - 'a');
            int val = evaluate_expression(t->right);
            variables[offset] = val;
        }
        else if (isAritmeticNode(t) || isRelationalNode(t))
        {
            evaluate_expression(t);
        }
        return;
    }
    if (isReadNode(t))
    {
        int offset = t->left->varname[0] - 'a';
        int val;
        scanf("%d", &val);
        variables[offset] = val;
        return;
    }
    if (isWriteNode(t))
    {
        int val = evaluate_expression(t->left);
        printf("%d\n", val);
        return;
    }
    if (isIfElseNode(t))
    {
        int val = evaluate_expression(t->left);
        if (val)
        {
            evaluate_tree(t->middle);
        }
        else
        {
            if (t->right != NULL)
            {
                evaluate_tree(t->right);
            }
        }
        return;
    }
    if (isWhileNode(t))
    {
        int val = evaluate_expression(t->left);
        while (val)
        {
            evaluate_tree(t->right);
            val = evaluate_expression(t->left);
        }
        return;
    }
    evaluate_tree(t->left);
    evaluate_tree(t->right);
}

int evaluate_expression(tnode *t)
{
    if (t->left == NULL && t->right == NULL)
    {
        int val;
        if (t->varname == NULL)
        {
            val = t->val;
        }
        else
        {
            int offset = t->varname[0] - 'a';
            val = variables[offset];
        }
        return val;
    }
    int left_expression = evaluate_expression(t->left);
    int right_expression = evaluate_expression(t->right);
    int val = doOperation(t->op, left_expression, right_expression);
    return val;
}

int doOperation(char *op, int left, int right)
{
    if (strcmp(op, "+") == 0)
    {
        return left + right;
    }
    else if (strcmp(op, "-") == 0)
    {
        return left - right;
    }
    else if (strcmp(op, "*") == 0)
    {
        return left * right;
    }
    else if (strcmp(op, "/") == 0)
    {
        return left / right;
    }
    else if (strcmp(op, "<") == 0)
    {
        return left < right;
    }
    else if (strcmp(op, "<=") == 0)
    {
        return left == right;
    }
    else if (strcmp(op, ">") == 0)
    {
        return left == right;
    }
    else if (strcmp(op, ">=") == 0)
    {
        return left == right;
    }
    else if (strcmp(op, "!=") == 0)
    {
        return left == right;
    }
    else if (strcmp(op, "==") == 0)
    {
        return left == right;
    }
    return 0;
}
