#include <stdio.h>
#include <stdlib.h>

// Not easy
typedef struct node
{
    int info;
    int rthread;        // TRUE if right is NULL or a non-NULL thread
    struct node *left;  // Pointer to left child
    struct node *right; // Pointer to right child
} NODE;
typedef struct tree
{
    NODE *root;
} TREE;

void init(TREE *pt)
{
    pt->root = NULL;
}
NODE *createNode(int e)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->info = e;
    temp->left = NULL;
    temp->right = NULL;
    temp->rthread = 1;
    return temp;
}
void setLeft(NODE *q, int e) // set node to left of q
{
    NODE *temp = createNode(e);
    q->left = temp;
    temp->right = q;
}
void setRight(NODE *q, int e)
{
    NODE *temp = createNode(e);
    temp->right = q->right; // thread
    q->right = temp;
    q->rthread = 0;
}
void inOrder(TREE *t)
{
    NODE *iter = t->root;
    NODE *q; // helper
    do
    {
        q = NULL;
        while (iter)
        {
            q = iter;
            iter = iter->left;
        }
        if (q != NULL)
        {
            printf("%d ", q->info);
            iter = q->right;
            while (q->rthread && iter)
            {
                printf("%d ", iter->info);
                q = iter;
                iter = iter->right;
            }
        }
    } while (q);
}
void create(TREE *pt)
{
    NODE *p, *q;
    int e, wish;
    printf("Enter root info\n");
    scanf("%d", &e);
    pt->root = createNode(e);
    do
    {
        printf("Enter info\n");
        scanf("%d", &e);

        p = pt->root;
        q = NULL;
        while (p)
        {
            q = p;
            if (e < p->info)
                p = p->left;
            else
            {
                if (p->rthread)
                    p = NULL;
                else
                    p = p->right;
            }
        }
        if (e < q->info)
            setLeft(q, e);
        else
            setRight(q, e);
        printf("Do you wish to add another element\n");
        scanf("%d", &wish);
    } while (wish);
}
int main()
{
    TREE t;
    init(&t);
    create(&t);
    inOrder(&t);
    return 0;
}