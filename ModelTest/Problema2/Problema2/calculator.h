#pragma once
#include "Adunare.h"
#include "Impartire.h"
#include "Inmultire.h"
#include "Scadere.h"
#include "operatie.h"
#include <cstdio>
class Calculator {
  private:
    operatie* operatii[4];
    int numar_operatii;

  public:
    Calculator();
    void Compute(int a,int b);
    void operator+=(operatie* op);
    void operator-=(const char* op);
    operator int();
    bool operator[](const char* operatie);
};
