#ifndef __PERSON_H
#define __PERSON_H

    typedef struct person
    {
        char rg[9];
        char name[31];
    } Person;

    Person *createPerson(char rg[8], char name[30]);
    void freePerson(Person *person);

#endif