// merge 2 doubly linked lists.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next, *prev;
} NODE;
typedef struct list
{
    NODE *head;
} DLIST;

void initList(DLIST *pl)
{
    pl->head = NULL;
}

NODE *CreateNode(int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insertLast(DLIST *pl, int ele)
{
    NODE *newnode = CreateNode(ele);
    if (pl->head == NULL)
    {
        pl->head = newnode;
        return;
    }
    NODE *tail = pl->head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    newnode->next = NULL;
}
void display(DLIST *pl)
{
    NODE *iter = pl->head;

    if (pl->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (iter != NULL)
    {
        printf("%d ", iter->data);
        iter = iter->next;
    }
}
void merge(DLIST *lst1, DLIST *lst2, DLIST lst3)
{
    NODE *iter1 = lst1->head;
    NODE *iter2 = lst2->head;
    // if (iter1->data < iter2->data)
    //     lst3->head = iter1;
    // else
    //     lst3->head = iter2;
    // NODE *iter3 = lst3->head;

    while (iter1 != NULL && iter2 != NULL)
    {
        if (iter2->data < iter1->data)
        {
            // iter3->next = iter1;
            // iter1->prev = iter3;
            insertLast(&lst3, iter2->data);
            iter2 = iter2->next;
            // iter3 = iter1;
        }
        else if (iter1->data <= iter2->data)
        {
            // iter3->next = iter2;
            // iter2->prev = iter3;
            insertLast(&lst3, iter1->data);
            iter1 = iter1->next;
            // iter3 = iter2;
        }
    }
    while (iter1)
    {
        insertLast(&lst3, iter1->data);
        iter1 = iter1->next;
    }
    while (iter2)
    {
        insertLast(&lst3, iter2->data);
        iter2 = iter2->next;
    }
    printf("\nList 3: ");
    display(&lst3);
}
int main()
{
    DLIST lst1;

    DLIST lst2;

    // res:
    DLIST lst3;

    initList(&lst1);
    initList(&lst2);
    initList(&lst3);
    // Filling first dll :
    insertLast(&lst1, 70);
    insertLast(&lst1, 80);
    insertLast(&lst1, 100);

    // filling 2nd dll:
    insertLast(&lst2, 30);
    insertLast(&lst2, 75);
    insertLast(&lst2, 120);

    printf("List 1: ");
    display(&lst1);

    printf("\nList 2: ");
    display(&lst2);
    merge(&lst1, &lst2, lst3);
    return 0;
}
