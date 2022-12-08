#include <stdio.h>
#include <limits.h>
#include "postfixEv.h"

int main()
{
    char str[30];

    printf("Enter a valid postfix expression\n");
    scanf("%s", str);

    int res = postfixEval(str);
    if (res == INT_MAX)
        printf("Divide by Zero Error\n");
    else
        printf("Result=%d\n", res);
}