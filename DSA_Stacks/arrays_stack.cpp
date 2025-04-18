#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;

    Stack(int s)
    {
        this->top = -1;
        this->size = s;
        this->arr = new int[s];
    }

    void push(int e)
    {
        if (top < size - 1)
        {
            arr[++top] = e;
        }
        else
        {
            cout << "stack full" << endl;
        }
    }

    int pop()
    { // it doesn't return the popped element just decrement top
        if (top != -1)
        {
            return arr[top--];
        }
        else
        {
            cout << "empty stack" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int peek()
    { // it returns the popped element but doesn't decrement top
        if (top != -1)
            return arr[top];
        else
        {
            cout << "empty stack" << endl;
            return -1;
        }
    }
};

int main()
{
    Stack *s1 = new Stack(5);
    s1->push(1);
    s1->push(2);
    s1->push(3);
    cout << "top element = " << s1->peek() << endl;
    cout << "is empty = " << s1->isEmpty() << endl;
    cout << "popped element = " << s1->pop() << endl;
    cout << "top element = " << s1->peek() << endl;
    cout << "is empty = " << s1->isEmpty() << endl;
}