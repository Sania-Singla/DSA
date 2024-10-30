#ifndef PRINT_TREE_H
#define PRINT_TREE_H

#include <iostream>
#include "queue.h"
#include "node.h"
using namespace std;

void printUsingBFT(Node *startNode, int n)
{
    Queue q1(n);
    q1.enqueue(startNode);
    while (!q1.isEmpty())
    {
        startNode = q1.dequeue();
        cout << startNode->data << "  ";

        if (startNode->lc)
        {
            q1.enqueue(startNode->lc);
        }
        if (startNode->rc)
        {
            q1.enqueue(startNode->rc);
        }
    }
    cout << endl;
}

#endif