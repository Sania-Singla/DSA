// time complexity : O(logn)   (worst case & best case)
// space complexity: O(1) for iterative because mid can be reused but O(logn) for recursive because of stack working 

#include<iostream>
using namespace std;

int binarySearch(int key, int arr[], int low, int high) {
    if(low <= high){
        // int mid = (low + high) / 2;        // could lead to overflow
        int mid = low + ( (high-low) / 2 );
        if (arr[mid] == key) return mid+1;   
        else if (key > arr[mid]) return binarySearch(key, arr, mid+1, high);
        else return binarySearch(key, arr, low, mid-1);
    }
    return -1;
}

int main () {
    int key;
    int arr[10] = {11,21,38,42,59,63,79,81,99,111};
    cout << "enter key:" << endl;
    cin >> key;
    if(binarySearch(key, arr, 0, 9) == -1) cout << "NOT FOUND." << endl;
    else cout << "position = " << binarySearch(key, arr, 0, 9);

    return 0;
}