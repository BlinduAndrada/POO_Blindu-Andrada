#include "Vector.h"

template <class T>
Vector<T>::Vector(int d, T* buf) : dim(d) {

	this->buffer = new T[dim];

	if (!buffer) {
		cout << "Allocation failed";
		exit(1);
	}
	
	for (auto i = 0; i < dim; i++)
		buffer[i] = buf[i];

}

template <class T>
Vector<T>::~Vector() {
	delete[] buffer;
}

template <class T>
void Vector<T>::Sortare() {
	for(auto i=0;i<dim-1;i++)
		for(auto j=i+1;j<dim;j++)
			if (buffer[i] > buffer[j]) {
				auto aux = buffer[i];
				buffer[i] = buffer[j];
				buffer[j] = aux;
			}
}

template <class T>
void Vector <T>::Print() {
	cout << "Vector dimension: " << dim << '\n';
	for (auto i = 0; i < dim; i++)
		cout << buffer[i] << " ";
	cout << '\n';
}

namespace{
	void test() {
		
		int a[10] = { 3,5,76,2,69,420,43,96,13,8 };
		double b[5] = { 2.4, 5.9, -2.4, 9.1 ,69.420 };

		Vector<int> v1(10, a);
		Vector<double> v2(5, b);

		v1.Print();
		v2.Print();

	}
}//punem o fct test, care ne ajuta sa rulam programul
