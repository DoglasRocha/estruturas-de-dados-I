#include "../includes/list.h"
#include "../includes/system.h"
#include <stdio.h>
#include <string.h>

void writeFileFromList(List *list, char filename[])
{
    FILE *file = fopen(filename, "w");
    Person *currentNode;

    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    for (int i = 0; i < list->length; i++)
        fprintf(file, "%s,%s\n", list->array[i]->name, list->array[i]->rg);

    fclose(file);
}
void readFileAndInsertIntoList(List *list, char filename[])
{
    FILE *file = fopen(filename, "r");
    char *name, *rg, buffer[128];

    if (file == NULL) 
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        name = strtok(buffer, ",");
        rg = strtok(NULL, "\n");
        SysInsertPersonFromFile(list, name,  rg);
    }

    fclose(file);
}
