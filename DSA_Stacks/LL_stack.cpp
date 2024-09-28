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

class Stack {
    public:
    Node * top;   // head

    Stack () {
        this -> top = NULL;
    }
    
    void push(int e) {
        Node * newNode = new Node(e);
        if(!newNode) {  // if null
            cout << "stack overflow" << endl;
            return;
        }
        if(top == NULL) {
            top = newNode;
            return;
        }
        else {
            newNode -> next = top;
            top = newNode;
        }
    }

    int pop() {
        if(top != NULL) {
            // delete that node
            Node * nodeToDelete = top;
            top = top -> next;
            nodeToDelete -> next = NULL;
            int element = nodeToDelete -> data;
            delete nodeToDelete;
            return element;
        }
        else {
            cout << "stack underflow" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == NULL ? true : false;
    }

    int peek() {
        if(top != NULL) return top -> data;
        else {
            cout << "empty stack" << endl;
            return -1;
        }
    }
};

int main () {
    Stack * s1 = new Stack();
    s1 -> push(1);
    s1 -> push(2);
    s1 -> push(3);
    cout << "top element = " << s1 -> peek() << endl;
    cout << "is empty = " << s1 -> isEmpty() << endl;
    cout << "popped element = " << s1 -> pop() << endl;
    cout << "top element = " << s1 -> peek() << endl;
    cout << "is empty = " << s1 -> isEmpty() << endl;
    cout << "popped element = " << s1 -> pop() << endl;
    cout << "top element = " << s1 -> peek() << endl;
    cout << "is empty = " << s1 -> isEmpty() << endl;
    cout << "popped element = " << s1 -> pop() << endl;
    cout << "top element = " << s1 -> peek() << endl;
    cout << "is empty = " << s1 -> isEmpty() << endl;
}