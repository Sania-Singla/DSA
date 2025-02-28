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

void prims(const vector<vector<int>> &cost, vector<vector<int>> &tree, const int &n, int &weight)
{
    vector<int> near(n, -1);

    // find the first minimum edge (k,l)
    int k = -1, l = -1, minCost = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] < minCost)
            {
                minCost = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    // push k & l to visited (near = 0) & add the edge in the tree
    near[k] = 0;
    near[l] = 0;
    tree[0][0] = k;
    tree[0][1] = l;

    weight = cost[k][l]; // final total weight of the tree

    // now for each un-visited node (near != 0) find its nearer node in visited
    for (int i = 0; i < n; i++)
    {
        if (near[i] != 0)
        {
            near[i] = (cost[i][k] < cost[i][l]) ? k : l;
        }
    }

    // fill rest of the tree (0th row is filled already)
    for (int i = 1; i < n - 1; i++) // tree has a size of (n-1)*2
    {
        // find the minimum edge again from the un-visited nodes
        int minCost = INT_MAX, u = -1;
        for (int j = 0; j < n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < minCost)
            {
                minCost = cost[j][near[j]];
                u = j;
            }
        }

        tree[i][0] = u; // add the new edge to the tree
        tree[i][1] = near[u];
        weight += minCost; // increment the weight
        near[u] = 0;       // add this to visited now

        for (int j = 0; j < n; j++)
        {
            if (near[j] != 0 && cost[u][j] != 0 && cost[u][j] != INT_MAX && cost[u][j] < cost[j][near[j]])
            {
                near[j] = u;
            }
        }
    }
}

int main()
{
    // un-directed & weighted graph's adjacency matrix (cost)
    //   A B C D E F
    // A * * * * * *
    // B * * * * * *
    // C * * * * * *
    // D * * * * * *
    // E * * * * * *
    // F * * * * * *
    vector<vector<int>> cost = {
        {0, 10, 2, INT_MAX, INT_MAX, 2},
        {10, 0, INT_MAX, INT_MAX, 9},
        {2, INT_MAX, 0, 5, INT_MAX, 1},
        {INT_MAX, INT_MAX, 5, 0, 7, 6},
        {INT_MAX, 9, INT_MAX, 7, 0, INT_MAX},
        {2, 8, 1, 6, INT_MAX, 0},
    };

    int n = cost.size(), weight = 0;
    vector<vector<int>> tree(n - 1, vector<int>(2));

    prims(cost, tree, n, weight);

    cout << "Edges in Minimum Spanning Tree:\n";
    print(tree);
    cout << "Total Weight of MST: " << weight << endl;

    return 0;
}