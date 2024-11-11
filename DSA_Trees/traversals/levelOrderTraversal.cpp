#include <iostream>
#include <queue>
#include "../headerFiles/createBST.h"
#include "../headerFiles/node.h"
using namespace std;

// OR BREADTH FIRST TRAVERSAL

void levelOrder_or_BFT(Node *root)
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

int main()
{
    vector<int> arr = {7, 10, 0, 12, 19, 1, 11, -1};
    Node *root = createBST(arr);
    levelOrder_or_BFT(root);
}