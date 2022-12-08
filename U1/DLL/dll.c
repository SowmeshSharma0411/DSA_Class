#include <stdio.h>
#include "dll.h"

int main()
{
    DLIST lobj;

    initList(&lobj);
    int choice;
    int ele;
    int status;
    int pos;
    do
    {
        printf("\n");
        printf("1.Insert Front 2.Insert Last 3.Display");
        printf("4. Delete Front 5.Delete Last ");
        printf("6.Insert At Pos 7. Delete at pos\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an integer\n");
            scanf("%d", &ele);
            insertFront(&lobj, ele);
            break;
        case 2:
            printf("Enter an integer\n");
            scanf("%d", &ele);
            insertLast(&lobj, ele);
            break;
        case 3:
            display(&lobj);
            break;

        case 4:
            status = deleteFront(&lobj, &ele);
            if (status)
                printf("Del ele is %d\n", ele);
            else
                printf("List is already empty\n");
            break;

        case 5:
            status = deleteLast(&lobj, &ele);
            if (status)
                printf("Del ele is %d\n", ele);
            else
                printf("List is already empty\n");
            break;

        case 6:
            printf("Enter an integer\n");
            scanf("%d", &ele);
            printf("Enter the pos\n");
            scanf("%d", &pos);
            status = insertAtPos(&lobj, ele, pos);
            if (status == 0)
                printf("Invalid position\n");
            break;
        case 7:
            printf("Enter the pos\n");
            scanf("%d", &pos);
            status = deleteAtPos(&lobj, &ele, pos);
            if (status)
                printf("Del ele is %d\n", ele);
            else
                printf("List is already empty or invalid pos\n");
            break;
        }
    } while (choice < 8);
    destroyList(&lobj);
}