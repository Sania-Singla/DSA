#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// O(n*C)
int knapsack(int C, vector<int> weights, vector<int> profits, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= C; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], profits[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // tracing back
    int w = C;
    vector<int> selectedItems(n, 0);
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selectedItems[i - 1] = 1; // Item was included
            w -= weights[i - 1];      // Reduce capacity
        }
    }

    print(selectedItems);
    return dp[n][C];
}

int main()
{
    vector<int> profits = {60, 100, 120}, weights = {10, 20, 30};
    int C = 50;
    cout << knapsack(C, weights, profits, profits.size()) << endl;
}
