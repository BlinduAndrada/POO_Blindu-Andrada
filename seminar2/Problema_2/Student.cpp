#include "Student.h"

//acestia sunt constructori

Student::Student() : name(nullptr), gradeMath(0), gradeEng(0), gradeHist(0) {}

Student::Student(const char* n, float gM, float gE, float gH) {

	name = new char[strlen(n) + 1];

	if (!name) {
		cout << "The allocation failed!";
		exit(-1);
	}

	strcpy(name, n);

	gradeMath = gM;
	gradeEng = gE;
	gradeHist = gH;

}

//destructor

Student::~Student() {

	delete[] name;

}

//metode

void Student::setName(const char* newName) {

	if (name)
		delete[] name;

	name = new char[strlen(newName) + 1];

	if (!name) {
		cout << "The allocation failed!";
		exit(-1);
	}

	strcpy(name, newName);
	
}

char* Student::getName()const {

	return this->name;

}

void Student::setGradeMath(float grade) {

	gradeMath = grade;

}


float Student::getGradeMath()const {

	return gradeMath;

}

void Student::setGradeEng(float grade) {

	gradeEng = grade;

}

float Student::getGradeEng()const {

	return gradeEng;

}

void Student::setGradeHist(float grade) {

	gradeHist = grade;

}

float Student::getGradeHist()const {

	return gradeHist;

}

float Student::getAvg()const {

	return (gradeMath + gradeEng + gradeHist) / 3;

}

void Student::print() {

	cout << "\n--------------------------------------------\n";
	cout << "Name: " << Student::getName() << '\n';
	cout << "Math grade: " << Student::getGradeMath() << '\n';
	cout << "English grade: " << Student::getGradeEng() << '\n';
	cout << "History grade: " << Student::getGradeHist() << '\n';
	cout << "Student's average grade: " << setprecision(3) << Student::getAvg();
	cout << "\n--------------------------------------------\n";

}