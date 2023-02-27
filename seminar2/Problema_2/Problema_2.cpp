#include "Student.h"
#include "functions.h"

int main() {

	Student stud1("Victor", 5.6f, 9.5f, 6.7f);
	Student stud2("Marcu", 6.6f, 9.5f, 10);

	stud1.print();
	stud2.print();

	//stud1.setName("Blindu Andrada");
	//stud1.setGradeEng(10);
	//stud1.setGradeHist(7);
	//stud1.setGradeMath(9.5f);
	//stud1.print();

	cout << "\nValue after name comparision: " << nameCompare(stud1, stud2);
	cout << "\nValue after Math grade comparision: " << mathGradeCompare(stud1, stud2);
	cout << "\nValue after English grade comparision: " << engGradeCompare(stud1, stud2);
	cout << "\nValue after History grade comparision: " << histGradeCompare(stud1, stud2);
	cout << "\nValue after average grade comparision: " << avgGradeCompare(stud1, stud2);

	return 0;
}