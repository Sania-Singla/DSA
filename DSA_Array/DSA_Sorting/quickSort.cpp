// time complexity: O(nlogn) (best & avg case)
// worst case O(n^2)
// space complexity: O(n) due to recursive stack (but else it is O(1))

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// int partition(vector<int> &arr, int s, int e)
// {
//     int pivot = arr[s], count = 0;
//     for (int i = s + 1; i <= e; i++)
//     {
//         if (arr[i] <= pivot)
//         {
//             count++;
//         }
//     }

//     int pivotIndex = s + count;
//     swap(arr[pivotIndex], arr[s]);

//     int i = s, j = e;

//     // i<=j wont work because not complusory that pivotIndex will be = mid
//     while (i < pivotIndex && j > pivotIndex)
//     {
//         if (arr[j] > pivot)
//         {
//             j--;
//         }
//         else if (arr[i] < pivot)
//         {
//             i++;
//         }
//         else
//         {
//             swap(arr[i++], arr[j--]);
//         }
//     }
//     return pivotIndex;
// }

int partition(vector<int> &arr, int s, int e)
{
    // choose mid element as the pivot ( can use any element but better performance for mid element )
    int mid = s + ((e - s) / 2);

    // loop from i:(s -> mid-1) & j:(e -> mid+1)
    int i = s, j = e, pivot = arr[mid];
    while (i < j)
    {
        if (arr[i] < pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
        }
    }

    return i;
}

void QS(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        cout << "pivot: " << p << endl;
        QS(arr, s, p - 1);
        QS(arr, p + 1, e);
    }
}

int main()
{
    vector<int> arr = {1, 4, 7, 2, 9, 0, 3, 5, 8, 6};
    QS(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
