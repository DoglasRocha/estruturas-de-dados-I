#include "../includes/list.hpp"

template <class T>
SequentialList<T>::SequentialList()
{
    length = 0;
    array = nullptr;
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

}

template <class T>
T SequentialList<T>::remove(int index, int *C, int *M)
{

}

template <class T>
T SequentialList<T>::getAt(int index, int *C, int *M)
{

}

template <class T>
void SequentialList<T>::insertInEmptyList(T data, int *C, int *M)
{

}

template <class T>
void SequentialList<T>::insertAtListHead(T data, int *C, int *M)
{

}

template <class T>
void SequentialList<T>::insertAtListTail(T data, int *C, int *M)
{

}

template <class T>
void SequentialList<T>::insertAtIndex(T data, int index, int *C, int *M)
{

}

template <class T>
T SequentialList<T>::removeListHead(int *C, int *M)
{

}

template <class T>
T SequentialList<T>::removeListTail(int *C, int *M)
{

}

template <class T>
T SequentialList<T>::removeAtIndex(int index, int *C, int *M)
{

}
