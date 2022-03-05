#include <iostream>
#include "NumberList.h"
int main() {
    NumberList lista;
    lista.Init();
    lista.Add(5);
    lista.Add(10);
    lista.Add(2);
    lista.Add(3);
    lista.Add(4);
    lista.Add(11);
    lista.Add(13);
    lista.Add(14);
    lista.Add(9);
    lista.Add(12);
    lista.Print();
    printf("\n");
    lista.Sort();
    lista.Print();
    printf("\n");
    lista.Add(12);
    lista.Print();


}