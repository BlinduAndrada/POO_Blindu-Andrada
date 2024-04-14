#include "Array.h"
#include <iostream>
#include "OutOfRangeException.h"
#include <exception>
#include "Compare.h"
using namespace std;

template<class T>
Array<T>::Array() {
	Size = Capacity = 0;
}

template<class T>
Array<T>::~Array() {
	delete[] List;
}

template<class T>
Array<T>::Array(int capacity) {
	List = new T * [capacity];
	Capacity = capacity;
	Size = 0;
}

template<class T>
Array<T>::Array(Array<T>& otherArray) {
	(*this) = otherArray;
}

template<class T>
T& Array<T>::operator[](int index) {

	if (index < 0 || index >= Size) {
		throw OutOfRangeException();
	}
	return *List[index];


}

template<class T>
const Array<T>& Array<T>::operator+=(T& newElem) {
	if (Size + 1 > Capacity) {
		throw "Capacitate maxima atinsa";
	}
	List[Size++] = &newElem;

	return (*this);
}

template<class T>
const Array<T>& Array<T>::Insert(int index, T& newElem) {

	if (index < 0 || index > Size || Size + 1 > Capacity) {
		throw OutOfRangeException();
	}

	int i = Size;
	while (i > index) {
		List[i] = List[i - 1];
		i--;
	}
	List[index] = &newElem;
	Size++;

	return (*this);
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray) {
	int asize = otherArray.Size;

	if (asize + Size >= Capacity) {
		throw OutOfRangeException();
	}

	int temp = Size + asize;
	while (temp + asize > index) {
		T[temp] = T[temp - asize];
		temp--;
	}

	int i = temp - asize;

	for (auto x : otherArray) {
		List[i++] = x;
	}
	Size++;

	return (*this);
}

template<class T>
const Array<T>& Array<T>::Delete(int index) {

	if (index < 0 || index >= Size) {
		throw OutOfRangeException();
	}
	delete List[index];
	while (index < Size) {
		List[index] = List[index + 1];
		index++;
	}
	Size--;
	delete List[Size];
	return (*this);
}

//?
template<class T>
bool Array<T>::operator=(Array<T>& otherArray) {
	Size = otherArray.GetSize();
	Capacity = otherArray.GetCapacity();

	delete[] List;
	List = new T * [Capacity];

	int index = 0;

	for (auto x : otherArray) {
		List[index++] = x;
	}

	return true;
}

template<class T>
void Array<T>::Sort() {
	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - i - 1; j++) {
			if (*List[j] > *List[j + 1]) {
				T* aux = List[j];
				List[j] = List[j + 1];
				List[j + 1] = aux;
			}
		}
	}
}

template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&)) {
	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - i - 1; j++) {
			if (compare(List[j], List[j + 1])) {
				T* aux = List[j];
				List[j] = List[j + 1];
				List[j + 1] = aux;
			}
		}
	}
}

template<class T>
void Array<T>::Sort(Compare* comparator) {
	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - i - 1; j++) {
			if (comparator->CompareElements(List[j], List[j + 1])) {
				T* aux = List[j];
				List[j] = List[j + 1];
				List[j + 1] = aux;
			}
		}
	}
}

template<class T>
int Array<T>::BinarySearch(const T& elem) {
	Array<T> temp = *this;
	int i = 0;
	int j = Size - 1;

	while (i < j) {
		int m = (i + j - 1) / 2;
		if (temp[m] == elem) {
			return m;
		}
		if (temp[m] < elem) {
			j = m - 1;
		}
		else {
			i = m + 1;
		}
	}

	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
	Array<T> temp = *this;
	int i = 0;
	int j = Size - 1;

	while (i < j) {
		int m = (i + j - 1) / 2;
		if (temp[m] == elem) {
			return m;
		}
		if (compare(temp[m], elem)) {
			j = m - 1;
		}
		else {
			i = m + 1;
		}
	}

	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator) {
	Array<T> temp = *this;
	int i = 0;
	int j = Size - 1;

	while (i < j) {
		int m = (i + j - 1) / 2;
		if (temp[m] == elem) {
			return m;
		}
		if (comparator->CompareElements(temp[m], elem)) {
			j = m - 1;
		}
		else {
			i = m + 1;
		}
	}

	return -1;
}

template<class T>
int Array<T>::Find(const T& elem) {
	return BinarySearch(elem);
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&)) {
	return BinarySearch(elem, compare);
}

template<class T>
int Array<T>::Find(const T& elem, Compare* comparator) {
	return BinarySearch(elem, comparator);
}