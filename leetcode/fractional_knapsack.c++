#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    struct Item
    {
        int profit;
        int weight;
        double ratio;
    };

    struct Comparator
    {
        bool operator()(Item &a, Item &b)
        {
            return a.ratio > b.ratio; // descending order
        }
    };

public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        vector<Item> items;
        for (int i = 0; i < val.size(); i++)
        {
            items.push_back({val[i], wt[i], (double)val[i] / wt[i]});
        }

        sort(items.begin(), items.end(), Comparator());

        double ans = 0;

        for (int i = 0; i < val.size(); i++)
        {
            if (items[i].weight <= capacity)
            {
                ans += items[i].profit;
                capacity -= items[i].weight;
            }
            else
            {
                ans += items[i].ratio * capacity;
                break;
            }
        }
        return ans;
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