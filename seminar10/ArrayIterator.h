#pragma once
template <class T>
class ArrayIterator {
private:
public:
    T** List;
    int Current;
    int Last;
    ArrayIterator() {
        Current = 0;
    }

    ArrayIterator& operator ++ () {
        Current++;
        return *this;
    }

    ArrayIterator& operator -- () {
        Current--;
        return *this;
    }

    bool operator== (ArrayIterator<T>&) {
        return Current == Last;
    }

    bool operator!=(ArrayIterator<T>&) {
        return Current != Last;
    }

    T* GetElement() {
        return List[Current];
    }

    T* operator* () {
        return GetElement();
    }

};