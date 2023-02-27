#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#pragma warning (disable : 4996)

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Student {

private:

	char* name;
	float gradeMath;
	float gradeEng;
	float gradeHist;

public:

	Student();
	Student(const char*, float, float, float);
	~Student();

	void setName(const char*);
	char* getName()const;
	void setGradeMath(float);
	float getGradeMath()const;
	void setGradeEng(float);
	float getGradeEng()const;
	void setGradeHist(float);
	float getGradeHist()const;
	float getAvg()const;

	void print();

};

#endif // !STUDENT_H_INCLUDED
