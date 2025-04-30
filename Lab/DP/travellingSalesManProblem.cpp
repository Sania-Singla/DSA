#include <iostream>
#include <climits>

using namespace std;

const int N = 4, INF = 1e9;

int graph[N][N] = {
    {0, 5, 9, 8},
    {5, 0, 7, 6},
    {9, 7, 0, 4},
    {8, 6, 4, 0}};

int dp[1 << N][N];

int tsp(int mask, int pos)
{
    if (mask == (1 << N) - 1)
        return graph[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INF;
    for (int city = 0; city < N; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = graph[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << tsp(1, 0) << endl;
}