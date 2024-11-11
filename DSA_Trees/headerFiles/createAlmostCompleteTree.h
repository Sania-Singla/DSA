#ifndef CREATE_ALMOST_COMPLETE_TREE_H
#define CREATE_ALMOST_COMPLETE_TREE_H

#include <iostream>
#include <vector>
#include "node.h"
#include<queue>
#include "printUsingBFT.h"
using namespace std;

// recursive
// Node *create(vector<int> arr, int i)
// {
//     if (i >= arr.size()) // base case
//         return NULL;

//     Node *root = new Node(arr[i]);

//     root->lc = create(arr, 2 * i + 1);
//     root->rc = create(arr, 2 * i + 2);

//     // setting parent pointers
//     if (root->lc)
//         root->lc->par = root;
//     if (root->rc)
//         root->rc->par = root;

//     return root;
// }

// Node *createAlmostCompleteTree(vector<int> arr)
// {
//     return create(arr, 0);
// }

// iterative
void insertInBST(Node *&root, int k)
{
    if (!root)
    {
        root = new Node(k);
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (!current->lc)
        {
            current->lc = new Node(k);
            current->lc->par = current;
            break;
        }
        else
        {
            q.push(current->lc);
        }

        if (!current->rc)
        {
            current->rc = new Node(k);
            current->rc->par = current;
            break;
        }
        else
        {
            q.push(current->rc);
        }
    }
}

Node *createAlmostCompleteTree(vector<int> arr)
{
    Node *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        insertInBST(root, arr[i]);
    }
    return root;
}

// int main()
// {
//     vector<int> arr = {7, 10, 12, 19, 0, 12, -1, 0};
//     Node *root = createAlmostCompleteTree(arr);
//     printUsingBFT(root);
// }
#endif