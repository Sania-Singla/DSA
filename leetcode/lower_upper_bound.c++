#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! only works for sorted array */

// O(logn)
int main()
{
    vector<int> nums = {1, 4, 5, 8, 11, 14, 16};
    int key = 14;

    auto it = lower_bound(nums.begin(), nums.end(), key); // it points to the first element >= key
    /*
    cout << it;  // error because its an address
    cout << nums.begin() // again error
    cout << it - nums.begin(); // gives the index of the element (pointer subtraction gives the number of elements between the two pointers)
    */
    if (it != nums.end())
        cout << "Lower bound of " << key << " is: " << *it; // prints the value of pointer
    else
        cout << "all are < " << key;

    cout << endl;

    it = upper_bound(nums.begin(), nums.end(), key); // it points to the first element > key //! strictly greater
    if (it != nums.end())
        cout << "Upper bound of " << key << " is: " << *it;
    else
        cout << "all are <= " << key;

    return 0;
}