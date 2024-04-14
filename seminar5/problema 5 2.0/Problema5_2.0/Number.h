#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

#include <string.h>
#include <iostream>
using namespace std;

class Number {

private:
    char* value;
    int base;
    bool isNegative;

    long long convertToBaseTen(char* s, int base);
    char* convertToBase(long long n, int base);
    int normalizeDigit(char c);
    char formalizeDigit(int n);

public:
    Number(const char* value, int base);
    ~Number();


    Number(const Number& n);
    Number(const Number&& n);
    Number(const int);

    char operator[] (int i);
    friend Number operator+ (const Number& x, const Number& y);
    friend Number operator- (const Number& x, const Number& y);
    bool operator> (Number& n);

    void operator= (const char*);  //pt char
    void operator= (const Number& n); //pt egalizare acelasi tip, Number
    void operator= (int n);   //pt int uri, n=12345

    void operator+= (Number& n);

    Number& operator-- ();
    Number& operator-- (int);


    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount();
    int  GetBase();
    long long getBaseTen();



    
};

char* toString(long long);
void copyString(char*, char*);