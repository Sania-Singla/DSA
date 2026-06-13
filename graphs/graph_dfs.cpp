#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// V cells * V sized loop for each cell
// O(v^2)
void DFS(int i, vector<vector<int>> graph, vector<bool> &visited, int n, vector<char> map)
{
    if (visited[i])
    {
        return;
    }

    cout << map[i];
    visited[i] = true;

    // find neighbours of node
    for (int j = 0; j < n; j++)
    {
        if (graph[i][j] == 1)
        {
            if (!visited[j])
            {
                DFS(j, graph, visited, n, map);
            }
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
    };

    int n = graph.size();

    vector<char> map = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<bool> visited(n, false);

    DFS(0, graph, visited, n, map);

    return 0;
}