#pragma once
#include <string>

class Person
{
    public:
        std::string name;
        long rg;
        Person(std::string name_="", long rg_=0);
        ~Person();
};