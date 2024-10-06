// time complexity: O(n/k) => O(n)
// space complexity: O(n)

#include <iostream>
using namespace std;

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

void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "empty list" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseKGroups (Node * &head, int k) {
    if(head == NULL || head -> next == NULL || k==1) return head;
    Node * temp = head;
    Node * prev = NULL;
    Node * curr = head;
    Node * forward = head;
    int count = 0;
    while(count < k && curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count ++;
    }
    head -> next = reverseKGroups(curr , k);
    return prev;
}

// MISTAKE
// Node *reverseKGroups(Node *head, int k)
// {
//     if (head == NULL || head->next == NULL || k == 1)
//         return head;
//     else
//     {   Node * temp = head;
//         while (temp != NULL)
//         {
//             Node *curr = head;
//             Node *prev = NULL;
//             Node *forward = NULL;
//             int count = 0;
//             while (count < k && curr != NULL)
//             {
//                 forward = curr->next;
//                 curr->next = prev;
//                 prev = curr;
//                 curr = forward;
//                 count++;
//             }
//             temp = curr;
//         }
//         // return temp;
//     }
// }

int main()
{
    Node *head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    cout << "head = " << head->data << endl;

    int k = 3;
    head = reverseKGroups(head, k);
    print(head);
    cout << "head = " << head->data << endl;
}