#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int partition(int *arr, int low, int high)
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
    return j;
}

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high+1);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

class Solution
{
public:
    void sortArray(int *nums, int s)
    {
        QuickSort(nums, 0, s - 1);
    }
};

int main()
{
    Solution sol;
    int nums[] = {-4, 0, 7, 4, 9, -5, -1, 0, -7, -1};
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    sol.sortArray(nums, sizeof(nums) / sizeof(nums[0]));

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
