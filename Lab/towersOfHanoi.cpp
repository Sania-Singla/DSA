#include <iostream>
using namespace std;

static int c; // for total number of iterations

void TOH(int n, char F, char A, char T)
{
    c++;
    if (n == 1)
    {

        cout << "move disc " << n << " from " << F << " to " << T << endl;
    }
    else
    {
        TOH(n - 1, F, T, A);
        cout << "move disc " << n << " from " << F << " to " << T << endl;
        TOH(n - 1, A, F, T);
    }
}

int main()
{
    int n = 1;
    while (n <= 10)
    {
        c = 0;
        cout << "n: " << n << endl;
        TOH(n, 'F', 'A', 'T');
        cout << "no. of iterations: " << c << endl;
        n++;
    }
}