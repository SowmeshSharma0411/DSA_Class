#include <stdio.h>
#include "deqArray.h"

int main()
{
    QUEUE qobj;

    initQueue(&qobj);

    int ele, choice, status;

    do
    {
        printf("1.EnqueueRear 2.EnqueueFront 3.DequeueFront 4.DequeueRear 5.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the integer data\n");
            scanf("%d", &ele);
            if (isFull(&qobj))
                printf("Queue is already full\n");
            else
                enqueueRear(&qobj, ele);
            break;
        case 2:
            printf("Enter the integer data\n");
            scanf("%d", &ele);
            if (isFull(&qobj))
                printf("Queue is already full\n");
            else
                enqueueFront(&qobj, ele);
            break;
        case 3:
            status = dequeueFront(&qobj, &ele);
            if (status == 0)
                printf("Queue is already empty\n");
            else
                printf("Deqd %d\n", ele);
            break;
        case 4:
            status = dequeueRear(&qobj, &ele);
            if (status == 0)
                printf("Queue is already empty\n");
            else
                printf("Deqd %d\n", ele);
            break;
        case 5:
            display(&qobj);
            break;
        }
    } while (choice < 6);
}