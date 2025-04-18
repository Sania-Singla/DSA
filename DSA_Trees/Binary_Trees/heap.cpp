#include <iostream>
#include <vector>
#include "./headerFiles/node.h"

using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

void printHeap(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        printHeap(root->lc);
        printHeap(root->rc);
    }
}

void insertInBT(Node *root, Node *newNode)
{
    if (!root->lc)
    {
        root->lc = newNode;
        newNode->par = root;
    }
    else if (!root->rc)
    {
        root->rc = newNode;
        newNode->par = root;
    }
    else
    {
        insertInBT(root->lc, newNode);
    }
}

void swap(Node *node1, Node *node2)
{
    int c = node1->data;
    node1->data = node2->data;
    node2->data = c;
}

void heapifyUp(Node *node)
{
    while (node->par && node->data > node->par->data)
    {
        swap(node, node->par);
    }
}

Node *createHeap(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        insertInBT(root, newNode);
        heapifyUp(newNode);
    }
    return root;
}

void heapifyDown(Node *node)
{
    if (node)
    {
        Node *max = node;
        if (node->lc && node->lc->data > max->data)
        {
            max = node->lc;
        }
        else if (node->rc->data > max->data)
        {
            max = node->rc;
        }
        if (node != max)
        {
            swap(max, node);
            heapifyDown(max);
        }
    }
}

Node *findLastNode(Node *root)
{
    Node *last = root;
    while (last)
    {
        if (last->rc)
            last = last->rc;
        else if (last->lc)
            last = last->lc;
        else
            break;
    }
    return last;
}

int deleteFromRoot(Node *root)
{
    if (root)
    {
        int val = root->data;
        Node *last = findLastNode(root);

        if (last == root)
        {
            delete root;
            return val;
        }

        root->data = last->data;

        // detach the last node from the heap
        if (last->par->lc == last)
        {
            last->par->lc = NULL;
        }
        else
        {
            last->par->rc = NULL;
        }
        delete last;

        heapifyDown(root);

        return val;
    }
}

void disruptHeap(Node *root, vector<int> &arr)
{
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        arr[i] = deleteFromRoot(root);
    }
}

void HS(vector<int> &arr)
{
    // step1: create a max heap (for ascending order)
    Node *root = createHeap(arr);

    // step2: delete elements 1 by 1 from root
    disruptHeap(root, arr);
}

int main()
{
    vector<int> arr = {5, 2, 4, 3, 1};
    HS(arr);
    print(arr);
}