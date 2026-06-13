// without visited
// A
// B C D
// C D E F
// D E
// E
// empty

// A: [B,C,D]
// B: [A, E, F]
// C: [A, F]
// D: [A]

// 0 1 0
// 1 0 1
// 1 1 0

// find neighbours of 2
// 0,1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// visited
// a b c d e f
// T T T   T T

// ho skta hai common neighbour abhi tk pop na hua ho so pop krte time bhi visited check lgega
// a
// b c d
// c d e f
// d e f f
// e f f
// f f
// f
// empty

void BFS(vector<vector<int>> graph, int n, vector<char> map)
{
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // important
        if (visited[node])
        {
            continue;
        }

        cout << map[node];

        visited[node] = true;

        // find neighbours of node
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1)
            { // there is an edge
                if (!visited[i])
                {
                    q.push(i);
                }
            }
            else
            {
                continue;
            }
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

    vector<char> map = {'A', 'B', 'C', 'D', 'E', 'F'};

    BFS(graph, graph.size(), map);

    return 0;
}