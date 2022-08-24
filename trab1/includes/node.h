#ifndef __NODE_H
#define __NODE_H
    #include "person.h"

    typedef struct node Node;
    struct node
    {
        Node *next;
        Node *prev;
        Person *person;
    };

    void createNode(Person *person);

#endif