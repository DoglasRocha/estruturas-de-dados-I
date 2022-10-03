#include "../includes/system.hpp"

void System::sortingMenu(int *C, int *M)
{
    cout << "Qual tipo de ordenação você quer utilizar?" << endl
         << "(1) Selection Sort" << endl
         << "(2) Insertion Sort" << endl
         << "(3) Bubble Sort" << endl
         << "(4) Shell Sort" << endl
         << "(5) Quick Sort" << endl
         << "(6) Merge Sort" << endl;

    cin >> option;

    if (option < 1 || option > 6)
    {
        cout << "Opção inválida!!" << endl;
        sortingMenu(C, M);
    }
    (*C)++;

    switch (option) {
        case 1:
            (*C)++;
            start = clock();
            selectionSort(C, M);
            printRuntime(C, M);
            break;

        case 2:
            (*C) += 2;
            start = clock();
            insertionSort(C, M);
            printRuntime(C, M);
            break;

        case 3:
            (*C) += 3;
            start = clock();
            bubbleSort(C, M);
            printRuntime(C, M);
            break;

        case 4:
            (*C) += 4;
            start = clock();
            shellSort(C, M);
            printRuntime(C, M);
            break;

        case 5:
            (*C) += 5;
            start = clock();
            quickSort(C, M, 0, list->getLength() - 1);
            printRuntime(C, M);
            break;

        case 6:
            (*C) += 6;
            start = clock();
            mergeSort(C, M, 0, list->getLength() - 1);
            printRuntime(C, M);
            break;
    }
}

void System::selectionSort(int *C, int *M)
{
    int i, j, l, smallerPos;
    l = list->getLength();

    for (i = 0; i < l; i++, (*C)++, (*M)++)
    {
        for (j = i; j < l; j++, (*C)++, (*M)++)
        {
            (*C)++;
            if (j == i || (*list)[j]->rg < (*list)[smallerPos]->rg)
                smallerPos = j,
                (*M)++;
        }

        list->swap(i, smallerPos, C, M);
    }
}

void System::insertionSort(int *C, int *M, int h)
{
    int i, j, l = list->getLength();
    Person *current;

    for (i = h; i < l; i++, (*C)++, (*M)++)
    {
        current = (*list)[i];

        for (j = i; j >= h && current->rg < (*list)[j - h]->rg; j -= h, (*C)++, (*M)++)
            (*list)[j] = (*list)[j - h];

        (*list)[j] = current;
        (*M)++;
    }
}

void System::bubbleSort(int *C, int *M)
{
    int moves = -1;

    while (moves != 0)
    {
        moves = 0;
        for (int i = 1, l = list->getLength(); i < l; i++, (*C) += 2, (*M)++)
        {
            if ((*list)[i]->rg < (*list)[i - 1]->rg)
                list->swap(i - 1, i, C, M),
                moves++;
        }
    }
}

void System::shellSort(int *C, int *M)
{
    for (int h = list->getLength() / 2; h > 0; h /= 2)
        insertionSort(C, M, h);
}

int System::partition(int *C, int *M, int begin, int end)
{
    int pivotIndex, count = 0, i, j;
    Person *pivot = (*list)[(begin + end) / 2];

    for (i = begin + 1; i <= end; i++, (*C) += 2, (*M)++)
        if ((*list)[i]->rg <= pivot->rg)
            count++;

    pivotIndex = begin + count;
    list->swap(pivotIndex, begin, C, M);

    i = begin, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        (*C)++;
        while ((*list)[i]->rg <= pivot->rg)
            (*C)++,
            (*M)++,
            i++;

        while ((*list)[j]->rg > pivot->rg)
            (*C)++,
            (*M)++,
            j--;

        (*C)++;
        if (i < pivotIndex && j > pivotIndex)
            list->swap(i++, j--, C, M);
    }

    return pivotIndex;
}

void System::quickSort(int *C, int *M, int begin, int end)
{
    int p;

    (*C)++;
    if (begin >= end)
        return;

    p = partition(C, M, begin, end);

    quickSort(C, M, begin, p - 1);
    quickSort(C, M, p + 1, end);
}

void System::merge(int *C, int *M, int begin, int mid, int end)
{
    int leftSize, rightSize, leftCount = 0, rightCount = 0, mergedIndex = begin;
    Person **leftList, **rightList;
    leftSize = mid - begin + 1;
    rightSize = end - mid;
    leftList = new Person*[leftSize];
    rightList = new Person*[rightSize];

    for (int i = 0; i < leftSize; i++, (*C)++, (*M)++)
        leftList[i] = (*list)[begin + i];

    for (int i = 0; i < rightSize; i++, (*C)++, (*M)++)
        rightList[i] = (*list)[mid + 1 + i];

    (*C)++;
    while (leftCount < leftSize && rightCount < rightSize)
    {
        (*C)++;
        if (leftList[leftCount]->rg <= rightList[rightCount]->rg)
            (*list)[mergedIndex] = leftList[leftCount],
            leftCount++;

        else
            (*list)[mergedIndex] = rightList[rightCount],
            rightCount++;

        (*M)++;
        mergedIndex++;
        (*C)++;
    }

    (*C)++;
    while (leftCount < leftSize)
        (*list)[mergedIndex] = leftList[leftCount],
        leftCount++,
        mergedIndex++,
        (*M)++, (*C)++;

    (*C)++;
    while (rightCount < rightSize)
        (*list)[mergedIndex] = rightList[rightCount],
        rightCount++,
        mergedIndex++,
        (*M)++, (*C)++;

    delete []rightList;
    delete []leftList;
}

void System::mergeSort(int *C, int *M, int begin, int end)
{
    (*C)++;
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    mergeSort(C, M, begin, mid);
    mergeSort(C, M, mid + 1, end);
    merge(C, M, begin, mid, end);
}