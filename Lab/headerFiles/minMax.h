#ifndef MAXMIN_H
#define MAXMIN_H

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> x)
{
    for (int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}

// Divide & Conquer
// T(n) = 2T(n/2) + c
// O(n)

// indices
void solve(const vector<int> &arr, int s, int e, int &minIdx, int &maxIdx)
{
    if (s == e)
    {
        maxIdx = s;
        minIdx = s;
    }
    else
    {
        int maxIdx1, minIdx1;
        int mid = s + ((e - s) / 2);
        solve(arr, s, mid, minIdx, maxIdx);
        solve(arr, mid + 1, e, minIdx1, maxIdx1);
        if (arr[maxIdx1] > arr[maxIdx])
        {
            maxIdx = maxIdx1;
        }
        if (arr[minIdx1] < arr[minIdx])
        {
            minIdx = minIdx1;
        }
    }
}

// values
// void solve(const vector<int> &arr, int s, int e, int &min, int &max)
// {
//     if (s == e)
//     {
//         max = arr[s];
//         min = arr[s];
//     }
//     else
//     {
//         int max1, min1;
//         int mid = s + ((e - s) / 2);
//         solve(arr, s, mid, min, max);
//         solve(arr, mid + 1, e, min1, max1);
//         if (max1 > max)
//         {
//             max = max1;
//         }
//         if (min1 < min)
//         {
//             min = min1;
//         }
//     }
// }

void minMax(const vector<int> &arr, int &min, int &max)
{
    solve(arr, 0, arr.size() - 1, min, max);
}

// int main()
// {
//     vector<int> arr = {3, 8, 4, 10, 7, 10, 8, 6};
//     int max, min;
//     minMax(arr, min, max);
//     cout << "min is: " << min << " & max is: " << max << endl;
//     return 0;
// }

#endif
