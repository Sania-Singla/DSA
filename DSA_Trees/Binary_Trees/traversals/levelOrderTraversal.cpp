#include <iostream>
#include <queue>
#include "../headerFiles/createBST.h"
#include "../headerFiles/node.h"
using namespace std;

// iterative
// printing level by level (can't use recursion(or stack) because that will print it depth wise)
void LOTorBFT(Node *root)
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
            // a level is done
            cout << endl;

            if (!q.empty()) // if empty then no more lc and rc so tree complete
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "\t";
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

// printing in a single line
// void LOTorBFT(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         root = q.front();
//         q.pop();

//         cout << root->data << "\t";

//         if (root->lc)
//         {
//             q.push(root->lc);
//         }
//         if (root->rc)
//         {
//             q.push(root->rc);
//         }
//     }
// }

int main()
{
    vector<int> arr = {7, 10, 0, 12, 19, 1, 11, -1};
    Node *root = createBST(arr);
    LOTorBFT(root);
}
