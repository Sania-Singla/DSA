#include <iostream>
#include <vector>
#include "headerFiles/node.h"
using namespace std;

Node *createSampleTree()
{
    /* created a tree
                  1
               2     3
             4   5 6   7
        */
    Node *root = new Node(1);
    root->lc = new Node(2);
    root->rc = new Node(3);
    root->lc->par = root;
    root->rc->par = root;

    root->lc->lc = new Node(4);
    root->lc->rc = new Node(5);
    root->lc->lc->par = root->lc;
    root->lc->rc->par = root->lc;

    root->rc->lc = new Node(6);
    root->rc->rc = new Node(7);
    root->rc->lc->par = root->rc;
    root->rc->rc->par = root->rc;
    return root;
}

void check(Node *node1, Node *node2)
{
    if (node1->lc == node2)
    {
        cout << node2->data << " is the left child of " << node1->data << endl;
    }
    else if (node2->lc == node1)
    {
        cout << node1->data << " is the left child of " << node2->data << endl;
    }
    else if (node1->rc == node2)
    {
        cout << node2->data << " is the right child of " << node1->data << endl;
    }
    else if (node2->rc == node1)
    {
        cout << node1->data << " is the right child of " << node2->data << endl;
    }
    else if (node1->par == node2->par)
    {
        cout << node1->data << " and " << node2->data << " are siblings" << endl;
    }
    else
    {
        cout << node1->data << " and " << node2->data << " dont have any imediate relation" << endl;
    }
}

int main()
{
    Node *root = createSampleTree();

    Node *nodeA = root->lc;     // Node 2
    Node *nodeB = root->rc;     // Node 3
    Node *nodeC = root->lc->lc; // Node 4
    Node *nodeD = root->lc->rc; // Node 5
    Node *nodeE = root->rc->lc; // Node 6

    check(nodeA, root);
    check(nodeB, root);
    check(nodeC, nodeD);
    check(nodeA, nodeB);
    check(nodeD, nodeE);
}