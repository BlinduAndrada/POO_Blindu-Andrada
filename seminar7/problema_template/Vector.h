#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<iostream>

using namespace std;

template <class T>
class Vector {

private:
	int dim;
	T* buffer;

public:
	Vector(int d, T* buf);
	~Vector();
	
	void Sortare();
	void Print();

};

#endif // !VECTOR_H_INCLUDED
