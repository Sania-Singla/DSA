#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/node.h"
#include "../headerFiles/printUsingBFT.h"
using namespace std;

void deleteLeafNode(Node *leafNode)
{
    if (leafNode->par)
    {
        if (leafNode->par->lc == leafNode)
        {
            leafNode->par->lc = NULL;
        }
        else
        {
            leafNode->par->rc = NULL;
        }
    }
    delete leafNode;
}

Node *maxFromBST(Node *root)
{
    if (!root)
    {
        return NULL;
    }
    else
    {
        while (root->rc)
        {
            root = root->rc;
        }
        return root;
    }
}

Node *minFromBST(Node *root)
{
    if (!root)
    {
        return NULL;
    }
    else
    {
        while (root->lc)
        {
            root = root->lc;
        }
        return root;
    }
}

Node *searchInBST(Node *root, int k)
{
    if (!root)
    {
        return NULL;
    }
    else
    {
        if (k == root->data)
        {
            return root;
        }
        else if (k > root->data)
        {
            return searchInBST(root->rc, k);
        }
        else
        {
            return searchInBST(root->lc, k);
        }
    }
}

Node *deleteFromBST(Node *root, int k)
{
    Node *target = searchInBST(root, k);
    if (!target)
    {
        return root;
    }
    else
    {
        if (!target->lc && !target->rc)
        {
            deleteLeafNode(target);
        }
        else if (target->lc)
        {
            Node *max = maxFromBST(target->lc);
            target->data = max->data;
            deleteFromBST(max, max->data); // can't call with root because infinite loop bn jayega
        }
        else
        {
            Node *min = minFromBST(target->rc);
            target->data = min->data;
            deleteFromBST(min, min->data);
        }
        return root;
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, 12, 19, 19, 1, 0};
    Node *root = createBST(arr);
    cout << "before deletion: " << endl;
    printUsingBFT(root);
    cout << "after deleting 10: " << endl;
    root = deleteFromBST(root, 10);
    printUsingBFT(root);
}