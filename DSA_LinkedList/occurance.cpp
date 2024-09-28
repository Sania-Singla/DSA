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

void insertAtTail(Node * &head, Node * &tail, int d) {
    Node * newNode = new Node(d);
    if(tail == NULL) {
        tail = newNode;
        head = newNode;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
    return;
}

void print(Node * &head) {
    Node * temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    return ;
}

int totalOcc(Node * &head, int k) {
    int count = 0;
    Node * temp = head;
    while(temp != NULL) {
        if(temp -> data == k) count ++;
        temp = temp -> next;
    }
    return count;
}

// delete all occurances
void deleteOcc(Node * &head, int k) {
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

int main () {
    Node * head = NULL;
    Node * tail = NULL;
    
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
    int total = totalOcc(head, k);
    cout << "total occurances: " << total << endl;

    cout << "after deletion list becomes: " << endl;
    deleteOcc(head, k);
    print(head);
}