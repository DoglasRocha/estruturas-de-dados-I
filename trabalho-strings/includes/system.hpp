//
// Created by doglasrocha on 11/6/22.
//

#ifndef TRABALHO_STRINGS_SYSTEM_HPP
#define TRABALHO_STRINGS_SYSTEM_HPP
#include "String.hpp"
#include "sequential-list.hpp"
#include "ocorrencia.hpp"

using std::string;

class System {
private:
    String texto;
    SequentialList<Ocorrencia *> listaOcorrencias;

public:
    System();
    ~System();
    void leArquivo();
    void imprimeTexto();
    void inverteArquivo();
    void imprimeArquivoInvertido();
    void forcaBruta(String *palavra);
    void addOcorrencia(String *palavra, long posicao);
    int binarySearch(String *palavra, int left, int right);
    int sequencialSearch(String *palavra);
    int imprimeMenu();
    void merge(int begin, int mid, int end);
    void mergeSort(int begin, int end);
    void imprimeOcorrencia(int posPalavra, int numOcorrencia=0);
    int lePalavra();
    void comprimirArquivo();
};

#endif //TRABALHO_STRINGS_SYSTEM_HPP
