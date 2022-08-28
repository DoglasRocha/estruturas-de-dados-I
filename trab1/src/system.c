#include "../includes/list.h"
#include "../includes/node.h"
#include "../includes/person.h"
#include "../includes/file.h"
#include <time.h>
#include <stdio.h>

double calcTimeDiffInMicroseconds(clock_t start, clock_t end) 
{
    double diff = (double) end - (double) start / ((double) CLOCKS_PER_SEC * 1000.0); 

    return diff;
}

void SysPrintNodeInfo(List *list, Node *node, int position, int *C, int *M, clock_t start)
{
    int index;
    clock_t end;

    if (position == 0)
        index = 0;

    else if (position == -1 || position > list->length)
        index = list->length;

    else
        index = position;

    end = clock();

    if (node != NULL)
        printf("Nome: %s, RG: %s, posição: %d, ", node->person->name, node->person->rg, position);
    else
        printf("Nó não encontrado, ");

    printf("C: %d, M: %d, Runtime: %fms \n", *C, *M, calcTimeDiffInMicroseconds(start, end));
}

Person *SysCreatePerson(void)
{
    char name[40], rg[10];

    printf("Digite o nome e o RG da pessoa: ");
    scanf("%s %s", name, rg);

    return createPerson(rg, name);
}

void SysInsertNode(List *list, int position, int *C, int *M)
{
    clock_t start = clock();

    Person *person = SysCreatePerson();
    Node *node = createNode(person);
    insertNode(list, node, position, C, M);
    SysPrintNodeInfo(list, node, position, C, M, start);
}

void SysInsertNodeFromFile(List *list, char name[], char rg[])
{
    int C, M;

    Person *person = createPerson(rg, name);
    Node *node = createNode(person);
    insertNode(list, node, -1, &C, &M);
}

void SysRemoveNode(List *list, int position, int *C, int *M)
{
    clock_t start = clock();

    Node *removedNode = removeNode(list, position, C, M);
    SysPrintNodeInfo(list, removedNode, position, C, M, start);
    freeNode(removedNode);
}

void SysSearchNode(List *list, char rg[], int *C, int *M)
{
    int position;
    clock_t start = clock();

    Node *node = searchNode(list, rg, &position, C, M);
    SysPrintNodeInfo(list, node, position, C, M, start);
}

void SysEvaluateOption(List *list, int option)
{
    int position, C, M;
    char rg[9], filename[256];
    C = M = 0;

    switch (option)
    {
    case 1:
        SysInsertNode(list, 0, &C, &M);
        break;

    case 2:
        SysInsertNode(list, -1, &C, &M);
        break;

    case 3:
        printf("Em qual posição você deseja inserir o nó? ");
        scanf("%d", &position);
        SysInsertNode(list, position, &C, &M);
        break;

    case 4:
        SysRemoveNode(list, 0, &C, &M);
        break;

    case 5:
        SysRemoveNode(list, -1, &C, &M);
        break;

    case 6:
        printf("De qual posição você deseja remover o nó? ");
        scanf("%d", &position);
        SysRemoveNode(list, position, &C, &M);
        break;

    case 7:
        printf("Qual RG você deseja procurar? ");
        scanf(" %s", rg);
        SysSearchNode(list, rg, &C, &M);
        break;

    case 8:
        printList(list);
        break;

    case 9:
        printf("Por favor, digite o nome do novo arquivo: ");
        scanf(" %s", filename);
        writeFileFromList(list, filename);
        break;
    
    case 10:
        printf("Por favor, digite o nome do arquivo a ser lido: ");
        scanf(" %s", filename);
        readFileAndInsertIntoList(list, filename);
        break;

    case 11:

        break;

    default:
        break;
    }
}