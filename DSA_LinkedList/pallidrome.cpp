// app1: time complexity:O(n) & space complexity: O(n)
// app2: time complexity:O(n) & space complexity: O(1)

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

void insertAtHead(Node* &head,int d) {
    Node * newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        return;
    }
    else {
        newNode -> next = head;
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

int length(Node * &head) {
    if(head == NULL) return 0;
    if(head -> next == NULL) return 1;
    Node * temp = head;
    int length = 0;
    while(temp != NULL) {
        length ++;
        temp = temp -> next;
    }
    return length;
}


// approach 1 (copy the LL into an array & then check)   
// bool isPallidrome(Node * &head, int l) {
//     int arr[l] = {0};
//     Node * temp = head;
//     int index = 0;
//     while(temp != NULL) { // O(n)
//         arr[index++] = temp -> data;
//         temp = temp -> next;
//     }
//     for (int i=0,j=l-1; i<j; i++,j--) {  // O(n/2)
//         if (arr[i] != arr[j]) return false;
//     }
//     return true;
// }

// approach 2 (find mid, then reverse the second half and compare then again reverse the second half to get the initial list again)
Node * middle(Node * &head) {
    Node * temp = head;
    Node * fast = head -> next;
    Node * slow = head;
    while(fast != NULL && fast -> next != NULL) {    // O(n/2)  // *** nearest in case of even length ***
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
} 

Node * reverse(Node * &head) {
    if(head == NULL || head -> next == NULL) return head;
    else {
        Node * reverseHead = reverse(head -> next);  // O(n)
        head -> next -> next = head;
        head -> next = NULL;
        return reverseHead;
    }
}

bool isPallidrome(Node * &head) {
    if(head == NULL || head -> next == NULL) return true;
    // step1
    Node * mid = middle(head);    // O(n/2)
    // step2
    mid -> next = reverse(mid -> next);    // O(n)
    // step3
    Node * head2 = mid -> next;
    Node * head1 = head;
    while(head2 != NULL) {    // O(n/2)
        if(head1 -> data != head2 -> data) return false;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    // step4
    mid -> next = reverse(mid -> next);   // repeating the step2
    return true;
}

int main() {
    Node * head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtHead(head,5);
    insertAtHead(head,5);
    insertAtHead(head,1);
    insertAtHead(head,4);
    insertAtHead(head,4);
    print(head);
    // int l = length(head);
    if(isPallidrome(head)) cout << "YES" << endl;
    else cout << "NO" << endl;
}