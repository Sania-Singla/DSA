#include <iostream>
#include <vector>
#include <map>

using namespace std;

// O(n^2)
// void TS(vector<int> arr, int sum)
// {
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == sum)
//             {
//                 cout << "i = " << i << " j = " << j << endl;
//                 return;
//             }
//         }
//     }
// }

// O(n) + S(n)
void TS(vector<int> arr, int sum)
{
    // S(n)
    map<int, int> m;

    // O(n)
    for (int i = 0; i < arr.size(); i++)
    {
        m[sum - arr[i]] = i;
    }

    // O(n)
    for (int i = 0; i < arr.size(); i++)
    {
        if (m.find(arr[i]) != m.end() && m[arr[i]] != i)
        {
            cout << "i = " << m[arr[i]] << " j = " << i << endl;
            return;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int sum = 12;
    TS(arr, sum);
}