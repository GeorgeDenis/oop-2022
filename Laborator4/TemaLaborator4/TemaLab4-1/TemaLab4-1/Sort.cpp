#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <stdarg.h>
Sort::Sort(unsigned lenght, int min, int max) {
    this->lista  = new int[lenght];
    this->lenght = lenght;
    for (unsigned i = 0; i < lenght; i++) {
        this->lista[i] = rand() % max + min;
    }
}

Sort::Sort() : lista(new int[8]{ 9, 11, 2, 5, 4, 1, 2, 8 }) {
    this->lenght = 5;
}

Sort::Sort(unsigned lenght, ...) {
    va_list args;
    va_start(args, lenght);
    lista        = new int[lenght];
    this->lenght = lenght;
    for (unsigned i = 0; i < this->lenght; ++i) {
        this->lista[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(int* vector, unsigned lenght) {
    lista        = new int[lenght];
    this->lenght = lenght;
    for (unsigned i = 0; i < lenght; i++)
        lista[i] = vector[i];
}

Sort::Sort(const char* numere) {
    int num = 1;
    for (int i = 0; i < strlen(numere); ++i)
        if (numere[i] == ',')
            ++num;
    this->lenght = num;
    lista        = new int[num];
    int index    = 0;
    char* sir    = new char[(strlen(numere) + 1) * sizeof(char)];
    strcpy(sir, numere);
    char* p = strtok(sir, ",");
    while (p != nullptr) {
        int numar    = atoi(p);
        lista[index] = numar;
        index++;
        p = strtok(nullptr, ",");
    }
    delete[] sir;
}

void Sort::InsertSort(bool ascendent) {
    int i, temp, j;
    for (i = 1; i < lenght; i++) {
        temp = lista[i];
        j    = i - 1;
        while ((j >= 0) && (lista[j] > temp)) {
            lista[j + 1] = lista[j];
            j--;
        }
        if (lista[j + 1] != temp)
            lista[j + 1] = temp;
    }
}
int Sort::partitioneaza(int* lista, int p, int q) {
    int pivot = lista[q];
    int i     = p - 1;
    for (int j = p; j < q; j++)
        if (lista[j] < pivot) {
            i++;
            std::swap(lista[i], lista[j]);
        }
    std::swap(lista[i+1], lista[q]);
    return (i + 1);
}

void Sort::QuickSort(bool ascendent) {
    helper(lista, 0, this->lenght - 1);
}
void Sort::helper(int* lista, int p, int q) {
    while (p < q) {
        int temp = partitioneaza(lista, p, q);
        helper(lista, p, temp-1);
        helper(lista, temp + 1, q);
    }
}

void Sort::BubbleSort(bool ascendent) {
    int ultim = lenght - 1;
    int n1;
    int i;
    while (ultim > 0) {
        n1    = ultim - 1;
        ultim = 0;
        for (i = 0; i < n1; i++)
            if (lista[i] > lista[i + 1]) {
                std::swap(lista[i], lista[i + 1]);
                ultim = i;
            }
    }
}

void Sort::Print() {
    for (unsigned i = 0; i < lenght; i++)
        printf("%d ", lista[i]);
}

int Sort::GetElementsCount() {
    if (lenght > 0)
        return lenght;
    else
        return -1;
}

int Sort::GetElementFromIndex(int index) {
    if (index < lenght) {
        int x = lista[index];
        return x;
    } else
        return -1;
}