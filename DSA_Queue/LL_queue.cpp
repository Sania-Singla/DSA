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

class Queue {
    public:
    Node * first;
    Node * end;

    Queue() {
        this -> first = NULL;
        this -> end = NULL;
    }

    void enqueue(int e) {
        Node * newNode = new Node(e);
        if(!newNode) {
            cout << "queue full" << endl;
            return;
        }
        if(first == NULL) {
            first = newNode;
            end = newNode;
        }
        else {
            end -> next = newNode;
            end = end -> next;
        }
    }

    int dequeue () {
        if(first == NULL) {    // this time front == end nhi hoga because uss pe data pda hai so front == NULL is only way to check empty
            cout << "empty queue" << endl;
            return -1;
        }
        else {
            int data = first -> data;
            first = first -> next;
            return data;
        }
    }

    int peek() {
        if(first == NULL) {
            cout << "empty queue" << endl;
            return -1;
        }
        else {
            return first -> data;
        }
    }

    bool isEmpty () {
        return first == NULL ? true : false;
    }
};

int main() {
    Queue q1;
    q1.enqueue(2);
    q1.enqueue(10);
    q1.enqueue(21);
    q1.enqueue(8);

    cout << "first element = " << q1.peek() << endl;
    cout << "popped element = " << q1.dequeue() << endl;
    cout << "first element = " << q1.peek() << endl;
    cout << "popped element = " << q1.dequeue() << endl;
    cout << "first element = " << q1.peek() << endl;
    cout << "popped element = " << q1.dequeue() << endl;
    cout << "first element = " << q1.peek() << endl;
    cout << "popped element = " << q1.dequeue() << endl;
    cout << "first element = " << q1.peek() << endl;
    cout << "popped element = " << q1.dequeue() << endl;
}
