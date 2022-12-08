#include <stdio.h>
#include "InfToPos.h"

int main()
{
    char infix[30], postfix[30];

    printf("Enter a valid infix expression\n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
}