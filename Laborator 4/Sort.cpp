#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <cstdarg>
#include<string.h>



Sort::Sort(int n, int maxi, int mini)
{
	
	vector = new int[count];
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		vector[i] = mini + rand() % (maxi - mini + 1);

	}

}

Sort::Sort() : vector(new int[5]{ 2,6,1,9,8 })
{
	count = 5;
}

Sort::Sort(int v[], int n)
{
	vector = new int [n];
	for (int i = 0; i < n; i++)
		vector[i] = v[i];
	count = n;

}

Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);
	this->count = count;
	vector = new int[count];
	for (int i = 0; i < count; i++)
	{
		vector[i] = va_arg(args, int);

	}
	va_end(args);
}

Sort::Sort(char* sir[])
{
	char* p;
	char t[100][100];
	p = strtok(sir, ",");
	while (p != nullptr)
	{
		strcpy(t[count++], p);
		p = strtok(nullptr, ",");
	}
	vector = new int[count];
	for (int i = 0; i < count; i++)
	{
		vector[i] = atoi(t[i]);
	}

}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < count; i++) {
		int j = i - 1;
		int key = vector[i];
		if (ascendent == true) {
			while (j >= 0 && vector[j] > key) {
				vector[j + 1] = vector[j];
				j--;
			}
		}
		else {
			while (j >= 0 && vector[j] < key) {
				vector[j + 1] = vector[j];
				j--;
			}
		}
		if (vector[j + 1] != key)
			vector[j + 1] = key;
	}
}

void Sort::QuickSort(bool ascendent)
{
	Sortare(vector, 0,count-1,ascendent);
}
void Sort::Sortare(int* vector, int low, int high, bool ascendent)
{
	if (low < high) 
	{
		int pi = Partitionare(vector, low, high, ascendent);
		Sortare(vector, low, pi - 1, ascendent);
		Sortare(vector, pi + 1, high, ascendent);
	}
}

int Sort::Partitionare(int* vector, int low, int high, bool ascendent)
{
	int x = vector[low];
	int i = low + 1;
	int j = high;
	int aux;
	while (i <= j) {
		if (ascendent == true) {
			if (vector[i] <= x)
				i++;
			if (vector[j] >= x)
				j--;
			if (i < j && vector[i] > x && vector[j] < x) {
				
				vector[i] = aux;
				vector[i] = vector[j];
				vector[j] = aux;
				i++;
				j--;
			}
		}
		else {
			if (vector[i] >= x)
				i++;
			if (vector[j] <= x)
				j--;
			if (i < j && vector[i] < x && vector[j] > x) {
				vector[i] = aux;
				vector[i] = vector[j];
				vector[j] = aux;
				i++;
				j--;
			}
		}
	}
	vector[low] = vector[i - 1];
	vector[i - 1] = x;
	return i - 1;
}

void Sort::BubbleSort(bool ascendent) {
	int u = count - 1;
	while (u > 0) {
		int n = u - 1;
		u = 0;
		for (int i = 0; i <= n; i++) {
			if (vector[i] > vector[i + 1] && ascendent == true) {
				vector[i] ^= vector[i + 1] ^= vector[i] ^= vector[i + 1];
				u = i;
			}
			if (vector [i] < vector[i + 1] && ascendent == false) {
				vector [i] ^= vector[i + 1] ^= vector[i] ^= vector[i + 1];
				u = i;
			}
		}
	}
}

void Sort::Print() {
	for (int i = 0; i < GetElementsCount(); i++)
		printf("%d ", GetElementFromIndex(i));
	printf("\n");
}

int Sort::GetElementsCount() {
	return this->count;
}

int Sort::GetElementFromIndex(int index) {
	return vector[index];
}

	


