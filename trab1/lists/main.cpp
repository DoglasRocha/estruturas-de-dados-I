#include <iostream>
#include "linked-list/src/node.cpp"
#include "linked-list/includes/node.hpp"
#include "common/includes/person.hpp"

int main(void)
{
    Person *test = new Person("Doglas", 12345678);
    Node<Person *> *node = new Node<Person *>(test);

    std::cout << node->data->name << ", " << node->data->rg << "\n";
}