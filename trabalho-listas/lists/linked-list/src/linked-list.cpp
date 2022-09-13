#include "../includes/linked-list.hpp"
#include "../includes/node.hpp"
#include "node.cpp"
#include <iostream>

template <class T> 
LinkedList<T>::LinkedList()
{
    head = tail = auxPointer = nullptr;
    length = auxPointerIndex = 0;
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    Node<T> *tmp, *aux;
    for (tmp = head; tmp != nullptr; tmp = aux)
    {
        aux = tmp->next;
        delete tmp;
    }
}

template <class T> 
LinkedList<T> *LinkedList<T>::insert(T data, int index, int *C, int *M)
{
    Node<T> *node = new Node<T>(data);

    switch (index)
    {
    case 0:
        insertAtListHead(node, C, M);
        (*C)++;
        break;
    
    case -1:
        insertAtListTail(node, C, M);
        (*C) += 2;
        break;

    default:
        insertAtIndex(node, index, C, M);
        (*C) += 2;
        break;
    }

    if (index <= auxPointerIndex)
        auxPointerIndex++;
    
    length++;

    return this;
}

template <class T> 
T LinkedList<T>::remove(int index, int *C, int *M)
{
    Node<T> *removedNode;
    T data;

    switch(index) 
    {
    case 0:
        removedNode = removeListHead(C, M);
        (*C)++;
        break;

    case -1:
        removedNode = removeListTail(C, M);
        (*C) += 2;
        break;

    default:
        removedNode = removeAtIndex(index, C, M);
        (*C) += 2;
        break;
    }

    
    data = removedNode->data;
    removedNode->data = nullptr;
    length--;
    (*M) += 3;
    delete removedNode;
    return data;
}

template <class T>
T LinkedList<T>::getAt(int index, int *C, int *M)
{
    return getNodeAt(index, C, M)->data;
}

template <class T>
int LinkedList<T>::getLength()
{
    return length;
}

template <class T> 
void LinkedList<T>::insertInEmptyList(Node<T> *node, int *C, int *M)
{
    head = tail = auxPointer = node,
    node->prev = node->next = nullptr,
    (*M) += 4;
}

template <class T> 
void LinkedList<T>::insertAtListHead(Node<T> *node, int *C, int *M)
{
    if (length == 0)
        insertInEmptyList(node, C, M);

    else
    {
        node->next = head;
        head->prev = node;
        head = node; 
        node->prev = nullptr; 

        (*M) += 4;
    }

    (*C)++;
}

template <class T> 
void LinkedList<T>::insertAtListTail(Node<T> *node, int *C, int *M)
{
    if (length == 0)
        insertInEmptyList(node, C, M);

    else        
    {
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
        (*M) += 4;
    }

    (*C)++;
}

template <class T> 
void LinkedList<T>::insertAtIndex(Node<T> *node, int index, int *C, int *M)
{
    Node<T> *aux;

    if (length == 0)
        insertInEmptyList(node, C, M),
        (*C)++;
    

    else if (length <= index)
        insertAtListTail(node, C, M),
        (*C) += 2;

    else
    {
        aux = getNodeAt(index, C, M);

        node->prev = aux->prev;
        aux->prev->next = node; 
        node->next = aux;
        aux->prev = node;
        (*M) += 4;
        (*C) += 2;
    }
}

template <class T> 
Node<T> *LinkedList<T>::getNodeAt(int index, int *C, int *M)
{
    int indexDelta = index - auxPointerIndex,
        diffToHead = index,
        diffToTail = length - 1 - index;

    if (-diffToHead > indexDelta)
        auxPointer = head,
        auxPointerIndex = 0,
        indexDelta = index - auxPointerIndex,
        (*M) += 3;

    if (diffToTail < indexDelta)
        auxPointer = tail,
        auxPointerIndex = length - 1,
        indexDelta = index - auxPointerIndex,
        (*M) += 3;

    (*C) += 2;

    if (indexDelta > 0)
    {
        while (index != auxPointerIndex)
        {
            auxPointerIndex++,
            auxPointer = auxPointer->next;
            (*C)++, (*M) += 2;

            if (auxPointer == nullptr)
                auxPointerIndex = 0,
                auxPointer = head;
        }
        (*C)++;
    }
    else
    {
        while (index != auxPointerIndex)
        {
            auxPointerIndex--,
            auxPointer = auxPointer->prev;
            (*C)++, (*M) += 2;

            if (auxPointer == nullptr)
                auxPointerIndex = length -1,
                auxPointer = tail;
        }
        (*C)++;
    }

    return auxPointer;
}

template <class T> 
Node<T> *LinkedList<T>::removeListHead(int *C, int *M)
{
    if (head == nullptr)
    {
        (*C)++;
        return nullptr;
    }
    (*C)++;

    Node<T> *nodeToRemove = head;

    head = nodeToRemove->next;

    if (head) head->prev = nullptr;
    auxPointerIndex--;
    (*C)++;
    (*M) += 3;
    
    return nodeToRemove;
}

template <class T> 
Node<T> *LinkedList<T>::removeListTail(int *C, int *M)
{
    if (tail == nullptr)
    {
        (*C)++;
        return nullptr;
    }
    (*C)++;
    
    Node<T> *nodeToRemove = tail;

    tail = nodeToRemove->prev;
    if (tail != nullptr) 
        tail->next = nullptr;

    auxPointer = tail,
    auxPointerIndex--;

    (*M) += 5;
    (*C)++;
    return nodeToRemove;
}

template <class T> 
Node<T> *LinkedList<T>::removeAtIndex(int index, int *C, int *M)
{
    Node<T> *nodeToRemove;

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

    nodeToRemove = getNodeAt(index, C, M);

    nodeToRemove->prev->next = nodeToRemove->next;
    nodeToRemove->next->prev = nodeToRemove->prev;

    auxPointer = nodeToRemove->next;

    (*M) += 4;
    return nodeToRemove;
}
