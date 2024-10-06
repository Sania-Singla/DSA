#include <iostream>
using namespace std;

/**************************************************************************************************************************************************/
/****************************************************************** MISTAKE ***********************************************************************/
/**************************************************************************************************************************************************/

class Stack
{
public:
    int top;
    int size;
    int *arr;
    int min;

    Stack(int s)
    {
        this->size = s;
        this->top = -1;
        this->arr = new int[s];
        this->min = INT16_MAX;
    }

    void push(int e)
    {
        if (this->top == this->size)
        {
            cout << "stack overflow" << endl;
            return;
        }
        else if (this->isEmpty())
        {
            this->min = e;
            arr[++top] = e;
        }
        else
        {
            if (e < this->min)
            {
                arr[++top] = (2 * e - this->min);
                this->min = e;
            }
            else
            {
                arr[++top] = e;
            }
        }
    }

    int pop()
    {
        if (this->isEmpty())
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        else
        {
            if (this->peek() > this->min)
            {
                return arr[top--];
            }
            else
            {
                int prevMin = min;
                int val = (2 * prevMin - this->peek());
                this->min = val;
                top--;
                return prevMin;
            }
        }
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }

    int minimumElement()
    {
        return this->min; // O(1) time and space complexity
    }

    int peek()
    {
        if (this->isEmpty())
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        else
        {
            if (arr[top] < min)
            {
                return min;
            }
            else
                return arr[top];
        }
    }
};

int main()
{
    Stack s1(5);
    s1.push(2);
    s1.push(5);
    s1.push(8);
    s1.push(3);
    s1.push(1);

    cout << s1.peek() << endl;
s1.pop();
    cout << s1.minimumElement();
}