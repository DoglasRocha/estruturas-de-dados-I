//
// Created by doglasrocha on 11/6/22.
//
#include "../includes/ocorrencia.hpp"

Ocorrencia::Ocorrencia() {
    posicoes = new SequentialList<int>();
}

Ocorrencia::~Ocorrencia() {
    delete posicoes;
}

Ocorrencia *Ocorrencia::setPalavra(string palavra_) {
    palavra = palavra_;

    return this;
}

Ocorrencia *Ocorrencia::addOcorrencia(int posicao) {
    posicoes->insert(posicao, -1);

    return this;
}

string Ocorrencia::getPalavra() {
    return palavra;
}

SequentialList<int> *Ocorrencia::getOcorrencias() {
    return posicoes;
}
