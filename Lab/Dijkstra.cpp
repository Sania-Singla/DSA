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

// O(n^2)
void SSSP(const int &source, const int &n, vector<int> &dist, vector<string> &path, const vector<vector<int>> &cost)
{
    vector<bool> visited(n, false);

    // intialize the dist with the direct distances from source
    for (int i = 0; i < n; i++) // O(n)
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

    for (int j = 1; j < n; j++) // O(n)
    {
        // get minimum path vertex (u) and set its visited to true
        int u = -1;
        for (int i = 0; i < n; i++) // O(n)
        {
            if (dist[i] < dist[u] && !visited[i])
            {
                u = i;
            }
        }
        if (u == -1) // no more reachable nodes
        {
            break;
        }
        visited[u] = true;

        // now update the dist with the optimial path through source -> min -> ...
        for (int i = 0; i < n; i++) // O(n)
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
    //   A B C ...
    // A * * * ...
    // B * * * ...
    // C * * * ...
    vector<vector<int>> cost = {
        {0, 5, 1, INT_MAX},
        {INT_MAX, 0, 7, 4},
        {INT_MAX, INT_MAX, 0, 6},
        {3, INT_MAX, INT_MAX, 0},
    };

    int n = cost.size(), source = 2;
    vector<int> dist(n);
    vector<string> path(n);

    SSSP(source, n, dist, path, cost);
    print(dist);
    print(path);
}