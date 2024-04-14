#include "Bursa.h"

Bursa::Bursa() : valoare(0), tip(nullptr) {}

Bursa::Bursa(int val, const char* tip_) : valoare(val) {

	this->tip = new char[strlen(tip_)+1];
	if (!tip) {
		cout << "Alocation failed";
		exit ( - 1);
	}
	strcpy(tip, tip_);


}

Bursa::Bursa(const Bursa& obj):valoare(obj.valoare) {
	this->tip = new char[strlen(obj.tip) + 1];

	if (!tip) {
		cout << "Alocation failed";
		exit(-1);
	}
	strcpy(tip, obj.tip);

}

Bursa::~Bursa() {
	delete[] tip;
}

void Bursa::SetValue(int val) {
	valoare = val;
}

int Bursa::GetValue()const{
	return valoare;
}

Bursa& Bursa::operator=(const Bursa& obj) {
	valoare = obj.valoare;
	if (this->tip)
		delete[] tip;
	this->tip = new char[strlen(obj.tip) + 1];
	if (!tip) {
		cout << "Alocation failed";
		exit(-1);
	}
	strcpy(tip, obj.tip);
	return *this;

}

istream& operator>>(istream& in, Bursa& obj) {
	cout << "Dati valoarea bursei: ";
	in >> obj.valoare;
	cout << "Dati tipul bursei: ";
	char buf[100];
	in >> buf;
	if (obj.tip)
		delete[] obj.tip;
	obj.tip = new char[strlen(buf) + 1];
	if (!obj.tip) {
		cout << "Alocation failed";
		exit(-1);
	}
	strcpy(obj.tip,buf);

	fflush(stdin);

	return in;

}

ostream& operator<<(ostream& out, const Bursa& obj) {
	out << "valoare bursa: " << obj.valoare << "\nTip bursa: " << obj.tip;
	return out;

}