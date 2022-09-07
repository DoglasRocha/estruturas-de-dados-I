#include "../includes/person.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Person *createPerson(char *rg, char *name)
{
    Person *person = malloc(sizeof(Person));

    sprintf(person->rg, "%s", rg ? rg : "");
    sprintf(person->name, "%s", name ? name : "");

    return person;
}

void freePerson(Person *person)
{
    free(person);
}