#include "Ford.h"

Ford::Ford() {
    numeMasina = new char[5];
    strcpy(numeMasina, "Ford");
    numeMasina[4] = '\0';
    fuel_capacity = 80;
    fuel_consumption = 10.5;
    average_speed    = 25; //Snow
}

char* Ford::get_numemasina() const {
    return numeMasina;
}

float Ford::get_fuelcapacity() const {
    return fuel_consumption;
}

float Ford::get_fuelconsumption() const {
    return fuel_capacity;
}

int Ford::get_averagespeed() const {
    return average_speed;
}

void Ford::setWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 80;
    if (this->weather == Weather::Rain)
        average_speed = 35;
}
