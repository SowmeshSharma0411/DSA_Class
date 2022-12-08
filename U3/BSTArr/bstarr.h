#define MAX 50
typedef struct tree
{
    int info;
    int used;
} TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt, int i);
void preorder(TREE *pt, int i);
void postorder(TREE *pt, int i);