#include <stdio.h>
#include "expr.h"

int main()
{
    TREE tobj;

    initTree(&tobj);

    char postfix[20];

    printf("Enter the valid postfix expression\n");
    scanf("%s", postfix);

    exprTree(&tobj, postfix);

    int res = eval(&tobj);
    printf("Result=%d\n", res);
}