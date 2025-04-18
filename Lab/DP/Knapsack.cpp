// 0/1 knapsack problem (either take it or leave it)

#include <iostream>
#include <vector>
using namespace std;

vector<double> profitByWeight(const vector<int> &profits, const vector<int> &weights)
{
    int n = profits.size();
    vector<double> pbyw(n);
    for (int i = 0; i < n; i++)
    {
        pbyw[i] = (double)profits[i] / weights[i];
    }
    return pbyw;
}

int Knapsack(const vector<int> &objects, const vector<int> &profits, const vector<int> &weights, vector<int> &includedObjects, int capacity)
{
    int n = objects.size();
    vector<double> pbyw = profitByWeight(profits, weights);
}

int main()
{
    vector<int> objects = {1, 2, 3, 4, 5}, profits = {10, 5, 15, 7, 6}, weights = {2, 3, 5, 7, 1};
    int n = objects.size(), capacity = 10;

    vector<int> includedObjects(n, 0);

    int maxProfit = Knapsack(objects, profits, weights, includedObjects, capacity);

    cout << "the max profit possible is: " << maxProfit << endl;
}