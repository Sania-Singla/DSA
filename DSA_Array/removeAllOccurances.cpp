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

int removeElement(int *nums, int size, int val)
{
    int i = 0, j = 0;
    while (i < size)
    {
        if (nums[i] == val)
        {
            i++;
        }
        else
        {
            if (j != i)
                swap(nums[j], nums[i]);
            i++;
            j++;
        }
    }
    return j;
}

int main()
{
    int arr[8] = {0, 1, 2, 2, 3, 0, 4, 2};
    print(arr, 8);
    int j = removeElement(arr, 8, 2);
    cout << j << endl;
    print(arr, j);
}