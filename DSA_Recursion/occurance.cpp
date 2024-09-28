#include<iostream>
using namespace std;

// just like binary sort
int firstOcc(int arr[], int i, int j, int k) {
    int ans = -1;
    if(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==k) {
            ans = mid;
            int leftAns = firstOcc(arr, i, mid-1, k);
            if(leftAns != -1) return leftAns;
            else return ans;
        }
        else if (arr[mid] < k) return firstOcc(arr, mid+1, j, k);
        else return firstOcc(arr, i, mid-1, k);
    }
    return ans;
}

int lastOcc(int arr[], int i, int j, int k) {
    int ans = -1;
    if(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==k) {
            ans = mid;
            int rightAns = lastOcc(arr, mid+1, j, k);
            if(rightAns != -1) return rightAns;
            else return ans;
        }
        else if (arr[mid] < k) return lastOcc(arr, mid+1, j, k);
        else return lastOcc(arr, i, mid-1, k);
    }
    return ans;
}

void deleteOcc(int newArr[], int arr[],int k, int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]!=k) {
            newArr[count++] = arr[i];
        }
    }
}

int main() {
    int arr[10] = {1,2,3,5,5,5,5,5,6,3};
    int n = 10;
    int k = 5;
    cout << "first occurance = " << firstOcc(arr, 0, n-1, k) << endl; 
    cout << "last occurance = " << lastOcc(arr, 0, n-1, k ) << endl; 
    int totalOcc = (lastOcc(arr, 0, n-1, k) - firstOcc(arr, 0, n-1, k) + 1);
    int newArr[n-totalOcc] = {0};
    cout << "total occurances = " << totalOcc << endl; 
    cout << "after deleting the array becomes: " << endl;
    deleteOcc(newArr, arr, k, n);
    for(int i=0;i<n-totalOcc;i++){
        cout << newArr[i] << " ";
    }
    cout << endl;
}