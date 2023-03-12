#include "Sort.h"

Sort::Sort(int counter, int min, int max) : count(counter) {

	this->elements = new int[count];

	// random numbers seed generator setting
	srand(time(nullptr));

	for (auto i = 0; i < count; i++)
		this->elements[i] = rand() % (max - min + 1) + min;

}

Sort::Sort(initializer_list<int> list) : count(static_cast<int>(list.size())) {

	this->elements = new int[count];

	for (auto i = 0; i < count; i++)
		if (i < list.size())
			this->elements[i] = *(list.begin() + i);

}

Sort::Sort(int* array, int counter) :count(counter) {

	this->elements = new int[count];

	for (auto i = 0; i < count; i++)
		this->elements[i] = array[i];

}

Sort::Sort(int first, ...) : count(1) {

	va_list args;

	va_start(args, first);

	auto next = va_arg(args, int);

	while (next != VA_LIMIT) {

		count++;
		next = va_arg(args, int);

	}

	this->elements = new int[count];

	va_start(args, first);

	this->elements[0] = first;

	for (auto i = 1; i < count; i++) {
		this->elements[i] = va_arg(args, int);
	}

	va_end(args);

}

Sort::Sort(const char* str) : count(0) {

	const char* ptr = str;

	while (*ptr != '\0') {

		if (*ptr == ',')
			count++;
		
		ptr++;

	}

	count++;

	this->elements = new int[count];

	ptr = str;

	auto i = 0;   

	while (*ptr != '\0') {

		if (*ptr >= '0' && *ptr <= '9') {

			this->elements[i] = 0;

			while (*ptr >= '0' && *ptr <= '9') {

				this->elements[i] = this->elements[i] * 10 + (*ptr - '0');

				ptr++;

			}

			i++;

		}
		else
			ptr++;

	}

}

Sort::~Sort() {

	delete[] this->elements;

}

void Sort::InsertSort(bool ascendent) {

	for (auto i = 1; i < count; i++) {

		auto current = elements[i];
		auto j = i - 1;

		while (j >= 0 && ((ascendent && elements[j] > current) || (!ascendent && elements[j] < current))) {

			this->elements[j + 1] = this->elements[j];

			j--;

		}

		this->elements[j + 1] = current;

	}

}

void Sort::QuickSort(bool ascendent) {

	QuickSortHelper(elements, 0, count - 1, ascendent);

}

void Sort::QuickSortHelper(int arr[], int left, int right, bool ascendent) {

	if (left < right) {

		auto pivotIndex = Partition(arr, left, right, ascendent);
		QuickSortHelper(arr, left, pivotIndex - 1, ascendent);
		QuickSortHelper(arr, pivotIndex + 1, right, ascendent);

	}

}

int Sort::Partition(int arr[], int left, int right, bool ascendent) {

	auto pivot = arr[right]; // the pivot is chosen to be the last element
	auto i = left - 1;

	for (auto j = left; j < right; j++) {

		if (ascendent) {

			if (arr[j] < pivot) {

				i++;

				Swap(arr[i], arr[j]);

			}

		}
		else {

			if (arr[j] > pivot) {

				i++;

				Swap(arr[i], arr[j]);

			}

		}

	}

	Swap(arr[i + 1], arr[right]);

	return i + 1;

}

void Sort::Swap(int& a, int& b) {

	auto temp = a;
	a = b;
	b = temp;

}

void Sort::BubbleSort(bool ascendent) {

	auto swapped = true;
	auto j = 0;

	while (swapped) {

		swapped = false;

		j++;

		for (auto i = 0; i < count - j; i++) {

			if ((ascendent && elements[i] > elements[i + 1]) || (!ascendent && elements[i] < elements[i + 1])) {

				Swap(elements[i], elements[i + 1]);

				swapped = true;

			}

		}

	}

}

void Sort::Print() {

	for (auto i = 0; i < count; i++)
		cout << elements[i] << " ";

	cout << '\n';

}

int Sort::GetElementsCount() {

	return this->count;

}

int Sort::GetElementFromIndex(int index) {

	if (index >= 0 && index < count)
		return this->elements[index];

	return -1;

}