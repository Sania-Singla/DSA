#include <iostream>
#include <vector>
#include "../headerFiles/createTree.h"
#include "../headerFiles/printUsingBFT.h"
#include "../headerFiles/stack.h"
#include "../headerFiles/node.h"
using namespace std;
// ALSO KNOWN AS PRE-ORDER TRAVERSAL

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

// recursive
void DFT(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        cout << root->data << "  ";
        if (root->lc)
            DFT(root->lc);
        if (root->rc)
            DFT(root->rc);
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -2, -1};
    Node *root = createTree(arr);
    cout << "binary first traversal: ";
    printUsingBFT(root, arr.size());
    cout << "depth first traversal: ";
    DFT(root);
}