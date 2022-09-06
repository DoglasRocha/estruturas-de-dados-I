#include <string>

class Person
{
    public:
        std::string nome;
        long rg;
        Person(std::string nome_="", long rg_=0);
        ~Person();
};