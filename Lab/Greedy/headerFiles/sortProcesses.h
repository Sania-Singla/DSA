#ifndef SORT_PROCESSES_AT
#define SORT_PROCESSES_AT

#include <iostream>
#include <vector>
#include "./process.h"
using namespace std;

void swap(Process &a, Process &b)
{
    Process c = a;
    a = b;
    b = c;
}

// O(n) works for repetitive elements as well
int partition(vector<Process> &processes, int s, int e)
{
    int i = s + 1, j = e;
    Process pivot = processes[s];
    // O(n)
    while (i <= j)
    {
        while (i <= e && processes[i].BT < pivot.BT)
        {
            i++;
        }
        while (j >= s && processes[j].BT > pivot.BT)
        {
            j--;
        }
        if (i <= j)
        {
            swap(processes[i++], processes[j--]); // prevents infinite loop
        }
    }
    swap(processes[j], processes[s]);
    return j;
}

// T(n) = 2T(n/2) + O(n)
// T(n) = nlogn
void solve(vector<Process> &processes, int s, int e)
{
    if (s < e)
    {
        int p = partition(processes, s, e); // O(n)
        solve(processes, s, p - 1);         // T(n/2)
        solve(processes, p + 1, e);         // T(n/2)
    }
}

void QS(vector<Process> &processes)
{
    solve(processes, 0, processes.size() - 1);
}

#endif