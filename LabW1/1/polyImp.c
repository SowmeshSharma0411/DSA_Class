#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void initPolynomial(POLYNOMIAL *pl)
{
    pl->head = NULL;
}
NODE *createNode(int cf, int px, int py)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->coeff = cf;
    newnode->px = px;
    newnode->py = py;
    newnode->poly = NULL;
    return newnode;
}
void insertLast(POLYNOMIAL *pl, int cf, int px, int py)
{
    NODE *newnode = createNode(cf, px, py);
    if (pl->head == NULL)
    {
        pl->head = newnode;
        return;
    }
    NODE *tail = pl->head;
    while (tail->poly != NULL)
    {
        tail = tail->poly;
    }
    tail->poly = newnode;
    newnode->poly = NULL;
}
void createPolynomial(POLYNOMIAL *pl)
{
    int ch = 1; // shouldnt be 0.
    int cf[4];
    printf("Your Poly should be of the form : Ax^2y^2 + Bxy^2 + Cx^2y + Dxy \n");
    printf("Enter A,B,C,D :\n");
    scanf("%d %d %d %d", &cf[0], &cf[1], &cf[2], &cf[3]);
    insertLast(pl, cf[0], 2, 2);
    insertLast(pl, cf[1], 1, 2);
    insertLast(pl, cf[2], 2, 1);
    insertLast(pl, cf[3], 1, 1);
}
void addPolynomial(POLYNOMIAL *pl1, POLYNOMIAL *pl2, POLYNOMIAL *pl3)
{
    NODE *p1 = pl1->head;
    NODE *p2 = pl2->head;
    int cf, px, py;
    while (p1 && p2)
    {
        if ((p1->px == p2->px) && (p1->py == p2->py))
        {
            cf = p1->coeff + p2->coeff;
            px = p1->px;
            py = p1->py;
            p1 = p1->poly;
            p2 = p2->poly;
        }
        insertLast(pl3, cf, px, py);
    }
    while (p1)
    {
        cf = p1->coeff;
        px = p1->px;
        py = p1->py;
        insertLast(pl3, cf, px, py);
        p1 = p1->poly;
    }
    while (p2)
    {
        cf = p2->coeff;
        px = p2->px;
        py = p2->py;
        insertLast(pl3, cf, px, py);
        p2 = p2->poly;
    }
}

void display(POLYNOMIAL *pl)
{
    NODE *p = pl->head;

    while (p->poly != NULL)
    {
        printf("(%d x^%dy^%d)+", p->coeff, p->px, p->py);
        p = p->poly;
    }
    printf("(%d x^%dy^%d)\n", p->coeff, p->px, p->py);
}

void destroyPolynomial(POLYNOMIAL *pl)
{
    NODE *p;

    while (pl->head != NULL)
    {
        p = pl->head;
        pl->head = pl->head->poly; // pl->head=p->next;
        free(p);
    }
}