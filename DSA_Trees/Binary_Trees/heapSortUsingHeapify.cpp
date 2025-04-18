#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify reduced heap
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    print(arr);
    return 0;
}