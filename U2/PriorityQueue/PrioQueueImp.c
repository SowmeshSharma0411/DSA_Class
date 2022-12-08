#include <stdio.h>
#include <stdlib.h>
#include "PrioQueue.h"

void initQueue(QUEUE *pq)
{
    pq->front = NULL;
}
NODE *create(int data, int pty)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->info = data;
    newnode->pri = pty;
    newnode->next = NULL;
    return newnode;
}
void enqueue(QUEUE *pq, int ele, int pty)
{
    // if (pq->front == NULL) // empty queue
    // {
    //     pq->front->info = ele;
    //     pq->front->pri = pty;
    //     pq->front->next = NULL;
    //     return;
    // }
    NODE *newnode = create(ele, pty);
    if (!pq->front || pty > pq->front->pri) // insert front case
    {
        newnode->next = pq->front;
        pq->front = newnode;
        return;
    }
    NODE *iter = pq->front;
    NODE *q;
    while (iter && iter->pri > pty)
    {
        q = iter;
        iter = iter->next;
    }
    q->next = newnode;
    newnode->next = iter;
}
int minDelete(QUEUE *pq)
{
    if (pq->front == NULL) // empty queue
        return -1;
    NODE *temp = pq->front;
    pq->front = pq->front->next;
    int ele = temp->info;
    free(temp);
    temp = NULL;
    return ele;
}
void display(QUEUE *pq)
{
    NODE *iter = pq->front;
    printf("Ele : Prio\n");
    while (iter)
    {
        printf("%d : %d\n", iter->info, iter->pri);
        iter = iter->next;
    }
}
void destroyQueue(QUEUE *pq)
{
    NODE *p = pq->front;
    while (pq->front != NULL)
    {
        pq->front = pq->front->next;
        printf("%d freed\n", p->info);
        free(p);
        p = pq->front;
    }
}