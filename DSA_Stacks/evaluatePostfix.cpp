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

// int evaluatePostfix(string postfix, int l) {
//     Stack s2(l);
//     for(int i = 0; i < l; i++) {
//         char c = postfix[i];

//         if(c!='*' && c!='/' && c!='+' && c!='-') {
//             s2.push(c - '0');
//         }
//         else {
//             // Pop two operands
//             int operand2 = s2.pop();
//             int operand1 = s2.pop();

//             // Perform the operation
//             int result;
//             switch(c) {
//                 case '+': result = operand1 + operand2; break;
//                 case '-': result = operand1 - operand2; break;
//                 case '*': result = operand1 * operand2; break;
//                 case '/': result = operand1 / operand2; break;
//                 default: cout << "Invalid operator" << endl; return -1;
//             }
//             // Push the result back to the stack
//             s2.push(result);
//         }
//     }
//     // The final result will be at the top of the stack
//     return s2.pop();
// }

int evaluatePostfix(string postfix)
{
    int l = postfix.length();
    Stack s(l);
    int ans;
    int i = 0;
    while (i < l)
    {
        if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
        {
            s.push(postfix[i] - '0');
        }
        else
        {
            int opr2 = s.pop();
            int opr1 = s.pop();
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
        i++;
    }
    return s.pop();
}

int main()
{
    string postfix = "27+3*2-5/";
    int ans;
    // int l = postfix.length();

    // ans = evaluatePostfix(postfix,l);
    ans = evaluatePostfix(postfix);
    cout << "ans:" << ans << endl;

    return 0;
}