#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/printUsingBFT.h"
#include "../headerFiles/stack.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// recursive
void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        if (root->lc)
            postorder(root->lc);
        if (root->rc)
            postorder(root->rc);
        cout << root->data << "  "; // post
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 11, -2, -1};
    Node *root = createBST(arr);
    cout << "postorder traversal: ";
    postorder(root);
}