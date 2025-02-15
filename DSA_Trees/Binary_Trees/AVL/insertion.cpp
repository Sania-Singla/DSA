// maintaince of complete/almost complete binary tree during insertion

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

Node *SRR(Node *j)
{
    Node *k = j->lc;

    k->par = j->par;
    if (j->par->lc == j)
    {
        j->par->lc = k;
    }
    else
    {
        j->par->rc = k;
    }

    j->lc = k->rc;
    if (j->lc)
        j->lc->par = j; // or k->rc->par = j;
    k->rc = j;
    j->par = k;
}

Node *SLR(Node *j)
{
    Node *k = j->rc;

    k->par = j->par;
    if (j->par->lc == j)
    {
        j->par->lc = k;
    }
    else
    {
        j->par->rc = k;
    }

    j->rc = k->lc;
    if (j->rc)
        j->rc->par = j; // or  k->lc->par = j;
    k->lc = j;
    j->par = k;
}

// Node * SRR(Node * k) {
//     Node * j = k -> par;
//     k -> par = j -> par;
//     if(j -> par -> lc = j) {
//         j -> par -> lc = k;
//     } else {
//         j -> par -> rc = k;
//     }

//     j -> lc = k -> rc;
//     k -> rc -> par = j;
//     k -> rc = j;
// }

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, 12, 19, 19, 1, 0};
    Node *root = createBST(arr);
    cout << "before deletion: " << endl;
    printUsingBFT(root);

    cout << "after inserting 11: " << endl;
    insertInBST(root, 11);
    printUsingBFT(root);
}
