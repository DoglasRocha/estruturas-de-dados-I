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
        void swap(int index1, int index2, int *C, int *M);
        void swapAndShift(int from, int to, int *C, int *M);

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