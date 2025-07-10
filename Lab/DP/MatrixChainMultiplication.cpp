#include <vector>
#include <iostream>
#include <climits>

using namespace std;

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
    cout << endl;
}

// O(n^3)
int MCM(vector<int> dim, int n)
{
    vector<vector<int>> C(n, vector<int>(n, 0));
    vector<vector<int>> S(n, vector<int>(n, 0));

    for (int d = 1; d < n - 1; d++) // denotes the difference between two matrix dimensions
    {
        for (int i = 1; i < n - d; i++) // i value needed to make j = i+d;
        {
            int j = i + d;

            int min = INT_MAX;
            for (int k = i; k < j; k++) // to vary k value to denote diff. parenthesis
            {
                int q = C[i][k] + C[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if (q < min)
                {
                    min = q;
                    S[i][j] = k;
                }
            }
            C[i][j] = min;
        }
    }

    print(C);
    print(S);
    return C[1][n - 1];
}

int main()
{
    vector<int> dim = {3, 2, 4, 2, 5};
    cout << "minimum number of multiplications performed = " << MCM(dim, dim.size()) << endl;
}