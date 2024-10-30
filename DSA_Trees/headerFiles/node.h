#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lc;
    Node *rc;
    Node *par;

    Node(int d)
    {
        this->data = d;
        this->lc = NULL;
        this->rc = NULL;
        this->par = NULL;
    }
};

#endif
