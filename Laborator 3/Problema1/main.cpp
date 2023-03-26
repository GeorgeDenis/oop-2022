#include <iostream>
#include "Math.h"

void Exemple() {
    //AM MODIFICAT AICIgi
    int a = 4,b = 8, c = 16;
    double A = 4.52, B = 7.383, C = 22.76;
    int n = 5, la = 42, lb = 9, lc = 32, ld = 58, le = 142;
    char s[] = "ana", t[] = " are";
    Math math;
    std::cout << math.Add(a, b) << '\n';
    std::cout << math.Add(a, b, c) << '\n';
    std::cout << math.Add(A, B) << '\n';
    std::cout << math.Add(A, B, C) << '\n';
    std::cout << math.Mul(a, b) << '\n';
    std::cout << math.Mul(a, b, c) << '\n';
    std::cout << math.Mul(A, B) << '\n';
    std::cout << math.Mul(A, B, C) << '\n';
    std::cout << math.Add(n, la, lb, lc, ld, le) << '\n';
    std::cout << math.Add(s, t);
}

int main() {
    Exemple();
    return 0;
}