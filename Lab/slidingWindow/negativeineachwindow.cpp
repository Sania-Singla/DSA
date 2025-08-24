#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            if (arr[i] < 0)
            {
                q.push(arr[i]);
            }
        }

        if (!q.empty())
        {
            ans.push_back(q.front());
        }
        else
        {
            ans.push_back(0);
        }

        for (int i = 1; i < arr.size() - k + 1; i++)
        {
            if (arr[i + k - 1] < 0)
            {
                q.push(arr[i + k - 1]);
            }

            if (arr[i - 1] < 0)
            {
                q.pop();
            }

            if (!q.empty())
            {
                ans.push_back(q.front());
            }
            else
            {
                ans.push_back(0);
            }
        }

        return ans;
    }
};