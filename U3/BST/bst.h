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
void destroyTree(TREE *pt);
NODE *search(TREE *pt, int ele);
// void insertNodeRec(TREE *pt, int ele);
void deleteNode(TREE *pt, int ele);

void preorderTraversal_It(TREE *pt);
void inorderTraversal_It(TREE *pt);
void postorderTraversal_It(TREE *pt);
void levelOrderTraversal_It(TREE *pt);