#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student

{

    char srn[14];

    char name[30];

    float cgpa;

} STUDENT;

typedef struct node

{

    STUDENT *s;

    struct node *prev, *next;

} NODE;

typedef struct list
{
    NODE *head;
} DLIST;

void initList(DLIST *pl)
{
    pl->head = NULL;
}

NODE *CreateNode(char *srn, char *name, float cgpa)
{
    NODE *newnode = malloc(sizeof(NODE));
    STUDENT *s = malloc(sizeof(STUDENT));
    newnode->next = NULL;
    newnode->prev = NULL;
    s->cgpa = cgpa;
    strcpy(s->srn, srn);
    strcpy(s->name, name);
    // strcpy(newnode->s->srn, srn);
    // strcpy(newnode->s->name, name);
    // newnode->s->cgpa = cgpa;
    newnode->s = s;
    return newnode;
}
void insertLast(DLIST *pl, char *srn, char *name, float cgpa)
{
    NODE *newnode = CreateNode(srn, name, cgpa);
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
    printf("SRN Name CGPA\n");
    while (iter != NULL)
    {
        printf("%s %s %f\n", iter->s->srn, iter->s->name, iter->s->cgpa);
        iter = iter->next;
    }
}
void search(DLIST *lst, char *Srn)
{
    NODE *iter = lst->head;
    int c = 0;
    while (iter)
    {
        // printf("%s\n%s\n", iter->s->srn, Srn);
        if (strcmp(iter->s->srn, Srn) == 0)
        {
            printf("Found!\n");
            c = 1;
            printf("%s %f ", iter->s->name, iter->s->cgpa);
            break;
        }
        iter = iter->next;
    }
    if (c == 0)
    {
        printf("Search Unsuccessful! ");
    }
}
int main()
{
    DLIST lst;
    initList(&lst);
    insertLast(&lst, "PES1UG21CS609", "Sowmesh", 9.59);
    insertLast(&lst, "PES1UG21CS780", "Arun", 9.77);
    insertLast(&lst, "PES1UG21CS447", "Joe", 8.55);

    display(&lst);

    printf("Enter SRN :\n");
    char srn[14];
    gets(srn);
    search(&lst, srn);
    return 0;
}

// past 1h : *srn vs srn[]
// srn[13] vs srn[14] : this caused huge problems