#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << "  ";
    }
    cout << endl;
}

int getPivot(vector<int> arr)
{
    int i = 0;
    while (i < arr.size() - 1 && arr[i] <= arr[i + 1])
    {
        i++;
    }
    return i + 1;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void reverse(vector<int> &arr, int s, int e)
{
    int i = s, j = e;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}

void rotateArray(vector<int> &arr, int p)
{
    int n = arr.size();
    reverse(arr, 0, n - 1);
    reverse(arr, 0, n - p - 1);
    reverse(arr, n - p, n - 1);
}

int BS(vector<int> arr, int target, int s, int e)
{
    if (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            return BS(arr, target, mid + 1, e);
        }
        else
        {
            return BS(arr, target, s, mid - 1);
        }
    }
}

int search(vector<int> arr, int target)
{
    int p = getPivot(arr);
    rotateArray(arr, p);
    print(arr);
    int i = BS(arr, target, 0, arr.size() - 1);
    return i;
}

int main()
{
    vector<int> arr = {2, 2, 2, 3, 2, 2, 2};
    int target = 5;
    cout << search(arr, target);
}
