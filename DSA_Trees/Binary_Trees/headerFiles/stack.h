#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"
using namespace std;

class Stack
{
public:
    int top;
    Node **arr;
    int size;

    Stack(int s)
    {
        this->size = s;
        this->top = -1;
        this->arr = new Node *[s];
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(Node *e)
    {
        if (this->isFull())
        {
            cout << "stack full" << endl;
        }
        else
        {
            arr[++top] = e;
        }
    }

    Node *pop()
    {
        if (this->isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            return arr[top--];
        }
    }

    Node *topElement()
    {
        if (this->isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            return arr[top];
        }
    }
};

#endif