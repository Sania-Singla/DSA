// time complexity : O(n^2)   (worst case)
// best case : O(n)
// space complexity: O(1)

#include<iostream>
using namespace std;

void swap (int &a, int &b) {
    int temp;
    temp = b;
    b = a;
    a = temp;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// in bubble sort i is only used for rounds but in selection sort we do use arr[i] in swapping 
// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n-1; i++) {  
//         // for optimization if already sorted
//         bool swapped = false;
//         for (int j = 0; j < n-i-1; j++) {   // or if want to use n-i only then use i from 1->n
//             if(arr[j] > arr[j+1]) {
//                 swap(arr[j], arr[j+1]);
//                 swapped = true;
//             }
//         }
//         if(!swapped) break;
//     }
// }

// recursive
void bubbleSort(int arr[], int n, int i, int j) {
    if(n==1) return;   // was the last pass
    if(i==n-1) return bubbleSort(arr, n-1, 0, 1);    // next pass
    if(arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
    }
    return bubbleSort(arr, n, ++i, ++j);
}

int main() {
    int arr[5] = {1,3,5,2,4};
    bubbleSort(arr, 5, 0, 1);
    print(arr, 5);
}