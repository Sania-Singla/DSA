#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << "\t";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// O(2n)
// int partition(vector<int> &arr, int s, int e)
// {
//     int pivot = arr[s], count = 0;
//     // O(n)
//     for (int i = s + 1; i <= e; i++)
//     {
//         if (arr[i] <= pivot)
//              count++;
//     }

//     int pivotIndex = s + count;
//     swap(arr[pivotIndex], arr[s]);

//     int i = s, j = e;

//     // O(n)
//     // i<=j wont work because not complusory that pivotIndex will be = mid
//     while (i < pivotIndex && j > pivotIndex)
//     {
//         if (arr[j] > pivot)
//             j--;
//         else if (arr[i] < pivot)
//             i++;
//         else
//             swap(arr[i++], arr[j--]);
//     }
//     return pivotIndex;
// }

// O(n) (EASIEST)
// int partition(vector<int> &arr, int s, int e)
// {
//     // choose mid element as the pivot (can use any element but better performance for mid element)
//     int mid = s + ((e - s) / 2);

//     // loop from i:(s -> mid-1) & j:(e -> mid+1)
//     int i = s, j = e, pivot = arr[mid];
//     while (i < j)
//     {
//         if (arr[i] < pivot)
//             i++;
//         else if (arr[j] > pivot)
//             j--;
//         else
//             swap(arr[i], arr[j]);
//     }

//     return i;
// }

// **Valid for duplicate elements as well**
// OR (using loops)
// int partition(vector<int> &nums, int s, int e)
// {
//     int i = s, j = e + 1, pivot = nums[s];
//     // O(n)
//     while (i <= j)
//     {
//         do
//         {
//             i++;
//         } while (i <= e && nums[i] < pivot);

//         do
//         {
//             j--;
//         } while (j >= s && nums[j] > pivot);

//         if (i <= j)
//         {
//             swap(nums[i++], nums[j--]); // prevents infinite loop
//         }
//     }
//     swap(nums[j], nums[s]);
//     return j;
// }

// OR
int partition(vector<int> &nums, int s, int e)
{
    int i = s + 1, j = e, pivot = nums[s];
    // O(n)
    while (i <= j)
    {
        while (i <= e && nums[i] < pivot)
        {
            i++;
        }
        while (j >= s && nums[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(nums[i++], nums[j--]); // prevents infinite loop
        }
    }
    swap(nums[j], nums[s]);
    return j;
}

int main()
{
    vector<int> arr = {1, 4, 5, 2, 9, 0, 0, 5, 8, 6};
    int p = partition(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}
