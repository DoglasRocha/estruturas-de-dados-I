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
        free(tmp);
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
        break;

    case -1:
        insertNodeInEnd(list, node);
        break;

    default:
        insertNodeInPosition(list, node, position);
        break;
    }

    list->length++;
}

Node *removeNode(List *list, int position)
{
    Node *nodeToRemove, *aux;
    int i;

    if (position >= list->length || position < 0) 
    {
        return NULL;
    }
    list->C++;

    nodeToRemove = movePointerToPosition(list, position);

    aux = nodeToRemove->prev;
    aux->next = nodeToRemove->next;
    aux = aux->next;
    aux->prev = nodeToRemove->prev;
    list->M += 4;
    list->length--;

    return nodeToRemove;
}

void printList(List *list)
{
    for (Node *aux = list->head; aux != NULL; aux = aux->next)
        printf("Nome: %s, RG: %s\n", aux->person->name, aux->person->rg);
}