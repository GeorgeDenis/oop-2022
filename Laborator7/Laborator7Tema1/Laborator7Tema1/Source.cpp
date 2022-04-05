#include <iostream>
#include <stdio.h>

double operator"" _Kelvin(unsigned long long x) {
    return (double) ((x - 273.15));
}

double operator"" _Fahrenheit(unsigned long long x) {
    return (double) ((x - 32) / 1.8);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    printf("%f\n", a);
    printf("%f\n", b);

    return 0;
}