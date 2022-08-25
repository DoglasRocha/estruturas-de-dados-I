#include "../includes/person.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Person *createPerson(char *rg, char *name)
{
    Person *person = malloc(sizeof(Person));

    strcpy(person->rg, rg); 
    person->rg[8] = '\0';
    strcpy(person->name, name);
    person->name[30] = '\0';

    return person;
}

void freePerson(Person *person)
{
    free(person);
}