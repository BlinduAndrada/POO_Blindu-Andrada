#pragma once
#include "Compare.h"
#include "ArrayIterator.h"

template<class T>
class Array {
private:

    T** List;
    int Capacity;
    int Size;

public:

    Array();
    ~Array();
    Array(int capacity);

    Array(Array<T>& otherArray);

    T& operator[] (int index);

    //
    const Array<T>& operator+=(T& newElem);
    //
    const Array<T>& Insert(int index, T& newElem);
    //
    const Array<T>& Insert(int index, Array<T> otherArray);
    const Array<T>& Delete(int index);
    bool operator=(Array<T>& otherArray);



    void Sort();
    void Sort(int(*compare)(const T&, const T&));
    void Sort(Compare* comparator);


    int BinarySearch(const T& elem);
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));
    int BinarySearch(const T& elem, Compare* comparator);



    int Find(const T& elem);
    int Find(const T& elem, int(*compare)(const T&, const T&));
    int Find(const T& elem, Compare* comparator);

    int GetSize() {
        return Size;
    }
    int GetCapacity() {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return begin();
    }
    ArrayIterator<T> GetEndIterator() {
        return end();
    }
    ArrayIterator<T> begin() {
        ArrayIterator<T> ar;
        ar.Last = Size;
        ar.List = List;
        return ar;
    }
    ArrayIterator<T> end() {
        ArrayIterator<T> ar;
        ar.Last = Size;
        ar.List = List;
        ar.Current = Size - 1;
        return ar;
    }
};
