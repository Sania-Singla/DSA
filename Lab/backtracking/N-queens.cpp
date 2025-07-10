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

bool canPlace(int k, int i, vector<int> x)
{
    for (int j = 0; j < k; j++)
    {
        if (i == x[j] || abs(j - k) == abs(x[j] - i))
        {
            return false;
        }
    }
    return true;
}

void NQ(int k, vector<int> &x, int n)
{
    if (k < n)
    {
        for (int i = 0; i < n; i++)
        {
            // cout << "k: " << k << endl;
            if (canPlace(k, i, x))
            {
                // cout << "i: " << i << endl;
                x[k] = i;
                if (k == n - 1)
                {
                    cout << "GOT A SOLUTION: ";
                    print(x);
                    // exit(0); // can't use return;
                }
                NQ(k + 1, x, n);
            }
            // else
            // {
            //     cout << "B" << endl;
            // }
        }
    }
}

int main()
{
    int n = 4;
    vector<int> x(n);
    NQ(0, x, n);
}