#include "../includes/encoder.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

void Encoder::merge(int begin, int mid, int end) {
    int leftSize, rightSize, leftCount = 0, rightCount = 0, mergedIndex = begin;
    Frequency **leftList, **rightList;
    leftSize = mid - begin + 1;
    rightSize = end - mid;
    leftList = new Frequency*[leftSize];
    rightList = new Frequency*[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftList[i] = listaFrequencias[begin + i];

    for (int i = 0; i < rightSize; i++)
        rightList[i] = listaFrequencias[mid + 1 + i];

    while (leftCount < leftSize && rightCount < rightSize)
    {
        if (leftList[leftCount]->getFreq() <= rightList[rightCount]->getFreq())
            listaFrequencias[mergedIndex] = leftList[leftCount],
            leftCount++;

        else
            listaFrequencias[mergedIndex] = rightList[rightCount],
            rightCount++;

        mergedIndex++;
    }

    while (leftCount < leftSize)
        listaFrequencias[mergedIndex] = leftList[leftCount],
        leftCount++,
        mergedIndex++;

    while (rightCount < rightSize)
        listaFrequencias[mergedIndex] = rightList[rightCount],
        rightCount++,
        mergedIndex++;

    delete []rightList;
    delete []leftList;
}

void Encoder::mergeSort(int begin, int end) {
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

void Encoder::buildHuffmanTree() {
    tree = new HuffmanTree(&listaFrequencias);
    tree->build();    
    //tree->printTree();
    tree->buildCodesTable(&listaCodigos);
    delete tree;
}

void Encoder::printList() {
    for (int i = 0, l = listaFrequencias.getLength(); i < l; i++)
    {
        cout << *listaFrequencias[i]->getPalavra() << ": "
             << listaFrequencias[i]->getFreq() << endl;
    }
}

void Encoder::printToFile() {
    FILE *output;
    int numPalavrasUnicas = 0, numTotalPalavras = 0;
    char nomeArquivo[100];

    numPalavrasUnicas = listaFrequencias.getLength();
    for (int i = 0; i < listaFrequencias.getLength(); i++)
        numTotalPalavras += listaFrequencias[i]->getFreq();

    cout << "Digite o nome do arquivo de destino: ";
    cin >> nomeArquivo;

    output = fopen(nomeArquivo, "w");
    if (output) {
        fwrite(&numPalavrasUnicas, sizeof(int), 1, output);
        //output.write(reinterpret_cast<char *>(&numTotalPalavras), sizeof(int));
        fwrite(&numTotalPalavras, sizeof(int), 1, output);
        //output.write(reinterpret_cast<char *>(&numTotalPalavras), sizeof(int));
        for (int i = 0; i < listaCodigos.getLength(); i++) {
            //output.write(reinterpret_cast<char *>(listaCodigos[i]), sizeof(WordAndCode));
            fwrite(&listaCodigos[i]->word, sizeof(std::string), 1, output);
            for (int j = 0; j < listaCodigos[i]->tamCodigo; j++)
                fwrite(&(listaCodigos[i]->code[j]), sizeof(uint8_t), 1, output);
        }

        fclose(output);
    }
}

Encoder::Encoder() {

}

Encoder::~Encoder() {
    for (int i = 0; i < listaFrequencias.getLength(); i++)
        delete listaFrequencias[i];

    for (int i = 0; i < listaCodigos.getLength(); i++)
        delete listaCodigos[i];
}

Encoder::Encoder(SequentialList<Ocorrencia *> *listaOcorrencias, String texto) {
    this->texto = texto;
    Frequency *frequencia = nullptr;

    for (int i = 0; i < listaOcorrencias->getLength(); i++) {
        frequencia = new Frequency();
        frequencia->setPalavra((*listaOcorrencias)[i]->getPalavra());
        frequencia->setFreq((*listaOcorrencias)[i]->getOcorrencias()->getLength());

        listaFrequencias.insert(frequencia, -1);
    }
}

void Encoder::encode() {
    mergeSort(0, listaFrequencias.getLength() - 1);
    buildHuffmanTree();
    printToFile();
}
