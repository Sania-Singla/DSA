#include <iostream>
#include <vector>
#include <algorithm>
#include "./headerFiles/process.h"
#include "./headerFiles/sortProcesses.h"

using namespace std;

void print(vector<int> arr)
{
    for (int val : arr)
    {
        cout << "P" + to_string(val) << " ";
    }
    cout << endl;
}

void AS(vector<Process> processes, vector<int> &exeOdr)
{
    // Sort based on burst time
    QS(processes);

    int time = 0;

    for (const Process &p : processes)
    {
        if (time < p.AT) // If CPU is idle, move time to the next process's arrival time
        {
            cout << "-------idle-------" << "\n\n";
            time = p.AT;
            cout << "current Time: " << time << "\n\n";
        }

        if (time > p.AT)
        {
            cout << "skipped: " << "P" << p.Id << "\t" << p.AT << "\t" << p.BT << "\n\n";
        }

        if (time == p.AT) // Execute process
        {
            exeOdr.push_back(p.Id);
            cout << "P" << p.Id << "\t" << p.AT << "\t" << p.BT << "\n\n";
            time += p.BT; // Increase time by burst time
            cout << "current Time: " << time << "\n\n";
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
    };

    vector<int> exeOdr;
    AS(processes, exeOdr);
    print(exeOdr);
    cout << "no of activities possible: " << exeOdr.size() << endl;
}