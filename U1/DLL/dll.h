typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
} NODE;

typedef struct list
{
    NODE *head;
} DLIST;

void initList(DLIST *pl);
void insertFront(DLIST *pl, int ele);
void insertLast(DLIST *pl, int ele);
void display(DLIST *pl);
int deleteFront(DLIST *pl, int *pele);
void destroyList(DLIST *pl);
int deleteLast(DLIST *pl, int *pele);
int insertAtPos(DLIST *pl, int ele, int pos);
int deleteAtPos(DLIST *pl, int *pele, int pos);