//
// Created by doglasrocha on 11/6/22.
//
#include "../includes/system.hpp"
#include "../includes/encoder.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

System::System() {
    int opcao;
    int posPalavra;

    do {
        opcao = imprimeMenu();
        switch (opcao) {
            case 1:
                leArquivo();
                inverteArquivo();
                break;

            case 2:
                imprimeTexto();
                break;

            case 3:
                imprimeArquivoInvertido();
                break;

            case 4:
                posPalavra = lePalavra();
                imprimeOcorrencia(posPalavra);
                break;

            case 5:
                comprimirArquivo();
                break;
        }
    } while (opcao != 6);
}

System::~System() {
    for (int i = 0, l = listaOcorrencias.getLength(); i < l; i++)
        delete listaOcorrencias[i];
}

void System::leArquivo() {
    string path;

    cout << "Qual o nome do arquivo?" << endl;
    cin >> path;

    ifstream input(path);
    stringstream buffer;

    input >> buffer.rdbuf();

    texto = buffer.str();
    // convertendo para lowercase
    for (int i = 0, l = texto.size(); i < l; i++)
        texto[i] = tolower(texto[i]);
}

void System::imprimeTexto() {
    cout << texto << endl;
}

int System::binarySearch(String *palavra, int left, int right) {
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (*listaOcorrencias[mid]->getPalavra() == *palavra)
            return mid;

        if (*listaOcorrencias[mid]->getPalavra() > *palavra)
            return binarySearch(palavra, left, mid - 1);

        return binarySearch(palavra, mid + 1, right);
    }
    return -1;
}

int System::sequencialSearch(String *palavra) {
    for (int i = 0, l = listaOcorrencias.getLength(); i < l; i++)
        if (*listaOcorrencias[i]->getPalavra() == *palavra)
            return i;
            
    return -1;
}

void System::inverteArquivo() {
    int i, posEspaco, tamTexto = texto.size();
    i = posEspaco = 0;
    String *palavra = new String();
    char *vetCharPalavra = nullptr;

    while (posEspaco < tamTexto - 1)
    {
        i = posEspaco;
        while (texto[posEspaco] != ' ' &&
               /*texto[posEspaco] != ',' &&
               texto[posEspaco] != '.' &&
               texto[posEspaco] != '!' &&
               */texto[posEspaco] != '-' /*&&
               texto[posEspaco] != ':' &&
               texto[posEspaco] != '?' &&
               texto[posEspaco] != '"' &&
               texto[posEspaco] != '\n'*/)
            posEspaco++;


        vetCharPalavra = texto.substr(i, posEspaco - i);
        *palavra = vetCharPalavra;

        posEspaco++;
        if (palavra->size() >= 1)
            forcaBruta(palavra);

        delete []vetCharPalavra;
    }

    mergeSort(0, listaOcorrencias.getLength() - 1);
    delete palavra;
}

void System::imprimeArquivoInvertido() {
    for (int i = 0, l = listaOcorrencias.getLength(); i < l; i++)
    {
        cout << *listaOcorrencias[i]->getPalavra() << ": ";
        for (int j = 0, m = listaOcorrencias[i]->getOcorrencias()->getLength(); j < m; j++) {
            cout << (*listaOcorrencias[i]->getOcorrencias())[j] << " ";
        }
        cout << endl;
    }
}

void System::forcaBruta(String *palavra) {
    long i, j, k, n, m;
    m = palavra->size();
    n = texto.size();

    for (i = 1; i <= (n - m + 1); i++) {
        k = i, j = 1;
        while ((*palavra)[j - 1] == texto[k - 1] && j <= m)
            j++, k++;

        if (j > m)
            addOcorrencia(palavra, i);
    }
}

