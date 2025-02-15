#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// iterative
// void postorder(Node *root)
// {
//     stack<Node *> s;
//     Node *temp = root;
//     Node *lastVisited = NULL;

//     while (temp != NULL || !s.empty())
//     {
//         if (temp != NULL)
//         {
//             s.push(temp);
//             temp = temp->lc;
//         }
//         else
//         {
//             temp = s.top();

//             // Check if right child is already visited or doesn't exist
//             if (temp->rc && temp->rc != lastVisited)
//             {
//                 temp = temp->rc;
//             }
//             else
//             {
//                 cout << temp->data << "  ";
//                 lastVisited = temp;
//                 s.pop();
//                 temp = NULL;
//             }
//         }
//     }
//     cout << endl;
// }

// or (using STL stack) (better for understanding)
void postorder(Node *root)
{
    stack<long> s;
    long temp = (long)root;

    while (temp != (long)NULL || !s.empty())
    {
        if (temp != (long)NULL)
        {
            s.push(temp);
            temp = long(((Node *)temp)->lc);
        }
        else
        {
            temp = s.top();
            s.pop();

            if (temp > 0)
            {
                s.push(-temp); // because we need the root again for coming back from right child and then we will print the root so to differentiate when to go to its rc and when to print it
                temp = long(((Node *)temp)->rc);
            }
            else
            {
                cout << ((Node *)(-temp))->data << "  ";
                temp = (long)NULL;
            }
        }
    }
    cout << endl;
}

// recursive
// void postorder(Node *root)
// {
//     if (!root)
//     {
//         return;
//     }
//     else
//     {
//         if (root->lc)
//             postorder(root->lc);
//         if (root->rc)
//             postorder(root->rc);
//         cout << root->data << "  "; // post
//     }
// }

int main()
{
    vector<int> arr = {7, 10, 0, 12, 19, 1, 11, -1};
    Node *root = createBST(arr);
    cout << "postorder traversal: ";
    postorder(root);
}