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
        if ((end == size - 1 && front == 0) || (end + 1 == front)) // or front == (end + 1) % size
        {
            cout << "queue full" << endl;
        }
        else if (front == -1) // first insertion
        {
            front = end = 0;
            arr[front] = e;
        }
        // else if (end == size - 1) // circulate
        // {
        //     end = 0;
        //     arr[end] = e;
        // }
        // else // normal case
        // {
        //     arr[++end] = e;
        // }
        else
        {
            end = (end + 1) % size; // if end == size - 1 then end = 0         // if normal case end = end + 1
            arr[end] = e;
        }
    }

    int dequeue()
    {
        if (front == -1) // empty
        {
            cout << "empty queue" << endl;
            return -1;
        }
        int data = arr[front];

        if (front == end) // last element pop (either queue has only 1 element or full)
        {
            front = -1;
            end = -1;
        }
        // else if (front == size - 1) // circulate
        // {
        //     front = 0;
        // }
        // else
        // {
        //     front++;
        // }
        else
        {
            front = (front + 1) % size; // if front == size - 1 then front = 0   // if normal case front = front + 1
        }

        return data;
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
        return front == -1 ? true : false;
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
    // q.enqueue(6);

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;

    q.enqueue(6);

    cout << "front element = " << q.frontElement() << endl;
    cout << "popped = " << q.dequeue() << endl;
    cout << "is Empty = " << q.isEmpty() << endl;

    q.enqueue(7);

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