#include "sequential-list.hpp"
#include "ocorrencia.hpp"
#include "huffman_tree.hpp"

class Encoder {
    public:
        class Frequency {
            private:
                String *palavra;
                int freq;

            public:
                Frequency();
                ~Frequency();
                void setPalavra(String *palavra);
                String *getPalavra() const;
                void setFreq(int freq);
                int getFreq() const;
        };

    private:
        SequentialList<Frequency *> listaFrequencias;
        HuffmanTree *tree = nullptr;

        void merge(int begin, int mid, int end);
        void mergeSort(int begin, int end);
        void buildHuffmanTree();
        void printList();
    
    public:
        Encoder();
        ~Encoder();
        Encoder(SequentialList<Ocorrencia *> *listaOcorrencias);
        void encode();
};