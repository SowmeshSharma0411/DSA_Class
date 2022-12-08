typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct list
{
    NODE *last;
} CSLL;

void initList(CSLL *pl);
void insertFront(CSLL *pl, int ele);
void insertLast(CSLL *pl, int ele);
void display(CSLL *pl);
int deleteFront(CSLL *pl, int *pele);
void destroyList(CSLL *pl);
int deleteLast(CSLL *pl, int *pele);
int insertAtPos(CSLL *pl, int ele, int pos);
int deleteAtPos(CSLL *pl, int *pele, int pos);