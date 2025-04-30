#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

pair<int, vector<int>> MSP(vector<vector<int>> graph, int n)
{
    vector<int> fdist(n, INT_MAX), path(n, -1);
    fdist[n - 1] = 0; // destination

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++) // if j = 0 -> n still will give answer but waste of iterations from 0 -> i since connection to next stage not backwards
        {
            if (i != j && graph[i][j] != INT_MAX && graph[i][j] + fdist[j] < fdist[i])
            {
                fdist[i] = graph[i][j] + fdist[j];
                path[i] = j;
            }
        }
    }
    return {fdist[0], path};
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

    pair<int, vector<int>> result = MSP(graph, graph.size());
    int minCost = result.first;
    vector<int> path = result.second;
    cout << "minimum cost = " << minCost << endl;
    print(path);
    return 0;
}