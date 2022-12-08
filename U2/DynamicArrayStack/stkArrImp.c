#include <stdio.h>
#include <stdlib.h>
#include "stkArr.h"

void initStack(STACK *ps, int n)
{
    ps->size = n;
    ps->s = (int *)calloc(ps->size, sizeof(int));
    ps->top = -1;
}
int isFull(STACK *ps)
{
    return (ps->top == ps->size) ? 1 : 0;
}
int isEmpty(STACK *ps)
{
    return (ps->top == -1) ? 1 : 0;
}
void push(STACK *ps, int ele)
{
    if (isFull(ps))
        stackDouble(ps);
    else
        ps->s[++ps->top] = ele;
}
int pop(STACK *ps)
{
    return ps->s[ps->top--];
}
int stackTop(STACK *ps)
{
    return ps->s[ps->top];
}
void display(STACK *ps)
{
    int c = ps->top;
    printf("Ele :\n");
    while (c >= 0)
        printf("%d\n", ps->s[c--]);
}
void stackDouble(STACK *ps)
{
    ps->size = ps->size * 2;
    ps->s = realloc(ps->s, ps->size);
}
void destroyStack(STACK *ps)
{
    free(ps->s);
    ps->s = NULL;
    ps->size = 0;
    ps->top = -1;
}