//
// Created by doglasrocha on 11/6/22.
//
#include "../includes/system.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>

using namespace std;

System::System() {
    leArquivo();
    // imprimeTexto();
    inverteArquivo();
    imprimeOcorrencias();
}

System::~System() {
    for (int i = 0, l = listaOcorrencias.getLength(); i < l; i++)
        delete listaOcorrencias[i];
}

void System::leArquivo() {
    ifstream input("Historia.txt");
    stringstream buffer;

    input >> buffer.rdbuf();

    texto = buffer.str();
}

void System::imprimeTexto() {
    cout << texto << endl;
}

int System::binarySearch(string &palavra, int left, int right) {
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (listaOcorrencias[mid]->getPalavra() == palavra)
            return mid;

        if (listaOcorrencias[mid]->getPalavra() > palavra)
            return binarySearch(palavra, left, mid - 1);

        return binarySearch(palavra, mid + 1, right);
    }
    return -1;
}

int System::sequencialSearch(string &palavra) {
    for (int i = 0, l = listaOcorrencias.getLength(); i < l; i++)
        if (listaOcorrencias[i]->getPalavra() == palavra)
            return i;

    return -1;
}

void System::inverteArquivo() {
    int i, posEspaco, tamTexto = texto.size();
    string palavra;
    for (i = posEspaco = 0; posEspaco < tamTexto; posEspaco++)
    {
        while (isalpha(texto[posEspaco]))
            posEspaco++;

        if (isalpha(texto[i]))
            palavra = texto.substr(i, posEspaco),
            forcaBruta(palavra);
        posEspaco++;
        i = posEspaco;
    }
    palavra = texto.substr(i, posEspaco);
    forcaBruta(palavra);
}

void System::imprimeOcorrencias() {
    for (int i = 0, l = listaOcorrencias.getLength(); i < l; i++)
    {
        cout << listaOcorrencias[i]->getPalavra() << ": ";
        for (int j = 0, m = listaOcorrencias[i]->getOcorrencias().getLength(); j < m; j++) {
            cout << listaOcorrencias[i]->getOcorrencias()[j] << ", ";
        }
        cout << endl;
    }
}

void System::forcaBruta(string &palavra) {
    long i, j, k, n, m;
    m = palavra.size();
    n = texto.size();

    for (i = 1; i <= (n - m + 1); i++) {
        k = i, j = 1;
        while (palavra[j - 1] == texto[k - 1] && j <= m)
            j++, k++;

        if (j > m)
            addOcorrencia(palavra, i);
    }
}

void System::addOcorrencia(string &palavra, long posicao) {
    int resultadoPesquisa = sequencialSearch(palavra);

    if (resultadoPesquisa == -1)
    {
        Ocorrencia *ocorrencia = new Ocorrencia();
        ocorrencia->setPalavra(palavra);
        ocorrencia->addOcorrencia(posicao);
        listaOcorrencias.insert(ocorrencia, -1);
    }
    else
        listaOcorrencias[resultadoPesquisa]->addOcorrencia(posicao);
}

