#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/list.h"
#include "includes/node.h"
#include "includes/person.h"
#include "includes/menu.h"
#include "includes/system.h"

int main(void)
{
    List *list = createList();
    int option;

    option = showMenu();
    while (option != 11)
    {
        SysEvaluateOption(list, option);
        option = printMenu();
    }

    freeList(list);
}