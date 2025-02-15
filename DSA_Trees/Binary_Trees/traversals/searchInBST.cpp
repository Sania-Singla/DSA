#include <iostream>
#include <vector>
#include "../headerFiles/node.h"
#include "../headerFiles/queue.h"
#include "../headerFiles/createBST.h"
#include <queue>
using namespace std;

// this is binary search (this is not breadth first search obvious because ye toh fir dfs mein bhi same hi krenge so queues or stacks se jo krte hai those are bfs and dfs)
bool searchInBST(Node *startNode, int k)
{
    if (!startNode)
    {
        return false;
    }
    else
    {
        if (startNode->data == k)
        {
            return true;
        }
        else if (k < startNode->data)
        {
            searchInBST(startNode->lc, k);
        }
        else
        {
            searchInBST(startNode->rc, k);
        }
    }
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -1};
    Node *root = createBST(arr);
    bool isFound = searchInBST(root, 17);
    if (isFound)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}