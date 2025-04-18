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
        this->size = s;
        this->top = -1;
        this->arr = new int[s];
    }

    void push(int e)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
            arr[++top] = e;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
};

int evaluatePostfix(string postfix)
{
    int l = postfix.length();
    Stack s(l);
    int ans;
    for (int i = 0; i < l; i++)
    {
        if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
        {
            // operand
            s.push(postfix[i] - '0');
        }
        else
        {
            // operator
            int opr2 = s.pop(), opr1 = s.pop();
            switch (postfix[i])
            {
            case '+':
            {
                ans = opr1 + opr2;
                break;
            }
            case '-':
            {
                ans = opr1 - opr2;
                break;
            }
            case '*':
            {
                ans = opr1 * opr2;
                break;
            }
            case '/':
            {
                ans = opr1 / opr2;
                break;
            }
            default:
            {
                cout << "Invalid operator" << endl;
                return -1;
            }
            }
            s.push(ans);
        }
    }
    return s.pop();
}

int main()
{
    string postfix = "27+3*2-5/";
    int ans;
    ans = evaluatePostfix(postfix);
    cout << "ans:" << ans << endl;
    return 0;
}