#include "../includes/frequency.hpp"

Frequency::Frequency() {
    palavra = nullptr;
    freq = 0;
}

Frequency::~Frequency() {
    delete palavra;
}

void Frequency::setPalavra(String *palavra) {
    this->palavra = new String();
    *this->palavra = *palavra;
}

String *Frequency::getPalavra() const {
    return palavra;
}

void Frequency::setFreq(int freq) {
    this->freq = freq;
}

int Frequency::getFreq() const {
    return freq;
}
