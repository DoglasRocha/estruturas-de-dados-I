#include <stdio.h>
#include <stdlib.h>
#include "includes/node.h"
#include "includes/person.h"

int main(void)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        return 1;

    node->prev = NULL;
    node->next = NULL;

    
}