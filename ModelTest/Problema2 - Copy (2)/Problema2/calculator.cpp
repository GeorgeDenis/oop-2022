#include "calculator.h"

Calculator::Calculator() {
    numar_operatii = 0;
}

void Calculator::Compute(int a, int b) {
    for (unsigned i = 0; i < numar_operatii; i++) {
        printf("%s(%d,%d) = %d\n", operatii[i]->getName(), a, b, operatii[i]->calculeaza(a, b));
    }
}

void Calculator::operator+=(operatie* op) {
    int ok = 1;
    for (unsigned i = 0; i < numar_operatii; i++)
        if (strcmp(op->getName(), operatii[i]->getName()) == 0)
            ok = 0;
    if (ok) {
        operatii[numar_operatii] = op;
        numar_operatii++;
    }
}

void Calculator::operator-=(const char* op) {
    if (numar_operatii > 0) {
        for (unsigned i = 0; i < numar_operatii; i++)
            if (strcmp(op, operatii[i]->getName()) == 0) {
                for (unsigned j = i; j < numar_operatii - 1; j++)
                    operatii[j] = operatii[j + 1];
                numar_operatii--;
            }
    }
}

Calculator::operator int() {
    return numar_operatii;
}

bool Calculator::operator[](const char* operatie) {
    for (unsigned i=0;i<numar_operatii;i++)
        if (strcmp(operatie, operatii[i]->getName())==0)
            return true;
    return false;

}
