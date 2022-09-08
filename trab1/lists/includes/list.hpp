#pragma once

template <class T>
class List
{
    public:
        virtual List<T> *insert(T data, int index, int *C, int *M) = 0;
        virtual T remove(int index, int *C, int *M) = 0;
        virtual T getAt(int index, int *C, int *M) = 0;
};