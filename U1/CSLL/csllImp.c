#include <stdio.h>
#include <stdlib.h>
#include "csll.h"

void initList(CSLL *pl)
{
    pl->last = NULL;
}
NODE *createNode(int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->info = ele;
    newnode->next = NULL;
    return newnode;
}
void insertFront(CSLL *pl, int ele)
{
    NODE *newnode = createNode(ele);
    if (pl->last == NULL)
    {
        newnode->next = newnode;
        pl->last = newnode;
        return;
    }
    newnode->next = pl->last->next;
    pl->last->next = newnode;
}
void insertLast(CSLL *pl, int ele)
{
    NODE *newnode = createNode(ele);
    if (pl->last == NULL)
    {
        newnode->next = newnode;
        pl->last = newnode;
        return;
    }
    newnode->next = pl->last->next;
    pl->last->next = newnode;
    pl->last = newnode;
}
void display(CSLL *pl)
{
    if (pl->last == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    NODE *temp = pl->last->next;
    while (temp->next != pl->last->next)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("%d ", temp->info);
}
int deleteFront(CSLL *pl, int *pele)
{
    if (pl->last == NULL)
        return 0;
    else if (pl->last->next == pl->last)
    {
        *pele = pl->last->info;
        free(pl->last);
        pl->last = NULL;
        return 1;
    }
    else
    {
        NODE *temp = pl->last->next;
        *pele = temp->info;
        pl->last->next = temp->next;
        free(temp);
        return 1;
    }
}
void destroyList(CSLL *pl)
{
    if (pl->last == NULL)
        return;
    // NODE *temp = pl->last->next;
    int pele;
    while (pl->last->next != pl->last)
    {
        if (deleteFront(pl, &pele) == 1)
            printf("Deleted : %d\n", pele);
        // pl->last = pl->last->next;
    }
    if (deleteFront(pl, &pele) == 1)
        printf("Deleted : %d\n", pele);
}
int deleteLast(CSLL *pl, int *pele)
{
    if (pl->last == NULL)
        return 0;
    else if (pl->last->next == pl->last)
    {
        *pele = pl->last->info;
        free(pl->last);
        pl->last = NULL;
        return 1;
    }
    else
    {
        NODE *iter = pl->last->next;
        while (iter->next != pl->last)
        {
            iter = iter->next;
        }
        iter->next = pl->last->next;
        *pele = pl->last->info;
        free(pl->last);
        pl->last = iter;
        return 1;
    }
}
int CountNodes(CSLL *pl)
{
    NODE *temp = pl->last->next;
    int c = 0;
    while (temp != pl->last)
    {
        c++;
        temp = temp->next;
    }
    return c + 1;
}
int insertAtPos(CSLL *pl, int ele, int pos)
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
        NODE *newnode = createNode(ele);
        NODE *iter = pl->last->next;
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
int deleteAtPos(CSLL *pl, int *pele, int pos)
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
        NODE *iter = pl->last->next;
        while (c != pos - 1)
        {
            iter = iter->next;
            c++;
        }
        *pele = iter->next->info;
        NODE *temp = iter;
        temp->next = iter->next;
        free(temp->next);
        return 1;
    }
}