#include "../includes/system.hpp"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

void System::searchingMenu(long rg, int *C, int *M)
{
    cout << "Qual busca você deseja utilizar?" << endl
         << "(1) Sequencial" << endl
         << "(2) Binária" << endl;
    cin >> option;

    if (option != 1 && option != 2)
        searchingMenu(rg, C, M);

    if (option == 1)
        sequentialSearch(rg, C, M);

    else
        binarySearch(rg, C, M);
}

void System::binarySearch(long rg, int *C, int *M)
{
    int currentPos = (int) round((list->getLength() - 1) / 2.0),
        increase = currentPos;
    (*M) += 2;
    start = clock();

    do
    {
        increase = increase == (int) round(increase / 2.0) ? 0 : (int) round(increase / 2.0);
        (*C)++, (*M)++;

        if ((*list)[currentPos]->rg > rg)
        {
            currentPos += -increase;
            (*M)++;
            (*C)++;
            continue;
        }
        else if ((*list)[currentPos]->rg < rg)
        {
            currentPos += increase;
            (*M)++;
            (*C) += 2;
            continue;
        }

        (*C) += 2;
    }
    while ((*list)[currentPos]->rg != rg && increase > 0);

    if ((*list)[currentPos]->rg == rg)
        printData((*list)[currentPos], currentPos, C, M);
    else
        printData(nullptr, 0, C, M);
}
