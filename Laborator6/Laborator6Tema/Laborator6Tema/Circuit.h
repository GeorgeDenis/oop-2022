#pragma once
#include "Car.h"
#include "Toyota.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Weather.h"
class Circuit {

	Car* masini[20];
    Car* finishMasini[20];
    Car* notFinishMasini[20];
    int numarMasini;
    int finish;
    int notFinish;
    int lenght;
    Weather weather;

  public:
    Circuit();
    void SetLength(int lenght);
    void SetWeather(Weather weather);
    void AddCar(Car* masina);
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
    void Race();
    double Timp(int viteza) const;
};