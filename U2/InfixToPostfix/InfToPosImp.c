#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfToPos.h"

void initStack(STACK *ps)
{
    ps->top = -1;
}
int isFull(STACK *ps)
{
    return ps->top == MAX - 1;
}
int isEmpty(STACK *ps)
{
    return ps->top == -1;
}
void push(STACK *ps, char ele)
{
    ps->a[++ps->top] = ele;
}
char pop(STACK *ps)
{
    return ps->a[ps->top--];
}
char stackTop(STACK *ps)
{
    return ps->a[ps->top];
}
int precedence(char st, char in)
{
    //^,*/,+-
    //>1 ; =1 ; <1
    switch (in)
    {
    case '+':
    case '-':
        if (st == '(')
            return 0;
        else
            return 1;

    case '*':
    case '/':
        if (st == '+' || st == '-' || st == '(')
            return 0;
        else
            return 1;
    case '(':
        return 0;

    case ')':
        if (st == '(')
            return 0;
        else
            return 1;
    }
}
void infixToPostfix(char infix[], char postfix[])
{
    STACK obj;
    initStack(&obj);
    int j = 0;
    char waste;
    // STACK *ptr = &obj;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if ((int)(infix[i]) >= 65 && (int)(infix[i]) <= 90)
        {
            postfix[j++] = infix[i];
        }
        else
        {
            while (!isEmpty(&obj) && precedence(stackTop(&obj), infix[i]))
            {
                postfix[j++] = pop(&obj);
            }
            if (infix[i] == ')')
                waste = pop(&obj);
            else
                push(&obj, infix[i]);
        }
    }
    while (!isEmpty(&obj))
        postfix[j++] = pop(&obj);
    postfix[j] = '\0';
}