#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int knapsack(int W, int N, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(W + 1, vector<int>(N + 1, 0)));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                // loop for number of times we can take the same item
                for (int k = 1; k <= N; k++)
                {
                    if (wt[i - 1] <= j) // zero based indexing
                    {
                        dp[i][j][k] = max(
                            dp[i - 1][j][k],
                            dp[i][j - wt[i - 1]][k - 1] + val[i - 1]); // i not i-1 because we can take the same item multiple times
                    }
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        return dp[n][W][N];
    }
};

int main()
{
    Solution sol;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    cout << sol.knapsack(capacity, 4, val, wt) << endl;
}
