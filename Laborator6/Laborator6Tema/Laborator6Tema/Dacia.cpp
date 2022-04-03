#include "Dacia.h"

Dacia::Dacia() {
    numeMasina = new char[6];
    strcpy(numeMasina, "Dacia");
    numeMasina[5] = '\0';
    fuel_capacity = 50;
    fuel_consumption = 6.5;
    average_speed    = 20;//Snow
}

char* Dacia::get_numemasina() const {
    return numeMasina;
}

float Dacia::get_fuelcapacity() const {
    return fuel_capacity;
}

float Dacia::get_fuelconsumption() const {
    return fuel_consumption;
}

int Dacia::get_averagespeed() const {
    return average_speed;
}

void Dacia::setWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 60;
    if (this->weather == Weather::Rain)
        average_speed = 30;
}
