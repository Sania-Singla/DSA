#include<iostream>
using namespace std;

bool sortedORnot (int arr[], int size) {
    if(size == 0 || size == 1) return true;
    else { 
        if(arr[0] > arr[1]) return false;
        bool ans = sortedORnot(arr+1, size-1);    // because arr is going to be a pointer
        return ans;
    }
}

int main () {
    int arr[5] = {1,2,3,4,5};
    if(sortedORnot(arr, 5)) cout << "SORTED" << endl;
    else cout << "NOT SORTED." << endl;
}