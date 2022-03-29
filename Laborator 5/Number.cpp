#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstdio>
#include <cstring>

Number::Number() {
    value = nullptr;
    base = -1;
    nrcifre = -1;
}

Number::Number(const char* value, int base) {
    int l = strlen(value);
    this->value = new char[l];
    strcpy(this->value, value);
    this->base = base;
    this->nrcifre = l;
    this->value[l] = NULL;
}

Number::Number(int value) {
    base = 10;
    int k = 0;
    int cvalue = value;
    while (cvalue != 0) {
        k++;
        cvalue /= 10;
    }
    this->value = new char[k + 1];
    int l = 0;
    while (value > 0) {
        this->value[l] = (char)(value % 10 + '0');
        value /= 10;
        l++;
    }
    this->value[l] = '\0';
}
Number::~Number() {
    base = -1;
    nrcifre = 0;
    delete value;
}
int Number::val(char c) const {
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
char Number::reval(int num) {
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
void Number::reverse(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int Number::baza10() const {
    int len = strlen(value);
    int p = 1;
    int num = 0;
    int i;
    for (i = len - 1; i >= 0; i--) {
        if (val(value[i]) >= base) {
            return -1;
        }
        num += val(this->value[i]) * p;
        p = p * base;
    }
    return num;
}

void Number::ConvertFromBase10(int newBase, int num) {
    int index = 0;
    int cnum = num;
    nrcifre = 0;
    base = newBase;
    while (cnum > 0) {
        cnum /= 10;
        nrcifre++;
    }
    value = new char[nrcifre + 1];
    value[nrcifre] = '\0';
    while (num > 0) {
        value[index++] = reval(num % 10);
        num /= base;
    }
    value[index] = '\0';
    reverse(this->value);
}

Number& Number::operator=(int value) {
    if (base == -1)
        ConvertFromBase10(10, value);
    else
        ConvertFromBase10(base, value);
    return *this;
}

Number& Number::operator=(const Number& numar) {
    this->base = numar.base;
    this->nrcifre = numar.nrcifre;
    strcpy(this->value, numar.value);
    return (*this);
}

Number& Number::operator=(const char* value) {
    delete this->value;
    nrcifre = strlen(value);
    this->value = new char[nrcifre + 1];
    strcpy(this->value, value);
    return (*this);
}

char Number::operator[](int index) {
    return value[index];
}

void Number::SwitchBase(int newBase) {
    int num = baza10();
    delete this->value;
    ConvertFromBase10(newBase, num);
}

void Number::Print() {
    printf("%s\n", value);
}

int Number::GetDigitsCount() {
    return nrcifre;
}

int Number::GetBase() {
    return base;
}

Number operator+(const Number& numar1, const Number& numar2) {
    int baza;
    int s;
    Number numarNou;
    if (numar1.base > numar2.base)
        baza = numar1.base;
    else
        baza = numar2.base;
    numarNou.base = baza;
    int num1, num2;
    num1 = numar1.baza10();
    num2 = numar2.baza10();
    s = num1 + num2;
    numarNou.ConvertFromBase10(baza, s);
    return numarNou;
}

Number operator-(const Number& numar1, const Number& numar2) {
    int baza;
    int s;
    Number numarNou;
    if (numar1.base > numar2.base)
        baza = numar1.base;
    else
        baza = numar2.base;
    numarNou.base = baza;
    int num1 = numar1.baza10();
    int num2 = numar2.baza10();
    s = num1 - num2;
    numarNou.ConvertFromBase10(baza, s);
    return numarNou;
}

Number& operator--(Number& numar) {
    char* temp;
    temp = new char[numar.nrcifre];
    temp[numar.nrcifre - 1] = '\0';
    numar.nrcifre--;
    strcpy(temp, numar.value + 1);
    delete numar.value;
    numar.value = new char[numar.nrcifre + 1];
    numar.value[numar.nrcifre] = '\0';
    strcpy(numar.value, temp);
    return numar;
}

Number& operator--(Number& numar, int) {
    char* temp;
    temp = new char[numar.nrcifre];
    temp[numar.nrcifre - 1] = '\0';
    numar.nrcifre--;
    for (unsigned i = 0; i < numar.nrcifre; i++)
        temp[i] = numar.value[i];
    delete numar.value;
    numar.value = new char[numar.nrcifre + 1];
    numar.value[numar.nrcifre] = '\0';
    strcpy(numar.value, temp);
    return numar;
}

bool operator>(const Number& numar1, const Number& numar2) {
    int num1 = numar1.baza10();
    int num2 = numar2.baza10();
    if (num1 > num2)
        return true;
    return false;
}

bool operator<(const Number& numar1, const Number& numar2) {
    int num1 = numar1.baza10();
    int num2 = numar2.baza10();
    if (num1 < num2)
        return true;
    return false;
}

bool operator>=(const Number& numar1, const Number& numar2) {
    return !(numar1 < numar2);
}

bool operator<=(const Number& numar1, const Number& numar2) {
    return !(numar1 > numar2);
}

bool operator==(const Number& numar1, const Number& numar2) {
    return !(numar1 > numar2 || numar1 < numar2);
}

Number& operator+=(Number& numar1, const Number& numar2) {
    numar1 = numar1 + numar2;
    return numar1;
}