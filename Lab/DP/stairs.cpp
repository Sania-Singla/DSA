#include <iostream>
#include <math.h>
using namespace std;

int NOS(int n)
{
    // int i = 1;
    // while (n > 0)
    // {
    //     int j = 0;
    //     while (n > 0 && j < i)
    //     {
    //         n--, j++;
    //     }
    //     if (j == i)
    //     {
    //         i++;
    //     }
    // }
    // return i - 1;

    return floor(-1 + sqrt(1 + 8 * n)) / 2;
}

int main()
{
    int n = 9;
    cout << NOS(n);

    return 0;
}