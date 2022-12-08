#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

// lil conf.

void initQueue(QUEUE *pq)
{
    pq->rear = -1;
    pq->front = -1;
}
void enqueue(QUEUE *pq, int ele)
{
    // from the end.86189881278
    if (isEmpty(pq))
    {
        pq->front = 0;
        pq->rear = 0;
    }
    else
        pq->rear = (pq->rear + 1) % MAX;
    pq->q[pq->rear] = ele;
    // pq->front = (pq->rear - 1) % MAX;
}
int dequeue(QUEUE *pq, int *pele)
{
    if (isEmpty(pq))
        return 0;
    else if (pq->front == pq->rear)
    {
        *pele = pq->q[pq->front];
        initQueue(pq);
    }
    else
    {
        *pele = pq->q[pq->front];
        pq->front = (pq->front + 1) % MAX;
    }
    return 1;
}
int isEmpty(QUEUE *pq)
{
    return pq->front == -1;
}
int isFull(QUEUE *pq)
{
    return (pq->rear + 1) % MAX == pq->front;
}
void display(QUEUE *pq)
{
    printf("Elements :\n");
    if (isEmpty(pq))
        return;
    int i = 0;
    for (i = pq->front; i != pq->rear; i = (i + 1) % MAX)
    {
        printf("%d\n", pq->q[i]);
    }
    printf("%d\n", pq->q[i]);
}
