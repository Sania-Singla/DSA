#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node * prev;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtHead(Node* &head,int d) {
    Node * newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        return;
    }
    else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    return;
}

void print(Node * &head) {
    if(head == NULL) {
        cout << "empty" << endl;
        return;
    }
    else {
        Node * temp = head;
        while(temp != NULL) {
            cout << temp -> data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return;
}

// iterative
// void reverse(Node * &head) {
//     if(head == NULL || head -> next == NULL) return;
//     Node * prev = NULL;
//     Node * curr = head;
//     Node * forward = head;
//     while(curr != NULL) {
//         forward = curr -> next;
//         curr -> next = curr -> prev;
//         curr -> prev = forward;
//         prev = curr;
//         curr = forward;
//     }
//     head = prev;
//     return;
// }

// recursive
Node * reverse(Node * &head) {
    if(head == NULL || head -> next == NULL) return head;
    else {
        Node * reverseHead = reverse(head -> next);
        Node * forward = head -> next -> next;
        head -> next -> next = head;
        head -> next -> prev = forward;
        head -> next = NULL;
        return reverseHead;
    }
}

int main () {
    Node * head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,0);
    insertAtHead(head,0);
    insertAtHead(head,1);
    print(head);
    // reverse(head);
    // print(head);
    head = reverse(head);
    print(head);
}