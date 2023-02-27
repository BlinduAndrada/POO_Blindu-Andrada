#include "functions.h"

int nameCompare(const Student& s1, const Student& s2) {

	auto x = strcmp(s1.getName(), s2.getName());

	return x;

}

int mathGradeCompare(const Student& s1, const Student& s2) {

	if (s1.getGradeMath() > s2.getGradeMath())
		return 1;

    if (s1.getGradeMath() < s2.getGradeMath())
    	return -1;

	return 0;

}

int engGradeCompare(const Student& s1, const Student& s2) {

	if (s1.getGradeEng() > s2.getGradeEng())
		return 1;

	if (s1.getGradeEng() < s2.getGradeEng())
		return -1;

	return 0;

}

int histGradeCompare(const Student& s1, const Student& s2) {

	if (s1.getGradeHist() > s2.getGradeHist())
		return 1;

	if (s1.getGradeHist() < s2.getGradeHist())
		return -1;

	return 0;

}

int avgGradeCompare(const Student& s1, const Student& s2) {

	if (s1.getAvg() > s2.getAvg())
		return 1;

	if (s1.getAvg() < s2.getAvg())
		return -1;

	return 0;

}