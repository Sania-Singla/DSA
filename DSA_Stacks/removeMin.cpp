#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> mainStack, minStack;

public:
    void push(int val)
    {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if (mainStack.empty())
            return;
        if (mainStack.top() == minStack.top())
        {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top()
    {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin()
    {
        return minStack.empty() ? -1 : minStack.top();
    }

    void removeMin()
    {
        if (minStack.empty())
            return;
        int minVal = minStack.top();
        stack<int> tempStack;

        while (!mainStack.empty())
        {
            if (mainStack.top() != minVal)
            {
                tempStack.push(mainStack.top());
            }
            mainStack.pop();
        }
        minStack.pop();

        while (!tempStack.empty())
        {
            push(tempStack.top());
            tempStack.pop();
        }
    }
};

int main()
{
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(10);

    cout << "Minimum Element: " << s.getMin() << endl;
    s.removeMin();
    cout << "Minimum Element after removal: " << s.getMin() << endl;
    return 0;
}
