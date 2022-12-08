#include <stdio.h>
#include <stdlib.h>
#include "par.h"

void initStack(STACK *ps)
{
    ps->top = -1;
    // ps->s = (int *)calloc(MAX, sizeof(int));
}
int isEmpty(STACK *ps)
{
    return (ps->top == -1) ? 1 : 0;
}
void push(STACK *ps, char ele)
{
    ps->s[++ps->top] = ele;
}
char pop(STACK *ps)
{
    return ps->s[ps->top--];
}
int checkBalanceParentheses(char str[])
{
    STACK obj;
    initStack(&obj);

    STACK *ptr = &obj;
    for (int i = 0; i < 30; i++)
    {
        char popped;
        if (str[i] == '{' || str[i] == '(' || str[i] == ']')
            push(ptr, str[i]);
        if (!isEmpty(ptr))
        {
            if (str[i] == '}' && ptr->s[ptr->top] == '{')
                popped = pop(ptr);
            if (str[i] == ']' && ptr->s[ptr->top] == '[')
                popped = pop(ptr);
            if (str[i] == ')' && ptr->s[ptr->top] == '(')
                popped = pop(ptr);
        }
        else
            return 1;
    }
    return 0;
}