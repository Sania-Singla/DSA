#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SOS(vector<int> &arr, int t)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < t + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]; // use OR operator if just want to return T/F for atleast one subset
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][t];
}

int main()
{
    vector<int> candidates = {2, 3, 5, 6, 8, 10};
    int target = 10;

    cout << SOS(candidates, target);
}