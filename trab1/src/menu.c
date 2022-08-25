#include "../includes/menu.h"
#include <stdio.h>

void printIntroduction(void)
{
    printf("TRABALHO 1 - LISTA DE CLIENTES\n");
    printf("==============================\n");
    printf("© by Doglas Rocha\n\n\n\n");
}

int printMenu(void)
{
    int option;

    printf("Digite a opção desejada:\n");
    printf("(1) - Inserir um nó no início da lista\n");
    printf("(2) - Inserir um nó no fim da lista\n");
    printf("(3) - Inserir um nó na posição N da lista\n");
    printf("(4) - Remover um nó no início da lista\n");
    printf("(5) - Remover um nó no fim da lista\n");
    printf("(6) - Remover um nó na posição N da lista\n");
    printf("(7) - Procurar um nó por RG\n");
    printf("(8) - Imprimir a lista na tela\n");
    printf("(9) - Salvar a lista em um arquivo\n");
    printf("(10) - Ler a lista de um arquivo\n");
    printf("(11) - Sair\n\n");

    scanf("%d", &option);

    if (option < 1 || option > 11)
        return printMenu();

    return option;
}

int showMenu(void)
{
    printIntroduction();
    return printMenu();
}