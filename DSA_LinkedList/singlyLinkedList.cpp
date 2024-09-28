#include <iostream>
using namespace std;

// linked list is a dynamic & linear data structure. It is a collection of nodes where  a node = an object having a data, and an address of the next node
class Node {
    public:
    int data;
    Node * next;

    // constructor
    Node (int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

// although while printing we dont need reference(actual address) but to keep consistency we will
void printList (Node * &head){
    Node * temp = head;   // so that we don't accidently change the head node
    if(head == NULL) {
        cout << "list is empty." << endl;
        return ;
    }
    while(temp != NULL) {
        cout << temp -> data << "  ";
        temp = temp -> next;
    }
    cout << endl;
}


void insertAtHead (Node * &head, Node * &tail, int d) {
    // create a new node
    // point it to the head
    // move the head to newNode
    if(head == NULL) { 
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node * newNode = new Node(d);
        newNode -> next = head;
        head = newNode;
    }
}


void insertAtTail (Node * &tail, Node * &head, int d) {
    // create a new node
    // point it to the NULL(already due to constructor) & tail to newNode
    // move the tail to the newNode
    if(tail == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node * newNode = new Node(d);
        tail -> next = newNode;
        tail = newNode;
    }
}


void insertAtPosition (Node * &head, Node * &tail, int position, int d) {
    if(position == 1) {
        // insert at head
        insertAtHead(head, tail, d);
        return ;
    }

    Node * temp = head;
    int count = 1;
    // create a new node
    Node * newNode = new Node(d);

    // traverse till the node at position-1 
    while (count < position - 1) {
        temp = temp -> next;
        count ++;
    }

    // check if insert at end (position == length of the list or next == NULL)
    if(temp -> next == NULL) {
        insertAtTail(tail, head, d);    // or tail = newNode; because neeche wala code will also work for insert at tail
        return ;        
    }

    // point the position-1 node to newNode and newNode to position+1 node
    newNode -> next = temp -> next;
    temp -> next = newNode;
}


void deleteFromPosition (Node * & tail, Node * &head, int position) {
    Node * temp = head;
    if(position == 1) {
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        int count = 1;
        while(count < position - 1 ) {
            temp = temp -> next;
            count ++;
        }
        Node * nodeToDelete = temp -> next;
        temp -> next = nodeToDelete -> next;
        if(nodeToDelete -> next == NULL) {
            tail = temp;
        }
        else {
            nodeToDelete -> next = NULL;
        }
        delete nodeToDelete;
    }
}


int main () {

    Node * node1 = new Node(10);  // head is an object of node class basically 
    cout << "data = " << node1 -> data << endl; 
    cout << "next = " << node1 -> next << endl; 

    Node * head = node1;
    Node * tail = node1;
    

    // traversing thru a list
    printList(head); 
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // inserting at head
    insertAtHead(head, tail, 12);
    printList(head);
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // inserting at tail
    insertAtTail(tail, head, 22);
    printList(head);
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // inserting at any position
    insertAtPosition(head, tail, 1, 17);
    printList(head);
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;


    // deleting node from any position
    deleteFromPosition(tail, head, 3);
    printList(head);
    cout << "head at = " << head -> data << endl;
    cout << "tail at = " << tail -> data << endl;

}