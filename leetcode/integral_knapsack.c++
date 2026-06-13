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
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // to print those items which are included in the knapsack
        int profit = dp[n][W];

        int w = W;
        for (int i = n; i > 0 && profit > 0; i--)
        {
            if (profit == dp[i - 1][w]) // means uper wale ka hi copy hua so ye value include nhi hui thi continue;
                continue;
            else
            {
                // This item is included.
                cout << i - 1 << ' '; // zero based indexing

                // Since this weight is included its
                // value is deducted
                profit = profit - val[i - 1];
                w = w - wt[i - 1];
            }
        }

        cout << endl;

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
