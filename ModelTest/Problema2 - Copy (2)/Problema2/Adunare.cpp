#include "Adunare.h"

Adunare::Adunare() {
    nume = new char[8];
    strcpy(nume, "Adunare");
    nume[7] = '\0';
}

int Adunare::calculeaza(int a, int b) {
    return a + b;
}

char* Adunare::getName() {
    return nume;
}
