#include "Inmultire.h"

Inmultire::Inmultire() {
    nume = new char[10];
    strcpy(nume, "Inmultire");
    nume[9] = '\0';
}

int Inmultire::calculeaza(int a, int b) {
    return a*b;
}

char* Inmultire::getName() {
    return nume;
}
