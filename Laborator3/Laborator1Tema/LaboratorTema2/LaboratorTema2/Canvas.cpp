#include "Canvas.h"
#include <string.h>
#include <stdarg.h>
#include <cstdio>
Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = y - ray; i <= y + ray; i++)
        for (int j = x - ray; j <= x + ray; j++)
            canvas[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i < right; i++)
        canvas[i][top] = ch;
    for (int i = bottom; i >= top; i--)
        canvas[left][i] = ch;
    for (int i = top; i <= bottom; i++)
        canvas[right][i] = ch;

    
}



void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
}

void Canvas::SetPoint(int x, int y, char ch) {
    canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

    
}

void Canvas::Print() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}

void Canvas::Clear() {
    memset(canvas, ' ', sizeof(canvas));
}
