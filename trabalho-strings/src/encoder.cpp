#include "../includes/encoder.hpp"
#include <iostream>

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

}

void Encoder::printList() {
    for (int i = 0, l = listaFrequencias.getLength(); i < l; i++)
    {
        cout << *listaFrequencias[i]->getPalavra() << ": "
             << listaFrequencias[i]->getFreq() << endl;
    }
}

Encoder::Encoder() {

}

Encoder::~Encoder() {
    for (int i = 0; i < listaFrequencias.getLength(); i++)
        delete listaFrequencias[i];
}

Encoder::Encoder(SequentialList<Ocorrencia *> *listaOcorrencias) {
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
    printList();
}

Encoder::Frequency::Frequency() {
    palavra = nullptr;
    freq = 0;
}

Encoder::Frequency::~Frequency() {
    delete palavra;
}

void Encoder::Frequency::setPalavra(String *palavra) {
    this->palavra = new String();
    *this->palavra = *palavra;
}

String *Encoder::Frequency::getPalavra() const {
    return palavra;
}

void Encoder::Frequency::setFreq(int freq) {
    this->freq = freq;
}

int Encoder::Frequency::getFreq() const {
    return freq;
}
