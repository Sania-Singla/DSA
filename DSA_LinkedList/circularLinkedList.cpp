// simple circular linked list 

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

void insertNode (Node * &tail, int element, int d) {
    Node * newNode = new Node(d);
    if(tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
        return ;
    }
    else {
        // assuming element exist in the list
        Node * temp = tail;
        while (temp -> data != element) {
            temp  = temp -> next;
        }
        // so we have found the element that is temp and we have to insert newNode after this temp now
        newNode -> next = temp -> next;
        temp -> next = newNode;
        // no need to update the tail since circular
    }
}

void deleteNode (Node * &tail, int element) {
    Node * temp = tail;
    if(tail == NULL) {
        cout << "empty list." << endl;
        return ;
    }
    else {
        Node * prev = tail;
        Node * curr = tail -> next;
        if(prev == curr) {
            curr -> next = NULL;   // assuming value match hi hogi fir toh
            tail = NULL;
            delete curr;
            return ;
        }
        while (curr -> data != element) {
            prev = curr;
            curr = curr -> next;
        } 
        prev -> next = curr -> next;
        if(tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void printList(Node * &tail) {
    Node * temp = tail;
    if(tail == NULL) {
        cout << "empty list." << endl;
        return ;
    }
    do
    {
        cout << temp -> data << "  ";
        temp = temp -> next;
    } while (temp != tail);
    cout << endl;
}

int main () { 

    // we dont create a node ourselves because then it won't point to itself istead to NULL
    Node * tail = NULL; // only one either head or tail is required (since circular)  

    // traversing thru a list
    printList(tail); 
    

    // insert after any element
    insertNode(tail, 17, 1);    
    printList(tail);  
    cout << "tail at = " << tail -> data << endl;  

    insertNode(tail, 1, 3);    
    printList(tail);   
    
    insertNode(tail, 3, 5);    
    printList(tail);   
    
    insertNode(tail, 3, 4);    
    printList(tail);   
    
    insertNode(tail, 1, 2);    
    printList(tail);   
    
    insertNode(tail, 5, 6);    
    printList(tail);  


    // deleting having data = element
    deleteNode(tail, 2);    
    printList(tail); 

    deleteNode(tail, 4);    
    printList(tail); 
    
    deleteNode(tail, 6);    
    printList(tail); 
    
    deleteNode(tail, 1);    
    printList(tail); 
    
    deleteNode(tail, 5);    
    printList(tail); 
    
    deleteNode(tail, 3);    
    printList(tail); 

}