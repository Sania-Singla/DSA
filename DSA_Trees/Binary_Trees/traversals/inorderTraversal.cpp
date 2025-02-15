#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// iterative
void inorder(Node *root)
{
    stack<Node *> s;
    Node *temp = root;

    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->lc;
        }
        else
        {
            temp = s.top();
            cout << temp->data << "  ";
            temp = temp->rc;
            s.pop();
        }
    }
}

// recursive
// void inorder(Node *root)
// {
//     if (!root)
//     {
//         return;
//     }
//     else
//     {
//         if (root->lc)
//             inorder(root->lc);
//         cout << root->data << "  "; // in
//         if (root->rc)
//             inorder(root->rc);
//     }
// }

int main()
{
    vector<int> arr = {7, 10, 0, 12, 19, 1, 11, -1};
    Node *root = createBST(arr);
    cout << "inorder traversal: ";
    inorder(root);
}