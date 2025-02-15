#include <iostream>
#include <vector>

using namespace std;

void print(const vector<string> &arr)
{
    for (string val : arr)
    {
        cout << val << "\t";
    }
    cout << endl;
}

bool safeToMove(const vector<vector<int>> mat, int x, int y, vector<vector<int>> &visited)
{
    return (x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && visited[x][y] != 1 && mat[x][y] != 1);
}

void ratInMaze(const vector<vector<int>> mat, int x, int y, const int dx, const int dy, vector<string> &possiblePaths, string &path, string &shortestPath, vector<vector<int>> &visited)
{
    if (x == dx && y == dy)
    {
        // you've reached the destination
        possiblePaths.push_back(path);
        if (path.length() < shortestPath.length() || shortestPath == "")
        {
            shortestPath = path;
        }
    }
    else
    {
        visited[x][y] = 1;

        // move up (x-1, y)
        if (safeToMove(mat, x - 1, y, visited))
        {
            path += 'U';
            ratInMaze(mat, x - 1, y, dx, dy, possiblePaths, path, shortestPath, visited);
            path.pop_back(); // backtracking
        }
        // move down (x+1, y)
        if (safeToMove(mat, x + 1, y, visited))
        {
            path += 'D';
            ratInMaze(mat, x + 1, y, dx, dy, possiblePaths, path, shortestPath, visited);
            path.pop_back(); // backtracking
        }
        // move left (x, y-1)
        if (safeToMove(mat, x, y - 1, visited))
        {
            path += 'L';
            ratInMaze(mat, x, y - 1, dx, dy, possiblePaths, path, shortestPath, visited);
            path.pop_back(); // backtracking
        }
        // move right (x, y+1)
        if (safeToMove(mat, x, y + 1, visited))
        {
            path += 'R';
            ratInMaze(mat, x, y + 1, dx, dy, possiblePaths, path, shortestPath, visited);
            path.pop_back(); // backtracking
        }

        visited[x][y] = 0; // backtracking
    }
}

int main()
{
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
    };

    int x, y, dx, dy;
    cout << "enter source x & y: ";
    cin >> x >> y;
    cout << "enter destination dx & dy: ";
    cin >> dx >> dy;

    if (mat[x][y] == 1 || mat[dx][dy] == 1)
    {
        return 0; // no possible path
    }
    else
    {
        int m = mat.size(), n = mat[0].size();
        string path = "", shortestPath = "";
        vector<string> possiblePaths;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        ratInMaze(mat, x, y, dx, dy, possiblePaths, path, shortestPath, visited);
        print(possiblePaths);
        cout << "Shortest path: " << shortestPath << ", number of steps required: " << shortestPath.length() << endl;
    }
}