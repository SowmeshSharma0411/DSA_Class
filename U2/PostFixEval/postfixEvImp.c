#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include "postfixEv.h"

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

void push(STACK *ps, int ele)
{
    ps->s[++(ps->top)] = ele;
}
int pop(STACK *ps)
{
    return (ps->s[ps->top--]);
}
int top(STACK *ps)
{
    return (ps->s[ps->top]);
}
int postfixEval(char str[])
{
    STACK obj;
    initStack(&obj);

    for (int i = 0; str[i] != '\0'; i++)
    {
        int exp = 0;
        int a = 0, b = 0;
        if ((int)(str[i]) >= 48 && (int)(str[i]) <= 57)
            push(&obj, str[i] - '0');
        else
        {
            a = pop(&obj);
            b = pop(&obj);
            // printf("%d %d\n", b, a);
            printf("%d top :\n", top(&obj));
            switch (str[i])
            {
            case '+':
                // printf("+ : %d\n", b + a);
                exp = (b + a);
                break;
            case '-':
                // printf("- : %d\n", b - a);
                exp = (b - a);
                break;
            case '*':
                // printf("* : %d\n", b * a);
                exp = (b * a);
                break;
            case '/':
                // printf("/ : %d\n", b / a);
                if (a == 0)
                    return INT_MAX;
                exp = (b / a);
                break;
            }
            push(&obj, exp);
        }
    }
    return top(&obj);
}