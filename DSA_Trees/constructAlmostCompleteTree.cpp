#include <iostream>
#include <vector>
#include "headerFiles/node.h"
#include "headerFiles/printUsingBFT.h"
using namespace std;

void create(Node *root, int d)
{
    if (root)
    {
        Node *newNode = new Node(d);
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
            create(root->lc, d);
        }
    }
}

Node *createAlmostCompleteTree(vector<int> arr)
{
    Node *root = new Node(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        create(root, arr[i]);
    }
    return root;
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -1};
    Node *root = createAlmostCompleteTree(arr);
    printUsingBFT(root, arr.size());
}