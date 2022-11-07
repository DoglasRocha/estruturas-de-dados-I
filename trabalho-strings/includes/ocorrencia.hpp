//
// Created by doglasrocha on 11/6/22.
//

#ifndef TRABALHO_STRINGS_OCORRENCIA_HPP
#define TRABALHO_STRINGS_OCORRENCIA_HPP
#include "sequential-list.hpp"
#include <string>

using std::string;

class Ocorrencia {
private:
    string palavra;
    SequentialList<int *> posicoes;

public:
    Ocorrencia();
    ~Ocorrencia();
    Ocorrencia *setPalavra(string palavra_);
    Ocorrencia *addOcorrencia(int posicao);
    string getPalavra();
    SequentialList<int *> getOcorrencias();
};

#endif //TRABALHO_STRINGS_OCORRENCIA_HPP
