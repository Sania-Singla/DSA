#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                {
                    // zero based indexing hai na
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]); // change here, we are not doing i-1 in the second part because we can take the same item multiple times
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
    }
};

int main()
{
    Solution sol;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    cout << sol.knapsack(capacity, val, wt) << endl;
}
