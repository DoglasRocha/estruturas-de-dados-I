#pragma once
#include "../../common/includes/person.hpp"

template <class T>
class SequentialList
{
    public:
        SequentialList();
        ~SequentialList();
        SequentialList<T> *insert(T data, int index, int *C, int *M);
        T remove(int index, int *C, int *M);
        T operator[](int index);
        int getLength();
        SequentialList<T> *swap(int index1, int index2, int *C, int *M);
        SequentialList<T> *swapAndShift(int from, int to, int *C, int *M);
        SequentialList<T> *clear();

    private:
        int length;
        T *array;
        
        void insertInEmptyList(T data, int *C, int *M);
        void insertAtListHead(T data, int *C, int *M);
        void insertAtListTail(T data, int *C, int *M);
        void insertAtIndex(T data, int index, int *C, int *M);
        T removeListHead(int *C, int *M);
        T removeListTail(int *C, int *M);
        T removeAtIndex(int index, int *C, int *M);
        void increaseListSize(int *C, int *M);
        void moveOneIndexUp(int indexToMove, int *C, int *M);
        void increaseListSizeAndMoveOneIndexUp(int indexToMove, int *C, int *M);
        void moveOneIndexDown(int indexToMove, int *C, int *M);
        void decreaseListSize(int *C, int *M);
        void moveOneIndexDownAndDecreaseListSize(int indexToMove, int *C, int *M);
};

template <class T>
SequentialList<T>::SequentialList()
{
    length = 0;
    array = static_cast<T *>(malloc(sizeof(T)));
}

template <class T>
SequentialList<T>::~SequentialList()
{
    clear();
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

    return this;
}

template <class T>
T SequentialList<T>::remove(int index, int *C, int *M)
{
    T removedData;

    switch (index)
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
T SequentialList<T>::operator[](int index)
{
    return array[index];
}

template <class T>
int SequentialList<T>::getLength()
{
    return length;
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
        increaseListSizeAndMoveOneIndexUp(index, C, M);
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
        return NULL;
    }
    (*C)++;

    T data = array[0];
    moveOneIndexDownAndDecreaseListSize(0, C, M);
    (*M)++;

    return data;
}

template <class T>
T SequentialList<T>::removeListTail(int *C, int *M)
{
    if (length == 0)
    {
        (*C)++;
        return NULL;
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
    array = static_cast<T *>(realloc(array, sizeof(T) * (length + 2)));
    (*M)++;
}

template <class T>
void SequentialList<T>::moveOneIndexUp(int indexToMove, int *C, int *M)
{
    for (int i = length; i > indexToMove; i--, (*C)++, (*M) += 2)
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
    array = static_cast<T *>(realloc(array, sizeof(T) * (length + 1)));
    (*M)++;
}

template <class T>
void SequentialList<T>::moveOneIndexDownAndDecreaseListSize(int indexToMove, int *C, int *M)
{
    moveOneIndexDown(indexToMove, C, M);
    decreaseListSize(C, M);
}

template<class T>
SequentialList<T> *SequentialList<T>::swap(int index1, int index2, int *C, int *M)
{
    T tmp;

    tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
    (*M) += 3;

    return this;
}

template<class T>
SequentialList<T> *SequentialList<T>::swapAndShift(int from, int to, int *C, int *M)
{
    if (from == -1)
        from = 0;

    (*C)++;

    T tmp = array[to];

    for (int i = to; i > from; i--, (*C)++, (*M) += 2)
        array[i] = array[i - 1];

    array[from] = tmp;
    (*M) += 2;

    return this;
}

template<class T>
SequentialList<T> *SequentialList<T>::clear()
{
    if (array)
    {
        for (int i = 0; i < length; i++)
            if (array[i] != NULL)
                delete array[i];

        free(array);
    }

    array = static_cast<T *>(malloc(sizeof(T)));
    length = 0;
    return this;
}
