#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void print(const vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

// O(n)
int partition(vector<int> &nums, int s, int e)
{
    // choosing first element as pivot
    int i = s + 1, j = e, pivot = nums[s];
    while (i <= j)
    {
        while (nums[i] < pivot)
        {
            i++;
        }
        while (nums[j] > pivot)
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

// Recursive
int KthsmallestElement(vector<int> &arr, int s, int e, int k)
{
    if (s == e)
    {
        return arr[s];
    }

    int p = partition(arr, s, e);

    if (p == k - 1)
    {
        return arr[p];
    }
    else if (p < k - 1)
    {
        return KthsmallestElement(arr, p + 1, e, k);
    }
    else
    {
        return KthsmallestElement(arr, s, p - 1, k);
    }
}

// Iterative
// int KthsmallestElement(vector<int> &arr, int k)
// {
//      int n = arr.size();
//     if (n == 1)
//         return arr[0];
//     int s = 0, e = n - 1, p;
//     while (s <= e)
//     {
//         int p = partition(arr, s, e);
//         if (p == k - 1)
//         {
//             return arr[p];
//         }
//         else if (p < k)
//         {
//             s = p + 1;
//         }
//         else
//         {
//             e = p - 1;
//         }
//     }
//     return arr[p];
// }

int main()
{
    // *distinct elements*
    vector<int> arr = {1, 11, 12, 9, 12, 4, 6, 28, 71};
    int k = 7;
    cout << KthsmallestElement(arr, 0, arr.size() - 1, k) << endl;

    // 'k' smallest elements
    print(arr, k);
}