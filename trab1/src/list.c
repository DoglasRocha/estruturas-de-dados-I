#include "../includes/list.h"
#include "../includes/node.h"
#include <stdlib.h>

List *createList(Person *personToAdd) 
{
    List *list = malloc(sizeof(List));

    list->next = NULL;
    list->prev = NULL;
    list->person = personToAdd;
    list->length = 1;
    list->C = list->M = 0;

    return list;
}

void freeList(List *list)
{
    Node *aux, *tmp;
    for (tmp = list->next; tmp->next != NULL; tmp = aux, list->C++)
    {
        aux = tmp->next;
        free(tmp);
    }
        
    free(tmp);
}

void insertNode(List *list, Node *node, int position)
{
    Node *aux;
    int i;

    switch (position)
    {
    case 0:
        if (list->length != 1)
            node->next = list->next, list->M++;

        list->C++, list->next = node, node->prev = list, list->M += 2;
        break;

    case -1:
        if (list->length == 1)
            list->next = node,
            node->prev = list;

        else
        {
            // for loop that reaches the end of the list
            for(aux = list->next; aux->next != NULL; aux = aux->next, list->C++, list->M++);

            aux->next = node, 
            node->prev = aux;
        }

        list->M += 2;
        list->C++;
        break;

    default:
        if (list->length == 1)
            list->next = node,
            node->prev = list,
            list->M += 3;

        else
        {
            // for loop that reaches the end of the list or the desired position
            for(aux = list->next, i = 0; aux->next != NULL && i < position; aux = aux->next, list->C++, i++, list->M++);

            node->next = aux->next, aux->next = node, node->prev = aux, list->M += 3;
        }

        list->C++;
        break;
    }

    list->length++;
}

Node *removeNode(List *list, int position)
{
    Node *nodeToRemove, *aux;
    int i;

    if (position >= list->length || position < 1) 
    {
        list->C++;
        return NULL;
    }

    // for loop that reaches the desired position
    for (nodeToRemove = list->next, i = 0; i < position; i++, nodeToRemove = nodeToRemove->next, list->C++, list->M++);

    aux = nodeToRemove->prev;
    aux->next = nodeToRemove->next;
    aux = aux->next;
    aux->prev = nodeToRemove->prev;
    list->M += 4;

    return nodeToRemove;
}