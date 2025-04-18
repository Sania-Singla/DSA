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

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "empty list" << endl;
    }
    else
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;
}

// Node *middle(Node *head)
// {
//     if (!head || !head->next)
//         return head;

//     Node *slow = head;
//     Node *fast = head->next;

//     while (fast && fast->next) // because in case of even nodes we need nearest as middle node because then in case of 2 nodes for ex. the mergesort would be in inifinte loop
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }
// OR
Node *middle(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node *merge(Node *&head1, Node *&head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    Node *head = NULL, *tail = NULL;

    // merge
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            insertAtTail(head, tail, head1->data);
            head1 = head1->next;
        }
        else
        {
            insertAtTail(head, tail, head2->data);
            head2 = head2->next;
        }
    }

    while (head1)
    {
        insertAtTail(head, tail, head1->data);
        head1 = head1->next;
    }

    while (head2)
    {
        insertAtTail(head, tail, head2->data);
        head2 = head2->next;
    }

    return head;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    else
    {
        // splitting the list into two halves until we have single elements (low==high here we say head -> next == NULL)
        Node *mid = middle(head);
        Node *head1 = head;
        Node *head2 = mid->next;
        mid->next = NULL; // to make them disjoint

        // left part
        head1 = mergeSort(head1);
        // right part
        head2 = mergeSort(head2);
        // merge
        return merge(head1, head2);
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);
    print(head);
    head = mergeSort(head);
    print(head);

    return 0;
}