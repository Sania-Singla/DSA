#include <iostream>
#include <vector>
#include "../headerFiles/node.h"
#include "../headerFiles/queue.h"
#include "../headerFiles/createTree.h"
using namespace std;

bool BFS(Node *startNode, int n, int k)
{
    Queue q1(n);
    q1.enqueue(startNode);
    while (!q1.isEmpty())
    {
        startNode = q1.dequeue();
        if (startNode->data == k)
        {
            return true;
        }

        if (startNode->lc)
        {
            q1.enqueue(startNode->lc);
        }
        if (startNode->rc)
        {
            q1.enqueue(startNode->rc);
        }
    }
    return false;
}

// recursive
void BFT(Node * root) {
    
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -1};
    Node *root = createTree(arr);
    BFT(root);
    bool isFound = BFS(root, arr.size(), 17);
    if (isFound)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}