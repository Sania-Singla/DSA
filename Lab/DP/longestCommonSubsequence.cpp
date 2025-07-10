#include <iostream>
#include <vector>

using namespace std;

// O(m*n)
pair<int, string> LCS(string x, string y, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) // for our convenience we have added one more extra row so if m = 5 it is [0,5] both included
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1]) // because string mein toh indexing 0 se hi hai
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string lcs;

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs = x[i - 1] + lcs; // prepend character to result because we are moving backwards
            i--, j--;             // diagonal movement hui hogi
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return {dp[m][n], lcs};
}

int main()
{
    string x = "ABCBDAB", y = "BDCAB";
    pair<int, string> ans = LCS(x, y, x.length(), y.length());
    cout << "length of longest common subsequence is = " << ans.first << endl;
    cout << "the subsequence is = " << ans.second << endl;
}