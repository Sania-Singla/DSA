#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// for circular testing
void printList(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "empty list." << endl;
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// for non circular
void print(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "empty list." << endl;
        return;
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head->next;

    while (fast)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node *removeLoop(Node *&head)
{
    if (!head)
        return NULL;

    Node *slow = head;
    Node *fast = head->next;
    while (fast)
    {
        if (fast == slow)
        {
            slow = head;
            if (fast->next != slow)
            {
                fast = fast->next;
                while (fast->next != slow->next)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            fast->next = NULL;
            return head;
        }
        else
        {
            fast = fast->next;
            if (fast)
                fast = fast->next;
            slow = slow->next;
        }
    }
    return head;
}

int main()
{
    Node *head = new Node(5);
    Node *node1 = new Node(4);
    Node *node2 = new Node(3);
    Node *node3 = new Node(2);
    Node *node4 = new Node(1);
    Node *node5 = new Node(0);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;
    // printList(head); // infinite loop

    if (floydDetectLoop(head))
        cout << "loop present" << endl;
    else
        cout << "loop absent" << endl;
    head = removeLoop(head);
    if (floydDetectLoop(head))
        cout << "loop present" << endl;
    else
        cout << "loop absent" << endl;
    print(head);
}