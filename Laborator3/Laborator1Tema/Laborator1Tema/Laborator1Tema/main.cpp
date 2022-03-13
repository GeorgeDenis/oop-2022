#include <iostream>
#include "Math.h";

int main() {
    Math mate;
    printf("%d\n", mate.Add(5, 6));
    printf("%d\n", mate.Add(5, 6, 7));
    printf("%f\n", mate.Add(5.2, 6.2));
    printf("%f\n", mate.Add(5.2, 6.2, 7.5));
    printf("%d\n", mate.Mul(5, 6));
    printf("%d\n", mate.Mul(5, 6, 7));
    printf("%f\n", mate.Mul(5.2, 6.2));
    printf("%f\n", mate.Mul(5.2, 6.2, 7.2));
    printf("%d \n", mate.Add(6, 3, 8, 2, 1, 5,8));
    printf("%s \n", mate.Add("denis", "B4"));
    return 0;
}