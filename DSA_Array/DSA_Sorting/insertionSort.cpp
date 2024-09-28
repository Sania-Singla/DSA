// time complexity : O(n^2)   (worst case)
// best case : O(n)
// space complexity: O(1)

#include<iostream>
using namespace std;


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ** we shift in insertion sort not swap
void insertionSort (int arr[], int n) {
    for(int i=1; i<n; i++) {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        // or
        // for (; j>=0; j--) {
            // if(arr[j] > temp) {
            //     arr[j+1] = arr[j];
            // }
            // else {
            //     break;
            // }
        // }
        arr[j+1] = temp;
    }
}

int main () {
    int arr[5] = {5,3,3,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    print(arr, n);
}