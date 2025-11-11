#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

bool canColor(int k, int i, vector<int> x, vector<vector<int>> rooms)
{
    for (int j = 0; j < k; j++)
    {
        // those who are neighbours(t) of k (having an edge with k) should be having x[t] = i
        if (rooms[k][j] && x[j] == i)
        {
            return false;
        }
    }
    return true;
}

void FC(int k, vector<vector<int>> rooms, int m, vector<int> &x, int n)
{
    if (k < n)
    {
        for (int i = 0; i < m; i++)
        {
            // cout << "k: " << k << ' ';

            if (canColor(k, i, x, rooms))
            {
                // cout << "i: " << i << ' ';

                x[k] = i;
                if (k == n - 1)
                {
                    cout << "GOT A SOLUTION: ";
                    print(x);
                    // exit(0);
                }
                FC(k + 1, rooms, m, x, n);
            }
        }
        // cout << "B" << endl;
    }
}

int main()
{
    // graph representing room connections
    vector<vector<int>> rooms = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
    };
    int m = 3, n = rooms.size(); // m = number of colors
    vector<int> x(n);            // index => room number & value => color assigned
    FC(0, rooms, m, x, n);
}