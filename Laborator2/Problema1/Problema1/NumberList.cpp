#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "NumberList.h"

void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if (count >= 10)
        return false;
    else {
        numbers[count] = x;
        count++;
    }
}

void NumberList::Sort() {
    int i, j;
    for (i = 0; i < count - 1; i++)
        for (j = i+1; j < count; j++)
            if (numbers[i] > numbers[j])
                std::swap(numbers[i], numbers[j]);
}

void NumberList::Print() {
    int j;
    for (j = 0; j < count; j++)
        printf("%d ", numbers[j]);
}


