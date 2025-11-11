#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool canInclude(vector<int> weights, int c, int i)
{
    return weights[i] <= c;
}

// memoized
vector<vector<int>> dp(101, vector<int>(101, -1));

int knapsack(vector<int> &weights, vector<int> &profits, int n, int c, int i) // pass by reference to reduce space complexity
{
    if (i >= n || c == 0)
    {
        return 0;
    }

    if (dp[i][c] != -1)  // because ho skta hai kuch inclusion/exclusion ka sequence bna ho and you get repitive capacity and at repitive index
    {
        return dp[i][c];
    }

    int ans = 0;

    if (canInclude(weights, c, i))
    {
        // aur hm kr bhi rhe hai include
        ans = profits[i] + knapsack(weights, profits, n, c - weights[i], i + 1);
    }

    dp[i][c] = max(ans, knapsack(weights, profits, n, c, i + 1));
    return dp[i][c];
}

// int knapsack(vector<int> weights, vector<int> profits, int n, int c, int i)
// {
//     if (i >= n || c == 0)
//     {
//         return 0;
//     }

//     int ans = 0;

//     if (canInclude(weights, c, i))
//     {
//         // aur hm kr bhi rhe hai include
//         ans = profits[i] + knapsack(weights, profits, n, c - weights[i], i + 1);
//     }

//     return max(ans, knapsack(weights, profits, n, c, i + 1));
// }

int main()
{
    vector<int> profits = {60, 100, 120}, weights = {10, 20, 30};
    int c = 50, n = profits.size();
    cout << knapsack(weights, profits, n, c, 0) << endl;
}
