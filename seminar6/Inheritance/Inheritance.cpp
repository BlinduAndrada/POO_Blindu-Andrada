#include "Student.h"

int main() {

	auto dim(3); // auto dim = 3;

	Student* stud;
	stud = new Student[dim];

	/*
	float* v1 = new float[dim];

	int rows = 3, cols = 4;
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
	*/

	for (int i = 0; i < dim; i++)
		cin >> stud[i];
	for (int i = 0; i < dim; i++)
		cout << stud[i] << '\n';

	return 0;

}