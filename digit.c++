#include<iostream>
using namespace std;

int main() {
    int x = 1234;

    while(x) {
        x %= 10;
        cout << x << endl;
        x /=10;
    }
}