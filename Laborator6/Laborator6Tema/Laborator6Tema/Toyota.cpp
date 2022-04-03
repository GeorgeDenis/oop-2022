#include "Toyota.h"

Toyota::Toyota() {
    numeMasina = new char[7];
    numeMasina[6] = '\0';
    strcpy(numeMasina, "Toyota");
    fuel_capacity    = 90;
    fuel_consumption = 8.5;
    average_speed    = 30; // Snow
}

char* Toyota::get_numemasina() const {
    return numeMasina;
}

float Toyota::get_fuelcapacity() const {
    return fuel_capacity;
}

float Toyota::get_fuelconsumption() const {
    return fuel_consumption;
}

int Toyota::get_averagespeed() const {
    return average_speed;
}

void Toyota::setWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 85;
    if (this->weather == Weather::Rain)
        average_speed = 40;
}
