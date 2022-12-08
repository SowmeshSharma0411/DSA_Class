#include <stdio.h>
#include "bst.h"

int main()
{
    TREE tobj[MAX];

    initTree(tobj);

    createTree(tobj);

    printf("Inorder traversal:");
    inorder(tobj, 0);

    printf("\nPreorder traversal:");
    preorder(tobj, 0);

    printf("\nPostorder traversal:");
    postorder(tobj, 0);
}