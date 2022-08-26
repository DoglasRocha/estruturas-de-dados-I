#ifndef __LIST_H
#define __LIST_H
    #include "node.h"

    typedef struct 
    {
        Node *head;
        Node *end;
        int length, C, M;

    } List;

    List *createList(void);
    void freeList(List *list);
    void insertNode(List *list, Node *node, int position);
    Node *removeNode(List *list, int position);
    Node *searchNode(List *list, char rg[], int *position);
    void printList(List *list);

#endif