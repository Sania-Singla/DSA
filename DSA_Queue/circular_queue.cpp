#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int end;
    int size;
    int *arr;

    Queue(int s)
    {
        this->size = s;
        this->arr = new int[s];
        this->front = -1;
        this->end = -1; // remember end jha pe hai vha pe element hai abhi
    }

    void push(int e)
    { // enqueue opr.
        if ((end + 1) % size == front)
        { // or end + 1 == front for % alternative    //(front == 0 && end == size-1) || (end == (front-1) % (size-1))
            cout << "queue full" << endl;
            return;
        }
        else if (front == -1)
        {
            // first element
            arr[++front] = e;
            end++;
        }
        else if (end == size - 1)
        {
            // circulate
            end = 0;
            arr[end] = e;
        }
        else
            arr[++end] = e;
    }

    int pop()
    { // dequeue opr.
        if (front == -1)
        {
            cout << "empty queue" << endl;
            return -1;
        }

        int data = arr[front];

        if (front == end)
        { // single element
            front = end = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return data;
    }

    int frontElement()
    { // or peek
        if (front == -1)
        {
            cout << "empty queue" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        return front == -1 ? true : false;
    }
};

int main()
{
    Queue q1(5);
    q1.push(2);
    q1.push(10);
    q1.push(21);
    q1.push(8);
    q1.push(3);
    // q1.push(7); // queue full
    cout << "front element = " << q1.frontElement() << endl;
    cout << "popped element = " << q1.pop() << endl;
    q1.push(7); // circulate so queue is not full
    cout << "front element = " << q1.frontElement() << endl;
    // cout << "front element = " << q1.frontElement() << endl;
    // cout << "popped element = " << q1.pop() << endl;
    // cout << "front element = " << q1.frontElement() << endl;
    // cout << "popped element = " << q1.pop() << endl;
    // cout << "front element = " << q1.frontElement() << endl;
    // cout << "popped element = " << q1.pop() << endl;
    // cout << "front element = " << q1.frontElement() << endl;
    // cout << "popped element = " << q1.pop() << endl;
}