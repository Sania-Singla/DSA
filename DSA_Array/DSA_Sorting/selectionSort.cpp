// time complexity : O(n^2)   (worst case & best case)
// space complexity: O(1)

#include <iostream>
using namespace std;

void swap (int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void selectionSort(int arr[],int n) {
    //sorting
    
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;

        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) minIndex = j; // jo mn mein min. sochne wali cheez hai
        }

        swap (arr[minIndex], arr[i]);
    }
}

int main () {
    int arr[5] = {100,301,98,21,57};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    print(arr, n);
}