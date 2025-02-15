#ifndef INSERT_IN_CBT_H
#define INSERT_IN_CBT_H

#include <iostream>
#include <vector>
#include "node.h"
#include <queue>
#include "printUsingBFT.h"
using namespace std;

// iterative
// O(n^2)
//          *(c)
//    *(0)       *(1)            +c
// *(2)  *(3) *(4)  *(5) ... total n-1 nodes
Node *insertInCBT(Node *&root, int k)
{
    Node *newNode = new Node(k);

    if (!root)
    {
        root = newNode;
    }
    else
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop(); // because everytime 'q' will be created again because we created a separate function for insert not merged in create function

            if (temp->lc == NULL)
            {
                temp->lc = newNode;
                newNode->par = temp;
                break;
            }
            else
            {
                q.push(temp->lc);
            }

            if (temp->rc == NULL)
            {
                temp->rc = newNode;
                newNode->par = temp;
                break;
            }
            else
            {
                q.push(temp->rc);
            }
        }
    }
    return newNode;
}

#endif