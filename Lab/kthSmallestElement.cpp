#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int partition(int *arr, int low, int high, int n)
{
    int i = low, j = high, key = arr[low];
    while (i <= j)
    {
        do
        {
            i++;
        } while (i < high && arr[i] < key);
        do
        {
            j--;
        } while (j >= low && arr[j] > key);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    print(arr, n);
    return j;
}

// int KthsmallestElement(int *arr, int n, int k)
// {
//     if (n == 1)
//         return arr[0];
//     int low = 0;
//     int high = n - 1;
//     int j;
//     while (low <= high)
//     {
//         int j = partition(arr, low, high + 1);
//         if (j == k - 1)
//         {
//             return arr[j];
//         }
//         else if (j < k)
//         {
//             low = j + 1;
//         }
//         else
//         {
//             high = j - 1;
//         }
//     }
//     return arr[j];
// }

int KthsmallestElement(int *arr, int low, int high, int k, int n)
{
    if (low == high)
        return arr[low];
    int j = partition(arr, low, high + 1, n);
    if (j == k - 1)
    {
        return arr[j];
    }
    else if (j < k - 1)
    {
        return KthsmallestElement(arr, j + 1, high, k, n);
    }
    else
    {
        return KthsmallestElement(arr, low, j - 1, k, n);
    }
}

int main()
{
    int arr[] = {1, 11, 12, 71, 9, 12, 4, 6, 28, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;
    cout << KthsmallestElement(arr, 0, n - 1, k, n) << endl;
    // top k elements
    print(arr, k);
}