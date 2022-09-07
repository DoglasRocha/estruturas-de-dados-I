#include <iostream>
#include <fstream>
#include "../includes/system.hpp"
#include "../common/includes/person.hpp"
using std::cout;
using std::cin;

System::System()
{
    linkedList = new LinkedList<Person *>();
    option = -1;

    run();
}

System::~System()
{
    delete linkedList;
}

void System::run()
{
    printCompleteMenu();
    while (option != 11)
    {
        evaluateMenuOption();
        printBasicMenu();
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
    cout << "(1) - Inserir um nó no início da lista\n";
    cout << "(2) - Inserir um nó no fim da lista\n";
    cout << "(3) - Inserir um nó na posição N da lista\n";
    cout << "(4) - Remover um nó no início da lista\n";
    cout << "(5) - Remover um nó no fim da lista\n";
    cout << "(6) - Remover um nó na posição N da lista\n";
    cout << "(7) - Procurar um nó por RG\n";
    cout << "(8) - Imprimir a lista na tela\n";
    cout << "(9) - Salvar a lista em um arquivo\n";
    cout << "(10) - Ler a lista de um arquivo\n";
    cout << "(11) - Sair\n\n";

    cin >> option;

    if (option < 1 || option > 11)
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
        searchInList(rg, &C, &M);
        break;

    case 8:
        for (int i = 0; i < linkedList->length; i++)
            cout << "Nome: " << linkedList->getAt(i, &C, &M)->name << ", "
                 << "RG: " << linkedList->getAt(i, &C, &M)->rg << ", "
                 << "posição: " << i << "\n";
        break;

    case 9:
        cout << "Por favor, digite o nome do novo arquivo: ";
        cin >> filename;
        writeFileFromList(filename);
        break;
    
    case 10:
        cout << "Por favor, digite o nome do arquivo a ser lido: ";
        scanf(" %s", filename);
        readFileAndInsertIntoList(filename);
        break;

    default:
        break;
    }
}

void System::printData(Person *person, int index, int *C, int *M)
{
    int pIndex;

    if (index == 0)
        pIndex = 0;

    else if (index == -1 || index > linkedList->length)
        pIndex = linkedList->length - 1;

    else
        pIndex = index;

    if (person != nullptr)
        cout << "Nome: " << person->name << ", RG: " << person->rg
             << " posição: " << pIndex << " ";
    else
        cout <<"RG não encontrado, ";

    cout << "C: " << *C << ", M: " << *M << ", Runtime: " << calcRuntime(start) 
         << "ms \n";
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
    linkedList->insert(person, index, C, M);
    printData(person, index, C, M);
}

void System::insertIntoListFromFile(std::string name, long rg)
{
    int C, M;

    Person *person = createPersonFromFile(name, rg);
    linkedList->insert(person, -1, &C, &M);
}

void System::removeFromList(int index, int *C, int *M)
{
    start = clock();

    Person *person = linkedList->remove(index, C, M);
    printData(person, index, C, M);
    delete person;
}

void System::searchInList(long rg, int *C, int *M)
{
    start = clock();
    int i;

    for (i = 0;
         i < linkedList->length && linkedList->getAt(i, C, M)->rg != rg; 
         i++, (*C)++, (*M) += 2);

    printData(linkedList->getAt(i, C, M), i, C, M);
}   

void System::writeFileFromList(std::string filename)
{
    int C = 0, M = 0;
    std::ofstream file(filename); 
    std::string name;
    long rg;

    if (file.is_open())
    {
        for (int i = 0; i < linkedList->length; i++)
        {
            name = linkedList->getAt(i, &C, &M)->name;
            rg = linkedList->getAt(i, &C, &M)->rg;
            file << name << "," << rg << "\n";
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
    std::ifstream file(filename);
    std::string line, name;
    long rg;
    Person *newPerson;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            commaPos = line.find(',');
            lineBreakPos = line.find('\n');

            name = line.substr(0, commaPos);
            rg = std::stol(line.substr(commaPos+1, lineBreakPos));

            newPerson = createPersonFromFile(name, rg);
            linkedList->insert(newPerson, -1, &C, &M);
        }

        file.close();
        return;
    }

    cout << "Erro na abertura do arquivo\n";
}
