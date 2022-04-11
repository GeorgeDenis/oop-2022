#pragma once
#include "operatie.h"
class Adunare : public operatie {

  public:
    Adunare();
    int calculeaza(int a, int b)override;
    char* getName() override;
};
