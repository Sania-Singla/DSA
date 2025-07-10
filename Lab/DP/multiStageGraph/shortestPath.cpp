#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>> arr)
{
    for (vector<int> row : arr)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printPath(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// O(n^2)
vector<int> MSG(vector<vector<int>> graph, int n)
{
    vector<int> path;
    vector<vector<int>> dp(n, vector<int>(2)); // {cost, nextVtx}
    dp[n - 1][0] = 0, dp[n - 1][1] = n - 1;    // sink -> sink

    for (int i = n - 2; i >= 0; i--)
    {
        // choose minimum edge
        int nextVtx = -1, minCost = INT_MAX;
        for (int j = i + 1; j < n; j++) // as no edge from 0 -> i (no backward or itself edges)
        {
            if (graph[i][j] != INT_MAX && graph[i][j] + dp[j][0] < minCost)
            {
                nextVtx = j, minCost = graph[i][j] + dp[j][0];
            }
        }

        dp[i][0] = minCost, dp[i][1] = nextVtx;
    }

    print(dp);

    int currVtx = 0;
    path.push_back(0);

    while (currVtx != n - 1)
    {
        currVtx = dp[currVtx][1];
        path.push_back(currVtx);
    }

    return path;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 9, 7, 3, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, 4, 2, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 2, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 11, 8, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 6, 5, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4, 3, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 5, 6, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 4},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 2},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 5},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
    };

    vector<int> path = MSG(graph, graph.size());
    printPath(path);
}