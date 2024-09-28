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

void print(Node * &head) {
    if(head == NULL) {
        cout << "empty" << endl;
        return;
    }
    Node * temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead (Node * &head, int d) {
    Node * newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
    return; 
}

void merge(int arr[], int s, int e) {
    
}

Node * radixSort(int arr[], int s, int e) {
    
}

int main() {
    Node * head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    head = radixSort(head);
    print(head);
}