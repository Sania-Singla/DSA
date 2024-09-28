#include <iostream>
using namespace std;

// iterative
// long long power(int n,int x) {
//     long long p = 1;
//     for (int i=0;i<x;i++){
//         p *= n;
//     }
//     return p;
// }


// recursive
// long long power(int n,int x) {
//     if(x == 1) return n;  // or if(x == 0) return 1;
//     return n * power(n,x-1);
// }


// more optimized 
// n^x => if x(even) then ans = (n^x/2 * n^x/2)
// n^x => if x(odd) then ans = n * (n^x/2 * n^x/2)
long long power(int n,int x) {
    if(x == 0) return 1;
    if(x == 1) return n;
    int ans =  power(n, x/2);
    if(x%2==0) return ans * ans;
    else return n * ans * ans;
}


int main () {
    int n,x;
    cout<<"enter n & x:"<< endl;
    cin >> n >> x;
    cout << "power = "<<power(n,x);
}