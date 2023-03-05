#include "Math.h"

int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

int Math::Add(double x, double y) {
	return static_cast<int>(x + y);
}

int Math::Add(double x, double y, double z) {
	return static_cast<int>(x + y + z);

}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

int Math::Mul(double x, double y) {
	return static_cast<int>(x * y);

}

int Math::Mul(double x, double y, double z) {
	return static_cast<int>(x * y * z);

}

int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int suma = 0;
	for (int i = 0; i < count; i++)
		suma += va_arg(args, int);
	va_end(args);
	return suma;

}

char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;
	//metoda 1 cu cstring 
	//char* r = new char[strlen(s1) + strlen(s2) + 1];
	//metoda 2
	int lenght1 = 0, lenght2 = 0;
	while (s1[lenght1] != '\0')
		lenght1++;
	while (s2[lenght2] != '\0')
		lenght2++;
	char* r = new char[lenght1 + lenght2 + 1];
	//
	for (int i = 0; i < lenght1; i++)
		r[i] = s1[i];

	for (int i = 0; i < lenght2; i++)
		r[lenght1 + i] = s2[i];
	
	r[lenght1 + lenght2] = '\0';

	return r;

}
