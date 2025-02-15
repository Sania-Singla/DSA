#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// the arrays are sorted
void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // copying arr1 if arr2 khtm
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

    // copying arr2 if arr1 khtm
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 6, 7};
    int arr2[] = {2, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n + m] = {0};
    merge(arr1, n, arr2, m, arr3);
    print(arr3, n + m);
}
