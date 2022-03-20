#pragma once
class Sort

{
    // add data members
    int* lista;
    unsigned lenght;
    void helper(int* lista, int p, int q);
    int partitioneaza(int* lista, int p, int q);
  public:
    // add constuctors
    Sort(unsigned lenght, int min, int max);
    Sort();
    Sort(unsigned lenght, ...);
    Sort(int* vector, unsigned lenght);
    Sort(const char* numere);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};