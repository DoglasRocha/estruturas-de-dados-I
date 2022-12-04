#include "sequential-list.hpp"
#include "ocorrencia.hpp"
#include "frequency.hpp"
#include "huffman_tree.hpp"

class Encoder {
    private:
        SequentialList<Frequency *> listaFrequencias;
        HuffmanTree *tree = nullptr;
        String texto;

        void merge(int begin, int mid, int end);
        void mergeSort(int begin, int end);
        void buildHuffmanTree();
        void printList();
    
    public:
        Encoder();
        ~Encoder();
        Encoder(SequentialList<Ocorrencia *> *listaOcorrencias, String texto);
        void encode();
};