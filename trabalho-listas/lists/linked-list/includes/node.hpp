#pragma once

template <class T> 
class Node
{
    public:
        Node *next, *prev;
        T data;

        Node(T data_=nullptr);
        ~Node();
};
