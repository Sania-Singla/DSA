#include<iostream>
using namespace std;


/**************************************************************************************************************************************************/
/****************************************************************** MISTAKE ***********************************************************************/
/**************************************************************************************************************************************************/


class Stack {
    public:
    int top;
    int size;
    int *arr;
    
    Stack(int s) {
        this -> size = s;
        this -> top = -1;
        this -> arr = new int[s];
    }

    void push(int e) {
        if(top == this -> size - 1) {
            cout << "stack overflow" << endl;
        }
        else {
            while(top != this -> size - 1) {
                int temp[100] = {0};
                int i=0;
                if(this -> peek() > e) {
                    arr[top++] = e;
                }
                else {
                    while(this -> peek() > e) {
                        temp[i++] = this -> pop();
                    }
                    arr[top++] = e;
                    while(i>=0) {
                        arr[top++] = temp[i--];
                    }
                }
            }
        }
    } 

    int pop() {
        if(top == -1) {
            cout << "stack underflow" << endl;
            return -1;
        }
        else {
            return arr[top--];
        }
    }

    int peek() {
         if(top == -1) {
            cout << "stack underflow" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    int min() {

    }
};

int main () {
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.peek();
}