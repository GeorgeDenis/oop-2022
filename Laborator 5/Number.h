#pragma once
class Number

{
    // add data members
    char* value;
    int base;
    int nrcifre;

public:
    Number();
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int value);

    ~Number();

    int val(char c)const;
    char reval(int num);
    void reverse(char* str);
    int baza10()const;
    void ConvertFromBase10(int base, int num);
    // add operators and copy/move constructor

    friend Number operator+(const Number& numar1, const Number& numar2);
    friend Number operator-(const Number& numar1, const Number& numar2);

    friend Number& operator--(Number& numar);
    friend Number& operator--(Number& numar, int);

    Number& operator=(int value);
    Number& operator=(const Number& numar);
    Number& operator=(const char* value);




    friend bool operator>(const Number& numar1, const Number& numar2);
    friend bool operator<(const Number& numar1, const Number& numar2);
    friend bool operator>=(const Number& numar1, const Number& numar2);
    friend bool operator<=(const Number& numar1, const Number& numar2);
    friend bool operator==(const Number& numar1, const Number& numar2);

    friend Number& operator+=(Number& numar1, const Number& numar2);
    char operator[](int index);


    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number

    int GetBase(); // returns the current base


};