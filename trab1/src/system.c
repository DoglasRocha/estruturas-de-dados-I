#include "../includes/list.h"
#include "../includes/node.h"
#include "../includes/person.h"
#include <stdio.h>

Person *SysCreatePerson(void)
{
    char name[31], rg[9];

    printf("Digite o nome e o RG da pessoa: ");
    scanf("%s %s", name, rg);

    return createPerson(name, rg);
}

void SysInsertNode(List *list, int position)
{
    Person *person = SysCreatePerson();
    Node *node = createNode(person);
    insertNode(list, node, position);
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
    
    default:
        break;
    }
}