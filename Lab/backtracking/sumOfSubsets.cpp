#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &x)
{
    for (int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}

bool canInclude(int k, int m, int S, int R, vector<int> arr)
{
    if (S + arr[k] > m || S + R < m)
    {
        return false;
    }
    return true;
}

// checking can we include kth value or not
void SOS(int k, const int m, const int n, vector<int> arr, vector<int> &x, int S, int R)
{
    if (k < n)
    {
        if (canInclude(k, m, S, R, arr))
        {
            x[k] = 1;
            if (S + arr[k] == m)
            {
                cout << "GOT A SOLUTION: ";
                print(x);
                // exit(0);
            }
            SOS(k + 1, m, n, arr, x, S + arr[k], R - arr[k]);
        }
        x[k] = 0;
        SOS(k + 1, m, n, arr, x, S, R - arr[k]);
    }
}

int main()
{
    vector<int> arr = {5, 10, 12, 13, 15, 18};
    int m = 30, n = arr.size(), S = 0, R = 0;
    for (int val : arr)
    {
        R += val;
    }
    vector<int> x(n, 0);
    SOS(0, m, n, arr, x, S, R);
}