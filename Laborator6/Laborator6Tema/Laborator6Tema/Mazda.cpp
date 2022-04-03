#include "Mazda.h"

Mazda::Mazda() {
    numeMasina = new char[6];
    strcpy(numeMasina, "Mazda");
    numeMasina[5]    = '\0';
    fuel_capacity    = 50;
    fuel_consumption = 9.5;
    average_speed    = 30; // Snow
}

char* Mazda::get_numemasina() const {
    return numeMasina;
}

float Mazda::get_fuelcapacity() const {
    return fuel_capacity;
}

float Mazda::get_fuelconsumption() const {
    return fuel_consumption;
}

int Mazda::get_averagespeed() const {
    return average_speed;
}

void Mazda::setWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 80;
    if (this->weather == Weather::Rain)
        average_speed = 30;
}
