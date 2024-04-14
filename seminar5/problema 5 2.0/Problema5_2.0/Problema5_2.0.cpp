#include "Number.h"
#include <iostream>
using namespace std;

int main() {
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }
    n1.Print();
    n2.Print();
    n1 = (n2 + n3 - n1) + n1;
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

    Number n4 = 12345;
    n1 = 255;
    n4 += n1;
    n4.Print();

    n4 = "13579";
    n4.Print();
    --n4--;
    n4.Print();

    

    Number n5("D4", 16);
    n1 = 20;

    n1 = n5 + n1;
    n1.Print();
   




    return 0;
}