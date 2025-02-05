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
        this->end = -1;
    }

    void enqueue(int e)
    {
        if (end == size - 1)
        {
            cout << "queue full" << endl;
        }
        else if (front == -1) // first insertion
        {
            arr[++front] = e;
            end++;
        }
        else
        {
            arr[++end] = e;
        }
    }

    int dequeue()
    {
        if (front == -1 || front > end)
        {
            cout << "empty queue" << endl;
            return -1;
        }
        else
        {
            return arr[front++];
        }
    }

    int frontElement()
    {
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
        return (front == -1 || front > end) ? true : false;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // queue full

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;
}