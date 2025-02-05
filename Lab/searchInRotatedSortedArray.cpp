#include <iostream>
#include <vector>

using namespace std;

bool BS(vector<int> nums, int target, int s, int e)
{
    cout << s << e << endl;
    if (s > e)
    {
        return false;
    }
    else
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] < target)
        {
            return BS(nums, target, mid + 1, e);
        }
        else
        {
            return BS(nums, target, s, mid - 1);
        }
    }
}

int pivot(vector<int> nums, int s, int e)
{
    int i = 0;
    while (nums[i] <= nums[i + 1])
    {
        i++;
    }
    return i + 1;
}

bool search(vector<int> &nums, int target)
{
    int l = nums.size();
    if (l == 0)
    {
        return false;
    }
    else if (l == 1)
    {
        if (nums[0] != target)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        int i = pivot(nums, 0, l - 1);
        cout << i << endl;
        int ans = BS(nums, target, 0, i - 1);
        if (ans == false)
        {
            ans = BS(nums, target, i, l - 1);
        }
        return ans;
    }
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 1};
    if (search(nums, 0))
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND";
    }
}