#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
    double arr[19] = {22, 24, 19, 38, 22, 22, 23, 29, 27, 57, 63, 23, 24, 29, 31, 24, 20, 25, 30, 34};
    int i, sum = 0;
    double k = 0;
    for (i = 0; i < 20; i++)
    {
        k += arr[i];
    }
    k = k / 19;

    std::cout << "? ";
    std::cout << k << std::endl;
}