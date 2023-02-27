#include "NumberList.h"

NumberList::NumberList() {

	for (auto i = 0; i < 10; i++)
		numbers[i] = 0;

	count = 0;

}

NumberList::NumberList(int num[], int c) {

	for (auto i = 0; i < 10; i++)
		numbers[i] = num[i];

	count = c;

}

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {

	
	if (count >= 10)
	{
		return false;
	}
	numbers[count] = x;
	count++;

	return true;

}

void NumberList::Sort() {
	
	for(auto i=0;i<count-1;i++)
		for(auto j=i+1;j<count;j++)
			if (numbers[i] > numbers[j]) {
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
				
}

void NumberList::Print() {
	for (auto i = 0; i < count; i++)
		cout << numbers[i] << " ";
	cout << '\n';

	cout << NumberList::getCount() << '\n';

}

int NumberList::getCount()const {

	return count;

}
