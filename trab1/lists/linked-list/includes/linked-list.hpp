#pragma once
#include "node.hpp"
#include "../../common/includes/person.hpp"
#include "../../includes/list.hpp"

template <class T>
class LinkedList : public List<T>
{
    public:
        int length;

        LinkedList();
        ~LinkedList();
        LinkedList<T> *insert(T data, int index, int *C, int *M);
        T remove(int index, int *C, int *M);
        T getAt(int index, int *C, int *M);

    private:
        Node<T> *head, *tail, *auxPointer;
        int auxPointerIndex;

        void insertInEmptyList(Node<T> *node, int *C, int *M);
        void insertAtListHead(Node<T> *node, int *C, int *M);
        void insertAtListTail(Node<T> *node, int *C, int *M);
        void insertAtIndex(Node<T> *node, int index, int *C, int *M);
        Node<T> *getNodeAt(int index, int *C, int *M);
        Node<T> *removeListHead(int *C, int *M);
        Node<T> *removeListTail(int *C, int *M);
        Node<T> *removeAtIndex(int index, int *C, int *M);
};