#pragma once
#include "time.h"
#include "linked-list/includes/list.hpp"
#include "linked-list/src/list.cpp"
#include "common/includes/person.hpp"

class System
{
    public:
        System();
        ~System();
        void run();

    private:
        int option;
        LinkedList<Person *> *listaEncadeada;

        double calcRuntime(clock_t start);
        int printBasicMenu();
        int printCompleteMenu();
        void evaluateMenuOption(int option);
};
