#include "NumberList.h"

int main(){

	int vec[10] = { 3, 9, -1, 2, 10, 1, -5, 6, 7, 12 };
	int count = 5; 
	NumberList obj(vec, count);

	obj.Init();
	obj.Print();

	obj.Add(3);
	obj.Print();

	obj.Sort();
	obj.Print();

	return 0;
}