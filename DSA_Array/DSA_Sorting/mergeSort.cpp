// time complexity: O(nlogn)
// space complexity: O(n+logn) => n>>logn => O(n) (recursive) (logn is due to stack but 'n' toh hoga hi due to merging)

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

void merge(int arr[], int s, int e)
{
    int mid = s + ((e - s) / 2);
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // making two new sub arrays (because abhi hmare paas divided arrays ka s & e aya hai vo divided arrays ni aye hain)
    int *first = new int[len1];
    int *second = new int[len2];

    int initialArrayIndex = s; // ** important **
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[initialArrayIndex++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[initialArrayIndex++];
    }

    // merge these 2 sorted arrays now
    int i = 0, j = 0;
    initialArrayIndex = s;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
            arr[initialArrayIndex++] = first[i++];
        else
            arr[initialArrayIndex++] = second[j++];
    }

    while (i < len1)
    {
        arr[initialArrayIndex++] = first[i++];
    }

    while (j < len2)
    {
        arr[initialArrayIndex++] = second[j++];
    }

    // can free up the sub array space now
    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = s + ((e - s) / 2);

        // left wala part
        mergeSort(arr, s, mid);

        // right wala part
        mergeSort(arr, mid + 1, e);

        merge(arr, s, e);
    }
}

int main()
{
    int arr[] = {4, 2, 1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);
}