#pragma once
#include "frequency.hpp"
#include "sequential-list.hpp"

class Node {
    private:
        Frequency *frequencia;
        Node *left, *right;

    public:
        Node();
        ~Node();
        friend class HuffmanTree;
};

class HuffmanTree {
    private:
        Node *root;
        SequentialList<Node *> listaNodes;
        
    public:
        HuffmanTree();
        HuffmanTree(SequentialList<Frequency *> *listaFrequencias);
        ~HuffmanTree();
        void build();
        void insertionSort();
        void printTree();
        void printLeaf(Node *leaf, std::string code="0");
};