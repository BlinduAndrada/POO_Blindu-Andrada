#include "NumberList.h"

int main(){

	//int vec[10] = { 3, 9, -1, 2, 10, 1, -5, 6, 7, 12 };
	//int count = 5; 
//	NumberList obj(vec, count);
	NumberList list;

	//obj.Init();
	//obj.Print();

	//obj.Add(3);
	//obj.Print();

	//obj.Sort();
	//obj.Print();



	list.Init();
	list.Add(3);
	list.Add(1);
	list.Add(4);
	list.Add(2);
	list.Add(7);
	list.Add(9);
	list.Print();
	list.Sort();
	list.Print();
	return 0;
}
