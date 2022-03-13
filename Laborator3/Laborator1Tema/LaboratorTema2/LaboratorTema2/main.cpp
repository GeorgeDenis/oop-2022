#include <iostream>
#include "Canvas.h"

int main() {
    Canvas canvas(20, 20);
    // canvas.DrawCircle(5, 10, 3, '*');
    canvas.DrawRect(5, 5, 15, 15, '*');
    // canvas.SetPoint(5, 10, '%');
    canvas.Print();
    canvas.FillRect(5, 5, 15, 15, '%');
    canvas.Print();
    canvas.Clear();
    canvas.DrawLine(5, 10, 15, 15, '.');
    canvas.Print();
}