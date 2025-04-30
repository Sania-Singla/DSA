#include <iostream>
#include <vector>

using namespace std;

float activitySelection(vector<float> &start, vector<float> &end)
{
    float ans = 0, finish = -1;

    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] >= finish)
        {
            finish = end[i];
            ans++;
            cout << start[i] << " " << finish << endl;
        }
    }

    return ans;
}

int main()
{
    vector<float> start = {5, 8, 12, 15, 16}, end = {8, 13, 14, 16, 17};
    cout << "Number of activities possible = " << activitySelection(start, end) << endl;
}