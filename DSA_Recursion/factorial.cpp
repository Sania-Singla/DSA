#include <iostream>
using namespace std;

// iterative
// long long fact(int n) {
//     long long f = 1;
//     for (int i=1;i<=n;i++) {
//         f *= i;
//     }
//     return f;
// }


// recursive
long long fact(int n) {
    if(n == 1) return 1; 
    return n * fact(n-1);
}

int main () {
    int n;
    cout<<"enter n:"<< endl;
    cin >> n;
    cout << "factorial = "<<fact(n);
}