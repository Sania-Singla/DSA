#include <iostream>
#include <vector>

using namespace std;

int LCS(string x, string y, int m, int n)
{
    vector<vector<int>> table(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // to initialize first row and col with 0
            {
                table[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[m][n];
}

int main()
{
    string x = "ABCBDAB", y = "BDCAB";
    cout << "length of longest common subsequence is = " << LCS(x, y, x.length(), y.length());
    return 0;
}