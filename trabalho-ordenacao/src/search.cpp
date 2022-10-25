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
    int indexFound;
    Person *result;

    if (option != 1 && option != 2)
        searchingMenu(rg, C, M);

    if (option == 1)
    {
        start = clock();
        result = sequentialSearch(rg, &indexFound, C, M);
    }

    else
    {
        start = clock();
        result = binarySearch(rg, 0, list->getLength() - 1, &indexFound, C, M);
    }

    printData(result, indexFound, C, M);
}

Person *System::binarySearch(long rg, int left, int right, int *indexFound, int *C, int *M)
{
    (*C)++;
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        (*C)++;
        if ((*list)[mid]->rg == rg)
        {
            *indexFound = mid;
            return (*list)[mid];
        }

        (*C)++;
        if ((*list)[mid]->rg > rg)
        {
            return binarySearch(rg, left, mid - 1, indexFound, C, M);
        }

        return binarySearch(rg, mid + 1, right, indexFound, C, M);
    }

    *indexFound = -1;
    return nullptr;
}

Person *System::sequentialSearch(long rg, int *indexFound, int *C, int *M)
{
    int i, l;

    for (i = 0, l = list->getLength(); i < l; i++, (*C) += 2, (*M)++)
        if ((*list)[i]->rg == rg)
        {
            *indexFound = i;
            return (*list)[i];
        }
    
    *indexFound = i;
    return nullptr;
}   
