#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/printUsingBFT.h"
#include "../headerFiles/stack.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// iterative
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
void DFT(Node *startNode, int n)
{
    stack<Node *> s;
    s.push(startNode);
    while (!s.empty())
    {
        startNode = s.top();
        s.pop();
        cout << startNode->data << "  ";

        if (startNode->rc) // ⭐ since in stack which gets pushed after gets popped earlier
        {
            s.push(startNode->rc);
        }
        if (startNode->lc)
        {
            s.push(startNode->lc);
        }
    }
    cout << endl;
}

// recursive
void DFT(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        cout << root->data << "  "; // pre
        if (root->lc)
            DFT(root->lc);
        if (root->rc)
            DFT(root->rc);
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -2, -1};
    Node *root = createBST(arr);
    cout << "breadth first traversal: ";
    printUsingBFT(root);
    cout << "depth first traversal: ";
    DFT(root);
}