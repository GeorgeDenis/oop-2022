#pragma once
#include "operatie.h"
class Inmultire : public operatie {
  public:
    Inmultire();
    int calculeaza(int a, int b) override;
    char* getName() override;
};
