#include "../includes/list.hpp"

template <class T>
SequentialList<T>::SequentialList()
{
    length = 0;
    array = new T[1];
}

template <class T>
SequentialList<T>::~SequentialList()
{
    if (array)
    {
        for (int i = 0; i < length; i++)
            if (array[i]) 
                delete(array[i]);

        delete array;
    }
}

template <class T>
SequentialList<T> *SequentialList<T>::insert(T data, int index, int *C, int *M)
{
    switch (index)
    {
    case 0:
        insertAtListHead(data, C, M);
        (*C)++;
        break;

    case -1:
        insertAtListTail(data, C, M);
        (*C) += 2;
        break;

    default:
        insertAtIndex(data, index, C, M);
        (*C) += 2;
        break;
    }

    length++;
}

template <class T>
T SequentialList<T>::remove(int index, int *C, int *M)
{
    T removedData;

    switch (position)
    {
    case 0:
        removedData = removeListHead(C, M);
        (*C)++;
        break;

    case -1:
        removedData = removeListTail(C, M);
        (*C) += 2;
        break;
    
    default:
        removedData = removeAtIndex(index, C, M);
        (*C) += 2;
        break;
    }

    length--;
    return removedData;
}

template <class T>
T SequentialList<T>::getAt(int index, int *C, int *M)
{
    return array[i];
}

template <class T>
void SequentialList<T>::insertInEmptyList(T data, int *C, int *M)
{
    array[0] = data;
    (*M)++;
}

template <class T>
void SequentialList<T>::insertAtListHead(T data, int *C, int *M)
{
    
    if (length == 0)
        insertInEmptyList(data, C, M);

    else
    {
        increaseListSizeAndMoveOneIndexUp(0, C, M);
        array[0] = data;
        (*M)++;
    }

    (*C)++;
}

template <class T>
void SequentialList<T>::insertAtListTail(T data, int *C, int *M)
{
    if (length == 0)
        insertInEmptyList(data, C, M);

    else 
    {
        increaseListSize(C, M);
        array[length] = data;
        (*M)++;
    }

    (*C)++;
}

template <class T>
void SequentialList<T>::insertAtIndex(T data, int index, int *C, int *M)
{
    if (length == 0)
        insertAtListHead(data, C, M), (*C)++;

    else if (length <= index)
        insertAtListTail(data, C, M), (*C)++;

    else
    {
        increaseListSizeAndMoveOneIndexUp(0, C, M);
        array[index] = data;
        (*M)++;
        (*C) += 2;
    }
}

template <class T>
T SequentialList<T>::removeListHead(int *C, int *M)
{
    if (length == 0)
    {
        (*C)++;
        return nullptr;
    }
    (*C)++;

    T data = array[0];
    moveOneIndexDownAndDecreaseListSize(0, C, M);
    (*M)++;

    return T;
}

template <class T>
T SequentialList<T>::removeListTail(int *C, int *M)
{
    if (length == 0)
    {
        (*C)++;
        return nullptr;
    }
    (*C)++;
    
    T data = array[length - 1];
    decreaseListSize(C, M);
    (*M)++;

    return data;
}

template <class T>
T SequentialList<T>::removeAtIndex(int index, int *C, int *M)
{
    T data;

    if (length <= 1)
    {
        (*C)++;
        return removeListHead(C, M);
    }
    else if (length - 1 <= index)
    {
        (*C) += 2;
        return removeListTail(C, M);
    }
    (*C) += 2;

    data = array[index];
    moveOneIndexDownAndDecreaseListSize(index, C, M);

    (*M)++;
    return data;
}


template <class T>
void SequentialList<T>::increaseListSize(int *C, int *M)
{
    T aux = new T[length + 1];

    for (int i = 0; i < length; i++, (*C)++, (*M) += 3)
    {
        aux[i] = array[i],
        array[i] = nullptr;
    }

    delete array;
    array = aux;
    (*M)++;
}

template <class T>
void SequentialList<T>::moveOneIndexUp(int indexToMove, int *C, int *M)
{
    for (int i = length - 1; i >= indexToMove; i--, (*C)++, (*M) += 2)
        array[i] = array[i - 1];
}

template <class T>
void SequentialList<T>::increaseListSizeAndMoveOneIndexUp(int indexToMove, int *C, int *M)
{
    increaseListSize(C, M);
    moveOneIndexUp(indexToMove, C, M);
}

template <class T>
void SequentialList<T>::moveOneIndexDown(int indexToMove, int *C, int *M)
{
    for (int i = indexToMove; i < length; i++, (*C)++, (*M) += 2)
        array[i] = array[i + 1];
}

template <class T>
void SequentialList<T>::decreaseListSize(int *C, int *M)
{
    T aux = new T[length - 1];
    for (int i = 0; i < length - 1; i++, (*C)++, (*M) += 3)
    {
        aux[i] = array[i],
        array[i] = nullptr;
    }

    delete array;
    array = aux;
    (*M)++;
}

template <class T>
void SequentialList<T>::moveOneIndexDownAndDecreaseListSize(int indexToMove, int *C, int *M)
{
    moveOneIndexDown(indexToMove, C, M);
    decreaseListSize(C, M);
}
