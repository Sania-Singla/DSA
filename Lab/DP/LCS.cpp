#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int LCS_recur(string s1, string s2, int i, int j)
{
    int n = s1.length(), m = s2.length();

    if (i >= n || j >= m)
    {
        return 0;
    }

    if (s1[i] == s2[j])
    {

        return 1 + LCS_recur(s1, s2, i + 1, j + 1);
    }

    return max(LCS_recur(s1, s2, i + 1, j), LCS_recur(s1, s2, i, j + 1)); // its like a zig-zag movement
}

// memoized
int LCS_memo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    int n = s1.length(), m = s2.length();

    if (i >= n || j >= m)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        dp[i][j] = 1 + LCS_memo(s1, s2, i + 1, j + 1, dp);
        return dp[i][j];
    }

    dp[i][j] =
        max(LCS_memo(s1, s2, i + 1, j, dp),
            LCS_memo(s1, s2, i, j + 1, dp));

    return dp[i][j];
}

int main()
{
    string s1 = "abcde", s2 = "ace";
    int n = s1.length(), m = s2.length();

    cout << LCS_recur(s1, s2, 0, 0) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << LCS_memo(s1, s2, 0, 0, dp) << endl;
}