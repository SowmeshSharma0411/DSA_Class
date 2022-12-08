#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

void initList(LLIST *pl)
{
    pl->head = NULL;
}

NODE *createNode(int data)
{
    NODE *newnode = (NODE *)(malloc(sizeof(NODE)));
    newnode->info = data;
    newnode->next = NULL;
}
void insertFront(LLIST *pl, int ele)
{
    NODE *newnode = createNode(ele);
    newnode->next = pl->head;
    pl->head = newnode;
}
void insertLast(LLIST *pl, int ele)
{
    NODE *newnode = createNode(ele);
    NODE *iter = pl->head;
    // empty list
    if (pl->head == NULL)
    {
        pl->head = newnode;
        return;
    }
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = newnode;
    newnode->next = NULL;
}
void display(LLIST *pl)
{
    NODE *iter = pl->head;

    if (pl->head == NULL)
        printf("List is empty\n");
    else
    {
        while (iter != NULL)
        {
            printf("%d ", iter->info);
            iter = iter->next;
        }
    }
}

int deleteFront1(LLIST *pl)
{
    NODE *temp = pl->head;
    int ele = temp->info;
    pl->head = pl->head->next;
    free(temp);
    temp = NULL;
    return ele;
}

int deleteFront2(LLIST *pl, int *pele)
{
    if (pl->head == NULL)
        return 0;
    NODE *temp = pl->head;
    pl->head = pl->head->next;
    *pele = temp->info;
    free(temp);
    temp = NULL;
    return 1;
}

void destroyList(LLIST *pl) // lil dbtful
{
    if (pl->head == NULL)
    {
        printf("Empty List ");
        return;
    }
    // NODE *iter = pl->head;
    int ele;
    while (pl->head != NULL)
    {
        ele = deleteFront1(pl);
        printf("Deleted : %d\n", ele);
        // pl->head = pl->head->next;
    }
}

int deleteLast(LLIST *pl)
{
    NODE *iter = pl->head;
    int ele;
    if (iter->next == NULL) // one node case
    {
        ele = iter->info;
        free(iter);
        iter = NULL;
        pl->head = NULL;
    }
    // NODE *temp = pl->head;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    // temp = iter->next;
    ele = iter->next->info;
    free(iter->next);
    // temp = NULL;
    iter->next = NULL;
    return ele;
}
int countNodes(LLIST *pl)
{
    NODE *p = pl->head;
    int count = 0;

    if (pl->head == NULL)
        return count;
    else
    {
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }
}
int insertAtPos(LLIST *pl, int ele, int pos)
{
    int n = countNodes(pl);
    if (pos < 0 || pos > n)
        return 0;
    else if (pos == 0)
    {
        insertFront(pl, ele);
        return 1;
    }
    else
    {
        NODE *iter = pl->head;
        NODE *newnode = createNode(ele);
        int c = 0;
        while (c != pos - 1)
        {
            iter = iter->next;
            c++;
        }
        newnode->next = iter->next;
        iter->next = newnode;
        return 1;
    }
}
int deleteAtPos(LLIST *pl, int *pele, int pos)
{
    int n = countNodes(pl);
    if (pos < 0 || pos > n)
        return 0;
    else if (pos == 0)
    {
        *pele = deleteFront1(pl);
        return 1;
    }
    else
    {
        NODE *iter = pl->head;
        NODE *temp = NULL;
        int c = 0;
        while (c != pos - 1)
        {
            iter = iter->next;
        }
        temp = iter->next;
        iter->next = temp->next;
        *pele = temp->info;
        free(temp);
        temp = NULL;
        return 1;
    }
}