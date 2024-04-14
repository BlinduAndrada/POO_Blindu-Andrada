#include <iostream>
#include "ArrayIterator.h"
#include "OutOfRangeException.h"
#include "Array.cpp"
#include "Compare.h"

using namespace std;
class CompareObj : public Compare {
public:
    virtual int CompareElements(void* e1, void* e2) override {
        return *(int*)e1 < *(int*)e2;
    }
};

int main() {
    Array<int> vector(20);
    int lim;
    cin >> lim;
    for (int i = 0; i < lim; i++) {
        int* value = new int(i % 5);
        try {

            vector += *value;
        }
        catch (const char* error) {
            cout << error << "\n";
            break;
        }

    }
    Array<int> copie = vector;
    int* value = new int(15);
    try {
        copie.Insert(15, *value);
    }
    catch (exception& e) {
        cout << e.what() << "\n";
    }

    try {
        copie.Delete(-5);
    }
    catch (const char* err) {
        cout << err << "\n";
    }
    try {
        copie[69];
    }
    catch (exception& e) {
        cout << e.what() << "\n";
    }
    copie.Sort(new CompareObj());
    cout << copie.BinarySearch(*(new int(3))) << "\n";

    cout << copie.Find(*(new int(6))) << "\n\n";
    
  /* CompareObj* a = new CompareObj();
    cout << copie.Find(12, a);*/   
   /* CompareObj comp;
    cout << copie.Find(4, &comp);*/

    for (auto el : copie) {
        cout << *el << "\n";
    }
    return 0;
}