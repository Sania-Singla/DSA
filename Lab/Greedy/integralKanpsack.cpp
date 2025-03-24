// an array of objects and its associated profit and weight array is given along with a bag(knapsack) of given capacity
// we have to fill the bag with objects of total weight <= capacity and max profit
// ** Remember: the objects are NOT dividable which means u must take the complete weight given ex: washing machine, hence in the end the capacity may not be 0 **

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(const auto &arr)
{
    for (auto val : arr)
    {
        cout << val << "\t";
    }
    cout << endl;
}

bool allTrue(const vector<bool> &ingoredIndices)
{
    for (int i = 0; i < ingoredIndices.size(); i++)
    {
        if (!ingoredIndices[i])
        {
            return false;
        }
    }
    return true;
}

void calculateProfitByWeight(const vector<int> &profits, const vector<int> &weights, vector<double> &profitByWeight)
{
    for (int i = 0; i < weights.size(); i++)
    {
        profitByWeight[i] = double(profits[i]) / weights[i];
    }
}

// find kth max value
int max(const vector<double> &profitByWeight, vector<bool> &ignoredIndices)
{
    int maxIndex = -1;
    double maxVal = -1;

    for (int i = 0; i < profitByWeight.size(); i++)
    {
        if (!ignoredIndices[i] && profitByWeight[i] > maxVal)
        {
            maxVal = profitByWeight[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int FK(const vector<int> &objects, const vector<int> &profits, const vector<int> &weights, vector<int> &includedObjects, int capacity)
{
    int n = objects.size();
    int totalProfit = 0;

    vector<double> profitByWeight(n, 0);
    calculateProfitByWeight(profits, weights, profitByWeight);

    cout << "Profit/Weight ratio of objects: ";
    print(profitByWeight);

    vector<bool> ingoredIndices(n, false);

    while (!allTrue(ingoredIndices) && capacity > 0) // all true in ignoredIndices: all objects have been processed
    {
        int maxIndex = max(profitByWeight, ingoredIndices);
        if (maxIndex == -1)
        {
            break; // no more objects
        }

        ingoredIndices[maxIndex] = true;

        if (weights[maxIndex] <= capacity)
        {
            includedObjects[maxIndex] = 1;
            totalProfit += profits[maxIndex];
            capacity -= weights[maxIndex];
        }
    }
    cout << "The remaining capacity is: " << capacity << endl;
    return totalProfit;
}

int main()
{
    vector<int> objects = {1, 2, 3, 4, 5, 6, 7};
    vector<int> profits = {10, 5, 15, 7, 6, 18, 3};
    vector<int> weights = {2, 3, 5, 7, 1, 4, 1};
    int n = objects.size(), capacity = 15;
    vector<int> includedObjects(n, 0); // only 0's & 1's not fractions

    int maxProfit = FK(objects, profits, weights, includedObjects, capacity);

    cout << "Objects included: ";
    print(includedObjects);
    cout << "The maximum profit possible is: " << maxProfit << endl;

    return 0;
}