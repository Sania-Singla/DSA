#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

using namespace std;

class Process
{
public:
    int Id, AT, BT;
    Process(int Id, int AT, int BT) : Id(Id), AT(AT), BT(BT) {}
};
#endif