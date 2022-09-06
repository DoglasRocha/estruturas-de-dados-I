#include "../includes/list.hpp"
#include "../includes/node.hpp"

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
}

template <class T> 
void LinkedList<T>::remove(int index, int *C, int *M)
{

}

template <class T> 
T *LinkedList<T>::search(long rg, int *foundAt, int *C, int *M)
{

}

template <class T> 
void LinkedList<T>::print()
{

}


template <class T> 
void LinkedList<T>::insertInEmptyList(Node<T> *node, int *C, int *M)
{

}

template <class T> 
void LinkedList<T>::insertAtListHead(Node<T> *node, int *C, int *M)
{

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
