#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find max profit and number of jobs done
//! every job has burst time of 1 unit **(this is the main differentiator from integral knapsack)**

// it is different from integral knapsack because isme only vo ek slot fill kregi na ki sara capacity reduce krdegi
// so no future options reduced
// ex: in knapsack if C = 10 and we include an item of wright 7 then now only remains 3 capacity
// but if in job scheduling if we include a job of deadline 7 then we can still include jobs of deadline 6,5,4,3,2,1 and even > 7 in early slots if empty

//! time complexity: O(nlogn + n*d) where d is max deadline
//! space complexity: O(d + n) where d is max deadline and n is number of jobs

int main()
{
    vector<int> deadline = {4, 1, 1, 1}, profit = {20, 10, 40, 30};

    int n = deadline.size();
    vector<pair<int, int>> jobs; // or we could struct if needed to return actual pIds

    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        jobs.push_back({profit[i], deadline[i]});
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    sort(jobs.begin(), jobs.end(), greater<>()); // sort jobs in decreasing order of profit

    vector<int> slots(maxDeadline + 1, -1);
    int count = 0, totalProfit = 0;

    for (auto job : jobs)
    {
        int p = job.first, d = job.second;

        for (int i = d; i >= 1; i--)
        {
            if (slots[i] == -1)
            { // empty slot
                slots[i] = p;
                count++;
                totalProfit += p;
                break;
            }
        }
    }

    cout << "Max Profit: " << totalProfit << ", Number of Jobs Done: " << count << endl;

    return 0;
}