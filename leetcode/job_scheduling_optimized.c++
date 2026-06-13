#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! time complexity: O(nlogn + n*d) where d is max deadline
//! space complexity: O(d + n) where d is max deadline and n is number of jobs

int find(int d, vector<int> &parent) {
    if(parent[d] == d) {
        return d; // itself is the empty slot
    }

    return parent[d] = find(parent[d], parent);  // ki agr 5 pr 4 likha tha toh ab 4 pr dekho empty hai ya kuch aur likha hai
}
int main()
{
    vector<int> deadline = {4, 1, 1, 1}, profit = {20, 10, 40, 30};

    int n = deadline.size();
    vector<pair<int, int>> jobs;

    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        jobs.push_back({profit[i], deadline[i]});
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    sort(jobs.begin(), jobs.end(), greater<>());

    vector<int> parent(maxDeadline + 1); // stores ki isse pehle konsa slot empty hai
    for (int i = 1; i <= maxDeadline; i++)
    {
        parent[i] = i; // itself is the empty slot
    }

    int count = 0, totalProfit = 0;

    for (auto job : jobs)
    {
        int p = job.first, d = job.second;

        int slot = find(d, parent);
        if (slot > 0) // because if 0 toh vo toh kabhi fill nhi hi krna tha means no empty slots
        {
            count++;
            totalProfit += p;
            parent[slot] = find(slot - 1, parent); 
        }
    }

    cout << "Max Profit: " << totalProfit << ", Number of Jobs Done: " << count << endl;

    return 0;
}