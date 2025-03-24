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

// O(n)
void merge(const vector<int> &arr, vector<int> &ans, int mid)
{
    int e = arr.size() - 1;
    int i = 0, j = mid + 1, k = 0;

    while (i <= mid && j <= e)
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

    while (i <= mid)
    {
        ans[k++] = arr[i++];
    }

    while (j <= e)
    {
        ans[k++] = arr[j++];
    }
}

// T(n) = 2T(n/2) + O(n)
// T(n) = 2T(n/2) + cn
// master's method: T(n) = O(nlogn)
void MS(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int mid = s + ((e - s) / 2);

        MS(arr, s, mid);     // T(n/2)
        MS(arr, mid + 1, e); // T(n/2)

        vector<int> ans(arr.size(), 0); // S(n)

        merge(arr, ans, mid); // O(n)

        // copy ans to arr: O(n)
        // for (int i = s; i < ans.size(); i++)
        // {
        //     arr[i] = ans[i];
        // }
        arr = ans;
    }
}

int main()
{
    vector<int> arr = {0, 3, 2, 7, 5, 4, 1, 8, 6, 9};
    MS(arr, 0, arr.size() - 1);
    print(arr);
}