#include <stdio.h>
#include <stdlib.h>
#include "PrioQueue.h"

int main()
{
    QUEUE qobj;

    initQueue(&qobj);

    enqueue(&qobj, 100, 100);

    enqueue(&qobj, 10, 10);
    enqueue(&qobj, 50, 50);

    display(&qobj);

    if (qobj.front != NULL)
        printf("%d\n", minDelete(&qobj));

    if (qobj.front != NULL)
        printf("%d\n", minDelete(&qobj));

    destroyQueue(&qobj);
}
