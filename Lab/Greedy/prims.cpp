// generate minimum weighted spanning tree T = (V, E') of given graph G = (V,E) where |E'| = |V|-1
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(const vector<vector<int>> &arr)
{
    for (const vector<int> &row : arr)
    {
        cout << row[0] << " - " << row[1] << endl;
    }
}

// O(n)
int minWeightedNear(const vector<vector<int>> &cost, const vector<int> &near)
{
    int minCost = INT_MAX, u = -1;
    for (int j = 0; j < cost.size(); j++)
    {
        if (near[j] != -1 && cost[j][near[j]] < minCost)
        {
            minCost = cost[j][near[j]];
            u = j;
        }
    }
    return u;
}

// O(n^2)
vector<int> minWeightedEdge(const vector<vector<int>> &cost)
{
    vector<int> edge(2, -1);
    int minCost = INT_MAX, n = cost.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && cost[i][j] < minCost)
            {
                minCost = cost[i][j];
                edge[0] = i, edge[1] = j;
            }
        }
    }
    return edge;
}

// O(n^2)
void prims(const vector<vector<int>> &cost, const int &n, vector<vector<int>> &tree, int &weight)
{
    vector<int> near(n, 0); // we can't say near = 0 means visited and don't further process it because for some vertex its near could be 0 too so there could have been a conflict

    // find the minimum weighted (costed) edge
    vector<int> edge = minWeightedEdge(cost); // O(n^2)
    int k = edge[0], l = edge[1];

    if (k == -1 || l == -1)
    {
        cout << "Graph is disconnected, No MST possible." << endl;
        tree.clear();
        return;
    }

    // now push this min edge into the tree and mark these vertices as visited (near = -1)
    tree[0][0] = k, tree[0][1] = l;
    near[k] = -1, near[l] = -1;
    weight = cost[k][l];

    // initialize rest of the near array with respect to k & l
    for (int i = 0; i < n; i++) // O(n)
    {
        if (near[i] != -1)
        {
            near[i] = cost[i][k] <= cost[i][l] ? k : l;
        }
    }

    // fill the remaining tree that is indexed from 1 -> n-2 (size = n-1)
    for (int i = 1; i < n - 1; i++) // O(n)
    {
        // since near has been completely initialized, so now find the minimum cost edge in near, add it to the tree, mark it as visited (near = -1)
        int u = minWeightedNear(cost, near); // O(n)
        if (u == -1)
        {
            cout << "Graph is disconnected, No MST possible." << endl;
            tree.clear();
            return;
        }

        tree[i][0] = u, tree[i][1] = near[u];
        weight += cost[u][near[u]];
        near[u] = -1; // update after weight increment

        // now repeat but before that update the near array (changes will be in the neighbour vertices of the newly visited vertex 'u')
        for (int j = 0; j < n; j++) // O(n)
        {
            if (near[j] != -1 && cost[u][j] != INT_MAX) // condn for checking the neighbour of 'u'
            {
                if (cost[j][u] < cost[j][near[j]])
                {
                    near[j] = u;
                }
            }
        }
    }
}

int main()
{
    // un-directed & weighted graph's adjacency matrix (cost)
    //   A B C ...
    // A * * * ...
    // B * * * ...
    // C * * * ...
    vector<vector<int>> cost = {
        // connected
        {0, 28, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX},
        {28, 0, 16, INT_MAX, INT_MAX, INT_MAX, 14},
        {INT_MAX, 16, 0, 12, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 12, 0, 22, INT_MAX, 18},
        {INT_MAX, INT_MAX, INT_MAX, 22, 0, 25, 24},
        {10, INT_MAX, INT_MAX, INT_MAX, 25, 0, INT_MAX},
        {INT_MAX, 14, INT_MAX, 18, 24, INT_MAX, 0},

        // disconnected
        // {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        // {INT_MAX, 0, 3, 6, 5, INT_MAX, INT_MAX, INT_MAX},
        // {INT_MAX, 3, 0, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX},
        // {INT_MAX, 6, INT_MAX, 0, 7, INT_MAX, INT_MAX, INT_MAX},
        // {INT_MAX, 5, 4, 7, 0, INT_MAX, INT_MAX, INT_MAX},
        // {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 3, 1},
        // {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 3, 0, 2},
        // {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, 2, 0},
    };

    int n = cost.size(), weight = 0;
    vector<vector<int>> tree(n - 1, vector<int>(2));

    prims(cost, n, tree, weight);

    if (tree.size()) // will be set to '0' if cleared (disconnected graph)
    {
        cout << "Edges in Minimum Spanning Tree:" << endl;
        print(tree);
        cout << "Total Weight of MST: " << weight << endl;
    }

    return 0;
}