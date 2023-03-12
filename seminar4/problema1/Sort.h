#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include<iostream>
#include<cstdarg>
#include<cstdlib>
#include<ctime>

using namespace std;

#define VA_LIMIT -1
#define NO_EL -1

class Sort {
	
private:

    int* elements;  //list, array
    int count;

    void QuickSortHelper(int arr[], int left, int right, bool ascendent = false);
    int Partition(int arr[], int left, int right, bool ascendent = false);
    void Swap(int& a, int& b);
	
public:
    
    Sort(int counter, int min, int max);
    Sort(initializer_list<int> list);
    Sort(int* array, int counter);
    Sort(int first, ...);
    Sort(const char* str);
    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();
    int  GetElementFromIndex(int index);

};

#endif // !SORT_H_INCLUDED
