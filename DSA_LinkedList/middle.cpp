// time complexity is O(n) + O(n/2) => O(n)
// space complexity is O(1)
// for more optimized time complexity is O(n/2) direct

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node (int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node * &head, int d) {
    Node * newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        return ;
    }
    newNode -> next = head;
    head = newNode;
}

void print(Node * head) {
    if(head == NULL) {
        cout << "empty list" << endl;
        return;
    }
    Node * temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int length(Node* &head) {
    if(head == NULL) return 0;
    if(head -> next == NULL) return 1;
    Node * temp = head;
    int count  = 0;
    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

// Node* middle(Node* &head) {
//     if(head == NULL) return head;
//     if(head -> next == NULL) return head;
//     Node * temp = head;
//     int l = length(head);
//     int count = 1;
//     while(count <= l/2) {
//         temp = temp -> next;
//         count++ ;
//     }
//     return temp;
// }

// more optimized
Node* middle(Node* &head) {
    if(head == NULL) return head;
    if(head -> next == NULL) return head;
    Node * fast = head -> next;
    Node * slow = head;
    while(fast != NULL) {    // moves n/2 times
        fast = fast -> next;
        if( fast != NULL) fast = fast -> next;   // ek aur age bdha do
        slow = slow -> next;
    }
    return slow;
}

int main() {
    Node * head = NULL;

    insertAtHead(head, 51);
    insertAtHead(head, 43);
    insertAtHead(head, 23);
    insertAtHead(head, 200);
    insertAtHead(head, 119);
    print(head);
    cout << "head = " << head -> data << endl;

    Node * mid = middle(head);
    cout << "middle = " << mid -> data << endl;
}