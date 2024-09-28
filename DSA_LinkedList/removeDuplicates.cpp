// time complexity: unsorted O(n^2) & sorted O(n)
// space complexity: both O(1)

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

void print(Node * &head){
    Node * temp = head;   
    if(head == NULL) {
        cout << "list is empty." << endl;
        return ;
    }
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead (Node * &head, int d) {
    if(head == NULL) { 
        Node* temp = new Node(d);
        head = temp;
    }
    else {
        Node * newNode = new Node(d);
        newNode -> next = head;
        head = newNode;
    }
}

// if sorted list
// void removeDuplicates (Node * &head) {
//     if(head == NULL) return;
//     if(head -> next == NULL) return;
//     Node * curr = head;
//     while(curr -> next != NULL) {
//         if(curr -> data == curr -> next -> data) {
//             Node * next_next = curr -> next -> next;
//             Node * nodeToDelete = curr -> next;
//             curr -> next = next_next;
//             nodeToDelete -> next =  NULL;
//             delete nodeToDelete;
//         }
//         else curr = curr -> next;
//     }
//     return;
// }

// if not sorted
void removeDuplicates (Node * head) {
    Node * curr = head;
    while(curr != NULL) {
        Node * temp = curr -> next;
        while(temp != NULL) {
            if(curr -> data == temp -> data) {
                Node * next = temp -> next;
                curr -> next = next;
                temp -> next = NULL;
                delete temp;
                temp = next;
            }
            else temp = temp -> next;
        }
        curr = curr -> next;
    }
}

int main () {
    Node * head = NULL;

    // sorted
    // insertAtHead(head, 4);
    // insertAtHead(head, 4);
    // insertAtHead(head, 3);
    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 2);
    // insertAtHead(head, 2);
    // print(head);

    // not sorted
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    print(head);

    removeDuplicates(head);
    print(head);
}