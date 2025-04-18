// an array of objects and its associated profit and weight array is given along with a bag(knapsack) of given capacity
// we have to fill the bag with objects of total weight <= capacity and max profit
// ** Remember: the objects are dividable which means u need not to take the complete weight given ex: vegetables **

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

vector<double> calculateProfitByWeight(const vector<int> &profits, const vector<int> &weights)
{
    vector<double> profitByWeight(profits.size());
    for (int i = 0; i < weights.size(); i++)
    {
        profitByWeight[i] = double(profits[i]) / weights[i];
    }
    return profitByWeight;
}

// find kth max value
int max(const vector<double> &arr, vector<bool> &ignoredIndices)
{
    int maxIndex = -1;
    double maxVal = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (!ignoredIndices[i] && arr[i] > maxVal)
        {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

double FK(const vector<int> &objects, const vector<int> &profits, const vector<int> &weights, vector<double> &fractionsIncluded, int capacity)
{
    int n = objects.size();
    double totalProfit = 0;

    vector<double> profitByWeight = calculateProfitByWeight(profits, weights);

    vector<bool> ingoredIndices(n, false);

    while (capacity > 0)
    {
        int maxIndex = max(profitByWeight, ingoredIndices);
        if (maxIndex == -1)
        {
            break; // no more objects
        }

        ingoredIndices[maxIndex] = true;

        if (weights[maxIndex] <= capacity)
        {
            fractionsIncluded[maxIndex] = 1;
            totalProfit += profits[maxIndex];
            capacity -= weights[maxIndex];
        }
        else
        {
            fractionsIncluded[maxIndex] = double(capacity) / weights[maxIndex];
            totalProfit += fractionsIncluded[maxIndex] * profits[maxIndex];
            capacity = 0;
        }
    }
    return totalProfit;
}

int main()
{
    vector<int> objects = {1, 2, 3, 4, 5, 6, 7}, profits = {10, 5, 15, 7, 6, 18, 3}, weights = {2, 3, 5, 7, 1, 4, 1};
    int n = objects.size(), capacity = 15;
    vector<double> fractionsIncluded(n, 0);

    double maxProfit = FK(objects, profits, weights, fractionsIncluded, capacity);

    cout << "Fractions of objects included: ";
    print(fractionsIncluded);
    cout << "The maximum profit possible is: " << maxProfit << endl;

    return 0;
}