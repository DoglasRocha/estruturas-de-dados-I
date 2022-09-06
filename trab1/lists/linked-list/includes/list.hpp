#pragma once
#include "node.hpp"
#include "../../common/includes/person.hpp"

template <class T>
class LinkedList
{
    public:
        Node<T> *head;
        Node<T> *tail;
        int length;

        LinkedList();
        ~LinkedList();
        LinkedList<T> *insert(T *data, int index, int *C, int *M);
        void remove(int index, int *C, int *M);
        T *search(long rg, int *foundAt, int *C, int *M);
        void print();

    private:
        void insertInEmptyList(Node<T> *node, int *C, int *M);
        void insertAtListHead(Node<T> *node, int *C, int *M);
        void insertAtListTail(Node<T> *node, int *C, int *M);
        void insertAtIndex(Node<T> *node, int index, int *C, int *M);
        Node<T> *getAtIndex(int index, int *C, int *M);
        Node<T> *removeHeadNode(int *C, int *M);
        Node<T> *removeTailNode(int *C, int *M);
        Node<T> *removeAtIndex(int index, int *C, int *M);
};