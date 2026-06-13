#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};

    sort(arr.begin(), arr.end());

    int len = 1, maxLen = 1;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            continue;
        else if (arr[i] + 1 == arr[i + 1])
        {
            len++;
        }
        else
        {
            maxLen = max(len, maxLen);
            len = 1;
        }
    }

    maxLen = max(len, maxLen);

    cout << maxLen;
}