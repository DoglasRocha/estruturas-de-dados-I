#include "../includes/node.hpp"

template <class T> 
Node<T>::Node(T data_)
{
    data = data_;
    next = prev = nullptr;
}

template <class T>
Node<T>::~Node()
{
    delete data;
}