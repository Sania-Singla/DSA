// time complexity : O(n^2)   (worst case & best case)
// space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void print(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        swap(arr[minIdx], arr[i]);
    }
}

int main()
{
    vector<int> arr = {100, 301, 98, 21, 57};
    selectionSort(arr, arr.size());
    print(arr);
}