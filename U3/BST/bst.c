#include <stdio.h>
#include "bst.h"

int main()
{
    TREE tobj;

    initTree(&tobj);
    int choice, ele;
    printf("1.Insert Node 2.Inorder 3. Preorder 4.Postorder\n");
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
        }
        printf("1.Insert Node 2.Inorder 3. Preorder 4.Postorder\n");
        scanf("%d", &choice);
    } while (choice < 5);
    destroyTree(&tobj);
}