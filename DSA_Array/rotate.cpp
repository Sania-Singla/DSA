// rotate the array by K units to the right
#include <iostream>
#include <stack>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// O(n^2) (BAD)
// void rotate(int *arr, int n, int k)
// {
//     for (int j = 0; j < k; j++)
//     {
//         int i = n - 1;
//         while (i > 0)
//         {
//             swap(arr[i], arr[i - 1]);
//             i--;
//         }
//     }
// }

// O(n^2) but S(n) (WORSE)
// void insertAtBottom(stack<int> &s, int val)
// {
//     if (s.empty())
//     {
//         s.push(val);
//     }
//     else
//     {
//         int topEl = s.top();
//         s.pop();

//         insertAtBottom(s, val);
//         s.push(topEl);
//     }
// }

// void rotate(int *arr, int n, int k)
// {
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         s.push(arr[i]);
//     }

//     for (int j = 0; j < k; j++)
//     {
//         int topEl = s.top();
//         s.pop();
//         insertAtBottom(s, topEl);  // O(n)
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         arr[n - i] = s.top();
//         s.pop();
//     }
// }

// O(n) but S(n)
// void rotate(int *arr, int n, int k)
// {
//     stack<int> s;
//     for (int i = n - k; i < n; i++)
//     {
//         s.push(arr[i]);
//     }

//     for (int i = 0; i < n - k; i++)
//     {
//         s.push(arr[i]);
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         arr[i] = s.top();
//         s.pop();
//     }
// }

// O(n) (GREAT)
void reverse(int *arr, int s, int e)
{
    int i = s, j = e;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}

void rotate(int *arr, int n, int k)
{
    reverse(arr, 0, n - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, k - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    rotate(arr, n, k % n); // when k == multiple of n the array is same
    print(arr, n);
}