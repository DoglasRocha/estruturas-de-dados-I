#include <iostream>
#include <fstream>
#include <cmath>
#include "../includes/system.hpp"
#include "../common/includes/person.hpp"
#include "../sequential-list/includes/sequential-list.hpp"
using std::cout;
using std::cin;
using std::endl;

System::System()
{
    list = new SequentialList<Person *>();
    option = -1;

    run();
}

System::~System()
{
    delete list;
}

void System::run()
{
    printCompleteMenu();
    evaluateMenuOption();

    while (option != 13)
    {
        printBasicMenu();
        evaluateMenuOption();
    }
}

double System::calcRuntime(clock_t start)
{
    double diff = ((double) clock() - (double) start) / (double) CLOCKS_PER_SEC;
    return diff;
}

void System::printBasicMenu()
{
    cout << "Digite a opção desejada:\n";
    cout << "(1) - Inserir uma pessoa no início da lista\n";
    cout << "(2) - Inserir uma pessoa no fim da lista\n";
    cout << "(3) - Inserir uma pessoa na posição N da lista\n";
    cout << "(4) - Remover uma pessoa no início da lista\n";
    cout << "(5) - Remover uma pessoa no fim da lista\n";
    cout << "(6) - Remover uma pessoa na posição N da lista\n";
    cout << "(7) - Procurar uma pessoa por RG\n";
    cout << "(8) - Ordenar a lista" << endl;
    cout << "(9) - Imprimir a lista na tela\n";
    cout << "(10) - Salvar a lista em um arquivo\n";
    cout << "(11) - Ler a lista de um arquivo\n";
    cout << "(12) - Limpar lista" << endl;
    cout << "(13) - Sair\n\n";

    cin >> option;

    if (option < 1 || option > 13)
        printBasicMenu();
}

void System::printCompleteMenu()
{
    cout << "TRABALHO 1 - LISTA DE CLIENTES\n";
    cout << "==============================\n";
    cout << "© by Doglas Rocha\n\n\n\n";

    printBasicMenu();
}

void System::evaluateMenuOption()
{
    int position, C, M;
    long rg;
    std::string filename;
    C = M = 0;

    switch (option)
    {
    case 1:
        insertIntoListManually(0, &C, &M);
        break;

    case 2:
        insertIntoListManually(-1, &C, &M);
        break;

    case 3:
        cout << "Em qual posição você deseja inserir o nó? ";
        cin >> position;
        insertIntoListManually(position, &C, &M);
        break;

    case 4:
        removeFromList(0, &C, &M);
        break;

    case 5:
        removeFromList(-1, &C, &M);
        break;

    case 6:
        cout << "De qual posição você deseja remover o nó? ";
        cin >> position;
        removeFromList(position, &C, &M);
        break;

    case 7:
        cout << "Qual RG você deseja procurar? ";
        cin >> rg;
        searchingMenu(rg, &C, &M);
        break;

    case 8:
        sortingMenu(&C, &M);
        break;

    case 9:
        for (int i = 0, l = list->getLength(); i < l; i++)
            cout << i << " - Nome: " << (*list)[i]->name << ", "
                 << "RG: " << (*list)[i]->rg << endl;
        break;

    case 10:
        cout << "Por favor, digite o nome do novo arquivo: ";
        cin >> filename;
        writeFileFromList(filename);
        break;
    
    case 11:
        cout << "Por favor, digite o nome do arquivo a ser lido: ";
        cin >> filename;
        readFileAndInsertIntoList(filename);
        break;

    case 12:
        list->clear();
        cout << "Lista limpa!" << endl;
        break;

    default:
        break;
    }
}

void System::printData(Person *person, int index, const int *C, const int *M)
{
    int pIndex, length = list->getLength();

    if (index <= 0 || length == 0)
        pIndex = 0;

    else if (index == -1 || index > length)
        pIndex = length - 1;

    else
        pIndex = index;

    if (person != nullptr)
        cout << pIndex << "- Nome: " << person->name << ", RG: " << person->rg
             << " posição: " << pIndex << ", ";
    else
        cout << "RG não encontrado, ";

    cout << "C(n): " << *C << ", M(n): " << *M << ", Runtime: " << calcRuntime(start)
         << "s \n";
}

void System::printRuntime(const int *C, const int *M) const
{
    cout << "C(n): " << *C << ", M(n): " << *M << ", Runtime: " << calcRuntime(start) << "s" << endl;
}

Person *System::createPersonManually()
{
    std::string name;
    long rg;

    cout << "Digite o nome e o RG da pessoa, separados por espaços: ";
    cin >> name >> rg;

    return new Person(name, rg);
}

Person *System::createPersonFromFile(std::string name, long rg)
{
    return new Person(name, rg);
}

void System::insertIntoListManually(int index, int *C, int *M)
{
    start = clock();

    Person *person = createPersonManually();
    list->insert(person, index, C, M);
    printData(person, index, C, M);
}

void System::removeFromList(int index, int *C, int *M)
{
    start = clock();

    Person *person = list->remove(index, C, M);
    printData(person, index, C, M);
    delete person;
}

void System::sequentialSearch(long rg, int *C, int *M)
{
    start = clock();
    int i, l;

    for (i = 0, l = list->getLength(); i < l; i++, (*C) += 2, (*M)++)
        if ((*list)[i]->rg == rg)
        {
            printData((*list)[i], i, C, M);
            return;
        }
    
    printData(nullptr, i, C, M);
}   

void System::writeFileFromList(std::string filename)
{
    std::ofstream file(filename); 
    std::string name;
    long rg;

    if (file.is_open())
    {
        for (int i = 0, l = list->getLength(); i < l; i++)
        {
            name = (*list)[i]->name;
            rg = (*list)[i]->rg;
            file << name << "," << rg << endl;
        }

        file.close();
        return;
    }

    cout << "Erro na abertura de arquivo\n";
}

void System::readFileAndInsertIntoList(std::string filename)
{
    int C = 0, M = 0;
    size_t commaPos, lineBreakPos;
    std::string line, name;
    long rg;
    Person *newPerson;
    start = clock();

    std::ifstream file(filename);

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            commaPos = line.find(',');
            lineBreakPos = line.find('\n');

            name = line.substr(0, commaPos);
            rg = std::stol(line.substr(commaPos+1, lineBreakPos));

            newPerson = createPersonFromFile(name, rg);
            list->insert(newPerson, -1, &C, &M);
        }

        file.close();
        cout << "Tempo de leitura e armazenamento do arquivo: " << calcRuntime(start) << "s\n\n";
        return;
    }

    cout << "Erro na abertura do arquivo\n";
}
