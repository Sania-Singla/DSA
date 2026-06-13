#include<iostream>
using namespace std;

int main() {
    int a = 4 ^ 4, b = 4 ^ 0, c = 4 ^ 2, d = 4 ^ 7, e = -2 ^ -5;
    cout << a << b << c << d << e << endl;

    int x = 0;

    x ^= 1;
    cout << x << endl;

    x ^= 2;
    cout << x << endl;

    x ^= 2;
    cout << x << endl;

    // x ^= 7;
    // cout << x << endl;

    // x ^= 2;
    // cout << x << endl;

    // x ^= 5;
    // cout << x << endl;
}