void System::addOcorrencia(String *palavra, long posicao) {
    int resultadoPesquisa = sequencialSearch(palavra);

    if (resultadoPesquisa == -1)
    {
        Ocorrencia *ocorrencia = new Ocorrencia();
        ocorrencia->setPalavra(palavra);
        ocorrencia->addOcorrencia(posicao);
        listaOcorrencias.insert(ocorrencia, -1);
    }
    else
    {
        listaOcorrencias[resultadoPesquisa]->addOcorrencia(posicao);
    }
}

int System::imprimeMenu() {
    int opcao;

    cout << "O que você deseja fazer?" << endl << endl;

    cout << "(1) Ler um arquivo" << endl
         << "(2) Imprime texto" << endl
         << "(3) Apresentar arquivo invertido" << endl
         << "(4) Procurar uma palavra no arquivo invertido" << endl
         << "(5) Comprimir arquivo" << endl
         << "(6) Sair" << endl;

    cin >> opcao;

    if (opcao < 1 || opcao > 6) {
        cout << "Opção inválida!!" << endl << endl;
        return imprimeMenu();
    }

    return opcao;
}

void System::merge(int begin, int mid, int end) {
    int leftSize, rightSize, leftCount = 0, rightCount = 0, mergedIndex = begin;
    Ocorrencia **leftList, **rightList;
    leftSize = mid - begin + 1;
    rightSize = end - mid;
    leftList = new Ocorrencia*[leftSize];
    rightList = new Ocorrencia*[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftList[i] = listaOcorrencias[begin + i];

    for (int i = 0; i < rightSize; i++)
        rightList[i] = listaOcorrencias[mid + 1 + i];

    while (leftCount < leftSize && rightCount < rightSize)
    {
        if (*leftList[leftCount]->getPalavra() <= *rightList[rightCount]->getPalavra())
            listaOcorrencias[mergedIndex] = leftList[leftCount],
            leftCount++;

        else
            listaOcorrencias[mergedIndex] = rightList[rightCount],
            rightCount++;

        mergedIndex++;
    }

    while (leftCount < leftSize)
        listaOcorrencias[mergedIndex] = leftList[leftCount],
        leftCount++,
        mergedIndex++;

    while (rightCount < rightSize)
        listaOcorrencias[mergedIndex] = rightList[rightCount],
        rightCount++,
        mergedIndex++;

    delete []rightList;
    delete []leftList;
}

void System::mergeSort(int begin, int end) {
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

void System::imprimeOcorrencia(int posPalavra, int numOcorrencia) {
    int begin, length, posOcorrencia, tamPalavra, opcao;
    char *trecho;

    posOcorrencia = (*listaOcorrencias[posPalavra]->getOcorrencias())[numOcorrencia];
    tamPalavra = listaOcorrencias[posPalavra]->getPalavra()->size();

    begin = posOcorrencia - 20;
    // protecao lado menor
    begin = begin < 0 ? 0 : begin;

    length = tamPalavra + 40;
    // protecao lado maior
    length = (length + posOcorrencia) > (texto.size() - 1) ? posOcorrencia - texto.size() - 1 : length;

    trecho = texto.substr(begin, length);
    cout << endl << trecho << endl << endl;

    cout << "Deseja ver mais uma ocorrência? 0 - Não, 1 - Sim ";
    cin >> opcao;

    delete []trecho;
    if (opcao && numOcorrencia < listaOcorrencias[posPalavra]->getOcorrencias()->getLength() - 1)
        imprimeOcorrencia(posPalavra, numOcorrencia + 1);
}

int System::lePalavra() {
    String palavra;
    int resultado;

    cout << "Qual palavra você deseja pesquisar? ";
    cin.ignore();
    cin >> palavra;

    resultado = binarySearch(&palavra, 0, listaOcorrencias.getLength() - 1);
    if (resultado == -1) {
        cout << "Palavra não encontrada, digite novamente." << endl;
        return lePalavra();
    }

    return resultado;
}

void System::comprimirArquivo() {
    // compressao iniciada e nao concluida
    Encoder compressor(&listaOcorrencias);
    //compressor.encode();
}
