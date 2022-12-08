#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void initTree(TREE *pt)
{
    pt->root == NULL;
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
    NODE *newnode = createNode(ele);
    if (pt->root == NULL)
    {
        pt->root = newnode;
        return;
    }
    NODE *iter = pt->root;
    NODE *temp = iter;
    while (iter)
    {
        temp = iter;
        if (newnode->info < iter->info)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if (newnode->info < iter->info)
        temp->left = newnode;
    else
        temp->right = newnode;
}
void preorder(NODE *n)
{
    if (n == NULL)
        return;
    else
    {
        printf("%d ", n->info);
        preorder(n->left);
        preorder(n->right);
    }
}
void preorderTraversal(TREE *pt)
{
    preorder(pt->root);
}
void inorder(NODE *n)
{
    if (n == NULL)
        return;
    else
    {
        inorder(n->left);
        printf("%d ", n->info);
        inorder(n->right);
    }
}
void inorderTraversal(TREE *pt)
{
    inorder(pt->root);
}
void postorder(NODE *n)
{
    if (n == NULL)
        return;
    else
    {
        postorder(n->left);
        postorder(n->right);
        printf("%d ", n->info);
    }
}
void postorderTraversal(TREE *pt)
{
    postorder(pt->root);
}
void destroy(NODE *n)
{
    if (n == NULL)
        return;
    else
    {
        destroy(n->left);
        destroy(n->right);
        printf("Freed %d\n", n->info);
        free(n)
    }
}
void destroyTree(TREE *pt)
{
    destroy(pt->root);
    pt->root = NULL;
}
NODE *searchNode(NODE *iter, int ele)
{
    if (iter == NULL)
        return iter;
    else
    {
        if (iter->info == ele)
            return iter;
        else if (ele < iter->info)
            searchNode(iter->left, ele);
        else
            searchNode(iter->right, ele);
        // Ele if ladder avoids excessive fnc calls.
    }
}
NODE *search(TREE *pt, int ele)
{
    return searchNode(pt->root, ele);
}
NODE *delete (NODE *n, int ele) // Imp Not done properly.
{
    if (n == NULL)
        return;
    if (ele < n->info)
        n->left = delete (n->left, ele);
    else if (ele > n->info)
        n->right = delete (n->right, ele);
    else
    {
        NODE *temp = NULL;
        if (n->left == NULL) // Single child/Lead node
        {
            temp = n->right;
            free(n);
            return temp;
        }
        else if (n->right == NULL) // Single child/Lead node
        {
            temp = n->left;
            free(n);
            return temp;
        }
        else // Inorder traversal
        {
            NODE *iter = n->right;
            while (n->left != NULL)
                n = n->left;
            n->info = iter->info;
            iter->right = delete (n->right, q->info);
        }
    }
    return n;
}
void deleteNode(TREE *pt, int ele)
{
    delete (pt->root, ele);
    pt->root = NULL;
}