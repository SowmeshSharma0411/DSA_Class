#include <stdio.h>
#include "circle.h"

int main()
{
    QUEUE qobj;

    initQueue(&qobj);

    int ele, choice, status;

    do
    {
        printf("1.Enqueue 2.Dequeue 3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the integer data\n");
            scanf("%d", &ele);
            if (isFull(&qobj))
                printf("Queue is already full\n");
            else
                enqueue(&qobj, ele);
            break;
        case 2:
            status = dequeue(&qobj, &ele);
            if (status == 0)
                printf("Queue is already empty\n");
            else
                printf("Deqd %d\n", ele);
            break;
        case 3:
            display(&qobj);
            break;
        }
    } while (choice < 4);
}