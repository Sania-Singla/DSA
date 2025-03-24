#include <iostream>
#include <vector>
#include <algorithm>
#include "./headerFiles/process.h"
#include "./headerFiles/sortProcesses.h"

using namespace std;

void AS(vector<Process> processes)
{
    int n = processes.size();

    // Sort based on arrival time
    QS(processes);

    int currentTime = 0;
    cout << "current Time: " << currentTime << "\n\n";

    for (const Process &p : processes)
    {
        if (currentTime < p.AT) // If CPU is idle, move time to the next process arrival
        {
            cout << "-------idle-------" << "\n\n";
            currentTime = p.AT;
            cout << "current Time: " << currentTime << "\n\n";
        }

        if (currentTime == p.AT) // Execute process
        {
            cout << "P" << p.Id << "\t" << p.AT << "\t" << p.BT << "\n\n";
            currentTime += p.BT; // Increase time by burst time
            cout << "current Time: " << currentTime << "\n\n";
        }
        else
        {
            cout << "skipped: " << "P" << p.Id << "\t" << p.AT << "\t" << p.BT << "\n\n";
        }
    }
}

int main()
{
    // Id AT BT
    vector<Process> processes = {
        {1, 0, 1},
        {2, 1, 2},
        {3, 2, 2},
        {4, 3, 4},
        {5, 4, 1},
        {6, 8, 2},
        {7, 9, 2},

    };

    AS(processes);

    return 0;
}