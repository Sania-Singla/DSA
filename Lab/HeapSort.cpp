#include <iostream>
#include <math.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[large])
    {
        large = left;
    }
    if (right < n && arr[right] > arr[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(arr[large], arr[i]);
        // furthur heapify
        heapify(arr, n, large);
    }
}

void heapSort(int arr[], int n)
{
    // form max heap
    for (int i = floor(n / 2); i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    printArray(arr, n);

    int size = n;

    for (int i = 0; i < size; i++)
    {
        swap(arr[0], arr[n - 1]);
        heapify(arr, --n, 0);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    heapify(arr, n, 0);

    printArray(arr, n);

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}
