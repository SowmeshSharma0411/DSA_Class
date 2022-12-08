#define MAX 3

typedef struct queue
{
    int a[MAX];
    int front;
    int rear;
} QUEUE;

void initQueue(QUEUE *pq);
int enqueue(QUEUE *pq, int ele);
int dequeue(QUEUE *pq, int *pele);
int isEmpty(QUEUE *pq);
int isFull(QUEUE *pq);
void display(QUEUE *pq);