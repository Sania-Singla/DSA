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

// O(n^3)
void APSP(vector<vector<int>> A, int n)
{
    // taking vtx 'k' as an intermediate vtx hence number of matrices A^0, A^1 ... A^n-1
    // and since we are using A^0 from calculating A^1, A^1 for calculating A^2 so that means ultimately we will we having all as the intermediate vertices
    // so final matrix will be our answer

    for (int k = 0; k < n; k++) // to change matrix number A^0, A^1, ...
    {
        for (int i = 0; i < n; i++) // to explore the matrix of n^2 number of elements
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX && A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }

        cout << "intermediate matrix:" << endl;
        print(A);
    }

    cout << "final solution:" << endl;
    print(A);
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
}