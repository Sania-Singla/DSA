#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
    }
    else
    {
        int topEl = s.top();
        s.pop();

        insertAtBottom(s, val);
        s.push(topEl);
    }
}

void print(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    for(int i = 1; i <= 5; i++) {
        s.push(i);
    }
    print(s);
    insertAtBottom(s, 6);
    print(s);
}