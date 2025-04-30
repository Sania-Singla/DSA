#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int MCM(vector<int> dim, int n)
{
    vector<vector<int>> table(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++) // l = chain length
    {
        for (int i = 0; i < n - l; i++)
        {
            int j = i + l;
            table[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++)
            {
                int q = table[i][k] + table[k][j] + dim[i] * dim[k] * dim[j];
                table[i][j] = min(table[i][j], q);
            }
        }
    }

    return table[0][n - 1];
}

int main()
{
    vector<int> dim = {1, 2, 3, 4}; // means matrices: A1(1x2), A2(2x3), A3(3x4)
    cout << "The minimum number of multiplications to be performed = "
         << MCM(dim, dim.size()) << endl;
    return 0;
}
