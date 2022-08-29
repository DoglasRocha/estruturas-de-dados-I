#ifndef __LIST_H
#define __LIST_H

#include "person.h"

typedef struct 
{
    Person **array;
    int length;

} List;

List *createList(void);
void freeList(List *list);
void insertPerson(List *list, Person *person, int position, int *C, int *M);
Person *removePerson(List *list, int position, int *C, int *M);
Person *searchPerson(List *list, char rg[], int *position, int *C, int *M);
void printList(List *list);

#endif