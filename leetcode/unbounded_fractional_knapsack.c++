#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// one item can be taken multiple times, so we will keep on taking the item until we have capacity to take it.
class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        double maxRatio = 0;
        for (int i = 0; i < val.size(); i++)
        {
            if (maxRatio < (double)val[i] / wt[i])
            {
                maxRatio = (double)val[i] / wt[i];
            }
        }

        return maxRatio * capacity;
    }
};

int main()
{
    Solution sol;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    cout << sol.fractionalKnapsack(val, wt, capacity) << endl;
}