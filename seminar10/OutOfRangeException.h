#pragma once
#include <exception>
using namespace std;

class OutOfRangeException : public exception {
	virtual const char* what() const throw() {
		return "Index Out Of Bounds Exception!";
	}
};