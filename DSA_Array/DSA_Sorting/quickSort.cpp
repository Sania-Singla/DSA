// time complexity: O(nlogn) (best & avg case)
// worst case O(n^2)
// space complexity: O(n) due to stack (but else it is O(1))

#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = b;
    b = a;
    a = temp;
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot) count++;
    }
    
    int pivotIndex = s+count;
    swap(arr[pivotIndex], arr[s]);

    int i=s, j=e;
    while(i < pivotIndex && j > pivotIndex) {   // i<=j wont work because not complusory that pivotIndex will be = mid
        while(arr[j] > arr[pivotIndex]) j--;
        while(arr[i] < arr[pivotIndex]) i++;
        if(i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if(s>=e) return ;
    else {
        int p = partition(arr, s, e);
        quickSort(arr, s, p-1);
        quickSort(arr, p+1, e);
    }
}

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int arr[10] = {10,2,1,4,2,5,1,23,23,5};
    quickSort(arr, 0, 9);
    print(arr, 10);
}