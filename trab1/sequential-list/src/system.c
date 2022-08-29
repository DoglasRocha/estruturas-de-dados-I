#include "../includes/list.h"
#include "../includes/person.h"
#include "../includes/file.h"
#include <time.h>
#include <stdio.h>

double calcTimeDiffInMiliseconds(clock_t start, clock_t end) 
{
    double diff = ((double) end - (double) start) / ((double) CLOCKS_PER_SEC) * 1000; 

    return diff;
}

void SysPrintPersonInfo(List *list, Person *person, int position, int *C, int *M, clock_t start)
{
    int index;
    clock_t end;

    if (position == 0)
        index = 0;

    else if (position == -1 || position > list->length)
        index = list->length - 1;

    else
        index = position;

    end = clock();

    if (person != NULL)
        printf("Nome: %s, RG: %s, posição: %d, ", person->name, person->rg, index);
    else
        printf("RG não encontrado, ");

    printf("C: %d, M: %d, Runtime: %.3fms \n", *C, *M, calcTimeDiffInMiliseconds(start, end));
}

Person *SysCreatePerson(void)
{
    char name[40], rg[10];

    printf("Digite o nome e o RG da pessoa: ");
    scanf("%s %s", name, rg);

    return createPerson(rg, name);
}

void SysInsertPerson(List *list, int position, int *C, int *M)
{
    clock_t start = clock();

    Person *person = SysCreatePerson();
    insertPerson(list, person, position, C, M);
    SysPrintPersonInfo(list, person, position, C, M, start);
}

void SysInsertPersonFromFile(List *list, char name[], char rg[])
{
    int C, M;

    Person *person = createPerson(rg, name);
    insertPerson(list, person, -1, &C, &M);
}

void SysRemovePerson(List *list, int position, int *C, int *M)
{
    clock_t start = clock();

    Person *removedPerson = removePerson(list, position, C, M);
    SysPrintPersonInfo(list, removedPerson, position, C, M, start);
    freePerson(removedPerson);
}

void SysSearchPerson(List *list, char rg[], int *C, int *M)
{
    int position;
    clock_t start = clock();

    Person *person = searchPerson(list, rg, &position, C, M);
    SysPrintPersonInfo(list, person, position, C, M, start);
}

void SysEvaluateOption(List *list, int option)
{
    int position, C, M;
    char rg[9], filename[256];
    C = M = 0;

    switch (option)
    {
    case 1:
        SysInsertPerson(list, 0, &C, &M);
        break;

    case 2:
        SysInsertPerson(list, -1, &C, &M);
        break;

    case 3:
        printf("Em qual posição você deseja inserir o nó? ");
        scanf("%d", &position);
        SysInsertPerson(list, position, &C, &M);
        break;

    case 4:
        SysRemovePerson(list, 0, &C, &M);
        break;

    case 5:
        SysRemovePerson(list, -1, &C, &M);
        break;

    case 6:
        printf("De qual posição você deseja remover o nó? ");
        scanf("%d", &position);
        SysRemovePerson(list, position, &C, &M);
        break;

    case 7:
        printf("Qual RG você deseja procurar? ");
        scanf(" %s", rg);
        SysSearchPerson(list, rg, &C, &M);
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