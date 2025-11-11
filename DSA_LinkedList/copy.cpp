#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;

    Node *newHead = NULL;
    Node *temp = NULL;

    while (head)
    {
        Node *newNode = new Node(head->val);
        if (!newHead)
        {
            newHead = newNode;
            temp = newHead;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }

        head = head->next;
    }

    return newHead;
}

int main()
{
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // node1->random = node3;
    // node2->random = node5;
    // node3->random = NULL;
    // node4->random = node2;
    // node5->random = node1;

    Node *head = node1;

    Node *newHead = copyRandomList(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    while (newHead)
    {
        cout << newHead->val << " ";
        // if (newHead->random)
        // {
        //     cout << newHead->random->val << endl;
        // }
        // else
        // {
        //     cout << "NULL" << endl;
        // }
        newHead = newHead->next;
    }

    return 0;
}