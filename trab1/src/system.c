#include "../includes/list.h"
#include "../includes/node.h"
#include "../includes/person.h"
#include <stdio.h>

void SysPrintNodeInfo(List *list, Node *node, int position)
{
    int index;

    if (position == 0)
        index = 0;

    else if (position == -1 || position > list->length)
        index = list->length;

    printf("Nome: %s, RG: %s, C: %d, M: %d, Runtime: \n", node->person->name, node->person->rg, list->C, list->M);
}

Person *SysCreatePerson(void)
{
    char name[31], rg[9];

    printf("Digite o nome e o RG da pessoa: ");
    scanf("%s %s", name, rg);

    return createPerson(rg, name);
}

void SysInsertNode(List *list, int position)
{
    Person *person = SysCreatePerson();
    Node *node = createNode(person);
    insertNode(list, node, position);
    SysPrintNodeInfo(list, node, position);
}

void SysRemoveNode(List *list, int position)
{
    Node *removedNode = removeNode(list, position);
    SysPrintNodeInfo(list, removedNode, position);
    freeNode(removedNode);
}

void SysEvaluateOption(List *list, int option)
{
    int position;

    switch (option)
    {
    case 1:
        SysInsertNode(list, 0);
        break;

    case 2:
        SysInsertNode(list, -1);
        break;

    case 3:
        printf("Em qual posição você deseja inserir o nó? ");
        scanf("%d", &position);
        SysInsertNode(list, position);
        break;

    case 4:
        SysRemoveNode(list, 0);
        break;

    case 5:
        SysRemoveNode(list, -1);
        break;

    case 6:
        printf("De qual posição você deseja remover o nó? ");
        scanf("%d", &position);
        SysRemoveNode(list, position);
        break;

    case 7:
        
        break;

    case 8:
        printList(list);
        break;

    case 9:

        break;
    
    case 10:

        break;

    case 11:

        break;

    default:
        break;
    }
}