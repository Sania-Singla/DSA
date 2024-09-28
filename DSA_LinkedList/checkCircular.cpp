// time complexity: O(n)
// space complexityL O(1)

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;        

    // constructor
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

// for circular testing
void insertNode (Node * &tail, int element, int d) {
    Node * newNode = new Node(d);
    if(tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    }
    else {
        Node * temp = tail;
        while (temp -> data != element) {
            temp  = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return ;
}

void printList(Node * &tail) {
    Node * temp = tail;
    if(tail == NULL) {
        cout << "empty list." << endl;
        return ;
    }
    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while (temp != tail);
    cout << endl;
}

// for non circular testing
void insertAtHead(Node * &head, Node * &tail, int d) {
    Node * newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
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

// check
bool checkCircular(Node * &tail) {
    Node * temp = tail;
    if(tail == NULL) return true;
    if(tail -> next == NULL) return false;
    do {
        if(temp -> next == NULL) return false;
        temp = temp -> next;
    } while(temp != tail);
    return true;
}

int main () {
    Node * tail = NULL; // only one either head or tail is required (since circular)

    // for circular testing  
    insertNode(tail, 13, 1);     
    insertNode(tail, 1, 3);      
    insertNode(tail, 3, 5);      
    insertNode(tail, 3, 4);      
    insertNode(tail, 1, 2);   
    printList(tail);

    // for non circular testing 
    // Node * head = NULL;  
    // insertAtHead(head, tail, 51);
    // insertAtHead(head, tail, 43);
    // insertAtHead(head, tail, 23);
    // insertAtHead(head, tail, 200);
    // insertAtHead(head, tail, 119);
    // print(head);
    // cout << "head = " << head -> data << endl;
    cout << "tail = " << tail -> data << endl;

    if(checkCircular(tail)) cout << "circular" << endl;
    else cout << "NOT circular" << endl;
}