#include<iostream>
using namespace std;

class Stack {
    public:
    int top;
    int size;
    char *arr;

    Stack (int s) {
        this -> top = -1;
        this -> size = s;
        this -> arr = new char[s/2];
    }

    void push(int c) {
        if(top != this -> size - 1) {
            arr[++top] = c;
        }
        else {
            cout << "stack overflow" << endl;
        }
    }

    char peek() {
        if(top != -1) return arr[top];
        else {
            cout << "stack underflow" << endl;
            return '0';
        }
    }

    void pop() {
        if(top != -1) {
            top--;
        }
        else {
            cout << "stack overflow" << endl;
        }
    }

    bool validParenthesis(string s,int i, int l) {
        if(l%2 != 0) return false;        
        if(i==l) return true;
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
            this -> push(s[i]);
            return validParenthesis(s, i+1, l);
        }
        else {
            if( this -> peek() == '0') return false;  // empty 
            if((s[i] == ')' && this -> peek() == '(') || (s[i] == ']' && this -> peek() == '[') || (s[i] == '}' && this -> peek() == '{')) {
                this -> pop();
                return validParenthesis(s, i+1, l);
            }
            else {
                return false;
            }
        }
    }
};

int main () {
    Stack s1(6);
    string s = "{[([][])]}";
    int l = s.length();
    if( s1.validParenthesis(s, 0, l) ) cout << "VALID" << endl;
    else cout << "NOT VALID" << endl;
}