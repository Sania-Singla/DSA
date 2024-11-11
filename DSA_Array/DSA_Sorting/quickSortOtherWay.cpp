#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// int partition(int *arr, int low, int high)
// {
//     int i = low, j = high, key = arr[low];
//     while (i <= j)
//     {
//         do
//         {
//             i++;
//         } while (i < high && arr[i] < key);

//         do
//         {
//             j--;
//         } while (j >= low && arr[j] > key);
//         if (i < j)
//         {
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[j], arr[low]);
//     return j;
// }

// OR
int partition(int nums[], int low, int high)
{
    int i = low + 1, j = high, key = nums[low];
    while (i <= j)
    {
        while (i <= high && nums[i] < key)
        {
            i++;
        }
        while (j >= 0 && nums[j] > key)
        {
            j--;
        }
        if (i <= j)
        {
            swap(nums[i++], nums[j--]);
        }
    }
    swap(nums[j], nums[low]);
    return j;
}

void QuickSort(int nums[], int low, int high)
{
    if (low < high)
    {
        int p = partition(nums, low, high);
        QuickSort(nums, low, p - 1);
        QuickSort(nums, p + 1, high);
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
    int nums[] = {-4, 0, 7, 4, 9, -5, -1, 0, -7, -1}; // {5,2,3,1}   // {5,1,1,2,0,0}
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
