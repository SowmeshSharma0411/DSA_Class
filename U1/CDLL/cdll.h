typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
} NODE;

typedef struct cdll
{
    NODE *head;
} CDLL;

void initList(CDLL *pl);
void insertFront(CDLL *pl, int ele);
void insertLast(CDLL *pl, int ele);
int insertAtPos(CDLL *pl, int ele, int pos);
void destroyList(CDLL *pl);
void display(CDLL *pl);
int deleteFront(CDLL *pl, int *pele);
int deleteLast(CDLL *pl, int *pele);
int deleteAtPos(CDLL *pl, int *pele, int pos);