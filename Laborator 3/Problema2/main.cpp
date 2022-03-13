#include <iostream>
#include "Canvas.h"
void useCanvasExample() {
    Canvas canv(50, 50);
    canv.Clear();
    canv.DrawLine(32, 31, 36, 38, '\\');
    canv.DrawLine(12, 19, 16, 11, '/');
    canv.SetPoint(24, 29, '-');
    canv.DrawRect(34, 33, 26, 40, '|');
    canv.FillRect(24, 33, 26, 45, '|');
    canv.DrawCircle(18, 25, 15, '+');
    canv.FillCircle(13, 18, 2, '0');
    canv.FillCircle(13, 32, 2, '0');
    canv.Print();
}
int main() {

    useCanvasExample();
    return 0;
}