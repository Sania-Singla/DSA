// time & space complexity for recursive: O(n)

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

// iterative
// Node * reverse( Node * &head) {
//     if(head == NULL) {
//         cout << "empty" << endl;
//         return head;
//     }
//     else if(head -> next == NULL) return head;   // Only one element in the list, no need to reverse.
//     Node * prev = NULL;
//     Node * curr = head;
//     Node * temp = head;
//     while(curr != NULL) {
//         temp = curr -> next;    // because we will break the connection so we need to store the next node before breaking the connection
//         curr -> next = prev;
//         prev = curr;
//         curr = temp;
//     }
//     return prev;
// }

// recursive
Node *reverse(Node *&head)
{
    if (head->next == NULL)
        return head; // Only one element in the list, no need to reverse.
    Node *chhotaHead = reverse(head->next);
    head->next->next = head; // can't do chottaHead->next = head; because chottaHead toh reversed list ka head ka abhi so ex: for last call the chhotaHead would be at 51 and we need to connect 200 to 119 now
    head->next = NULL;
    return chhotaHead;
}

Node *rotateRight(Node *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }
    else
    {
        Node *temp = head;
        int l = 0;
        while (temp)
        {
            temp = temp->next;
            l++;
        }
        k %= l;
        if(k==0) return head;
        Node *head1 = reverse(head);
        temp = head1;
        temp = head1;
        for (int i = 1; i < k; i++)
        {
            temp = temp->next;
        }
        Node *head2 = temp->next;
        temp->next = nullptr;
        head1 = reverse(head1);
        head2 = reverse(head2);
        temp = head1;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head2;
        return head1;
    }
}

int main()
{
    Node *head = NULL;

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    // insertAtHead(head, 23);
    // insertAtHead(head, 200);
    // insertAtHead(head, 119);
    print(head);
    cout << "head = " << head->data << endl;

    head = reverse(head);
    print(head);
    cout << "head = " << head->data << endl;

    head = rotateRight(head, 2);
    print(head);
}