#include <stdio.h>
#include <stdlib.h>
#include "bst_It.h"

void initTree(TREE *pt)
{
    pt->root = NULL;
}

NODE *createNode(int ele)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
void insertNode(TREE *pt, int ele)
{
    NODE *newNode = createNode(ele);

    NODE *p = pt->root;
    NODE *q = NULL;

    if (pt->root == NULL)
    {
        pt->root = newNode;
    }
    else
    {
        while (p != NULL)
        {
            q = p;

            if (newNode->info < p->info)
                p = p->left;
            else
                p = p->right;
        }
        if (newNode->info < q->info)
            q->left = newNode;
        else
            q->right = newNode;
    }
}

// For Iterative traversals: Imp Concepts :
void initStack(STACK *ps)
{
    ps->top = -1;
}
void push(STACK *ps, NODE *pn)
{
    ps->s[++(ps->top)] = pn;
}

NODE *pop(STACK *ps)
{
    return ps->s[(ps->top)--];
}

int isEmpty(STACK *ps)
{
    return ps->top == -1;
}
void preorderTraversal(TREE *pt)
{
    STACK stk;
    initStack(&stk);
    NODE *curr = pt->root;
    push(&stk, curr);
    while (!isEmpty(&stk))
    {
        curr = pop(&stk);
        printf("%d ", curr->info);
        if (curr->right != NULL)
            push(&stk, curr->right);
        if (curr->left != NULL)
            push(&stk, curr->left);
    }
    printf("\n");
}
void inorderTraversal(TREE *pt)
{
    STACK stk;
    initStack(&stk);
    NODE *curr = pt->root;
    // do
    // {
    //     while (curr)
    //     {
    //         push(&stk, curr);
    //         curr = curr->left;
    //     }
    //     NODE *popped = pop(&stk);
    //     printf("%d ", popped->info);
    //     curr = popped->right;
    // } while (!isEmpty(&stk) || curr);
    while (curr != NULL || !isEmpty(&stk))
    {
        if (curr != NULL)
        {
            push(&stk, curr);
            curr = curr->left;
        }
        else
        {
            curr = pop(&stk);
            printf("%d ", curr->info);
            curr = curr->right;
        }
    }
    printf("\n");
}
void postorderTraversal(TREE *pt)
{
    if (pt->root == NULL)
        return;
    STACK s1, s2;
    initStack(&s1);
    initStack(&s2);
    NODE *curr = pt->root;
    push(&s1, curr);

    while (!isEmpty(&s1))
    {
        curr = pop(&s1);
        push(&s2, curr);
        if (curr->left != NULL)
            push(&s1, curr->left);
        if (curr->right != NULL)
            push(&s1, curr->right);
    }
    while (!isEmpty(&s2))
    {
        curr = pop(&s2);
        printf("%d ", curr->info);
    }
    printf("\n");
}

// for level order traversal
void initQueue(QUEUE *pq)
{
    pq->front = 0;
    pq->rear = -1;
}
void enqueue(QUEUE *pq, NODE *ele)
{
    pq->a[++pq->rear] = ele;
}
NODE *dequeue(QUEUE *pq)
{
    return pq->a[pq->front++];
}

int isEmptyQ(QUEUE *pq)
{
    return pq->front > pq->rear;
}
void levelOrderTraversal(TREE *pt)
{
    QUEUE q;
    initQueue(&q);
    NODE *temp = pt->root;
    if (temp == NULL)
        return;
    enqueue(&q, pt->root);
    while (!isEmptyQ(&q))
    {
        temp = dequeue(&q);
        printf("%d ", temp->info);
        if (temp->left != NULL)
            enqueue(&q, temp->left);
        if (temp->right != NULL)
            enqueue(&q, temp->right);
    }
    printf("\n");
}

void destroyNode(NODE *r)
{
    if (r != NULL)
    {
        destroyNode(r->left);
        destroyNode(r->right);
        printf("%d freed\n", r->info);
        free(r);
    }
}
void destroyTree(TREE *pt)
{
    destroyNode(pt->root);
    pt->root = NULL;
}
