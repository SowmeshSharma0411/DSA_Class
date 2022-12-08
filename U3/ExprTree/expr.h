#define MAX 10
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct tree
{
    NODE *root;
} TREE;

typedef struct stack
{
    int top;
    NODE *s[MAX];
} STACK;

void initTree(TREE *pt);
void initStack(STACK *ps);
void exprTree(TREE *pt, char expr[]);
int eval(TREE *pt);