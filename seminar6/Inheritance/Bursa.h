#ifndef BURSA_H_INCLUDED
#define BURSA_H_INCLUDED
#pragma warning (disable: 4996)

#include <iostream>
#include <cstring>

using namespace std;

class Bursa {

protected:

	int valoare;
	char* tip;

public:

	Bursa();
	Bursa(int, const char*);
	Bursa(const Bursa&);
	~Bursa();

	void SetValue(int);
	int GetValue()const;

	Bursa& operator =(const Bursa&);

	friend istream& operator >> (istream&, Bursa&);
	friend ostream& operator << (ostream&, const Bursa&);

};

#endif // !BURSA_H_INCLUDED
