#include "../includes/huffman_tree.hpp"
#include <iostream>

Node::Node() {
    frequencia = nullptr;
    left = right = nullptr;
}

Node::~Node() {
    if (left)
        delete left;

    if (right)
        delete right;
}

HuffmanTree::HuffmanTree() {
    root = nullptr;
}

HuffmanTree::~HuffmanTree() {
    if (root)
        delete root;
}

HuffmanTree::HuffmanTree(SequentialList<Frequency *> *listaFrequencias) :
HuffmanTree() 
{
    Node *node;
    for (int i = 0, l = listaFrequencias->getLength(); i < l; i++) {
        node = new Node();
        node->frequencia = (*listaFrequencias)[i];
        std::cout << node->frequencia->getFreq() << "," << *node->frequencia->getPalavra() << std::endl;
        listaNodes.insert(node, -1);
    }
}

void HuffmanTree::build() {
    Node *node1, *node2, *node3;

    while (listaNodes.getLength() != 1) {
        node1 = listaNodes.remove(0);
        node2 = listaNodes.remove(0);

        node3 = new Node();
        node3->frequencia = new Frequency();
        node3->frequencia->setFreq(node1->frequencia->getFreq() + node2->frequencia->getFreq());

        if (node1->frequencia->getFreq() < node2->frequencia->getFreq())
            node3->left = node1,
            node3->right = node2;
        else
            node3->left = node2,
            node3->right = node1;

        listaNodes.insert(node3, -1);
        insertionSort();
    }

    root = node3;
}

void HuffmanTree::insertionSort() {
    int i, j, l = listaNodes.getLength();
    Node *current;

    for (i = 1; i < l; i++)
    {
        current = listaNodes[i];

        for (j = i; j >= 1 && current->frequencia->getFreq() < listaNodes[j - 1]->frequencia->getFreq(); j -= 1)
            listaNodes[j] = listaNodes[j - 1];

        listaNodes[j] = current;
    }

}

void HuffmanTree::printTree() {
    printLeaf(root);
}

void HuffmanTree::printLeaf(Node *leaf) {
    if (leaf->left) 
        printLeaf(leaf->left);
    
    if (leaf->right)
        printLeaf(leaf->right);

    std::cout << leaf->frequencia->getFreq() << " ";

    if (leaf->frequencia->getPalavra())
        std::cout << *leaf->frequencia->getPalavra();

    std::cout << std::endl;
}
