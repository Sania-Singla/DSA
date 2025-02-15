#ifndef CREATE_BST_H
#define CREATE_BST_H

#include <iostream>
#include <vector>
#include "queue.h"
#include "node.h"
using namespace std;

void create(Node *root, int d)
{
    if (!root)
        return;
    if (root->data >= d)
    {
        if (root->lc)
            create(root->lc, d);
        else
        {
            Node *newNode = new Node(d);
            root->lc = newNode;
            newNode->par = root;
        }
    }
    else
    {
        if (root->rc)
            create(root->rc, d);
        else
        {
            Node *newNode = new Node(d);
            root->rc = newNode;
            newNode->par = root;
        }
    }
}

Node *createBST(vector<int> arr)
{
    int s = arr.size();
    Node *root = new Node(arr[0]);
    for (int i = 1; i < s; i++)
    {
        create(root, arr[i]);
    }
    return root;
}
#endif