#include "../includes/String.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

void String::limpaString() {
    if (cArray != nullptr)
        delete[] cArray,
        cArray = nullptr;

    length = 0;
}

String::String() {
    cArray = new char[1];
    length = 0; 
}

String::String(const char *texto) {
    int tamTexto = strlen(texto);
    length = tamTexto;

    cArray = new char[tamTexto + 1];

    for (int i = 0; i < tamTexto; i++)
        cArray[i] = texto[i];

    cArray[tamTexto] = '\0';
}

String::~String() {
    limpaString();
}

void String::operator=(const std::string& texto) {
    int tamTexto = texto.size();

    limpaString();
    length = tamTexto;
    cArray = new char[tamTexto + 1];

    for (int i = 0; i < tamTexto; i++)
        cArray[i] = texto[i];

    cArray[tamTexto] = '\0';
}

void String::operator=(String &texto) {
    int tamTexto = texto.size();
    limpaString();
    
    length = tamTexto;
    cArray = new char[tamTexto + 1];

    for (int i = 0; i < tamTexto; i++)
        cArray[i] = texto[i];

    cArray[tamTexto] = '\0';
}

void String::operator=(const char *texto) {
    int tamTexto = strlen(texto);
    limpaString();

    length = tamTexto;
    cArray = new char[tamTexto + 1];

    for (int i = 0; i < tamTexto; i++)
        cArray[i] = texto[i];

    cArray[tamTexto] = '\0';
}

const bool String::operator==(String& texto) {
    int tamTexto = texto.size(), i;

    for (i = 0; i < length && i < tamTexto; i++)
        if (cArray[i] != texto[i])
            return false;

    return i < tamTexto || i < length ? false : true;
}

const bool String::operator>(String& texto) {
    int tamTexto = texto.size(), i;

    for (i = 0; i < length && i < tamTexto; i++)
        if (cArray[i] < texto[i])
            return false;
        else if (cArray[i] > texto[i])
            return true;

    if (length > tamTexto)
        return true;

    return false;
}

const bool String::operator<(String& texto) {
    int tamTexto = texto.size(), i;

    for (i = 0; i < length && i < tamTexto; i++)
        if (cArray[i] > texto[i])
            return false;
        else if (cArray[i] < texto[i])
            return true;

    if (length >= tamTexto)
        return false;

    return true;
}

const bool String::operator<=(String& texto) {
    int tamTexto = texto.size(), i;

    for (i = 0; i < length && i < tamTexto; i++)
        if (cArray[i] > texto[i])
            return false;
        else if (cArray[i] < texto[i])
            return true;

    if (length > tamTexto)
        return false;

    return true;
}

void String::operator+=(const char caracter) {
    char *stringAntiga = cArray;
    cArray = new char[length + 2];

    for (int i = 0; i < length; i++)
        cArray[i] = stringAntiga[i];

    delete stringAntiga;
    cArray[length] = caracter;
    cArray[length + 1] = '\0';
    length++;
}

char &String::operator[](const int index) {
    int position;
    if (index < 0) 
        position = 0;
    else if (index >= length)
        position = length - 1;
    else
        position = index;

    return cArray[position];
}

char *String::substr(const int begin, const int length_) {
    char *retString;
    int i, j;

    retString = new char[length_ + 1];
    for (i = begin, j= 0; i < (begin + length_); i++, j++)
        retString[j] = cArray[i];

    retString[j] ='\0';
    return retString;
}

const int String::size() const {
    return length;
}

std::ostream& operator<<(std::ostream& os, String &texto) {
    os << texto.cArray;
    return os;
}

void operator>>(std::istream& is, String &texto) {
    std::string receiver;
    std::getline(is, receiver);

    texto = receiver;
}
