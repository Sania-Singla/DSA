#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(const auto &arr)
{
    for (const auto &val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

void SSSP(const int &source, const int &n, vector<int> &dist, vector<string> &path, const vector<vector<int>> &cost)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        if (cost[source][i] != INT_MAX)
        {
            path[i] = to_string(source) + ">" + to_string(i);
        }
        else
        {
            path[i] = "Unreachable";
        }
    }
    visited[source] = true;

    for (int j = 1; j < n; j++)
    {
        int min = INT_MAX, u = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = true;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && cost[u][i] != INT_MAX && dist[i] > dist[u] + cost[u][i]) // we are explicitly checking for infinite case because it causes integer overflow (wraps to INT_MIN) when i add something in max possible integer: dist[i] > dist[u] + cost[u][i]
            {
                dist[i] = dist[u] + cost[u][i];
                path[i] = path[u] + ">" + to_string(i);
            }
        }
    }
}

int main()
{
    // directed & weighted graph's adjacency matrix (cost)
    //   A B C D
    // A * * * *
    // B * * * *
    // C * * * *
    // D * * * *
    vector<vector<int>> cost = {
        {0, 5, 1, INT_MAX},
        {INT_MAX, 0, 7, 4},
        {INT_MAX, INT_MAX, 0, 6},
        {3, INT_MAX, INT_MAX, 0},
    };

    int n = cost.size(), source = 0;
    vector<int> dist(n);
    vector<string> path(n);

    SSSP(source, n, dist, path, cost);
    print(dist);
    print(path);
}