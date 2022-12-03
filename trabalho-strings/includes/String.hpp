#pragma once
#include <string>

class String {
    private:
        int length;
        char *cArray = nullptr;
        void limpaString();

    public:
        String();
        String(const char *texto);
        ~String();
        void operator=(const std::string& texto);
        void operator=(String &texto);
        void operator=(const char *texto);
        const bool operator==(String& texto);
        const bool operator>(String& texto);
        const bool operator<(String& texto);
        const bool operator<=(String& texto);
        void operator+=(const char caracter);
        char &operator[](const int index);
        char *substr(const int begin, const int length_);
        const int size() const;
        friend std::ostream& operator<<(std::ostream& os, String &texto);
        friend void operator>>(std::istream& is, String &texto);
};