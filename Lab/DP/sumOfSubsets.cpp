#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &x)
{
    for (int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}

bool canInclude(int k, int m, int S, int R, vector<int> arr)
{
    if (S + arr[k] > m || S + R < m) // S + R < m is just an early pruning condition hence optional
    {
        return false;
    }
    return true;
}

int SOS(int i, const int m, const int n, vector<int> arr, int S, int R, vector<vector<int>> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i][S] != -1)
        return dp[i][S];

    int c1 = 0;
    if (canInclude(i, m, S, R, arr))
    {
        if (S + arr[i] == m)
        {
            c1 = 1;
        }
        else
        {
            c1 = SOS(i + 1, m, n, arr, S + arr[i], R - arr[i], dp);
        }
    }

    int c2 = SOS(i + 1, m, n, arr, S, R - arr[i], dp);

    dp[i][S] = c1 + c2;

    return dp[i][S];
}

int main()
{
    vector<int> arr = {5, 10, 12, 13, 15, 18};
    int m = 30, n = arr.size(), S = 0, R = 0;
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));

    for (int val : arr)
    {
        R += val;
    }

    cout << SOS(0, m, n, arr, S, R, dp);
}