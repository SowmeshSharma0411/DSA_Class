#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *createNode(int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = NULL;
    return newnode;
}
void disp(NODE *head)
{
    int c = 0;
    while (head != NULL)
    {
        printf("Ele %d : %d\n", ++c, head->data);
        head = head->next;
    }
}
int main()
{

    NODE *one = createNode(1);
    NODE *two = createNode(2);
    one->next = two;
    NODE *three = createNode(3);
    two->next = three;
    NODE *four = createNode(4);
    three->next = four;
    NODE *five = createNode(5);
    four->next = five;
    NODE *six = createNode(6);
    five->next = six;
    NODE *seven = createNode(7);
    six->next = seven;

    NODE *p = one;
    NODE *q = two;
    disp(one);
    printf("After Deletion :\n");
    while (1)
    {
        free(p);
        if (q == NULL)
            break;
        p = q->next;
        q->next = p->next;
        q = p->next;
    }
    disp(two);
    return 0;
}