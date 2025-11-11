#include <iostream>
#include <vector>

using namespace std;

int RatInMaze(int m, int n, int i, int j, vector<vector<int>> &t)
{
    if (i >= m || j >= n)
    { // no need to check i < 0 || j < 0
        return 0;
    }

    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    // no need of visited array and path string (pushing/popping)

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    // Right
    int rightCount = RatInMaze(m, n, i, j + 1, t);

    // Bottom
    int bottomCount = RatInMaze(m, n, i + 1, j, t);

    t[i][j] = rightCount + bottomCount;
    return t[i][j];
}

int main()
{
    int m = 3, n = 4;
    vector<vector<int>> t(m, vector<int>(n, -1));
    cout << RatInMaze(m, n, 0, 0, t);
}