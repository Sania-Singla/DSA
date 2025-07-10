#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

void LSS(vector<int> arr, vector<int> &subset) {
    
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subset;
    LSS(arr, subset);
    print(subset);
}