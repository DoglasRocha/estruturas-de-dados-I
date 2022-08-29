#ifndef __PERSON_H
#define __PERSON_H

typedef struct person
{
    char rg[10];
    char name[40];
} Person;

Person *createPerson(char rg[10], char name[40]);
void freePerson(Person *person);

#endif