// ⭐ Conditions:
// magic constant (sum) S = n * (n^2 + 1) / 2
// square matrix
// distinct elements from range (1 - n*n) (all should be present)

#include <iostream>
#include <vector>
using namespace std;

void generateMagicSq(vector<vector<int>> &magicSq, int i, int j, int n, int currVal)
{
    // Base case: stop when all numbers are placed (1 - n*n)
    if (currVal > n * n)
    {
        return;
    }

    // both row and col are out of bounds, move down one row in the same col
    if (i < 0 && j < 0)
    {
        i += 2;
        j += 1;
    }
    // only row out of bound (wrap to last row)sea
    else if (i < 0)
    {
        i = n - 1; // i += n; as i = -1
    }
    // only col out of bound (wrap to last col)
    else if (j < 0)
    {
        j = n - 1; // j += n; as j = -1
    }

    // If the cell is already filled, move down one row in the same col
    if (magicSq[i][j] != 0)
    {
        i += 2;
        j += 1;
        return generateMagicSq(magicSq, i, j, n, currVal);
    }

    // Place the current value in the cell
    magicSq[i][j] = currVal;

    // call for the next number, moving diagonally up (i-1) and to the left (j-1)
    generateMagicSq(magicSq, i - 1, j - 1, n, currVal + 1);
}

int main()
{
    int n;
    cout << "Enter the order of the magic square (odd): ";
    cin >> n;

    // Magic squares are only defined for odd orders
    if (n % 2 == 0 || n < 1)
    {
        cout << "Order must be an odd positive integer!" << endl;
        return 0;
    }

    vector<vector<int>> magicSq(n, vector<int>(n, 0)); // Initialize the matrix with 0

    /* ⭐ can start from mid of 1st and last row or col the logic will change when moving down/left/right/up instead of diagonally on filled or both out of bound cases */
    // Start at the middle col & first row
    int row = 0, col = n / 2;
    magicSq[row][col] = 1;

    generateMagicSq(magicSq, row - 1, col - 1, n, 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << magicSq[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}