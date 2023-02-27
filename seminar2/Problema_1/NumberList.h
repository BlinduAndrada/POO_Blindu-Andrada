#ifndef NUMBERLIST_H_INCLUDED
#define	NUMBERLIST_H_INCLUDED

#include <iostream>

using namespace std;

class NumberList {

	//private:

	int numbers[10];
	int count;

public:

	NumberList();
	NumberList(int[], int);

	void Init();
	bool Add(int x);

	void Sort();
	void Print();

	int getCount()const;

};

#endif // !NUMBERLIST_H_INCLUDED