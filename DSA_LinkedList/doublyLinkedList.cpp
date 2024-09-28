#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node * prev;

    // constructor
    Node (int d) {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void printList (Node * &head) {
    Node * temp = head;
    if(head == NULL) {
        cout << "list is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp -> data << "  ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLength (Node * &head) {
    Node * temp = head;
    int length = 0;
    while (temp != NULL) {
        temp = temp -> next;
        length ++;
    }
    return length;
}


void insertAtHead (Node * &head, Node * &tail, int d) {
    //empty list
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node * newNode = new Node(d);
        Node * temp = head;
        temp -> prev = newNode;
        newNode -> next = temp;
        head = newNode; // or head = head -> prev;
    }
}


void insertAtTail (Node * &tail, Node * &head, int d) {
    //empty list
    if(tail == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node * newNode = new Node(d);
        Node * temp = tail;
        temp -> next = newNode;
        newNode -> prev = temp;
        tail = newNode;
    }
}


void insertAtPosition (Node * &tail, Node * &head, int position, int d) {
    if(position == 1) {
        insertAtHead(head, tail, d);
        return ;
    }
    else if( getLength(head) == position - 1 ) {
        insertAtTail(tail, head, d);
        return ;
    }
    else {
        Node * newNode = new Node(d);
        Node * temp = head;
        int count = 1;
        while (count < position - 1) {
            temp = temp -> next;
            count ++;
        }
        Node * beforeNode = temp;
        Node * afterNode = temp -> next;
        beforeNode -> next = newNode;
        newNode -> prev = beforeNode;
        afterNode -> prev = newNode;
        newNode -> next = afterNode;

        // or
        // temp -> next -> prev = newNode;
        // newNode -> next = temp -> next;
        // temp -> next = newNode;
        // newNode -> prev = temp;
    }
}


void deletionFromPosition (Node * &head, Node * &tail, int position) {
    if(position == 1) {
        Node * temp = head;
        head = temp -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return ;
    }
    else if (getLength(head) == position) {
        Node * temp = tail;
        tail = temp -> prev;
        tail -> next = NULL;
        temp -> prev = NULL;
        delete temp;
        return ;
    }
    else {
        Node * temp = head;
        int count = 1;
        while (count < position - 1) {
            temp = temp -> next;
            count ++;
        }
        Node * nodeToDelete = temp -> next;
        temp -> next = nodeToDelete -> next;
        temp -> next -> prev = temp;
        nodeToDelete -> next = NULL;
        nodeToDelete -> prev = NULL;
        delete nodeToDelete;
    }
}


int main () {

    Node * node1 = new Node(10);  
    cout << "data = " << node1 -> data << endl; 
    cout << "next = " << node1 -> next << endl; 
    cout << "prev = " << node1 -> prev << endl; 

    Node * head = node1;
    Node * tail = node1;
    

    // traversing thru a list
    printList(head); 
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // insert at head 
    insertAtHead(head, tail, 12);
    printList(head); 
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;
    

    // insert at tail 
    insertAtTail(tail, head, 15);
    printList(head); 
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;

    
    // insert at any position
    insertAtPosition(tail, head, 2, 41);
    printList(head); 
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // delete from any position
    deletionFromPosition(head, tail, 4);
    printList(head); 
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // get list length 
    cout << "length = " << getLength(head) << endl;
}