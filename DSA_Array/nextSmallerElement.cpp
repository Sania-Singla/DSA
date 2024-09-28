#include<iostream>
using namespace std;


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// basic approach
// void nextSmallerElement(int arr[], int s,int e) {    // O(n^2)
//     if(s==e) {
//         arr[s] = -1;
//         return;
//     }
//     int i = s+1;
//     while(i<=e) {
//         if(arr[s] > arr[i]) {
//             arr[s] = arr[i];
//             break;
//         }
//         i++;
//     }
//     if(i>e) arr[s] = -1;
//     return nextSmaller(arr, s+1, e);
// }


// using stacks

class Stack {
    public:
    int top;
    int size;
    int *arr;

    Stack (int s) {
        this -> top = -1;
        this -> size = s;
        this -> arr = new int[s];
    }

    void push(int e) {
        arr[++top] = e;
    }

    int pop() {
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }
};


void nextSmallerElement(int arr[], int n) {     // O(n)
    Stack s1(n);
    s1.push(-1);
    // will start from back
    for(int i=n-1; i>=0; i--) {
        
        while(s1.peek() > arr[i]) {     // smallest element will always be in the stack
            s1.pop();
        }

        int top = s1.peek();
        s1.push(arr[i]);
        arr[i] = top;

    }
}

void prevSmallerElement (int arr[], int n) {
    Stack s2(n);
    s2.push(-1);
    // will start from front
    for(int i=0; i<n; i++) {
        while(s2.peek() > arr[i]) {
            s2.pop();
        }

        int top = s2.peek();
        s2.push(arr[i]);
        arr[i] = top; 
    }
}


int main () {
    int arr1[5] = {2,1,4,2,5};
    int arr2[5] = {2,1,4,2,5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    // nextSmallerElement(arr1, 0, n-1);
    nextSmallerElement(arr1,n);
    print(arr1,n);
    prevSmallerElement(arr2,n);
    print(arr2,n);
}