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

void selectionSort(Node *head) // sort in descending order
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    else
    {
        Node *temp1 = head;
        Node *temp2 = NULL;
        Node *max = NULL;
        while (temp1->next != NULL)
        {
            max = temp1;
            temp2 = temp1->next;
            while (temp2 != NULL)
            {
                if (temp2->data > max->data)
                {
                    max = temp2;
                }
                temp2 = temp2->next;
            }
            swap(max->data, temp1->data);
            temp1 = temp1->next;
        }
    }
}

void bubbleSort(Node *head) // sort in ascending order
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    else
    {
        Node *lastSorted = NULL;
        Node *temp = NULL;
        bool swapped;
        do
        {
            temp = head;
            swapped = false;
            while (temp->next != lastSorted)
            {
                if (temp->data > temp->next->data)
                {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
            lastSorted = temp;
        } while (swapped);
    }
}

void insertionSort(Node *&head) // sort in descending order
{
    Node *sortedHead = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        if (sortedHead == NULL || curr->data >= sortedHead->data)
        {
            curr->next = sortedHead;
            sortedHead = curr;
        }
        else
        {
            Node *temp = sortedHead;
            while (temp->next != NULL && curr->data <= temp->next->data)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    head = sortedHead;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    selectionSort(head);
    print(head);

    bubbleSort(head);
    print(head);

    insertionSort(head);
    print(head);
}