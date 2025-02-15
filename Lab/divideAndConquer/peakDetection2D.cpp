// find peak ( can be multiple )

#include <iostream>
#include <vector>
using namespace std;

int maxElRow(vector<vector<int>> matrix, int midCol)
{
    int max = matrix[0][midCol];
    int row = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][midCol] > max)
        {
            max = matrix[i][midCol];
            row = i;
        }
    }

    return row;
}

// Recursive
void peak(vector<vector<int>> matrix, int s, int e, vector<int> &ans)
{
    int midCol = s + ((e - s) / 2);
    int targetRow = maxElRow(matrix, midCol);
    int target = matrix[targetRow][midCol];

    if (midCol - 1 >= s && matrix[targetRow][midCol - 1] >= target)
    {
        return peak(matrix, s, midCol - 1, ans);
    }
    else if (midCol + 1 <= e && matrix[targetRow][midCol + 1] >= target)
    {
        return peak(matrix, midCol + 1, e, ans);
    }
    else
    {
        ans[0] = targetRow;
        ans[1] = midCol;
        return;
    }
}

int main()
{
    // initialize a 2D matrix
    vector<vector<int>> matrix = {
        {41, 8, 2, 48, 18},
        {16, 15, 9, 7, 44},
        {48, 35, 6, 38, 28},
        {3, 2, 14, 15, 33},
        {39, 36, 13, 46, 42},
    };

    int rowNm = matrix.size();
    int colNum = matrix[0].size();

    vector<int> ans = {0, 0};
    peak(matrix, 0, colNum - 1, ans);
    cout << "row" << ans[0] << "col" << ans[1];
}