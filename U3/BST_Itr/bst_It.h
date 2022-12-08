#define MAX 10
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct TREE
{
    NODE *root;
} TREE;

typedef struct stack
{
    int top;
    NODE *s[MAX];
} STACK;

typedef struct queue
{
    int front, rear;
    NODE *a[MAX];
} QUEUE;
void initTree(TREE *pt);
void insertNode(TREE *pt, int ele);
void preorderTraversal(TREE *pt);
void inorderTraversal(TREE *pt);
void postorderTraversal(TREE *pt);
void levelOrderTraversal(TREE *pt);
void destroyTree(TREE *pt);