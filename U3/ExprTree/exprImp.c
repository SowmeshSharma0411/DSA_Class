#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "expr.h"

void initTree(TREE *pt)
{
    pt->root = NULL;
}
void initStack(STACK *ps)
{
    ps->top = -1;
}
void push(STACK *ps, NODE *pn)
{
    ps->s[++ps->top] = pn;
}
NODE *createNode(int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->info = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
NODE *pop(STACK *ps)
{
    return ps->s[(ps->top)--];
}
void exprTree(TREE *pt, char expr[])
{
    STACK stk;
    initStack(&stk);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        NODE *newnode = createNode(expr[i]);
        if ((int)expr[i] >= 48 && (int)expr[i] <= 57)
        {
            push(&stk, newnode);
        }
        else
        {
            newnode->right = pop(&stk);
            newnode->left = pop(&stk);
            push(&stk, newnode);
        }
    }
    pt->root = pop(&stk);
}
int evalNode(NODE *n)
{
    int res;
    switch (n->info)
    {
    case '+':
        res = evalNode(n->left) + evalNode(n->right);
        break;
    case '-':
        res = evalNode(n->left) - evalNode(n->right);
        break;
    case '*':
        res = evalNode(n->left) * evalNode(n->right);
        break;
    case '/':
        res = evalNode(n->left) / evalNode(n->right);
        break;
    case '^':
        res = evalNode(n->left) ^ evalNode(n->right);
        break;
    default:
        res = n->info - '0';
    }
    return res;
}
int eval(TREE *pt)
{
    return evalNode(pt->root);
}