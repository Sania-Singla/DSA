// time complexity: O(n^2) worst case, O(n) best case
// space complexity: O(1)

#include <iostream>
using namespace std;

static int c;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        c++;
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            c++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int i = 1;
    while (i <= 10)
    {
        c = 0;
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        cout << "array size = " << i << endl;
        cout << "before = ";
        print(arr, i);
        insertionSort(arr, i);
        cout << "after = ";
        print(arr, i);
        cout << "number of iterations =" << c << endl;
        i++;
    }
}