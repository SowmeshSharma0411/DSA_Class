#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

list_t *create_list() // return a newly created empty doubly linked list
{
    // DO NOT MODIFY!!!
    list_t *l = (list_t *)malloc(sizeof(list_t));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

node_t *CreateNode(int data)
{
    node_t *newnode = malloc(sizeof(node_t));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = data;
    return newnode;
}
void insert_front(list_t *list, int data) // TODO: inserts data to the beginning of the linked list
{
    node_t *newnode = CreateNode(data);
    if (list->head == NULL) // Empty list.
    {
        list->head = newnode;
        list->tail = newnode;
        return;
    }
    newnode->next = list->head;
    list->head->prev = newnode;
    list->head = newnode;
    (list->size)++;
}

void insert_back(list_t *list, int data) // TODO: inserts data to the end of the linked list
{
    node_t *newnode = CreateNode(data);
    if (is_empty(list))
    {
        list->head = newnode;
        list->tail = newnode;
        return;
    }
    node_t *tail = list->tail;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    newnode->next = NULL;
    (list->size)++;
}

void insert_after(list_t *list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    if (list->head == NULL || list->head->next == NULL) // head=NULL or only 1 node;
    {
        insert_back(list, data);
        return;
    }
    node_t *iter = list->head;
    node_t *newnode = CreateNode(data);
    while (iter->data != prev)
    {
        iter = iter->next;
    }
    if (iter == NULL) // no "prev" : maybe a new msg:
        return;
    newnode->next = iter->next;
    newnode->prev = iter;
    iter->next->prev = newnode;
    iter->next = newnode;
    (list->size)++;
}

void delete_front(list_t *list) // TODO: delete the start node from the linked list.
{
    if (is_empty(list))
    {
        return;
    }
    else if (list->head->next == NULL)
    {
        // *pele = list->head->data;
        free(list->head);
        list->head = NULL;
        list->size = 0;
    }
    else
    {
        // *pele = list->head->data;
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
        (list->size)--;
    }
}

void delete_back(list_t *list) // TODO: delete the end node from the linked list.
{
    if (is_empty(list))
    {
        return;
    }
    else if (list->head->next == NULL)
    {
        // *pele = list->head->data;
        free(list->head);
        list->head = NULL;
        list->size = 0;
    }
    else
    {
        node_t *temp = list->tail;
        list->tail = list->tail->prev;
        free(temp);
        temp = NULL;
        (list->size)--;
    }
}

void delete_node(list_t *list, int data) // TODO: delete the node with “data” from the linked list.
{
    if (is_empty(list))
    {
        return;
    }
    node_t *iter = list->head;
    if (iter->data == data)
    {
        delete_front(list);
        return;
    }
    else if (data == list->tail->data)
    {
        delete_back(list);
        return;
    }
    while (iter->data != data)
    {
        iter = iter->next;
    }
    // *pele = iter->data;
    iter->prev->next = iter->next;
    iter->next->prev = iter->prev;
    free(iter);
    iter = NULL;
    (list->size)--;
}

node_t *search(list_t *list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
    if (is_empty(list))
        return NULL;
    node_t *iter = list->head;
    while (iter->data != data)
    {
        iter = iter->next;
    }
    return iter;
}

int is_empty(list_t *list) // return true or 1 if the list is empty; else returns false or 0
{
    // DO NOT MODIFY!!!
    return list->size == 0;
}

int size(list_t *list) // returns the number of nodes in the linked list.
{
    // DO NOT MODIFY!!!
    return list->size;
}

void delete_nodes(node_t *head) // helper
{
    // DO NOT MODIFY!!!
    if (head == NULL)
        return;
    delete_nodes(head->next);
    free(head);
}

void delete_list(list_t *list) // free all the contents of the linked list
{
    // DO NOT MODIFY!!!
    delete_nodes(list->head);
    free(list);
}

void display_list(list_t *list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
    // DO NOT MODIFY!!!
    node_t *it = list->head;
    while (it != NULL)
    {
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}
