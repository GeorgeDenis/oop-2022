#include <iostream>
#include "Canvas.h"

int main() {
    Canvas canvas(30,30);
    //canvas.DrawCircle(5, 10, 3, '*');
    canvas.DrawRect(5, 5, 10, 10,'*');
    //canvas.SetPoint(5, 10, '%');
    canvas.Print();

}