#include "../includes/node.h"
#include "../includes/person.h"
#include <stdlib.h>

Node *createNode(Person *person)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        return NULL;

    node->prev = node->next = NULL;
    node->person = person;

    return node;
}

void freeNode(Node *nodeToFree)
{
    freePerson(nodeToFree->person);
    free(nodeToFree);
}
