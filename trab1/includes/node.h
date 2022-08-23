#ifndef __NODE_H
#define __NODE_H
    #include "person.h"

    typedef struct node
    {
        struct node *next;
        struct node *prev;
        Person *person;
    } Node;

#endif