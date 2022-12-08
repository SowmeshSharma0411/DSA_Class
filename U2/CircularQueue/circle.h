// Circular Queue using Mod
#define MAX 5
typedef struct queue
{
    int q[MAX];
    int front;
    int rear;
} QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq, int ele);
int dequeue(QUEUE *pq, int *pele);
int isEmpty(QUEUE *pq);
int isFull(QUEUE *pq);
void display(QUEUE *pq);