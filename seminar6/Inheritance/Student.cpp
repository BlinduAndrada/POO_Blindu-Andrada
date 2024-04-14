#include "Student.h"

Student::Student():varsta(0),nume(nullptr), Bursa() {}

Student::Student(int varsta_, const char* num, int val, const char* tip_) :varsta(varsta_), Bursa(val, tip_) {
	this->nume = new char[strlen(num) + 1];
	if (!nume) {
		cout << "Nu e bine";
		exit(-1);
	}
	strcpy(nume, num);
}

Student::Student(const Student& obj) : varsta(obj.varsta), Bursa(obj) {
	this->nume = new char[strlen(obj.nume) + 1];
	if (!nume) {
		cout << "Nu e bine";
		exit(-1);
	}
	strcpy(nume, obj.nume);
}

Student::~Student() {
	delete[] nume;
}

void Student::SetVarsta(int varsta_) {
	varsta = varsta_;

}
int Student::GetVarsta()const {
	return varsta;
}

istream& operator>>(istream& in, Student& obj) {

	in >> (Bursa&)obj;  //operator>>(in,(Bursa&)obj);
	cout << "Dati varsta studentului: ";
	in >> obj.varsta;
	cout << "Dati numele studentului: ";
	char buf[100];
	in >> buf;
	if (obj.nume)
		delete[] obj.nume;
	obj.nume = new char[strlen(buf) + 1];
	if (!obj.nume) {
		cout << "Alocation failed";
		exit(-1);
	}
	strcpy(obj.nume, buf);
	return in;

}

ostream& operator<<(ostream& out, const Student& obj) {
	out << (Bursa&)obj;  //operator<<(out,(Bursa&)obj);
	out << "Varsta studentului: " << obj.varsta << "\nNume student: " << obj.nume;
	return out;

}