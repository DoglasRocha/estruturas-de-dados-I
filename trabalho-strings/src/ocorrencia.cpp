//
// Created by doglasrocha on 11/6/22.
//
#include "../includes/ocorrencia.hpp"

Ocorrencia::Ocorrencia() {

}

Ocorrencia::~Ocorrencia() {
    // for (int i = 0, l = posicoes.getLength(); i < l; i++)
    //     delete posicoes[i];
}

Ocorrencia *Ocorrencia::setPalavra(string palavra_) {
    palavra = palavra_;

    return this;
}

Ocorrencia *Ocorrencia::addOcorrencia(int posicao) {
    int buscaPosicao = binarySearch(posicao, 0, posicoes.getLength() - 1);

    if (buscaPosicao == -1)
        posicoes.insert(posicao, -1);

    return this;
}

string Ocorrencia::getPalavra() {
    return palavra;
}

SequentialList<int> Ocorrencia::getOcorrencias() {
    return posicoes;
}

int Ocorrencia::binarySearch(int key, int left, int right) {
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (posicoes[mid] == key)
            return mid;

        if (posicoes[mid] > key)
            return binarySearch(key, left, mid - 1);

        return binarySearch(key, mid + 1, right);
    }
    return -1;
}
