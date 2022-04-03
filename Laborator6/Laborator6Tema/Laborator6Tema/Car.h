#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Weather.h"
#include <cstring>
#include <cstdio>
class Car {
  protected:
    char* numeMasina;
    float fuel_capacity;
    float fuel_consumption;
    int average_speed;//km per h
    Weather weather;
  public:
    virtual char* get_numemasina() const   = 0;
    virtual float get_fuelcapacity() const = 0;
    virtual float get_fuelconsumption() const = 0;
    virtual int get_averagespeed() const      = 0;
    virtual void setWeather(Weather weather)        = 0;
};