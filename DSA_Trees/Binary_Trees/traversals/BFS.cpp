#include <iostream>
#include <vector>
#include "../headerFiles/node.h"
#include "../headerFiles/queue.h"
#include "../headerFiles/createBST.h"
#include <queue>
using namespace std;

// bool BFS(Node *startNode, int n, int k)
// {
//     Queue q1(n);
//     q1.enqueue(startNode);
//     while (!q1.isEmpty())
//     {
//         startNode = q1.dequeue();
//         if (startNode->data == k)
//         {
//             return true;
//         }

//         if (startNode->lc)
//         {
//             q1.enqueue(startNode->lc);
//         }
//         if (startNode->rc)
//         {
//             q1.enqueue(startNode->rc);
//         }
//     }
//     return false;
// }

// using STL queues
bool BFS(Node *startNode, int k)
{
    queue<Node *> q;
    q.push(startNode);
    while (!q.empty())
    {
        startNode = q.front();
        q.pop();
        if (startNode->data == k)
        {
            return true;
        }
        else
        {
            if (startNode->lc)
            {
                q.push(startNode->lc);
            }
            if (startNode->rc)
            {
                q.push(startNode->rc);
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 10, 12, 19, 0, 12, -1};
    Node *root = createBST(arr);
    if (BFS(root, 17))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}