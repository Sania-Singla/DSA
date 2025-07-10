#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &x)
{
    for (int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}

// we are filling the kth position in x with i
bool canVisit(vector<vector<int>> graph, vector<int> x, int k, int i)
{
    // so if we dont have an edge with what we filled on previous position then return false;
    if (k > 0 && graph[x[k - 1]][i] == 0)
    {
        return false;
    }
    // if last position check cycle should existance
    else if (k == graph.size() - 1 && graph[i][x[0]] == 0)
    {
        return false;
    }
    else
    {
        // check if already visited
        for (int j = 0; j < k; j++)
        {
            if (x[j] == i)
            {
                return false;
            }
        }
        return true;
    }
}

void HC(vector<vector<int>> graph, int n, vector<int> &x, int k)
{
    // k is just the position in x we are trying to fill right now
    if (k < n)
    {
        for (int i = 0; i < n; i++)
        {

            // cout << "k: " << k << ' ';

            if (canVisit(graph, x, k, i))
            {
                // cout << "i: " << i << ' ';

                x[k] = i;
                if (k == n - 1)
                {
                    cout << "GOT A SOLUTION: ";
                    print(x);
                    // exit(0); // can't use return;
                }
                HC(graph, n, x, k + 1);
            }
            // cout << "B ";
        }
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 0},
    };

    int n = graph.size();
    vector<int> x(n, -1);
    HC(graph, n, x, 0);
}