#include <stdio.h>
#include "bst_It.h"

int main()
{
    TREE tobj;

    initTree(&tobj);
    int choice, ele;
    NODE *res;
    printf("\n1.Insert Node 2.Inorder 3. Preorder 4.Postorder 5.levelorder");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 1:
            printf("Enter an integer\n");
            scanf("%d", &ele);
            insertNode(&tobj, ele);
            break;
        case 2:
            inorderTraversal(&tobj);
            break;
        case 3:
            preorderTraversal(&tobj);
            break;
        case 4:
            postorderTraversal(&tobj);
            break;
        case 5:
            levelOrderTraversal(&tobj);
            break;
        }
        printf("1.Insert Node 2.Inorder 3. Preorder 4.Postorder 5.levelorder\n");
        scanf("%d", &choice);
    } while (choice < 6);
    destroyTree(&tobj);
}