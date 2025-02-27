#include <iostream>
#include <vector>
#include <math.h>

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

int nextPowerOfTwo(int val)
{
    int p = 1;
    while (p < val)
    {
        p *= 2;
    }
    return p;
}

void padMatrix(vector<vector<int>> &mat, int newSize)
{
    mat.resize(newSize, vector<int>(newSize, 0));

    for (auto &row : mat)
    {
        row.resize(newSize, 0);
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2)
{
    // order should be same
    int n = mat1.size();
    vector<vector<int>> sum(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return sum;
}

vector<vector<int>> subMatrices(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2)
{
    // order should be same
    int n = mat1.size();
    vector<vector<int>> sub(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sub[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return sub;
}

// T(n) = 7T(n/2) + O(n^2)
// T(n) = O(n^2.81) (using master's thm)
vector<vector<int>> stressen(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2)
{
    int n = mat1.size();
    // base case for 1*1
    if (n == 1)
    {
        return {{mat1[0][0] * mat2[0][0]}};
    }
    else
    {
        int half = n / 2;

        // sub matrices for mat1
        vector<vector<int>> A(half, vector<int>(half, 0)), B(half, vector<int>(half, 0)), C(half, vector<int>(half, 0)), D(half, vector<int>(half, 0));
        // sub matrices for mat2
        vector<vector<int>> E(half, vector<int>(half, 0)), F(half, vector<int>(half, 0)), G(half, vector<int>(half, 0)), H(half, vector<int>(half, 0));

        // populating these sub matrices
        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < half; j++)
            {
                // for mat1
                A[i][j] = mat1[i][j];
                B[i][j] = mat1[i][j + half];
                C[i][j] = mat1[i + half][j];
                D[i][j] = mat1[i + half][j + half];

                // for mat2
                E[i][j] = mat2[i][j];
                F[i][j] = mat2[i][j + half];
                G[i][j] = mat2[i + half][j];
                H[i][j] = mat2[i + half][j + half];
            }
        }

        // recursion (compute the 7 products)
        // 7 * T(n/2)
        vector<vector<int>> P = stressen(addMatrices(A, D), addMatrices(E, H));
        vector<vector<int>> Q = stressen(addMatrices(C, D), E);
        vector<vector<int>> R = stressen(A, subMatrices(F, H));
        vector<vector<int>> S = stressen(D, subMatrices(G, E));
        vector<vector<int>> T = stressen(addMatrices(A, B), H);
        vector<vector<int>> U = stressen(subMatrices(C, A), addMatrices(E, F));
        vector<vector<int>> V = stressen(subMatrices(B, D), addMatrices(G, H));

        // add the products (compute the 4 sums)
        // 4 * O((n/2)^2) => O(n^2)
        vector<vector<int>> s00 = addMatrices(subMatrices(addMatrices(P, S), T), V);
        vector<vector<int>> s01 = addMatrices(R, T);
        vector<vector<int>> s10 = addMatrices(Q, S);
        vector<vector<int>> s11 = subMatrices(addMatrices(addMatrices(P, R), U), Q);

        vector<vector<int>> ans(n, vector<int>(n));

        // assign the sum into the final answer;
        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < half; j++)
            {
                ans[i][j] = s00[i][j];
                ans[i][j + half] = s01[i][j];
                ans[i + half][j] = s10[i][j];
                ans[i + half][j + half] = s11[i][j];
            }
        }
        return ans;
    }
}

// using Divide & Conquer
vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
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
        int newSize = max(max(m, n), p);   // for square matrix
        newSize = nextPowerOfTwo(newSize); // for power of 2 size
        padMatrix(mat1, newSize);
        padMatrix(mat2, newSize);

        cout << "padded mat1: " << endl;
        print(mat1);
        cout << "padded mat2: " << endl;
        print(mat2);

        vector<vector<int>> ans = stressen(mat1, mat2);

        // Trim the padded rows/columns
        vector<vector<int>> trimmedAns(m, vector<int>(p));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
            {
                trimmedAns[i][j] = ans[i][j];
            }
        }

        return trimmedAns;
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
    cout << "result: " << endl;
    print(ans);
}
