#include "Mercedes.h"

Mercedes::Mercedes() {
    numeMasina = new char[9];
    strcpy(numeMasina, "Mercedes");
    numeMasina[8]    = '\0';
    fuel_capacity    = 90;
    fuel_consumption = 15.5;
    average_speed    = 40; // Snow
}

char* Mercedes::get_numemasina() const {
    return numeMasina;
}

float Mercedes::get_fuelcapacity() const {
    return fuel_capacity;
}

float Mercedes::get_fuelconsumption() const {
    return fuel_consumption;
}

int Mercedes::get_averagespeed() const {
    return average_speed;
}

void Mercedes::setWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 100;
    if (this->weather == Weather::Rain)
        average_speed = 50;
}
