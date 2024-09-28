#include<iostream>
using namespace std;

class Queue {
    public:
    int front;
    int rear;
    int size;
    int * arr;

    Queue(int s) {
        this -> size = s;
        this -> rear = 0;
        this -> front = 0;
        this -> arr = new int[s];
    }

    void push(int e) {
        if(rear == size) {
            cout << "queue full" << endl;
            return ;
        }
        else {
            arr[rear++] = e;
        }
    }

    int pop () {
        if(front == rear && rear == 0) {  // because hm na original queue mein se jb dusri queue bnte hain toh fir uske baad push kha kre original queue mein ? toh ise rear ko 0 pe lana pdta hai toh fir front == rear hota hai last element pe but that is != 0  
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

    void print() {
        for(int i=this -> front; i<this -> size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void interleave () {
        Queue newQ(this -> size/2);
        while(front != size/2) {
            int e = this -> pop();
            newQ.push(e);
        }

        // newQ.print();
        // this -> print();
        rear = 0;

        while(newQ.front != newQ.rear) {
            int e = newQ.pop();
            this -> push(e);
            e = this -> pop();
            this -> push(e);
        }

        this -> front = 0;  // because the front of original queue is at size right now
    }
};

int main () {
    Queue q(10);
    q.push(11);   
    q.push(12);   
    q.push(13);   
    q.push(14);   
    q.push(15);   
    q.push(16);   
    q.push(17);   
    q.push(18);   
    q.push(19);   
    q.push(20);   

    q.print();
    cout << "front = " << q.peek() << endl;
    q.interleave();
    q.print();
    cout << "front = " << q.peek() << endl;
}