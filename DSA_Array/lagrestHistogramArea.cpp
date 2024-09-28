#include<iostream>
using namespace std;
 


/**************************************************************************************************************************************************/
/****************************************************************** MISTAKE ***********************************************************************/
/**************************************************************************************************************************************************/



void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copy(int arr[], int arr2[], int n) {
    for(int i=0; i<n; i++) {
        arr2[i] = arr[i];
    }
}

class Stack {
    public:
    int top;
    int size;
    int *arr;

    Stack (int s) {
        this -> top = 1;
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

void prevSmallerElement(int arr[], int n) {
    Stack prevSmallers(n);
    prevSmallers.push(-1);
    for(int i=0; i<n; i++) {
        while(prevSmallers.peek() >= arr[i]) {
            prevSmallers.pop();
        }
        int top = prevSmallers.peek();
        prevSmallers.push(arr[i]);
        arr[i] = top;
    }
}

void nextSmallerElement(int arr[], int n) {
    Stack nextSmallers(n);
    nextSmallers.push(-1);
    for(int i=n-1; i>=0; i--) {
        while(nextSmallers.peek() >= arr[i]) {
            nextSmallers.pop();
        }
        int top = nextSmallers.peek();
        nextSmallers.push(arr[i]);
        arr[i] = top;
    }
}

int largestArea(int heights[], int n) {
    int prev[n] = {0};
    int next[n] = {0};
    copy(heights, prev, n);
    copy(heights, next, n);
    nextSmallerElement(next, n);
    prevSmallerElement(prev, n);   // so basically now one array contains the prev smaller element for the curr height and other contain the next smaller element 

    int area = INT32_MIN;

    for(int i=0; i<n; i++) {
        cout << "height" << heights[i] << endl;
        int l = heights[i]; 

        // case when b<0 (not right)
        if(next[i] == -1) {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        cout << "area = "<< area << endl;
        int newArea = l * b;
        cout << "new area = " << newArea << endl;
        area = max(area, newArea);
    } 

    return area;
}

int main () {
    int heights[] = {2,1,5,6,2,3};
    int n = sizeof(heights) / sizeof(heights[0]);
    cout << "largets area possible = " << largestArea(heights,n) << endl;
}