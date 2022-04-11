#include <iostream>
#include "Adunare.h"
#include "Impartire.h"
#include "Inmultire.h"
#include "Scadere.h"
#include "operatie.h"
#include "calculator.h"
int main() {
    Calculator c;
    c += new Adunare();
    c += new Scadere();
    c += new Adunare(); // NU se mai adauga inca o operatie de adunare
    c += new Inmultire();
    c += new Impartire();
    c.Compute(20, 10);
    std::cout << "Numar operatii suportate: " << (int) c << std::endl;
     if (c["Scadere"])
        std::cout << "Operatia de scadere este suportata de calculator" << std::endl;
    c -= "Scadere";
    c -= "Impartire";
    c.Compute(15, 6);
    std::cout << "Numar operatii suportate: " << (int) c << std::endl;
}