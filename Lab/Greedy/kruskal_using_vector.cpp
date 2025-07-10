#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, weight;
};

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
}

int Find(vector<int> parent, int u)
{
    while (parent[u] >= 0)
    {
        u = parent[u];
    }
    return u;
}

void Union(vector<int> &parent, vector<int> &rank, int u, int v)
{
    int i = Find(parent, u), j = Find(parent, v);
    if (rank[i] < rank[j])
    {
        parent[i] = j;
        rank[j]++;
    }
    else
    {
        parent[j] = i;
        rank[i]++;
    }
}

vector<vector<int>> Kruskal(vector<Edge> edges, int n, int e)
{
    vector<vector<int>> tree; // (n-1)*2
    vector<int> parent(n, -1);
    vector<int> rank(n, 0);

    int totalWeight = 0;

    // !Sort the edges in increasing order of weights

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].u, v = edges[i].v;

        if (Find(parent, u) != Find(parent, v))
        {
            Union(parent, rank, u, v);
            totalWeight += edges[i].weight;
            tree.push_back({u, v});
        }
    }

    return tree;
}

int main()
{
    // !already sorted in increasing weights
    vector<Edge> edges = {
        // u v wt
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9},
    };

    int n = 5; // number of vertices
    vector<vector<int>> tree = Kruskal(edges, n, edges.size());
    print(tree);
}
