#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/stack.h"
#include "../headerFiles/node.h"
#include <stack>
using namespace std;

// using STL stack
bool DFS(Node *startNode, int k)
{
    if (!startNode)
    {
        return false;
    }
    else
    {
        stack<Node *> s;
        s.push(startNode);
        while (!s.empty())
        {
            startNode = s.top();
            s.pop();
            if (startNode->data == k)
            {
                return true;
            }
            if (startNode->rc)
            {
                s.push(startNode->rc);
            }
            if (startNode->lc)
            {
                s.push(startNode->lc);
            }
        }
        return false;
    }
}

// recursive
// bool DFS(Node *root, int k)
// {
//     if (!root)
//     {
//         return false;
//     }
//     else
//     {
//         if (root->data == k)
//         {
//             return true;
//         }

//         bool foundInLeft = DFS(root->lc, k);
//         if (foundInLeft)
//             return true;
//         return DFS(root->rc, k);
//     }
// }

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -2, -1};
    Node *root = createBST(arr);
    if (DFS(root, 12))
        cout << "found";
    else
        cout << "not found";
}