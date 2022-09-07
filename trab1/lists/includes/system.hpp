#pragma once
#include <string>
#include <time.h>
#include "../linked-list/includes/list.hpp"
#include "../linked-list/src/list.cpp"
#include "../sequential-list/includes/list.hpp"
#include "../sequential-list/src/list.cpp"
#include "../common/includes/person.hpp"

class System
{
    public:
        System();
        ~System();
        void run();
    
    private:
        int option;
        clock_t start;
        SequentialList<Person *> *linkedList;

        double calcRuntime(clock_t start);
        void printBasicMenu();
        void printCompleteMenu();
        void evaluateMenuOption();
        void printData(Person *person, int index, int *C, int *M);
        Person *createPersonManually();
        Person *createPersonFromFile(std::string name, long rg);
        void insertIntoListManually(int index, int *C, int *M);
        void insertIntoListFromFile(std::string name, long rg);
        void removeFromList(int index, int *C, int *M);
        void searchInList(long rg, int *C, int *M);
        void writeFileFromList(std::string filename);
        void readFileAndInsertIntoList(std::string filename);
};
