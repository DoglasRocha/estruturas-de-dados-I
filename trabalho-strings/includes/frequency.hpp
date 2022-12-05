#pragma once
#include "String.hpp"

class Frequency {
    private:
        String *palavra;
        int freq;

    public:
        Frequency();
        ~Frequency();
        void setPalavra(String *palavra);
        String *getPalavra() const;
        void setFreq(int freq);
        int getFreq() const;
};