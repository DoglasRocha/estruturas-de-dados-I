#include "../includes/list.hpp"
#include "../includes/node.hpp"
#include <iostream>

template <class T> 
LinkedList<T>::LinkedList()
{
    head = tail = nullptr;
    length = 0;
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    for (T *aux = head; aux != nullptr; aux = aux->next)
        delete aux;
}

template <class T> 
LinkedList<T> *LinkedList<T>::insert(T *data, int index, int *C, int *M)
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

    length++;

    return this;
}

template <class T> 
void LinkedList<T>::remove(int index, int *C, int *M)
{
    Node<T> *removedNode;

    switch(index) 
    {
    case 0:
        removedNode = removeHeadNode(C, M);
        (*C)++;
        break;

    case -1:
        removedNode = removeTailNode(C, M);
        (*C) += 2;
        break;

    default:
        removedNode = removeAtIndex(index, C, M);
        (*C) += 2;
        break;
    }

    length--;
    delete removedNode;
}

template <class T> 
T *LinkedList<T>::search(long rg, int *foundAt, int *C, int *M)
{
    Node<T> *aux;
    int i;

    for (aux = head, i = 0; 
         aux != nullptr; 
         aux = aux->next, i++, (*C) += 2, (*M)++)
    {
        if (aux->data->rg == rg)
        {
            *foundAt = i;
            return aux->data;
        }
    }

    *foundAt = i;
    return nullptr;
}

template <class T> 
void LinkedList<T>::print()
{
    int i = 0;
    for (Node<T> *aux = head; aux != nullptr; aux = aux->next, i++)
        std::cout << "Nome: " << aux->data->name << ", RG: " << aux->data->rg 
            << ", posição: " << i << "\n";
}


template <class T> 
void LinkedList<T>::insertInEmptyList(Node<T> *node, int *C, int *M)
{
    head = tail = node,
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
        node->prev = NULL; 

        (*M) += 4;
    }

    (*C)++;
}

template <class T> 
void LinkedList<T>::insertAtListTail(Node<T> *node, int *C, int *M)
{

}

template <class T> 
void LinkedList<T>::insertAtIndex(Node<T> *node, int index, int *C, int *M)
{

}

template <class T> 
Node<T> *LinkedList<T>::getAtIndex(int index, int *C, int *M)
{

}

template <class T> 
Node<T> *LinkedList<T>::removeHeadNode(int *C, int *M)
{

}

template <class T> 
Node<T> *LinkedList<T>::removeTailNode(int *C, int *M)
{

}

template <class T> 
Node<T> *LinkedList<T>::removeAtIndex(int index, int *C, int *M)
{

}
