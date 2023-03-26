#include "Sort.h"
#include <iostream>

int main() {
    Sort a(10, 1, 100);
    a.InsertSort();
    a.Print();

    Sort b;
    b.Print();

    int v[] = { 1, 2, 3, 4, 5 };
    Sort c(v, 5);
    c.Print();

    Sort d(2, 6, 3, 5, 8, 1, 9);
    d.BubbleSort();
    d.Print();

    char sir[] = "1,6,8,12,15";
    Sort e(sir);
    e.QuickSort();
    e.Print();

    return 0;
}