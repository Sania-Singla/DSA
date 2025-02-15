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

void merge(const vector<int> &arr, vector<int> &ans, int pivot)
{
    int e = arr.size() - 1;
    int i = 0, j = pivot + 1, k = 0;

    while (i <= pivot && j <= e)
    {
        if (arr[i] < arr[j])
        {
            ans[k++] = arr[i++];
        }
        else
        {
            ans[k++] = arr[j++];
        }
    }

    while (i <= pivot)
    {
        ans[k++] = arr[i++];
    }

    while (j <= e)
    {
        ans[k++] = arr[j++];
    }
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    print(arr);
    vector<int> ans(arr.size(), 0);
    int mid = (arr.size() - 1) / 2;
    int pivot = mid;
    merge(arr, ans, pivot);
    print(ans);
}