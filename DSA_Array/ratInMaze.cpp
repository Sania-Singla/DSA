#include <iostream>
#include <vector>
using namespace std;

bool isSafeToMove(int x, int y, int m, int n, vector<vector<int>> mat, vector<vector<int>> visited)
{
    if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == 0 && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, int dx, int dy, int m, int n, vector<vector<int>> mat, vector<vector<int>> &visited, string & minPath, string &path)
{
    if (x == dx && y == dy)
    {
        // ans.push_back(path);
        if(minPath.empty() || path.length() < minPath.length()) {
            minPath = path;
        }
        return;
    }
    else
    {
        visited[x][y] = 1;
        // move Left
        if (isSafeToMove(x, y + 1, m, n, mat, visited))
        {
            path.push_back('L');
            solve(x, y, dx, dy, m, n, mat, visited, minPath, path);
            path.pop_back();
        }
        // move Right
        if (isSafeToMove(x, y - 1, m, n, mat, visited))
        {
            path.push_back('R');
            solve(x, y, dx, dy, m, n, mat, visited, minPath, path);
            path.pop_back();
        }
        // move Up
        if (isSafeToMove(x + 1, y, m, n, mat, visited))
        {
            path.push_back('U');
            solve(x, y, dx, dy, m, n, mat, visited, minPath, path);
            path.pop_back();
        }
        // move Down
        if (isSafeToMove(x - 1, y, m, n, mat, visited))
        {
            path.push_back('D');
            solve(x, y, dx, dy, m, n, mat, visited, minPath, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
}

int main()
{
    // order of matrix
    int m, n;
    cout << "enter order m * n" << endl;
    cin >> m >> n;
    // creating the matrix
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter element for j & i = " << j << "  " << i << endl;
            cin >> mat[i][j];
        }
        cout << endl;
    }

    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    // source
    int x, y;
    cin >> x >> y;
    // destination
    int dx, dy;
    cin >> dx >> dy;
    if (mat[x][y] == 1)
    {
        return 0;
    }
    else
    {
        string path = "";
      	string minPath = "";
      	solve(x, y, dx, dy, m, n, mat, visited, minPath, path);
      	// return the minimum path from ans (which contains all the possible paths)
      	cout << "min path is :" << minPath << "number of steps are:"<<minPath.length()<<endl;
    }
}