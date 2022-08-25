#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/list.h"
#include "includes/node.h"
#include "includes/person.h"
#include "includes/menu.h"

int main(void)
{
    List *list = createList();
    Person *test, *test1, *test2, *test3;
    Node *testNode, *testNode1, *testNode2, *testNode3;
    
    test = createPerson("12345678", "Doglas");
    test1 = createPerson("32165487", "Doglas1");
    test2 = createPerson("78456123", "Doglas2");
    test3 = createPerson("87654321", "Doglas3");

    testNode = createNode(test);
    testNode1 = createNode(test1);
    testNode2 = createNode(test2);
    testNode3 = createNode(test3);

    insertNode(list, testNode, -1);
    insertNode(list, testNode1, -1);
    insertNode(list, testNode2, -1);
    insertNode(list, testNode3, -1);

    printList(list);

    freeList(list);

    showMenu();
}