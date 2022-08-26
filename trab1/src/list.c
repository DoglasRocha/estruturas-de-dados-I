#include "../includes/list.h"
#include "../includes/node.h"
#include <stdio.h>
#include <stdlib.h>

List *createList(void) 
{
    List *list = malloc(sizeof(List));

    list->head = NULL;
    list->end = NULL;
    list->length = list->C = list->M = 0;

    return list;
}

void freeList(List *list)
{
    Node *aux, *tmp;
    for (tmp = list->head; tmp != NULL; tmp = aux, list->C++)
    {
        aux = tmp->next;
        freeNode(tmp);
    }
        
    free(list);
}

void insertNodeInEmptyList(List *list, Node *node)
{
    list->head = list->end = node,
    node->prev = node->next = NULL,
    list->M += 4;
}

void insertNodeInHead(List *list, Node *node)
{
    if (list->length == 0)
        insertNodeInEmptyList(list, node);

    else
    {
        node->next = list->head;
        list->head = node; 
        node->prev = NULL; 

        list->M += 3;
    }

    list->C++;
}

void insertNodeInEnd(List *list, Node *node)
{
    if (list->length == 0)
        insertNodeInEmptyList(list, node);

    else        
    {
        list->end->next = node;
        node->prev = list->end;
        node->next = NULL;
        list->end = node;
        list->M += 3;
    }

    list->C++;
}

Node *movePointerToPosition(List *list, int position)
{
    Node *aux;
    int i;

    if (position < list->length / 2) 
        for (aux = list->head, i = 0; i < position; aux = aux->next, i++, list->C++, list->M++);

    else
        for (aux = list->end, i = list->length - 1; i > position; aux = aux->prev, i--, list->C++, list->M++);

    return aux;
}

void insertNodeInPosition(List *list, Node *node, int position)
{
    Node *aux;
    int i;

    if (list->length == 0)
        insertNodeInEmptyList(list, node),
        list->C++;
    

    else if (list->length <= position)
        insertNodeInEnd(list, node),
        list->C += 2;

    else
    {
        aux = movePointerToPosition(list, position);

        node->prev = aux->prev;
        aux->prev->next = node; 
        node->next = aux;
        aux->prev = node;
        list->M += 4;
        list->C += 3;
    }
}

void insertNode(List *list, Node *node, int position)
{
    switch (position)
    {
    case 0:
        insertNodeInHead(list, node);
        list->C++;
        break;

    case -1:
        insertNodeInEnd(list, node);
        list->C += 2;
        break;

    default:
        insertNodeInPosition(list, node, position);
        list->C += 2;
        break;
    }

    list->length++;
}

Node *removeHeadNode(List *list)
{
    if (list->head == NULL)
    {
        list->C++;
        return NULL;
    }
    list->C++;

    Node *nodeToRemove = list->head;

    list->head = nodeToRemove->next;

    if (list->length > 1)
        list->head->prev = NULL;

    list->C++;
    list->M += 3;
    
    return nodeToRemove;
}

Node *removeTailNode(List *list)
{
    if (list->end == NULL)
    {
        list->C++;
        return NULL;
    }
    list->C++;
    
    Node *nodeToRemove = list->end;

    list->end = nodeToRemove->prev;
    list->end->next = NULL;

    list->M += 3;
    return nodeToRemove;
}

Node *removeNodeInPosition(List *list, int position)
{
    Node *nodeToRemove;

    if (list->length <= 1)
    {
        list->C++;
        return removeHeadNode(list);
    }
    else if (list->length <= position)
    {
        list->C += 2;
        return removeTailNode(list);
    }
    list->C += 2;

    nodeToRemove = movePointerToPosition(list, position);

    nodeToRemove->prev->next = nodeToRemove->next;
    nodeToRemove->next->prev = nodeToRemove->prev;

    list->M += 3;
    return nodeToRemove;
}

Node *removeNode(List *list, int position)
{
    Node *removedNode;

    switch (position)
    {
    case 0:
        removedNode = removeHeadNode(list);
        list->C++;
        break;

    case -1:
        removedNode = removeTailNode(list);
        list->C += 2;
        break;
    
    default:
        removedNode = removeNodeInPosition(list, position);
        list->C += 2;
        break;
    }


    list->length--;
    return removedNode;
}

void printList(List *list)
{
    for (Node *aux = list->head; aux != NULL; aux = aux->next)
        printf("Nome: %s, RG: %s\n", aux->person->name, aux->person->rg);
}