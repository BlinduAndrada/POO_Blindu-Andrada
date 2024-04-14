#include "Map.h"


int main()
{
    Map<int, const char*> m, n;

    n[15] = "";
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    //std::cout << m.Includes(n);

    for (auto [key, value, index] : m)
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    m[20] = "result";
    m.Set(30, "Andrada");

    for (auto [key, value, index] : m)
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    if (m.Includes(n))
        printf("Mapul n include mapul m.\n");
    else
        printf("Mapul n nu include mapul m.\n");

    return 0;

}