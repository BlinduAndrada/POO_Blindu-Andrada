#include "Vector.h"

int main() {

	int a[10]={3,5,76,2,69,420,43,96,13,8};
	double b[5] = { 2.4, 5.9, -2.4, 9.1 ,69.420 };

	Vector<int> v1(10, a);
	Vector<double> v2(5, b);

	v1.Print();
	v2.Print();

	return 0;

}