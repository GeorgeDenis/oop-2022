#include "Scadere.h"

Scadere::Scadere() {
    nume = new char[8];
    strcpy(nume, "Scadere");
    nume[7] = '\0';
}

int Scadere::calculeaza(int a, int b) {
    return a-b;
}

char* Scadere::getName() {
    return nume;
}
