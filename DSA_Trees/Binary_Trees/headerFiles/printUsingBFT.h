#ifndef PRINT_TREE_H
#define PRINT_TREE_H

#include <iostream>
#include "queue.h"
#include <queue>
#include "node.h"
using namespace std;

// iterative
// void printUsingBFT(Node *startNode, int n)
// {
//     Queue q1(n);
//     q1.enqueue(startNode);
//     while (!q1.isEmpty())
//     {
//         startNode = q1.dequeue();
//         cout << startNode->data << "  ";

//         if (startNode->lc)
//         {
//             q1.enqueue(startNode->lc);
//         }
//         if (startNode->rc)
//         {
//             q1.enqueue(startNode->rc);
//         }
//     }
//     cout << endl;
// }

// using STL queues
void printUsingBFT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai & root ke rc and lc queue mein insert ho chuke hai so can push null again
            cout << endl;
            if (!q.empty()) // agr empty hi ho gya toh toh bs khtm sb
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->lc)
            {
                q.push(temp->lc);
            }

            if (temp->rc)
            {
                q.push(temp->rc);
            }
        }
    }
}

// recursive
void printUsingBFT_recursive(Node * root) {
    
}

#endif