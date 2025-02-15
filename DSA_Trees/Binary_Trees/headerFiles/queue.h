#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    Node **arr;
    int size;

    Queue(int s)
    {
        this->size = s;
        this->front = -1;
        this->rear = -1;
        this->arr = new Node *[s];
    }

    bool isFull()
    {
        return rear < size - 1 ? false : true;
    }

    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(Node *e)
    {
        if (this->isFull())
        {
            cout << "queue full" << endl;
        }
        else if (front == -1)
        {
            arr[++rear] = e;
            front++;
        }
        else
        {
            arr[++rear] = e;
        }
    }

    Node *dequeue()
    {
        if (this->isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            return arr[front++];
        }
    }

    Node *frontElement()
    {
        if (this->isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            return arr[front];
        }
    }
};

#endif
