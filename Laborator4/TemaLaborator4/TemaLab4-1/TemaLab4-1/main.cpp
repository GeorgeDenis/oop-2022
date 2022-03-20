#pragma once
#include <iostream>
#include "Sort.h"
int main() {
    int v[] = { 5, 1, 2, 4, 5 };
    Sort l(10, 1, 10);
    l.Print();
    printf("\n");
    Sort l1;
    l1.Print();
    printf("\n");
    Sort l2(5, 1, 2, 3, 4, 5);
    l2.Print();
    printf("\n");
    Sort l3(v, 5);
    l3.Print();
    printf("\n");
    Sort l4("10,40,100,5,70");
    l4.Print();
    printf("\n");


    l2.BubbleSort();
    l2.Print();
    printf("\n");

    l4.InsertSort();
    l4.Print();
    printf("\n");

    std::cout << std::endl << l.GetElementFromIndex(1);
    std::cout << std::endl << l2.GetElementsCount();
    std::cout << std::endl << l3.GetElementFromIndex(2);

    l1.QuickSort();
    l1.Print();
    printf("\n");
}