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
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int distance;
            distance = (x - j) * (x - j) + (y - i) * (y - i);
            if (distance <= ray * (ray + 1) && distance >= ray * (ray - 1))
                SetPoint(i, j, ch);
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++)
        SetPoint(top, i, ch);
    for (int i = top; i <= bottom; i++)
        SetPoint(i, left, ch);
    for (int i = bottom; i >= top; i--)
        SetPoint(i, right, ch);
    for (int i = right; i >= left; i--)
        SetPoint(bottom, i, ch);
}



void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left + 1; i < right; i++) {
        for (int j = top + 1; j < bottom; j++) {
            SetPoint(i, j, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int D  = 2 * dy - dx;
    int y  = y1;
    int x;
    for (x = x1; x <=x2; x++) {
        SetPoint(x, y, ch);
        if (D>0) {
            y = y + 1;
            D = D - 2 * dx;
        } 
        D = D + 2 * dy;
    }
    
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
