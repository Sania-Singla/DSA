#ifndef CREATE_ALMOST_COMPLETE_TREE_H
#define CREATE_ALMOST_COMPLETE_TREE_H

#include <iostream>
#include <vector>
#include "node.h"
#include <queue>
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

// iterative (using insertion function separate)
// void insertInBST(Node *&root, int k)
// {
//     Node *newNode = new Node(k);

//     if (!root)
//     {
//         root = newNode;
//         return;
//     }

//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop(); // because everytime 'q' will be created again because we created a separate function for insert not merged in create function

//         if (temp->lc == NULL)
//         {
//             temp->lc = newNode;
//             newNode->par = temp;
//             return;
//         }
//         else
//         {
//             q.push(temp->lc);
//         }

//         if (temp->rc == NULL)
//         {
//             temp->rc = newNode;
//             newNode->par = temp;
//             return;
//         }
//         else
//         {
//             q.push(temp->rc);
//         }
//     }
// }

// Node *createAlmostCompleteTree(vector<int> &arr)
// {
//     Node *root = NULL;
//     for (int val : arr)
//     {
//         insertInBST(root, val);
//     }
//     return root;
// }

Node *createAlmostCompleteTree(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    Node *temp = root;
    queue<Node *> q;
    q.push(temp);

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        while (!q.empty())
        {
            temp = q.front();
            if (temp->lc == NULL)
            {
                temp->lc = newNode;
                newNode->par = temp;
                q.push(temp->lc);
            }
            else if (temp->rc == NULL)
            {
                temp->rc = newNode;
                newNode->par = temp;
                q.push(temp->rc);
            }
            else
            {
                q.pop();
                q.push(temp->lc);
                q.push(temp->rc);
            }
        }
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