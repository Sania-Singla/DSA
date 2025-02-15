#include <iostream>
#include <vector>

using namespace std;

// O(n)
bool sortedORnot(const vector<int> &arr, int i)
{
    int n = arr.size();
    if (i >= n)
    {
        return true;
    }
    else
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
        return sortedORnot(arr, ++i);
    }
}

// O(n) (divide & conquer)
// T(n) = 2T(n/2) + c
// bool sortedORnot(const vector<int> &arr, int s, int e)
// {
//     if (s >= e)
//     {
//         return true;
//     }
//     else
//     {
//         int mid = s + ((e - s) / 2);
//         if ((mid == s || arr[mid] >= arr[mid - 1]) && (mid == e || arr[mid] <= arr[mid + 1]))
//         {
//             return sortedORnot(arr, s, mid - 1) && sortedORnot(arr, mid + 1, e);
//         }

//         return false;
//     }
// }

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3};
    if (sortedORnot(arr, 0))
        cout << "SORTED" << endl;
    else
        cout << "NOT SORTED." << endl;
}