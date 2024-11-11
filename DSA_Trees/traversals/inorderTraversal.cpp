#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/stack.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// recursive
void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        if (root->lc)
            inorder(root->lc);
        cout << root -> data << "  ";  // in
        if (root->rc)
            inorder(root->rc);
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 11, -2, -1};
    Node *root = createBST(arr);
    cout << "inorder traversal: ";
    inorder(root);
}