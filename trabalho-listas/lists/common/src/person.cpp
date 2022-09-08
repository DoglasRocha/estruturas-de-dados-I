#include <string>
#include  "../includes/person.hpp"

Person::Person(std::string name_, long rg_)
{
    name = name_;
    rg = rg_;
}

Person::~Person() {}