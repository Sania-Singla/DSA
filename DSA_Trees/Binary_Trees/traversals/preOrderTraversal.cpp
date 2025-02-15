#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/printUsingBFT.h"
#include "../headerFiles/stack.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// iterative (using our own stack)
// void DFT(Node *startNode, int n)
// {
//     Stack *s1 = new Stack(n);
//     s1->push(startNode);
//     while (!s1->isEmpty())
//     {
//         startNode = s1->pop();
//         cout << startNode->data << "  ";

//         if (startNode->rc) // ⭐ since in stack which gets pushed after gets popped earlier
//         {
//             s1->push(startNode->rc);
//         }
//         if (startNode->lc)
//         {
//             s1->push(startNode->lc);
//         }
//     }
//     cout << endl;
// }

// using STL stack
// void DFT(Node *root)
// {
//     stack<Node *> s;
//     s.push(root);

//     while (!s.empty())
//     {
//         root = s.top();
//         s.pop();
//         cout << root->data << "  ";

//         if (root->rc) // ⭐ since in stack which gets pushed after gets popped earlier
//         {
//             s.push(root->rc);
//         }
//         if (root->lc)
//         {
//             s.push(root->lc);
//         }
//     }
//     cout << endl;
// }

// better for unnderstanding (abdul bari)
void DFT(Node *root)
{
    stack<Node *> s;
    Node *temp = root;

    while (temp != NULL || !s.empty()) // if temp == NULL but still if there is something in stack that means we are yet to go to its right
    {
        if (temp != NULL)
        {
            cout << temp->data << "  ";
            s.push(temp); // before moving to its left push it to the stack for returning to
            temp = temp->lc;
        }
        else
        {
            // go to its par -> right and remove the par now (no longer needed)
            temp = s.top();
            temp = temp->rc;
            s.pop();
        }
    }
    cout << endl;
}

// recursive
// void DFT(Node *root)
// {
//     if (!root)
//     {
//         return;
//     }
//     else
//     {
//         cout << root->data << "  "; // pre
//         if (root->lc)
//             DFT(root->lc);
//         if (root->rc)
//             DFT(root->rc);
//     }
// }

int main()
{
    vector<int> arr = {7, 10, 0, 12, 19, 1, 11, -1};
    Node *root = createBST(arr);
    cout << "breadth first traversal: " << endl;
    printUsingBFT(root);
    cout << "depth first traversal: " << endl;
    DFT(root);
}