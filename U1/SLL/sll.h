typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct llist
{
    NODE *head;
} LLIST;

void initList(LLIST *pl);
void insertFront(LLIST *pl, int ele);
void insertLast(LLIST *pl, int ele);
void display(LLIST *pl);
/*
Precondition: List is already created and not empty
*/
int deleteFront1(LLIST *pl);
/*List is created and may be empty or may have nodes*/
// Return value: indicates success or failure status
int deleteFront2(LLIST *pl, int *pele);
void destroyList(LLIST *pl);

/*
Precondition: List is already created and not empty
*/
int deleteLast(LLIST *pl);
int insertAtPos(LLIST *pl, int ele, int pos);
int deleteAtPos(LLIST *pl, int *pele, int pos);