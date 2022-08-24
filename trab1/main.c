#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/list.h"
#include "includes/node.h"
#include "includes/person.h"

int main(void)
{
    Person test, test1, test2;
    
    strcpy(test.name, "doglas");
    strcpy(test.rg, "12345678");

    strcpy(test1.name, "doglas1");
    strcpy(test1.rg, "87654321");

    strcpy(test2.name, "doglas2");
    strcpy(test2.rg, "78456123");

    List *list = createList();
    Node *testNode = malloc(sizeof(Node));
    Node *testNode1 = malloc(sizeof(Node));
    Node *testNode2 = malloc(sizeof(Node));

    testNode->person = &test;
    testNode1->person = &test1;
    testNode2->person = &test2;

    insertNode(list, testNode, -1);
    insertNode(list, testNode1, -1);
    insertNode(list, testNode2, 1);

    printList(list);

    freeList(list);
}