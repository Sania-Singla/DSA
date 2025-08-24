#include <bits/stdc++.h>
using namespace std;

// standard example of sliding window pattern
class Solution
{
public:
    int maximumSumSubarray(vector<int> &arr, int k)
    {
        // code here
        int maxSum = INT_MIN, sum = 0, n = arr.size();

        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }

        maxSum = sum;

        for (int i = 1; i <= n - k; i++)
        {
            sum -= arr[i - 1];
            sum += arr[i + k - 1];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }

        return maxSum;
    }
};