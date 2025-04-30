#include <iostream>
#include <vector>
using namespace std;
float activitySelection(vector<float> &start, vector<float> &end)
{
    float ans = 0;
    float finish = -1;
    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] >= finish)
        {
            finish = end[i];
            ans++;
            cout << start[i] << " ";
            cout << finish << endl;
        }
    }
    cout << "Number of activites possible = ";
    return ans;
}
int main()
{
    vector<float> start = {5, 8, 12, 15, 16};
    vector<float> end = {8, 13, 14, 16, 17};
    cout << "Activities possible = " << endl
         << activitySelection(start, end);
    return 0;
}