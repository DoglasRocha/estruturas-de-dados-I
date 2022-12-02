#include "../includes/String.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

String::String() {
    cArray = (char *) malloc(sizeof(char) * 2);
    length = 0; 
}

String::String(const char *texto) {
    int tamTexto = strlen(texto);
    length = tamTexto;

    cArray = (char *) malloc(sizeof(char) * tamTexto);

    for (int i = 0; i < tamTexto; i++)
        cArray[i] = texto[i];
}

String::~String() {
    free(cArray);
    length = 0;
}

void String::operator=(const std::string& texto) {
    int tamTexto = texto.size();
    length = tamTexto;

    free(cArray);
    cArray = (char *) malloc(sizeof(char) * tamTexto);

    for (int i = 0; i < tamTexto; i++)
        cArray[i] = texto[i];
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

    if (length > tamTexto)
        return true;

    return false;
}

const bool String::operator<(String& texto) {
    int tamTexto = texto.size(), i;

    for (i = 0; i < length && i < tamTexto; i++)
        if (cArray[i] > texto[i])
            return false;

    if (length >= tamTexto)
        return false;

    return true;
}

void String::operator+=(const char caracter) {
    cArray = (char *) realloc(cArray, sizeof(char) * (length + 1));
    cArray[length] = caracter;
    length++;
}

const char String::operator[](const int index) {
    int position;
    if (index < 0) 
        position = 0;
    else if (index >= length)
        position = length - 1;
    else
        position = index;

    return cArray[position];
}

String String::substr(const int begin, const int length) {
    String retString;

    for (int i = begin; i < (begin + length); i++)
        retString += cArray[i];

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
