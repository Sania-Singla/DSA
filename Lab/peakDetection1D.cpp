// peak detection in 1D

#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int> arr, int s, int e)
{
    int midIndex = s + ((e - s) / 2);
    int target = arr[midIndex];

    if (midIndex - 1 >= s && arr[midIndex - 1] >= target)
    {
        return peak(arr, s, midIndex - 1);
    }
    else if (midIndex + 1 <= e && arr[midIndex + 1] >= target)
    {
        return peak(arr, midIndex + 1, e);
    }
    else
    {
        return midIndex;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int peakIdx = peak(arr, 0, n - 1);

    if (peakIdx == -1)
    {
        cout << "peak doesn't exist";
    }
    else
    {
        cout << "peak exists &= " << peakIdx;
    }

    return 0;
}