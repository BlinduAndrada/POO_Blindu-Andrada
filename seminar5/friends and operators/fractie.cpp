#include "fractie.h"

Fractie::Fractie(int aa, int bb) {
	a = aa;
	b = bb;
}

Fractie::Fractie(const Fractie& obj) {
	a = obj.a;
	b = obj.b;

}

Fractie::~Fractie() {
	//cout<<"Am apelat destructorul";
}

double Fractie::GetValue()const {
	return static_cast<double>(a / b);
}

Fractie Fractie::GetInvers()const {
	Fractie inv;
	inv.a = b;
	inv.b= a;

	return inv;
}

void Fractie::SetData(int val1, int val2) {
	a = val1;
	b = val2;

}

float Fractie::GetA()const {
	return static_cast<float>(a);
}

float Fractie::GetB()const {
	return static_cast<float>(b);
}

void Fractie::Print() {
	cout << "f= " << a << "/" << b;
}

Fractie operator +(const Fractie& f1, const Fractie& f2) {
	Fractie sum;
	sum.a = f1.a * f2.b + f2.a + f1.b;
	sum.b = f1.b * f2.b;
	return sum;
}

Fractie operator -(const Fractie& f1, const Fractie& f2) {
	Fractie dif;
	dif.a = f1.a * f2.b - f2.a + f1.b;
	dif.b = f1.b * f2.b;
	return dif;
}

Fractie operator *(const Fractie& f1, const Fractie& f2) {
	Fractie p;
	p.a = f1.a * f2.a;
	p.b = f1.b * f2.b;
	return p;
}

Fractie operator /(const Fractie& f1, const Fractie& f2) {
	Fractie div;
	div.a = f1.a * f2.b;
	div.b = f1.b * f1.a;
	return div;
}

Fractie operator -(const Fractie& f1) {
	Fractie sign;
	sign.a = -f1.a;
	sign.b = f1.b;
	return sign;
}

Fractie& Fractie::operator +=(const Fractie& f) {
	this->a = a * f.b + b * f.a;
	this->b = b * f.b;
	return *this;
}

Fractie& Fractie::operator -=(const Fractie& f) {
	this->a = a * f.b - b * f.a;
	this->b = b * f.b;
	return *this;
}

Fractie& Fractie::operator *=(const Fractie& f) {
	this->a = a * f.a;
	this->b = b * f.b;
	return *this;
}

Fractie& Fractie::operator /=(const Fractie& f) {
	this->a = a * f.b ;
	this->b = b * f.a;
	return *this;
}

bool Fractie::operator ==(const Fractie& f) {
	//return (((*this).a == f.a) && ((*this).b == f.b));   (*this).a = this->a
	if (this->a == f.a && this->b == f.b)
		return 1;
	return 0;

}

bool Fractie::operator !=(const Fractie& f) {
	
	if (this->a != f.a || this->b != f.b)
		return 1;
	return 0;

}

bool Fractie::operator <(const Fractie& f) {

	if (this->GetValue() < f.GetValue())
		return 1;
	return 0;

}

bool Fractie::operator >(const Fractie& f) {

	if (this->GetValue() > f.GetValue())
		return 1;
	return 0;

}

bool Fractie::operator <=(const Fractie& f) {

	if (this->GetValue() <= f.GetValue())
		return 1;
	return 0;

}


bool Fractie::operator >=(const Fractie& f) {

	if (this->GetValue() >= f.GetValue())
		return 1;
	return 0;

}

