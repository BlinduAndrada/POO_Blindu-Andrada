#ifndef FRACTIE_H_INCLUDED
#define FRACTIE_H_INCLUDED

#include<iostream>

using namespace std;

class Fractie {

private:
	int a;
	int b;

public:
	Fractie(int aa=0, int bb=0);
	Fractie(const Fractie&);
	~Fractie();

	double GetValue()const;
	Fractie GetInvers()const; 
	void SetData(int, int);
	float GetA()const;
	float GetB()const;

	void Print();

	//functii friend
	friend Fractie operator +(const Fractie&, const Fractie&);
	friend Fractie operator -(const Fractie&, const Fractie&);
	friend Fractie operator *(const Fractie&, const Fractie&);
	friend Fractie operator /(const Fractie&, const Fractie&);
	friend Fractie operator -(const Fractie&);

	Fractie& operator +=(const Fractie&);  //Fractie &operator +=(Fractie *this,const Fractie&)
	Fractie& operator -=(const Fractie&);  //Fractie &operator -=(Fractie *this,const Fractie&)
	Fractie& operator *=(const Fractie&);  //Fractie &operator *=(Fractie *this,const Fractie&)
	Fractie& operator /=(const Fractie&);  //Fractie &operator /=(Fractie *this,const Fractie&)

	bool operator ==(const Fractie&);
	bool operator !=(const Fractie&);
	bool operator <(const Fractie&);
	bool operator >(const Fractie&);
	bool operator <=(const Fractie&);
	bool operator >=(const Fractie&);


};

#endif // !FRACTIE_H_INCLUDED
