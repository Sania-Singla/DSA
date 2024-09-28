#include <iostream>
using namespace std;

void sayDigits(string arr[], int n) {
    if(n==0) return ;
    sayDigits(arr, n/10);
    cout << arr[n%10] << " ";
}

int main () {
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cout << "enter n:" << endl;
    cin >> n;
    sayDigits(arr,n);
}