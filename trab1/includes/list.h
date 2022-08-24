#ifndef __LIST_H
#define __LIST_H
    #include "node.h"

    typedef struct 
    {
        Node *next;
        Person *person;
        const Node *prev;
        int length, C, M;

    } List;

    List *createList(Person *personToAdd);
    void freeList(List *list);
    void insertNode(List *list, Node *node, int position);
    Node *removeNode(List *list, int position);

#endif