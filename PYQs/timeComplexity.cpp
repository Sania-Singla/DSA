#include<iostream>
#include<math.h>
using namespace std;

// void function(int n) {
//     int count = 0;
//     for(int i=1; i<=n; i+5) {
//         for(int j=n; j>3; j=pow(j,1.0/5.0)) {
//             for(int k=1; k<=pow(n,4); k=k*8) {
//                 cout << "*";
//             }
//         }
//     }
// }

// void printH(int n) {
//     for(int i=1; i<=n; i=i+5) {
//         cout << "H ";
//     }
// }

// void printH(int n) {
//     for(int k=1; k<=pow(n,4); k=k*8) {
//         cout << "H ";
//     }
// }

// void printH(int n) {
//     for(int j=n; j>3; j=pow(j,1.0/5.0)) {
//         cout << "H ";
//     }
// }

void nestedLoop(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=j; k++) {
                // some constant time operation 
            }
        }
    }
}


int function (int n) {
    if( n<=1 ) return 1;
    else {
        function(n-1);
        for(int i=1;i<=n;i++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    function(n);
    // printH(n);
}