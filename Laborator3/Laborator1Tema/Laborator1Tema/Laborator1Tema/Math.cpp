#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdio>
#include <string.h>
#include <stdarg.h>
int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

double Math::Add(double x, double y) {
    return x + y;
}

double Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

double Math::Mul(double x, double y) {
    return x * y;
}

double Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    int* p = &count;
    int x, s = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        x = va_arg(args, int);
        s = s + x;
    }
    va_end(args);
    return s;
}

char* Math::Add(const char* x, const char* y) {
    int lenght, lenghtX, lenghtY;
    lenghtX = strlen(x);
    lenghtY = strlen(y);
    lenght  = lenghtX;
    lenght += lenghtY;
    lenght += 1;
    char* cuvant = new char[lenght];
    for (unsigned i = 0; x[i]; i++)
        *(cuvant + i) = x[i];
    for (unsigned i = 0; y[i]; i++)
        *(cuvant + lenghtX + i) = y[i];
    *(cuvant + lenght - 1) = NULL;
    return cuvant;
}
