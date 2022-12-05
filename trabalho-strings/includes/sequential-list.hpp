#pragma once
#include <cstdlib>

template <class T>
class SequentialList
{
    public:
        SequentialList();
        ~SequentialList();
        SequentialList<T> *insert(T data, int index);
        T remove(int index);
        T &operator[](int index);
        int getLength();
        SequentialList<T> *swap(int index1, int index2);

    SequentialList<T> *clear();

    private:
        int length;
        T *array;
        
        void insertInEmptyList(T data);
        void insertAtListHead(T data);
        void insertAtListTail(T data);
        void insertAtIndex(T data, int index);
        T removeListHead();
        T removeListTail();
        T removeAtIndex(int index);
        void increaseListSize();
        void moveOneIndexUp(int indexToMove);
        void increaseListSizeAndMoveOneIndexUp(int indexToMove);
        void moveOneIndexDown(int indexToMove);
        void decreaseListSize();
        void moveOneIndexDownAndDecreaseListSize(int indexToMove);
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
    free(array);
}

template <class T>
SequentialList<T> *SequentialList<T>::insert(T data, int index)
{
    switch (index)
    {
        case 0:
            insertAtListHead(data);
            break;

        case -1:
            insertAtListTail(data);
            break;

        default:
            insertAtIndex(data, index);
            break;
    }
    length++;

    return this;
}

template <class T>
T SequentialList<T>::remove(int index)
{
    T removedData;

    switch (index)
    {
        case 0:
            removedData = removeListHead();
            break;

        case -1:
            removedData = removeListTail();
            break;

        default:
            removedData = removeAtIndex(index);
            break;
    }

    length--;
    return removedData;
}

template <class T>
T &SequentialList<T>::operator[](int index)
{
    return array[index];
}

template <class T>
int SequentialList<T>::getLength()
{
    return length;
}

template <class T>
void SequentialList<T>::insertInEmptyList(T data)
{
    if (length == 0)
        array = static_cast<T *>(realloc(array, sizeof(T)));
    array[0] = data;
}

template <class T>
void SequentialList<T>::insertAtListHead(T data)
{
    if (length == 0)
        insertInEmptyList(data);

    else
    {
        increaseListSizeAndMoveOneIndexUp(0);
        array[0] = data;
    }
}

template <class T>
void SequentialList<T>::insertAtListTail(T data)
{
    if (length == 0)
        insertInEmptyList(data);

    else
    {
        increaseListSize();
        array[length] = data;
    }
}

template <class T>
void SequentialList<T>::insertAtIndex(T data, int index)
{
    if (length == 0)
        insertAtListHead(data);

    else if (length <= index)
        insertAtListTail(data);

    else
    {
        increaseListSizeAndMoveOneIndexUp(index);
        array[index] = data;
    }
}

template <class T>
T SequentialList<T>::removeListHead()
{
    if (length == 0)
        return NULL;

    T data = array[0];
    moveOneIndexDownAndDecreaseListSize(0);

    return data;
}

template <class T>
T SequentialList<T>::removeListTail()
{
    if (length == 0)
        return NULL;


    T data = array[length - 1];
    decreaseListSize();

    return data;
}

template <class T>
T SequentialList<T>::removeAtIndex(int index)
{
    T data;

    if (length <= 1)
        return removeListHead();

    else if (length - 1 <= index)
        return removeListTail();


    data = array[index];
    moveOneIndexDownAndDecreaseListSize(index);
    
    return data;
}


template <class T>
void SequentialList<T>::increaseListSize()
{
    array = static_cast<T *>(realloc(array, sizeof(T) * (length + 2)));
}

template <class T>
void SequentialList<T>::moveOneIndexUp(int indexToMove)
{
    for (int i = length; i > indexToMove; i--)
        array[i] = array[i - 1];
}

template <class T>
void SequentialList<T>::increaseListSizeAndMoveOneIndexUp(int indexToMove)
{
    increaseListSize();
    moveOneIndexUp(indexToMove);
}

template <class T>
void SequentialList<T>::moveOneIndexDown(int indexToMove)
{
    for (int i = indexToMove; i < (length-1); i++)
        array[i] = array[i + 1];
}

template <class T>
void SequentialList<T>::decreaseListSize()
{
    array = static_cast<T *>(realloc(array, sizeof(T) * (length - 1)));
}

template <class T>
void SequentialList<T>::moveOneIndexDownAndDecreaseListSize(int indexToMove)
{
    moveOneIndexDown(indexToMove);
    decreaseListSize();
}

template<class T>
SequentialList<T> *SequentialList<T>::swap(int index1, int index2)
{
    T tmp;

    tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;

    return this;
}

template<class T>
SequentialList<T> *SequentialList<T>::clear()
{
    if (array)
    {
        // for (int i = 0; i < length; i++)
        //     if (array[i] != NULL)
        //         delete array[i];

        free(array);
    }

    array = static_cast<T *>(malloc(sizeof(T)));
    length = 0;
    return this;
}
