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
    cout << "(7) - Procurar um nó por RG\n";
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
            cout << "Nome: " << (*list)[i]->name << ", "
                 << "RG: " << (*list)[i]->rg << ", "
                 << "posição: " << i << "\n";
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
        cout << "Nome: " << person->name << ", RG: " << person->rg
             << " posição: " << pIndex << ", ";
    else
        cout <<"RG não encontrado, ";

    cout << "C: " << *C << ", M: " << *M << ", Runtime: " << calcRuntime(start) 
         << "s \n";
}

void System::printRuntime(const int *C, const int *M) const
{
    cout << "C: " << *C << ", M: " << *M << ", Runtime: " << calcRuntime(start) << "s" << endl;
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

void System::searchingMenu(long rg, int *C, int *M)
{
    cout << "Qual busca você deseja utilizar?" << endl
         << "(1) Sequencial" << endl
         << "(2) Binária" << endl;
    cin >> option;

    if (option != 1 && option != 2)
        searchingMenu(rg, C, M);

    if (option == 1)
        sequentialSearch(rg, C, M);

    else
        binarySearch(rg, C, M);
}

void System::binarySearch(long rg, int *C, int *M)
{
    int currentPos = (int) round((list->getLength() - 1) / 2.0),
        increase = currentPos;
    (*M) += 2;
    start = clock();

    do
    {
        increase = increase == (int) round(increase / 2.0) ? 0 : (int) round(increase / 2.0);
        (*C)++, (*M)++;

        if ((*list)[currentPos]->rg > rg)
        {
            currentPos += -increase;
            (*M)++;
            (*C)++;
            continue;
        }
        else if ((*list)[currentPos]->rg < rg)
        {
            currentPos += increase;
            (*M)++;
            (*C) += 2;
            continue;
        }

        (*C) += 2;
    }
    while ((*list)[currentPos]->rg != rg && increase > 0);

    if ((*list)[currentPos]->rg == rg)
        printData((*list)[currentPos], currentPos, C, M);
    else
        printData(nullptr, 0, C, M);
}

void System::sortingMenu(int *C, int *M)
{
    cout << "Qual tipo de ordenação você quer utilizar?" << endl
         << "(1) Selection Sort" << endl
         << "(2) Insertion Sort" << endl
         << "(3) Bubble Sort" << endl
         << "(4) Shell Sort" << endl
         << "(5) Quick Sort" << endl
         << "(6) Merge Sort" << endl;

    cin >> option;

    if (option < 1 || option > 6)
    {
        cout << "Opção inválida!!" << endl;
        sortingMenu(C, M);
    }
    (*C)++;

    switch (option) {
        case 1:
            (*C)++;
            selectionSort(C, M);
            break;

        case 2:
            (*C) += 2;
            insertionSort(C, M);
            break;

        case 3:
            (*C) += 3;
            bubbleSort(C, M);
            break;

        case 4:
            (*C) += 4;
            shellSort(C, M);
            break;

        case 5:
            (*C) += 5;
            quickSort(C, M);
            break;

        case 6:
            (*C) += 6;
            mergeSort(C, M);
            break;
    }
}

void System::selectionSort(int *C, int *M)
{
    int i, j, l, smallerPos;
    l = list->getLength();
    start = clock();

    for (i = 0; i < l; i++, (*C)++, (*M)++)
    {
        for (j = i; j < l; j++, (*C)++, (*M)++)
        {
            (*C)++;
            if (j == i || (*list)[j]->rg < (*list)[smallerPos]->rg)
                smallerPos = j,
                (*M)++;
        }

        list->swap(i, smallerPos, C, M);
    }

    printRuntime(C, M);
}

void System::insertionSort(int *C, int *M)
{
    int i, j, l = list->getLength();
    Person *current;
    start = clock();

    for (i = 1; i < l; i++, (*C)++, (*M)++)
    {
        current = (*list)[i];
        j = i - 1;
        while (j >= 0 && current->rg < (*list)[j]->rg)
        {
            (*C)++, (*M)++;
            (*list)[j + 1] = (*list)[j];
            j--;
        }
        (*C)++, (*M)++;
        (*list)[j + 1] = current;
    }
    printRuntime(C, M);
}

void System::bubbleSort(int *C, int *M)
{
    int moves = -1;

    while (moves != 0)
    {
        moves = 0;
        for (int i = 1, l = list->getLength(); i < l; i++, (*C) += 2, (*M)++)
        {
            if ((*list)[i]->rg < (*list)[i - 1]->rg)
                list->swap(i - 1, i, C, M),
                moves++;
        }
    }

    printRuntime(C, M);
}

void System::shellSort(int *C, int *M)
{
    int i, j, l = list->getLength(), h;
    Person *current;
    start = clock();

    for (h = l / 2; h > 0; h /= 2)
    {
        for (i = h; i < l; i++, (*C)++, (*M)++)
        {
            current = (*list)[i];
            for (j = i; j >= h && (*list)[j - h]->rg > current->rg; j -= h, (*C)++, (*M)++)
            {
                (*list)[j] = (*list)[j - h];
            }
            (*list)[j] = current;
            (*M)++;
        }
    }

    printRuntime(C, M);
}

void System::quickSort(int *C, int *M, int begin, int end)
{
    int i, j;
    if (end == -1)
        end = list->getLength() - 1;
    i = begin, j = end;

    Person *key = (*list)[(begin + end) / 2];

    do
    {
        (*C)++, (*M)++;
        while ((*list)[i]->rg < key->rg)
            i++, (*C)++, (*M)++;

        while ((*list)[j]->rg > key->rg)
            j--, (*C)++, (*M)++;

        (*C)++;
        if (i <= j)
        {
            list->swap(i, j, C, M);
            i++, j--;
        }
    }
    while (i > j);
    if (j > begin) quickSort(C, M, begin, j);
    (*C)++;
    if (i < end) quickSort(C, M, i, end);
    (*C)++;
}

void System::mergeSort(int *C, int *M)
{

}
