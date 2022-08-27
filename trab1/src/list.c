#include "../includes/list.h"
#include "../includes/node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList(void) 
{
    List *list = malloc(sizeof(List));

    list->head = list->end = NULL;
    list->length = 0;

    return list;
}

void freeList(List *list)
{
    Node *aux, *tmp;
    for (tmp = list->head; tmp != NULL; tmp = aux)
    {
        aux = tmp->next;
        freeNode(tmp);
    }
        
    free(list);
}

void insertNodeInEmptyList(List *list, Node *node, int *C, int *M)
{
    list->head = list->end = node,
    node->prev = node->next = NULL,
    (*M) += 4;
}

void insertNodeInHead(List *list, Node *node, int *C, int *M)
{
    if (list->length == 0)
        insertNodeInEmptyList(list, node, C, M);

    else
    {
        node->next = list->head;
        list->head = node; 
        node->prev = NULL; 

        (*M) += 3;
    }

    (*C)++;
}

void insertNodeInEnd(List *list, Node *node, int *C, int *M)
{
    if (list->length == 0)
        insertNodeInEmptyList(list, node, C, M);

    else        
    {
        list->end->next = node;
        node->prev = list->end;
        node->next = NULL;
        list->end = node;
        (*M) += 3;
    }

    (*C)++;
}

Node *movePointerToPosition(List *list, int position, int *C, int *M)
{
    Node *aux;
    int i;

    if (position < list->length / 2) 
        for (aux = list->head, i = 0; i < position; aux = aux->next, i++, (*C)++, (*M)++);

    else
        for (aux = list->end, i = list->length - 1; i > position; aux = aux->prev, i--, (*C)++, (*M)++);

    return aux;
}

void insertNodeInPosition(List *list, Node *node, int position, int *C, int *M)
{
    Node *aux;
    int i;

    if (list->length == 0)
        insertNodeInEmptyList(list, node, C, M),
        (*C)++;
    

    else if (list->length <= position)
        insertNodeInEnd(list, node, C, M),
        (*C) += 2;

    else
    {
        aux = movePointerToPosition(list, position, C, M);

        node->prev = aux->prev;
        aux->prev->next = node; 
        node->next = aux;
        aux->prev = node;
        (*M) += 4;
        (*C) += 3;
    }
}

void insertNode(List *list, Node *node, int position, int *C, int *M)
{
    switch (position)
    {
    case 0:
        insertNodeInHead(list, node, C, M);
        (*C)++;
        break;

    case -1:
        insertNodeInEnd(list, node, C, M);
        (*C) += 2;
        break;

    default:
        insertNodeInPosition(list, node, position, C, M);
        (*C) += 2;
        break;
    }

    list->length++;
}

Node *removeHeadNode(List *list, int *C, int *M)
{
    if (list->head == NULL)
    {
        (*C)++;
        return NULL;
    }
    (*C)++;

    Node *nodeToRemove = list->head;

    list->head = nodeToRemove->next;

    if (list->length > 1)
        list->head->prev = NULL;

    (*C)++;
    (*M) += 3;
    
    return nodeToRemove;
}

Node *removeTailNode(List *list, int *C, int *M)
{
    if (list->end == NULL)
    {
        (*C)++;
        return NULL;
    }
    (*C)++;
    
    Node *nodeToRemove = list->end;

    list->end = nodeToRemove->prev;
    list->end->next = NULL;

    (*M) += 3;
    return nodeToRemove;
}

Node *removeNodeInPosition(List *list, int position, int *C, int *M)
{
    Node *nodeToRemove;

    if (list->length <= 1)
    {
        (*C)++;
        return removeHeadNode(list, C, M);
    }
    else if (list->length - 1 <= position)
    {
        (*C) += 2;
        return removeTailNode(list, C, M);
    }
    (*C) += 2;

    nodeToRemove = movePointerToPosition(list, position, C, M);

    nodeToRemove->prev->next = nodeToRemove->next;
    nodeToRemove->next->prev = nodeToRemove->prev;

    (*M) += 3;
    return nodeToRemove;
}

Node *removeNode(List *list, int position, int *C, int *M)
{
    Node *removedNode;

    switch (position)
    {
    case 0:
        removedNode = removeHeadNode(list, C, M);
        (*C)++;
        break;

    case -1:
        removedNode = removeTailNode(list, C, M);
        (*C) += 2;
        break;
    
    default:
        removedNode = removeNodeInPosition(list, position, C, M);
        (*C) += 2;
        break;
    }

    list->length--;
    return removedNode;
}

Node *searchNode(List *list, char rg[], int *position, int *C, int *M)
{
    Node *node;
    int i;

    for (node = list->head, i = 0; 
         node != NULL;
         node = node->next, i++, (*C) += 2, (*M)++)
    {
            if (!strcmp(node->person->rg, rg))
            {
                *position = i;
                return node;       
            }
    }

    *position = i;
    return NULL;

}

void printList(List *list)
{
    for (Node *aux = list->head; aux != NULL; aux = aux->next)
        printf("Nome: %s, RG: %s\n", aux->person->name, aux->person->rg);
}