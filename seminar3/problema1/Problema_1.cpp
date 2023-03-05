#include "Math.h"

int main() {

	cout << Math::Add(3, 7) << '\n';
	cout << Math::Add(3, 7, 9) << '\n';
	cout << Math::Add(3.124, 5.98) << '\n';
	cout << Math::Add(3.124, 5.98, 6.5678) << '\n';
	cout << '\n';
	cout << Math::Mul(3, 7) << '\n';
	cout << Math::Mul(3, 7, 9) << '\n';
	cout << Math::Mul(3.124, 5.98) << '\n';
	cout << Math::Mul(3.124, 5.98, 6.5678) << '\n';
	cout << '\n';
	cout << Math::Add(5, 1, 2, 3, 4, 5) << '\n';
	cout << '\n';
	
	//metoda 1: sir de caractere constante
	/*const char* s1 = "Hello";
	const char* s2 = "World";
	const char* s3 = Math::Add(s1, s2);
	if (s3 != nullptr) {
		cout << s3 << '\n';
		delete[] s3;
	}
	else
		cout << "Error" << '\n';*/

	char buf[250];
	cout << "Primul string: ";
	cin.getline(buf, 250);
	char* s1 = new char[strlen(buf) + 1];
	if (!s1) {
		cout << "Alocation error";
		exit(-1);
	}
	else
		strcpy(s1, buf);

	fflush(stdin); 
	
	cout << "Al doilea string: ";
	cin.getline(buf, 250);
	char* s2 = new char[strlen(buf) + 1];
	if (!s2) {
		cout << "Alocation error";
		exit(-1);
	}
	else
		strcpy(s2, buf);

	char* s3 = Math::Add(s1, s2);
	if (s3 != nullptr) {
		cout << s3 << '\n';
		delete[] s3;
	}
	else
		cout << "Error" << '\n'; 
	




	return 0;

}
