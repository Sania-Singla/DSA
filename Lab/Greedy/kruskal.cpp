#include <iostream>
using namespace std;
#define N 5
#define E 7
struct Edge
{
    int src, dest, weight;
};
void minHeapify(Edge arr[], int n, int i)
{
    int left = (2 * i) + 1, right = (2 * i) + 2, smallest = i;
    if (left < n && arr[left].weight < arr[smallest].weight)
        smallest = left;
    if (right < n && arr[right].weight < arr[smallest].weight)
        smallest = right;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void buildMinHeap(Edge arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}
void heapSort(Edge arr[], int n)
{
    buildMinHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    // Reverse the array to get ascending order
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - 1 - i]);
}
int find(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]); // Path compression
    return parent[i];
}
void Union(int parent[], int rank[], int x, int y)
{
    int rootX = find(parent, x), rootY = find(parent, y);
    if (rootX != rootY)
    {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}
void Kruskal(Edge edges[], int n, int e)
{
    int parent[N], rank[N] = {0}, t[N - 1][2], minCost = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i; // Initialize parent array correctly

    heapSort(edges, e);

    int i = 0, j = 0;
    while (i < n - 1 && j < e)
    {
        int u = edges[j].src, v = edges[j].dest, w = edges[j].weight;
        int rootU = find(parent, u), rootV = find(parent, v);
        if (rootU != rootV)
        {
            t[i][0] = u, t[i][1] = v, minCost += w;
            Union(parent, rank, rootU, rootV);
            i++;
        }
        j++;
    }
    if (i != n - 1)
    {
        cout << "No MST exists!\n";
        return;
    }
    cout << "MST Edges:\n";
    for (int k = 0; k < n - 1; k++)
        cout << t[k][0] << " " << t[k][1] << endl;
    cout << "Total Minimum Cost: " << minCost << endl;
}
int main()
{
    Edge edges[E] = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}};
    Kruskal(edges, N, E);
    return 0;
}