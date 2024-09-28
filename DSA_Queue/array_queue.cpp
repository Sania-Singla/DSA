#include<iostream>
using namespace std;

class Queue {
    public:
    int front;
    int end;
    int size;
    int *arr;

    Queue(int s) {
        this -> size = s;
        this -> arr = new int[s];
        this -> front = 0;
        this -> end = 0;    // remember end jha pe hai vha pe element nhi hai abhi 
    }

    void push(int e) {      // enqueue opr.
        if(end == this -> size) {
            cout << "queue full" << endl;
            return;
        }
        else {
            arr[end++] = e;
        }
    }

    int pop() {    // dequeue opr.
        if(front == end) {
            cout << "empty queue" << endl;
            return -1;
        }
        else {
            int data = arr[front++];
            if(front == end) {
                front = 0;
                end = 0;
            }
            return data;
        }
    }

    int frontElement() {  // or peek
        if(front == end) {
            cout << "empty queue" << endl;
            return -1;
        }
        else {
            return arr[front];
        }
    }

    bool isEmpty() {
        return front == end ? true : false;   
    }
};

int main() {
    Queue q1(5);
    q1.push(2);
    q1.push(10);
    q1.push(21);
    q1.push(8);
    // q1.push(3);

    cout << "front element = " << q1.frontElement() << endl;
    cout << "popped element = " << q1.pop() << endl;
    cout << "front element = " << q1.frontElement() << endl;
    cout << "popped element = " << q1.pop() << endl;
    cout << "front element = " << q1.frontElement() << endl;
    cout << "popped element = " << q1.pop() << endl;
    cout << "front element = " << q1.frontElement() << endl;
    cout << "popped element = " << q1.pop() << endl;
    cout << "front element = " << q1.frontElement() << endl;
    cout << "popped element = " << q1.pop() << endl;
    
}