#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtHead(Node* &head, Node * &tail, int d) {
    Node * newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

void print(Node * head) {
    Node * temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* middle(Node * &head) {
    Node * temp = head;
    Node * fast = head -> next;
    Node * slow = head;
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) fast = fast -> next;
        slow = slow -> next;
    }
    return slow;
}

Node* reverse (Node * &head) {
    if(head == NULL || head -> next == NULL) return head;
    else {
        Node * reverseHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return reverseHead;
    }
}

// approach-1
// bool isPallidrome(Node * &head) {
//     if(head == NULL || head -> next == NULL) return true;
//     Node * mid = middle(head);
//     Node * head2 = reverse(mid);
//     Node * head1 = head;
//     while(head2 != NULL) {
//         if(head1 -> data != head2 -> data) return false;
//         head1 = head1 -> next;
//         head2 = head2 -> next;
//     }

//     head2 = reverse(head2);
//     return true;
// }

// approach-2
bool isPallidrome(Node * &head, Node * &tail) {
    if(head == NULL || head -> next == NULL) return true;
    Node * temp1 = head;
    Node * temp2 = tail;
    while(temp1 != temp2) {
        if(temp1 -> data != temp2 -> data) return false;
        temp1 = temp1 -> next;
        temp2 = temp2 -> prev;
    }
    return true;
}

int main() {
    Node * head = NULL;
    Node * tail = NULL;
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);

    if(isPallidrome(head, tail)) cout << "YES" << endl;
    else cout << "NO" << endl;
}