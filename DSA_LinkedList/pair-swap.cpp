#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    if (head != NULL)
    {
        newNode->next = head;
    }
    head = newNode;
}

// iterative
// Node *pairSwap(Node *head)
// {
//     if (!head || !head->next)
//         return head;
//     else
//     {
//         Node *curr = head;
//         Node *prev = NULL;
//         head = curr->next;
//         while (curr && curr->next)
//         {
//             Node *currNext = curr->next;
//             Node *currNextNext = currNext->next;
//             curr->next = currNextNext;
//             currNext->next = curr;
//             if (prev)
//             {
//                 prev->next = currNext;
//             }
//             prev = curr;
//             curr = currNextNext;
//         }
//         return head;
//     }
// }

// recursive
// Node *pairSwap(Node *head)
// {
//     if (!head || !head->next)
//         return head;
//     else
//     {
//         Node *curr = head;
//         Node *currNext = curr->next;
//         curr->next = pairSwap(currNext->next);
//         currNext->next = curr;
//         return currNext;
//     }
// }

// MISTAKE
// Node *reversekgroup(Node *head, int k)
// {
//     if (!head || !head->next || k == 1)
//         return head;
//     else
//     {
//         int i;
//         Node *temp = head;
//         Node *prev = NULL;
//         Node *next = NULL;
//         Node *curr = head;
//         while (temp->next != NULL)
//         {
//             i = 0;
//             prev = NULL;
//             prev ? cout << "up " << prev->data << temp->data : cout << "up & prev null " << temp->data << curr->next->next->next;
//             while (i < k && curr != NULL)
//             {
//                 next = curr->next;
//                 curr->next = prev;
//                 prev = curr;
//                 curr = next;
//                 i++;
//             }
//             Node *nextGroupConnect = curr;
//             for (int i = 0; i < k - 1 && nextGroupConnect != NULL; i++)
//             {
//                 nextGroupConnect = nextGroupConnect->next;
//             }
//             if (temp == head)
//                 head = prev;
//             temp->next = nextGroupConnect;
//             cout << temp->next->data;
//             temp = curr;
//             cout << "down " << temp->data << temp->next->data << nextGroupConnect->data << prev->data;
//         }
//         return head;
//     }
// }

// Node *reversekgroup(Node *&head, int k)
// {
//     if (!head || !head->next || k == 1)
//         return head;
//     else
//     {
//         int i;
//         Node *prev = NULL;
//         Node *next = NULL;
//         Node *curr = head;
//         i = 0;
//         while (i < k && curr != NULL)
//         {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//             i++;
//         }
//         head->next = reversekgroup(curr, k);
//         return prev;
//     }
// }

// leaving leftout nodes as it is if less than k
Node *reversekgroup(Node *&head, int k)
{
    if (!head || !head->next || k == 1)
        return head;
    else
    {
        Node *temp = head;
        int l = 1;
        while (temp)
        {
            temp = temp->next;
            l++;
        }
        int i;
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = head;
        i = 0;
        int leftNodes = l;
        if(leftNodes < k) {
            return head;
        }
        while (i < k && curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        head->next = reversekgroup(curr, k);
        return prev;
    }
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    head = reversekgroup(head, 4);
    print(head);

    // head = pairSwap(head);
    // print(head);
}