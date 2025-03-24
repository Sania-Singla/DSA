// #ifndef NO_OF_STAGES_H
// #define NO_OF_STAGES_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// O(n^2)
int numberOfStages(const vector<vector<int>> &mtx, int n)
{
    int k = 1, currNode = 0;
    while (currNode != n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (mtx[currNode][i] != INT_MAX && mtx[currNode][i] != 0)
            {
                k++, currNode = i;
                break;
            }
        }
    }
    return k;
}

int main()
{
    //  0 1 2 ...
    // 0 * * *
    // 1 * * *
    // 2 * * *
    vector<vector<int>> mtx = {
        // demo multi-stage graph
        {0, 7, 3, 1, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, 8, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 6, INT_MAX, 10, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 2, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 14, 13, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 12, 6, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, 4},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 7},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 9},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
    };
    int k = numberOfStages(mtx, mtx.size());
    cout << "number of stages: " << k << endl;
    return 0;
}

// #endif
