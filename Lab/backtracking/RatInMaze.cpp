#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<vector<int>> &maze, vector<string> &answer, int n, int x, int y, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        answer.push_back(path);
        path = "";
        return;
    }

    if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0)
        return;

    maze[x][y] = 0; // mark as visited

    path.push_back('D');
    solve(maze, answer, n, x + 1, y, path); // down
    path.pop_back();

    path.push_back('L');
    solve(maze, answer, n, x, y - 1, path); // left
    path.pop_back();

    path.push_back('R');
    solve(maze, answer, n, x, y + 1, path); // right
    path.pop_back();

    path.push_back('U');
    solve(maze, answer, n, x - 1, y, path); // up
    path.pop_back();

    maze[x][y] = 1; // restore (backtrack)
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    // code here
    int n = maze.size();
    vector<string> answer;

    solve(maze, answer, n, 0, 0, "");

    return answer;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };

    vector<string> answers = ratInMaze(maze);

    for (string path : answers)
    {
        cout << path << " ";
    }
}