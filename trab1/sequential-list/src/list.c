#include "../includes/list.h"
#include "../includes/person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList(void) 
{
    List *list = malloc(sizeof(List));

    list->array = malloc(sizeof(Person *));
    list->length = 0;

    return list;
}

void freeList(List *list)
{
    for (int i = 0; i < list->length; i++)
        freePerson(list->array[i]);
        
    free(list->array);
    free(list);
}

void insertPersonInEmptyList(List *list, Person *person, int *C, int *M)
{
    list->array[0] = person;
    (*M)++;
}

void increaseListSize(List *list, int *C, int *M)
{
    list->array = realloc(list->array, sizeof(Person *) * (list->length + 1));
    (*M)++;
}

void moveOnePositionUp(List *list, int positionToMove, int *C, int *M)
{
    for (int i = list->length; i >= positionToMove; i--, (*C)++, (*M) += 2)
        list->array[i] = list->array[i - 1];
}

void increaseListSizeAndMoveOnePositionUp(List *list, int positionToMove, int *C, int *M)
{
    increaseListSize(list, C, M);
    moveOnePositionUp(list, positionToMove, C, M);
}

void insertPersonInFirstPosition(List *list, Person *person, int *C, int *M)
{
    if (list->length == 0)
        insertPersonInEmptyList(list, person, C, M);

    else
    {
        increaseListSizeAndMoveOnePositionUp(list, 0, C, M);
        list->array[0] = person;
        (*M)++;
    }

    (*C)++;
}

void insertPersonInLastPosition(List *list, Person *person, int *C, int *M)
{
    if (list->length == 0)
        insertPersonInEmptyList(list, person, C, M);

    else        
    {
        increaseListSize(list, C, M);
        list->array[list->length] = person;
        (*M)++;
    }

    (*C)++;
}

void insertPersonInPosition(List *list, Person *person, int position, int *C, int *M)
{
    if (list->length == 0)
        insertPersonInEmptyList(list, person, C, M),
        (*C)++;
    

    else if (list->length <= position)
        insertPersonInLastPosition(list, person, C, M),
        (*C) += 2;

    else
    {
        increaseListSizeAndMoveOnePositionUp(list, position, C, M);
        list->array[position] = person;
        (*M)++;
        (*C) += 2;
    }
}

void insertPerson(List *list, Person *person, int position, int *C, int *M)
{
    switch (position)
    {
    case 0:
        insertPersonInFirstPosition(list, person, C, M);
        (*C)++;
        break;

    case -1:
        insertPersonInLastPosition(list, person, C, M);
        (*C) += 2;
        break;

    default:
        insertPersonInPosition(list, person, position, C, M);
        (*C) += 2;
        break;
    }

    list->length++;
}

void moveOnePositionDown(List *list, int position, int *C, int *M)
{
    for (int i = position; i < list->length; i++, (*C)++, (*M) += 2)
        list->array[i] = list->array[i + 1];
}

void decreaseListSize(List *list, int *C, int *M)
{
    list->array = realloc(list->array, sizeof(Person *) * list->length - 1);
}

void moveOnePositionDownAndDecreaseListSize(List *list, int position, int *C, int *M)
{
    moveOnePositionDown(list, position, C, M);
    decreaseListSize(list, C, M);
}

Person *removePersonInFirstPosition(List *list, int *C, int *M)
{
    if (list->length == 0)
    {
        (*C)++;
        return NULL;
    }
    (*C)++;

    Person *personToRemove = list->array[0];
    moveOnePositionDownAndDecreaseListSize(list, 0, C, M);
    (*M)++;
    
    return personToRemove;
}

Person *removePersonInLastPosition(List *list, int *C, int *M)
{
    if (list->length == 0)
    {
        (*C)++;
        return NULL;
    }
    (*C)++;
    
    Person *personToRemove = list->array[list->length - 1];
    decreaseListSize(list, C, M);

    (*M)++;
    return personToRemove;
}

Person *removePersonInPosition(List *list, int position, int *C, int *M)
{
    Person *personToRemove;

    if (list->length <= 1)
    {
        (*C)++;
        return removePersonInFirstPosition(list, C, M);
    }
    else if (list->length - 1 <= position)
    {
        (*C) += 2;
        return removePersonInLastPosition(list, C, M);
    }
    (*C) += 2;

    personToRemove = list->array[position];
    moveOnePositionDownAndDecreaseListSize(list, position, C, M);

    (*M)++;
    return personToRemove;
}

Person *removePerson(List *list, int position, int *C, int *M)
{
    Person *removedPerson;

    switch (position)
    {
    case 0:
        removedPerson = removePersonInFirstPosition(list, C, M);
        (*C)++;
        break;

    case -1:
        removedPerson = removePersonInLastPosition(list, C, M);
        (*C) += 2;
        break;
    
    default:
        removedPerson = removePersonInPosition(list, position, C, M);
        (*C) += 2;
        break;
    }

    list->length--;
    return removedPerson;
}

Person *searchPerson(List *list, char rg[], int *position, int *C, int *M)
{
    int i;

    for (i = 0; i < list->length; i++, (*C) += 2, (*M)++)
    {
        if (!strcmp(list->array[i]->rg, rg))
        {
            *position = i;
            return list->array[i];       
        }
    }

    *position = i;
    return NULL;
}

void printList(List *list)
{
    for (int i = 0; i < list->length; i++)
        printf("Nome: %s, RG: %s, posição: %d\n", list->array[i]->name, list->array[i]->rg, i);
}