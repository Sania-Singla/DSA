#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, weight;
};

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

class MinHeap
{
private:
    vector<Edge> heap;

    void heapifyUp(int idx)
    {
        if (idx > 0)
        {
            int parent = (idx - 1) / 2;
            if (heap[parent].weight > heap[idx].weight)
            {
                swap(heap[parent], heap[idx]);
                heapifyUp(parent); // parent is still by position the same only the data changed
            }
        }
    }

    void heapifyDown(int idx)
    { // for deletion
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < heap.size() && heap[left].weight < heap[smallest].weight)
        {
            smallest = left;
        }
        if (right < heap.size() && heap[right].weight < heap[smallest].weight)
        {
            smallest = right;
        }

        if (smallest != idx)
        {
            swap(heap[idx], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    bool isEmpty() const
    {
        return heap.empty();
    }

    void insert(Edge edge)
    {
        heap.push_back(edge);
        heapifyUp(heap.size() - 1);
    }

    Edge top()
    {
        if (heap.empty())
        {
            return {-1, -1, INT_MAX};
        }
        else
        {
            Edge minEdge = heap[0];
            heap[0] = heap.back(); // swap root with last element
            heap.pop_back();       // remove last element
            if (!heap.empty())
            {
                heapifyDown(0);
            }
            return minEdge;
        }
    }
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
    // create min heap
    MinHeap minHeap;

    for (Edge edge : edges)
    {
        minHeap.insert(edge);
    }

    vector<vector<int>> tree;
    vector<int> parent(n, -1);
    vector<int> rank(n, 0);

    int totalWeight = 0;

    while (!minHeap.isEmpty() && tree.size() < n - 1)
    {
        Edge minEdge = minHeap.top();
        int u = minEdge.u, v = minEdge.v;

        if (Find(parent, u) != Find(parent, v))
        {
            Union(parent, rank, u, v);
            totalWeight += minEdge.weight;
            tree.push_back({u, v});
        }
    }

    return tree;
}

int main()
{
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
