#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"

void initList(CDLL *pl)
{
    pl->head = NULL;
}
NODE *CreateNode(int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->info = ele;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insertFront(CDLL *pl, int ele)
{

    NODE *newnode = CreateNode(ele);
    if (pl->head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        pl->head = newnode;
        return;
    }
    NODE *last = pl->head->prev;
    newnode->next = pl->head;
    newnode->prev = last;
    last->next = newnode;
    pl->head->prev = newnode;
    pl->head = newnode;
}
void insertLast(CDLL *pl, int ele)
{
    NODE *newnode = CreateNode(ele);
    if (pl->head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        pl->head = newnode;
        return;
    }
    NODE *last = pl->head->prev;
    newnode->prev = last;
    newnode->next = last->next;
    last->next = newnode;
    pl->head->prev = newnode;
}
int CountNodes(CDLL *pl)
{
    int c = 0;
    if (pl->head == NULL)
        return c;
    NODE *iter = pl->head;
    while (iter->next != pl->head)
    {
        c++;
        iter = iter->next;
    }
    return c + 1;
}
int insertAtPos(CDLL *pl, int ele, int pos)
{
    int n = CountNodes(pl);

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
        NODE *newnode = CreateNode(ele);
        NODE *iter = pl->head;
        int c = 0;
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
void destroyList(CDLL *pl)
{
    if (pl->head == NULL)
        return;
    NODE *last = pl->head->prev;
    int ele;
    while (pl->head != last)
    {
        ele = pl->head->info;
        pl->head = pl->head->next;
        free(pl->head->prev);
        printf("Deleted : %d\n", ele);
        pl->head->prev = last;
        last->next = pl->head;
    }
    ele = pl->head->info;
    free(pl->head);
    printf("Deleted : %d\n", ele);
}
void display(CDLL *pl)
{
    if (pl->head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    NODE *iter = pl->head;
    NODE *last = pl->head->prev;
    while (iter != last)
    {
        printf("%d ", iter->info);
        iter = iter->next;
    }
    printf("%d ", iter->info);
}
int deleteFront(CDLL *pl, int *pele)
{
    if (pl->head == NULL)
    {
        return 0;
    }
    else if (pl->head->next == pl->head->prev)
    {
        *pele = pl->head->info;
        free(pl->head);
        pl->head = NULL;
        return 1;
    }
    else
    {
        *pele = pl->head->info;
        NODE *last = pl->head->prev;
        pl->head = pl->head->next;
        free(pl->head->prev);
        pl->head->prev = last;
        last->next = pl->head;
        return 1;
    }
}
int deleteLast(CDLL *pl, int *pele)
{
    if (pl->head == NULL)
    {
        return 0;
    }
    else if (pl->head->next == pl->head->prev)
    {
        *pele = pl->head->info;
        free(pl->head);
        pl->head = NULL;
        return 1;
    }
    else
    {
        NODE *last = pl->head->prev;
        *pele = last->info;
        last = last->prev;
        free(last->next);
        pl->head->prev = last;
        last->next = pl->head;
        return 1;
    }
}
int deleteAtPos(CDLL *pl, int *pele, int pos)
{
    int n = CountNodes(pl);
    if (pos < 0 || pos >= n)
        return 0;
    else if (pos == 0)
        return deleteFront(pl, pele);
    else if (pos == n - 1)
        return deleteLast(pl, pele);
    else
    {
        int c = 0;
        NODE *iter = pl->head;
        while (c != pos - 1)
        {
            iter = iter->next;
            c++;
        }
        NODE *temp = iter->next;
        *pele = temp->info;
        iter->next = temp->next;
        temp->next->prev = iter;
        free(temp);
        return 1;
    }
}