#include <iostream>
#include <vector>
#include "../headerFiles/createAlmostCompleteTree.h"
#include "../headerFiles/node.h"
#include "../headerFiles/printUsingBFT.h"
using namespace std;

Node * copy(Node *root)
{
    if (!root)
        return NULL;

    Node *newNode = new Node(root->data);
    
    newNode -> lc = copy(root -> lc);
    newNode -> rc = copy(root -> rc);

    if (root->lc)
    {
        newNode -> lc -> par = newNode;
    }
    if (root->rc)
    {
        newNode -> rc -> par = newNode;
    }

    return newNode;
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -1, 0};

    Node *originalRoot = createAlmostCompleteTree(arr);

    cout << "Original tree:" << endl;
    printUsingBFT(originalRoot);

    Node *copyRoot = copy(originalRoot);

    cout << "Copied tree:" << endl;
    printUsingBFT(copyRoot);

    return 0;
}