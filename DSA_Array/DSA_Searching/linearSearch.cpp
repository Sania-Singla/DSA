// time complexity: O(n) (worst case & best case)
// space complexity: O(1)

#include <iostream>
using namespace std;

// iterative
// int linearSearch(int key, int arr[], int n) {
//     for (int i=0; i< n; i++) {
//         if(arr[i] == key) {
//             return i + 1;  // position
//         }
//     }
//     return -1;
// }

// recursive
int linearSearch(int key, int arr[], int n)
{
    if (n == 0)
        return -1;
    else
    {
        if (arr[0] == key)
            return 1;
        else
            return linearSearch(key, arr + 1, n - 1) + 1;
    }
}

int main()
{
    int key;
    int arr[10] = {11, 21, 38, 42, 59, 63, 79, 81, 99, 111};
    cout << "enter key:" << endl;
    cin >> key;
    if (linearSearch(key, arr, 10) == -1)
        cout << "NOT FOUND." << endl;
    else
        cout << "position = " << linearSearch(key, arr, 10);

    return 0;
}