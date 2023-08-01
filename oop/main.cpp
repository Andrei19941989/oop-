//Добавьте в класс String реализацию конструктора копирования. Инвариант класса остается тем же (в size хранится размер строки без завершающего 0 символа, str указывает на C-style строку, т. е. с завершающим нулевым символом).
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    String(const char *str = "");
    String(size_t n, char c);
    ~String();


    String(const String &other)
            : size(other.size) {
        str = new char[other.size + 1];
        strcpy(str, other.str);
    }


    void append(const String &other);

    size_t size;
    char *str;
};
