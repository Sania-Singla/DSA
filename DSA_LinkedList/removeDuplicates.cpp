// time complexity: unsorted O(n^2) without map but with map O(n) with S(n) & sorted O(n)
// space complexity: both O(1)

#include <bits/stdc++.h>
#include "./headers/node.h"
using namespace std;

// if sorted list
void removeDuplicatesSorted(Node *&head)
{
    if (!head || !head->next)
        return;
    Node *curr = head;
    while (curr)
    {
        if (curr->next && curr->data == curr->next->data)
        {
            Node *nodeToDelete = curr->next;
            curr->next = nodeToDelete->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }
        else
        {
            curr = curr->next;
        }
    }
}

// if not sorted
void removeDuplicatesUnSorted(Node *&head)
{
    // Node *curr = head;
    // while (curr)
    // {
    //     Node *temp = curr;
    //     while (temp -> next)
    //     {
    //         if (curr->data == temp->next->data)
    //         {
    //             Node *nodeToDelete = temp->next;
    //             temp->next = nodeToDelete->next;
    //             nodeToDelete->next = NULL;
    //             delete nodeToDelete;
    //         }
    //         else
    //         {
    //             temp = temp->next;
    //         }
    //     }
    //     curr = curr->next;
    // }

    // O(n) but S(n) also
    if (!head || !head->next)
        return;
    unordered_map<int, bool> visited;
    Node *prev = NULL;
    Node *curr = head;

    while (curr)
    {
        if (visited[curr->data])
        {
            Node *nodeToDelete = curr;
            prev->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
        }
        curr = prev->next;
    }
}


int main()
{
    Node *head = NULL;

    // SORTED
    // insertAtHead(head, 4);
    // insertAtHead(head, 4);
    // insertAtHead(head, 3);
    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 2);
    // insertAtHead(head, 2);
    // print(head);
    // removeDuplicatesSorted(head);
    // print(head);

    // NON-SORTED
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    print(head);
    removeDuplicatesUnSorted(head);
    print(head);
}