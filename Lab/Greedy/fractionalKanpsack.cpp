// an array of objects and its associated profit and weight array is given along with a bag(knapsack) of given capacity
// we have to fill the bag with objects of total weight <= capacity and max profit
// ** Remember: the objects are dividable which means u need not to take the complete weight given ex: vegetables **

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Item
{
public:
    int id, wt, pf;
    double ratio, fraction = 0;
    Item(int id, int wt, int pf) : id(id), wt(wt), pf(pf)
    {
        ratio = double(pf) / wt;
    }
};

void print(vector<Item> items)
{
    for (auto item : items)
    {
        cout << to_string(item.id) + "=" + to_string(item.fraction) << " ";
    }
    cout << endl;
}

void swap(Item &a, Item &b)
{
    Item c = a;
    a = b;
    b = c;
}

int partition(vector<Item> &items, int s, int e)
{
    int i = s + 1, j = e;
    Item pivot = items[s];

    while (i <= j)
    {
        while (i <= e && items[i].ratio > pivot.ratio)
        {
            i++;
        }
        while (j >= s && items[j].ratio < pivot.ratio)
        {
            j--;
        }
        if (i <= j)
        {
            swap(items[i++], items[j--]);
        }
    }
    swap(items[j], items[s]);
    return j;
}

void QS(vector<Item> &items, int s, int e)
{
    if (s <= e)
    {
        int p = partition(items, s, e);
        QS(items, s, p - 1);
        QS(items, p + 1, e);
    }
}

double FK(vector<Item> &items, int capacity)
{
    double totalProfit = 0;

    // sort based on p/w (descending order)
    QS(items, 0, items.size() - 1);

    for (Item &item : items)
    {
        if (item.wt <= capacity)
        {
            item.fraction = 1;
            totalProfit += item.pf;
            capacity -= item.wt;
        }
        else
        {
            item.fraction = double(capacity) / item.wt;
            totalProfit += item.fraction * item.pf;
            capacity = 0;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    vector<Item> items = {
        {1, 2, 10},
        {2, 3, 5},
        {3, 5, 15},
        {4, 7, 7},
    };
    int capacity = 15;

    double maxProfit = FK(items, capacity);

    print(items);

    cout << "The maximum profit possible is: " << maxProfit << endl;
}