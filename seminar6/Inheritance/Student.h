#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Bursa.h"

class Student : public Bursa {
	
	//private:

	int varsta;
	char* nume;

public:

	Student();
	Student(int, const char*, int, const char*);
	Student(const Student&);
	~Student();

	void SetVarsta(int);
	int GetVarsta()const;

	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);

};

#endif // !STUDENT_H_INCLUDED
