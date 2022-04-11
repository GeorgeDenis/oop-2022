#include "Impartire.h"

Impartire::Impartire() {
        nume = new char[10];
        strcpy(nume, "Impartire");
        nume[9] = '\0';
}

int Impartire::calculeaza(int a, int b) {
    return a/b;
}

char* Impartire::getName() {
    return nume;
}
