#include <stdio.h>
#include "deqArray.h"

// dry run this shit.

void initQueue(QUEUE *pq)
{
    pq->front = -1;
    pq->rear = -1;
}
int isEmpty(QUEUE *pq)
{
    return pq->rear == -1;
}
int isFull(QUEUE *pq)
{
    return (pq->rear + 1) % MAX == pq->front;
}
void enqueueRear(QUEUE *pq, int ele)
{
    if (isEmpty(pq)) // list empty
    {
        pq->front = 0;
        pq->rear = 0;
    }
    else
        pq->rear = (pq->rear + 1) % MAX;
    pq->q[pq->rear] = ele;
}
void enqueueFront(QUEUE *pq, int ele)
{
    if (isEmpty(pq)) // list empty
    {
        pq->front = 0;
        pq->rear = 0;
    }
    else
        pq->front = (pq->front + MAX - 1) % MAX;
    pq->q[pq->front] = ele;
}
int dequeueRear(QUEUE *pq, int *pele)
{
    if (isEmpty(pq))
        return 0;
    else if (pq->front == pq->rear) // 1 ele case.
    {
        *pele = pq->q[pq->rear];
        initQueue(pq);
        return 1;
    }
    else
    {
        *pele = pq->q[pq->rear];
        pq->rear = (pq->rear + MAX - 1) % MAX; //(pq->rear=(pq->rea-1+MAX)%MAX)
        return 1;
    }
}
int dequeueFront(QUEUE *pq, int *pele)
{
    if (isEmpty(pq))
        return 0;
    else if (pq->front == pq->rear) // 1 ele case.
    {
        *pele = pq->q[pq->front];
        initQueue(pq);
        return 1;
    }
    else
    {
        *pele = pq->q[pq->front];
        pq->front = (pq->front + 1) % MAX;
        return 1;
    }
}
void display(QUEUE *pq)
{
    printf("Elements : \n");
    if (isEmpty(pq))
        return;
    int i = 0;
    for (i = pq->front; i != pq->rear; i = (i + 1) % MAX)
    {
        printf("%d ", pq->q[i]);
    }
    printf("%d\n", pq->q[i]);
}