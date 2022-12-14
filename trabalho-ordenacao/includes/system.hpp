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

        static double calcRuntime(clock_t start);

        void printBasicMenu();
        void printCompleteMenu();
        void evaluateMenuOption();

        void printData(Person *person, int index, const int *C, const int *M);
        void printRuntime(const int *C, const int *M) const;

        static Person *createPersonManually();

        static Person *createPersonFromFile(std::string &name, long rg);
        void insertIntoListManually(int index, int *C, int *M);
        void removeFromList(int index, int *C, int *M);

        void writeFileFromList(std::string &filename);
        void readFileAndInsertIntoList(std::string &filename);

        void searchingMenu(long rg, int *C, int *M);
        Person *sequentialSearch(long rg, int *indexFound, int *C, int *M);
        Person *binarySearch(long rg, int left, int right, int *indexFound, int *C, int *M);

        void sortingMenu(int *C, int *M);
        void selectionSort(int *C, int *M);
        void insertionSort(int *C, int *M, int h=1);
        void bubbleSort(int *C, int *M);
        void shellSort(int *C, int *M);
        int partition(int *C, int *M, int begin, int end);
        void quickSort(int *C, int *M, int begin, int end);
        void merge(int *C, int *M, int begin, int mid, int end);
        void mergeSort(int *C, int *M, int begin, int end);
};
