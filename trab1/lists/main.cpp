#include <iostream>
#include "linked-list/includes/list.hpp"
#include "linked-list/src/list.cpp"
#include "common/includes/person.hpp"

int main(void)
{
    int a = 0, b = 0;
    Person *test = new Person("Doglas", 12345678);
    Person *test2 = new Person("Doglas", 12345679);
    Person *test3 = new Person("Doglas", 12345689);
    LinkedList<Person *> *list = new LinkedList<Person *>();
    list->
        insert(test,-1, &a, &b)->
        insert(test2, -1, &a, &b)->
        insert(test3, -1, &a, &b);

    
    
}