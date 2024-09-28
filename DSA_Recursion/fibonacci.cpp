// time complexity: O(2^n)

#include<iostream>
using namespace std;

int NthfibonacciTerm(int n) {
    if(n==0 || n==1) return n;
    return NthfibonacciTerm(n-1) + NthfibonacciTerm(n-2);
}

int main() {
    int n;
    cout << "enter index of the term (starting from 0)" << endl;
    cin >> n;
    cout << NthfibonacciTerm(n);
}