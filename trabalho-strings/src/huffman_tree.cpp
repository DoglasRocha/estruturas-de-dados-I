#include "../includes/huffman_tree.hpp"
#include <iostream>
#include <string>

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

        // std::cout << "1 " << node1->frequencia->getFreq() << " 2 " << node2->frequencia->getFreq()
        //           << " r " << node3->frequencia->getFreq() << std::endl; 
        if (node1->frequencia->getFreq() > node2->frequencia->getFreq())
            node3->left = node1,
            node3->right = node2;
        else
            node3->left = node2,
            node3->right = node1;

        listaNodes.insert(node3, 0);
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

void HuffmanTree::printLeaf(Node *leaf, std::string code) {
    if (leaf->frequencia->getPalavra())
        std::cout << *leaf->frequencia->getPalavra() << " " << code << std::endl;

    if (leaf->left) {
        printLeaf(leaf->left, code + '0');
    }
    
    if (leaf->right)
        printLeaf(leaf->right, code + '1');
}

void HuffmanTree::buildCodesTable(SequentialList<WordAndCode *> *listaCodigos) {
    assignCode(root, listaCodigos);
}

void HuffmanTree::assignCode(Node *leaf, SequentialList<WordAndCode *> *listaCodigos, std::string code) {
    if (leaf->frequencia->getPalavra()) {
        WordAndCode *codigo = new WordAndCode();

        char *palavra = leaf->frequencia->getPalavra()->substr(
            0, leaf->frequencia->getPalavra()->size()
        );

        codigo->word = palavra;
        codigo->code = new uint8_t[code.size()];
        codigo->tamCodigo = code.size();
        for (int i = 0; i < code.size(); i++)
            codigo->code[i] = code[i] == '1' ? 1 : 0;

        listaCodigos->insert(codigo, -1);
        
        delete []palavra;
    }

    if (leaf->left) {
        assignCode(leaf->left, listaCodigos, code + '0');
    } 

    if (leaf->right) {
        assignCode(leaf->right, listaCodigos, code + '1');
    }
}  
