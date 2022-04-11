#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
class operatie {
  protected:
    char* nume;

  public:
    virtual int calculeaza(int a, int b) = 0;
    virtual char* getName()              = 0;
};