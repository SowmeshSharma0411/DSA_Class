#include <stdio.h>
#include "queuearr.h"

void initQueue(QUEUE *pq)
{
    pq->front = 0; // 0 it seems
    pq->rear = -1;
}
int isFull(QUEUE *pq)
{
    return pq->rear == MAX - 1;
}
int enqueue(QUEUE *pq, int ele)
{
    // insert from the back. xd
    if (isFull(pq)) // list full
        return 0;
    else
    {
        pq->a[++pq->rear] = ele;
        return 1;
    }
}
int isEmpty(QUEUE *pq)
{
    return pq->rear < pq->front;
}
int dequeue(QUEUE *pq, int *pele)
{
    if (isEmpty(pq))
        return 0;
    else
    {
        *pele = pq->a[pq->front++];
        return 1;
    }
}
void display(QUEUE *pq)
{
    int i = pq->front;
    printf("Elements of queue : \n");
    while (i <= pq->rear)
    {
        printf("%d\n", pq->a[i++]);
    }
    printf("\n");
}