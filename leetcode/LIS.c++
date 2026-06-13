#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, int> LIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> trace_back(n);

    int len = 1, lastIdx = 0;
    for (int i = 1; i < n; i++)
    {
        trace_back[i] = i;

        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
            {
                trace_back[i] = j;
                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] > len)
        {
            len = dp[i];
            lastIdx = i;
        }
    }

    vector<int> seq(len);
    for (int i = len - 1; i >= 0 && trace_back[lastIdx] != lastIdx; i--)
    {
        seq[i] = nums[lastIdx];
        lastIdx = trace_back[lastIdx];
    }
    seq[0] = nums[lastIdx];  // had to do it explicitly since the loop condition terminated at this 

    return {seq, len};
}
int main()
{
    vector<int> nums = {5, 4, 11, 1, 16, 8};
    pair<vector<int>, int> p = LIS(nums);

    cout << "Length of LIS: " << p.second << endl;
    cout << "Indices of LIS: ";
    for (int x : p.first)
    {
        cout << x << " ";
    }
    return 0;
}