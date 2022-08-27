#include "../includes/list.h"
#include "../includes/node.h"
#include "../includes/system.h"
#include <stdio.h>
#include <string.h>

void writeFileFromList(List *list, char filename[])
{
    FILE *file = fopen(filename, "w");
    Node *currentNode;

    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    for (currentNode = list->head; currentNode != NULL; currentNode = currentNode->next)
        fprintf(file, "%s,%s\n", currentNode->person->name, currentNode->person->rg);

    fclose(file);
}
void readFileAndInsertIntoList(List *list, char filename[])
{
    FILE *file = fopen(filename, "r");
    char *name, *rg, buffer[40];

    if (file == NULL) 
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        name = strtok(buffer, ",");
        rg = strtok(NULL, "\n");
        //printf("%s %s\n", name, rg);
        //getchar();
        SysInsertNodeFromFile(list, name,  rg);
    }

    fclose(file);
}
