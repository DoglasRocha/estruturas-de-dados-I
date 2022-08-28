#include "../includes/person.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Person *createPerson(char *rg, char *name)
{
    Person *person = malloc(sizeof(Person));

    sprintf(person->rg, "%s", rg);
    //strcpy(person->rg, rg); 
    person->rg[8] = '\0';
    sprintf(person->name, "%s", name);
    //strcpy(person->name, name);
    person->name[30] = '\0';

    return person;
}

void freePerson(Person *person)
{
    free(person);
}