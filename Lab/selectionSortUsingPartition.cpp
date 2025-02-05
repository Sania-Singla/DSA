#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int partition(int *arr, int low, int high)
{
    int i = low + 1, j = high;
    int pivot = arr[low];  

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)  
            i++;
        while (j >= low && arr[j] > pivot)    
            j--;
        if (i < j)
            swap(arr[i], arr[j]);  
    }
    swap(arr[low], arr[j]);  
    return j;  
}

void selectionSortUsingPartition(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        partition(arr, i, n - 1);
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    selectionSortUsingPartition(arr, n);
    print(arr, n);
    return 0;
}
