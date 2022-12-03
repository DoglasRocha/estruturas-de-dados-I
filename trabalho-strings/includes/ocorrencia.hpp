//
// Created by doglasrocha on 11/6/22.
//

#ifndef TRABALHO_STRINGS_OCORRENCIA_HPP
#define TRABALHO_STRINGS_OCORRENCIA_HPP
#include "sequential-list.hpp"
#include "String.hpp"

class Ocorrencia {
private:
    String *palavra;
    SequentialList<int> posicoes;

public:
    Ocorrencia();
    ~Ocorrencia();
    Ocorrencia *setPalavra(String *palavra_);
    Ocorrencia *addOcorrencia(int posicao);
    String *getPalavra();
    SequentialList<int> getOcorrencias();
    int binarySearch(int key, int left, int right);
};

#endif //TRABALHO_STRINGS_OCORRENCIA_HPP
