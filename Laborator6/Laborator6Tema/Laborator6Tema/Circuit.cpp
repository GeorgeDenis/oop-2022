#include "Circuit.h"
#include <iostream>
Circuit::Circuit() {
    numarMasini = 0;
    finish      = 0;
    notFinish   = 0;
    lenght      = 0;
    weather     = Weather::Snow;
}

void Circuit::SetLength(int lenght) {
    this->lenght = lenght;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
    for (unsigned i = 0; i < numarMasini; i++)
        masini[i]->setWeather(weather);
}

void Circuit::AddCar(Car* masina) {
    masina->setWeather(this->weather);
    masini[numarMasini] = masina;
    numarMasini++;
}
void Circuit::Race() {
    for (unsigned i = 0; i < numarMasini; i++) {
        int distantaParcursa = (int) ((masini[i]->get_fuelcapacity() * 100) / masini[i]->get_fuelconsumption());
        if (distantaParcursa < lenght) {
            notFinishMasini[notFinish] = masini[i];
            notFinish++;
        } else {
            finishMasini[finish] = masini[i];
            int i                = finish;
            while (i > 0) {
                if (Timp(finishMasini[i]->get_averagespeed()) < Timp(finishMasini[i - 1]->get_averagespeed())) {
                    Car* temp           = finishMasini[i];
                    finishMasini[i]     = finishMasini[i - 1];
                    finishMasini[i - 1] = temp;
                } else
                    break;
                i--;
            }
            finish++;
        }
    }
}

double Circuit::Timp(int viteza) const {
    return (double) (lenght * 1.00 / viteza); // viteza= distanta / timp => timp = distanta / viteza
}

void Circuit::ShowFinalRanks() {
    if (finish != 0) {
        for (unsigned i = 0; i < finish; i++) {
            double time         = Timp(finishMasini[i]->get_averagespeed());
            int timp_in_secunde = (int) (time * 3600);
            int ore             = (timp_in_secunde / 3600);
            timp_in_secunde     = timp_in_secunde % 3600;
            int minute          = timp_in_secunde / 60;
            timp_in_secunde     = timp_in_secunde % 60;
            int secunde         = timp_in_secunde;
            printf("%s | %02dh|%02dm|%02ds \n", finishMasini[i]->get_numemasina(), ore, minute, secunde);
        }
    } else
        printf("Nicio masina nu a terminat!!");
}

void Circuit::ShowWhoDidNotFinish() {
    if (notFinish !=0) {
        for (unsigned i = 0; i < notFinish; i++)
            printf("%s nu a terminat cursa \n", notFinishMasini[i]->get_numemasina());
    } else
        printf("Toate masinile au terminat cursa!");
}
