#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// O(n^2)
// void nextSmallerElement(vector<int> &arr, int s, int e)
// {
//     if (s == e)
//     {
//         arr[s] = -1;
//     }
//     else
//     {
//         int i = s + 1;
//         while (i <= e)
//         {
//             if (arr[s] > arr[i])
//             {
//                 arr[s] = arr[i];
//                 break;
//             }
//             i++;
//         }
//         if (i > e)
//         {
//             arr[s] = -1;
//         }
//         return nextSmallerElement(arr, s + 1, e);
//     }
// }

// O(n) using stacks
void nextSmallerElement(vector<int> &arr)
{
    stack<int> s;
    vector<int> nse(arr.size());

    // will start from back
    for (int i = arr.size() - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top() > arr[i])
        {
            s.pop();
        }

        nse[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    arr = nse; // copy to arr
}

void prevSmallerElement(vector<int> &arr)
{
    stack<int> s;
    vector<int> pse(arr.size());

    // will start from front
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && s.top() > arr[i])
        {
            s.pop();
        }

        pse[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    arr = pse;
}

void nextGreaterElement(vector<int> &arr)
{
    stack<int> s;
    vector<int> nge(arr.size());

    // will start from back
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        nge[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    arr = nge; // copy to arr
}

void prevGreaterElement(vector<int> &arr)
{
    stack<int> s;
    vector<int> pge(arr.size());

    // will start from front
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && s.top() < arr[i])
        {
            s.pop();
        }

        pge[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    arr = pge;
}

int main()
{
    vector<int> arr = {2, 0, 4, 2, 5};
    vector<int> nextGreater = arr, nextSmaller = arr, prevGreater = arr, prevSmaller = arr;
    cout << "given array: ";
    print(arr);

    cout << "next smaller element array: ";
    nextSmallerElement(nextSmaller);
    print(nextSmaller);

    cout << "prev smaller element array: ";
    prevSmallerElement(prevSmaller);
    print(prevSmaller);

    cout << "next greater element array: ";
    nextGreaterElement(nextGreater);
    print(nextGreater);

    cout << "prev greater element array: ";
    prevGreaterElement(prevGreater);
    print(prevGreater);
}