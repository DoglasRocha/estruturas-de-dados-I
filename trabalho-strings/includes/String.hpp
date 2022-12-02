#pragma once
#include <string>

class String {
    private:
        int length;
        char *cArray;

    public:
        String();
        String(const char *texto);
        ~String();
        void operator=(const std::string& texto);
        const bool operator==(String& texto);
        const bool operator>(String& texto);
        const bool operator<(String& texto);
        void operator+=(const char caracter);
        const char operator[](const int index);
        String substr(const int begin, const int length);
        const int size() const;
        friend std::ostream& operator<<(std::ostream& os, String &texto);
        friend void operator>>(std::istream& is, String &texto);
};