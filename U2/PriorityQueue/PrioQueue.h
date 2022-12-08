// Ascending Priority Queue, Ordered Linked List Implementation
typedef struct node
{
    int info;
    int pri;
    struct node *next;
} NODE;

typedef struct queue
{
    NODE *front;
} QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq, int ele, int pty);
void display(QUEUE *pq);
int minDelete(QUEUE *pq);
void destroyQueue(QUEUE *pq);