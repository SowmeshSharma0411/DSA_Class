#include <stdio.h>
#include "sll.h"

int main()
{
    LLIST lobj;

    initList(&lobj);
    int choice;
    int ele;
    int status;
    int pos;
    do
    {
        printf("\n");
        printf("1.Insert Front 2.Insert Last 3.Display");
        printf("4. Delete Front 5.Delete Front 6.Delete Last ");
        printf("7.Insert At Pos 8. Delete at pos\n");
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
            if (lobj.head == NULL)
                printf("List is already empty\n");
            else
            {
                ele = deleteFront1(&lobj);
                printf("Del ele is %d\n", ele);
            }
            break;
        case 5:
            status = deleteFront2(&lobj, &ele);
            if (status)
                printf("Del ele is %d\n", ele);
            else
                printf("List is already empty\n");
            break;

        case 6:
            if (lobj.head == NULL)
                printf("List is already empty\n");
            else
            {
                ele = deleteLast(&lobj);
                printf("Del ele is %d\n", ele);
            }
            break;

        case 7:
            printf("Enter an integer\n");
            scanf("%d", &ele);
            printf("Enter the pos\n");
            scanf("%d", &pos);
            status = insertAtPos(&lobj, ele, pos);
            if (status == 0)
                printf("Invalid position\n");
            break;
        case 8:
            printf("Enter the pos\n");
            scanf("%d", &pos);
            status = deleteAtPos(&lobj, &ele, pos);
            if (status)
                printf("Del ele is %d\n", ele);
            else
                printf("List is already empty or invalid pos\n");
            break;
        }
    } while (choice < 9);
    destroyList(&lobj);
}