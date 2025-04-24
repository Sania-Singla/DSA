#include <iostream>
#include <vector>

using namespace std;

int c = 0;

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

void NQ(int k, vector<int> &x, bool &done)
{
    int n = x.size();
    if (k < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (done)
            {
                break;
            }

            cout << "k: " << k << endl;
            c++;
            if (canPlace(k, i, x))
            {
                cout << "i: " << i << endl;
                x[k] = i;
                if (k == n - 1)
                {
                    cout << "GOT A SOLUTION: ";
                    print(x);
                    done = true; // we only need one solution
                }
                NQ(k + 1, x, done);
            }
        }
        cout << "B" << endl;
    }
}

int main()
{
    int n = 4;
    c = 0;
    bool done = false;
    vector<int> x(n);
    NQ(0, x, done);
    cout << "Number of iterations: " << c << endl;
}