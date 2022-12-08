#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void initList(DLIST *pl)
{
    pl->head = NULL;
}
NODE *CreateNode(int data)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->info = data;
    return newnode;
}
void insertFront(DLIST *pl, int ele)
{
    NODE *newnode = CreateNode(ele);
    if (pl->head == NULL) // Empty list.
    {
        pl->head = newnode;
        return;
    }
    newnode->next = pl->head;
    pl->head->prev = newnode;
    pl->head = newnode;
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
        printf("%d ", iter->info);
        iter = iter->next;
    }
}
int deleteFront(DLIST *pl, int *pele)
{
    if (pl->head == NULL)
    {
        return 0;
    }
    else if (pl->head->next == NULL)
    {
        *pele = pl->head->info;
        free(pl->head);
        pl->head = NULL;
        return 1;
    }
    else
    {
        *pele = pl->head->info;
        pl->head = pl->head->next;
        free(pl->head->prev);
        pl->head->prev = NULL;
        return 1;
    }
}
void destroyList(DLIST *pl)
{
    if (pl->head == NULL)
        return;
    int succ = 0;
    int ele;
    while (pl->head != NULL)
    {
        succ = deleteFront(pl, &ele);
        if (succ != 0)
            printf("Deleted : %d\n", ele);
        // pl->head = pl->head->next;
    }
}
int deleteLast(DLIST *pl, int *pele)
{
    if (pl->head == NULL)
    {
        return 0;
    }
    else if (pl->head->next == NULL)
    {
        *pele = pl->head->info;
        free(pl->head);
        pl->head = NULL;
        return 1;
    }
    else
    {
        NODE *iter = pl->head;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        *pele = iter->info;
        iter->prev->next = NULL;
        free(iter);
        iter = NULL;
        return 1;
    }
}
int countNodes(DLIST *pl)
{
    NODE *iter = pl->head;
    int count = 0;

    if (pl->head == NULL)
        return count;
    else
    {
        while (iter != NULL)
        {
            count++;
            iter = iter->next;
        }
        return count;
    }
}
int insertAtPos(DLIST *pl, int ele, int pos)
{
    int n = countNodes(pl);
    if (pos < 0 || pos > n)
        return 0;
    else if (pos == 0)
    {
        insertFront(pl, ele);
        return 1;
    }
    else if (pos == n)
    {
        insertLast(pl, ele);
        return 1;
    }
    else
    {
        int c = 0;
        NODE *iter = pl->head;
        NODE *newnode = CreateNode(ele);
        while (c != pos - 1)
        {
            iter = iter->next;
            c++;
        }
        newnode->next = iter->next;
        newnode->prev = iter;
        iter->next->prev = newnode;
        iter->next = newnode;
        return 1;
    }
}
int deleteAtPos(DLIST *pl, int *pele, int pos)
{
    int n = countNodes(pl);
    if (pos < 0 || pos > n)
        return 0;
    else if (pos == 0)
    {
        deleteFront(pl, pele);
        return 1;
    }
    else if (pos == n)
    {
        deleteLast(pl, pele);
        return 1;
    }
    else
    {
        NODE *iter = pl->head;
        int c = 0;
        while (c != pos)
        {
            iter = iter->next;
            c++;
        }
        *pele = iter->info;
        iter->prev->next = iter->next;
        iter->next->prev = iter->prev;
        free(iter);
        iter = NULL;
        return 1;
    }
}