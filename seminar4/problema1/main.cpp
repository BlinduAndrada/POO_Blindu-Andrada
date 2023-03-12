#include "Sort.h"

int main() {

    cout << "\n--List initialization with each constructor--\n\n";

    cout << "\n//Object with random element list (sort1)//\n\n";
    Sort sort1(10, 0, 100);
    sort1.Print();

    cout << "\n//Object with initializer list (sort2)//\n\n";
    Sort sort2 = { 10, 20, 30, 40, 50 };
    sort2.Print();

    cout << "\n//Object with list from an existing vector (sort3)//\n\n";
    int array[] = { 6, 5, 1, 2, 10, 4, 7, 8 };
    Sort sort3(array, 8);
    sort3.Print();

    cout << "\n//Object with variadic list (sort4)//\n\n";
    Sort sort4(10, 5, 100, 25, 50, 75, 10, 95, 30, 60, -1);
    sort4.Print();

    cout << "\n//Object with list from a string with numbers (sort5)//\n\n";
    Sort sort5("56,20,10,7,97");
    sort5.Print();

    cout << "\n--Sorting--\n\n";

    cout << "\n//InsertSort for \'sort1\' object//\n\n";
    sort1.InsertSort();
    sort1.Print();

    cout << "\n//QuickSort for \'sort2\' object//\n\n";
    sort2.QuickSort();
    sort2.Print();

    cout << "\n//BubbleSort for \'sort3\' object//\n\n";
    sort3.BubbleSort();
    sort3.Print();

    cout << "\n--\'Get\' Methods--\n\n";

    cout << "The counter from the list of the object \'sort4\': " << sort4.GetElementsCount() << '\n';
    cout << "The element with index \'3\' from the list of the object \'sort4\': " << sort4.GetElementFromIndex(3) << '\n';
    
    if (sort4.GetElementFromIndex(10) == NO_EL)
        cout << "The element with index \'10\' from the list of the object \'sort4\': there is no such element with index \'10\'" << '\n';
    else
        cout << "The element with index \'10\' from the list of the object \'sort4\': " << sort4.GetElementFromIndex(10) << '\n';

	return 0;

}
