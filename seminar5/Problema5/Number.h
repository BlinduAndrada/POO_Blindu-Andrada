#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#pragma warning (disable : 4996)

#include<cstring>
#include<iostream>
#include <algorithm>

using namespace std;

class Number {

private:
	char* value_;
	int base_;
	int digitsCount_;
	static const int MAX_DIGITS = 1000;

public:
	Number(const char* val, int b);
	~Number();
	Number(const Number& other); //copy
	Number(Number&& other);//move
	Number& operator=(const Number& other); //copy assigment
	Number& operator=(Number&& other); //move assigment

	friend Number operator+(const Number& nr1, const Number& nr2);
	friend Number operator-(const Number& nr1, const Number& nr2);

	Number operator--(int);
	Number& operator--();
	Number& operator+=(const Number& other);

	bool operator==(const Number& other) const;
	bool operator!=(const Number& other) const;
	bool operator>(const Number& other) const;
	bool operator<(const Number& other) const;
	bool operator>=(const Number& other) const;
	bool operator<=(const Number& other) const;
	char operator[](int index) const;  //operator de indexare

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount() const;
	int GetBase() const;

};

#endif // !NUMBER_H_INCLUDED
