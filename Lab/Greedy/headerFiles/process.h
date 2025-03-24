#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

using namespace std;

class Process
{
public:
    int Id, AT, BT, CT, TAT, WT;
    Process(int Id, int AT, int BT) : Id(Id), AT(AT), BT(BT) {}
};

class GanttEntry
{
public:
    int Id, ST, ET;
    GanttEntry(int Id, int ST, int ET) : Id(Id), ST(ST), ET(ET) {}
};

void printProcessTable(const vector<Process> &processes)
{
    cout << "Id\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (const Process &p : processes)
    {
        cout << "P" << p.Id << "\t" << p.AT << "\t" << p.BT << "\t" << p.CT << "\t" << p.TAT << "\t" << p.WT << endl;
    }
}

void printGanttChart(const vector<GanttEntry> &gc)
{
    cout << "Gantt Chart: ";
    for (const GanttEntry &g : gc)
    {
        cout << "| P" << g.Id << " (" << g.ST << "-" << g.ET << ") ";
    }
    cout << "|" << endl;
}

#endif