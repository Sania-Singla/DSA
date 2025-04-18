#include <iostream>
#include <cmath>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;

    Stack(int s)
    {
        this->size = s;
        this->top = -1;
        this->arr = new char[s];
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

    char pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return '0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
        {
            return '0';
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
};

int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// void convertToPostfix(string infix, int i, int l, Stack& s1, string & postfix) {
//     if(i == l) return;

//     if(infix[i] == '(') {
//         s1.push(infix[i]);
//     }
//     else if(infix[i] == ')') {
//         while(s1.peek() != '(') {
//             postfix += s1.pop();
//         }
//         s1.pop();    // for popping the '('
//     }
//     else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {
//         if(s1.isEmpty()) {
//             s1.push(infix[i]);
//         }
//         else {
//             while(!s1.isEmpty() && precedence(s1.peek()) >= precedence(infix[i])) {
//                 postfix += s1.pop();
//             }
//             s1.push(infix[i]);
//         }
//     }
//     else {
//         postfix += infix[i];
//     }
//     return convertToPostfix(infix,i+1,l,s1,postfix);
// }

string convertToPostfix(string infix)
{
    int l = infix.length();
    Stack s(l);
    string postfix;
    for (int i = 0; i < l; i++)
    {
        if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop(); // pop '('
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (s.peek() == '(')
            {
                s.push(infix[i]);
            }
            else
            {
                while (precedence(s.peek()) >= precedence(infix[i]))
                {
                    postfix += s.pop();
                }
                s.push(infix[i]);
            }
        }
        else
        {
            postfix += infix[i];
        }
    }
    // pop any remaning elements in the stack
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

int main()
{
    string infix = "((2+7)*3-2)/5";
    string postfix;
    // int l = infix.length();
    // Stack s1(l);
    // convertToPostfix(infix, 0, l, s1, postfix);
    postfix = convertToPostfix(infix);

    // Pop any remaining operators in the stack
    // while(!s1.isEmpty()) {
    //     postfix += s1.pop();
    // }

    cout << postfix << endl;

    return 0;
}