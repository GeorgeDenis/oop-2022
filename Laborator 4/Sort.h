#pragma once
class Sort

{

    // add data members

    int count;
    int* vector;
    void Sortare(int* vector, int low, int high,bool ascendent);
    int Partitionare(int* vector, int low, int high,bool ascendent);
public:

    // add constuctors
    Sort(int n, int maxi, int mini);

    Sort();

    Sort(int v[], int n);

    Sort(int count, ...);

    Sort(char* sir[]);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

}