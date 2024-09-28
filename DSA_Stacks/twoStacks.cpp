#include<iostream>
using namespace std;

class Stack {
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int s) {
        this -> size = s;
        this -> top1 = -1;
        this -> top2 = s;
        this -> arr = new int[s];
    }

    void push1(int e) {
        if(top1 + 1 < top2) {    // or top2- top1 > 1    // also handled top1 < this -> size
            arr[++top1] = e;
            return;
        }
        else {
            cout << "stack1 overflow" << endl;
        }
    }

    void push2(int e) {
        if (top2 - 1 > top1) {   // or top2 - top1 > 1    // also handled top2 < 0 
            arr[--top2] = e;
            return;
        }
        else {
            cout << "stack2 overflow" << endl;
        }
    }

    int pop1() {
        if(top1 != -1) {
            return arr[top1--];
        }
        else {
            cout << "empty stack1" << endl;
            return -1;
        }
    }

    int pop2() {
        if(top2 < this -> size) {
            return arr[top2++];
        }
        else {
            cout << "empty stack2" << endl;
            return -1;
        }
    }

    int peek1() {
        if(top1 != -1) return arr[top1];
        else {
            cout << "empty stack1" << endl;
            return -1;
        }
    }

    int peek2() {
        if(top2 < this -> size) return arr[top2];
        else {
            cout << "empty stack2" << endl;
            return -1;
        }
    }

    bool isEmpty1() {
        return top1 == -1 ? true : false;
    }

    bool isEmpty2() {
        return top2 == this -> size + 1 ? true : false;
    }
};

int main() {
    Stack * s1 = new Stack(5);
    s1 -> push1(1);
    s1 -> push1(2);

    s1 -> push2(5);
    s1 -> push2(4);
    s1 -> push2(3);
    s1 -> push2(9);  // overflow

    cout << "is stack1 empty = " << s1 -> isEmpty1() << endl;
    cout << "top element in stack1 = " << s1 -> peek1() << endl;
    cout << "popped element from stack1 = " << s1 -> pop1() << endl;
    cout << "is stack1 empty = " << s1 -> isEmpty1() << endl;
    cout << "top element in stack1 = " << s1 -> peek1() << endl;
    cout << "popped element from stack1 = " << s1 -> pop1() << endl;
    cout << "is stack1 empty = " << s1 -> isEmpty1() << endl;
    cout << "top element in stack1 = " << s1 -> peek1() << endl;

    cout << "is stack2 empty = " << s1 -> isEmpty2() << endl;
    cout << "top element in stack2 = " << s1 -> peek2() << endl;
    cout << "popped element from stack2 = " << s1 -> pop2() << endl;
    cout << "is stack2 empty = " << s1 -> isEmpty2() << endl;
    cout << "top element in stack2 = " << s1 -> peek2() << endl;
    cout << "popped element from stack2 = " << s1 -> pop2() << endl;
    cout << "is stack2 empty = " << s1 -> isEmpty2() << endl;
    cout << "top element in stack2 = " << s1 -> peek2() << endl;
        cout << "popped element from stack2 = " << s1 -> pop2() << endl;

    cout << "top element in stack2 = " << s1 -> peek2() << endl;
}