#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(const auto &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "stage " << i + 1 << " has " << arr[i] << " vertices." << endl;
    }
}

bool present(vector<int> &arr, int x)
{
    for (int val : arr)
    {
        if (val == x)
        {
            return true;
        }
    }
    return false;
}

vector<int> numberOfVerticesStageWise(const vector<vector<int>> &mtx, int n)
{
    vector<int> vertices, currNodeConnections;
    vertices.push_back(1); // source
    int currNode = 0;

    for (int i = 0; i < n; i++)
    {
        if (mtx[currNode][i] != INT_MAX && mtx[currNode][i] != 0)
        {
            if (!present(currNodeConnections, i))
            {
                currNodeConnections.push_back(i);
            }
        }
    }

    vertices.push_back(currNodeConnections.size());

    vector<int> nextStageConnections;

    while (currNode != n - 1)
    {
        for (int i = 0; i <= nextStageConnections.size(); i++)
        {
            currNode = currNodeConnections.front();
            currNodeConnections.erase(currNodeConnections.begin());

            for (int i = 0; i < n; i++)
            {
                if (mtx[currNode][i] != INT_MAX && mtx[currNode][i] != 0)
                {
                    if (!present(currNodeConnections, i))
                    {
                        currNodeConnections.push_back(i);
                        nextStageConnections.push_back(i);
                    }
                }
            }
        }
        vertices.push_back(nextStageConnections.size());
        nextStageConnections.clear();
    }
    return vertices;
}

int main()
{
    //  1 2 3 ...
    // 1 * * *
    // 2 * * *
    // 3 * * *
    vector<vector<int>> mtx = {
        // demo multi-stage graph
        {0, 2, 5, 6, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, INT_MAX, 7, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 1, 9, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 6, 3, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 6},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 4},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},

    };

    vector<int> vertices = numberOfVerticesStageWise(mtx, mtx.size());
    print(vertices);
    return 0;
}

// {0, 7, 3, 1, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
// {INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, 8, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
// {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 6, INT_MAX, 10, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
// {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 2, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 14, 13, INT_MAX, INT_MAX},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 12, 6, INT_MAX},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 4},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 7},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 9},
// {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},