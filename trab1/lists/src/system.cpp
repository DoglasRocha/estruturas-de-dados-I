#include "../includes/system.hpp"
#include "../common/includes/person.hpp"

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
    option = printCompleteMenu();
    while (option != 11)
    {
        evaluateMenuOption(option);
        option = printBasicMenu();
    }
}

double System::calcRuntime(clock_t start)
{

}

int System::printBasicMenu()
{

}

int System::printCompleteMenu()
{

}

void System::evaluateMenuOption(int option)
{

}

void System::printData(Person *person, int index, int *C, int *M)
{

}

Person *System::createPersonFromFile(std::string name, long rg)
{

}

void System::insertIntoListManually(int index, int *C, int *M)
{

}

void System::insertIntoListFromFile(std::string name, long rg)
{

}

void System::removeFromList(int index, int *C, int *M)
{

}

void System::searchInList(long rg, int *C, int *M)
{

}
