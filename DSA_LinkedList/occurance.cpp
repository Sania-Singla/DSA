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

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (tail == NULL)
    {
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    return;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// delete all occurrences
void deleteAllOcc(Node *&head, int k)
{
    while (head != NULL && head->data == k)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    Node *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        if (curr->data == k)
        {
            Node *toDelete = curr;
            curr = curr->next;
            prev->next = curr;
            delete toDelete;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

int firstOcc(Node *head, int k)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == k)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

int lastOcc(Node *head, int k)
{
    int i = 0, lastIndex = -1;
    while (head != NULL)
    {
        if (head->data == k)
            lastIndex = i;
        head = head->next;
        i++;
    }
    return lastIndex;
}

int totalOcc(Node *head, int k)
{
    int count = 0;
    while (head != NULL)
    {
        if (head->data == k)
            count++;
        head = head->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 17);
    insertAtTail(head, tail, 14);
    insertAtTail(head, tail, 14);
    insertAtTail(head, tail, 14);
    insertAtTail(head, tail, 16);
    insertAtTail(head, tail, 17);
    insertAtTail(head, tail, 17);
    insertAtTail(head, tail, 19);
    print(head);

    int k = 14;

    int first = firstOcc(head, k);
    cout << "first occ index: " << first << endl;
    int last = lastOcc(head, k);
    cout << "last occ index: " << last << endl;
    int total = totalOcc(head, k);
    cout << "total occs: " << total << endl;

    deleteAllOcc(head, k);
    print(head);
}