#pragma once
#include <string>
#include <time.h>
#include "list.hpp"
#include "../linked-list/includes/linked-list.hpp"
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
        List<Person *> *list;

        double calcRuntime(clock_t start);
        void printBasicMenu();
        void selectListType();
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
