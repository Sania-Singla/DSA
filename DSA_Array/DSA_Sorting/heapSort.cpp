// ** creating a max heap but NOT using heapify, hence T(n) = O(nlogn) **

#include <iostream>
#include <vector>
#include <queue>
#include "../../DSA_Trees/Binary_Trees/headerFiles/node.h"
#include "../../DSA_Trees/Binary_Trees/headerFiles/insertInCBT.h"
using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << "  ";
    }
    cout << endl;
}

void levelorder(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();

        cout << root->data << "  ";
        if (root->lc)
            q.push(root->lc);
        if (root->rc)
            q.push(root->rc);
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void adjustForInsertion(Node *&nodeToAdjust)
{
    while (nodeToAdjust->par && nodeToAdjust->data > nodeToAdjust->par->data)
    {
        swap(nodeToAdjust->data, nodeToAdjust->par->data);
        nodeToAdjust = nodeToAdjust->par;
        // adjustForInsertion(nodeToAdjust->par);  // S(logn)
    }
}

Node *maxHeap(const vector<int> &arr)
{
    Node *root = NULL;
    for (int val : arr) // O(n)
    {
        Node *newNode = insertInCBT(root, val); // O(n^2)
        adjustForInsertion(newNode);            // O(logn) (max value)
    }
    return root;
}

void adjustForDeletion(Node *&nodeToAdjust)
{
    Node *maxChild = NULL;
    if (nodeToAdjust->lc && nodeToAdjust->rc)
    {
        maxChild = nodeToAdjust->lc->data > nodeToAdjust->rc->data ? nodeToAdjust->lc : nodeToAdjust->rc;
    }
    else if (nodeToAdjust->lc || nodeToAdjust->rc)
    {
        maxChild = nodeToAdjust->lc ? nodeToAdjust->lc : nodeToAdjust->rc;
    }
    if (maxChild && nodeToAdjust->data < maxChild->data)
    {
        swap(nodeToAdjust->data, maxChild->data);
        adjustForDeletion(maxChild);
    }
}

void deleteRoot(Node *&root, vector<int> &arr, int e)
{
    swap(root->data, arr[e]);
    adjustForDeletion(root);
}

void heapSort(vector<int> &arr)
{
    // create max heap (for ascending order)
    Node *root = maxHeap(arr);
    cout << "max heap: " << endl;
    levelorder(root);

    // delete all elements 1by1 from heap (obviously from root)
    for (int i = 0; i < arr.size(); i++)
    {
        deleteRoot(root, arr, arr.size() - i - 1);
    }
}

int main()
{
    vector<int> arr = {10, 20, 15, 12, 40, 25, 18};
    heapSort(arr);
    print(arr);
}
