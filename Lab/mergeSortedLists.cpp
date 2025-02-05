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

void insertNode(Node *&head, int e)
{
    Node *newNode = new Node(e);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *merge(Node *head1, Node *head2)
{
    Node *head = NULL;
    if (head1 == head2)
        return head1;
    else
    {
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                insertNode(head, head1->data);
                head1 = head1->next;
            }
            else
            {
                insertNode(head, head2->data);
                head2 = head2->next;
            }
        }

        while (head1 != NULL)
        {
            insertNode(head, head1->data);
            head1 = head1->next;
        }

        while (head2 != NULL)
        {
            insertNode(head, head2->data);
            head2 = head2->next;
        }
    }
    return head;
}

int main()
{
    Node *head1 = new Node(10);
    insertNode(head1, 8);
    insertNode(head1, 6);
    insertNode(head1, 4);
    insertNode(head1, 2);
    print(head1);

    Node *head2 = new Node(9);
    insertNode(head2, 7);
    insertNode(head2, 5);
    insertNode(head2, 3);
    insertNode(head2, 1);
    print(head2);

    Node *head = merge(head1, head2);
    print(head); // result will look opposite because we are inserting at head
}