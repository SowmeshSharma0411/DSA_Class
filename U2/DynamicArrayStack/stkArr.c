#include <stdio.h>
#include "stkArr.h"

int main()
{
    STACK sobj;

    int n = 3;
    initStack(&sobj, n);

    int choice;
    int ele;

    do
    {
        printf("1.Push 2.Pop 3.Display 4.Peek\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an integer\n");
            scanf("%d", &ele);
            push(&sobj, ele);
            break;

        case 2:
            if (!isEmpty(&sobj))
            {
                ele = pop(&sobj);
                printf("Popped %d\n", ele);
            }
            else
                printf("Stack is Empty\n");
            break;

        case 3:
            display(&sobj);
            break;

        case 4:
            if (!isEmpty(&sobj))
            {
                ele = stackTop(&sobj);
                printf("Stack top is %d\n", ele);
            }
            else
                printf("Stack is Empty\n");
            break;
        }
    } while (choice < 5);

    destroyStack(&sobj);
}