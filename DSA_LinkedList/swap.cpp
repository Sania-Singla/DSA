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
        cout << "list is empty." << endl;
    }
    else
    {
        while (head != NULL)
        {
            cout << head->data << "  ";
            head = head->next;
        }
        cout << endl;
    }
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

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void selectionSort(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    else
    {
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            Node *min = temp1;
            Node *temp2 = temp1->next;
            while (temp2 != NULL)
            {
                if (temp2->data < min->data)
                {
                    min = temp2;
                }
                temp2 = temp2->next;
            }
            swap(temp1->data, min->data);
            temp1 = temp1->next;
        }
    }
}

int main()
{
    Node *head = new Node(10);
    insertAtHead(head, 1);
    insertAtHead(head, 7);
    insertAtHead(head, 15);
    insertAtHead(head, 13);
    print(head);

    selectionSort(head);
    print(head);
}