#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(auto arr)
{
    for (auto row : arr)
    {
        for (int val : row)
        {
            if (val == INT_MAX)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void APSP(vector<vector<int>> A, int n)
{
    for (int k = 0; k < n; k++) // change matrix number A^0 A^1 ...
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX && A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }

        print(A);
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0},
    };

    APSP(graph, graph.size());
    return 0;
}