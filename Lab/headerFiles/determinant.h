#ifndef DETERMINANT_H
#define DETERMINANT_H

#include <iostream>
#include <vector>

using namespace std;

// * although sq. mtx but just to be conceptually clear i've used n & m separately but in this case n = m

// O(n^2)
vector<vector<int>> subMatrix(const vector<vector<int>> &mat, const int &row, const int &col)
{
    // give me a matrix removing this row & col
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> subMat(m - 1, vector<int>(n - 1));
    int sub_i = 0;
    for (int i = 0; i < m; i++)
    {
        if (i != row)
        {
            int sub_j = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != col)
                {
                    subMat[sub_i][sub_j] = mat[i][j];
                    sub_j++;
                }
            };
            sub_i++;
        }
    }
    return subMat;
}

// T(n) = n(T(n-1) + O(n^2))
// O(n*(n! + n^2)) => O(n*n!) => O(n!)
int determinant(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    if (m == 1)
    {
        return mat[0][0];
    }
    else if (m == 2)
    {
        return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
    }
    else
    {
        int ans = 0;
        // O(n)
        for (int i = 0; i < n; i++)
        {
            int sign = i % 2 == 0 ? 1 : -1;
            int term = sign * mat[0][i];
            vector<vector<int>> subMat = subMatrix(mat, 0, i); // O(n^2) & S(n^2)
            ans += term * determinant(subMat);                 // O(n!)
        }
        return ans;
    }
}

// int main()
// {
//     // determinant is only defined for square matrices (n*n)
//     vector<vector<int>> mat = {
//         {1, -2, 3},
//         {2, 0, 3},
//         {1, 5, 4},
//     };

//     cout << "determinant of given matrix is: " << determinant(mat) << endl;
// }

#endif