#include <stdio.h>
#include "par.h"

int main()
{
    char str[30];

    printf("Enter a parenthesized expression\n");
    scanf("%s", str);

    if (checkBalanceParentheses(str))
        printf("Balanced\n");
    else
        printf("Not balanced\n");
}