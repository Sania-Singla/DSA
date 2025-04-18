#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char extra_rod) {
    if(n==0) return;
    towerOfHanoi(n-1, from_rod, extra_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n-1, extra_rod, to_rod, from_rod);
}

int main () {
    int n=3;
    towerOfHanoi(n,'A','C','B');
}