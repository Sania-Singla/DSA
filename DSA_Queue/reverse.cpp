#include<iostream>
using namespace std;

class Stack {
    public:
    int top;
    int size;
    int *arr;

    Stack(int s) {
        this -> top = -1;
        this -> size = s;
        this -> arr = new int[s];
    }

    void push(int e) {
        if(top == size-1) {
            cout << "stack full" << endl;
            return ;
        }
        else {
            arr[++top] = e;
        }
    }

    int pop() {
        if(top == -1) {
            cout << "empty stack" << endl;
            return -1;
        }
        else {
            return arr[top--];
        }
    }

    int peek() {
        if(top == -1) {
            cout << "empty stack" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }
};

class Queue {
    public:
    int front;
    int rear;
    int *arr;
    int size;
    
    Queue (int s) {
        this -> front = 0;
        this -> rear = 0;
        this -> arr = new int[s];
        this -> size = s;
    }

    void push(int e) {
        if(rear == size) {
            cout << "queue full" << endl;
            return;
        }
        else {
            arr[rear++] = e;
        }
    }

    int pop () {
        if(front == rear) {
            cout << "empty queue" << endl;
            return -1;
        }
        else {
            return arr[front++];
        }
    }

    int peek() {
        if(front == rear) {
            cout << "empty queue" << endl;
            return -1;
        }
        else {
            return arr[front];
        }
    }

    void reverse() {
        Stack s(this -> size);

        while(this -> front != this -> rear) {
            int e = this -> pop();
            s.push(e);
        }

        front = 0;
        rear = 0;

        while(s.top != -1) {
            int e = s.pop();
            this -> push(e);
        } 
    }
};


int main () {
    Queue q(5);
    q.push(2);   
    q.push(1);   
    q.push(6);   
    q.push(8);   
    q.push(10);

    cout << "front = " << q.peek() << endl;
    q.reverse();  
    cout << "front = " << q.peek() << endl;
}