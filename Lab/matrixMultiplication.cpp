#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>> &arr)
{
    for (const vector<int> &row : arr)
    {
        for (const int &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

// O(m*p*n)
vector<vector<int>> multiply(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2)
{
    // m*n & n1*p
    int m = mat1.size(), n = mat1[0].size(), n1 = mat2.size(), p = mat2[0].size();
    if (n != n1)
    {
        cout << "matrices can't be multiplied." << endl;
        return {};
    }
    else
    {
        vector<vector<int>> ans(m, vector<int>(p));
        // O(m)
        for (int i = 0; i < m; i++)
        {
            // O(p)
            for (int j = 0; j < p; j++)
            {
                int val = 0;
                // O(n)
                for (int k = 0; k < n; k++)
                {
                    val += mat1[i][k] * mat2[k][j];
                }
                ans[i][j] = (val);
            }
        }
        return ans;
    }
}

int main()
{
    // mat1 * mat2 (order matters)
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
    };
    vector<vector<int>> mat2 = {
        {7, 8},
        {9, 10},
        {11, 12},
    };
    vector<vector<int>> ans = multiply(mat1, mat2);
    print(ans);
    return 0;
}