// space complexity: O(logn->n) due to recursive stack but else it is O(1)
// time complexity: O(nlogn) (best & avg case)
// worst case O(n^2)
// mid element as pivot -> best case (already sorted in any order) O(nlogn)
//                      -> worst case O(n^2)
// any other element as pivot -> best case (pivot comes at mid always -> coincidental) O(nlogn)
//                            -> worst case (already sorted in any order) O(n^2)

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << "\t";
    }
    cout << endl;
}

// O(n)
int partition(vector<int> &nums, int s, int e)
{
    int i = s + 1, j = e, pivot = nums[s];
    // O(n)
    while (i <= j)
    {
        while (i <= e && nums[i] <= pivot)
        {
            i++;
        }
        while (j > s && nums[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[j], nums[s]);
    return j;
}

// T(n) = 2T(n/2) + O(n)
// T(n) = nlogn
void QS(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e); // O(n)
        print(arr);
        QS(arr, s, p - 1); // T(n/2)
        QS(arr, p + 1, e); // T(n/2)
    }
}

int main()
{
    // *repetitive elements*
    vector<int> arr = {5, 1, 1, 2, 0, 0};
    print(arr);
    QS(arr, 0, arr.size() - 1);
    print(arr);
}
