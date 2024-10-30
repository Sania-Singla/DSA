#include <iostream>
#include <vector>
#include "../headerFiles/createTree.h"
#include "../headerFiles/node.h"
#include "../headerFiles/queue.h"
using namespace std;

void PRE_ORDER_or_DEPTH_FIRST(Node *root)
{
    if (root)
    {
        cout << root->data << "  ";
        if (root->lc)
            PRE_ORDER_or_DEPTH_FIRST(root->lc);
        if (root->rc)
            PRE_ORDER_or_DEPTH_FIRST(root->rc);
    }
}

void LEVEL_ORDER_or_BREDTH_WISE(Node *root, int n)
{
    if (root)
    {
        Queue *q = new Queue(n);
        q->enqueue(root);
        while (!q->isEmpty())
        {
            root = q->dequeue();
            cout << root->data << "  ";

            if (root->lc)
            {
                q->enqueue(root->lc);
            }
            if (root->rc)
            {
                q->enqueue(root->rc);
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {1, 5, 11, 10, 17, 0, -1};
    Node *root = createTree(arr);
    cout << "DFT: " << endl;
    PRE_ORDER_or_DEPTH_FIRST(root);
    cout << endl;
    cout << "BFT: " << endl;
    LEVEL_ORDER_or_BREDTH_WISE(root, arr.size());
}