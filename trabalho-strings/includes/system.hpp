//
// Created by doglasrocha on 11/6/22.
//

#ifndef TRABALHO_STRINGS_SYSTEM_HPP
#define TRABALHO_STRINGS_SYSTEM_HPP
#include <string>
#include "sequential-list.hpp"
#include "ocorrencia.hpp"

using std::string;

class System {
private:
    string texto;
    SequentialList<Ocorrencia *> listaOcorrencias;

public:
    System();
    ~System();
    void leArquivo();
    void imprimeTexto();
    void inverteArquivo();
    void imprimeOcorrencias();
    void forcaBruta(string &palavra);
    void addOcorrencia(string &palavra, long posicao);
    int binarySearch(string &palavra, int left, int right);
    int sequencialSearch(string &palavra);
};

#endif //TRABALHO_STRINGS_SYSTEM_HPP
