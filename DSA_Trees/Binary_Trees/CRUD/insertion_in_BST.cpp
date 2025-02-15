#include <iostream>
#include <vector>
#include "../headerFiles/createBST.h"
#include "../headerFiles/node.h"
#include "../headerFiles/printUsingBFT.h"
using namespace std;

void insertInBST(Node *root, int k)
{
    if (!root)
    {
        return;
    }
    else
    {
        Node *newNode = new Node(k);
        if (k <= root->data)
        {
            if (!root->lc)
            {
                root->lc = newNode;
                newNode->par = root;
            }
            else
            {
                insertInBST(root->lc, k);
            }
        }
        else
        {
            if (!root->rc)
            {
                root->rc = newNode;
                newNode->par = root;
            }
            else
            {
                insertInBST(root->rc, k);
            }
        }
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, 12, 19, 19, 1, 0};
    Node *root = createBST(arr);
    cout << "before deletion: " << endl;
    printUsingBFT(root);
    cout << "after inserting 11: " << endl;
    insertInBST(root, 11);
    printUsingBFT(root);
    cout << "after inserting 9: " << endl;
    insertInBST(root, 9);
    printUsingBFT(root);
    cout << "after inserting 6: " << endl;
    insertInBST(root, 6);
    printUsingBFT(root);
}
