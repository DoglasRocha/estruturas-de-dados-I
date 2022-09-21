#pragma once
#include <string>
#include <time.h>
#include "../sequential-list/includes/sequential-list.hpp"
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
        SequentialList<Person *> *list;

        double calcRuntime(clock_t start);

        void printBasicMenu();
        void printCompleteMenu();
        void evaluateMenuOption();

        void printData(Person *person, int index, int *C, int *M);

        Person *createPersonManually();

        Person *createPersonFromFile(std::string name, long rg);
        void insertIntoListManually(int index, int *C, int *M);
        void removeFromList(int index, int *C, int *M);

        void writeFileFromList(std::string filename);
        void readFileAndInsertIntoList(std::string filename);

        void searchingMenu(long rg, int *C, int *M);
        void sequentialSearch(long rg, int *C, int *M);
        void binarySearch(long rg, int *C, int *M);

        void sortingMenu(int *C, int *M);
        void selectionSort(int *C, int *M);
        void insertionSort(int *C, int *M);
        void bubbleSort(int *C, int *M);
        void shellSort(int *C, int *M);
        void quickSort(int *C, int *M);
        void mergeSort(int *C, int *M);
};
