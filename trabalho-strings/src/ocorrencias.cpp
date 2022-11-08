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
    for (int i = 0, l = posicoes.getLength(); i < l; i++)
        if (posicoes[i] == posicao)
            return this;
            
    posicoes.insert(posicao, -1);

    return this;
}

string Ocorrencia::getPalavra() {
    return palavra;
}

SequentialList<int> Ocorrencia::getOcorrencias() {
    return posicoes;
}
