#ifndef __LIST_H
#define __LIST_H
    #include "node.h"

    typedef struct 
    {
        Node *head;
        Node *end;
        int length;

    } List;

    List *createList(void);
    void freeList(List *list);
    void insertNode(List *list, Node *node, int position, int *C, int *M);
    Node *removeNode(List *list, int position, int *C, int *M);
    Node *searchNode(List *list, char rg[], int *position, int *C, int *M);
    void printList(List *list);

#endif