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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

// delete all occurances
void deleteAllOcc(Node * &head, int k) {
    Node * prev = NULL;
    Node * curr = head;
    while(curr != NULL) {
        if(curr -> data == k) {
            Node* toDelete = curr;
            curr = curr -> next;
            if(prev != NULL) prev -> next = curr;
            toDelete -> next = NULL;
            delete toDelete;
        }
        else {
            prev = curr;
            curr = curr -> next;
        }
    }
}

int firstOcc(Node *head, int k)
{
    if (head == NULL)
        return -1;
    else if (head->next == NULL)
    {
        if (head->data == k)
            return 0;
        else
            return -1;
    }
    else
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == k)
            {
                return count;
            }
            count++;
            temp = temp->next;
        }
        return -1;
    }
}

int lastOcc(Node *head, int k)
{
    if (head == NULL)
        return -1;
    else if (head->next == NULL)
    {
        if (head->data == k)
            return 0;
        else
            return -1;
    }
    else
    {
        int count = -1;
        int i = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == k)
            {
                count = i;
            }
            i++;
            temp = temp->next;
        }
        return count;
    }
}

int totalOcc(Node *head, int k)
{
    if (head == NULL)
        return 0;
    else if (head->next == NULL)
    {
        if (head->data == k)
        {
            return 1;
        }
        else
            return 0;
    }
    else
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == k)
                count++;
            temp = temp->next;
        }
        return count;
    }
}



// MISTAKE


























// void deleteAllOcc(Node *&head, int k)
// {
//     Node *prev = NULL;
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         if (curr->data == k)
//         {
//             Node *temp = curr;
//             curr = curr->next;
//             if (prev != NULL)
//                 prev->next = curr;
//             temp->next = NULL;
//             delete temp;
//         }
//         else
//         {
//             prev = curr;
//             curr = curr->next;
//         }
//     }
// }

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

    int k = 10;
    // int total = totalOcc(head, k);
    // cout << "total occurances: " << total << endl;

    // cout << "after deletion list becomes: " << endl;
    // deleteOcc(head, k);
    // print(head);

    int first = firstOcc(head, k);
    cout << "first occ index: " << first << endl;
    int last = lastOcc(head, k);
    cout << "last occ index: " << last << endl;
    int total = totalOcc(head, k);
    cout << "total occs: " << total << endl;
    deleteAllOcc(head, k);
    print(head);
}