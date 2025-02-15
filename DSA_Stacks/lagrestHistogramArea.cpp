#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>

using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// *index*
vector<int> prevSmallerIdx(const vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> pse(n);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        pse[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return pse;
}

// *index*
vector<int> nextSmallerIdx(const vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> nse(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        nse[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return nse;
}

int largestArea(const vector<int> &heights)
{
    int n = heights.size();

    // so we have arrays for next and prev smaller height *indices* for each height
    vector<int> prev = nextSmallerIdx(heights);
    vector<int> next = prevSmallerIdx(heights);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n; // for avoiding -ve breadth(b)
        }
        int b = next[i] - prev[i] - 1;
        area = max(area, l * b);
    }

    return area;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "largets area possible = " << largestArea(heights) << endl;
}