#pragma once
#include "operatie.h"
class Scadere : public operatie {
  public:
    Scadere();
    int calculeaza(int a, int b) override;
    char* getName() override;
};
