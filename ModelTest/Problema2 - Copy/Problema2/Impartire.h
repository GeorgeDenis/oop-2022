#pragma once
#include "operatie.h"
class Impartire : public operatie {
  public:
    Impartire();
    int calculeaza(int a, int b) override;
    char* getName() override;
};
